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
  
	lv_obj_t *MainScreen;
	bool MainScreen_del;
	lv_obj_t *g_kb_MainScreen;
	lv_obj_t *MainScreen_contHeader;
	lv_obj_t *MainScreen_digital_clock;
	lv_obj_t *MainScreen_datetext;
	lv_obj_t *MainScreen_labelAlarmNut;
	lv_obj_t *MainScreen_labelAlarmPlunger;
	lv_obj_t *MainScreen_imgNetwork;
	lv_obj_t *MainScreen_imgSerialPort;
	lv_obj_t *MainScreen_imgUsbPort;
	lv_obj_t *MainScreen_barBatteryLevel;
	lv_obj_t *MainScreen_contFooter;
	lv_obj_t *MainScreen_imgSyringe;
	lv_obj_t *MainScreen_labelDrug;
	lv_obj_t *MainScreen_labelSyringe;
	lv_obj_t *MainScreen_labelDiameter;
	lv_obj_t *MainScreen_barSyringeLevel;
	lv_obj_t *MainScreen_labelSyringeInfo;
	lv_obj_t *MainScreen_imgForbidden;
	lv_obj_t *MainScreen_imgDroplet;
	lv_obj_t *MainScreen_contMain;
	lv_obj_t *MainScreen_barOcclusionLevel;
	lv_obj_t *MainScreen_label_1;
	lv_obj_t *MainScreen_labelInjectionMode;
	lv_obj_t *MainScreen_label_2;
	lv_obj_t *MainScreen_labelInjectionRate;
	lv_obj_t *MainScreen_label_Error;
	lv_obj_t *MainScreen_labelInjectedVolume;
	lv_obj_t *MainScreen_label_3;
	lv_obj_t *MainScreen_label_4;
	lv_obj_t *MainScreen_label_5;
	lv_obj_t *MainScreen_label_6;
	lv_obj_t *MainScreen_labelTimeLeft;
	lv_obj_t *MainScreen_labelRemVolume;
	lv_obj_t *MainScreen_labelPatientKg;
	lv_obj_t *MainScreen_labelTotalVolume;
	lv_obj_t *MainScreen_btnGoSettingMain;
	lv_obj_t *MainScreen_btnGoSettingMain_label;
	lv_obj_t *MainScreen_contSetting;
	lv_obj_t *MainScreen_btnGoMainSetting;
	lv_obj_t *MainScreen_btnGoMainSetting_label;
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
	lv_obj_t *MainScreen_contSyringe;
	lv_obj_t *MainScreen_btnGoSettingSyringe;
	lv_obj_t *MainScreen_btnGoSettingSyringe_label;
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
	lv_obj_t *MainScreen_label_18;
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


void setup_scr_MainScreen(lv_ui *ui);
LV_IMG_DECLARE(_network_64_alpha_64x64);
LV_IMG_DECLARE(_Serial_64_alpha_64x64);
LV_IMG_DECLARE(_usb_64_alpha_64x64);

LV_IMG_DECLARE(_batterybg_64_38x64);

LV_IMG_DECLARE(_battery_64_38x64);
LV_IMG_DECLARE(_syringe2_512_alpha_400x100);
LV_IMG_DECLARE(_forbidden_64_alpha_64x64);
LV_IMG_DECLARE(_droplet_32_alpha_32x32);

LV_IMG_DECLARE(_ledbar_empty_25x132);

LV_IMG_DECLARE(_ledbar_full_25x132);

LV_IMG_DECLARE(_Syringe_100_100x100);

LV_IMG_DECLARE(_Syringe_100_100x100);

LV_IMG_DECLARE(_Syringe_100_100x100);

LV_IMG_DECLARE(_Syringe_100_100x100);

LV_IMG_DECLARE(_Syringe_100_100x100);

LV_IMG_DECLARE(_Syringe_100_100x100);

LV_IMG_DECLARE(_Syringe_100_100x100);

LV_IMG_DECLARE(_Syringe_100_100x100);

LV_IMG_DECLARE(_Syringe_100_100x100);

LV_IMG_DECLARE(_Syringe_100_100x100);

LV_IMG_DECLARE(_Syringe_100_100x100);

LV_IMG_DECLARE(_Syringe_100_100x100);

LV_IMG_DECLARE(_Syringe_100_100x100);

LV_IMG_DECLARE(_Syringe_100_100x100);

LV_IMG_DECLARE(_Nurse_100_100x100);

LV_IMG_DECLARE(_Nurse_100_100x100);

LV_IMG_DECLARE(_Bolus_100_100x100);

LV_IMG_DECLARE(_Bolus_100_100x100);

LV_IMG_DECLARE(_Purge_100_100x100);

LV_IMG_DECLARE(_Purge_100_100x100);

LV_IMG_DECLARE(_Setting_100_100x100);

LV_IMG_DECLARE(_Setting_100_100x100);

LV_FONT_DECLARE(lv_font_montserratMedium_19)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_montserratMedium_18)
LV_FONT_DECLARE(lv_font_Alatsi_Regular_18)
LV_FONT_DECLARE(lv_font_Amiko_Regular_21)
LV_FONT_DECLARE(lv_font_arial_17)
LV_FONT_DECLARE(lv_font_Acme_Regular_30)
LV_FONT_DECLARE(lv_font_arial_33)
LV_FONT_DECLARE(lv_font_arial_35)
LV_FONT_DECLARE(lv_font_arial_25)
LV_FONT_DECLARE(lv_font_arial_100)
LV_FONT_DECLARE(lv_font_Acme_Regular_20)
LV_FONT_DECLARE(lv_font_Acme_Regular_22)
LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_Acme_Regular_26)
LV_FONT_DECLARE(lv_font_Acme_Regular_25)
LV_FONT_DECLARE(lv_font_Acme_Regular_28)
LV_FONT_DECLARE(lv_font_Acme_Regular_24)
LV_FONT_DECLARE(lv_font_Alatsi_Regular_19)
LV_FONT_DECLARE(lv_font_arial_14)
LV_FONT_DECLARE(lv_font_Alatsi_Regular_16)
LV_FONT_DECLARE(lv_font_SourceHanSerifSC_Regular_18)


#ifdef __cplusplus
}
#endif
#endif
