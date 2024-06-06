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
extern lv_group_t *g_syringevalues;
 uint8_t cur_SyringeManufacture,cur_SyringeType;
static void MainScreen_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		ui_move_animation(guider_ui.MainScreen_imgDroplet, 1500, 100, 397, 100, &lv_anim_path_ease_in, LV_ANIM_REPEAT_INFINITE, 200, 0, 0, NULL, NULL, NULL);
		updateSyringeCompanyList(&guider_ui);
	updateSyringeDrugList(&guider_ui);
		break;
	}
	default:
		break;
	}
}
static void MainScreen_btnGoSettingMain_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		
	
		ui_move_animation(guider_ui.MainScreen_contSetting, 200, 0, 0, 80, &lv_anim_path_linear, 0, 0, 0, 0, NULL, animcontSetting_ready_callback, NULL);
		ui_move_animation(guider_ui.MainScreen_contMain, 200, 0, -800, 80, &lv_anim_path_linear, 0, 0, 0, 0, NULL, NULL, NULL);
		break;
	}
	default:
		break;
	}
}
static void MainScreen_btnGoMainSetting_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_move_animation(guider_ui.MainScreen_contSetting, 200, 0, 800, 80, &lv_anim_path_linear, 0, 0, 0, 0, NULL, NULL, NULL);
		ui_move_animation(guider_ui.MainScreen_contMain, 200, 0, 0, 80, &lv_anim_path_linear, 0, 0, 0, 0, NULL, animcontMain_ready_callback, NULL);
		break;
	}
	default:
		break;
	}
}
static void MainScreen_btnMenuSyringe_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		
	
		ui_move_animation(guider_ui.MainScreen_contSetting, 200, 0, 800, 80, &lv_anim_path_linear, 0, 0, 0, 0, NULL, NULL, NULL);
		ui_move_animation(guider_ui.MainScreen_contSyringe, 200, 0, 0, 80, &lv_anim_path_linear, 0, 0, 0, 0, NULL, animcontSyringe_ready_callback, NULL);
		lv_obj_add_flag(guider_ui.MainScreen_listSyringeType, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.MainScreen_listSyringeType, LV_OBJ_FLAG_CLICKABLE);
		lv_obj_add_flag(guider_ui.MainScreen_contSyringeValues, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.MainScreen_contSyringeValues, LV_OBJ_FLAG_CLICKABLE);
		break;
	}
	default:
		break;
	}
}
static void MainScreen_btnGoSettingSyringe_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
			lv_ui *ui=(lv_ui *)lv_event_get_user_data(e);
		lv_obj_t *obj=lv_event_get_target(e);	
		if(lv_obj_has_flag(ui->MainScreen_contSyringeValues,LV_OBJ_FLAG_CLICKABLE))
		{
			uint8_t id;
			id=lv_obj_get_child_id(lv_group_get_focused(g_syringevalues));
		  printf("@1id=%d\n",id);
		  if(id==7) 
		  {
		    lv_obj_clear_flag(ui->MainScreen_contSyringeValues, LV_OBJ_FLAG_CLICKABLE);
		    //lv_obj_clear_flag(guider_ui.MainScreen_contSyringeValues, LV_OBJ_FLAG_CLICK_FOCUSABLE);
		    lv_obj_add_flag(ui->MainScreen_listSyringeType, LV_OBJ_FLAG_CLICKABLE);
		    //lv_obj_add_flag(guider_ui.MainScreen_listSyringeType, LV_OBJ_FLAG_CLICK_FOCUSABLE);
		    setlistSyringeTypeGroup(ui);
		  }
		  else
		  {
			lv_obj_t *obj=lv_group_get_focused(g_syringevalues);
			lv_obj_clear_state(obj,LV_STATE_FOCUS_KEY);
			lv_group_focus_prev(g_syringevalues);
			obj=lv_group_get_focused(g_syringevalues);
			lv_obj_add_state(obj,LV_STATE_FOCUS_KEY);		
	
		  }
	
		}
		else if (lv_obj_has_flag(ui->MainScreen_listSyringeType,LV_OBJ_FLAG_CLICKABLE))
		{
		  lv_obj_clear_flag(ui->MainScreen_listSyringeType, LV_OBJ_FLAG_CLICKABLE);
		  //lv_obj_clear_flag(guider_ui.MainScreen_listSyringeType, LV_OBJ_FLAG_CLICK_FOCUSABLE);
		  lv_obj_add_flag(ui->MainScreen_listSyringeCompany, LV_OBJ_FLAG_CLICKABLE);
		  //lv_obj_add_flag(guider_ui.MainScreen_listSyringeCompany, LV_OBJ_FLAG_CLICK_FOCUSABLE);
		  
		  lv_obj_add_flag(ui->MainScreen_listSyringeType, LV_OBJ_FLAG_HIDDEN);
		  lv_obj_add_flag(ui->MainScreen_contSyringeValues, LV_OBJ_FLAG_HIDDEN);
		  setlistSyringeCompanyGroup(ui);
		}
		else
		{
		  ui_move_animation(ui->MainScreen_contSetting,200,0,0,80,&lv_anim_path_linear,0,0,0,0,NULL,animcontSetting_ready_callback,NULL);
		  ui_move_animation(ui->MainScreen_contSyringe,200,0,800,80,&lv_anim_path_linear,0,0,0,0,NULL,NULL,NULL);
		}
		break;
	}
	default:
		break;
	}
}
static void MainScreen_listSyringeCompany_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_ui *ui=(lv_ui *)lv_event_get_user_data(e);
	lv_obj_t *obj=lv_event_get_target(e);
	cur_SyringeManufacture=lv_obj_get_child_id(obj);
	updateSyringeTypeList(ui,cur_SyringeManufacture);
	setlistSyringeTypeGroup(ui);
	lv_obj_add_state(obj,LV_STATE_FOCUS_KEY);
		lv_obj_clear_flag(guider_ui.MainScreen_contSyringeValues, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.MainScreen_listSyringeType, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.MainScreen_listSyringeType, LV_OBJ_FLAG_CLICKABLE);
		break;
	}
	default:
		break;
	}
}
static void MainScreen_listSyringeType_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_ui *ui=(lv_ui *)lv_event_get_user_data(e);
	lv_obj_t *obj=lv_event_get_target(e);
	setcontSyringeValuesGroup(ui);
	lv_obj_add_state(obj,LV_STATE_FOCUS_KEY);
		lv_obj_add_flag(guider_ui.MainScreen_contSyringeValues, LV_OBJ_FLAG_CLICKABLE);
		break;
	}
	case LV_EVENT_FOCUSED:
	{
		lv_ui *ui=(lv_ui *)lv_event_get_user_data(e);
	lv_obj_t *obj=lv_event_get_target(e);
	cur_SyringeType=lv_obj_get_child_id(obj);
	updateSyringeValues(ui,cur_SyringeType);
		break;
	}
	default:
		break;
	}
}
static void MainScreen_spinboxSyringeVolume_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_DEFOCUSED:
	{
		lv_ui *ui=(lv_ui *)lv_event_get_user_data(e);
	lv_obj_set_style_text_color(ui->MainScreen_spinboxSyringeDiaTolerance,lv_color_black(),LV_PART_MAIN);
	lv_obj_set_style_text_color(ui->MainScreen_spinboxSyringeDiaTolerance,lv_color_black(),LV_PART_CURSOR);
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxSyringeDiaTolerance,0,LV_PART_CURSOR);
		break;
	}
	default:
		break;
	}
}
void events_init_MainScreen(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->MainScreen, MainScreen_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_btnGoSettingMain, MainScreen_btnGoSettingMain_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_btnGoMainSetting, MainScreen_btnGoMainSetting_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_btnMenuSyringe, MainScreen_btnMenuSyringe_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_btnGoSettingSyringe, MainScreen_btnGoSettingSyringe_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_listSyringeCompany, MainScreen_listSyringeCompany_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_listSyringeType, MainScreen_listSyringeType_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_spinboxSyringeVolume, MainScreen_spinboxSyringeVolume_event_handler, LV_EVENT_ALL, ui);
}

void events_init(lv_ui *ui)
{

}
