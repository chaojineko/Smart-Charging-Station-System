// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.2
// LVGL version: 9.1.0
// Project name: SquareLine_Project

#ifndef _UI_THEMES_H
#define _UI_THEMES_H

#ifdef __cplusplus
extern "C" {
#endif

#define UI_THEME_COLOR_COLOR1 0
#define UI_THEME_COLOR_COLOR2 1

#define UI_THEME_DEFAULT 0

extern const ui_theme_variable_t _ui_theme_color_color1[1];
extern const ui_theme_variable_t _ui_theme_alpha_color1[1];

extern const ui_theme_variable_t _ui_theme_color_color2[1];
extern const ui_theme_variable_t _ui_theme_alpha_color2[1];

extern const uint32_t * ui_theme_colors[1];
extern const uint8_t * ui_theme_alphas[1];
extern uint8_t ui_theme_idx;

void ui_theme_set(uint8_t theme_idx);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
