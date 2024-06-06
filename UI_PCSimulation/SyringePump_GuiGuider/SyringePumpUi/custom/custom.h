/*
* Copyright 2023 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef __CUSTOM_H_
#define __CUSTOM_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "gui_guider.h"

void custom_init(lv_ui *ui);
void LoadDefaults();
void MainScreenSetStyle(lv_ui *ui);

void setcontSettingGroup(lv_ui *ui);
void setcontMainGroup(lv_ui *ui);
void setcontSyringeGroup(lv_ui *ui);
void setcontSyringeValuesGroup(lv_ui *ui);
void setlistSyringeCompanyGroup(lv_ui *ui);
void setlistSyringeTypeGroup(lv_ui *ui);

void loadSyringeCompanyList(lv_ui *ui);
void loadSyringeTypeList(lv_ui *ui,uint8_t companyindex);
void loadSyringeValues(lv_ui *ui,uint8_t Typeindex);

void animcontMain_ready_callback(lv_anim_t * a);
void animcontSetting_ready_callback(lv_anim_t * a);
void animcontSyringe_ready_callback(lv_anim_t * a);

#ifdef __cplusplus
}
#endif
#endif /* EVENT_CB_H_ */
