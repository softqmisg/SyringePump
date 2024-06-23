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



void setup_scr_LogoScreen(lv_ui *ui)
{
	//Write codes LogoScreen
	ui->LogoScreen = lv_obj_create(NULL);
	ui->g_kb_LogoScreen = lv_keyboard_create(ui->LogoScreen);
	lv_obj_add_event_cb(ui->g_kb_LogoScreen, kb_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_add_flag(ui->g_kb_LogoScreen, LV_OBJ_FLAG_HIDDEN);
	lv_obj_set_style_text_font(ui->g_kb_LogoScreen, &lv_font_SourceHanSerifSC_Regular_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_size(ui->LogoScreen, 800, 480);
	lv_obj_set_scrollbar_mode(ui->LogoScreen, LV_SCROLLBAR_MODE_OFF);

	//Write style for LogoScreen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->LogoScreen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->LogoScreen, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->LogoScreen, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes LogoScreen_img_1
	ui->LogoScreen_img_1 = lv_img_create(ui->LogoScreen);
	lv_obj_add_flag(ui->LogoScreen_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->LogoScreen_img_1, &_farafan_logo_600x194);
	lv_img_set_pivot(ui->LogoScreen_img_1, 0,0);
	lv_img_set_angle(ui->LogoScreen_img_1, 0);
	lv_obj_set_pos(ui->LogoScreen_img_1, 100, 143);
	lv_obj_set_size(ui->LogoScreen_img_1, 600, 194);

	//Write style for LogoScreen_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->LogoScreen_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//The custom code of LogoScreen.
	

	//Update current screen layout.
	lv_obj_update_layout(ui->LogoScreen);

	//Init events for screen.
	events_init_LogoScreen(ui);
}
