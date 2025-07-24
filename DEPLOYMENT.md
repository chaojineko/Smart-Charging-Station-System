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
git clone git@gitee.com:chaojineko/test2.git
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