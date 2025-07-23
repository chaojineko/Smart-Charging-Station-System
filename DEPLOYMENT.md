# 部署和安装指南

## 硬件要求

### 最低配置
- **处理器**: ARM Cortex-A7 1GHz 或更高
- **内存**: 512MB RAM (推荐1GB+)
- **存储**: 256MB可用空间
- **显示**: 支持Framebuffer的LCD显示器
- **分辨率**: 800x480 或 1024x600
- **触摸**: 电容式或电阻式触摸屏 (可选)

### 推荐配置
- **处理器**: ARM Cortex-A53 1.2GHz+
- **内存**: 1GB+ RAM
- **存储**: 2GB+ eMMC/SD卡
- **显示**: 7寸或10寸工业级LCD
- **接口**: USB、Ethernet、CAN总线

## 软件环境

### Linux内核要求
- 内核版本: 4.14+ (推荐5.4+)
- 必需的内核模块:
  - Framebuffer支持 (`CONFIG_FB=y`)
  - Input设备支持 (`CONFIG_INPUT=y`)
  - Evdev支持 (`CONFIG_INPUT_EVDEV=y`)
  - 触摸屏驱动

### 交叉编译工具链
```bash
# 安装ARM交叉编译工具链 (Ubuntu/Debian)
sudo apt-get install gcc-arm-linux-gnueabihf
sudo apt-get install g++-arm-linux-gnueabihf

# 或使用Linaro工具链
wget https://releases.linaro.org/components/toolchain/binaries/latest/arm-linux-gnueabihf/gcc-linaro-arm-linux-gnueabihf.tar.xz
tar -xf gcc-linaro-arm-linux-gnueabihf.tar.xz
export PATH=$PATH:/path/to/gcc-linaro-arm-linux-gnueabihf/bin
```

## 编译步骤

### 1. 环境准备
```bash
# 创建工作目录
mkdir -p ~/charging-station
cd ~/charging-station

# 克隆项目代码
git clone <your-repository-url> lv_port_linux
cd lv_port_linux
```

### 2. 配置编译选项
```bash
# 编辑Makefile设置交叉编译器
vim Makefile

# 修改以下行:
CC = arm-linux-gnueabihf-gcc
```

### 3. 调整配置文件
```bash
# 编辑lv_conf.h
vim lv_conf.h

# 确保以下配置正确:
#define LV_USE_LINUX_FBDEV 1
#define LV_USE_EVDEV       1
#define LV_USE_FREETYPE    0  // 减少依赖
```

### 4. 编译项目
```bash
# 清理之前的编译文件
make clean

# 编译项目
make -j$(nproc)

# 检查编译结果
ls -la build/bin/main
file build/bin/main  # 确认是ARM架构
```

## 目标设备部署

### 1. 文件传输
```bash
# 使用scp传输到目标设备
scp -r build/ root@<target-ip>:/opt/charging-station/
scp customer_users.txt merchant_users.txt root@<target-ip>:/opt/charging-station/
scp check_touch.sh root@<target-ip>:/opt/charging-station/
```

### 2. 设备环境配置
```bash
# 在目标设备上执行
ssh root@<target-ip>

# 创建必要目录
mkdir -p /opt/charging-station
cd /opt/charging-station

# 设置执行权限
chmod +x build/bin/main
chmod +x check_touch.sh

# 检查设备状态
./check_touch.sh
```

### 3. 系统服务配置
创建systemd服务文件 `/etc/systemd/system/charging-station.service`:

```ini
[Unit]
Description=Smart Charging Station Service
After=multi-user.target

[Service]
Type=simple
User=root
WorkingDirectory=/opt/charging-station
ExecStart=/opt/charging-station/build/bin/main
Restart=always
RestartSec=5
StandardOutput=journal
StandardError=journal

[Install]
WantedBy=multi-user.target
```

启用服务:
```bash
# 重新加载systemd配置
systemctl daemon-reload

# 启用服务
systemctl enable charging-station.service

# 启动服务
systemctl start charging-station.service

# 检查状态
systemctl status charging-station.service
```

## 设备特定配置

### 触摸屏校准
```bash
# 查找触摸设备
ls /dev/input/event*
cat /proc/bus/input/devices | grep -A 5 -B 5 Touch

# 测试触摸响应
evtest /dev/input/event0  # 替换为实际设备号

# 在main.c中调整校准参数
# lv_evdev_set_calibration(touch, 0, 0, 实际宽度, 实际高度);
```

### 显示器配置
```bash
# 检查framebuffer设备
ls -la /dev/fb*
cat /sys/class/graphics/fb0/virtual_size
cat /sys/class/graphics/fb0/bits_per_pixel

# 设置显示参数 (如果需要)
fbset -fb /dev/fb0 -g 800 480 800 480 32
```

### 网络配置 (可选)
```bash
# 配置静态IP (编辑/etc/network/interfaces)
auto eth0
iface eth0 inet static
    address 192.168.1.100
    netmask 255.255.255.0
    gateway 192.168.1.1
    dns-nameservers 8.8.8.8
```

## 自动启动脚本

创建启动脚本 `/opt/charging-station/start.sh`:

```bash
#!/bin/bash

# 设置环境变量
export DISPLAY=:0
export HOME=/root

# 切换到工作目录
cd /opt/charging-station

# 检查设备状态
echo "检查系统状态..."
./check_touch.sh

# 等待设备就绪
sleep 2

# 启动应用程序
echo "启动充电桩系统..."
./build/bin/main
```

设置权限并测试:
```bash
chmod +x /opt/charging-station/start.sh
/opt/charging-station/start.sh
```

## 故障排除

### 编译问题
1. **找不到头文件**: 检查交叉编译工具链安装
2. **链接错误**: 确认所有源文件都被正确编译
3. **架构不匹配**: 验证交叉编译器配置

### 运行时问题
1. **权限错误**: 确保以root权限运行或正确设置设备权限
2. **显示异常**: 检查framebuffer设备和分辨率配置
3. **触摸不响应**: 验证输入设备路径和权限

### 性能优化
1. **启动速度**: 禁用不必要的系统服务
2. **内存使用**: 调整LVGL内存配置
3. **响应性**: 优化定时器间隔和优先级

## 维护和更新

### 日志管理
```bash
# 查看应用日志
journalctl -u charging-station.service -f

# 清理旧日志
journalctl --vacuum-time=7d
```

### 备份用户数据
```bash
# 创建备份脚本
#!/bin/bash
DATE=$(date +%Y%m%d_%H%M%S)
cp customer_users.txt customer_users_$DATE.backup
cp merchant_users.txt merchant_users_$DATE.backup
```

### 远程更新
```bash
# 创建更新脚本
#!/bin/bash
systemctl stop charging-station.service
cp build/bin/main build/bin/main.backup
# 传输新版本
scp new_main root@<target-ip>:/opt/charging-station/build/bin/main
systemctl start charging-station.service
```
