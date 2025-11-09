# 多层缓冲架构设计文档
## Multi-Tier Buffer Architecture Design

## 概述

本文档详细说明了 sta2eth 项目的多层缓冲架构设计，用于解决 SDIO 与 Ethernet 之间的时序不匹配问题。

### 问题背景
- **SDIO 时钟**：动态协商（取决于 P4-C6 信号质量）
- **PSRAM 时钟**：200 MHz（固定）
- **EMAC 时钟**：50 MHz（固定）
- **时序冲突**：不同时钟域导致封包延迟和锁死

### 解决方案
四层缓冲池架构，实现时钟域隔离和速率解耦。

---

## 架构设计

### 四个独立缓冲池

```
┌─────────────────────────────────────────────────────────────────┐
│                         应用层任务                                │
│              (eth_to_wifi_task / wifi_to_eth_task)              │
└────────┬────────────────────────────────────────────┬───────────┘
         │                                              │
         │ 入队                                   出队   │
         ▼                                              ▼
┌─────────────────────┐                     ┌─────────────────────┐
│  SDIO TX Buffer Pool │                     │  PSRAM RX Pool      │
│  (内部 RAM)          │                     │  (PSRAM)            │
│  - 32 个缓冲         │                     │  - 2048 个缓冲      │
│  - 每个 1600 字节    │                     │  - 每个 1600 字节   │
│  - 总计 ~51 KB       │                     │  - 总计 ~3.2 MB     │
│  - 速率: SDIO 动态   │                     │  - 速率: 50 MHz     │
│  - 重试: 20 次       │                     │  - 读写: 50 MHz     │
└──────────┬──────────┘                     └──────────┬──────────┘
           │                                            │
           │ DMA 传输                             DMA 传输 │
           │ (SDIO 速率)                      (50 MHz)    │
           ▼                                            ▼
┌─────────────────────┐                     ┌─────────────────────┐
│   SDIO 驱动层       │ ◄─── SDIO BUS ───► │   WiFi (C6)         │
│  (esp_wifi_remote)  │                     │                     │
└─────────────────────┘                     └─────────────────────┘
           │                                            │
           │ DMA 接收                             DMA 接收 │
           │ (SDIO 速率)                      (SDIO 速率) │
           ▼                                            ▼
┌─────────────────────┐                     ┌─────────────────────┐
│  SDIO RX Buffer Pool │                     │  PSRAM TX Pool      │
│  (内部 RAM)          │                     │  (PSRAM)            │
│  - 32 个缓冲         │                     │  - 2048 个缓冲      │
│  - 每个 1600 字节    │                     │  - 每个 1600 字节   │
│  - 总计 ~51 KB       │                     │  - 总计 ~3.2 MB     │
│  - 速率: SDIO 动态   │                     │  - 速率: 50 MHz     │
│  - 重试: 20 次       │                     │  - 读写: 50 MHz     │
└──────────┬──────────┘                     └──────────┬──────────┘
           │                                            │
           │ DMA 搬移                             入队   │
           │ (50 MHz)                                   │
           ▼                                            ▼
┌─────────────────────────────────────────────────────────────────┐
│                      应用层任务                                   │
│              (wifi_to_eth_task / eth_to_wifi_task)              │
└─────────────────────────────────────────────────────────────────┘
           │                                            │
           │ 出队                                   入队  │
           ▼                                            ▼
   ┌──────────────┐                           ┌──────────────┐
   │ Ethernet TX  │                           │ Ethernet RX  │
   │  (EMAC)      │                           │  (EMAC)      │
   │  50 MHz      │                           │  50 MHz      │
   └──────────────┘                           └──────────────┘
```

---

## 详细设计

### 1. SDIO TX Buffer Pool（内部 RAM）

**用途**: SDIO 发送缓冲，从 PSRAM TX Pool 获取数据后通过 SDIO 发送到 C6

**规格**:
- **位置**: 内部 RAM (MALLOC_CAP_INTERNAL | MALLOC_CAP_DMA)
- **数量**: 32 个缓冲区
- **单个大小**: 1600 字节（1个 MTU）
- **总大小**: 51,200 字节（~50 KB）
- **访问速率**: 跟随 SDIO 协商时钟（动态）
- **重试机制**: 20 次重试
- **DMA**: 使用 GDMA 进行 PSRAM → 内部 RAM 搬移

**特点**:
- 小容量、高速
- 直接与 SDIO 驱动交互
- 允许 SDIO 层处理重试和流控
- 避免 SDIO 阻塞影响应用层

### 2. SDIO RX Buffer Pool（内部 RAM）

**用途**: SDIO 接收缓冲，从 C6 接收数据后搬移到 PSRAM RX Pool

**规格**:
- **位置**: 内部 RAM (MALLOC_CAP_INTERNAL | MALLOC_CAP_DMA)
- **数量**: 32 个缓冲区
- **单个大小**: 1600 字节
- **总大小**: 51,200 字节（~50 KB）
- **访问速率**: 跟随 SDIO 协商时钟（动态）
- **重试机制**: 20 次重试
- **DMA**: 使用 GDMA 进行内部 RAM → PSRAM 搬移（50 MHz）

**特点**:
- 接收侧对应的内部 RAM 缓冲
- 快速接收 SDIO 数据
- 通过 DMA 异步搬移到 PSRAM

### 3. PSRAM TX Pool

**用途**: Ethernet → WiFi 路径的大容量缓冲

**规格**:
- **位置**: PSRAM (MALLOC_CAP_SPIRAM)
- **数量**: 2048 个缓冲区
- **单个大小**: 1600 字节
- **总大小**: 3,276,800 字节（~3.2 MB）
- **访问速率**: 固定 50 MHz（PSRAM 时钟的 1/4）
- **DMA 搬移速率**: 50 MHz（与 EMAC 时钟匹配）

**特点**:
- 大容量缓冲
- 固定访问速率，避免时钟域冲突
- 与 EMAC 时钟同步（50 MHz）
- 解耦 Ethernet 和 SDIO 速度差异

### 4. PSRAM RX Pool

**用途**: WiFi → Ethernet 路径的大容量缓冲

**规格**:
- **位置**: PSRAM (MALLOC_CAP_SPIRAM)
- **数量**: 2048 个缓冲区
- **单个大小**: 1600 字节
- **总大小**: 3,276,800 字节（~3.2 MB）
- **访问速率**: 固定 50 MHz
- **DMA 搬移速率**: 50 MHz

**特点**:
- 接收侧对应的 PSRAM 缓冲
- 从 SDIO RX Buffer Pool 接收数据
- 以固定速率供 EMAC 读取

---

## 数据流路径

### Ethernet → WiFi (下行)

```
1. EMAC RX → PSRAM TX Pool (50 MHz DMA)
   - 应用层: wired_recv_callback() 入队到 PSRAM TX Pool
   
2. PSRAM TX Pool → SDIO TX Buffer Pool (50 MHz DMA)
   - DMA 任务: 批量搬移，每次搬移 8-16 个包
   - 速率控制: 50 MHz 固定时钟
   
3. SDIO TX Buffer Pool → SDIO 驱动 → C6 (SDIO 动态时钟)
   - SDIO 任务: 从内部 RAM 缓冲池取包
   - 调用 wifi_remote_tx()
   - SDIO 驱动层处理 20 次重试
   - 失败后丢弃并记录错误
```

### WiFi → Ethernet (上行)

```
1. C6 → SDIO 驱动 → SDIO RX Buffer Pool (SDIO 动态时钟)
   - SDIO 驱动: 接收到内部 RAM 缓冲池
   - wifi_recv_callback() 触发
   
2. SDIO RX Buffer Pool → PSRAM RX Pool (50 MHz DMA)
   - DMA 任务: 异步搬移到 PSRAM
   - 速率控制: 50 MHz 固定时钟
   - 避免阻塞 SDIO 接收
   
3. PSRAM RX Pool → EMAC TX (50 MHz DMA)
   - 应用层: wifi_to_eth_task() 从 PSRAM RX Pool 取包
   - 调用 wired_send() 发送到 EMAC
```

---

## DMA 配置

### GDMA 通道分配

```c
// 4 个 DMA 通道
#define DMA_CHAN_PSRAM_TO_INTERNAL_TX   0  // PSRAM TX → SDIO TX
#define DMA_CHAN_INTERNAL_TO_PSRAM_RX   1  // SDIO RX → PSRAM RX
#define DMA_CHAN_EMAC_TO_PSRAM_TX       2  // EMAC → PSRAM TX
#define DMA_CHAN_PSRAM_TO_EMAC_RX       3  // PSRAM RX → EMAC
```

### DMA 传输参数

```c
// PSRAM 访问 DMA 配置（50 MHz）
typedef struct {
    uint32_t burst_size;        // 16 字节对齐
    uint32_t transfer_size;     // 每次传输大小
    uint32_t clock_div;         // 时钟分频器（200MHz / 4 = 50MHz）
    bool enable_circular;       // 循环 DMA
    bool enable_interrupt;      // 完成中断
} psram_dma_config_t;

// SDIO 缓冲 DMA 配置（跟随 SDIO 时钟）
typedef struct {
    uint32_t burst_size;        // 64 字节对齐（SDIO 块大小）
    uint32_t transfer_size;     // 每次传输大小
    bool auto_reload;           // 自动重载
    bool enable_timeout;        // 超时保护
    uint32_t timeout_ms;        // 超时时间（避免锁死）
} sdio_dma_config_t;
```

---

## 防锁死机制

### 1. DMA 超时保护

```c
// 每个 DMA 传输设置超时
#define DMA_TRANSFER_TIMEOUT_MS  100  // 100ms 超时

// DMA 传输函数
esp_err_t dma_transfer_with_timeout(dma_channel_t channel, 
                                    void *src, void *dst, 
                                    size_t len) {
    // 启动 DMA
    dma_start(channel, src, dst, len);
    
    // 等待完成，带超时
    TickType_t start = xTaskGetTickCount();
    while (!dma_is_done(channel)) {
        if (xTaskGetTickCount() - start > pdMS_TO_TICKS(DMA_TRANSFER_TIMEOUT_MS)) {
            dma_abort(channel);
            ESP_LOGE(TAG, "DMA timeout on channel %d", channel);
            return ESP_ERR_TIMEOUT;
        }
        vTaskDelay(pdMS_TO_TICKS(1));
    }
    
    return ESP_OK;
}
```

### 2. 缓冲池满处理

```c
// 内部 RAM 缓冲池满时的处理
if (sdio_tx_pool_full()) {
    // 不阻塞，直接丢弃并记录
    s_stats.sdio_tx_pool_full++;
    ESP_LOGW(TAG, "SDIO TX pool full, dropping packet");
    return ESP_ERR_NO_MEM;
}

// PSRAM 缓冲池满时的处理
if (psram_tx_pool_full()) {
    // 记录统计
    s_stats.psram_tx_pool_full++;
    ESP_LOGW(TAG, "PSRAM TX pool full, dropping packet");
    return ESP_ERR_NO_MEM;
}
```

### 3. DMA 死锁检测

```c
// DMA 健康监控任务
void dma_watchdog_task(void *arg) {
    static uint32_t last_transfer_count[4] = {0};
    
    while (1) {
        vTaskDelay(pdMS_TO_TICKS(5000));  // 每 5 秒检查
        
        for (int i = 0; i < 4; i++) {
            uint32_t current = dma_get_transfer_count(i);
            if (current == last_transfer_count[i]) {
                // DMA 通道停滞
                if (dma_is_busy(i)) {
                    ESP_LOGE(TAG, "DMA channel %d stalled, resetting", i);
                    dma_reset(i);
                }
            }
            last_transfer_count[i] = current;
        }
    }
}
```

---

## 实现步骤

### Phase 1: 数据结构和缓冲池（2-3 天）

1. **修改 `packet_buffer_pool.h/c`**:
   - 添加 4 个独立的缓冲池类型
   - 实现内部 RAM 分配器
   - 实现 PSRAM 固定速率访问包装器

```c
typedef enum {
    POOL_SDIO_TX,      // 内部 RAM, 32 buffers
    POOL_SDIO_RX,      // 内部 RAM, 32 buffers
    POOL_PSRAM_TX,     // PSRAM, 2048 buffers
    POOL_PSRAM_RX,     // PSRAM, 2048 buffers
} buffer_pool_type_t;

// 初始化所有缓冲池
esp_err_t buffer_pools_init(void);

// 分配/释放（自动从正确的池中）
packet_buffer_t* buffer_alloc(buffer_pool_type_t type, size_t len);
void buffer_free(packet_buffer_t *pkt);
```

2. **内存计算**:
   - 内部 RAM: 2 × 32 × 1600 = 102,400 字节 (~100 KB)
   - PSRAM: 2 × 2048 × 1600 = 6,553,600 字节 (~6.4 MB)
   - 总计: ~6.5 MB

### Phase 2: DMA 传输层（3-4 天）

1. **创建 `dma_transfer.h/c`**:
   - GDMA 通道管理
   - 50 MHz 时钟配置
   - 超时保护
   - 批量传输优化

```c
// DMA 批量传输（PSRAM → 内部 RAM）
esp_err_t dma_batch_transfer_psram_to_internal(
    buffer_pool_type_t src_pool,
    buffer_pool_type_t dst_pool,
    uint32_t max_packets);

// DMA 批量传输（内部 RAM → PSRAM）
esp_err_t dma_batch_transfer_internal_to_psram(
    buffer_pool_type_t src_pool,
    buffer_pool_type_t dst_pool,
    uint32_t max_packets);
```

2. **DMA 任务**:
   - 创建 4 个 DMA 搬移任务（优先级 15，高于应用层）
   - 每个任务负责一个方向的数据搬移
   - 使用信号量触发（避免轮询）

### Phase 3: 应用层集成（2-3 天）

1. **修改 `sta2eth_main.c`**:
   - 更新 `eth_to_wifi_task` 使用 PSRAM TX Pool
   - 更新 `wifi_to_eth_task` 使用 PSRAM RX Pool
   - 移除所有重试逻辑（已完成）

2. **修改 SDIO 层**:
   - 创建 SDIO 发送/接收任务
   - 使用 SDIO TX/RX Buffer Pool
   - 实现 20 次重试逻辑

### Phase 4: 测试和优化（2-3 天）

1. **单元测试**:
   - 缓冲池分配/释放
   - DMA 传输正确性
   - 超时处理

2. **集成测试**:
   - 端到端数据流
   - 高负载压力测试
   - 锁死场景测试

3. **性能优化**:
   - 调整 DMA 批量大小
   - 优化任务优先级
   - 减少上下文切换

**总估计**: 9-13 天开发时间

---

## 配置参数

### sdkconfig 选项

```ini
# 内部 RAM 缓冲池配置
CONFIG_SDIO_TX_BUFFER_COUNT=32
CONFIG_SDIO_RX_BUFFER_COUNT=32
CONFIG_SDIO_BUFFER_SIZE=1600
CONFIG_SDIO_RETRY_COUNT=20

# PSRAM 缓冲池配置
CONFIG_PSRAM_TX_BUFFER_COUNT=2048
CONFIG_PSRAM_RX_BUFFER_COUNT=2048
CONFIG_PSRAM_BUFFER_SIZE=1600

# DMA 配置
CONFIG_DMA_PSRAM_CLOCK_DIV=4          # 200MHz / 4 = 50MHz
CONFIG_DMA_TRANSFER_TIMEOUT_MS=100
CONFIG_DMA_BATCH_SIZE=16               # 每次批量传输 16 个包

# 防锁死配置
CONFIG_DMA_WATCHDOG_ENABLED=y
CONFIG_DMA_WATCHDOG_INTERVAL_MS=5000
```

---

## 性能指标

### 理论吞吐量

- **SDIO**: ~200 Mbps（取决于协商结果）
- **PSRAM → 内部 RAM**: 50 MHz × 32-bit = 200 MB/s = 1600 Mbps
- **EMAC**: 100 Mbps（Fast Ethernet）

### 延迟

- **Ethernet → WiFi 路径**:
  - EMAC → PSRAM: <1 ms
  - PSRAM → 内部 RAM: ~5 ms（批量传输）
  - 内部 RAM → SDIO: <10 ms（含重试）
  - **总延迟**: ~16 ms

- **WiFi → Ethernet 路径**:
  - SDIO → 内部 RAM: <10 ms
  - 内部 RAM → PSRAM: ~5 ms
  - PSRAM → EMAC: <1 ms
  - **总延迟**: ~16 ms

### 缓冲容量

- **突发吸收能力**: 
  - PSRAM: 2048 × 1600 = 3.2 MB
  - 可吸收 ~25 秒的 100 Mbps 流量

---

## 注意事项

1. **内存对齐**: 所有 DMA 缓冲区必须满足对齐要求
   - 内部 RAM: 4 字节对齐
   - PSRAM: 64 字节对齐（cache line）

2. **Cache 一致性**: PSRAM 访问需要考虑 cache 刷新
   ```c
   // 写入 PSRAM 前
   esp_cache_flush(buffer, len);
   
   // 从 PSRAM 读取后
   esp_cache_invalidate(buffer, len);
   ```

3. **优先级**: 
   - DMA 任务: 优先级 15
   - 应用任务: 优先级 10
   - 统计任务: 优先级 3

4. **错误恢复**: 所有 DMA 超时必须触发通道重置

---

## 后续优化

1. **零拷贝**: 尝试减少数据复制次数
2. **动态调整**: 根据流量动态调整 DMA 批量大小
3. **功耗优化**: 空闲时降低 DMA 频率
4. **统计监控**: 详细的性能计数器

---

**文档版本**: 1.0  
**创建日期**: 2025-11-09  
**适用项目**: sta2eth (ESP32-P4 + ESP32-C6)  
**状态**: 设计阶段 - 待实现
