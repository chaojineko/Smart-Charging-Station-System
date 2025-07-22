#include "charging_system.h"
#include "user_auth.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// 全局充电数据
charging_data_t g_charging_data = {0};

// 充电价格配置 (元/kWh)
#define FAST_CHARGING_RATE 1.8 // 快充价格
#define SLOW_CHARGING_RATE 1.2 // 慢充价格

/**
 * @brief 初始化充电系统
 */
void charging_system_init(void)
{
    memset(&g_charging_data, 0, sizeof(charging_data_t));
    g_charging_data.state = CHARGING_STATE_IDLE;
    g_charging_data.mode  = CHARGING_MODE_FAST;
}

/**
 * @brief 开始充电
 * @param mode 充电模式
 * @param username 用户名
 * @return true 成功, false 失败
 */
bool start_charging(charging_mode_t mode, const char * username)
{
    if(!username) {
        printf("错误: 用户名为空\n");
        return false;
    }

    printf("开始充电: 用户=%s, 模式=%s\n", username, (mode == CHARGING_MODE_FAST) ? "快充" : "慢充");

    // 初始化充电数据
    memset(&g_charging_data, 0, sizeof(charging_data_t));
    g_charging_data.mode  = mode;
    g_charging_data.state = CHARGING_STATE_CHARGING;
    strncpy(g_charging_data.username, username, sizeof(g_charging_data.username) - 1);

    // 设置充电参数（根据模式）
    if(mode == CHARGING_MODE_FAST) {
        g_charging_data.power   = 60.0;  // 快充60kW
        g_charging_data.voltage = 400.0; // 400V
        g_charging_data.current = 150.0; // 150A
    } else {
        g_charging_data.power   = 7.0;   // 慢充7kW
        g_charging_data.voltage = 220.0; // 220V
        g_charging_data.current = 32.0;  // 32A
    }

    // 记录开始时间
    g_charging_data.start_time   = time(NULL);
    g_charging_data.current_time = g_charging_data.start_time;

    printf("充电参数设置完成: 功率=%.1fkW, 电压=%.1fV, 电流=%.1fA\n", g_charging_data.power, g_charging_data.voltage,
           g_charging_data.current);

    return true;
}

/**
 * @brief 停止充电
 * @return true 成功, false 失败
 */
bool stop_charging(void)
{
    if(g_charging_data.state != CHARGING_STATE_CHARGING) {
        return false;
    }

    g_charging_data.state = CHARGING_STATE_FINISHED;

    // 注意：此处不进行扣费，扣费由用户在结算界面确认支付时执行
    // 避免重复扣费问题

    return true;
}

/**
 * @brief 更新充电数据（模拟充电过程）
 */
void update_charging_data(void)
{
    if(g_charging_data.state != CHARGING_STATE_CHARGING) {
        return;
    }

    time_t old_time              = g_charging_data.current_time;
    g_charging_data.current_time = time(NULL);

    // 计算充电时长（秒）
    double elapsed_seconds = difftime(g_charging_data.current_time, g_charging_data.start_time);

    // 如果是第一次更新，设置旧时间
    if(old_time == 0) {
        old_time = g_charging_data.start_time;
    }

    // 计算这次更新的时间间隔
    double time_delta = difftime(g_charging_data.current_time, old_time);

    // 模拟一些功率波动（让数据更真实，但不影响累积电量）
    double base_power     = (g_charging_data.mode == CHARGING_MODE_FAST) ? 60.0 : 7.0;
    double variation      = sin(elapsed_seconds / 10.0) * 2.0; // +/-2的波动
    g_charging_data.power = base_power + variation;
    if(g_charging_data.power < 0.1) g_charging_data.power = 0.1;

    // 累积计算已充入电量（基于基础功率，确保只增不减）
    if(time_delta > 0) {
        double energy_increment = base_power * (time_delta / 3600.0); // kWh
        g_charging_data.energy_charged += energy_increment;
    }

    // 电压轻微波动
    double voltage_base     = (g_charging_data.mode == CHARGING_MODE_FAST) ? 400.0 : 220.0;
    g_charging_data.voltage = voltage_base + sin(elapsed_seconds / 7.0) * 5.0;

    // 电流根据功率和电压计算 (P = U * I)
    g_charging_data.current = (g_charging_data.power * 1000.0) / g_charging_data.voltage;

    // 模拟充电进度 (假设需要充入30kWh为100%)
    double target_energy             = 30.0; // 目标充电量 30kWh
    g_charging_data.progress_percent = (g_charging_data.energy_charged / target_energy) * 100.0;
    if(g_charging_data.progress_percent > 100.0) {
        g_charging_data.progress_percent = 100.0;
    }

    // 计算费用（基于累积的电量，确保只增不减）
    g_charging_data.total_cost = calculate_charging_cost();

    // 如果充电完成，自动停止
    if(g_charging_data.progress_percent >= 100.0) {
        g_charging_data.state = CHARGING_STATE_FINISHED;
    }
}

/**
 * @brief 获取充电模式字符串
 * @param mode 充电模式
 * @return 模式字符串
 */
const char * get_charging_mode_string(charging_mode_t mode)
{
    switch(mode) {
        case CHARGING_MODE_FAST: return "快充";
        case CHARGING_MODE_SLOW: return "慢充";
        default: return "未知";
    }
}

/**
 * @brief 获取格式化的充电时长字符串
 * @param buffer 输出缓冲区
 * @param buffer_size 缓冲区大小
 */
void get_charging_duration_string(char * buffer, size_t buffer_size)
{
    if(!buffer) {
        snprintf(buffer, buffer_size, "00:00:00");
        return;
    }

    // 如果还没开始充电，返回0
    if(g_charging_data.start_time == 0) {
        snprintf(buffer, buffer_size, "00:00:00");
        return;
    }

    double elapsed_seconds = difftime(g_charging_data.current_time, g_charging_data.start_time);
    int hours              = (int)(elapsed_seconds / 3600);
    int minutes            = (int)((elapsed_seconds - hours * 3600) / 60);
    int seconds            = (int)(elapsed_seconds - hours * 3600 - minutes * 60);

    snprintf(buffer, buffer_size, "%02d:%02d:%02d", hours, minutes, seconds);
}

/**
 * @brief 计算充电费用
 * @return 当前费用
 */
double calculate_charging_cost(void)
{
    double rate = (g_charging_data.mode == CHARGING_MODE_FAST) ? FAST_CHARGING_RATE : SLOW_CHARGING_RATE;
    return g_charging_data.energy_charged * rate;
}

/**
 * @brief 获取当前充电数据
 * @return 充电数据指针
 */
const charging_data_t * get_charging_data(void)
{
    return &g_charging_data;
}
