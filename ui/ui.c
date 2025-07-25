// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.2
// LVGL version: 9.1.0
// Project name: SquareLine_Project

#include "ui.h"
#include "ui_helpers.h"
#include "../src/user_auth.h"
#include "../src/charging_system.h"
#include <stdio.h>

///////////////////// VARIABLES ////////////////////

// SCREEN: ui_Screen1 主页面
void ui_Screen1_screen_init(void);
lv_obj_t * ui_Screen1;
lv_obj_t * ui_Image1;
lv_obj_t * ui_Image2;
lv_obj_t * ui_Label1;
void ui_event_Button2(lv_event_t * e);
lv_obj_t * ui_Button2;
lv_obj_t * ui_Label2;
lv_obj_t * ui_Image15;
void ui_event_Image13(lv_event_t * e);
lv_obj_t * ui_Image13;
lv_obj_t * ui_Label45;
lv_obj_t * ui_Container7;
lv_obj_t * ui_Label50;
void ui_event_Button23(lv_event_t * e);
lv_obj_t * ui_Button23;
lv_obj_t * ui_Label51;

// SCREEN: ui_Screen2身份选择
void ui_Screen2_screen_init(void);
lv_obj_t * ui_Screen2;
lv_obj_t * ui_Image5;
lv_obj_t * ui_Label3;
lv_obj_t * ui_Label4;
lv_obj_t * ui_Label5;
// S2选择页面的商家按钮
void ui_event_Button3(lv_event_t * e);
lv_obj_t * ui_Button3;
lv_obj_t * ui_Image3;
// S2选择页面的用户按钮
void ui_event_Button4(lv_event_t * e);
lv_obj_t * ui_Button4;
lv_obj_t * ui_Image4;
// home按钮
void ui_event_Button8(lv_event_t * e);
lv_obj_t * ui_Button8;
lv_obj_t * ui_Image14;

// SCREEN: ui_Screen3 顾客账号登陆
void ui_Screen3_screen_init(void);
lv_obj_t * ui_Screen3;
lv_obj_t * ui_Image6;
void ui_event_TextArea1(lv_event_t * e);
lv_obj_t * ui_TextArea1;
void ui_event_TextArea2(lv_event_t * e);
lv_obj_t * ui_TextArea2;
lv_obj_t * ui_Label6;
lv_obj_t * ui_Label7;
void ui_event_Button1(lv_event_t * e);
lv_obj_t * ui_Button1;
lv_obj_t * ui_Label8;
void ui_event_Button6(lv_event_t * e);
lv_obj_t * ui_Button6;
lv_obj_t * ui_Label10;
lv_obj_t * ui_Image17;
void ui_event_Button9(lv_event_t * e);
lv_obj_t * ui_Button9;
lv_obj_t * ui_Image16;
lv_obj_t * ui_Container3;
lv_obj_t * ui_Label23;
void ui_event_Button16(lv_event_t * e);
lv_obj_t * ui_Button16;
lv_obj_t * ui_Label26;
lv_obj_t * ui_Keyboard1;

// SCREEN: ui_Screen4 顾客创建账户
void ui_Screen4_screen_init(void);
lv_obj_t * ui_Screen4;
lv_obj_t * ui_Image7;
void ui_event_TextArea4(lv_event_t * e);
lv_obj_t * ui_TextArea4;
void ui_event_TextArea5(lv_event_t * e);
lv_obj_t * ui_TextArea5;
lv_obj_t * ui_Label11;
lv_obj_t * ui_Label12;
void ui_event_Button7(lv_event_t * e);
lv_obj_t * ui_Button7;
lv_obj_t * ui_Label13;
lv_obj_t * ui_Keyboard3;
void ui_event_Button32(lv_event_t * e);
lv_obj_t * ui_Button32;
lv_obj_t * ui_Label66;
lv_obj_t * ui_Container13;
lv_obj_t * ui_Label68;
void ui_event_Button37(lv_event_t * e);
lv_obj_t * ui_Button37;
lv_obj_t * ui_Label69;

// SCREEN: ui_Screen5 用户选择界面
void ui_Screen5_screen_init(void);
lv_obj_t * ui_Screen5;
lv_obj_t * ui_Image8;
lv_obj_t * ui_Label9;
// 余额查询按钮
void ui_event_Button5(lv_event_t * e);
lv_obj_t * ui_Button5;
lv_obj_t * ui_Label16;
void ui_event_Button10(lv_event_t * e);
lv_obj_t * ui_Button10;
lv_obj_t * ui_Label17;
void ui_event_Button11(lv_event_t * e);
lv_obj_t * ui_Button11;
void ui_event_Label18(lv_event_t * e);
lv_obj_t * ui_Label18;
void ui_event_Button13(lv_event_t * e);
lv_obj_t * ui_Button13;
lv_obj_t * ui_Image18;
lv_obj_t * ui_Container1;
lv_obj_t * ui_Label19;
void ui_event_Button12(lv_event_t * e);
lv_obj_t * ui_Button12;
lv_obj_t * ui_Label21;
lv_obj_t * ui_Image9;
lv_obj_t * ui_Container2;
lv_obj_t * ui_Label22;
void ui_event_Button15(lv_event_t * e);
lv_obj_t * ui_Button15;
lv_obj_t * ui_Label24;
void ui_event_Button14(lv_event_t * e);
lv_obj_t * ui_Button14;
lv_obj_t * ui_Label25;
lv_obj_t * ui_Container4;
lv_obj_t * ui_Image10;
lv_obj_t * ui_Label27;
void ui_event_Button18(lv_event_t * e);
lv_obj_t * ui_Button18;
lv_obj_t * ui_Label29;
lv_obj_t * ui_Container5;
lv_obj_t * ui_Label28;
void ui_event_Button19(lv_event_t * e);
lv_obj_t * ui_Button19;
lv_obj_t * ui_Label31;
void ui_event_Button17(lv_event_t * e);
lv_obj_t * ui_Button17;
lv_obj_t * ui_Label30;
void ui_event_Button20(lv_event_t * e);
lv_obj_t * ui_Button20;
lv_obj_t * ui_Label32;
lv_obj_t * ui_Container6;
lv_obj_t * ui_Label34;
void ui_event_Button21(lv_event_t * e);
lv_obj_t * ui_Button21;
lv_obj_t * ui_Label35;

// SCREEN: ui_Screen6 充电界面
void ui_Screen6_screen_init(void);
lv_obj_t * ui_Screen6;
lv_obj_t * ui_Image11;
lv_obj_t * ui_Label33;
lv_obj_t * ui_Label36;
lv_obj_t * ui_Label37;
lv_obj_t * ui_Label38;
lv_obj_t * ui_Bar1;
lv_obj_t * ui_Label39;
void ui_event_Button22(lv_event_t * e);
lv_obj_t * ui_Button22;
lv_obj_t * ui_Label42;
lv_obj_t * ui_Label40;
lv_obj_t * ui_Label41;
lv_obj_t * ui_Label43;

// SCREEN: ui_Screen7 结算界面
void ui_Screen7_screen_init(void);
lv_obj_t * ui_Screen7;
lv_obj_t * ui_Image12;
lv_obj_t * ui_Label44;
lv_obj_t * ui_Label46;
lv_obj_t * ui_Label47;
lv_obj_t * ui_Label48;
lv_obj_t * ui_Label49;
void ui_event_Button25(lv_event_t * e);
lv_obj_t * ui_Button25;
lv_obj_t * ui_Label15;
lv_obj_t * ui_Image20;
lv_obj_t * ui_Container8;
void ui_event_Image19(lv_event_t * e);
lv_obj_t * ui_Image19;
void ui_event_Image21(lv_event_t * e);
lv_obj_t * ui_Image21;
void ui_event_Image22(lv_event_t * e);
lv_obj_t * ui_Image22;
lv_obj_t * ui_Container9;
lv_obj_t * ui_Image23;
lv_obj_t * ui_Label20;
void ui_event_Button28(lv_event_t * e);
lv_obj_t * ui_Button28;
lv_obj_t * ui_Label56;
void ui_event_Button29(lv_event_t * e);
lv_obj_t * ui_Button29;
lv_obj_t * ui_Label57;
lv_obj_t * ui_Image26;
lv_obj_t * ui_Container11;
lv_obj_t * ui_Image24;
lv_obj_t * ui_Label52;
void ui_event_Button27(lv_event_t * e);
lv_obj_t * ui_Button27;
lv_obj_t * ui_Label55;
void ui_event_Button30(lv_event_t * e);
lv_obj_t * ui_Button30;
lv_obj_t * ui_Label58;
lv_obj_t * ui_Image27;
lv_obj_t * ui_Container12;
lv_obj_t * ui_Label59;
void ui_event_Button31(lv_event_t * e);
lv_obj_t * ui_Button31;
lv_obj_t * ui_Label60;
lv_obj_t * ui_Image28;
lv_obj_t * ui_Container10;
lv_obj_t * ui_Label53;
void ui_event_Button24(lv_event_t * e);
lv_obj_t * ui_Button24;
lv_obj_t * ui_Label54;

// SCREEN: ui_Screen8 充电枪解锁界面
void ui_Screen8_screen_init(void);
lv_obj_t * ui_Screen8;
lv_obj_t * ui_Image25;
lv_obj_t * ui_Label61;
void ui_event_Button26(lv_event_t * e);
lv_obj_t * ui_Button26;
lv_obj_t * ui_Label62;

// SCREEN: ui_Screen9 感谢界面
void ui_Screen9_screen_init(void);
lv_obj_t * ui_Screen9;
lv_obj_t * ui_Image29;
lv_obj_t * ui_Label63;
void ui_event_Button33(lv_event_t * e);
lv_obj_t * ui_Button33;
lv_obj_t * ui_Image31;

// SCREEN: ui_Screen10 商家登陆界面
void ui_Screen10_screen_init(void);
lv_obj_t * ui_Screen10;
lv_obj_t * ui_Image30;
void ui_event_Button34(lv_event_t * e);
lv_obj_t * ui_Button34;
lv_obj_t * ui_Image33;
void ui_event_TextArea6(lv_event_t * e);
lv_obj_t * ui_TextArea6;
void ui_event_TextArea7(lv_event_t * e);
lv_obj_t * ui_TextArea7;
lv_obj_t * ui_Label64;
lv_obj_t * ui_Label65;
void ui_event_Button36(lv_event_t * e);
lv_obj_t * ui_Button36;
lv_obj_t * ui_Label67;
lv_obj_t * ui_Image34;
lv_obj_t * ui_Keyboard4;

// SCREEN: ui_Screen11 请在控制台操作界面
void ui_Screen11_screen_init(void);
lv_obj_t * ui_Screen11;
lv_obj_t * ui_Image32;
lv_obj_t * ui_Label70;
void ui_event_Button38(lv_event_t * e);
lv_obj_t * ui_Button38;
lv_obj_t * ui_Image36;
lv_obj_t * ui____initial_actions0;
const lv_image_dsc_t * ui_imgset_bg[4]      = {&ui_img_bg1_png, &ui_img_bg2_png, &ui_img_bg3_png, &ui_img_bg4_png};
const lv_image_dsc_t * ui_imgset_qr_code[2] = {&ui_img_qr_code1_png, &ui_img_qr_code2_png};
const lv_image_dsc_t * ui_imgset_s[9] = {&ui_img_s1_png, &ui_img_s2_png, &ui_img_s3_png, &ui_img_s4_png, &ui_img_s5_png,
                                         &ui_img_s6_png, &ui_img_s7_png, &ui_img_s8_png, &ui_img_s9_png};
const lv_image_dsc_t * ui_imgset_slider_bg[3]   = {&ui_img_slider_bg1_png, &ui_img_slider_bg2_png,
                                                   &ui_img_slider_bg3_png};
const lv_image_dsc_t * ui_imgset_slider_mask[2] = {&ui_img_slider_mask1_png, &ui_img_slider_mask2_png};

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 32
#error "LV_COLOR_DEPTH should be 32bit to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_Button2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target          = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_Screen2, LV_SCR_LOAD_ANIM_FADE_ON, 400, 0, &ui_Screen2_screen_init);
    }
}
void ui_event_Image13(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target          = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_flag_modify(ui_Container7, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    }
}
void ui_event_Button23(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target          = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_flag_modify(ui_Container7, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_Button3(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target          = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_Screen10, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_Screen10_screen_init);
    }
}
void ui_event_Button4(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target          = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_Screen3, LV_SCR_LOAD_ANIM_FADE_ON, 400, 0, &ui_Screen3_screen_init);
    }
}
void ui_event_Button8(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target          = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_Screen1, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_Screen1_screen_init);
    }
}
// 登陆账号的文本框
void ui_event_TextArea1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);                             // 获取事件代码
    lv_obj_t * target          = lv_event_get_target(e);                           // 获取事件目标对象
    if(event_code == LV_EVENT_FOCUSED) {                                           // 如果事件是获得焦点
        _ui_flag_modify(ui_Keyboard1, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE); // 移除键盘的隐藏标志
        _ui_keyboard_set_target(ui_Keyboard1, ui_TextArea1);                       // 设置键盘的目标对象为账号文本框
    }
    if(event_code == LV_EVENT_DEFOCUSED) {                                      // 如果事件是失去焦点
        _ui_flag_modify(ui_Keyboard1, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD); // 添加键盘的隐藏标志
    }
}
// 登陆密码的文本框
void ui_event_TextArea2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target          = lv_event_get_target(e);
    if(event_code == LV_EVENT_FOCUSED) {
        _ui_flag_modify(ui_Keyboard1, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_keyboard_set_target(ui_Keyboard1, ui_TextArea2);
    }
    if(event_code == LV_EVENT_DEFOCUSED) {
        _ui_flag_modify(ui_Keyboard1, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_Button1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target          = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_Screen4, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_Screen4_screen_init);
    }
}
void ui_event_Button6(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target          = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        // 获取账号和密码
        const char * username = lv_textarea_get_text(ui_TextArea1);
        const char * password = lv_textarea_get_text(ui_TextArea2);

        // 执行顾客登录验证
        auth_result_t result = user_login(username, password, USER_TYPE_CUSTOMER);

        if(result == AUTH_SUCCESS) {
            // 设置当前用户
            set_current_user(username, USER_TYPE_CUSTOMER);
            // 登录成功，跳转到用户选择界面
            _ui_screen_change(&ui_Screen5, LV_SCR_LOAD_ANIM_FADE_ON, 400, 0, &ui_Screen5_screen_init);
        } else {
            // 登录失败，显示错误弹窗
            const char * error_msg = auth_result_to_string(result);
            lv_label_set_text(ui_Label23, error_msg);
            _ui_flag_modify(ui_Container3, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
            printf("顾客登录失败: %s\n", error_msg);
        }
    }
}
void ui_event_Button9(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target          = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_Screen1, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_Screen1_screen_init);
    }
}
void ui_event_Button16(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target          = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_flag_modify(ui_Container3, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_TextArea4(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target          = lv_event_get_target(e);
    if(event_code == LV_EVENT_FOCUSED) {
        _ui_flag_modify(ui_Keyboard3, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_keyboard_set_target(ui_Keyboard3, ui_TextArea4);
    }
    if(event_code == LV_EVENT_DEFOCUSED) {
        _ui_flag_modify(ui_Keyboard3, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_TextArea5(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target          = lv_event_get_target(e);
    if(event_code == LV_EVENT_FOCUSED) {
        _ui_flag_modify(ui_Keyboard3, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_keyboard_set_target(ui_Keyboard3, ui_TextArea5);
    }
    if(event_code == LV_EVENT_DEFOCUSED) {
        _ui_flag_modify(ui_Keyboard3, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_Button7(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target          = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_Screen3, LV_SCR_LOAD_ANIM_FADE_ON, 400, 0, &ui_Screen3_screen_init);
    }
}
// 注册成功后的回调函数
static void register_success_callback(lv_timer_t * timer)
{
    _ui_screen_change(&ui_Screen1, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_Screen1_screen_init);
    lv_timer_del(timer);
}

void ui_event_Button32(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target          = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        // 获取注册的账号和密码
        const char * username = lv_textarea_get_text(ui_TextArea4);
        const char * password = lv_textarea_get_text(ui_TextArea5);

        // 检查输入是否为空
        if(!username || !password || strlen(username) == 0 || strlen(password) == 0) {
            lv_label_set_text(ui_Label68, "请输入账号和密码!");
            // 使用自定义中文字体
            lv_obj_set_style_text_font(ui_Label68, &ui_font_chinese48title, LV_PART_MAIN | LV_STATE_DEFAULT);
            _ui_flag_modify(ui_Container13, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
            printf("注册失败: 账号或密码为空\n");
            return;
        }

        // 执行顾客注册
        bool success = user_register(username, password, USER_TYPE_CUSTOMER);

        if(success) {
            // 注册成功，延时后返回登录界面
            lv_label_set_text(ui_Label68, "注册成功! 即将返回登录界面...");
            // 使用自定义中文字体
            lv_obj_set_style_text_font(ui_Label68, &ui_font_chinese48title, LV_PART_MAIN | LV_STATE_DEFAULT);
            _ui_flag_modify(ui_Container13, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
            printf("顾客注册成功: %s\n", username);

            // 清空输入框
            lv_textarea_set_text(ui_TextArea4, "");
            lv_textarea_set_text(ui_TextArea5, "");

            // 延时1.5秒后返回主界面
            lv_timer_create(register_success_callback, 1500, NULL);
        } else {
            // 注册失败
            lv_label_set_text(ui_Label68, "用户名已存在!");
            // 使用自定义中文字体
            lv_obj_set_style_text_font(ui_Label68, &ui_font_chinese48title, LV_PART_MAIN | LV_STATE_DEFAULT);
            _ui_flag_modify(ui_Container13, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
            printf("顾客注册失败: 用户名已存在\n");
        }
    }
}

void ui_event_Button37(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target          = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        // 这是弹窗中的"上一步"按钮，用于关闭弹窗
        _ui_flag_modify(ui_Container13, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_Button5(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target          = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        // 刷新当前用户的余额信息
        refresh_current_user_balance();
        // 更新余额显示
        update_balance_display();
        // 显示余额查询弹窗
        _ui_flag_modify(ui_Container2, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    }
}
void ui_event_Button10(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target          = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_flag_modify(ui_Container5, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    }
}
void ui_event_Button11(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target          = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_flag_modify(ui_Container1, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    }
}
void ui_event_Label18(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target          = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_flag_modify(ui_Container1, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    }
}
void ui_event_Button13(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target          = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_Screen1, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_Screen1_screen_init);
    }
}
void ui_event_Button12(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target          = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_flag_modify(ui_Container1, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_Button15(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target          = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_flag_modify(ui_Container2, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_Button14(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target          = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_flag_modify(ui_Container4, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    }
}
void ui_event_Button18(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target          = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_flag_modify(ui_Container4, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_Button19(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target          = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_flag_modify(ui_Container5, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_Button17(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target          = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        // 获取当前用户
        const user_info_t * current = get_current_user();
        if(current) {
            // 开始快充
            if(start_charging(CHARGING_MODE_FAST, current->username)) {
                _ui_flag_modify(ui_Container5, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
                _ui_flag_modify(ui_Container6, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
            }
        }
    }
}
void ui_event_Button20(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target          = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        // 获取当前用户
        const user_info_t * current = get_current_user();
        if(current) {
            // 开始慢充
            if(start_charging(CHARGING_MODE_SLOW, current->username)) {
                _ui_flag_modify(ui_Container5, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
                _ui_flag_modify(ui_Container6, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
            }
        }
    }
}
void ui_event_Button21(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target          = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        // 检查充电状态，确保已经选择了充电模式
        const charging_data_t * charging = get_charging_data();
        if(charging && charging->state == CHARGING_STATE_CHARGING) {
            // 切换到充电界面
            _ui_screen_change(&ui_Screen6, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_Screen6_screen_init);
            // 开始更新充电显示
            update_charging_display();
        } else {
            // 如果没有选择充电模式，返回选择界面
            printf("错误: 请先选择充电模式\n");
        }
    }
}
void ui_event_Button22(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target          = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        // 停止充电
        stop_charging();
        // 切换到结算界面
        _ui_screen_change(&ui_Screen7, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_Screen7_screen_init);
    }
}
void ui_event_Button25(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target          = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_flag_modify(ui_Container8, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    }
}
void ui_event_Image19(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target          = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_flag_modify(ui_Container11, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(ui_Container8, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_Image21(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target          = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_flag_modify(ui_Container8, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_Container9, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    }
}
void ui_event_Image22(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target          = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
#include "../src/charging_system.h"
#include "../src/user_auth.h"

        // 获取充电费用
        double total_cost = calculate_charging_cost();

        // 获取当前用户余额
        double current_balance = current_user.balance;

        printf("[DEBUG] Wallet Payment - Total Cost: %.2f, Current Balance: %.2f\n", total_cost, current_balance);

        if(current_balance >= total_cost) {
            // 余额足够，扣费并显示成功界面
            if(user_deduct_balance(current_user.username, current_user.type, total_cost)) {
                // 刷新当前用户余额
                refresh_current_user_balance();
                double remaining_balance = current_user.balance;

                // 更新成功界面的显示信息
                char success_text[256];
                snprintf(success_text, sizeof(success_text), "扣款成功! \n本次消费:%.2f元\n剩余余额:%.2f元", total_cost,
                         remaining_balance);
                lv_label_set_text(ui_Label59, success_text);

                // 隐藏支付方式选择界面，显示扣款成功界面
                _ui_flag_modify(ui_Container8, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
                _ui_flag_modify(ui_Container12, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);

                printf("[DEBUG] Wallet Payment Success - Cost: %.2f, Remaining: %.2f\n", total_cost, remaining_balance);
            } else {
                // 扣费失败，显示余额不足界面
                _ui_flag_modify(ui_Container8, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
                _ui_flag_modify(ui_Container10, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);

                printf("[DEBUG] Wallet Payment Failed - Balance deduction failed\n");
            }
        } else {
            // 余额不足，显示余额不足界面
            _ui_flag_modify(ui_Container8, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
            _ui_flag_modify(ui_Container10, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);

            printf("[DEBUG] Insufficient Balance - Cost: %.2f, Balance: %.2f\n", total_cost, current_balance);
        }
    }
}
void ui_event_Button28(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target          = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_flag_modify(ui_Container9, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_Button29(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target          = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_Screen8, LV_SCR_LOAD_ANIM_FADE_ON, 400, 0, &ui_Screen8_screen_init);
    }
}
void ui_event_Button27(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target          = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_flag_modify(ui_Container11, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_Button30(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target          = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_Screen8, LV_SCR_LOAD_ANIM_FADE_ON, 400, 0, &ui_Screen8_screen_init);
    }
}
void ui_event_Button31(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target          = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_Screen8, LV_SCR_LOAD_ANIM_FADE_ON, 400, 0, &ui_Screen8_screen_init);
    }
}
void ui_event_Button24(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target          = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_flag_modify(ui_Container10, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_Button26(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target          = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_Screen9, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_Screen9_screen_init);
    }
}
void ui_event_Button33(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target          = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_Screen1, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_Screen1_screen_init);
    }
}
void ui_event_Button34(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target          = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_Screen1, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_Screen1_screen_init);
    }
}
void ui_event_TextArea6(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target          = lv_event_get_target(e);
    if(event_code == LV_EVENT_FOCUSED) {
        _ui_flag_modify(ui_Keyboard4, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_keyboard_set_target(ui_Keyboard4, ui_TextArea6);
    }
    if(event_code == LV_EVENT_DEFOCUSED) {
        _ui_flag_modify(ui_Keyboard4, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_TextArea7(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target          = lv_event_get_target(e);
    if(event_code == LV_EVENT_FOCUSED) {
        _ui_flag_modify(ui_Keyboard4, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_keyboard_set_target(ui_Keyboard4, ui_TextArea7);
    }
    if(event_code == LV_EVENT_DEFOCUSED) {
        _ui_flag_modify(ui_Keyboard4, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_Button36(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target          = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        // 获取商家账号和密码
        const char * username = lv_textarea_get_text(ui_TextArea6);
        const char * password = lv_textarea_get_text(ui_TextArea7);

        // 执行商家登录验证
        auth_result_t result = user_login(username, password, USER_TYPE_MERCHANT);

        if(result == AUTH_SUCCESS) {
            // 设置当前用户
            set_current_user(username, USER_TYPE_MERCHANT);
            // 登录成功，跳转到商家操作界面
            _ui_screen_change(&ui_Screen11, LV_SCR_LOAD_ANIM_FADE_ON, 400, 0, &ui_Screen11_screen_init);
            printf("商家登录成功: %s\n", username);
        } else {
            // 登录失败，显示错误提示（目前在控制台输出，你可以在UI中添加弹窗）
            const char * error_msg = auth_result_to_string(result);
            printf("商家登录失败: %s\n", error_msg);
        }
    }
}
void ui_event_Button38(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target          = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        // 清理Screen11资源
        ui_Screen11_cleanup();
        _ui_screen_change(&ui_Screen1, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_Screen1_screen_init);
    }
}

///////////////////// SCREENS ////////////////////

void ui_init(void)
{
    lv_disp_t * dispp  = lv_display_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen1_screen_init();
    ui_Screen2_screen_init();
    ui_Screen3_screen_init();
    ui_Screen4_screen_init();
    ui_Screen5_screen_init();
    ui_Screen6_screen_init();
    ui_Screen7_screen_init();
    ui_Screen8_screen_init();
    ui_Screen9_screen_init();
    ui_Screen10_screen_init();
    ui_Screen11_screen_init();
    ui____initial_actions0 = lv_obj_create(NULL);
    lv_disp_load_scr(ui_Screen1);
}
