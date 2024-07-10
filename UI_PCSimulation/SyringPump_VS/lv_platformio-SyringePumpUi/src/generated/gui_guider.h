/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *LogoScreen;
	bool LogoScreen_del;
	lv_obj_t *g_kb_LogoScreen;
	lv_obj_t *LogoScreen_img_1;
	lv_obj_t *MainScreen;
	bool MainScreen_del;
	lv_obj_t *g_kb_MainScreen;
	lv_obj_t *MainScreen_contHeader;
	lv_obj_t *MainScreen_digital_clockHeader;
	lv_obj_t *MainScreen_datetextHeader;
	lv_obj_t *MainScreen_labelHeaderAlarmNut;
	lv_obj_t *MainScreen_labelHeaderAlarmPlunger;
	lv_obj_t *MainScreen_imgHeaderNetwork;
	lv_obj_t *MainScreen_imgHeaderSerialPort;
	lv_obj_t *MainScreen_imgHeaderUsbPort;
	lv_obj_t *MainScreen_barHeaderBatteryLevel;
	lv_obj_t *MainScreen_contFooter;
	lv_obj_t *MainScreen_imgFooterSyringe;
	lv_obj_t *MainScreen_labelFooterDrug;
	lv_obj_t *MainScreen_labelFooterSyringe;
	lv_obj_t *MainScreen_labelFooterDiameter;
	lv_obj_t *MainScreen_barFooterSyringeLevel;
	lv_obj_t *MainScreen_labelFooterSyringeInfo;
	lv_obj_t *MainScreen_imgFooterForbidden;
	lv_obj_t *MainScreen_imgFooterDroplet;
	lv_obj_t *MainScreen_contMain;
	lv_obj_t *MainScreen_barMainOcclusionLevel;
	lv_obj_t *MainScreen_labelMainInjectionMode;
	lv_obj_t *MainScreen_labelMainInjectionRate;
	lv_obj_t *MainScreen_labelMainError;
	lv_obj_t *MainScreen_labelMainInjectedVolume;
	lv_obj_t *MainScreen_labelMainTimeLeft;
	lv_obj_t *MainScreen_labelMainRemVolume;
	lv_obj_t *MainScreen_labelMainPatientKg;
	lv_obj_t *MainScreen_labelMainTotalVolume;
	lv_obj_t *MainScreen_btnGoMenuMain;
	lv_obj_t *MainScreen_btnGoMenuMain_label;
	lv_obj_t *MainScreen_contMenu;
	lv_obj_t *MainScreen_contMenuButtons;
	lv_obj_t *MainScreen_label_7;
	lv_obj_t *MainScreen_label_9;
	lv_obj_t *MainScreen_label_10;
	lv_obj_t *MainScreen_label_11;
	lv_obj_t *MainScreen_label_12;
	lv_obj_t *MainScreen_label_13;
	lv_obj_t *MainScreen_label_8;
	lv_obj_t *MainScreen_label_14;
	lv_obj_t *MainScreen_label_15;
	lv_obj_t *MainScreen_label_16;
	lv_obj_t *MainScreen_label_17;
	lv_obj_t *MainScreen_btnMenuSyringe;
	lv_obj_t *MainScreen_btnMenuSyringe_label;
	lv_obj_t *MainScreen_btnMenuDrug;
	lv_obj_t *MainScreen_btnMenuDrug_label;
	lv_obj_t *MainScreen_btnMenuMode;
	lv_obj_t *MainScreen_btnMenuMode_label;
	lv_obj_t *MainScreen_btnMenuOCC;
	lv_obj_t *MainScreen_btnMenuOCC_label;
	lv_obj_t *MainScreen_btnMenuKVO;
	lv_obj_t *MainScreen_btnMenuKVO_label;
	lv_obj_t *MainScreen_btnMenuIntInf;
	lv_obj_t *MainScreen_btnMenuIntInf_label;
	lv_obj_t *MainScreen_btnMenuRhyInf;
	lv_obj_t *MainScreen_btnMenuRhyInf_label;
	lv_obj_t *MainScreen_btnMenuNurseCall;
	lv_obj_t *MainScreen_btnMenuNurseCall_label;
	lv_obj_t *MainScreen_btnMenuBolus;
	lv_obj_t *MainScreen_btnMenuBolus_label;
	lv_obj_t *MainScreen_btnMenuPurge;
	lv_obj_t *MainScreen_btnMenuPurge_label;
	lv_obj_t *MainScreen_btnMenuSetting;
	lv_obj_t *MainScreen_btnMenuSetting_label;
	lv_obj_t *MainScreen_btnGoMainMenu;
	lv_obj_t *MainScreen_btnGoMainMenu_label;
	lv_obj_t *MainScreen_contSyringe;
	lv_obj_t *MainScreen_btnGoMenuSyringe;
	lv_obj_t *MainScreen_btnGoMenuSyringe_label;
	lv_obj_t *MainScreen_listSyringeCompany;
	lv_obj_t *MainScreen_listSyringeCompany_item0;
	lv_obj_t *MainScreen_listSyringeCompany_item1;
	lv_obj_t *MainScreen_listSyringeCompany_item2;
	lv_obj_t *MainScreen_listSyringeCompany_item3;
	lv_obj_t *MainScreen_listSyringeCompany_item4;
	lv_obj_t *MainScreen_listSyringeCompany_item5;
	lv_obj_t *MainScreen_listSyringeCompany_item6;
	lv_obj_t *MainScreen_listSyringeCompany_item7;
	lv_obj_t *MainScreen_listSyringeCompany_item8;
	lv_obj_t *MainScreen_listSyringeCompany_item9;
	lv_obj_t *MainScreen_listSyringeCompany_item10;
	lv_obj_t *MainScreen_listSyringeCompany_item11;
	lv_obj_t *MainScreen_listSyringeCompany_item12;
	lv_obj_t *MainScreen_listSyringeCompany_item13;
	lv_obj_t *MainScreen_listSyringeCompany_item14;
	lv_obj_t *MainScreen_listSyringeCompany_item15;
	lv_obj_t *MainScreen_listSyringeCompany_item16;
	lv_obj_t *MainScreen_listSyringeCompany_item17;
	lv_obj_t *MainScreen_listSyringeCompany_item18;
	lv_obj_t *MainScreen_listSyringeCompany_item19;
	lv_obj_t *MainScreen_listSyringeCompany_item20;
	lv_obj_t *MainScreen_listSyringeCompany_item21;
	lv_obj_t *MainScreen_listSyringeCompany_item22;
	lv_obj_t *MainScreen_listSyringeCompany_item23;
	lv_obj_t *MainScreen_listSyringeCompany_item24;
	lv_obj_t *MainScreen_listSyringeCompany_item25;
	lv_obj_t *MainScreen_listSyringeCompany_item26;
	lv_obj_t *MainScreen_listSyringeCompany_item27;
	lv_obj_t *MainScreen_listSyringeCompany_item28;
	lv_obj_t *MainScreen_listSyringeCompany_item29;
	lv_obj_t *MainScreen_listSyringeCompany_item30;
	lv_obj_t *MainScreen_listSyringeCompany_item31;
	lv_obj_t *MainScreen_listSyringeCompany_item32;
	lv_obj_t *MainScreen_listSyringeCompany_item33;
	lv_obj_t *MainScreen_listSyringeCompany_item34;
	lv_obj_t *MainScreen_listSyringeCompany_item35;
	lv_obj_t *MainScreen_listSyringeCompany_item36;
	lv_obj_t *MainScreen_listSyringeCompany_item37;
	lv_obj_t *MainScreen_listSyringeCompany_item38;
	lv_obj_t *MainScreen_listSyringeCompany_item39;
	lv_obj_t *MainScreen_listSyringeCompany_item40;
	lv_obj_t *MainScreen_listSyringeCompany_item41;
	lv_obj_t *MainScreen_listSyringeCompany_item42;
	lv_obj_t *MainScreen_listSyringeCompany_item43;
	lv_obj_t *MainScreen_listSyringeCompany_item44;
	lv_obj_t *MainScreen_listSyringeCompany_item45;
	lv_obj_t *MainScreen_listSyringeCompany_item46;
	lv_obj_t *MainScreen_listSyringeCompany_item47;
	lv_obj_t *MainScreen_listSyringeCompany_item48;
	lv_obj_t *MainScreen_listSyringeCompany_item49;
	lv_obj_t *MainScreen_listSyringeType;
	lv_obj_t *MainScreen_listSyringeType_item0;
	lv_obj_t *MainScreen_listSyringeType_item1;
	lv_obj_t *MainScreen_listSyringeType_item2;
	lv_obj_t *MainScreen_listSyringeType_item3;
	lv_obj_t *MainScreen_listSyringeType_item4;
	lv_obj_t *MainScreen_listSyringeType_item5;
	lv_obj_t *MainScreen_listSyringeType_item6;
	lv_obj_t *MainScreen_listSyringeType_item7;
	lv_obj_t *MainScreen_listSyringeType_item8;
	lv_obj_t *MainScreen_listSyringeType_item9;
	lv_obj_t *MainScreen_listSyringeType_item10;
	lv_obj_t *MainScreen_listSyringeType_item11;
	lv_obj_t *MainScreen_listSyringeType_item12;
	lv_obj_t *MainScreen_listSyringeType_item13;
	lv_obj_t *MainScreen_listSyringeType_item14;
	lv_obj_t *MainScreen_listSyringeType_item15;
	lv_obj_t *MainScreen_listSyringeType_item16;
	lv_obj_t *MainScreen_listSyringeType_item17;
	lv_obj_t *MainScreen_listSyringeType_item18;
	lv_obj_t *MainScreen_listSyringeType_item19;
	lv_obj_t *MainScreen_contSyringeValues;
	lv_obj_t *MainScreen_labelSyringeNameValue;
	lv_obj_t *MainScreen_labelSyringeVolumeValue;
	lv_obj_t *MainScreen_labelSyringeInnerDiaValue;
	lv_obj_t *MainScreen_labelSyringeOuterDiaValue;
	lv_obj_t *MainScreen_labelSyringeBarrelLenValue;
	lv_obj_t *MainScreen_labelSyringePlungerLenValue;
	lv_obj_t *MainScreen_labelSyringeDiaTolValue;
	lv_obj_t *MainScreen_taSyringeNameValue;
	lv_obj_t *MainScreen_spinboxSyringeVolume;
	lv_obj_t *MainScreen_spinboxSyringeVolume_btn;
	lv_obj_t *MainScreen_spinboxSyringeVolume_btn_minus;
	lv_obj_t *MainScreen_spinboxSyringeInnerDia;
	lv_obj_t *MainScreen_spinboxSyringeInnerDia_btn;
	lv_obj_t *MainScreen_spinboxSyringeInnerDia_btn_minus;
	lv_obj_t *MainScreen_spinboxSyringeOuterDia;
	lv_obj_t *MainScreen_spinboxSyringeOuterDia_btn;
	lv_obj_t *MainScreen_spinboxSyringeOuterDia_btn_minus;
	lv_obj_t *MainScreen_spinboxSyringeBarrelLen;
	lv_obj_t *MainScreen_spinboxSyringeBarrelLen_btn;
	lv_obj_t *MainScreen_spinboxSyringeBarrelLen_btn_minus;
	lv_obj_t *MainScreen_spinboxSyringePlungerLen;
	lv_obj_t *MainScreen_spinboxSyringePlungerLen_btn;
	lv_obj_t *MainScreen_spinboxSyringePlungerLen_btn_minus;
	lv_obj_t *MainScreen_spinboxSyringeDiaTolerance;
	lv_obj_t *MainScreen_spinboxSyringeDiaTolerance_btn;
	lv_obj_t *MainScreen_spinboxSyringeDiaTolerance_btn_minus;
	lv_obj_t *MainScreen_labelSyringeHeader;
	lv_obj_t *MainScreen_btnDummySyringe;
	lv_obj_t *MainScreen_btnDummySyringe_label;
	lv_obj_t *MainScreen_contDrug;
	lv_obj_t *MainScreen_btnGoMenuDrug;
	lv_obj_t *MainScreen_btnGoMenuDrug_label;
	lv_obj_t *MainScreen_listDrugBrand;
	lv_obj_t *MainScreen_listDrugBrand_item0;
	lv_obj_t *MainScreen_listDrugBrand_item1;
	lv_obj_t *MainScreen_listDrugBrand_item2;
	lv_obj_t *MainScreen_listDrugBrand_item3;
	lv_obj_t *MainScreen_listDrugBrand_item4;
	lv_obj_t *MainScreen_listDrugBrand_item5;
	lv_obj_t *MainScreen_listDrugBrand_item6;
	lv_obj_t *MainScreen_listDrugBrand_item7;
	lv_obj_t *MainScreen_listDrugBrand_item8;
	lv_obj_t *MainScreen_listDrugBrand_item9;
	lv_obj_t *MainScreen_listDrugBrand_item10;
	lv_obj_t *MainScreen_listDrugBrand_item11;
	lv_obj_t *MainScreen_listDrugBrand_item12;
	lv_obj_t *MainScreen_listDrugBrand_item13;
	lv_obj_t *MainScreen_listDrugBrand_item14;
	lv_obj_t *MainScreen_listDrugBrand_item15;
	lv_obj_t *MainScreen_listDrugBrand_item16;
	lv_obj_t *MainScreen_listDrugBrand_item17;
	lv_obj_t *MainScreen_listDrugBrand_item18;
	lv_obj_t *MainScreen_listDrugBrand_item19;
	lv_obj_t *MainScreen_listDrugBrand_item20;
	lv_obj_t *MainScreen_listDrugBrand_item21;
	lv_obj_t *MainScreen_listDrugBrand_item22;
	lv_obj_t *MainScreen_listDrugBrand_item23;
	lv_obj_t *MainScreen_listDrugBrand_item24;
	lv_obj_t *MainScreen_listDrugBrand_item25;
	lv_obj_t *MainScreen_listDrugBrand_item26;
	lv_obj_t *MainScreen_listDrugBrand_item27;
	lv_obj_t *MainScreen_listDrugBrand_item28;
	lv_obj_t *MainScreen_listDrugBrand_item29;
	lv_obj_t *MainScreen_listDrugBrand_item30;
	lv_obj_t *MainScreen_listDrugBrand_item31;
	lv_obj_t *MainScreen_listDrugBrand_item32;
	lv_obj_t *MainScreen_listDrugBrand_item33;
	lv_obj_t *MainScreen_listDrugBrand_item34;
	lv_obj_t *MainScreen_listDrugBrand_item35;
	lv_obj_t *MainScreen_listDrugBrand_item36;
	lv_obj_t *MainScreen_listDrugBrand_item37;
	lv_obj_t *MainScreen_listDrugBrand_item38;
	lv_obj_t *MainScreen_listDrugBrand_item39;
	lv_obj_t *MainScreen_listDrugBrand_item40;
	lv_obj_t *MainScreen_listDrugBrand_item41;
	lv_obj_t *MainScreen_listDrugBrand_item42;
	lv_obj_t *MainScreen_listDrugBrand_item43;
	lv_obj_t *MainScreen_listDrugBrand_item44;
	lv_obj_t *MainScreen_listDrugBrand_item45;
	lv_obj_t *MainScreen_listDrugBrand_item46;
	lv_obj_t *MainScreen_listDrugBrand_item47;
	lv_obj_t *MainScreen_listDrugBrand_item48;
	lv_obj_t *MainScreen_listDrugBrand_item49;
	lv_obj_t *MainScreen_contDrugValues;
	lv_obj_t *MainScreen_label_26;
	lv_obj_t *MainScreen_label_25;
	lv_obj_t *MainScreen_label_24;
	lv_obj_t *MainScreen_label_23;
	lv_obj_t *MainScreen_label_22;
	lv_obj_t *MainScreen_label_21;
	lv_obj_t *MainScreen_label_20;
	lv_obj_t *MainScreen_label_28;
	lv_obj_t *MainScreen_label_27;
	lv_obj_t *MainScreen_taDrugNameValue;
	lv_obj_t *MainScreen_taDrugBrandValue;
	lv_obj_t *MainScreen_ddlistDrugId;
	lv_obj_t *MainScreen_spinboxDrugmgml;
	lv_obj_t *MainScreen_spinboxDrugmgml_btn;
	lv_obj_t *MainScreen_spinboxDrugmgml_btn_minus;
	lv_obj_t *MainScreen_spinboxDruguml;
	lv_obj_t *MainScreen_spinboxDruguml_btn;
	lv_obj_t *MainScreen_spinboxDruguml_btn_minus;
	lv_obj_t *MainScreen_spinboxDrugperkg;
	lv_obj_t *MainScreen_spinboxDrugperkg_btn;
	lv_obj_t *MainScreen_spinboxDrugperkg_btn_minus;
	lv_obj_t *MainScreen_spinboxDrugRateMin;
	lv_obj_t *MainScreen_spinboxDrugRateMin_btn;
	lv_obj_t *MainScreen_spinboxDrugRateMin_btn_minus;
	lv_obj_t *MainScreen_spinboxDrugRateMax;
	lv_obj_t *MainScreen_spinboxDrugRateMax_btn;
	lv_obj_t *MainScreen_spinboxDrugRateMax_btn_minus;
	lv_obj_t *MainScreen_spinboxDrugRateDef;
	lv_obj_t *MainScreen_spinboxDrugRateDef_btn;
	lv_obj_t *MainScreen_spinboxDrugRateDef_btn_minus;
	lv_obj_t *MainScreen_labelDrugHeader;
	lv_obj_t *MainScreen_btnDummyDrug;
	lv_obj_t *MainScreen_btnDummyDrug_label;
	lv_obj_t *MainScreen_contMode;
	lv_obj_t *MainScreen_btnGoMenuMode;
	lv_obj_t *MainScreen_btnGoMenuMode_label;
	lv_obj_t *MainScreen_listModeMode;
	lv_obj_t *MainScreen_listModeMode_item0;
	lv_obj_t *MainScreen_listModeMode_item1;
	lv_obj_t *MainScreen_listModeMode_item2;
	lv_obj_t *MainScreen_listModeMode_item3;
	lv_obj_t *MainScreen_listModeMode_item4;
	lv_obj_t *MainScreen_listModeMode_item5;
	lv_obj_t *MainScreen_listModeUnit;
	lv_obj_t *MainScreen_listModeUnit_item0;
	lv_obj_t *MainScreen_listModeUnit_item1;
	lv_obj_t *MainScreen_listModeUnit_item2;
	lv_obj_t *MainScreen_listModeUnit_item3;
	lv_obj_t *MainScreen_listModeUnit_item4;
	lv_obj_t *MainScreen_listModeUnit_item5;
	lv_obj_t *MainScreen_listModeUnit_item6;
	lv_obj_t *MainScreen_listModeUnit_item7;
	lv_obj_t *MainScreen_contModeValues;
	lv_obj_t *MainScreen_contModeValueWeight;
	lv_obj_t *MainScreen_label_33;
	lv_obj_t *MainScreen_label_38;
	lv_obj_t *MainScreen_spinboxModeBodyWeight;
	lv_obj_t *MainScreen_spinboxModeBodyWeight_btn;
	lv_obj_t *MainScreen_spinboxModeBodyWeight_btn_minus;
	lv_obj_t *MainScreen_contModeValueInfusionRate;
	lv_obj_t *MainScreen_label_39;
	lv_obj_t *MainScreen_labelModeInfusionRateUnit;
	lv_obj_t *MainScreen_spinboxModeInfusionRate;
	lv_obj_t *MainScreen_spinboxModeInfusionRate_btn;
	lv_obj_t *MainScreen_spinboxModeInfusionRate_btn_minus;
	lv_obj_t *MainScreen_contModeValueTotalTime;
	lv_obj_t *MainScreen_label_41;
	lv_obj_t *MainScreen_spinboxModeTotalTimeHour;
	lv_obj_t *MainScreen_spinboxModeTotalTimeHour_btn;
	lv_obj_t *MainScreen_spinboxModeTotalTimeHour_btn_minus;
	lv_obj_t *MainScreen_spinboxModeTotalTimeMinute;
	lv_obj_t *MainScreen_spinboxModeTotalTimeMinute_btn;
	lv_obj_t *MainScreen_spinboxModeTotalTimeMinute_btn_minus;
	lv_obj_t *MainScreen_spinboxModeTotalTimeSecond;
	lv_obj_t *MainScreen_spinboxModeTotalTimeSecond_btn;
	lv_obj_t *MainScreen_spinboxModeTotalTimeSecond_btn_minus;
	lv_obj_t *MainScreen_label_43;
	lv_obj_t *MainScreen_label_44;
	lv_obj_t *MainScreen_contModeValueTotalVolume;
	lv_obj_t *MainScreen_label_35;
	lv_obj_t *MainScreen_labelModeVolumeUnit;
	lv_obj_t *MainScreen_spinboxModeTotalVolume;
	lv_obj_t *MainScreen_spinboxModeTotalVolume_btn;
	lv_obj_t *MainScreen_spinboxModeTotalVolume_btn_minus;
	lv_obj_t *MainScreen_labelModeHeader;
	lv_obj_t *MainScreen_btnDummyMode;
	lv_obj_t *MainScreen_btnDummyMode_label;
	lv_obj_t *MainScreen_contOcclusion;
	lv_obj_t *MainScreen_btnGoMenuOcclusion;
	lv_obj_t *MainScreen_btnGoMenuOcclusion_label;
	lv_obj_t *MainScreen_label_45;
	lv_obj_t *MainScreen_sliderOcclusionOcc;
	lv_obj_t *MainScreen_contKVO;
	lv_obj_t *MainScreen_label_46;
	lv_obj_t *MainScreen_contKVOValues;
	lv_obj_t *MainScreen_label_47;
	lv_obj_t *MainScreen_label_48;
	lv_obj_t *MainScreen_swKVOMode;
	lv_obj_t *MainScreen_labelswKVOModeEnable;
	lv_obj_t *MainScreen_labelswKVOModeDisable;
	lv_obj_t *MainScreen_labelKVORate;
	lv_obj_t *MainScreen_spinboxKVORate;
	lv_obj_t *MainScreen_spinboxKVORate_btn;
	lv_obj_t *MainScreen_spinboxKVORate_btn_minus;
	lv_obj_t *MainScreen_btnGoMenuKVO;
	lv_obj_t *MainScreen_btnGoMenuKVO_label;
	lv_obj_t *MainScreen_btnDummyKVO;
	lv_obj_t *MainScreen_btnDummyKVO_label;
	lv_obj_t *MainScreen_contIntermittent;
	lv_obj_t *MainScreen_label_54;
	lv_obj_t *MainScreen_contIntermittentValues;
	lv_obj_t *MainScreen_label_53;
	lv_obj_t *MainScreen_label_52;
	lv_obj_t *MainScreen_label_55;
	lv_obj_t *MainScreen_label_56;
	lv_obj_t *MainScreen_labelIntermittentInfusionRate;
	lv_obj_t *MainScreen_labelIntermittentBackGroundRate;
	lv_obj_t *MainScreen_spinboxIntermittentInfusionRate;
	lv_obj_t *MainScreen_spinboxIntermittentInfusionRate_btn;
	lv_obj_t *MainScreen_spinboxIntermittentInfusionRate_btn_minus;
	lv_obj_t *MainScreen_contIntermittentDuration;
	lv_obj_t *MainScreen_label_58;
	lv_obj_t *MainScreen_label_57;
	lv_obj_t *MainScreen_spinboxIntermittentDurationHour;
	lv_obj_t *MainScreen_spinboxIntermittentDurationHour_btn;
	lv_obj_t *MainScreen_spinboxIntermittentDurationHour_btn_minus;
	lv_obj_t *MainScreen_spinboxIntermittentDurationMinute;
	lv_obj_t *MainScreen_spinboxIntermittentDurationMinute_btn;
	lv_obj_t *MainScreen_spinboxIntermittentDurationMinute_btn_minus;
	lv_obj_t *MainScreen_spinboxIntermittentDurationSecond;
	lv_obj_t *MainScreen_spinboxIntermittentDurationSecond_btn;
	lv_obj_t *MainScreen_spinboxIntermittentDurationSecond_btn_minus;
	lv_obj_t *MainScreen_spinboxIntermittentBackgroundRate;
	lv_obj_t *MainScreen_spinboxIntermittentBackgroundRate_btn;
	lv_obj_t *MainScreen_spinboxIntermittentBackgroundRate_btn_minus;
	lv_obj_t *MainScreen_contIntermittentSleep;
	lv_obj_t *MainScreen_label_60;
	lv_obj_t *MainScreen_label_59;
	lv_obj_t *MainScreen_spinboxIntermittentSleepHour;
	lv_obj_t *MainScreen_spinboxIntermittentSleepHour_btn;
	lv_obj_t *MainScreen_spinboxIntermittentSleepHour_btn_minus;
	lv_obj_t *MainScreen_spinboxIntermittentSleepMinute;
	lv_obj_t *MainScreen_spinboxIntermittentSleepMinute_btn;
	lv_obj_t *MainScreen_spinboxIntermittentSleepMinute_btn_minus;
	lv_obj_t *MainScreen_spinboxIntermittentSleepSecond;
	lv_obj_t *MainScreen_spinboxIntermittentSleepSecond_btn;
	lv_obj_t *MainScreen_spinboxIntermittentSleepSecond_btn_minus;
	lv_obj_t *MainScreen_btnGOMenuIntermittent;
	lv_obj_t *MainScreen_btnGOMenuIntermittent_label;
	lv_obj_t *MainScreen_btnDummyIntermittent;
	lv_obj_t *MainScreen_btnDummyIntermittent_label;
	lv_obj_t *MainScreen_contRhythmic;
	lv_obj_t *MainScreen_label_72;
	lv_obj_t *MainScreen_btnGoMenuRhythmic;
	lv_obj_t *MainScreen_btnGoMenuRhythmic_label;
	lv_obj_t *MainScreen_btnDummyRhythmic;
	lv_obj_t *MainScreen_btnDummyRhythmic_label;
	lv_obj_t *MainScreen_contNurseCall;
	lv_obj_t *MainScreen_label_66;
	lv_obj_t *MainScreen_contNurseCallValues;
	lv_obj_t *MainScreen_label_65;
	lv_obj_t *MainScreen_label_64;
	lv_obj_t *MainScreen_swNurseCall;
	lv_obj_t *MainScreen_labelswNurseCallEnable;
	lv_obj_t *MainScreen_labelswNurseCallDisable;
	lv_obj_t *MainScreen_label_61;
	lv_obj_t *MainScreen_spinboxNurseCallDuration;
	lv_obj_t *MainScreen_spinboxNurseCallDuration_btn;
	lv_obj_t *MainScreen_spinboxNurseCallDuration_btn_minus;
	lv_obj_t *MainScreen_btnGoMenuNurseCall;
	lv_obj_t *MainScreen_btnGoMenuNurseCall_label;
	lv_obj_t *MainScreen_btnDummyNurseCall;
	lv_obj_t *MainScreen_btnDummyNurseCall_label;
	lv_obj_t *MainScreen_contBolus;
	lv_obj_t *MainScreen_label_78;
	lv_obj_t *MainScreen_contBolusValues;
	lv_obj_t *MainScreen_label_88;
	lv_obj_t *MainScreen_label_86;
	lv_obj_t *MainScreen_label_85;
	lv_obj_t *MainScreen_labelBolusRateUnit;
	lv_obj_t *MainScreen_labelBolusMaxVolumeUnit;
	lv_obj_t *MainScreen_spinboxBolusRate;
	lv_obj_t *MainScreen_spinboxBolusRate_btn;
	lv_obj_t *MainScreen_spinboxBolusRate_btn_minus;
	lv_obj_t *MainScreen_spinboxBolusMaxVolume;
	lv_obj_t *MainScreen_spinboxBolusMaxVolume_btn;
	lv_obj_t *MainScreen_spinboxBolusMaxVolume_btn_minus;
	lv_obj_t *MainScreen_contBolusInterVal;
	lv_obj_t *MainScreen_label_80;
	lv_obj_t *MainScreen_label_79;
	lv_obj_t *MainScreen_spinboxBolusIntervalHour;
	lv_obj_t *MainScreen_spinboxBolusIntervalHour_btn;
	lv_obj_t *MainScreen_spinboxBolusIntervalHour_btn_minus;
	lv_obj_t *MainScreen_spinboxBolusIntervalMinute;
	lv_obj_t *MainScreen_spinboxBolusIntervalMinute_btn;
	lv_obj_t *MainScreen_spinboxBolusIntervalMinute_btn_minus;
	lv_obj_t *MainScreen_spinboxBolusIntervalSecond;
	lv_obj_t *MainScreen_spinboxBolusIntervalSecond_btn;
	lv_obj_t *MainScreen_spinboxBolusIntervalSecond_btn_minus;
	lv_obj_t *MainScreen_btnGoMenuBolus;
	lv_obj_t *MainScreen_btnGoMenuBolus_label;
	lv_obj_t *MainScreen_btnDummyBolus;
	lv_obj_t *MainScreen_btnDummyBolus_label;
	lv_obj_t *MainScreen_contPurge;
	lv_obj_t *MainScreen_label_96;
	lv_obj_t *MainScreen_contPurgeValues;
	lv_obj_t *MainScreen_label_95;
	lv_obj_t *MainScreen_label_94;
	lv_obj_t *MainScreen_label_93;
	lv_obj_t *MainScreen_labelPurgeRateUnit;
	lv_obj_t *MainScreen_labelPurgeMaxVolumeUnit;
	lv_obj_t *MainScreen_spinboxPurgeRate;
	lv_obj_t *MainScreen_spinboxPurgeRate_btn;
	lv_obj_t *MainScreen_spinboxPurgeRate_btn_minus;
	lv_obj_t *MainScreen_spinboxPurgeMaxVolume;
	lv_obj_t *MainScreen_spinboxPurgeMaxVolume_btn;
	lv_obj_t *MainScreen_spinboxPurgeMaxVolume_btn_minus;
	lv_obj_t *MainScreen_contPurgeInterVal;
	lv_obj_t *MainScreen_label_90;
	lv_obj_t *MainScreen_label_89;
	lv_obj_t *MainScreen_spinboxPurgeIntervalHour;
	lv_obj_t *MainScreen_spinboxPurgeIntervalHour_btn;
	lv_obj_t *MainScreen_spinboxPurgeIntervalHour_btn_minus;
	lv_obj_t *MainScreen_spinboxPurgeIntervalMinute;
	lv_obj_t *MainScreen_spinboxPurgeIntervalMinute_btn;
	lv_obj_t *MainScreen_spinboxPurgeIntervalMinute_btn_minus;
	lv_obj_t *MainScreen_spinboxPurgeIntervalSecond;
	lv_obj_t *MainScreen_spinboxPurgeIntervalSecond_btn;
	lv_obj_t *MainScreen_spinboxPurgeIntervalSecond_btn_minus;
	lv_obj_t *MainScreen_btnGoMenuPurge;
	lv_obj_t *MainScreen_btnGoMenuPurge_label;
	lv_obj_t *MainScreen_btnDummyPurge;
	lv_obj_t *MainScreen_btnDummyPurge_label;
	lv_obj_t *MainScreen_ta_keybard;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_move_animation(void * var, int32_t duration, int32_t delay, int32_t x_end, int32_t y_end, lv_anim_path_cb_t path_cb,
                       uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                       lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void ui_scale_animation(void * var, int32_t duration, int32_t delay, int32_t width, int32_t height, lv_anim_path_cb_t path_cb,
                        uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                        lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void ui_img_zoom_animation(void * var, int32_t duration, int32_t delay, int32_t zoom, lv_anim_path_cb_t path_cb,
                           uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                           lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void ui_img_rotate_animation(void * var, int32_t duration, int32_t delay, lv_coord_t x, lv_coord_t y, int32_t rotate,
                   lv_anim_path_cb_t path_cb, uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time,
                   uint32_t playback_delay, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void init_scr_del_flag(lv_ui *ui);

void setup_ui(lv_ui *ui);


extern lv_ui guider_ui;


void setup_scr_LogoScreen(lv_ui *ui);
void setup_scr_MainScreen(lv_ui *ui);
LV_IMG_DECLARE(_farafan_logo_600x194);
LV_IMG_DECLARE(_network_64_alpha_64x64);
LV_IMG_DECLARE(_Serial_64_alpha_64x64);
LV_IMG_DECLARE(_usb_64_alpha_64x64);

LV_IMG_DECLARE(_batterybg_64_38x64);

LV_IMG_DECLARE(_battery_64_38x64);
LV_IMG_DECLARE(_syringe2_512_alpha_400x100);
LV_IMG_DECLARE(_forbidden_64_alpha_64x64);
LV_IMG_DECLARE(_droplet_32_alpha_32x32);

LV_IMG_DECLARE(_ledbar_empty_26x132);

LV_IMG_DECLARE(_ledbar_full_26x132);

LV_IMG_DECLARE(_Syringe_100_100x100);

LV_IMG_DECLARE(_Syringe_100_100x100);

LV_IMG_DECLARE(_Drug_100_100x100);

LV_IMG_DECLARE(_Drug_100_100x100);

LV_IMG_DECLARE(_Mode_100_100x100);

LV_IMG_DECLARE(_Mode_100_100x100);

LV_IMG_DECLARE(_OCC_100_100x100);

LV_IMG_DECLARE(_OCC_100_100x100);

LV_IMG_DECLARE(_KVO_100_100x100);

LV_IMG_DECLARE(_KVO_100_100x100);

LV_IMG_DECLARE(_Intermittent_100_100x100);

LV_IMG_DECLARE(_Intermittent_100_100x100);

LV_IMG_DECLARE(_Rhythmic_100_100x100);

LV_IMG_DECLARE(_Rhythmic_100_100x100);

LV_IMG_DECLARE(_Nurse_100_100x100);

LV_IMG_DECLARE(_Nurse_100_100x100);

LV_IMG_DECLARE(_Bolus_100_100x100);

LV_IMG_DECLARE(_Bolus_100_100x100);

LV_IMG_DECLARE(_Purge_100_100x100);

LV_IMG_DECLARE(_Purge_100_100x100);

LV_IMG_DECLARE(_Setting_100_100x100);

LV_IMG_DECLARE(_Setting_100_100x100);

LV_IMG_DECLARE(_ledbar_empty_26x132);

LV_IMG_DECLARE(_ledbar_full_26x132);

LV_IMG_DECLARE(_ledbar_full_26x132);

LV_FONT_DECLARE(lv_font_montserratMedium_19)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_montserratMedium_18)
LV_FONT_DECLARE(lv_font_Alatsi_Regular_18)
LV_FONT_DECLARE(lv_font_Amiko_Regular_21)
LV_FONT_DECLARE(lv_font_arial_17)
LV_FONT_DECLARE(lv_font_arial_33)
LV_FONT_DECLARE(lv_font_arial_35)
LV_FONT_DECLARE(lv_font_arial_25)
LV_FONT_DECLARE(lv_font_arial_100)
LV_FONT_DECLARE(lv_font_Acme_Regular_22)
LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_Acme_Regular_26)
LV_FONT_DECLARE(lv_font_Acme_Regular_25)
LV_FONT_DECLARE(lv_font_Acme_Regular_28)
LV_FONT_DECLARE(lv_font_Acme_Regular_24)
LV_FONT_DECLARE(lv_font_Alatsi_Regular_19)
LV_FONT_DECLARE(lv_font_arial_14)
LV_FONT_DECLARE(lv_font_Alatsi_Regular_16)
LV_FONT_DECLARE(lv_font_calibrib_18)
LV_FONT_DECLARE(lv_font_Alatsi_Regular_21)
LV_FONT_DECLARE(lv_font_Alatsi_Regular_14)
LV_FONT_DECLARE(lv_font_SourceHanSerifSC_Regular_18)


#ifdef __cplusplus
}
#endif
#endif
