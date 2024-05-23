/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"
#include "custom.h"


void setup_scr_MainScreen(lv_ui *ui)
{
	//Write codes MainScreen
	ui->MainScreen = lv_obj_create(NULL);
	ui->g_kb_MainScreen = lv_keyboard_create(ui->MainScreen);
	lv_obj_add_event_cb(ui->g_kb_MainScreen, kb_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_add_flag(ui->g_kb_MainScreen, LV_OBJ_FLAG_HIDDEN);
	lv_obj_set_style_text_font(ui->g_kb_MainScreen, &lv_font_SourceHanSerifSC_Regular_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_size(ui->MainScreen, 800, 480);
	lv_obj_set_scrollbar_mode(ui->MainScreen, LV_SCROLLBAR_MODE_OFF);

	//Write style for MainScreen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_btn_2
	ui->MainScreen_btn_2 = lv_btn_create(ui->MainScreen);
	ui->MainScreen_btn_2_label = lv_label_create(ui->MainScreen_btn_2);
	lv_label_set_text(ui->MainScreen_btn_2_label, "Page1");
	lv_label_set_long_mode(ui->MainScreen_btn_2_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->MainScreen_btn_2_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->MainScreen_btn_2, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->MainScreen_btn_2_label, LV_PCT(100));
	lv_obj_set_pos(ui->MainScreen_btn_2, 642, 255);
	lv_obj_set_size(ui->MainScreen_btn_2, 100, 50);

	//Write style for MainScreen_btn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_btn_2, lv_color_hex(0x009ea9), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_btn_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_btn_2, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_btn_2, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->MainScreen_btn_2, lv_color_hex(0x0d4b3b), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->MainScreen_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->MainScreen_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->MainScreen_btn_2, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->MainScreen_btn_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_btn_2, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_btn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_btn_1
	ui->MainScreen_btn_1 = lv_btn_create(ui->MainScreen);
	ui->MainScreen_btn_1_label = lv_label_create(ui->MainScreen_btn_1);
	lv_label_set_text(ui->MainScreen_btn_1_label, "Goto2");
	lv_label_set_long_mode(ui->MainScreen_btn_1_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->MainScreen_btn_1_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->MainScreen_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->MainScreen_btn_1_label, LV_PCT(100));
	lv_obj_set_pos(ui->MainScreen_btn_1, 645, 377);
	lv_obj_set_size(ui->MainScreen_btn_1, 100, 50);

	//Write style for MainScreen_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_btn_1, lv_color_hex(0x009ea9), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_btn_1, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_btn_1, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->MainScreen_btn_1, lv_color_hex(0x0d4b3b), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->MainScreen_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->MainScreen_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->MainScreen_btn_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->MainScreen_btn_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_btn_1, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_slider_1
	ui->MainScreen_slider_1 = lv_slider_create(ui->MainScreen);
	lv_slider_set_range(ui->MainScreen_slider_1, 0, 100);
	lv_slider_set_mode(ui->MainScreen_slider_1, LV_SLIDER_MODE_NORMAL);
	lv_slider_set_value(ui->MainScreen_slider_1, 50, LV_ANIM_OFF);
	lv_obj_set_pos(ui->MainScreen_slider_1, 413, 330);
	lv_obj_set_size(ui->MainScreen_slider_1, 200, 10);

	//Write style for MainScreen_slider_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_slider_1, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_slider_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_slider_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_slider_1, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_outline_width(ui->MainScreen_slider_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_slider_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_slider_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_slider_1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_slider_1, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_slider_1, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_slider_1, 50, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style for MainScreen_slider_1, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_slider_1, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_slider_1, lv_color_hex(0x2195f6), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_slider_1, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_slider_1, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes MainScreen_ta_1
	ui->MainScreen_ta_1 = lv_textarea_create(ui->MainScreen);
	lv_textarea_set_text(ui->MainScreen_ta_1, "Hello World");
	lv_textarea_set_placeholder_text(ui->MainScreen_ta_1, "");
	lv_textarea_set_password_bullet(ui->MainScreen_ta_1, "*");
	lv_textarea_set_password_mode(ui->MainScreen_ta_1, false);
	lv_textarea_set_one_line(ui->MainScreen_ta_1, false);
	lv_textarea_set_accepted_chars(ui->MainScreen_ta_1, "");
	lv_textarea_set_max_length(ui->MainScreen_ta_1, 32);
	#if LV_USE_KEYBOARD != 0 || LV_USE_ZH_KEYBOARD != 0
		lv_obj_add_event_cb(ui->MainScreen_ta_1, ta_event_cb, LV_EVENT_ALL, ui->g_kb_MainScreen);
	#endif
	lv_obj_set_pos(ui->MainScreen_ta_1, 375, 41);
	lv_obj_set_size(ui->MainScreen_ta_1, 355, 93);

	//Write style for MainScreen_ta_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->MainScreen_ta_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_ta_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_ta_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_ta_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_ta_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_ta_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_ta_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_ta_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_ta_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->MainScreen_ta_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->MainScreen_ta_1, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->MainScreen_ta_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_ta_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_ta_1, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_ta_1, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_ta_1, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_ta_1, 4, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_ta_1, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_ta_1, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_ta_1, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_ta_1, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_ta_1, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write codes MainScreen_spinbox_1
	ui->MainScreen_spinbox_1 = lv_spinbox_create(ui->MainScreen);
	lv_obj_set_pos(ui->MainScreen_spinbox_1, 465, 234);
	lv_obj_set_width(ui->MainScreen_spinbox_1, 70);
	lv_obj_set_height(ui->MainScreen_spinbox_1, 40);
	lv_spinbox_set_digit_format(ui->MainScreen_spinbox_1, 4, 3);
	lv_spinbox_set_range(ui->MainScreen_spinbox_1, -9999, 9999);
	lv_coord_t MainScreen_spinbox_1_h = lv_obj_get_height(ui->MainScreen_spinbox_1);
	ui->MainScreen_spinbox_1_btn = lv_btn_create(ui->MainScreen);
	lv_obj_set_size(ui->MainScreen_spinbox_1_btn, MainScreen_spinbox_1_h, MainScreen_spinbox_1_h);
	lv_obj_align_to(ui->MainScreen_spinbox_1_btn, ui->MainScreen_spinbox_1, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinbox_1_btn, LV_SYMBOL_PLUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinbox_1_btn, lv_MainScreen_spinbox_1_increment_event_cb, LV_EVENT_ALL, NULL);
	ui->MainScreen_spinbox_1_btn_minus = lv_btn_create(ui->MainScreen);
	lv_obj_set_size(ui->MainScreen_spinbox_1_btn_minus, MainScreen_spinbox_1_h, MainScreen_spinbox_1_h);
	lv_obj_align_to(ui->MainScreen_spinbox_1_btn_minus, ui->MainScreen_spinbox_1, LV_ALIGN_OUT_LEFT_MID, -5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinbox_1_btn_minus, LV_SYMBOL_MINUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinbox_1_btn_minus, lv_MainScreen_spinbox_1_decrement_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_set_pos(ui->MainScreen_spinbox_1, 465, 234);

	//Write style for MainScreen_spinbox_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_spinbox_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinbox_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinbox_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_spinbox_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->MainScreen_spinbox_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->MainScreen_spinbox_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->MainScreen_spinbox_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_spinbox_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_spinbox_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_spinbox_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_spinbox_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_spinbox_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinbox_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinbox_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_spinbox_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_spinbox_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_spinbox_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_spinbox_1, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->MainScreen_spinbox_1, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinbox_1, &lv_font_montserratMedium_12, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinbox_1, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_spinbox_1, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinbox_1, lv_color_hex(0x2195f6), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinbox_1, LV_GRAD_DIR_NONE, LV_PART_CURSOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_MainScreen_spinbox_1_extra_btns_main_default
	static lv_style_t style_MainScreen_spinbox_1_extra_btns_main_default;
	ui_init_style(&style_MainScreen_spinbox_1_extra_btns_main_default);
	
	lv_style_set_text_color(&style_MainScreen_spinbox_1_extra_btns_main_default, lv_color_hex(0xffffff));
	lv_style_set_text_font(&style_MainScreen_spinbox_1_extra_btns_main_default, &lv_font_montserratMedium_12);
	lv_style_set_text_opa(&style_MainScreen_spinbox_1_extra_btns_main_default, 255);
	lv_style_set_bg_opa(&style_MainScreen_spinbox_1_extra_btns_main_default, 255);
	lv_style_set_bg_color(&style_MainScreen_spinbox_1_extra_btns_main_default, lv_color_hex(0x2195f6));
	lv_style_set_bg_grad_dir(&style_MainScreen_spinbox_1_extra_btns_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_border_width(&style_MainScreen_spinbox_1_extra_btns_main_default, 0);
	lv_style_set_radius(&style_MainScreen_spinbox_1_extra_btns_main_default, 5);
	lv_obj_add_style(ui->MainScreen_spinbox_1_btn, &style_MainScreen_spinbox_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_spinbox_1_btn_minus, &style_MainScreen_spinbox_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_slider_2
	ui->MainScreen_slider_2 = lv_slider_create(ui->MainScreen);
	lv_slider_set_range(ui->MainScreen_slider_2, 0, 29);
	lv_slider_set_mode(ui->MainScreen_slider_2, LV_SLIDER_MODE_NORMAL);
	lv_slider_set_value(ui->MainScreen_slider_2, 10, LV_ANIM_OFF);
	lv_obj_set_pos(ui->MainScreen_slider_2, 762, 73);
	lv_obj_set_size(ui->MainScreen_slider_2, 12, 283);

	//Write style for MainScreen_slider_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_slider_2, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_slider_2, lv_color_hex(0x34ffa4), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_slider_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_slider_2, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_outline_width(ui->MainScreen_slider_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_slider_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_slider_2, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_slider_2, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_slider_2, lv_color_hex(0x34ff98), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_slider_2, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_slider_2, 50, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style for MainScreen_slider_2, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_slider_2, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_slider_2, lv_color_hex(0x00ed5c), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_slider_2, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_slider_2, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes MainScreen_list_1
	ui->MainScreen_list_1 = lv_list_create(ui->MainScreen);
	ui->MainScreen_list_1_item0 = lv_list_add_btn(ui->MainScreen_list_1, LV_SYMBOL_SAVE, "save");
	ui->MainScreen_list_1_item1 = lv_list_add_btn(ui->MainScreen_list_1, LV_SYMBOL_SAVE, "save_1");
	ui->MainScreen_list_1_item2 = lv_list_add_btn(ui->MainScreen_list_1, LV_SYMBOL_SAVE, "save_2");
	ui->MainScreen_list_1_item3 = lv_list_add_btn(ui->MainScreen_list_1, LV_SYMBOL_SAVE, "save_3");
	ui->MainScreen_list_1_item4 = lv_list_add_btn(ui->MainScreen_list_1, LV_SYMBOL_SAVE, "save_4");
	ui->MainScreen_list_1_item5 = lv_list_add_btn(ui->MainScreen_list_1, LV_SYMBOL_SAVE, "save_5");
	ui->MainScreen_list_1_item6 = lv_list_add_btn(ui->MainScreen_list_1, LV_SYMBOL_SAVE, "save_6");
	ui->MainScreen_list_1_item7 = lv_list_add_btn(ui->MainScreen_list_1, LV_SYMBOL_SAVE, "save_7");
	ui->MainScreen_list_1_item8 = lv_list_add_btn(ui->MainScreen_list_1, LV_SYMBOL_SAVE, "save_8");
	ui->MainScreen_list_1_item9 = lv_list_add_btn(ui->MainScreen_list_1, LV_SYMBOL_SAVE, "save_9");
	ui->MainScreen_list_1_item10 = lv_list_add_btn(ui->MainScreen_list_1, LV_SYMBOL_SAVE, "save_10");
	ui->MainScreen_list_1_item11 = lv_list_add_btn(ui->MainScreen_list_1, LV_SYMBOL_SAVE, "save_11");
	ui->MainScreen_list_1_item12 = lv_list_add_btn(ui->MainScreen_list_1, LV_SYMBOL_SAVE, "save_12");
	ui->MainScreen_list_1_item13 = lv_list_add_btn(ui->MainScreen_list_1, LV_SYMBOL_SAVE, "save_13");
	ui->MainScreen_list_1_item14 = lv_list_add_btn(ui->MainScreen_list_1, LV_SYMBOL_SAVE, "save_14");
	lv_obj_set_pos(ui->MainScreen_list_1, 75, 124);
	lv_obj_set_size(ui->MainScreen_list_1, 133, 181);
	lv_obj_set_scrollbar_mode(ui->MainScreen_list_1, LV_SCROLLBAR_MODE_AUTO);

	//Write style state: LV_STATE_DEFAULT for &style_MainScreen_list_1_main_main_default
	static lv_style_t style_MainScreen_list_1_main_main_default;
	ui_init_style(&style_MainScreen_list_1_main_main_default);
	
	lv_style_set_pad_top(&style_MainScreen_list_1_main_main_default, 5);
	lv_style_set_pad_left(&style_MainScreen_list_1_main_main_default, 5);
	lv_style_set_pad_right(&style_MainScreen_list_1_main_main_default, 5);
	lv_style_set_pad_bottom(&style_MainScreen_list_1_main_main_default, 5);
	lv_style_set_bg_opa(&style_MainScreen_list_1_main_main_default, 255);
	lv_style_set_bg_color(&style_MainScreen_list_1_main_main_default, lv_color_hex(0x000000));
	lv_style_set_bg_grad_dir(&style_MainScreen_list_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_border_width(&style_MainScreen_list_1_main_main_default, 1);
	lv_style_set_border_opa(&style_MainScreen_list_1_main_main_default, 255);
	lv_style_set_border_color(&style_MainScreen_list_1_main_main_default, lv_color_hex(0xe1e6ee));
	lv_style_set_border_side(&style_MainScreen_list_1_main_main_default, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_MainScreen_list_1_main_main_default, 3);
	lv_style_set_shadow_width(&style_MainScreen_list_1_main_main_default, 0);
	lv_obj_add_style(ui->MainScreen_list_1, &style_MainScreen_list_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_MainScreen_list_1_main_scrollbar_default
	static lv_style_t style_MainScreen_list_1_main_scrollbar_default;
	ui_init_style(&style_MainScreen_list_1_main_scrollbar_default);
	
	lv_style_set_radius(&style_MainScreen_list_1_main_scrollbar_default, 3);
	lv_style_set_bg_opa(&style_MainScreen_list_1_main_scrollbar_default, 255);
	lv_style_set_bg_color(&style_MainScreen_list_1_main_scrollbar_default, lv_color_hex(0xffffff));
	lv_style_set_bg_grad_dir(&style_MainScreen_list_1_main_scrollbar_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(ui->MainScreen_list_1, &style_MainScreen_list_1_main_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_MainScreen_list_1_extra_btns_main_default
	static lv_style_t style_MainScreen_list_1_extra_btns_main_default;
	ui_init_style(&style_MainScreen_list_1_extra_btns_main_default);
	
	lv_style_set_pad_top(&style_MainScreen_list_1_extra_btns_main_default, 5);
	lv_style_set_pad_left(&style_MainScreen_list_1_extra_btns_main_default, 5);
	lv_style_set_pad_right(&style_MainScreen_list_1_extra_btns_main_default, 5);
	lv_style_set_pad_bottom(&style_MainScreen_list_1_extra_btns_main_default, 5);
	lv_style_set_border_width(&style_MainScreen_list_1_extra_btns_main_default, 0);
	lv_style_set_text_color(&style_MainScreen_list_1_extra_btns_main_default, lv_color_hex(0x00ff1d));
	lv_style_set_text_font(&style_MainScreen_list_1_extra_btns_main_default, &lv_font_montserratMedium_12);
	lv_style_set_text_opa(&style_MainScreen_list_1_extra_btns_main_default, 255);
	lv_style_set_radius(&style_MainScreen_list_1_extra_btns_main_default, 3);
	lv_style_set_bg_opa(&style_MainScreen_list_1_extra_btns_main_default, 255);
	lv_style_set_bg_color(&style_MainScreen_list_1_extra_btns_main_default, lv_color_hex(0x000000));
	lv_style_set_bg_grad_dir(&style_MainScreen_list_1_extra_btns_main_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(ui->MainScreen_list_1_item14, &style_MainScreen_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_list_1_item13, &style_MainScreen_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_list_1_item12, &style_MainScreen_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_list_1_item11, &style_MainScreen_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_list_1_item10, &style_MainScreen_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_list_1_item9, &style_MainScreen_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_list_1_item8, &style_MainScreen_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_list_1_item7, &style_MainScreen_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_list_1_item6, &style_MainScreen_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_list_1_item5, &style_MainScreen_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_list_1_item4, &style_MainScreen_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_list_1_item3, &style_MainScreen_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_list_1_item2, &style_MainScreen_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_list_1_item1, &style_MainScreen_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_list_1_item0, &style_MainScreen_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_MainScreen_list_1_extra_texts_main_default
	static lv_style_t style_MainScreen_list_1_extra_texts_main_default;
	ui_init_style(&style_MainScreen_list_1_extra_texts_main_default);
	
	lv_style_set_pad_top(&style_MainScreen_list_1_extra_texts_main_default, 5);
	lv_style_set_pad_left(&style_MainScreen_list_1_extra_texts_main_default, 5);
	lv_style_set_pad_right(&style_MainScreen_list_1_extra_texts_main_default, 5);
	lv_style_set_pad_bottom(&style_MainScreen_list_1_extra_texts_main_default, 5);
	lv_style_set_border_width(&style_MainScreen_list_1_extra_texts_main_default, 0);
	lv_style_set_text_color(&style_MainScreen_list_1_extra_texts_main_default, lv_color_hex(0x0D3055));
	lv_style_set_text_font(&style_MainScreen_list_1_extra_texts_main_default, &lv_font_montserratMedium_12);
	lv_style_set_text_opa(&style_MainScreen_list_1_extra_texts_main_default, 255);
	lv_style_set_radius(&style_MainScreen_list_1_extra_texts_main_default, 3);
	lv_style_set_bg_opa(&style_MainScreen_list_1_extra_texts_main_default, 255);
	lv_style_set_bg_color(&style_MainScreen_list_1_extra_texts_main_default, lv_color_hex(0xffffff));
	lv_style_set_bg_grad_dir(&style_MainScreen_list_1_extra_texts_main_default, LV_GRAD_DIR_NONE);

	//The custom code of MainScreen.
	lv_keyboard_set_popovers(ui->g_kb_MainScreen, true);
lv_obj_set_style_bg_opa(ui->MainScreen_slider_2, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
MainScreenSetStyle(ui);
MainScreengroup(ui);

	//Update current screen layout.
	lv_obj_update_layout(ui->MainScreen);

	//Init events for screen.
	events_init_MainScreen(ui);
}
