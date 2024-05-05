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
	lv_obj_t *MainScreen_contFooter;
	lv_obj_t *MainScreen_imgSyringe;
	lv_obj_t *MainScreen_labelDrug;
	lv_obj_t *MainScreen_labelSyringe;
	lv_obj_t *MainScreen_labelDiameter;
	lv_obj_t *MainScreen_barSyringeLevel;
	lv_obj_t *MainScreen_labelSyringeInfo;
	lv_obj_t *MainScreen_imgForbidden;
	lv_obj_t *MainScreen_imgDroplet;
	lv_obj_t *MainScreen_contHeader;
	lv_obj_t *MainScreen_digital_clock;
	lv_obj_t *MainScreen_datetext;
	lv_obj_t *MainScreen_labelAlarmNut;
	lv_obj_t *MainScreen_labelAlarmPlunger;
	lv_obj_t *MainScreen_imgNetwork;
	lv_obj_t *MainScreen_imgSerialPort;
	lv_obj_t *MainScreen_imgUsbPort;
	lv_obj_t *MainScreen_barBatteryLevel;
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
	lv_obj_t *MainScreen_btnGoSetting;
	lv_obj_t *MainScreen_btnGoSetting_label;
	lv_obj_t *MainScreen_contSetting;
	lv_obj_t *MainScreen_btnGoMain;
	lv_obj_t *MainScreen_btnGoMain_label;
	lv_obj_t *MainScreen_img_1;
	lv_obj_t *MainScreen_img_3;
	lv_obj_t *MainScreen_img_4;
	lv_obj_t *MainScreen_img_5;
	lv_obj_t *MainScreen_img_6;
	lv_obj_t *MainScreen_img_7;
	lv_obj_t *MainScreen_label_7;
	lv_obj_t *MainScreen_label_9;
	lv_obj_t *MainScreen_label_10;
	lv_obj_t *MainScreen_label_11;
	lv_obj_t *MainScreen_label_12;
	lv_obj_t *MainScreen_label_13;
	lv_obj_t *MainScreen_img_2;
	lv_obj_t *MainScreen_img_8;
	lv_obj_t *MainScreen_img_9;
	lv_obj_t *MainScreen_img_10;
	lv_obj_t *MainScreen_img_11;
	lv_obj_t *MainScreen_label_8;
	lv_obj_t *MainScreen_label_14;
	lv_obj_t *MainScreen_label_15;
	lv_obj_t *MainScreen_label_16;
	lv_obj_t *MainScreen_label_17;
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
LV_IMG_DECLARE(_syringe2_512_alpha_400x100);
LV_IMG_DECLARE(_forbidden_64_alpha_64x64);
LV_IMG_DECLARE(_droplet_32_alpha_32x32);
LV_IMG_DECLARE(_network_64_alpha_64x64);
LV_IMG_DECLARE(_Serial_64_alpha_64x64);
LV_IMG_DECLARE(_usb_64_alpha_64x64);

LV_IMG_DECLARE(_batterybg_64_38x64);

LV_IMG_DECLARE(_battery_64_38x64);

LV_IMG_DECLARE(_ledbar_empty_25x132);

LV_IMG_DECLARE(_ledbar_full_25x132);
LV_IMG_DECLARE(_Syringe_72_alpha_100x100);
LV_IMG_DECLARE(_Syringe_72_alpha_100x100);
LV_IMG_DECLARE(_Syringe_72_alpha_100x100);
LV_IMG_DECLARE(_Syringe_72_alpha_100x100);
LV_IMG_DECLARE(_Syringe_72_alpha_100x100);
LV_IMG_DECLARE(_Syringe_72_alpha_100x100);
LV_IMG_DECLARE(_Nurse_72_alpha_100x100);
LV_IMG_DECLARE(_Nurse_72_alpha_100x100);
LV_IMG_DECLARE(_droplet_64_alpha_100x100);
LV_IMG_DECLARE(_syringe1_128_alpha_100x100);
LV_IMG_DECLARE(_Setting_72_alpha_100x100);

LV_FONT_DECLARE(lv_font_Amiko_Regular_21)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_arial_17)
LV_FONT_DECLARE(lv_font_montserratMedium_19)
LV_FONT_DECLARE(lv_font_montserratMedium_18)
LV_FONT_DECLARE(lv_font_Alatsi_Regular_18)
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


#ifdef __cplusplus
}
#endif
#endif
