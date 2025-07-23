#include "lvgl/lvgl.h"
#include "lvgl/demos/lv_demos.h"
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

// 添加UI头文件
#include "ui/ui.h"
// 添加用户认证头文件
#include "src/user_auth.h"
// 添加充电系统头文件
#include "src/charging_system.h"

#ifndef PATH_PREFIX
#define PATH_PREFIX "./"
#endif

static const char * getenv_default(const char * name, const char * dflt)
{
    return getenv(name) ?: dflt;
}

// 充电显示更新定时器回调函数
static void charging_timer_cb(lv_timer_t * timer)
{
    // 检查当前是否在Screen6界面并且正在充电
    extern lv_obj_t * ui_Screen6;
    extern lv_obj_t * ui_Screen7;

    if(lv_screen_active() == ui_Screen6) {
        const charging_data_t * charging = get_charging_data();
        if(charging && charging->state == CHARGING_STATE_CHARGING) {
            update_charging_display();
        }
    }
    // 检查当前是否在Screen7界面，更新计费显示
    else if(lv_screen_active() == ui_Screen7) {
        const charging_data_t * charging = get_charging_data();
        if(charging) {
            update_billing_summary();
        }
    }
}

#if LV_USE_LINUX_FBDEV
static void lv_linux_disp_init(void)
{
    const char * device = getenv_default("LV_LINUX_FBDEV_DEVICE", "/dev/fb0");
    lv_display_t * disp = lv_linux_fbdev_create();

    lv_linux_fbdev_set_file(disp, device);
}
#elif LV_USE_SDL
static void lv_linux_disp_init(void)
{
    const int width  = atoi(getenv("LV_SDL_VIDEO_WIDTH") ?: "800");
    const int height = atoi(getenv("LV_SDL_VIDEO_HEIGHT") ?: "480");

    lv_sdl_window_create(width, height);
}
#else
#error Unsupported configuration
#endif

int main(void)
{
    lv_init();
    /*Linux display device init*/
    lv_linux_disp_init();

#if LV_USE_SDL
    // init input device
    lv_sdl_mouse_create();
    lv_sdl_keyboard_create();
    lv_sdl_mousewheel_create();
#endif

#if LV_USE_LINUX_FBDEV
    // 创建输入设备
    printf("正在初始化触摸设备...\n");
    lv_indev_t * touch = lv_evdev_create(LV_INDEV_TYPE_POINTER, "/dev/input/event0");
    if(touch == NULL) {
        printf("警告: 无法打开 /dev/input/event0, 尝试 /dev/input/event1\n");
        touch = lv_evdev_create(LV_INDEV_TYPE_POINTER, "/dev/input/event1");
        if(touch == NULL) {
            printf("警告: 无法打开 /dev/input/event1, 尝试 /dev/input/event2\n");
            touch = lv_evdev_create(LV_INDEV_TYPE_POINTER, "/dev/input/event2");
            if(touch == NULL) {
                printf("错误: 无法找到触摸设备!\n");
            } else {
                printf("成功打开触摸设备: /dev/input/event2\n");
            }
        } else {
            printf("成功打开触摸设备: /dev/input/event1\n");
        }
    } else {
        printf("成功打开触摸设备: /dev/input/event0\n");
    }

    if(touch != NULL) {
        // 校准输入设备屏幕坐标
        // lv_evdev_set_calibration(touch, 0, 0, 1024, 600); // 黑色边框的屏幕
        lv_evdev_set_calibration(touch, 0, 0, 800, 480); // 蓝色边框的屏幕
        printf("触摸设备校准完成: 800x480\n");
    }
#endif

    // 初始化用户认证系统
    if(!user_auth_init()) {
        printf("用户认证系统初始化失败!\n");
        return -1;
    }

    // 初始化充电系统
    charging_system_init();

    // 初始化UI界面
    ui_init();

    // 创建定时器用于更新充电显示
    lv_timer_t * charging_timer = lv_timer_create(charging_timer_cb, 1000, NULL); // 每1秒更新一次

    /*Handle LVGL tasks*/
    while(1) {
        lv_timer_handler();
        usleep(5000);
    }
    return 0;
}