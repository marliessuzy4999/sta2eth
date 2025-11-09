# ESP32-C6 OTA 升级功能需求文档

## 概述

本文档详细说明了在 ESP32-P4 + ESP32-C6 sta2eth 项目中实现 C6 固件 OTA 升级功能的需求和技术方案。

### 问题背景

当前遇到的问题：
```
W (2598) transport: === ESP-Hosted Version Warning ===
Version on Host is NEWER than version on co-processor
RPC requests sent by host may encounter timeout errors
or may not be supported by co-processor
```

C6 固件版本过旧，但开发板上难以手动升级，需要实现自动化的 OTA 升级机制。

## 功能需求

### 1. 固件版本检测

**目标**: 在 P4 启动时检测 C6 固件版本并与 P4 侧期望版本比较

**需求细节**:
- P4 启动后等待 C6 SDIO 就绪
- 通过 ESP-Hosted 控制通道查询 C6 固件版本
- 比较 C6 版本与 P4 期望的最低版本
- 设置超时机制（建议 10-15 秒）处理 C6 固件损坏的情况

**技术参考**:
- ESP-Hosted 版本协议: https://github.com/espressif/esp-hosted/blob/master/docs/common/version_handshake.md
- 控制路径 API: https://github.com/espressif/esp-hosted/blob/master/host/control_lib/include/ctrl_api.h

### 2. OTA 升级模式触发

**触发条件**:
1. C6 固件版本低于 P4 期望的最低版本
2. C6 固件无响应或损坏（超时）
3. 手动触发（可选：通过按钮或配置接口）

**行为**:
- 在检测 WiFi 凭据之前进入 OTA 模式
- 跳过正常的 WiFi 连接流程
- 启动专用的 OTA Web 服务器

### 3. OTA Web 服务器

**功能要求**:

#### 3.1 网络配置
- **IP 段**: 使用专用 IP 段，建议 `192.168.100.0/24`
  - P4 (Ethernet): `192.168.100.1`
  - DHCP 范围: `192.168.100.100-192.168.100.200`
- **端口**: HTTP 80 或 HTTPS 443
- **协议**: 优先使用 HTTP（简化实现），可选 HTTPS

#### 3.2 Web 界面功能
1. **固件上传页面**
   - 显示当前 C6 固件版本（如果可获取）
   - 显示 P4 期望的最低版本
   - 文件上传控件（支持 .bin 文件）
   - 上传进度显示
   - 上传完成/失败提示

2. **C6 优化参数配置**（可选）
   - SDIO 时钟速度设置
   - RX/TX 缓冲区大小
   - 网络分割开关
   - 电源管理选项
   - 调试日志级别

3. **升级状态监控**
   - 实时显示升级进度
   - 显示 C6 日志输出（如果可用）
   - 升级成功后自动重启选项

#### 3.3 技术实现
- **HTTP 服务器**: ESP-IDF HTTP Server
  - 文档: https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/protocols/esp_http_server.html
  - 示例: https://github.com/espressif/esp-idf/tree/master/examples/protocols/http_server

- **文件上传处理**: Multipart form data
  - 示例: https://github.com/espressif/esp-idf/blob/master/examples/protocols/http_server/file_serving/main/file_server.c

### 4. OTA 升级流程

**步骤**:

1. **准备阶段**
   - P4 接收固件文件到 PSRAM 缓冲区
   - 验证固件文件格式（ESP32-C6 image header）
   - 计算并验证 SHA256 校验和（可选）

2. **传输阶段**
   - 通过 ESP-Hosted 控制通道通知 C6 进入 OTA 模式
   - 使用 SDIO 数据通道传输固件数据到 C6
   - 分块传输，每块建议 4KB-8KB
   - 传输进度反馈到 Web 界面

3. **验证阶段**
   - C6 验证接收到的固件
   - C6 返回验证结果
   - 如果失败，允许重试（最多 3 次）

4. **应用阶段**
   - C6 将新固件写入 OTA 分区
   - 设置启动分区
   - C6 重启
   - P4 等待 C6 重新连接并验证新版本

**技术参考**:
- ESP OTA API: https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/system/ota.html
- ESP-Hosted OTA: https://github.com/espressif/esp-hosted/tree/master/host/host_ota

### 5. 错误处理

**超时处理**:
- SDIO 就绪超时: 15 秒
- 版本查询超时: 10 秒
- OTA 传输超时: 每块 5 秒
- C6 重启等待: 30 秒

**错误恢复**:
- 传输失败: 自动重试 3 次
- 验证失败: 回滚到旧版本（C6 侧自动）
- 升级失败: 显示错误信息，允许重新尝试
- 致命错误: 降级到最小可用模式，仅保留 OTA 功能

### 6. 安全考虑

**可选安全功能**:
1. **固件签名验证**
   - 使用 ESP32 Secure Boot 机制
   - 文档: https://docs.espressif.com/projects/esp-idf/en/latest/esp32/security/secure-boot-v2.html

2. **HTTPS 传输**
   - 使用 TLS 加密固件传输
   - 自签名证书或 Let's Encrypt

3. **访问控制**
   - Web 界面密码保护
   - IP 白名单（仅允许特定 IP 访问）

## 技术实现方案

### 架构设计

```
┌─────────────────────────────────────────────────────────┐
│                      PC (OTA 客户端)                      │
│                   192.168.100.100                        │
└──────────────────────┬──────────────────────────────────┘
                       │ Ethernet
                       │ HTTP POST (固件.bin)
┌──────────────────────▼──────────────────────────────────┐
│                    ESP32-P4 (主机)                        │
│  ┌─────────────────────────────────────────────────┐   │
│  │         OTA Web 服务器 (端口 80)                 │   │
│  │  - 固件上传界面                                  │   │
│  │  - 配置界面                                      │   │
│  │  - 状态监控                                      │   │
│  └─────────────────────┬───────────────────────────┘   │
│                        │                                 │
│  ┌─────────────────────▼───────────────────────────┐   │
│  │      OTA 管理器                                  │   │
│  │  - 固件验证                                      │   │
│  │  - PSRAM 缓冲                                   │   │
│  │  - 进度追踪                                      │   │
│  └─────────────────────┬───────────────────────────┘   │
│                        │                                 │
│  ┌─────────────────────▼───────────────────────────┐   │
│  │      ESP-Hosted 主机驱动                         │   │
│  │  - 控制通道 (版本查询/OTA 命令)                 │   │
│  │  - 数据通道 (固件传输)                          │   │
│  └─────────────────────┬───────────────────────────┘   │
└────────────────────────┼───────────────────────────────┘
                         │ SDIO
┌────────────────────────▼───────────────────────────────┐
│                   ESP32-C6 (从机)                        │
│  ┌──────────────────────────────────────────────────┐  │
│  │      ESP-Hosted 从机固件                          │  │
│  │  - 控制路径处理                                   │  │
│  │  - OTA 接收器                                    │  │
│  └─────────────────────┬────────────────────────────┘  │
│                        │                                │
│  ┌─────────────────────▼────────────────────────────┐  │
│  │      ESP32 OTA 子系统                             │  │
│  │  - 分区管理                                       │  │
│  │  - 固件写入                                       │  │
│  │  - 启动验证                                       │  │
│  └───────────────────────────────────────────────────┘  │
└─────────────────────────────────────────────────────────┘
```

### 关键组件

#### 1. 版本检测模块
```c
// 文件: main/c6_version_check.c

typedef struct {
    uint8_t major;
    uint8_t minor;
    uint8_t patch;
    char git_hash[8];
} firmware_version_t;

// 查询 C6 固件版本
esp_err_t c6_get_firmware_version(firmware_version_t *version, uint32_t timeout_ms);

// 比较版本
bool c6_version_is_compatible(firmware_version_t *c6_ver, firmware_version_t *min_ver);
```

#### 2. OTA Web 服务器
```c
// 文件: main/ota_webserver.c

// 启动 OTA 专用 Web 服务器
esp_err_t ota_webserver_start(void);

// 停止 Web 服务器
void ota_webserver_stop(void);

// 处理固件上传
esp_err_t handle_firmware_upload(httpd_req_t *req);

// 处理配置更新
esp_err_t handle_config_update(httpd_req_t *req);
```

#### 3. OTA 传输管理器
```c
// 文件: main/c6_ota_manager.c

// 初始化 OTA 会话
esp_err_t c6_ota_begin(size_t firmware_size);

// 传输固件数据块
esp_err_t c6_ota_write(const uint8_t *data, size_t len);

// 完成 OTA 并触发 C6 重启
esp_err_t c6_ota_end(void);

// 取消 OTA
void c6_ota_abort(void);

// 获取进度
uint8_t c6_ota_get_progress(void);
```

### 配置参数

在 `sdkconfig.defaults.esp32p4` 添加:

```ini
# C6 OTA 配置
CONFIG_C6_OTA_ENABLED=y
CONFIG_C6_OTA_MIN_VERSION_MAJOR=1
CONFIG_C6_OTA_MIN_VERSION_MINOR=2
CONFIG_C6_OTA_MIN_VERSION_PATCH=0

# OTA Web 服务器配置
CONFIG_C6_OTA_WEBSERVER_PORT=80
CONFIG_C6_OTA_NETWORK_IP="192.168.100.1"
CONFIG_C6_OTA_NETWORK_NETMASK="255.255.255.0"
CONFIG_C6_OTA_DHCP_START="192.168.100.100"
CONFIG_C6_OTA_DHCP_END="192.168.100.200"

# 超时配置
CONFIG_C6_OTA_SDIO_READY_TIMEOUT_MS=15000
CONFIG_C6_OTA_VERSION_QUERY_TIMEOUT_MS=10000
CONFIG_C6_OTA_TRANSFER_CHUNK_TIMEOUT_MS=5000
CONFIG_C6_OTA_REBOOT_WAIT_TIMEOUT_MS=30000

# 缓冲配置
CONFIG_C6_OTA_BUFFER_SIZE=262144  # 256KB in PSRAM
CONFIG_C6_OTA_CHUNK_SIZE=8192     # 8KB chunks

# 重试配置
CONFIG_C6_OTA_MAX_RETRIES=3
```

## 开发步骤建议

### Phase 1: 版本检测 (1-2 天)
1. 实现 C6 版本查询功能
2. 添加版本比较逻辑
3. 集成到启动流程
4. 测试不同版本场景

### Phase 2: OTA Web 服务器 (3-4 天)
1. 搭建基础 HTTP 服务器
2. 实现固件上传界面
3. 添加文件处理逻辑
4. 实现状态监控页面
5. 添加配置界面（可选）

### Phase 3: OTA 传输机制 (3-5 天)
1. 实现 PSRAM 固件缓冲
2. 开发 SDIO 传输协议
3. 添加 C6 侧接收逻辑（需修改 ESP-Hosted 从机固件）
4. 实现进度追踪
5. 添加错误处理和重试

### Phase 4: 集成测试 (2-3 天)
1. 端到端 OTA 流程测试
2. 错误场景测试
3. 性能优化
4. 文档完善

**总估计**: 9-14 天开发时间

## 相关资源

### ESP-IDF 文档
- **OTA 更新**: https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/system/ota.html
- **ESP HTTPS OTA**: https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/system/esp_https_ota.html
- **HTTP 服务器**: https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/protocols/esp_http_server.html
- **分区表**: https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-guides/partition-tables.html

### GitHub 仓库
- **ESP-IDF**: https://github.com/espressif/esp-idf
- **ESP-Hosted**: https://github.com/espressif/esp-hosted
- **ESP-Hosted 文档**: https://github.com/espressif/esp-hosted/tree/master/docs

### 示例代码
- **简单 OTA**: https://github.com/espressif/esp-idf/tree/master/examples/system/ota/simple_ota_example
- **高级 OTA**: https://github.com/espressif/esp-idf/tree/master/examples/system/ota/advanced_https_ota
- **原生 OTA**: https://github.com/espressif/esp-idf/tree/master/examples/system/ota/native_ota_example
- **文件服务器**: https://github.com/espressif/esp-idf/tree/master/examples/protocols/http_server/file_serving
- **Captive Portal**: https://github.com/espressif/esp-idf/tree/master/examples/protocols/http_server/captive_portal

### ESP-Hosted 特定资源
- **主机 OTA**: https://github.com/espressif/esp-hosted/tree/master/host/host_ota
- **控制 API**: https://github.com/espressif/esp-hosted/blob/master/host/control_lib/include/ctrl_api.h
- **版本握手**: https://github.com/espressif/esp-hosted/blob/master/docs/common/version_handshake.md

## Web 界面设计参考

### 基础 HTML 结构
```html
<!DOCTYPE html>
<html>
<head>
    <title>ESP32-C6 OTA 升级</title>
    <style>
        /* 简洁的 CSS 样式 */
        body { font-family: Arial, sans-serif; margin: 40px; }
        .container { max-width: 600px; margin: auto; }
        .version-info { background: #f0f0f0; padding: 15px; margin: 20px 0; }
        .upload-form { border: 2px dashed #ccc; padding: 20px; text-align: center; }
        .progress-bar { width: 100%; height: 30px; background: #f0f0f0; margin: 20px 0; }
        .progress-fill { height: 100%; background: #4CAF50; width: 0%; transition: width 0.3s; }
        .status { margin: 20px 0; padding: 10px; }
        .success { background: #d4edda; color: #155724; }
        .error { background: #f8d7da; color: #721c24; }
        .warning { background: #fff3cd; color: #856404; }
    </style>
</head>
<body>
    <div class="container">
        <h1>ESP32-C6 固件 OTA 升级</h1>
        
        <div class="version-info">
            <h3>版本信息</h3>
            <p>当前 C6 版本: <strong id="current-version">检测中...</strong></p>
            <p>要求最低版本: <strong id="min-version">1.2.0</strong></p>
            <p>状态: <span id="version-status">等待检测</span></p>
        </div>
        
        <div class="upload-form">
            <h3>上传固件</h3>
            <input type="file" id="firmware-file" accept=".bin">
            <button onclick="uploadFirmware()">开始升级</button>
        </div>
        
        <div class="progress-bar" id="progress-container" style="display:none;">
            <div class="progress-fill" id="progress-fill"></div>
        </div>
        
        <div id="status-message"></div>
    </div>
    
    <script>
        // JavaScript 实现文件上传和进度显示
        function uploadFirmware() { /* 实现代码 */ }
    </script>
</body>
</html>
```

## 注意事项

1. **C6 从机固件需要修改**: 需要在 ESP-Hosted C6 从机固件中添加 OTA 接收功能
2. **分区表**: C6 需要配置为支持 OTA 的分区表（factory + ota_0 + ota_1）
3. **内存管理**: 使用 PSRAM 存储固件以避免内部 RAM 不足
4. **断电保护**: OTA 过程中断电可能导致 C6 变砖，建议添加恢复机制
5. **版本兼容性**: 确保新旧版本的 ESP-Hosted 协议兼容

## 后续扩展

可能的功能扩展:
- 自动固件下载（从云端）
- 固件回滚功能
- 批量设备 OTA（多个 C6）
- OTA 日志远程上传
- 固件差分升级（减少传输数据量）

---

**文档版本**: 1.0  
**创建日期**: 2025-11-09  
**适用项目**: sta2eth (ESP32-P4 + ESP32-C6)  
**作者**: GitHub Copilot
