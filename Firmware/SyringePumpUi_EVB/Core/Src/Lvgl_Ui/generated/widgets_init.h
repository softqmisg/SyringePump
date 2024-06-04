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


#ifdef __cplusplus
}
#endif
#endif
