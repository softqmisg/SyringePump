/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"

#if LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif


#include "custom.h"
static void MainScreen_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		ui_move_animation(guider_ui.MainScreen_imgDroplet, 1500, 100, 397, 100, &lv_anim_path_ease_in, LV_ANIM_REPEAT_INFINITE, 200, 0, 0, NULL, NULL, NULL);
		lv_obj_clear_flag(guider_ui.MainScreen_btnGoSetting, LV_OBJ_FLAG_CLICK_FOCUSABLE);
		lv_obj_clear_flag(guider_ui.MainScreen_btnGoMain, LV_OBJ_FLAG_CLICK_FOCUSABLE);
		lv_obj_clear_flag(guider_ui.MainScreen_datetext, LV_OBJ_FLAG_CLICK_FOCUSABLE);
		lv_obj_set_style_radius(guider_ui.MainScreen_barOcclusionLevel, 0, LV_PART_MAIN);
		lv_obj_set_style_radius(guider_ui.MainScreen_barBatteryLevel, 0, LV_PART_MAIN);
		break;
	}
	default:
		break;
	}
}
static void MainScreen_btnGoSetting_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_move_animation(guider_ui.MainScreen_contSetting, 200, 0, 0, 80, &lv_anim_path_linear, 0, 0, 0, 0, NULL, NULL, NULL);
		ui_move_animation(guider_ui.MainScreen_contMain, 200, 0, -800, 80, &lv_anim_path_linear, 0, 0, 0, 0, NULL, NULL, NULL);
		SettingConSetGroup(&guider_ui);
		break;
	}
	default:
		break;
	}
}
static void MainScreen_btnGoMain_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_move_animation(guider_ui.MainScreen_contSetting, 200, 0, 800, 80, &lv_anim_path_linear, 0, 0, 0, 0, NULL, NULL, NULL);
		ui_move_animation(guider_ui.MainScreen_contMain, 200, 0, 0, 80, &lv_anim_path_linear, 0, 0, 0, 0, NULL, NULL, NULL);
		MainConSetGroup(&guider_ui);
		break;
	}
	default:
		break;
	}
}
void events_init_MainScreen(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->MainScreen, MainScreen_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_btnGoSetting, MainScreen_btnGoSetting_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_btnGoMain, MainScreen_btnGoMain_event_handler, LV_EVENT_ALL, ui);
}

void events_init(lv_ui *ui)
{

}
