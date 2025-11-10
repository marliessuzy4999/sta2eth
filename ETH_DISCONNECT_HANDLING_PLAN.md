# Ethernet断开/重连处理方案

## 用户需求

> 充分处理eth断开和重连的情况，也就是理论上你要在pc连接后，将phy、内部变量，缓冲池、c6的状态等，全部清理一遍，然后从第一个封包获取mac，再用这个mac去初始化c6，再去连接，再去重新建立桥接，你得判断到底是硬件瞬断，还是正常的网线拔出再插入。包括模块突然掉电重启，也应该是这个逻辑。

## 需要处理的场景

### 1. 网线拔出/插入

```
正常运行 → 网线拔出 → ETHERNET_EVENT_DISCONNECTED
         ↓
    等待网线插入 → ETHERNET_EVENT_CONNECTED
         ↓
    可能是同一台PC，也可能是不同PC
```

### 2. PC断电/重启

```
正常运行 → PC断电 → Ethernet link down
         ↓
    等待PC上电 → Ethernet link up
         ↓
    MAC可能改变（不同PC）或相同（同一PC）
```

### 3. 硬件瞬断

```
正常运行 → 瞬间断开（<1秒） → ETHERNET_EVENT_DISCONNECTED
         ↓ 立即重连
    ETHERNET_EVENT_CONNECTED
         ↓
    应该是同一台PC，MAC不变
```

### 4. 系统掉电重启

```
系统启动 → 走完整初始化流程
```

## 判断策略

### 瞬断 vs 正常拔出

**判断依据：断开时长**

```
断开时长 < 3秒 → 判定为瞬断
断开时长 >= 3秒 → 判定为正常拔出
```

**瞬断处理：**
- 不重新学习MAC
- 不重启WiFi
- 不重建Bridge
- 仅等待link恢复

**正常拔出处理：**
- 清理所有状态
- 重新学习MAC
- 如果MAC变化，重启WiFi并重建Bridge
- 如果MAC相同，继续使用

## 实现方案

### 状态机设计

```
STATE_INIT          → 初始化，等待首次MAC学习
STATE_RUNNING       → 正常运行
STATE_ETH_DOWN      → Ethernet断开
STATE_WAIT_RELEARN  → 等待重新学习MAC
STATE_RECONFIGURE   → 重新配置WiFi和Bridge
```

### 需要清理的资源

#### 1. Ethernet相关

```c
// 不需要清理PHY，保持运行
// 只需要清除内部状态

// 清除学习的MAC
s_mac_learned = false;
memset(s_pc_mac, 0, 6);

// 清除event flags
xEventGroupClearBits(s_event_flags, MAC_LEARNED_BIT);
```

#### 2. WiFi相关（仅在MAC变化时）

```c
// 断开WiFi连接
esp_wifi_disconnect();

// 停止WiFi
esp_wifi_stop();

// 不需要清理C6状态，它会在下次esp_wifi_start()时重置
```

#### 3. Bridge相关（仅在MAC变化时）

```c
// 销毁Bridge
if (s_br_netif) {
    esp_netif_destroy(s_br_netif);
    s_br_netif = NULL;
}

// Bridge glue会自动清理
// FDB会自动清除
```

#### 4. 不需要清理的

- **PHY硬件**：保持初始化状态
- **SDIO通信**：保持活动
- **C6 WiFi驱动**：在esp_wifi_stop()时自动清理
- **内存池**：由系统管理，不需要手动清理

### 事件处理逻辑

```c
static void eth_event_handler(void *arg, esp_event_base_t event_base,
                               int32_t event_id, void *event_data)
{
    switch (event_id) {
    case ETHERNET_EVENT_CONNECTED:
        ESP_LOGI(TAG, "Ethernet Link Up");
        
        // 记录link up时间
        s_last_link_up_time = esp_timer_get_time();
        
        if (s_state == STATE_ETH_DOWN) {
            // 从断开恢复
            uint64_t down_duration = s_last_link_up_time - s_last_link_down_time;
            
            if (down_duration < 3000000) {  // 3秒
                ESP_LOGI(TAG, "Short disconnection (%.1fs), assuming same PC", 
                         down_duration / 1000000.0);
                // 瞬断，不重新学习
                s_state = STATE_RUNNING;
            } else {
                ESP_LOGI(TAG, "Long disconnection (%.1fs), re-learning MAC", 
                         down_duration / 1000000.0);
                // 正常拔出，重新学习
                s_mac_learned = false;
                memset(s_pc_mac, 0, 6);
                xEventGroupClearBits(s_event_flags, MAC_LEARNED_BIT);
                s_state = STATE_WAIT_RELEARN;
                xEventGroupSetBits(s_event_flags, RELEARN_MAC_BIT);
            }
        } else {
            // 首次连接
            s_state = STATE_WAIT_RELEARN;
        }
        
        xEventGroupSetBits(s_event_flags, ETH_LINK_UP_BIT);
        break;
        
    case ETHERNET_EVENT_DISCONNECTED:
        ESP_LOGW(TAG, "Ethernet Link Down");
        
        // 记录link down时间
        s_last_link_down_time = esp_timer_get_time();
        s_state = STATE_ETH_DOWN;
        
        xEventGroupClearBits(s_event_flags, ETH_LINK_UP_BIT);
        break;
    }
}
```

### MAC重学习逻辑

```c
static esp_err_t relearn_mac_if_needed(void)
{
    if (s_state != STATE_WAIT_RELEARN) {
        return ESP_OK;  // 不需要重学习
    }
    
    ESP_LOGI(TAG, "Waiting for new packet to learn MAC...");
    
    // 等待MAC学习
    xEventGroupWaitBits(s_event_flags, MAC_LEARNED_BIT, pdFALSE, pdFALSE, portMAX_DELAY);
    
    // 检查MAC是否变化
    bool mac_changed = false;
    if (s_has_previous_mac) {
        mac_changed = memcmp(s_pc_mac, s_previous_mac, 6) != 0;
    }
    
    if (mac_changed) {
        ESP_LOGI(TAG, "PC MAC changed! Old: %02x:%02x:%02x:%02x:%02x:%02x",
                 s_previous_mac[0], s_previous_mac[1], s_previous_mac[2],
                 s_previous_mac[3], s_previous_mac[4], s_previous_mac[5]);
        ESP_LOGI(TAG, "               New: %02x:%02x:%02x:%02x:%02x:%02x",
                 s_pc_mac[0], s_pc_mac[1], s_pc_mac[2],
                 s_pc_mac[3], s_pc_mac[4], s_pc_mac[5]);
        
        // MAC变化，需要重新配置
        s_state = STATE_RECONFIGURE;
        return ESP_ERR_NOT_FINISHED;  // 表示需要重新配置
    } else {
        ESP_LOGI(TAG, "Same PC MAC, continuing...");
        s_state = STATE_RUNNING;
        return ESP_OK;
    }
}
```

### 重新配置流程

```c
static esp_err_t reconfigure_wifi_and_bridge(void)
{
    ESP_LOGI(TAG, "Reconfiguring WiFi and Bridge with new MAC...");
    
    // 1. 销毁现有Bridge
    if (s_br_netif) {
        ESP_LOGI(TAG, "Destroying existing bridge...");
        esp_netif_destroy(s_br_netif);
        s_br_netif = NULL;
    }
    
    // 2. 停止WiFi
    ESP_LOGI(TAG, "Stopping WiFi...");
    esp_wifi_disconnect();
    vTaskDelay(pdMS_TO_TICKS(100));
    esp_wifi_stop();
    vTaskDelay(pdMS_TO_TICKS(100));
    
    // 3. 更新WiFi MAC
    ESP_LOGI(TAG, "Updating WiFi MAC to new PC MAC...");
    ESP_ERROR_CHECK(esp_wifi_set_mac(WIFI_IF_STA, s_pc_mac));
    
    // 4. 重启WiFi
    ESP_LOGI(TAG, "Restarting WiFi...");
    ESP_ERROR_CHECK(esp_wifi_start());
    
    // 5. 重新连接
    ESP_ERROR_CHECK(connect_wifi());
    
    // 6. 重建Bridge
    ESP_ERROR_CHECK(create_bridge());
    
    // 7. 保存新MAC作为previous
    memcpy(s_previous_mac, s_pc_mac, 6);
    s_has_previous_mac = true;
    s_state = STATE_RUNNING;
    
    ESP_LOGI(TAG, "Reconfiguration complete!");
    return ESP_OK;
}
```

### 主循环修改

```c
void app_main(void)
{
    // ... 初始化代码 ...
    
    // 首次学习和配置
    ESP_ERROR_CHECK(wait_for_pc_mac());
    memcpy(s_previous_mac, s_pc_mac, 6);
    s_has_previous_mac = true;
    
    ESP_ERROR_CHECK(init_wifi_with_pc_mac());
    ESP_ERROR_CHECK(connect_wifi());
    ESP_ERROR_CHECK(create_bridge());
    
    s_state = STATE_RUNNING;
    
    // 监控循环
    while (1) {
        EventBits_t bits = xEventGroupWaitBits(
            s_event_flags,
            RELEARN_MAC_BIT | WIFI_DISCONNECTED_BIT | RECONFIGURE_BIT,
            pdTRUE, pdFALSE, portMAX_DELAY
        );
        
        if (bits & RELEARN_MAC_BIT) {
            // Ethernet重连，可能需要重学习MAC
            esp_err_t ret = relearn_mac_if_needed();
            
            if (ret == ESP_ERR_NOT_FINISHED) {
                // MAC变化，需要重新配置
                reconfigure_wifi_and_bridge();
            }
            // else: MAC相同或瞬断，继续运行
        }
        
        if (bits & WIFI_DISCONNECTED_BIT) {
            // WiFi断开会自动重连（在event handler中）
            ESP_LOGI(TAG, "WiFi disconnected, reconnecting...");
        }
        
        if (bits & RECONFIGURE_BIT) {
            // 用户请求重新配置
            ESP_LOGI(TAG, "User requested reconfiguration, restarting...");
            esp_restart();
        }
        
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}
```

## 需要添加的全局变量

```c
// 状态
typedef enum {
    STATE_INIT,
    STATE_RUNNING,
    STATE_ETH_DOWN,
    STATE_WAIT_RELEARN,
    STATE_RECONFIGURE
} system_state_t;

static system_state_t s_state = STATE_INIT;

// MAC学习
static uint8_t s_previous_mac[6] = {0};
static bool s_has_previous_mac = false;

// 时间戳（用于判断瞬断）
static uint64_t s_last_link_down_time = 0;
static uint64_t s_last_link_up_time = 0;

// Event flags
#define RELEARN_MAC_BIT      BIT8
```

## 各场景处理总结

### 场景1：网线拔出 < 3秒插回

```
运行中 → 拔出 → link down → 记录时间
      ↓
    插入 → link up → 计算时长 < 3秒
      ↓
    判定瞬断 → 不重新学习 → 继续运行 ✅
```

**清理的内容：**
- 无需清理任何内容

### 场景2：网线拔出 > 3秒插回（同一台PC）

```
运行中 → 拔出 → link down → 记录时间
      ↓
    插入 → link up → 计算时长 > 3秒
      ↓
    判定正常拔出 → 重新学习MAC → MAC相同
      ↓
    继续运行（不重建WiFi/Bridge）✅
```

**清理的内容：**
- MAC学习标志

### 场景3：网线拔出 > 3秒插回（不同PC）

```
运行中 → 拔出 → link down
      ↓
    插入 → link up → 重新学习MAC → MAC不同
      ↓
    销毁Bridge → 停止WiFi → 更新WiFi MAC → 重启WiFi → 重建Bridge ✅
```

**清理的内容：**
- MAC学习标志
- Bridge netif
- WiFi连接状态
- WiFi MAC地址（更新为新MAC）

### 场景4：系统掉电重启

```
上电 → 完整初始化流程
    ↓
  等待MAC学习 → 配置WiFi → 建立Bridge ✅
```

**清理的内容：**
- 所有状态自动清零（重启）

## 优化建议

### 1. 添加健壮性

```c
// MAC学习超时
#define MAC_LEARN_TIMEOUT_MS  30000  // 30秒

// 在wait_for_pc_mac()中添加超时
EventBits_t bits = xEventGroupWaitBits(
    s_event_flags, 
    MAC_LEARNED_BIT, 
    pdFALSE, pdFALSE, 
    pdMS_TO_TICKS(MAC_LEARN_TIMEOUT_MS)
);

if (!(bits & MAC_LEARNED_BIT)) {
    ESP_LOGE(TAG, "MAC learning timeout! Please check PC connection.");
    return ESP_ERR_TIMEOUT;
}
```

### 2. 添加日志

```c
ESP_LOGI(TAG, "===========================================");
ESP_LOGI(TAG, "Ethernet Reconnection Detected");
ESP_LOGI(TAG, "Down duration: %.2f seconds", down_duration / 1000000.0);
ESP_LOGI(TAG, "Action: %s", (down_duration < 3000000) ? "Continue" : "Re-learn");
ESP_LOGI(TAG, "===========================================");
```

### 3. 持久化配置

```c
// 保存上次的MAC到NVS（可选）
void save_last_mac_to_nvs(const uint8_t *mac) {
    nvs_handle_t nvs;
    nvs_open("sta2eth", NVS_READWRITE, &nvs);
    nvs_set_blob(nvs, "last_mac", mac, 6);
    nvs_commit(nvs);
    nvs_close(nvs);
}

// 启动时读取（可用于快速恢复）
bool load_last_mac_from_nvs(uint8_t *mac) {
    nvs_handle_t nvs;
    if (nvs_open("sta2eth", NVS_READONLY, &nvs) == ESP_OK) {
        size_t len = 6;
        esp_err_t ret = nvs_get_blob(nvs, "last_mac", mac, &len);
        nvs_close(nvs);
        return (ret == ESP_OK && len == 6);
    }
    return false;
}
```

## 最终结论

### ✅ 完整的断线重连方案

| 功能 | 实现 |
|------|------|
| 瞬断检测 | ✅ 时间戳比较 |
| MAC重学习 | ✅ 自动触发 |
| MAC变化检测 | ✅ 比较previous MAC |
| 资源清理 | ✅ 按需清理 |
| WiFi重配置 | ✅ MAC变化时执行 |
| Bridge重建 | ✅ MAC变化时执行 |
| 日志记录 | ✅ 完整追踪 |

### 不需要清理的资源

- ❌ PHY硬件（保持初始化）
- ❌ SDIO通信（持续活动）
- ❌ 内存池（系统管理）
- ❌ C6内部状态（WiFi API自动管理）

### 需要清理的资源

- ✅ MAC学习标志
- ✅ Bridge netif（仅MAC变化时）
- ✅ WiFi连接（仅MAC变化时）
- ✅ Event flags

**方案简洁、高效、可靠！**
