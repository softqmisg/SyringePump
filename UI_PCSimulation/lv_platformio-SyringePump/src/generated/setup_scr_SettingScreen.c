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



void setup_scr_SettingScreen(lv_ui *ui)
{
	//Write codes SettingScreen
	ui->SettingScreen = lv_obj_create(NULL);
	lv_obj_set_size(ui->SettingScreen, 800, 480);
	lv_obj_set_scrollbar_mode(ui->SettingScreen, LV_SCROLLBAR_MODE_OFF);

	//Write style for SettingScreen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->SettingScreen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->SettingScreen, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->SettingScreen, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes SettingScreen_slider_1
	ui->SettingScreen_slider_1 = lv_slider_create(ui->SettingScreen);
	lv_slider_set_range(ui->SettingScreen_slider_1, 0, 100);
	lv_slider_set_mode(ui->SettingScreen_slider_1, LV_SLIDER_MODE_NORMAL);
	lv_slider_set_value(ui->SettingScreen_slider_1, 50, LV_ANIM_OFF);
	lv_obj_set_pos(ui->SettingScreen_slider_1, 320, 236);
	lv_obj_set_size(ui->SettingScreen_slider_1, 160, 8);

	//Write style for SettingScreen_slider_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->SettingScreen_slider_1, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->SettingScreen_slider_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->SettingScreen_slider_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->SettingScreen_slider_1, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_outline_width(ui->SettingScreen_slider_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->SettingScreen_slider_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for SettingScreen_slider_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->SettingScreen_slider_1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->SettingScreen_slider_1, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->SettingScreen_slider_1, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->SettingScreen_slider_1, 50, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style for SettingScreen_slider_1, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->SettingScreen_slider_1, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->SettingScreen_slider_1, lv_color_hex(0x2195f6), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->SettingScreen_slider_1, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->SettingScreen_slider_1, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes SettingScreen_spinbox_1
	ui->SettingScreen_spinbox_1 = lv_spinbox_create(ui->SettingScreen);
	lv_obj_set_pos(ui->SettingScreen_spinbox_1, 398, 271);
	lv_obj_set_width(ui->SettingScreen_spinbox_1, 70);
	lv_obj_set_height(ui->SettingScreen_spinbox_1, 40);
	lv_spinbox_set_digit_format(ui->SettingScreen_spinbox_1, 4, 3);
	lv_spinbox_set_range(ui->SettingScreen_spinbox_1, -9999, 9999);
	lv_coord_t SettingScreen_spinbox_1_h = lv_obj_get_height(ui->SettingScreen_spinbox_1);
	ui->SettingScreen_spinbox_1_btn = lv_btn_create(ui->SettingScreen);
	lv_obj_set_size(ui->SettingScreen_spinbox_1_btn, SettingScreen_spinbox_1_h, SettingScreen_spinbox_1_h);
	lv_obj_align_to(ui->SettingScreen_spinbox_1_btn, ui->SettingScreen_spinbox_1, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
	lv_obj_set_style_bg_img_src(ui->SettingScreen_spinbox_1_btn, LV_SYMBOL_PLUS, 0);
	lv_obj_add_event_cb(ui->SettingScreen_spinbox_1_btn, lv_SettingScreen_spinbox_1_increment_event_cb, LV_EVENT_ALL, NULL);
	ui->SettingScreen_spinbox_1_btn_minus = lv_btn_create(ui->SettingScreen);
	lv_obj_set_size(ui->SettingScreen_spinbox_1_btn_minus, SettingScreen_spinbox_1_h, SettingScreen_spinbox_1_h);
	lv_obj_align_to(ui->SettingScreen_spinbox_1_btn_minus, ui->SettingScreen_spinbox_1, LV_ALIGN_OUT_LEFT_MID, -5, 0);
	lv_obj_set_style_bg_img_src(ui->SettingScreen_spinbox_1_btn_minus, LV_SYMBOL_MINUS, 0);
	lv_obj_add_event_cb(ui->SettingScreen_spinbox_1_btn_minus, lv_SettingScreen_spinbox_1_decrement_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_set_pos(ui->SettingScreen_spinbox_1, 398, 271);

	//Write style for SettingScreen_spinbox_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->SettingScreen_spinbox_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->SettingScreen_spinbox_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->SettingScreen_spinbox_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->SettingScreen_spinbox_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->SettingScreen_spinbox_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->SettingScreen_spinbox_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->SettingScreen_spinbox_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->SettingScreen_spinbox_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->SettingScreen_spinbox_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->SettingScreen_spinbox_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->SettingScreen_spinbox_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->SettingScreen_spinbox_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->SettingScreen_spinbox_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->SettingScreen_spinbox_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->SettingScreen_spinbox_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->SettingScreen_spinbox_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->SettingScreen_spinbox_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for SettingScreen_spinbox_1, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->SettingScreen_spinbox_1, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->SettingScreen_spinbox_1, &lv_font_montserratMedium_12, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->SettingScreen_spinbox_1, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->SettingScreen_spinbox_1, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->SettingScreen_spinbox_1, lv_color_hex(0x2195f6), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->SettingScreen_spinbox_1, LV_GRAD_DIR_NONE, LV_PART_CURSOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_SettingScreen_spinbox_1_extra_btns_main_default
	static lv_style_t style_SettingScreen_spinbox_1_extra_btns_main_default;
	ui_init_style(&style_SettingScreen_spinbox_1_extra_btns_main_default);
	
	lv_style_set_text_color(&style_SettingScreen_spinbox_1_extra_btns_main_default, lv_color_hex(0xffffff));
	lv_style_set_text_font(&style_SettingScreen_spinbox_1_extra_btns_main_default, &lv_font_montserratMedium_12);
	lv_style_set_text_opa(&style_SettingScreen_spinbox_1_extra_btns_main_default, 255);
	lv_style_set_bg_opa(&style_SettingScreen_spinbox_1_extra_btns_main_default, 255);
	lv_style_set_bg_color(&style_SettingScreen_spinbox_1_extra_btns_main_default, lv_color_hex(0x2195f6));
	lv_style_set_bg_grad_dir(&style_SettingScreen_spinbox_1_extra_btns_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_border_width(&style_SettingScreen_spinbox_1_extra_btns_main_default, 0);
	lv_style_set_radius(&style_SettingScreen_spinbox_1_extra_btns_main_default, 5);
	lv_obj_add_style(ui->SettingScreen_spinbox_1_btn, &style_SettingScreen_spinbox_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->SettingScreen_spinbox_1_btn_minus, &style_SettingScreen_spinbox_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes SettingScreen_btn_1
	ui->SettingScreen_btn_1 = lv_btn_create(ui->SettingScreen);
	ui->SettingScreen_btn_1_label = lv_label_create(ui->SettingScreen_btn_1);
	lv_label_set_text(ui->SettingScreen_btn_1_label, "Button");
	lv_label_set_long_mode(ui->SettingScreen_btn_1_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->SettingScreen_btn_1_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->SettingScreen_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->SettingScreen_btn_1_label, LV_PCT(100));
	lv_obj_set_pos(ui->SettingScreen_btn_1, 398, 360);
	lv_obj_set_size(ui->SettingScreen_btn_1, 100, 50);

	//Write style for SettingScreen_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->SettingScreen_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->SettingScreen_btn_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->SettingScreen_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->SettingScreen_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->SettingScreen_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->SettingScreen_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->SettingScreen_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->SettingScreen_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->SettingScreen_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->SettingScreen_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//The custom code of SettingScreen.
	

	//Update current screen layout.
	lv_obj_update_layout(ui->SettingScreen);

	//Init events for screen.
	events_init_SettingScreen(ui);
}
