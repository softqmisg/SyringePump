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

void setcontMainGroup(lv_ui *ui);
void setcontMenuGroup(lv_ui *ui);
void setlistSyringeCompanyGroup(lv_ui *ui);
void setlistSyringeTypeGroup(lv_ui *ui);
void setcontSyringeValuesGroup(lv_ui *ui);
void setlistDrugBrandGroup(lv_ui  *ui);
void setcontDrugValuesGroup(lv_ui  *ui);
void setlistModeModeGroup(lv_ui *ui);
void setlistModeUnitGroup(lv_ui *ui);
void setcontModeValuesGroup(lv_ui *ui);
void setbarOcclusionOccGroup(lv_ui *ui);
void setKVOModeGroup(lv_ui *ui);
void setIntermittentGroup(lv_ui *ui);
void setRhythmicGroup(lv_ui *ui);
void setNurseCallGroup(lv_ui *ui);
void setBolusGroup(lv_ui *ui);
void setPurgeGroup(lv_ui *ui);
void setSettingsGroup(lv_ui *ui);

void updateMain(lv_ui *ui);
void updateSyringeCompanyList(lv_ui *ui);
void updateSyringeTypeList(lv_ui *ui,uint8_t companyindex);
void updateSyringeValues(lv_ui *ui,uint8_t Manufactureindex,uint8_t Typeindex);
void updateDrugList(lv_ui *ui);
void updateDrugValues(lv_ui *ui,uint8_t drugindex);
void updateModeModeList(lv_ui *ui);
void updateModeUnitList(lv_ui *ui,uint8_t modeindex);
void updateModeValues(lv_ui *ui,uint8_t modeindex,uint8_t unitindex);
void updateOcclusionValues(lv_ui *ui);
void updateKVOModeValues(lv_ui *ui);
void updateIntermittentValues(lv_ui *ui);
void updateRhythmicValues(lv_ui *ui);
void updateNurseCallValues(lv_ui *ui);
void updateBoluseValues(lv_ui *ui);
void updatePurgeValues(lv_ui *ui);
void updateSettingsValues(lv_ui *ui);

void animcontMain_ready_callback(lv_anim_t * a);
void animcontMenu_ready_callback(lv_anim_t * a);
void animcontSyringe_ready_callback(lv_anim_t * a);
void animcontDrug_ready_callback(lv_anim_t * a);
void animcontMode_ready_callback(lv_anim_t * a);
void animcontOcclusion_ready_callback(lv_anim_t *a);
void animcontKVO_ready_callback(lv_anim_t *a);
void animcontIntermittent_ready_callback(lv_anim_t *a);
void animcontRhythmic_ready_callback(lv_anim_t *a);
void animcontNurseCall_ready_callback(lv_anim_t *a);
void animcontBolus_ready_callback(lv_anim_t *a);
void animcontPurge_ready_callback(lv_anim_t *a);
void animcontSettings_ready_callback(lv_anim_t *a);
void animcontSettingsClock_ready_callback(lv_anim_t *a);

void animcontSyringe_del_callback(lv_anim_t * a);
void animcontDrug_del_callback(lv_anim_t * a);
void animcontMode_del_callback(lv_anim_t * a);
void animcontOcclusion_del_callback(lv_anim_t *a);
void animcontKVO_del_callback(lv_anim_t *a);
void animcontIntermittent_del_callback(lv_anim_t *a);
void animcontRhythmic_del_callback(lv_anim_t *a);
void animcontNurseCall_del_callback(lv_anim_t *a);
void animcontBolus_del_callback(lv_anim_t *a);
void animcontPurge_del_callback(lv_anim_t *a);
void animcontSettings_del_callback(lv_anim_t *a);
void animcontSettingsClock_del_callback(lv_anim_t *a);
#ifdef __cplusplus
}
#endif
#endif /* EVENT_CB_H_ */
