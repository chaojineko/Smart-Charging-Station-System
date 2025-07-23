# 快速开始指南

## 🚀 5分钟快速体验

### 方式一: SDL2桌面模拟 (推荐用于开发测试)

1. **安装依赖**
```bash
sudo apt-get update
sudo apt-get install libsdl2-dev build-essential
```

2. **配置SDL2模式**
```bash
# 编辑lv_conf.h，确保SDL2启用
sed -i 's/#define LV_USE_LINUX_FBDEV.*1/#define LV_USE_LINUX_FBDEV 0/' lv_conf.h
sed -i 's/#define LV_USE_SDL.*0/#define LV_USE_SDL 1/' lv_conf.h
```

3. **编译运行**
```bash
make clean && make
./build/bin/main
```

4. **开始体验**
   - 点击界面上的按钮进行操作
   - 默认商家账号: `666666` / `666666`
   - 可以注册新的顾客账号进行充电体验

### 方式二: 树莓派/ARM板部署

1. **下载预编译版本** (如果提供)
```bash
wget https://github.com/your-repo/releases/latest/charging-station-arm.tar.gz
tar -xzf charging-station-arm.tar.gz
cd charging-station
```

2. **或从源码编译**
```bash
# 安装交叉编译工具链
sudo apt-get install gcc-arm-linux-gnueabihf

# 编译
make clean && make CC=arm-linux-gnueabihf-gcc
```

3. **传输到目标设备**
```bash
scp -r build/ *.txt *.sh pi@<raspberry-pi-ip>:~/charging-station/
```

4. **在树莓派上运行**
```bash
ssh pi@<raspberry-pi-ip>
cd charging-station
sudo ./build/bin/main
```

## 📱 功能演示路径

### 顾客充电流程
1. **启动应用** → 主界面
2. **点击"顾客"** → 用户类型选择
3. **新用户注册** → 输入用户名、密码
4. **登录成功** → 顾客主界面
5. **选择充电模式** → 快充(120kW) 或 慢充(7kW)
6. **开始充电** → 观察实时充电数据
7. **停止充电** → 查看结算信息
8. **选择支付方式** → 微信/支付宝/余额支付
9. **支付完成** → 充电结束

### 商家管理流程
1. **启动应用** → 主界面
2. **点击"商家"** → 用户类型选择
3. **商家登录** → 用户名: `666666`, 密码: `666666`
4. **进入管理界面** → 商家控制台启动
5. **在终端输入命令**:
   - `list` - 查看所有用户
   - `balance 用户名` - 查看用户余额
   - `set 用户名 金额` - 设置用户余额
   - `add 用户名 金额` - 为用户充值
   - `help` - 查看帮助
   - `exit` - 退出

## 🔧 常用配置

### 屏幕分辨率调整
编辑 `main.c` 文件:
```c
// 找到这行代码，根据你的屏幕调整
lv_evdev_set_calibration(touch, 0, 0, 800, 480); // 800x480
// 或
lv_evdev_set_calibration(touch, 0, 0, 1024, 600); // 1024x600
```

### 触摸设备调试
```bash
# 运行诊断脚本
./check_touch.sh

# 手动测试触摸设备
sudo evtest /dev/input/event0  # 或event1, event2
```

### 用户数据管理
```bash
# 查看现有用户
cat customer_users.txt  # 顾客用户
cat merchant_users.txt  # 商家用户

# 手动添加用户 (格式: 用户名:密码:余额)
echo "testuser:123456:100.00" >> customer_users.txt
```

## 💡 开发技巧

### 添加调试信息
在代码中添加 `printf` 语句:
```c
printf("调试信息: 当前充电功率 = %.2f kW\n", power);
```

### 修改界面布局
1. 使用 SquareLine Studio 编辑UI文件
2. 导出代码替换 `ui/` 目录下的文件
3. 重新编译运行

### 自定义充电参数
编辑 `src/charging_system.c`:
```c
// 修改充电功率
#define FAST_CHARGING_POWER 120.0  // 快充功率(kW)
#define SLOW_CHARGING_POWER 7.0    // 慢充功率(kW)

// 修改费率
#define CHARGING_RATE 1.5  // 元/kWh
```

## 🐛 问题解决

### 编译失败
```bash
# 清理并重新编译
make clean
make

# 检查错误信息，通常是缺少依赖库
sudo apt-get install build-essential
```

### 触摸不工作
```bash
# 检查设备权限
ls -la /dev/input/event*

# 尝试不同的event设备
# 修改main.c中的设备路径
lv_evdev_create(LV_INDEV_TYPE_POINTER, "/dev/input/event1");
```

### 界面显示异常
```bash
# 检查framebuffer
cat /sys/class/graphics/fb0/virtual_size

# 调整颜色深度 (lv_conf.h)
#define LV_COLOR_DEPTH 16  // 或32
```

### 程序崩溃
```bash
# 使用GDB调试
gdb ./build/bin/main
(gdb) run
(gdb) bt  # 查看崩溃堆栈
```

## 📚 进阶学习

### LVGL学习资源
- [LVGL官方文档](https://docs.lvgl.io/)
- [LVGL GitHub](https://github.com/lvgl/lvgl)
- [SquareLine Studio](https://squareline.io/) - 可视化UI设计工具

### Linux嵌入式开发
- [Buildroot](https://buildroot.org/) - 构建嵌入式Linux系统
- [Yocto Project](https://www.yoctoproject.org/) - 嵌入式Linux发行版构建

### 硬件集成
- 学习CAN总线通信接入实际充电桩硬件
- 集成支付模块(微信/支付宝SDK)
- 添加RFID卡片识别功能
- 接入云端管理平台

## 🔄 版本更新

### 获取最新版本
```bash
git pull origin main
git submodule update --recursive
make clean && make
```

### 备份用户数据
```bash
cp customer_users.txt customer_users.backup
cp merchant_users.txt merchant_users.backup
```

---

🎉 **恭喜！** 你已经成功运行了智能充电桩系统！

如有问题，请查看详细的 [README.md](README.md) 或提交 [GitHub Issue](https://github.com/your-repo/issues)。
