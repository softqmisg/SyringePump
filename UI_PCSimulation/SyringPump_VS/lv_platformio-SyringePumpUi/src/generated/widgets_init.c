/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include "gui_guider.h"
#include "widgets_init.h"
#include <stdlib.h>
char cur_textofarea[25];

__attribute__((unused)) void kb_event_cb (lv_event_t *e) {
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *kb = lv_event_get_target(e);
	lv_obj_t *ta=lv_keyboard_get_textarea(kb);

	if(code==LV_EVENT_VALUE_CHANGED)
	{
		lv_textarea_set_text(guider_ui.MainScreen_ta_keybard,lv_textarea_get_text(ta));

	}
    if( code == LV_EVENT_CANCEL)
	{
		lv_textarea_set_text(ta,cur_textofarea);
    }
}

__attribute__((unused)) void ta_event_cb (lv_event_t *e) {
    lv_event_code_t code = lv_event_get_code(e);

#if LV_USE_KEYBOARD || LV_USE_ZH_KEYBOARD
    lv_obj_t *ta = lv_event_get_target(e);
#endif
    lv_obj_t *kb = lv_event_get_user_data(e);
	if( code == LV_EVENT_VALUE_CHANGED)
	{
	}
    if ( code == LV_EVENT_CLICKED)
    {
#if LV_USE_ZH_KEYBOARD != 0
        // lv_zh_keyboard_set_textarea(kb, ta);
#endif
#if LV_USE_KEYBOARD != 0
        lv_keyboard_set_textarea(kb, ta);
#endif
		lv_snprintf(cur_textofarea,20,"%s",lv_textarea_get_text(ta));
		lv_textarea_set_text(guider_ui.MainScreen_ta_keybard,cur_textofarea);
        lv_obj_move_foreground(guider_ui.MainScreen_ta_keybard);
        lv_obj_clear_flag(guider_ui.MainScreen_ta_keybard, LV_OBJ_FLAG_HIDDEN);

        lv_obj_move_foreground(kb);
        lv_obj_clear_flag(kb, LV_OBJ_FLAG_HIDDEN);
        lv_group_focus_obj(kb);
        lv_group_set_editing(lv_obj_get_group(kb), true);
    }

    if (code == LV_EVENT_CANCEL || code == LV_EVENT_READY)
    {

#if LV_USE_ZH_KEYBOARD != 0
        // lv_zh_keyboard_set_textarea(kb, ta);
#endif
#if LV_USE_KEYBOARD != 0
        lv_keyboard_set_textarea(kb, ta);
#endif
        lv_group_set_editing(lv_obj_get_group(kb), false);
        lv_obj_move_background(guider_ui.MainScreen_ta_keybard);
        lv_obj_add_flag(guider_ui.MainScreen_ta_keybard, LV_OBJ_FLAG_HIDDEN);
        lv_obj_move_background(kb);
        lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
       if(code == LV_EVENT_READY)
	   {
			lv_obj_clear_state(ta,LV_STATE_EDITED);
	   }
		lv_group_focus_obj(ta);

    }
}

#if LV_USE_ANALOGCLOCK != 0
void clock_count(int *hour, int *min, int *sec)
{
    (*sec)++;
    if(*sec == 60)
    {
        *sec = 0;
        (*min)++;
    }
    if(*min == 60)
    {
        *min = 0;
        if(*hour < 12)
        {
            (*hour)++;
        } else {
            (*hour)++;
            *hour = *hour %12;
        }
    }
}
#endif


extern int MainScreen_digital_clockHeader_hour_value;
extern int MainScreen_digital_clockHeader_min_value;
extern int MainScreen_digital_clockHeader_sec_value;
extern char MainScreen_digital_clockHeader_meridiem[];

void MainScreen_digital_clockHeader_timer(lv_timer_t *timer)
{
    clock_count_12(&MainScreen_digital_clockHeader_hour_value, &MainScreen_digital_clockHeader_min_value, &MainScreen_digital_clockHeader_sec_value, MainScreen_digital_clockHeader_meridiem);
    if (lv_obj_is_valid(guider_ui.MainScreen_digital_clockHeader))
    {
        lv_dclock_set_text_fmt(guider_ui.MainScreen_digital_clockHeader, "%d:%02d:%02d %s", MainScreen_digital_clockHeader_hour_value, MainScreen_digital_clockHeader_min_value, MainScreen_digital_clockHeader_sec_value, MainScreen_digital_clockHeader_meridiem);
    }
}
static lv_obj_t * MainScreen_datetextHeader_calendar;

void MainScreen_datetextHeader_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t * btn = lv_event_get_target(e);
	if(code == LV_EVENT_FOCUSED){
		char * s = lv_label_get_text(btn);
		if(MainScreen_datetextHeader_calendar == NULL){
			MainScreen_datetextHeader_init_calendar(btn, s);
		}
	}
}

void MainScreen_datetextHeader_init_calendar(lv_obj_t *obj, char * s)
{
	if (MainScreen_datetextHeader_calendar == NULL){
		lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
		MainScreen_datetextHeader_calendar = lv_calendar_create(lv_layer_top());
		lv_obj_t * scr = lv_obj_get_screen(obj);
		lv_coord_t scr_height = lv_obj_get_height(scr);
		lv_coord_t scr_width = lv_obj_get_width(scr);
		lv_obj_set_size(MainScreen_datetextHeader_calendar, scr_width * 0.8, scr_height * 0.8);
		char * year = strtok(s, "/");
		char * month = strtok(NULL, "/");
		char * day = strtok(NULL, "/");
		lv_calendar_set_showed_date(MainScreen_datetextHeader_calendar, atoi(year), atoi(month));
		lv_calendar_date_t highlighted_days[1];       /*Only its pointer will be saved so should be static*/
		highlighted_days[0].year = atoi(year);
		highlighted_days[0].month = atoi(month);
		highlighted_days[0].day = atoi(day);
		lv_calendar_set_highlighted_dates(MainScreen_datetextHeader_calendar, highlighted_days, 1);
		lv_obj_align(MainScreen_datetextHeader_calendar,LV_ALIGN_CENTER, 0, 0);
 
		lv_obj_add_event_cb(MainScreen_datetextHeader_calendar, MainScreen_datetextHeader_calendar_event_handler, LV_EVENT_ALL,NULL);
		lv_calendar_header_arrow_create(MainScreen_datetextHeader_calendar);
		lv_obj_update_layout(scr);
	}
}

void MainScreen_datetextHeader_calendar_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t * obj = lv_event_get_current_target(e);
 
	if (code == LV_EVENT_VALUE_CHANGED){
		lv_calendar_date_t date;
		lv_calendar_get_pressed_date(obj,&date);
		char buf[16];
		lv_snprintf(buf,sizeof(buf),"%d/%02d/%02d", date.year, date.month ,date.day);
		lv_label_set_text(guider_ui.MainScreen_datetextHeader, buf);
		lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
		lv_obj_set_style_bg_opa(lv_layer_top(), LV_OPA_TRANSP, 0);
		lv_obj_del(MainScreen_datetextHeader_calendar);
		MainScreen_datetextHeader_calendar = NULL;
	}
}

void lv_MainScreen_spinboxSyringeVolume_increment_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_increment(guider_ui.MainScreen_spinboxSyringeVolume);
	}
}
void lv_MainScreen_spinboxSyringeVolume_decrement_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_decrement(guider_ui.MainScreen_spinboxSyringeVolume);
	}
}
void lv_MainScreen_spinboxSyringeInnerDia_increment_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_increment(guider_ui.MainScreen_spinboxSyringeInnerDia);
	}
}
void lv_MainScreen_spinboxSyringeInnerDia_decrement_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_decrement(guider_ui.MainScreen_spinboxSyringeInnerDia);
	}
}
void lv_MainScreen_spinboxSyringeOuterDia_increment_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_increment(guider_ui.MainScreen_spinboxSyringeOuterDia);
	}
}
void lv_MainScreen_spinboxSyringeOuterDia_decrement_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_decrement(guider_ui.MainScreen_spinboxSyringeOuterDia);
	}
}
void lv_MainScreen_spinboxSyringeBarrelLen_increment_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_increment(guider_ui.MainScreen_spinboxSyringeBarrelLen);
	}
}
void lv_MainScreen_spinboxSyringeBarrelLen_decrement_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_decrement(guider_ui.MainScreen_spinboxSyringeBarrelLen);
	}
}
void lv_MainScreen_spinboxSyringePlungerLen_increment_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_increment(guider_ui.MainScreen_spinboxSyringePlungerLen);
	}
}
void lv_MainScreen_spinboxSyringePlungerLen_decrement_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_decrement(guider_ui.MainScreen_spinboxSyringePlungerLen);
	}
}
void lv_MainScreen_spinboxSyringeDiaTolerance_increment_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_increment(guider_ui.MainScreen_spinboxSyringeDiaTolerance);
	}
}
void lv_MainScreen_spinboxSyringeDiaTolerance_decrement_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_decrement(guider_ui.MainScreen_spinboxSyringeDiaTolerance);
	}
}
void lv_MainScreen_spinboxDrugmgml_increment_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_increment(guider_ui.MainScreen_spinboxDrugmgml);
	}
}
void lv_MainScreen_spinboxDrugmgml_decrement_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_decrement(guider_ui.MainScreen_spinboxDrugmgml);
	}
}
void lv_MainScreen_spinboxDruguml_increment_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_increment(guider_ui.MainScreen_spinboxDruguml);
	}
}
void lv_MainScreen_spinboxDruguml_decrement_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_decrement(guider_ui.MainScreen_spinboxDruguml);
	}
}
void lv_MainScreen_spinboxDrugperkg_increment_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_increment(guider_ui.MainScreen_spinboxDrugperkg);
	}
}
void lv_MainScreen_spinboxDrugperkg_decrement_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_decrement(guider_ui.MainScreen_spinboxDrugperkg);
	}
}
void lv_MainScreen_spinboxDrugRateMin_increment_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_increment(guider_ui.MainScreen_spinboxDrugRateMin);
	}
}
void lv_MainScreen_spinboxDrugRateMin_decrement_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_decrement(guider_ui.MainScreen_spinboxDrugRateMin);
	}
}
void lv_MainScreen_spinboxDrugRateMax_increment_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_increment(guider_ui.MainScreen_spinboxDrugRateMax);
	}
}
void lv_MainScreen_spinboxDrugRateMax_decrement_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_decrement(guider_ui.MainScreen_spinboxDrugRateMax);
	}
}
void lv_MainScreen_spinboxDrugRateDef_increment_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_increment(guider_ui.MainScreen_spinboxDrugRateDef);
	}
}
void lv_MainScreen_spinboxDrugRateDef_decrement_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_decrement(guider_ui.MainScreen_spinboxDrugRateDef);
	}
}
void lv_MainScreen_spinboxModeBodyWeight_increment_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_increment(guider_ui.MainScreen_spinboxModeBodyWeight);
	}
}
void lv_MainScreen_spinboxModeBodyWeight_decrement_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_decrement(guider_ui.MainScreen_spinboxModeBodyWeight);
	}
}
void lv_MainScreen_spinboxModeInfusionRate_increment_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_increment(guider_ui.MainScreen_spinboxModeInfusionRate);
	}
}
void lv_MainScreen_spinboxModeInfusionRate_decrement_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_decrement(guider_ui.MainScreen_spinboxModeInfusionRate);
	}
}
void lv_MainScreen_spinboxModeTotalTimeHour_increment_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_increment(guider_ui.MainScreen_spinboxModeTotalTimeHour);
	}
}
void lv_MainScreen_spinboxModeTotalTimeHour_decrement_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_decrement(guider_ui.MainScreen_spinboxModeTotalTimeHour);
	}
}
void lv_MainScreen_spinboxModeTotalTimeMinute_increment_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_increment(guider_ui.MainScreen_spinboxModeTotalTimeMinute);
	}
}
void lv_MainScreen_spinboxModeTotalTimeMinute_decrement_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_decrement(guider_ui.MainScreen_spinboxModeTotalTimeMinute);
	}
}
void lv_MainScreen_spinboxModeTotalTimeSecond_increment_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_increment(guider_ui.MainScreen_spinboxModeTotalTimeSecond);
	}
}
void lv_MainScreen_spinboxModeTotalTimeSecond_decrement_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_decrement(guider_ui.MainScreen_spinboxModeTotalTimeSecond);
	}
}
void lv_MainScreen_spinboxModeTotalVolume_increment_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_increment(guider_ui.MainScreen_spinboxModeTotalVolume);
	}
}
void lv_MainScreen_spinboxModeTotalVolume_decrement_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_decrement(guider_ui.MainScreen_spinboxModeTotalVolume);
	}
}
void lv_MainScreen_spinboxKVORate_increment_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_increment(guider_ui.MainScreen_spinboxKVORate);
	}
}
void lv_MainScreen_spinboxKVORate_decrement_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_decrement(guider_ui.MainScreen_spinboxKVORate);
	}
}
void lv_MainScreen_spinboxIntermittentInfusionRate_increment_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_increment(guider_ui.MainScreen_spinboxIntermittentInfusionRate);
	}
}
void lv_MainScreen_spinboxIntermittentInfusionRate_decrement_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_decrement(guider_ui.MainScreen_spinboxIntermittentInfusionRate);
	}
}
void lv_MainScreen_spinboxIntermittentDurationHour_increment_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_increment(guider_ui.MainScreen_spinboxIntermittentDurationHour);
	}
}
void lv_MainScreen_spinboxIntermittentDurationHour_decrement_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_decrement(guider_ui.MainScreen_spinboxIntermittentDurationHour);
	}
}
void lv_MainScreen_spinboxIntermittentDurationMinute_increment_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_increment(guider_ui.MainScreen_spinboxIntermittentDurationMinute);
	}
}
void lv_MainScreen_spinboxIntermittentDurationMinute_decrement_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_decrement(guider_ui.MainScreen_spinboxIntermittentDurationMinute);
	}
}
void lv_MainScreen_spinboxIntermittentDurationSecond_increment_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_increment(guider_ui.MainScreen_spinboxIntermittentDurationSecond);
	}
}
void lv_MainScreen_spinboxIntermittentDurationSecond_decrement_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_decrement(guider_ui.MainScreen_spinboxIntermittentDurationSecond);
	}
}
void lv_MainScreen_spinboxIntermittentBackgroundRate_increment_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_increment(guider_ui.MainScreen_spinboxIntermittentBackgroundRate);
	}
}
void lv_MainScreen_spinboxIntermittentBackgroundRate_decrement_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_decrement(guider_ui.MainScreen_spinboxIntermittentBackgroundRate);
	}
}
void lv_MainScreen_spinboxIntermittentSleepHour_increment_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_increment(guider_ui.MainScreen_spinboxIntermittentSleepHour);
	}
}
void lv_MainScreen_spinboxIntermittentSleepHour_decrement_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_decrement(guider_ui.MainScreen_spinboxIntermittentSleepHour);
	}
}
void lv_MainScreen_spinboxIntermittentSleepMinute_increment_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_increment(guider_ui.MainScreen_spinboxIntermittentSleepMinute);
	}
}
void lv_MainScreen_spinboxIntermittentSleepMinute_decrement_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_decrement(guider_ui.MainScreen_spinboxIntermittentSleepMinute);
	}
}
void lv_MainScreen_spinboxIntermittentSleepSecond_increment_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_increment(guider_ui.MainScreen_spinboxIntermittentSleepSecond);
	}
}
void lv_MainScreen_spinboxIntermittentSleepSecond_decrement_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_decrement(guider_ui.MainScreen_spinboxIntermittentSleepSecond);
	}
}
void lv_MainScreen_spinboxNurseCallDuration_increment_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_increment(guider_ui.MainScreen_spinboxNurseCallDuration);
	}
}
void lv_MainScreen_spinboxNurseCallDuration_decrement_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_decrement(guider_ui.MainScreen_spinboxNurseCallDuration);
	}
}
void lv_MainScreen_spinboxBolusRate_increment_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_increment(guider_ui.MainScreen_spinboxBolusRate);
	}
}
void lv_MainScreen_spinboxBolusRate_decrement_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_decrement(guider_ui.MainScreen_spinboxBolusRate);
	}
}
void lv_MainScreen_spinboxBolusMaxVolume_increment_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_increment(guider_ui.MainScreen_spinboxBolusMaxVolume);
	}
}
void lv_MainScreen_spinboxBolusMaxVolume_decrement_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_decrement(guider_ui.MainScreen_spinboxBolusMaxVolume);
	}
}
void lv_MainScreen_spinboxBolusIntervalHour_increment_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_increment(guider_ui.MainScreen_spinboxBolusIntervalHour);
	}
}
void lv_MainScreen_spinboxBolusIntervalHour_decrement_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_decrement(guider_ui.MainScreen_spinboxBolusIntervalHour);
	}
}
void lv_MainScreen_spinboxBolusIntervalMinute_increment_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_increment(guider_ui.MainScreen_spinboxBolusIntervalMinute);
	}
}
void lv_MainScreen_spinboxBolusIntervalMinute_decrement_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_decrement(guider_ui.MainScreen_spinboxBolusIntervalMinute);
	}
}
void lv_MainScreen_spinboxBolusIntervalSecond_increment_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_increment(guider_ui.MainScreen_spinboxBolusIntervalSecond);
	}
}
void lv_MainScreen_spinboxBolusIntervalSecond_decrement_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_decrement(guider_ui.MainScreen_spinboxBolusIntervalSecond);
	}
}
void lv_MainScreen_spinboxPurgeRate_increment_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_increment(guider_ui.MainScreen_spinboxPurgeRate);
	}
}
void lv_MainScreen_spinboxPurgeRate_decrement_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_decrement(guider_ui.MainScreen_spinboxPurgeRate);
	}
}
void lv_MainScreen_spinboxPurgeMaxVolume_increment_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_increment(guider_ui.MainScreen_spinboxPurgeMaxVolume);
	}
}
void lv_MainScreen_spinboxPurgeMaxVolume_decrement_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_decrement(guider_ui.MainScreen_spinboxPurgeMaxVolume);
	}
}
void lv_MainScreen_spinboxPurgeIntervalHour_increment_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_increment(guider_ui.MainScreen_spinboxPurgeIntervalHour);
	}
}
void lv_MainScreen_spinboxPurgeIntervalHour_decrement_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_decrement(guider_ui.MainScreen_spinboxPurgeIntervalHour);
	}
}
void lv_MainScreen_spinboxPurgeIntervalMinute_increment_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_increment(guider_ui.MainScreen_spinboxPurgeIntervalMinute);
	}
}
void lv_MainScreen_spinboxPurgeIntervalMinute_decrement_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_decrement(guider_ui.MainScreen_spinboxPurgeIntervalMinute);
	}
}
void lv_MainScreen_spinboxPurgeIntervalSecond_increment_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_increment(guider_ui.MainScreen_spinboxPurgeIntervalSecond);
	}
}
void lv_MainScreen_spinboxPurgeIntervalSecond_decrement_event_cb(lv_event_t * event)
{
	lv_event_code_t code = lv_event_get_code(event);
	if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT){
	  lv_spinbox_decrement(guider_ui.MainScreen_spinboxPurgeIntervalSecond);
	}
}

