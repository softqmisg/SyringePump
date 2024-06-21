/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef WIDGET_INIT_H
#define WIDGET_INIT_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"
#include "gui_guider.h"

__attribute__((unused)) void kb_event_cb(lv_event_t *e);
__attribute__((unused)) void ta_event_cb(lv_event_t *e);
#if LV_USE_ANALOGCLOCK != 0
void clock_count(int *hour, int *min, int *sec);
#endif


void MainScreen_digital_clock_timer(lv_timer_t *timer);
void MainScreen_datetext_event_handler(lv_event_t *e);
void MainScreen_datetext_calendar_event_handler(lv_event_t *e);
void MainScreen_datetext_init_calendar(lv_obj_t *obj, char * s);extern lv_obj_t * MainScreen_spinboxSyringeVolume;
void lv_MainScreen_spinboxSyringeVolume_increment_event_cb(lv_event_t * event);
void lv_MainScreen_spinboxSyringeVolume_decrement_event_cb(lv_event_t * event);
extern lv_obj_t * MainScreen_spinboxSyringeInnerDia;
void lv_MainScreen_spinboxSyringeInnerDia_increment_event_cb(lv_event_t * event);
void lv_MainScreen_spinboxSyringeInnerDia_decrement_event_cb(lv_event_t * event);
extern lv_obj_t * MainScreen_spinboxSyringeOuterDia;
void lv_MainScreen_spinboxSyringeOuterDia_increment_event_cb(lv_event_t * event);
void lv_MainScreen_spinboxSyringeOuterDia_decrement_event_cb(lv_event_t * event);
extern lv_obj_t * MainScreen_spinboxSyringeBarrelLen;
void lv_MainScreen_spinboxSyringeBarrelLen_increment_event_cb(lv_event_t * event);
void lv_MainScreen_spinboxSyringeBarrelLen_decrement_event_cb(lv_event_t * event);
extern lv_obj_t * MainScreen_spinboxSyringePlungerLen;
void lv_MainScreen_spinboxSyringePlungerLen_increment_event_cb(lv_event_t * event);
void lv_MainScreen_spinboxSyringePlungerLen_decrement_event_cb(lv_event_t * event);
extern lv_obj_t * MainScreen_spinboxSyringeDiaTolerance;
void lv_MainScreen_spinboxSyringeDiaTolerance_increment_event_cb(lv_event_t * event);
void lv_MainScreen_spinboxSyringeDiaTolerance_decrement_event_cb(lv_event_t * event);
extern lv_obj_t * MainScreen_spinboxDrugmgml;
void lv_MainScreen_spinboxDrugmgml_increment_event_cb(lv_event_t * event);
void lv_MainScreen_spinboxDrugmgml_decrement_event_cb(lv_event_t * event);
extern lv_obj_t * MainScreen_spinboxDruguml;
void lv_MainScreen_spinboxDruguml_increment_event_cb(lv_event_t * event);
void lv_MainScreen_spinboxDruguml_decrement_event_cb(lv_event_t * event);
extern lv_obj_t * MainScreen_spinboxDrugperkg;
void lv_MainScreen_spinboxDrugperkg_increment_event_cb(lv_event_t * event);
void lv_MainScreen_spinboxDrugperkg_decrement_event_cb(lv_event_t * event);
extern lv_obj_t * MainScreen_spinboxDrugRateMin;
void lv_MainScreen_spinboxDrugRateMin_increment_event_cb(lv_event_t * event);
void lv_MainScreen_spinboxDrugRateMin_decrement_event_cb(lv_event_t * event);
extern lv_obj_t * MainScreen_spinboxDrugRateMax;
void lv_MainScreen_spinboxDrugRateMax_increment_event_cb(lv_event_t * event);
void lv_MainScreen_spinboxDrugRateMax_decrement_event_cb(lv_event_t * event);
extern lv_obj_t * MainScreen_spinboxDrugRateDef;
void lv_MainScreen_spinboxDrugRateDef_increment_event_cb(lv_event_t * event);
void lv_MainScreen_spinboxDrugRateDef_decrement_event_cb(lv_event_t * event);
extern lv_obj_t * MainScreen_spinboxModeBodyWeight;
void lv_MainScreen_spinboxModeBodyWeight_increment_event_cb(lv_event_t * event);
void lv_MainScreen_spinboxModeBodyWeight_decrement_event_cb(lv_event_t * event);
extern lv_obj_t * MainScreen_spinboxModeInfusionRate;
void lv_MainScreen_spinboxModeInfusionRate_increment_event_cb(lv_event_t * event);
void lv_MainScreen_spinboxModeInfusionRate_decrement_event_cb(lv_event_t * event);
extern lv_obj_t * MainScreen_spinboxModeTotalTimeHour;
void lv_MainScreen_spinboxModeTotalTimeHour_increment_event_cb(lv_event_t * event);
void lv_MainScreen_spinboxModeTotalTimeHour_decrement_event_cb(lv_event_t * event);
extern lv_obj_t * MainScreen_spinboxModeTotalTimeMinute;
void lv_MainScreen_spinboxModeTotalTimeMinute_increment_event_cb(lv_event_t * event);
void lv_MainScreen_spinboxModeTotalTimeMinute_decrement_event_cb(lv_event_t * event);
extern lv_obj_t * MainScreen_spinboxModeTotalTimeSecond;
void lv_MainScreen_spinboxModeTotalTimeSecond_increment_event_cb(lv_event_t * event);
void lv_MainScreen_spinboxModeTotalTimeSecond_decrement_event_cb(lv_event_t * event);
extern lv_obj_t * MainScreen_spinboxModeTotalVolume;
void lv_MainScreen_spinboxModeTotalVolume_increment_event_cb(lv_event_t * event);
void lv_MainScreen_spinboxModeTotalVolume_decrement_event_cb(lv_event_t * event);
extern lv_obj_t * MainScreen_spinboxKVORate;
void lv_MainScreen_spinboxKVORate_increment_event_cb(lv_event_t * event);
void lv_MainScreen_spinboxKVORate_decrement_event_cb(lv_event_t * event);
extern lv_obj_t * MainScreen_spinboxIntermittentInfusionRate;
void lv_MainScreen_spinboxIntermittentInfusionRate_increment_event_cb(lv_event_t * event);
void lv_MainScreen_spinboxIntermittentInfusionRate_decrement_event_cb(lv_event_t * event);
extern lv_obj_t * MainScreen_spinboxIntermittentDurationHour;
void lv_MainScreen_spinboxIntermittentDurationHour_increment_event_cb(lv_event_t * event);
void lv_MainScreen_spinboxIntermittentDurationHour_decrement_event_cb(lv_event_t * event);
extern lv_obj_t * MainScreen_spinboxIntermittentDurationMinute;
void lv_MainScreen_spinboxIntermittentDurationMinute_increment_event_cb(lv_event_t * event);
void lv_MainScreen_spinboxIntermittentDurationMinute_decrement_event_cb(lv_event_t * event);
extern lv_obj_t * MainScreen_spinboxIntermittentDurationSecond;
void lv_MainScreen_spinboxIntermittentDurationSecond_increment_event_cb(lv_event_t * event);
void lv_MainScreen_spinboxIntermittentDurationSecond_decrement_event_cb(lv_event_t * event);
extern lv_obj_t * MainScreen_spinboxIntermittentBackgroundRate;
void lv_MainScreen_spinboxIntermittentBackgroundRate_increment_event_cb(lv_event_t * event);
void lv_MainScreen_spinboxIntermittentBackgroundRate_decrement_event_cb(lv_event_t * event);
extern lv_obj_t * MainScreen_spinboxIntermittentSleepHour;
void lv_MainScreen_spinboxIntermittentSleepHour_increment_event_cb(lv_event_t * event);
void lv_MainScreen_spinboxIntermittentSleepHour_decrement_event_cb(lv_event_t * event);
extern lv_obj_t * MainScreen_spinboxIntermittentSleepMinute;
void lv_MainScreen_spinboxIntermittentSleepMinute_increment_event_cb(lv_event_t * event);
void lv_MainScreen_spinboxIntermittentSleepMinute_decrement_event_cb(lv_event_t * event);
extern lv_obj_t * MainScreen_spinboxIntermittentSleepSecond;
void lv_MainScreen_spinboxIntermittentSleepSecond_increment_event_cb(lv_event_t * event);
void lv_MainScreen_spinboxIntermittentSleepSecond_decrement_event_cb(lv_event_t * event);


#ifdef __cplusplus
}
#endif
#endif
