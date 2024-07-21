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
#include "MachineState.h"
 uint8_t cur_SyringeManufacture,cur_SyringeType;
 uint8_t cur_Drug;


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
		animcontMain_ready_callback(NULL);
		ui_move_animation(guider_ui.MainScreen_imgFooterDroplet, 1500, 100, 397, 100, &lv_anim_path_ease_in, LV_ANIM_REPEAT_INFINITE, 200, 0, 0, NULL, NULL, NULL);
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
		ui_move_animation(guider_ui.MainScreen_contSyringe, 300, 0, 0, 80, &lv_anim_path_linear, 0, 0, 0, 0, NULL, animcontSyringe_ready_callback, NULL);
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
		ui_move_animation(guider_ui.MainScreen_contDrug, 300, 0, 0, 80, &lv_anim_path_linear, 0, 0, 0, 0, NULL, animcontDrug_ready_callback, NULL);
		lv_obj_clear_flag(guider_ui.MainScreen_contDrugValues, LV_OBJ_FLAG_CLICKABLE);
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
		ui_move_animation(guider_ui.MainScreen_contMode, 300, 0, 0, 80, &lv_anim_path_linear, 0, 0, 0, 0, NULL, animcontMode_ready_callback, NULL);
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
static void MainScreen_btnMenuOCC_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_move_animation(guider_ui.MainScreen_contOcclusion, 300, 0, 0, 80, &lv_anim_path_linear, 0, 0, 0, 0, NULL, animcontOcclusion_ready_callback, NULL);
		break;
	}
	default:
		break;
	}
}
static void MainScreen_btnMenuKVO_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_move_animation(guider_ui.MainScreen_contKVO, 300, 0, 0, 80, &lv_anim_path_linear, 0, 0, 0, 0, NULL, animcontKVO_ready_callback, NULL);
		break;
	}
	default:
		break;
	}
}
static void MainScreen_btnMenuIntInf_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_move_animation(guider_ui.MainScreen_contIntermittent, 300, 0, 0, 80, &lv_anim_path_linear, 0, 0, 0, 0, NULL, animcontIntermittent_ready_callback, NULL);
		break;
	}
	default:
		break;
	}
}
static void MainScreen_btnMenuNurseCall_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_move_animation(guider_ui.MainScreen_contNurseCall, 300, 0, 0, 80, &lv_anim_path_linear, 0, 0, 0, 0, NULL, animcontNurseCall_ready_callback, NULL);
		break;
	}
	default:
		break;
	}
}
static void MainScreen_btnMenuBolus_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_move_animation(guider_ui.MainScreen_contBolus, 300, 0, 0, 80, &lv_anim_path_linear, 0, 0, 0, 0, NULL, animcontBolus_ready_callback, NULL);
		break;
	}
	default:
		break;
	}
}
static void MainScreen_btnMenuPurge_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_move_animation(guider_ui.MainScreen_contPurge, 300, 0, 0, 80, &lv_anim_path_linear, 0, 0, 0, 0, NULL, animcontPurge_ready_callback, NULL);
		break;
	}
	default:
		break;
	}
}
static void MainScreen_btnMenuSetting_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_move_animation(guider_ui.MainScreen_contSettings, 300, 0, 0, 80, &lv_anim_path_linear, 0, 0, 0, 0, NULL, animcontSettings_ready_callback, NULL);
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
		        lv_group_t *g=lv_group_get_default();
		        uint8_t id=lv_obj_get_child_id(lv_group_get_focused(g));      
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
				lv_obj_t *obj=lv_group_get_focused(g);
				lv_obj_clear_state(obj,LV_STATE_FOCUS_KEY);
		        lv_group_set_editing(g,false);
				lv_group_focus_prev(g);
				obj=lv_group_get_focused(g);
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
			  ui_move_animation(ui->MainScreen_contSyringe,300,0,800,80,&lv_anim_path_linear,0,0,0,0,NULL,NULL,animcontSyringe_del_callback);
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
	case LV_EVENT_FOCUSED:
	{
		lv_ui *ui=(lv_ui *)lv_event_get_user_data(e);
	lv_label_set_text(ui->MainScreen_labelSyringeHeader,"Select Company");
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
			if(cur_SyringeManufacture==0)
			{
				setcontSyringeValuesGroup(ui);
				lv_obj_add_state(obj,LV_STATE_FOCUS_KEY);
				lv_obj_add_flag(guider_ui.MainScreen_contSyringeValues, LV_OBJ_FLAG_CLICKABLE);
			}
			else
			{
				memcpy(&currentMachineState.Syringe,&DefaultSyrings[cur_SyringeManufacture][cur_SyringeType],sizeof(syringe_t));
				lv_obj_clear_flag(ui->MainScreen_listSyringeType,LV_OBJ_FLAG_CLICKABLE);
				lv_obj_clear_flag(ui->MainScreen_contSyringeValues,LV_OBJ_FLAG_CLICKABLE);
				MainScreen_btnGoMenuSyringe_event_handler(e);
			}
		break;
	}
	case LV_EVENT_FOCUSED:
	{
		lv_ui *ui=(lv_ui *)lv_event_get_user_data(e);
	lv_obj_t *obj=lv_event_get_target(e);
	lv_label_set_text(ui->MainScreen_labelSyringeHeader,"Select Syringe Type");
	cur_SyringeType=lv_obj_get_child_id(obj);
	updateSyringeValues(ui,cur_SyringeManufacture,cur_SyringeType);
	
		break;
	}
	default:
		break;
	}
}
static void MainScreen_taSyringeNameValue_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_FOCUSED:
	{
		lv_ui *ui=(lv_ui *)lv_event_get_user_data(e);
	lv_label_set_text(ui->MainScreen_labelSyringeHeader,"Edit Name");
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
	case LV_EVENT_FOCUSED:
	{
		lv_ui *ui=(lv_ui *)lv_event_get_user_data(e);
	lv_label_set_text(ui->MainScreen_labelSyringeHeader,"Edit Volume (cc)");
		break;
	}
	default:
		break;
	}
}
static void MainScreen_spinboxSyringeInnerDia_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_FOCUSED:
	{
		lv_ui *ui=(lv_ui *)lv_event_get_user_data(e);
	lv_label_set_text(ui->MainScreen_labelSyringeHeader,"Edit Inner Diameter");
		break;
	}
	default:
		break;
	}
}
static void MainScreen_spinboxSyringeOuterDia_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_FOCUSED:
	{
		lv_ui *ui=(lv_ui *)lv_event_get_user_data(e);
	lv_label_set_text(ui->MainScreen_labelSyringeHeader,"Edit External Diameter");
		break;
	}
	default:
		break;
	}
}
static void MainScreen_spinboxSyringeBarrelLen_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_FOCUSED:
	{
		lv_ui *ui=(lv_ui *)lv_event_get_user_data(e);
	lv_label_set_text(ui->MainScreen_labelSyringeHeader,"Edit Barrel Length");
		break;
	}
	default:
		break;
	}
}
static void MainScreen_spinboxSyringePlungerLen_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_FOCUSED:
	{
		lv_ui *ui=(lv_ui *)lv_event_get_user_data(e);
	lv_label_set_text(ui->MainScreen_labelSyringeHeader,"Edit Plunger Length");
		break;
	}
	default:
		break;
	}
}
static void MainScreen_spinboxSyringeDiaTolerance_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_FOCUSED:
	{
		lv_ui *ui=(lv_ui *)lv_event_get_user_data(e);
	lv_label_set_text(ui->MainScreen_labelSyringeHeader,"Edit Diameter Tolerance");
		break;
	}
	default:
		break;
	}
}
static void MainScreen_btnDummySyringe_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_FOCUSED:
	{
		lv_ui *ui=(lv_ui *)lv_event_get_user_data(e);
	if(cur_SyringeManufacture==0)
	{
	    lv_snprintf(DefaultSyrings[cur_SyringeManufacture][cur_SyringeType].Name,20,"%s",lv_textarea_get_text(ui->MainScreen_taSyringeNameValue));
	    DefaultSyrings[cur_SyringeManufacture][cur_SyringeType].Volume=lv_spinbox_get_value(ui->MainScreen_spinboxSyringeVolume);
	    DefaultSyrings[cur_SyringeManufacture][cur_SyringeType].InnerDia10=lv_spinbox_get_value(ui->MainScreen_spinboxSyringeInnerDia);
	    DefaultSyrings[cur_SyringeManufacture][cur_SyringeType].OuterDia10=lv_spinbox_get_value(ui->MainScreen_spinboxSyringeOuterDia);
	    DefaultSyrings[cur_SyringeManufacture][cur_SyringeType].BarrelLen10=lv_spinbox_get_value(ui->MainScreen_spinboxSyringeBarrelLen);
	    DefaultSyrings[cur_SyringeManufacture][cur_SyringeType].PlungerLen10=lv_spinbox_get_value(ui->MainScreen_spinboxSyringePlungerLen);
	    DefaultSyrings[cur_SyringeManufacture][cur_SyringeType].DiaTolerance10=lv_spinbox_get_value(ui->MainScreen_spinboxSyringeDiaTolerance);
	}
	memcpy(&currentMachineState.Syringe,&DefaultSyrings[cur_SyringeManufacture][cur_SyringeType],sizeof(syringe_t));
	lv_obj_clear_flag(ui->MainScreen_contSyringeValues,LV_OBJ_FLAG_CLICKABLE);
	lv_obj_clear_flag(ui->MainScreen_listSyringeType,LV_OBJ_FLAG_CLICKABLE);
	e->code=LV_EVENT_CLICKED;
	MainScreen_btnGoMenuSyringe_event_handler(e);
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
					lv_group_t *g=lv_group_get_default();
					uint8_t id=lv_obj_get_child_id(lv_group_get_focused(g));
				  printf("@1id=%d\n",id);
				  if(id<10) 
				  {
				    lv_obj_clear_flag(ui->MainScreen_contDrugValues, LV_OBJ_FLAG_CLICKABLE);
				    lv_obj_add_flag(ui->MainScreen_listDrugBrand, LV_OBJ_FLAG_CLICKABLE);
				    setlistDrugBrandGroup(ui);
				  }
				  else
				  {
					lv_obj_t *obj=lv_group_get_focused(g);
					lv_obj_clear_state(obj,LV_STATE_FOCUS_KEY);
	                lv_group_set_editing(g,false);
					lv_group_focus_prev(g);
					obj=lv_group_get_focused(g);
					lv_obj_add_state(obj,LV_STATE_FOCUS_KEY);		
			
				  }
			
				}
				else
				{
				  ui_move_animation(ui->MainScreen_contDrug,300,0,800,80,&lv_anim_path_linear,0,0,0,0,NULL,NULL,animcontDrug_del_callback);
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
		  lv_ui *ui = (lv_ui *)lv_event_get_user_data(e);
	  lv_obj_t *obj = lv_event_get_target(e);
	
	      if (cur_Drug == 0)
	  {
	      setcontDrugValuesGroup(ui);
	      lv_obj_add_state(obj, LV_STATE_FOCUS_KEY);
	      lv_obj_add_flag(guider_ui.MainScreen_contDrugValues, LV_OBJ_FLAG_CLICKABLE);
	  }
	  else
	  {
	      memcpy(&currentMachineState.Drug, &DefaultDrugs[cur_Drug], sizeof(drug_t));
	      lv_obj_clear_flag(ui->MainScreen_contDrugValues, LV_OBJ_FLAG_CLICKABLE);
	      MainScreen_btnGoMenuDrug_event_handler(e);
	  }
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
static void MainScreen_taDrugNameValue_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_FOCUSED:
	{
		  lv_ui *ui = (lv_ui *)lv_event_get_user_data(e);
	  lv_label_set_text(ui->MainScreen_labelDrugHeader,"Edit Name");
		break;
	}
	default:
		break;
	}
}
static void MainScreen_taDrugBrandValue_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_FOCUSED:
	{
		  lv_ui *ui = (lv_ui *)lv_event_get_user_data(e);
	  lv_label_set_text(ui->MainScreen_labelDrugHeader,"Edit Mfg.");
		break;
	}
	default:
		break;
	}
}
static void MainScreen_ddlistDrugId_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_FOCUSED:
	{
		  lv_ui *ui = (lv_ui *)lv_event_get_user_data(e);
	  lv_label_set_text(ui->MainScreen_labelDrugHeader,"Edit Measuring Unit");
		uint16_t id = lv_dropdown_get_selected(guider_ui.MainScreen_ddlistDrugId);
		switch(id) {
		default:
			break;
		}
		break;
	}
	default:
		break;
	}
}
static void MainScreen_spinboxDrugmgml_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_FOCUSED:
	{
		  lv_ui *ui = (lv_ui *)lv_event_get_user_data(e);
	  lv_label_set_text(ui->MainScreen_labelDrugHeader,"Edit mg/ml");
		break;
	}
	default:
		break;
	}
}
static void MainScreen_spinboxDruguml_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_FOCUSED:
	{
		  lv_ui *ui = (lv_ui *)lv_event_get_user_data(e);
	  lv_label_set_text(ui->MainScreen_labelDrugHeader,"Edit Unit/ml");
		break;
	}
	default:
		break;
	}
}
static void MainScreen_spinboxDrugperkg_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_FOCUSED:
	{
		lv_ui *ui = (lv_ui *)lv_event_get_user_data(e);
	lv_label_set_text(ui->MainScreen_labelDrugHeader,"Edit Per Kg of Body Weight");
		break;
	}
	default:
		break;
	}
}
static void MainScreen_spinboxDrugRateMin_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_FOCUSED:
	{
		  lv_ui *ui = (lv_ui *)lv_event_get_user_data(e);
	  lv_label_set_text(ui->MainScreen_labelDrugHeader,"Edit Infusion Minimum Rate");
		break;
	}
	default:
		break;
	}
}
static void MainScreen_spinboxDrugRateMax_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_FOCUSED:
	{
		  lv_ui *ui = (lv_ui *)lv_event_get_user_data(e);
	  lv_label_set_text(ui->MainScreen_labelDrugHeader,"Edit Infusion Maximum Rate");
		break;
	}
	default:
		break;
	}
}
static void MainScreen_spinboxDrugRateDef_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_FOCUSED:
	{
		  lv_ui *ui = (lv_ui *)lv_event_get_user_data(e);
	  lv_label_set_text(ui->MainScreen_labelDrugHeader,"Edit Infusion Default Rate");
		break;
	}
	default:
		break;
	}
}
static void MainScreen_btnDummyDrug_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_FOCUSED:
	{
		lv_ui *ui=(lv_ui *)lv_event_get_user_data(e);
	if(cur_Drug==0)
	{
	    lv_snprintf(DefaultDrugs[cur_Drug].Name,20,"%s",lv_textarea_get_text(ui->MainScreen_taDrugNameValue));
	    lv_snprintf(DefaultDrugs[cur_Drug].Brand,20,"%s",lv_textarea_get_text(ui->MainScreen_taDrugBrandValue));
	    DefaultDrugs[cur_Drug].Id=lv_dropdown_get_selected(ui->MainScreen_ddlistDrugId);
	    DefaultDrugs[cur_Drug].mg_ml_1000=lv_spinbox_get_value(ui->MainScreen_spinboxDrugmgml);
	    DefaultDrugs[cur_Drug].u_ml_1000=lv_spinbox_get_value(ui->MainScreen_spinboxDruguml);
	    DefaultDrugs[cur_Drug].per_kg_1000=lv_spinbox_get_value(ui->MainScreen_spinboxDrugperkg);
	    DefaultDrugs[cur_Drug].RateMin10=lv_spinbox_get_value(ui->MainScreen_spinboxDrugRateMin);
	    DefaultDrugs[cur_Drug].RateMax10=lv_spinbox_get_value(ui->MainScreen_spinboxDrugRateMax);
	    DefaultDrugs[cur_Drug].RateDef10=lv_spinbox_get_value(ui->MainScreen_spinboxDrugRateDef);
	}
	memcpy(&currentMachineState.Drug, &DefaultDrugs[cur_Drug], sizeof(drug_t));
	lv_obj_clear_flag(ui->MainScreen_contDrugValues,LV_OBJ_FLAG_CLICKABLE);
	e->code=LV_EVENT_CLICKED;
	MainScreen_btnGoMenuDrug_event_handler(e);
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
					lv_group_t *g=lv_group_get_default();
					uint8_t id=lv_obj_get_child_id(lv_obj_get_parent(lv_group_get_focused(g)));		
				
			  printf("@id=%d\n",id);
			  if(id==3) 
			  {
			    lv_obj_clear_flag(ui->MainScreen_contModeValues, LV_OBJ_FLAG_CLICKABLE);
			    lv_obj_add_flag(ui->MainScreen_listModeUnit, LV_OBJ_FLAG_CLICKABLE);
			    setlistModeUnitGroup(ui);
			  }
			  else
			  {
				lv_obj_t *obj=lv_group_get_focused(g);
				lv_obj_clear_state(obj,LV_STATE_FOCUS_KEY);
	   			lv_group_set_editing(g,false);
				lv_group_focus_prev(g);
				obj=lv_group_get_focused(g);
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
		  ui_move_animation(ui->MainScreen_contMode,300,0,800,80,&lv_anim_path_linear,0,0,0,0,NULL,NULL,animcontMode_del_callback);
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
	case LV_EVENT_FOCUSED:
	{
		lv_ui *ui=(lv_ui *)lv_event_get_user_data(e);
	lv_label_set_text(ui->MainScreen_labelModeHeader,"Select Operating Mode");
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
	lv_label_set_text(ui->MainScreen_labelModeHeader,"Select Infusion Type");
	cur_ModeUnit=lv_obj_get_child_id(obj);
	updateModeValues(ui,cur_ModeMode,cur_ModeUnit);
		break;
	}
	default:
		break;
	}
}
static void MainScreen_spinboxModeBodyWeight_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_FOCUSED:
	{
		lv_ui *ui=(lv_ui *)lv_event_get_user_data(e);
	lv_label_set_text(ui->MainScreen_labelModeHeader,"Select Infusion Data");
		break;
	}
	default:
		break;
	}
}
static void MainScreen_spinboxModeInfusionRate_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_FOCUSED:
	{
		lv_ui *ui=(lv_ui *)lv_event_get_user_data(e);
	lv_label_set_text(ui->MainScreen_labelModeHeader,"Select Infusion Data");
		break;
	}
	default:
		break;
	}
}
static void MainScreen_spinboxModeTotalTimeHour_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_FOCUSED:
	{
		lv_ui *ui=(lv_ui *)lv_event_get_user_data(e);
	lv_label_set_text(ui->MainScreen_labelModeHeader,"Select Infusion Data");
		break;
	}
	default:
		break;
	}
}
static void MainScreen_spinboxModeTotalTimeMinute_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_FOCUSED:
	{
		lv_ui *ui=(lv_ui *)lv_event_get_user_data(e);
	lv_label_set_text(ui->MainScreen_labelModeHeader,"Select Infusion Data");
		break;
	}
	default:
		break;
	}
}
static void MainScreen_spinboxModeTotalTimeSecond_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_FOCUSED:
	{
		lv_ui *ui=(lv_ui *)lv_event_get_user_data(e);
	lv_label_set_text(ui->MainScreen_labelModeHeader,"Select Infusion Data");
		break;
	}
	default:
		break;
	}
}
static void MainScreen_spinboxModeTotalVolume_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_FOCUSED:
	{
		lv_ui *ui=(lv_ui *)lv_event_get_user_data(e);
	lv_label_set_text(ui->MainScreen_labelModeHeader,"Select Infusion Data");
		break;
	}
	default:
		break;
	}
}
static void MainScreen_btnDummyMode_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_FOCUSED:
	{
		lv_ui *ui=(lv_ui *)lv_event_get_user_data(e);
	DefaultModes[cur_ModeMode][cur_ModeUnit].TotalVolume10=lv_spinbox_get_value(ui->MainScreen_spinboxModeTotalVolume);
	DefaultModes[cur_ModeMode][cur_ModeUnit].InfusionRate10=lv_spinbox_get_value(ui->MainScreen_spinboxModeInfusionRate);
	DefaultModes[cur_ModeMode][cur_ModeUnit].TotalTime=lv_spinbox_get_value(ui->MainScreen_spinboxModeTotalTimeHour)*3600+
	                                                    lv_spinbox_get_value(ui->MainScreen_spinboxModeTotalTimeMinute)*60+
	                                                    lv_spinbox_get_value(ui->MainScreen_spinboxModeTotalTimeSecond);
	DefaultModes[cur_ModeMode][cur_ModeUnit].BodyWeight=lv_spinbox_get_value(ui->MainScreen_spinboxModeBodyWeight);
	memcpy(&currentMachineState.Mode,&DefaultModes[cur_ModeMode][cur_ModeUnit],sizeof(infusionmode_t));	
	if(cur_ModeMode==modeIntermittent)
	    currentMachineState.IntermittentInfusionRateUnit=cur_ModeUnit;
	lv_obj_clear_flag(ui->MainScreen_contModeValues,LV_OBJ_FLAG_CLICKABLE);
	lv_obj_clear_flag(ui->MainScreen_listModeUnit,LV_OBJ_FLAG_CLICKABLE);
	e->code=LV_EVENT_CLICKED;
	MainScreen_btnGoMenuMode_event_handler(e);
		break;
	}
	default:
		break;
	}
}
static void MainScreen_btnGoMenuOcclusion_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
				lv_ui *ui=(lv_ui *)lv_event_get_user_data(e);
			ui_move_animation(ui->MainScreen_contOcclusion,300,0,800,80,&lv_anim_path_linear,0,0,0,0,NULL,NULL,animcontOcclusion_del_callback);
		break;
	}
	default:
		break;
	}
}
static void MainScreen_sliderOcclusionOcc_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_VALUE_CHANGED:
	{
		lv_ui *ui=(lv_ui *)lv_event_get_user_data(e);
	printf("value=%d\n\r",lv_slider_get_value(ui->MainScreen_sliderOcclusionOcc));
	if(lv_slider_get_value(ui->MainScreen_sliderOcclusionOcc)==0)
	  lv_slider_set_value(ui->MainScreen_sliderOcclusionOcc,1,LV_ANIM_ON);
		break;
	}
	case LV_EVENT_CLICKED:
	{
		lv_ui *ui=(lv_ui *)lv_event_get_user_data(e);
	currentMachineState.OcclusionLevel=lv_slider_get_value(ui->MainScreen_sliderOcclusionOcc);
	MainScreen_btnGoMenuOcclusion_event_handler(e);
		break;
	}
	default:
		break;
	}
}
static void MainScreen_swKVOMode_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_VALUE_CHANGED:
	{
		lv_obj_t * status_obj = lv_event_get_target(e);
		int status = lv_obj_has_state(status_obj, LV_STATE_CHECKED) ? 1 : 0;
		switch(status) {
		case 0:
		{
			lv_obj_add_flag(guider_ui.MainScreen_labelswKVOModeEnable, LV_OBJ_FLAG_HIDDEN);
			lv_obj_clear_flag(guider_ui.MainScreen_labelswKVOModeDisable, LV_OBJ_FLAG_HIDDEN);
			break;
		}
		case 1:
		{
			lv_obj_clear_flag(guider_ui.MainScreen_labelswKVOModeEnable, LV_OBJ_FLAG_HIDDEN);
			lv_obj_add_flag(guider_ui.MainScreen_labelswKVOModeDisable, LV_OBJ_FLAG_HIDDEN);
			break;
		}
		default:
			break;
		}
		break;
	}
	default:
		break;
	}
}
static void MainScreen_btnGoMenuKVO_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_ui *ui=(lv_ui *)lv_event_get_user_data(e);
	lv_group_t *g=lv_group_get_default();
	uint8_t id=lv_obj_get_child_id(lv_group_get_focused(g));
	  
	printf("@KVO id=%d\n",id);
	if (lv_obj_has_state(ui->MainScreen_swKVOMode, LV_STATE_FOCUS_KEY)) 
	{
	  ui_move_animation(ui->MainScreen_contKVO,300,0,800,80,&lv_anim_path_linear,0,0,0,0,NULL,NULL,animcontKVO_del_callback);
	}
	else if(id>2)
	{
	  lv_obj_t *obj=lv_group_get_focused(g);
	  lv_obj_clear_state(obj,LV_STATE_FOCUS_KEY);
	  lv_group_set_editing(g,false);
	  lv_group_focus_prev(g);
	  obj=lv_group_get_focused(g);
	  lv_obj_add_state(obj,LV_STATE_FOCUS_KEY);		
	}
		break;
	}
	default:
		break;
	}
}
static void MainScreen_btnDummyKVO_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_FOCUSED:
	{
		        lv_ui *ui=(lv_ui *)lv_event_get_user_data(e);
	        if(lv_obj_has_state(ui->MainScreen_swKVOMode,LV_STATE_CHECKED))
	            currentMachineState.KvoMode=true;
	        else
	            currentMachineState.KvoMode=false;
	        currentMachineState.KvoRate10=lv_spinbox_get_value(ui->MainScreen_spinboxKVORate);
	        ui_move_animation(ui->MainScreen_contKVO,300,0,800,80,&lv_anim_path_linear,0,0,0,0,NULL,NULL,animcontKVO_del_callback);
		break;
	}
	default:
		break;
	}
}
static void MainScreen_btnGOMenuIntermittent_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_ui *ui=(lv_ui *)lv_event_get_user_data(e);
	lv_group_t *g=lv_group_get_default();
	uint8_t id=lv_obj_get_child_id(lv_group_get_focused(g));
	        
	      printf("@Intermittent id=%d\n",id);
	      if(id==6) 
	      {
	        ui_move_animation(ui->MainScreen_contIntermittent,300,0,800,80,&lv_anim_path_linear,0,0,0,0,NULL,NULL,animcontIntermittent_del_callback);
	      }
	      else
	      {
	        lv_obj_t *obj=lv_group_get_focused(g);
	        lv_obj_clear_state(obj,LV_STATE_FOCUS_KEY);
	        lv_group_set_editing(g,false);
	        lv_group_focus_prev(g);
	        obj=lv_group_get_focused(g);
	        lv_obj_add_state(obj,LV_STATE_FOCUS_KEY);		
	      }
		break;
	}
	default:
		break;
	}
}
static void MainScreen_btnDummyIntermittent_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_FOCUSED:
	{
		lv_ui *ui=(lv_ui *)lv_event_get_user_data(e);
	currentMachineState.IntermittentInfusionRate10=lv_spinbox_get_value(ui->MainScreen_spinboxIntermittentInfusionRate);
	currentMachineState.IntermittentDuration=lv_spinbox_get_value(ui->MainScreen_spinboxIntermittentDurationHour)*3600+
	                                                    lv_spinbox_get_value(ui->MainScreen_spinboxIntermittentDurationMinute)*60+
	                                                    lv_spinbox_get_value(ui->MainScreen_spinboxIntermittentDurationSecond);
	currentMachineState.IntermittentBackgroundRate10=lv_spinbox_get_value(ui->MainScreen_spinboxIntermittentBackgroundRate);
	
	currentMachineState.IntermittentSleep=lv_spinbox_get_value(ui->MainScreen_spinboxIntermittentSleepHour)*3600+
	                                                    lv_spinbox_get_value(ui->MainScreen_spinboxIntermittentSleepMinute)*60+
	                                                    lv_spinbox_get_value(ui->MainScreen_spinboxIntermittentSleepSecond);
	
	ui_move_animation(ui->MainScreen_contIntermittent,300,0,800,80,&lv_anim_path_linear,0,0,0,0,NULL,NULL,animcontIntermittent_del_callback);
	
		break;
	}
	default:
		break;
	}
}
static void MainScreen_swNurseCall_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_VALUE_CHANGED:
	{
		lv_obj_t * status_obj = lv_event_get_target(e);
		int status = lv_obj_has_state(status_obj, LV_STATE_CHECKED) ? 1 : 0;
		switch(status) {
		case 0:
		{
			lv_obj_add_flag(guider_ui.MainScreen_labelswNurseCallEnable, LV_OBJ_FLAG_HIDDEN);
			lv_obj_clear_flag(guider_ui.MainScreen_labelswNurseCallDisable, LV_OBJ_FLAG_HIDDEN);
			break;
		}
		case 1:
		{
			lv_obj_clear_flag(guider_ui.MainScreen_labelswNurseCallEnable, LV_OBJ_FLAG_HIDDEN);
			lv_obj_add_flag(guider_ui.MainScreen_labelswNurseCallDisable, LV_OBJ_FLAG_HIDDEN);
			break;
		}
		default:
			break;
		}
		break;
	}
	default:
		break;
	}
}
static void MainScreen_btnGoMenuNurseCall_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_ui *ui=(lv_ui *)lv_event_get_user_data(e);
	lv_group_t *g=lv_group_get_default();
	uint8_t id=lv_obj_get_child_id(lv_group_get_focused(g));
	  
	printf("@NurseCall id=%d\n",id);
	if(id==2) 
	{
	  ui_move_animation(ui->MainScreen_contNurseCall,200,0,800,80,&lv_anim_path_linear,0,0,0,0,NULL,NULL,animcontNurseCall_del_callback);
	}
	else
	{
	  lv_obj_t *obj=lv_group_get_focused(g);
	  lv_obj_clear_state(obj,LV_STATE_FOCUS_KEY);
	  lv_group_set_editing(g,false);
	  lv_group_focus_prev(g);
	  obj=lv_group_get_focused(g);
	  lv_obj_add_state(obj,LV_STATE_FOCUS_KEY);		
	}
		break;
	}
	default:
		break;
	}
}
static void MainScreen_btnDummyNurseCall_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_FOCUSED:
	{
		lv_ui *ui=(lv_ui *)lv_event_get_user_data(e);
	if(lv_obj_has_state(ui->MainScreen_swNurseCall,LV_STATE_CHECKED))
	    currentMachineState.NurseCall=true;
	else
	    currentMachineState.NurseCall=false;
	currentMachineState.NurseActiveDuration=lv_spinbox_get_value(ui->MainScreen_spinboxNurseCallDuration);
	ui_move_animation(ui->MainScreen_contNurseCall,300,0,800,80,&lv_anim_path_linear,0,0,0,0,NULL,NULL,animcontNurseCall_del_callback);
		break;
	}
	default:
		break;
	}
}
static void MainScreen_btnGoMenuBolus_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_ui *ui=(lv_ui *)lv_event_get_user_data(e);
	lv_group_t *g=lv_group_get_default();
	uint8_t id=lv_obj_get_child_id(lv_group_get_focused(g));
	  
	printf("@Bolus id=%d\n",id);
	if(lv_obj_has_state(ui->MainScreen_spinboxBolusRate,LV_STATE_FOCUS_KEY))
	{
	  ui_move_animation(ui->MainScreen_contBolus,200,0,800,80,&lv_anim_path_linear,0,0,0,0,NULL,NULL,animcontBolus_del_callback);
	}
	else
	{
	  lv_obj_t *obj=lv_group_get_focused(g);
	  lv_obj_clear_state(obj,LV_STATE_FOCUS_KEY);
	  lv_group_set_editing(g,false);
	  lv_group_focus_prev(g);
	  obj=lv_group_get_focused(g);
	  lv_obj_add_state(obj,LV_STATE_FOCUS_KEY);		
	}
		break;
	}
	default:
		break;
	}
}
static void MainScreen_btnDummyBolus_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_FOCUSED:
	{
		lv_ui *ui=(lv_ui *)lv_event_get_user_data(e);
	currentMachineState.BolusRate10=lv_spinbox_get_value(ui->MainScreen_spinboxBolusRate);
	currentMachineState.BolusMaxVolume10=lv_spinbox_get_value(ui->MainScreen_spinboxBolusMaxVolume);
	currentMachineState.BolusIntervalTime=lv_spinbox_get_value(ui->MainScreen_spinboxBolusIntervalHour)*3600+
	                                                    lv_spinbox_get_value(ui->MainScreen_spinboxBolusIntervalMinute)*60+
	                                                    lv_spinbox_get_value(ui->MainScreen_spinboxBolusIntervalSecond);
	ui_move_animation(ui->MainScreen_contBolus,300,0,800,80,&lv_anim_path_linear,0,0,0,0,NULL,NULL,animcontBolus_del_callback);
		break;
	}
	default:
		break;
	}
}
static void MainScreen_btnGoMenuPurge_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_ui *ui=(lv_ui *)lv_event_get_user_data(e);
	lv_group_t *g=lv_group_get_default();
	uint8_t id=lv_obj_get_child_id(lv_group_get_focused(g));
	  
	printf("@Purge id=%d\n",id);
	if(lv_obj_has_state(ui->MainScreen_spinboxPurgeRate,LV_STATE_FOCUS_KEY))
	{
	  ui_move_animation(ui->MainScreen_contPurge,200,0,800,80,&lv_anim_path_linear,0,0,0,0,NULL,NULL,animcontPurge_del_callback);
	}
	else
	{
	  lv_obj_t *obj=lv_group_get_focused(g);
	  lv_obj_clear_state(obj,LV_STATE_FOCUS_KEY);
	  lv_group_set_editing(g,false);
	  lv_group_focus_prev(g);
	  obj=lv_group_get_focused(g);
	  lv_obj_add_state(obj,LV_STATE_FOCUS_KEY);		
	}
		break;
	}
	default:
		break;
	}
}
static void MainScreen_btnDummyPurge_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_FOCUSED:
	{
		lv_ui *ui=(lv_ui *)lv_event_get_user_data(e);
	currentMachineState.PurgeRate10=lv_spinbox_get_value(ui->MainScreen_spinboxPurgeRate);
	currentMachineState.PurgeMaxVolume10=lv_spinbox_get_value(ui->MainScreen_spinboxPurgeMaxVolume);
	currentMachineState.PurgeIntervalTime=lv_spinbox_get_value(ui->MainScreen_spinboxPurgeIntervalHour)*3600+
	                                                    lv_spinbox_get_value(ui->MainScreen_spinboxPurgeIntervalMinute)*60+
	                                                    lv_spinbox_get_value(ui->MainScreen_spinboxPurgeIntervalSecond);
	ui_move_animation(ui->MainScreen_contPurge,300,0,800,80,&lv_anim_path_linear,0,0,0,0,NULL,NULL,animcontPurge_del_callback);
		break;
	}
	default:
		break;
	}
}
static void MainScreen_btnSettingsClock_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_move_animation(guider_ui.MainScreen_contSettingsClock, 300, 0, 0, 80, &lv_anim_path_linear, 0, 0, 0, 0, NULL, animcontSettingsClock_ready_callback, NULL);
		break;
	}
	default:
		break;
	}
}
static void MainScreen_btnSettingsCalender_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_move_animation(guider_ui.MainScreen_contSettingsCalender, 300, 0, 0, 80, &lv_anim_path_linear, 0, 0, 0, 0, NULL, animcontSettingsCalender_ready_callback, NULL);
		break;
	}
	default:
		break;
	}
}
static void MainScreen_btnGoMenuSettings_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_move_animation(guider_ui.MainScreen_contSettings, 300, 0, 800, 80, &lv_anim_path_linear, 0, 0, 0, 0, NULL, NULL, animcontSettings_del_callback);
		break;
	}
	default:
		break;
	}
}
static void MainScreen_btnGoSettingsClock_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_ui *ui=(lv_ui *)lv_event_get_user_data(e);
	lv_group_t *g=lv_group_get_default();
	uint8_t id=lv_obj_get_child_id(lv_group_get_focused(g));
	  
	printf("@Setting Clock id=%d\n",id);
	if(lv_obj_has_state(ui->MainScreen_spinboxSettingsClockHour,LV_STATE_FOCUS_KEY))
	{
	  ui_move_animation(ui->MainScreen_contSettingsClock,300,0,800,80,&lv_anim_path_linear,0,0,0,0,NULL,NULL,animcontSettingsClock_del_callback);
	}
	else
	{
	  lv_obj_t *obj=lv_group_get_focused(g);
	  lv_obj_clear_state(obj,LV_STATE_FOCUS_KEY);
	  lv_group_set_editing(g,false);
	  lv_group_focus_prev(g);
	  obj=lv_group_get_focused(g);
	  lv_obj_add_state(obj,LV_STATE_FOCUS_KEY);		
	}
		break;
	}
	default:
		break;
	}
}
static void MainScreen_btnDummySettingsClock_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_FOCUSED:
	{
		extern int MainScreen_digital_clockHeader_hour_value;
	extern int MainScreen_digital_clockHeader_min_value;
	extern int MainScreen_digital_clockHeader_sec_value;
	extern char MainScreen_digital_clockHeader_meridiem[];
	lv_ui *ui=(lv_ui *)lv_event_get_user_data(e);
	MainScreen_digital_clockHeader_hour_value=lv_spinbox_get_value(ui->MainScreen_spinboxSettingsClockHour);
	MainScreen_digital_clockHeader_min_value=lv_spinbox_get_value(ui->MainScreen_spinboxSettingsClockMinute);    
	MainScreen_digital_clockHeader_sec_value=lv_spinbox_get_value(ui->MainScreen_spinboxSettingsClockSecond);  
	if(MainScreen_digital_clockHeader_hour_value>=12)
	{
	  lv_snprintf(MainScreen_digital_clockHeader_meridiem,3,"PM");
	  if(MainScreen_digital_clockHeader_hour_value>12)
	    MainScreen_digital_clockHeader_hour_value-=12;
	}
	else
	{
	  lv_snprintf(MainScreen_digital_clockHeader_meridiem,3,"AM");
	}
	ui_move_animation(ui->MainScreen_contSettingsClock,300,0,800,80,&lv_anim_path_linear,0,0,0,0,NULL,NULL,animcontSettingsClock_del_callback);
		break;
	}
	default:
		break;
	}
}
static void MainScreen_btnGoSettingsCalender_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_ui *ui=(lv_ui *)lv_event_get_user_data(e);
	lv_group_t *g=lv_group_get_default();
	uint8_t id=lv_obj_get_child_id(lv_group_get_focused(g));
	  
	printf("@Setting Calender id=%d\n",id);
	if(lv_obj_has_state(ui->MainScreen_datetextSettingsCalender,LV_STATE_FOCUS_KEY))
	{
	  ui_move_animation(ui->MainScreen_contSettingsCalender,300,0,800,80,&lv_anim_path_linear,0,0,0,0,NULL,NULL,animcontSettingsCalender_del_callback);
	}
	else
	{
	  lv_obj_t *obj=lv_group_get_focused(g);
	  lv_obj_clear_state(obj,LV_STATE_FOCUS_KEY);
	  lv_group_set_editing(g,false);
	  lv_group_focus_prev(g);
	  obj=lv_group_get_focused(g);
	  lv_obj_add_state(obj,LV_STATE_FOCUS_KEY);		
	}
		break;
	}
	default:
		break;
	}
}
static void MainScreen_btnDummySettingsCalender_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_FOCUSED:
	{
		
	lv_ui *ui=(lv_ui *)lv_event_get_user_data(e);

	lv_label_set_text(ui->MainScreen_datetextHeader, lv_label_get_text(ui->MainScreen_datetextSettingsCalender));  
	ui_move_animation(ui->MainScreen_contSettingsCalender,300,0,800,80,&lv_anim_path_linear,0,0,0,0,NULL,NULL,animcontSettingsCalender_del_callback);
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
	lv_obj_add_event_cb(ui->MainScreen_btnMenuSyringe, MainScreen_btnMenuSyringe_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_btnMenuDrug, MainScreen_btnMenuDrug_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_btnMenuMode, MainScreen_btnMenuMode_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_btnMenuOCC, MainScreen_btnMenuOCC_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_btnMenuKVO, MainScreen_btnMenuKVO_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_btnMenuIntInf, MainScreen_btnMenuIntInf_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_btnMenuNurseCall, MainScreen_btnMenuNurseCall_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_btnMenuBolus, MainScreen_btnMenuBolus_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_btnMenuPurge, MainScreen_btnMenuPurge_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_btnMenuSetting, MainScreen_btnMenuSetting_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_btnGoMainMenu, MainScreen_btnGoMainMenu_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_btnGoMenuSyringe, MainScreen_btnGoMenuSyringe_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_listSyringeCompany, MainScreen_listSyringeCompany_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_listSyringeType, MainScreen_listSyringeType_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_taSyringeNameValue, MainScreen_taSyringeNameValue_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_spinboxSyringeVolume, MainScreen_spinboxSyringeVolume_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_spinboxSyringeInnerDia, MainScreen_spinboxSyringeInnerDia_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_spinboxSyringeOuterDia, MainScreen_spinboxSyringeOuterDia_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_spinboxSyringeBarrelLen, MainScreen_spinboxSyringeBarrelLen_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_spinboxSyringePlungerLen, MainScreen_spinboxSyringePlungerLen_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_spinboxSyringeDiaTolerance, MainScreen_spinboxSyringeDiaTolerance_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_btnDummySyringe, MainScreen_btnDummySyringe_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_btnGoMenuDrug, MainScreen_btnGoMenuDrug_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_listDrugBrand, MainScreen_listDrugBrand_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_taDrugNameValue, MainScreen_taDrugNameValue_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_taDrugBrandValue, MainScreen_taDrugBrandValue_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb((ui->MainScreen_ddlistDrugId), MainScreen_ddlistDrugId_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_spinboxDrugmgml, MainScreen_spinboxDrugmgml_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_spinboxDruguml, MainScreen_spinboxDruguml_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_spinboxDrugperkg, MainScreen_spinboxDrugperkg_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_spinboxDrugRateMin, MainScreen_spinboxDrugRateMin_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_spinboxDrugRateMax, MainScreen_spinboxDrugRateMax_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_spinboxDrugRateDef, MainScreen_spinboxDrugRateDef_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_btnDummyDrug, MainScreen_btnDummyDrug_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_btnGoMenuMode, MainScreen_btnGoMenuMode_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_listModeMode, MainScreen_listModeMode_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_listModeUnit, MainScreen_listModeUnit_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_spinboxModeBodyWeight, MainScreen_spinboxModeBodyWeight_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_spinboxModeInfusionRate, MainScreen_spinboxModeInfusionRate_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_spinboxModeTotalTimeHour, MainScreen_spinboxModeTotalTimeHour_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_spinboxModeTotalTimeMinute, MainScreen_spinboxModeTotalTimeMinute_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_spinboxModeTotalTimeSecond, MainScreen_spinboxModeTotalTimeSecond_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_spinboxModeTotalVolume, MainScreen_spinboxModeTotalVolume_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_btnDummyMode, MainScreen_btnDummyMode_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_btnGoMenuOcclusion, MainScreen_btnGoMenuOcclusion_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_sliderOcclusionOcc, MainScreen_sliderOcclusionOcc_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_swKVOMode, MainScreen_swKVOMode_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_btnGoMenuKVO, MainScreen_btnGoMenuKVO_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_btnDummyKVO, MainScreen_btnDummyKVO_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_btnGOMenuIntermittent, MainScreen_btnGOMenuIntermittent_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_btnDummyIntermittent, MainScreen_btnDummyIntermittent_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_swNurseCall, MainScreen_swNurseCall_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_btnGoMenuNurseCall, MainScreen_btnGoMenuNurseCall_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_btnDummyNurseCall, MainScreen_btnDummyNurseCall_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_btnGoMenuBolus, MainScreen_btnGoMenuBolus_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_btnDummyBolus, MainScreen_btnDummyBolus_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_btnGoMenuPurge, MainScreen_btnGoMenuPurge_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_btnDummyPurge, MainScreen_btnDummyPurge_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_btnSettingsClock, MainScreen_btnSettingsClock_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_btnSettingsCalender, MainScreen_btnSettingsCalender_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_btnGoMenuSettings, MainScreen_btnGoMenuSettings_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_btnGoSettingsClock, MainScreen_btnGoSettingsClock_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_btnDummySettingsClock, MainScreen_btnDummySettingsClock_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_btnGoSettingsCalender, MainScreen_btnGoSettingsCalender_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->MainScreen_btnDummySettingsCalender, MainScreen_btnDummySettingsCalender_event_handler, LV_EVENT_ALL, ui);

	for (int i = 0; i < lv_obj_get_child_cnt(ui->MainScreen_listSyringeCompany); i++)
		lv_obj_add_event_cb(lv_obj_get_child(ui->MainScreen_listSyringeCompany, i), MainScreen_listSyringeCompany_event_handler, LV_EVENT_ALL, ui);
	for (int i = 0; i < lv_obj_get_child_cnt(ui->MainScreen_listSyringeType); i++)
		lv_obj_add_event_cb(lv_obj_get_child(ui->MainScreen_listSyringeType, i), MainScreen_listSyringeType_event_handler, LV_EVENT_ALL, ui);
	for (int i = 0; i < lv_obj_get_child_cnt(ui->MainScreen_listDrugBrand); i++)
		lv_obj_add_event_cb(lv_obj_get_child(ui->MainScreen_listDrugBrand, i), MainScreen_listDrugBrand_event_handler, LV_EVENT_ALL, ui);
	for (int i = 0; i < lv_obj_get_child_cnt(ui->MainScreen_listModeMode); i++)
		lv_obj_add_event_cb(lv_obj_get_child(ui->MainScreen_listModeMode, i), MainScreen_listModeMode_event_handler, LV_EVENT_ALL, ui);
	for (int i = 0; i < lv_obj_get_child_cnt(ui->MainScreen_listModeUnit); i++)
		lv_obj_add_event_cb(lv_obj_get_child(ui->MainScreen_listModeUnit, i), MainScreen_listModeUnit_event_handler, LV_EVENT_ALL, ui);
}

void events_init(lv_ui *ui)
{
}
