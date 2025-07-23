#!/bin/bash

echo "===== 触摸设备诊断脚本 ====="

echo "1. 检查输入设备："
ls -la /dev/input/

echo ""
echo "2. 检查event设备权限："
for i in {0..9}; do
    if [ -e "/dev/input/event$i" ]; then
        echo "  /dev/input/event$i: $(ls -la /dev/input/event$i)"
        echo "    设备信息: $(cat /sys/class/input/event$i/device/name 2>/dev/null || echo '未知')"
    fi
done

echo ""
echo "3. 检查framebuffer设备："
ls -la /dev/fb*

echo ""
echo "4. 运行程序前的建议："
echo "  - 确保以root权限运行程序"
echo "  - 检查触摸设备驱动是否正确加载"
echo "  - 可以使用 evtest 工具测试触摸设备"

echo ""
echo "5. 测试触摸输入（如果安装了evtest）："
echo "  运行: evtest /dev/input/event0"
echo "  然后触摸屏幕看是否有输出"
