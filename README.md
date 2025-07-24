# 智能充电桩系统 (Smart Charging Station System)

## 📖 项目简介

本项目是一个基于Linux的智能充电桩管理系统，使用LVGL图形库构建用户界面，支持触摸屏操作。系统实现了用户认证、充电管理、支付结算、商家管理等核心功能，适用于新能源汽车充电桩的商业化运营。

## ✨ 主要特性

- 🎨 **现代化UI界面**: 基于LVGL 9.1.0图形库，支持触摸屏操作
- 👥 **双用户系统**: 支持顾客和商家两种用户类型
- 🔋 **智能充电管理**: 支持快充/慢充模式，实时监控充电状态
- 💰 **多样化支付**: 支持微信支付、支付宝、钱包余额支付
- 🖥️ **商家控制台**: 提供用户管理、余额操作等管理功能
- 📊 **实时数据监控**: 显示功率、电流、电压等充电参数
- 🔐 **安全认证**: 基于文件的用户认证系统

## 🛠️ 技术栈

### 核心技术
- **GUI框架**: LVGL 9.1.0 - 轻量级嵌入式图形库
- **开发语言**: C语言
- **构建系统**: Makefile
- **目标平台**: Linux (支持ARM交叉编译)

### 图形后端支持
- **Linux Framebuffer (fbdev)**: 直接访问帧缓冲设备
- **DRM/KMS**: 现代Linux图形显示栈
- **SDL2**: 跨平台多媒体库(用于开发调试)

### 输入设备支持
- **Evdev**: Linux事件设备接口，支持触摸屏
- **键盘/鼠标**: 通过evdev或SDL2支持

### 系统组件
- **用户认证系统**: 基于文件的用户管理
- **充电管理系统**: 实时充电状态监控和控制
- **商家控制台**: 终端命令行管理界面
- **支付系统**: 多种支付方式集成

## 📁 项目结构

```
lv_port_linux/
├── README.md                    # 项目说明文档
├── main.c                       # 主程序入口
├── lv_conf.h                    # LVGL配置文件
├── Makefile                     # 构建配置
├── check_touch.sh               # 触摸设备诊断脚本
├── customer_users.txt           # 顾客用户数据
├── merchant_users.txt           # 商家用户数据
├── src/                         # 业务逻辑模块
│   ├── user_auth.c/.h          # 用户认证系统
│   ├── charging_system.c/.h    # 充电管理系统
│   └── merchant_console.c/.h   # 商家控制台
├── ui/                          # 用户界面模块
│   ├── ui.c/.h                 # UI主文件
│   ├── ui_events.h             # UI事件处理
│   ├── ui_helpers.c/.h         # UI辅助函数
│   ├── screens/                # 界面屏幕
│   │   ├── ui_Screen1.c        # 主界面
│   │   ├── ui_Screen2.c        # 用户选择界面
│   │   ├── ui_Screen3.c        # 登录界面
│   │   ├── ui_Screen4.c        # 注册界面
│   │   ├── ui_Screen5.c        # 充电模式选择
│   │   ├── ui_Screen6.c        # 充电进行界面
│   │   ├── ui_Screen7.c        # 结算界面
│   │   ├── ui_Screen8.c        # 支付方式选择
│   │   ├── ui_Screen9.c        # 支付完成界面
│   │   ├── ui_Screen10.c       # 顾客主界面
│   │   └── ui_Screen11.c       # 商家管理界面
│   ├── components/             # UI组件
│   ├── fonts/                  # 字体文件
│   └── images/                 # 图片资源
├── lvgl/                       # LVGL图形库
└── build/                      # 构建输出目录
```

## 🔄 系统流程

### 1. 启动流程
```
系统初始化 → 图形设备初始化 → 触摸设备配置 → 用户认证系统初始化 → 充电系统初始化 → UI界面启动
```

### 2. 用户使用流程

#### 顾客使用流程
```
主界面 → 选择用户类型(顾客) → 登录/注册 → 顾客主界面 → 选择充电模式 → 开始充电 → 充电监控 → 结算 → 选择支付方式 → 支付完成
```

#### 商家管理流程
```
主界面 → 选择用户类型(商家) → 商家登录 → 商家管理界面 → 控制台操作(查看用户、管理余额等)
```

### 3. 商家控制台命令
- `help` - 显示帮助信息
- `list` - 查看所有用户信息
- `balance <用户名>` - 查看指定用户余额
- `set <用户名> <金额>` - 设置用户余额
- `add <用户名> <金额>` - 为用户充值
- `exit` - 退出控制台

## 🚀 快速开始

### 环境要求
- Linux操作系统 (推荐Ubuntu 18.04+)
- GCC编译器或ARM交叉编译工具链
- 支持Framebuffer的显示设备
- 触摸屏设备 (可选)

### 编译安装

1. **克隆项目**
```bash
git clone git@gitee.com:chaojineko/test2.git
cd lv_port_linux
```

2. **安装依赖** (如果使用SDL2后端)
```bash
sudo apt-get update
sudo apt-get install libsdl2-dev
```

3. **配置图形后端** (可选)
编辑 `lv_conf.h` 文件：
- 使用Framebuffer: `#define LV_USE_LINUX_FBDEV 1`
- 使用SDL2: `#define LV_USE_SDL 1`

4. **编译项目**
```bash
# 本地编译
make clean && make

# ARM交叉编译 (需要配置交叉编译工具链)
make clean && make CC=arm-linux-gnueabihf-gcc
```

5. **运行程序**
```bash
# 需要root权限访问设备节点
sudo ./build/bin/main
```

### 设备配置

1. **触摸屏配置**
- 确保触摸设备在 `/dev/input/eventX` 下可用
- 运行诊断脚本检查设备状态：
```bash
chmod +x check_touch.sh
./check_touch.sh
```

2. **屏幕分辨率配置**
- 在 `main.c` 中调整校准参数：
```c
lv_evdev_set_calibration(touch, 0, 0, 800, 480); // 根据实际触摸屏尺寸调整
```

3. **用户数据初始化**
- 系统会自动创建默认用户文件
- 默认商家账号: `666666/666666`

## 🔧 配置说明

### LVGL配置 (`lv_conf.h`)
- `LV_COLOR_DEPTH`: 颜色深度设置
- `LV_USE_LINUX_FBDEV`: 启用Linux Framebuffer支持
- `LV_USE_EVDEV`: 启用evdev输入设备支持
- `LV_USE_FREETYPE`: 字体渲染支持 (已禁用以减少依赖)

### 系统参数
- 充电功率范围: 7kW - 120kW (可在代码中调整)
- 充电费率: 1.5元/kWh
- 支持的支付方式: 微信支付、支付宝、钱包余额

## 🐛 故障排除

### 常见问题

1. **触摸不响应**
   - 检查设备权限: `ls -la /dev/input/event*`
   - 使用 `evtest` 工具测试触摸设备
   - 确认触摸校准参数正确

2. **编译错误**
   - 检查是否安装了必要的开发库
   - 确认交叉编译工具链配置正确
   - 查看具体错误信息调整配置

3. **界面显示异常**
   - 检查framebuffer设备: `ls -la /dev/fb*`
   - 确认屏幕分辨率配置
   - 检查LVGL配置参数

### 调试技巧
- 启用LVGL日志输出查看详细信息
- 使用 `printf` 添加调试信息
- 检查系统日志: `dmesg | grep input`

## 📄 许可证

本项目基于MIT许可证开源 - 查看 [LICENSE](LICENSE) 文件了解详情。

## 🙏 致谢

- [LVGL](https://lvgl.io/) - 优秀的嵌入式图形库
- [lv_port_linux](https://github.com/lvgl/lv_port_linux) - Linux移植基础框架

---

⭐ 如果这个项目对你有帮助，请给个Star支持一下！

```