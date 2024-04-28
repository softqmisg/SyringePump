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



void setup_scr_InitScreen(lv_ui *ui)
{
	//Write codes InitScreen
	ui->InitScreen = lv_obj_create(NULL);
	lv_obj_set_size(ui->InitScreen, 800, 480);
	lv_obj_set_scrollbar_mode(ui->InitScreen, LV_SCROLLBAR_MODE_OFF);

	//Write style for InitScreen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->InitScreen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->InitScreen, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->InitScreen, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes InitScreen_img_1
	ui->InitScreen_img_1 = lv_img_create(ui->InitScreen);
	lv_obj_add_flag(ui->InitScreen_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->InitScreen_img_1, &_logo_new_color_small_alpha_340x340);
	lv_img_set_pivot(ui->InitScreen_img_1, 50,50);
	lv_img_set_angle(ui->InitScreen_img_1, 0);
	lv_obj_set_pos(ui->InitScreen_img_1, 230, 70);
	lv_obj_set_size(ui->InitScreen_img_1, 340, 340);

	//Write style for InitScreen_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->InitScreen_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//The custom code of InitScreen.
	

	//Update current screen layout.
	lv_obj_update_layout(ui->InitScreen);

	//Init events for screen.
	events_init_InitScreen(ui);
}
