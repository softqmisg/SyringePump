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
	lv_obj_set_pos(ui->MainScreen_btn_2, 350, 190);
	lv_obj_set_size(ui->MainScreen_btn_2, 100, 50);

	//Write style for MainScreen_btn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_btn_2, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_btn_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_btn_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_btn_2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
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
	lv_obj_set_pos(ui->MainScreen_btn_1, 350, 269);
	lv_obj_set_size(ui->MainScreen_btn_1, 100, 50);

	//Write style for MainScreen_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_btn_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//The custom code of MainScreen.
	MainScreengroup(ui);

	//Update current screen layout.
	lv_obj_update_layout(ui->MainScreen);

	//Init events for screen.
	events_init_MainScreen(ui);
}
