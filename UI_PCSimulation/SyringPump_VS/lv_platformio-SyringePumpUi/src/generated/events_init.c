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
extern lv_group_t *g_drugvalues;
 uint8_t cur_Drug;
extern lv_group_t *g_modevalues;

 uint8_t cur_ModeMode,cur_ModeUnit;
static void LogoScreen_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.MainScreen, guider_ui.MainScreen_del, &guider_ui.LogoScreen_del, setup_scr_MainScreen, LV_SCR_LOAD_ANIM_FADE_ON, 800, 4000, false, true);
		lv_obj_fade_in(guider_ui.LogoScreen_img_1,1800,200);
	
		break;
	}
	default:
		break;
	}
}
void events_init_LogoScreen(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->LogoScreen, LogoScreen_event_handler, LV_EVENT_ALL, ui);
}
static void MainScreen_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		ui_move_animation(guider_ui.MainScreen_imgDroplet, 1500, 100, 397, 100, &lv_anim_path_ease_in, LV_ANIM_REPEAT_INFINITE, 200, 0, 0, NULL, NULL, NULL);
		updateSyringeCompanyList(&guider_ui);
	updateDrugList(&guider_ui);
	updateModeModeList(&guider_ui);
	
	
		break;
	}
	default:
		break;
	}
}
static void MainScreen_btnGoMenuMain_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		
	
		ui_move_animation(guider_ui.MainScreen_contMenu, 200, 0, 0, 80, &lv_anim_path_linear, 0, 0, 0, 0, NULL, animcontMenu_ready_callback, NULL);
		ui_move_animation(guider_ui.MainScreen_contMain, 200, 0, -800, 80, &lv_anim_path_linear, 0, 0, 0, 0, NULL, NULL, NULL);
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
		ui_move_animation(guider_ui.MainScreen_contMenu, 200, 0, 800, 80, &lv_anim_path_linear, 0, 0, 0, 0, NULL, NULL, NULL);
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
static void MainScreen_btnMenuDrug_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_move_animation(guider_ui.MainScreen_contMenu, 200, 0, 800, 80, &lv_anim_path_linear, 0, 0, 0, 0, NULL, NULL, NULL);
		ui_move_animation(guider_ui.MainScreen_contDrug, 200, 0, 0, 80, &lv_anim_path_linear, 0, 0, 0, 0, NULL, animcontDrug_ready_callback, NULL);
		break;
	}
	default:
		break;
	}
}
static void MainScreen_btnMenuMode_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_move_animation(guider_ui.MainScreen_contMenu, 200, 0, 800, 80, &lv_anim_path_linear, 0, 0, 0, 0, NULL, NULL, NULL);
		ui_move_animation(guider_ui.MainScreen_contMode, 200, 0, 0, 80, &lv_anim_path_linear, 0, 0, 0, 0, NULL, animcontMode_ready_callback, NULL);
		lv_obj_add_flag(guider_ui.MainScreen_listModeUnit, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.MainScreen_listModeUnit, LV_OBJ_FLAG_CLICKABLE);
		lv_obj_add_flag(guider_ui.MainScreen_contModeValues, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.MainScreen_contModeValues, LV_OBJ_FLAG_CLICKABLE);
		break;
	}
	default:
		break;
	}
}
static void MainScreen_btnGoMainMenu_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_move_animation(guider_ui.MainScreen_contMenu, 200, 0, 800, 80, &lv_anim_path_linear, 0, 0, 0, 0, NULL, NULL, NULL);
		ui_move_animation(guider_ui.MainScreen_contMain, 200, 0, 0, 80, &lv_anim_path_linear, 0, 0, 0, 0, NULL, animcontMain_ready_callback, NULL);
		break;
	}
	default:
		break;
	}
}
static void MainScreen_btnGoMenuSyringe_event_handler (lv_event_t *e)
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
		  ui_move_animation(ui->MainScreen_contMenu,200,0,0,80,&lv_anim_path_linear,0,0,0,0,NULL,animcontMenu_ready_callback,NULL);
		  ui_move_animation(ui->MainScreen_contSyringe,200,0,800,80,&lv_anim_path_linear,0,0,0,0,NULL,NULL,NULL);
	      lv_obj_add_state(ui->MainScreen_btnMenuSyringe,LV_STATE_FOCUS_KEY);		  
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
		lv_obj_clear_flag(guider_ui.MainScreen_contSyringeValues, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.MainScreen_listSyringeType, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.MainScreen_listSyringeType, LV_OBJ_FLAG_CLICKABLE);
		lv_ui *ui=(lv_ui *)lv_event_get_user_data(e);
	lv_obj_t *obj=lv_event_get_target(e);
	cur_SyringeManufacture=lv_obj_get_child_id(obj);
	updateSyringeTypeList(ui,cur_SyringeManufacture);
	setlistSyringeTypeGroup(ui);
	lv_obj_add_state(obj,LV_STATE_FOCUS_KEY);
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
	updateSyringeValues(ui,cur_SyringeManufacture,cur_SyringeType);
	
		break;
	}
	default:
		break;
	}
}
static void MainScreen_btnGoMenuDrug_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
					lv_ui *ui=(lv_ui *)lv_event_get_user_data(e);
				lv_obj_t *obj=lv_event_get_target(e);	
				if(lv_obj_has_flag(ui->MainScreen_contDrugValues,LV_OBJ_FLAG_CLICKABLE))
				{
					uint8_t id;
					id=lv_obj_get_child_id(lv_group_get_focused(g_drugvalues));
				  printf("@1id=%d\n",id);
				  if(id<10) 
				  {
				    lv_obj_clear_flag(ui->MainScreen_contDrugValues, LV_OBJ_FLAG_CLICKABLE);
				    lv_obj_add_flag(ui->MainScreen_listDrugBrand, LV_OBJ_FLAG_CLICKABLE);
				    setlistDrugBrandGroup(ui);
				  }
				  else
				  {
					lv_obj_t *obj=lv_group_get_focused(g_drugvalues);
					lv_obj_clear_state(obj,LV_STATE_FOCUS_KEY);
					lv_group_focus_prev(g_drugvalues);
					obj=lv_group_get_focused(g_drugvalues);
					lv_obj_add_state(obj,LV_STATE_FOCUS_KEY);		
			
				  }
			
				}
				else
				{
				  ui_move_animation(ui->MainScreen_contMenu,200,0,0,80,&lv_anim_path_linear,0,0,0,0,NULL,animcontMenu_ready_callback,NULL);
				  ui_move_animation(ui->MainScreen_contDrug,200,0,800,80,&lv_anim_path_linear,0,0,0,0,NULL,NULL,NULL);
	              lv_obj_add_state(ui->MainScreen_btnMenuDrug,LV_STATE_FOCUS_KEY);		  
				}
		break;
	}
	default:
		break;
	}
}
static void MainScreen_listDrugBrand_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
				lv_ui *ui=(lv_ui *)lv_event_get_user_data(e);
		lv_obj_t *obj=lv_event_get_target(e);
		setcontDrugValuesGroup(ui);
		lv_obj_add_state(obj,LV_STATE_FOCUS_KEY);
		lv_obj_add_flag(guider_ui.MainScreen_contDrugValues, LV_OBJ_FLAG_CLICKABLE);
		lv_obj_add_flag(guider_ui.MainScreen_contDrugValues, LV_OBJ_FLAG_CLICKABLE);
		break;
	}
	case LV_EVENT_FOCUSED:
	{
		lv_ui *ui=(lv_ui *)lv_event_get_user_data(e);
	lv_obj_t *obj=lv_event_get_target(e);
	cur_Drug=lv_obj_get_child_id(obj);
	updateDrugValues(ui,cur_Drug);
		break;
	}
	default:
		break;
	}
}
static void MainScreen_btnGoMenuMode_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		  lv_ui *ui=(lv_ui *)lv_event_get_user_data(e);
		lv_obj_t *obj=lv_event_get_target(e);	
		if(lv_obj_has_flag(ui->MainScreen_contModeValues,LV_OBJ_FLAG_CLICKABLE))
		{
			uint8_t id;
			id=lv_obj_get_child_id(lv_obj_get_parent(lv_group_get_focused(g_modevalues)));
			
		  printf("@id=%d\n",id);
		  if(id==3) 
		  {
		    lv_obj_clear_flag(ui->MainScreen_contModeValues, LV_OBJ_FLAG_CLICKABLE);
		    lv_obj_add_flag(ui->MainScreen_listModeUnit, LV_OBJ_FLAG_CLICKABLE);
		    setlistModeUnitGroup(ui);
		  }
		  else
		  {
			lv_obj_t *obj=lv_group_get_focused(g_modevalues);
			lv_obj_clear_state(obj,LV_STATE_FOCUS_KEY);
			lv_group_focus_prev(g_modevalues);
			obj=lv_group_get_focused(g_modevalues);
			lv_obj_add_state(obj,LV_STATE_FOCUS_KEY);		
		  }
		}
		else if (lv_obj_has_flag(ui->MainScreen_listModeUnit,LV_OBJ_FLAG_CLICKABLE))
		{
		  lv_obj_clear_flag(ui->MainScreen_listModeUnit, LV_OBJ_FLAG_CLICKABLE);
		  lv_obj_add_flag(ui->MainScreen_listModeMode, LV_OBJ_FLAG_CLICKABLE);
		  lv_obj_add_flag(ui->MainScreen_listModeUnit, LV_OBJ_FLAG_HIDDEN);
		  lv_obj_add_flag(ui->MainScreen_contModeValues, LV_OBJ_FLAG_HIDDEN);
		  setlistModeModeGroup(ui);
		}
		else
		{
		  ui_move_animation(ui->MainScreen_contMenu,200,0,0,80,&lv_anim_path_linear,0,0,0,0,NULL,animcontMenu_ready_callback,NULL);
		  ui_move_animation(ui->MainScreen_contMode,200,0,800,80,&lv_anim_path_linear,0,0,0,0,NULL,NULL,NULL);
	      lv_obj_add_state(ui->MainScreen_btnMenuMode,LV_STATE_FOCUS_KEY);		  
		}
		break;
	}
	default:
		break;
	}
}
static void MainScreen_listModeMode_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_obj_clear_flag(guider_ui.MainScreen_listModeUnit, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.MainScreen_listModeUnit, LV_OBJ_FLAG_CLICKABLE);
		lv_obj_clear_flag(guider_ui.MainScreen_contModeValues, LV_OBJ_FLAG_HIDDEN);
		  lv_ui *ui=(lv_ui *)lv_event_get_user_data(e);
	  lv_obj_t *obj=lv_event_get_target(e);
	  cur_ModeMode=lv_obj_get_child_id(obj);
	  updateModeUnitList(ui,cur_ModeMode);
	  setlistModeUnitGroup(ui);
	  lv_obj_add_state(obj,LV_STATE_FOCUS_KEY);
		break;
	}
	default:
		break;
	}
}
static void MainScreen_listModeUnit_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_ui *ui=(lv_ui *)lv_event_get_user_data(e);
	lv_obj_t *obj=lv_event_get_target(e);
	setcontModeValuesGroup(ui);
	lv_obj_add_state(obj,LV_STATE_FOCUS_KEY);
		lv_obj_add_flag(guider_ui.MainScreen_contModeValues, LV_OBJ_FLAG_CLICKABLE);
		break;
	}
	case LV_EVENT_FOCUSED:
	{
		lv_ui *ui=(lv_ui *)lv_event_get_user_data(e);
	lv_obj_t *obj=lv_event_get_target(e);
	cur_ModeUnit=lv_obj_get_child_id(obj);
	updateModeValues(ui,cur_ModeMode,cur_ModeUnit);
	
		break;
	}
	default:
		break;
	}
}
void events_init_MainScreen(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->MainScreen, MainScreen_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_btnGoMenuMain, MainScreen_btnGoMenuMain_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_btnGoMainMenu, MainScreen_btnGoMainMenu_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_btnMenuSyringe, MainScreen_btnMenuSyringe_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_btnMenuDrug, MainScreen_btnMenuDrug_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_btnMenuMode, MainScreen_btnMenuMode_event_handler, LV_EVENT_ALL, ui);
	// lv_obj_add_event_cb(ui->MainScreen_btnMenuOCC, MainScreen_btnMenuOCC_event_handler, LV_EVENT_ALL, ui);
	// lv_obj_add_event_cb(ui->MainScreen_btnMenuKVO, MainScreen_btnMenuKVO_event_handler, LV_EVENT_ALL, ui);
	// lv_obj_add_event_cb(ui->MainScreen_btnMenuIntInf, MainScreen_btnMenuIntInf_event_handler, LV_EVENT_ALL, ui);
	// lv_obj_add_event_cb(ui->MainScreen_btnMenuRhyInf, MainScreen_btnMenuRhyInf_event_handler, LV_EVENT_ALL, ui);
	// lv_obj_add_event_cb(ui->MainScreen_btnMenuNurseCall, MainScreen_btnMenuNurseCall_event_handler, LV_EVENT_ALL, ui);
	// lv_obj_add_event_cb(ui->MainScreen_btnMenuBolus, MainScreen_btnMenuBolus_event_handler, LV_EVENT_ALL, ui);
	// lv_obj_add_event_cb(ui->MainScreen_btnMenuPurge, MainScreen_btnMenuPurge_event_handler, LV_EVENT_ALL, ui);
	// lv_obj_add_event_cb(ui->MainScreen_btnMenuSetting, MainScreen_btnMenuSetting_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_btnGoMenuSyringe, MainScreen_btnGoMenuSyringe_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_btnGoMenuDrug, MainScreen_btnGoMenuDrug_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_btnGoMenuMode, MainScreen_btnGoMenuMode_event_handler, LV_EVENT_ALL, ui);


	for(int i=0;i<lv_obj_get_child_cnt(ui->MainScreen_listSyringeCompany);i++)
		lv_obj_add_event_cb(lv_obj_get_child(ui->MainScreen_listSyringeCompany,i), MainScreen_listSyringeCompany_event_handler, LV_EVENT_ALL, ui);
    for(int i=0;i<lv_obj_get_child_cnt(ui->MainScreen_listSyringeType);i++)
		lv_obj_add_event_cb(lv_obj_get_child(ui->MainScreen_listSyringeType,i), MainScreen_listSyringeType_event_handler, LV_EVENT_ALL, ui);	
    for(int i=0;i<lv_obj_get_child_cnt(ui->MainScreen_listDrugBrand);i++)
		lv_obj_add_event_cb(lv_obj_get_child(ui->MainScreen_listDrugBrand,i), MainScreen_listDrugBrand_event_handler, LV_EVENT_ALL, ui);	
    for(int i=0;i<lv_obj_get_child_cnt(ui->MainScreen_listModeMode);i++)
		lv_obj_add_event_cb(lv_obj_get_child(ui->MainScreen_listModeMode,i), MainScreen_listModeMode_event_handler, LV_EVENT_ALL, ui);	
    for(int i=0;i<lv_obj_get_child_cnt(ui->MainScreen_listModeUnit);i++)
		lv_obj_add_event_cb(lv_obj_get_child(ui->MainScreen_listModeUnit,i), MainScreen_listModeUnit_event_handler, LV_EVENT_ALL, ui);	


}

void events_init(lv_ui *ui)
{

}
