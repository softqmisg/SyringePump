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
#include "custom.h"
static void InitScreen_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.MainScreen, guider_ui.MainScreen_del, &guider_ui.InitScreen_del, setup_scr_MainScreen, LV_SCR_LOAD_ANIM_FADE_ON, 400, 3000, false, true);
		break;
	}
	default:
		break;
	}
}
void events_init_InitScreen(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->InitScreen, InitScreen_event_handler, LV_EVENT_ALL, ui);
}
static void MainScreen_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		lv_ui *ui=lv_event_get_user_data(e);
	MainScreengroup(ui);
		break;
	}
	default:
		break;
	}
}
static void MainScreen_btn_2_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_PRESSED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.SettingScreen, guider_ui.SettingScreen_del, &guider_ui.MainScreen_del, setup_scr_SettingScreen, LV_SCR_LOAD_ANIM_OVER_LEFT, 200, 200, false, true);
		break;
	}
	default:
		break;
	}
}
void events_init_MainScreen(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->MainScreen, MainScreen_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_btn_2, MainScreen_btn_2_event_handler, LV_EVENT_ALL, ui);
}
static void SettingScreen_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		lv_ui *ui=lv_event_get_user_data(e);
	SettingScreengroup(ui);
		break;
	}
	default:
		break;
	}
}
static void SettingScreen_btn_1_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_PRESSED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.MainScreen, guider_ui.MainScreen_del, &guider_ui.SettingScreen_del, setup_scr_MainScreen, LV_SCR_LOAD_ANIM_OVER_RIGHT, 200, 200, false, true);
		break;
	}
	default:
		break;
	}
}
void events_init_SettingScreen(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->SettingScreen, SettingScreen_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->SettingScreen_btn_1, SettingScreen_btn_1_event_handler, LV_EVENT_ALL, ui);
}

void events_init(lv_ui *ui)
{

}
