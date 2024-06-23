/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"
#include "custom.h"


int MainScreen_digital_clock_min_value = 57;
int MainScreen_digital_clock_hour_value = 11;
int MainScreen_digital_clock_sec_value = 3;
char MainScreen_digital_clock_meridiem[] = "AM";
void setup_scr_MainScreen(lv_ui *ui)
{
	//Write codes MainScreen
	ui->MainScreen = lv_obj_create(NULL);
	ui->g_kb_MainScreen = lv_keyboard_create(ui->MainScreen);
	lv_obj_add_event_cb(ui->g_kb_MainScreen, kb_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_add_flag(ui->g_kb_MainScreen, LV_OBJ_FLAG_HIDDEN);
	lv_obj_set_style_text_font(ui->g_kb_MainScreen, &lv_font_SourceHanSerifSC_Regular_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_size(ui->MainScreen, 800, 480);
	lv_obj_set_scrollbar_mode(ui->MainScreen, LV_SCROLLBAR_MODE_OFF);

	//Write style for MainScreen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_contHeader
	ui->MainScreen_contHeader = lv_obj_create(ui->MainScreen);
	lv_obj_set_pos(ui->MainScreen_contHeader, 0, 0);
	lv_obj_set_size(ui->MainScreen_contHeader, 800, 80);
	lv_obj_set_scrollbar_mode(ui->MainScreen_contHeader, LV_SCROLLBAR_MODE_OFF);

	//Write style for MainScreen_contHeader, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_contHeader, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->MainScreen_contHeader, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->MainScreen_contHeader, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->MainScreen_contHeader, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_contHeader, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_contHeader, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_contHeader, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_contHeader, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_contHeader, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_contHeader, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_contHeader, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_contHeader, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_contHeader, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_digital_clock
	static bool MainScreen_digital_clock_timer_enabled = false;
	ui->MainScreen_digital_clock = lv_dclock_create(ui->MainScreen_contHeader, "11:57:03 AM");
	if (!MainScreen_digital_clock_timer_enabled) {
		lv_timer_create(MainScreen_digital_clock_timer, 1000, NULL);
		MainScreen_digital_clock_timer_enabled = true;
	}
	lv_obj_set_pos(ui->MainScreen_digital_clock, 5, 40);
	lv_obj_set_size(ui->MainScreen_digital_clock, 130, 36);

	//Write style for MainScreen_digital_clock, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_radius(ui->MainScreen_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_digital_clock, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_digital_clock, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_digital_clock, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_digital_clock, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_digital_clock, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_digital_clock, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_datetext
	ui->MainScreen_datetext = lv_label_create(ui->MainScreen_contHeader);
	lv_label_set_text(ui->MainScreen_datetext, "2024/05/05");
	lv_obj_set_style_text_align(ui->MainScreen_datetext, LV_TEXT_ALIGN_CENTER, 0);
	lv_obj_add_flag(ui->MainScreen_datetext, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_add_event_cb(ui->MainScreen_datetext, MainScreen_datetext_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_set_pos(ui->MainScreen_datetext, 5, 0);
	lv_obj_set_size(ui->MainScreen_datetext, 130, 36);

	//Write style for MainScreen_datetext, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->MainScreen_datetext, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_datetext, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_datetext, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_datetext, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_datetext, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_datetext, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_datetext, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_datetext, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_datetext, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_datetext, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_datetext, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_datetext, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_labelAlarmNut
	ui->MainScreen_labelAlarmNut = lv_label_create(ui->MainScreen_contHeader);
	lv_label_set_text(ui->MainScreen_labelAlarmNut, "Nut Released");
	lv_label_set_long_mode(ui->MainScreen_labelAlarmNut, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_labelAlarmNut, 191, 19);
	lv_obj_set_size(ui->MainScreen_labelAlarmNut, 112, 40);

	//Write style for MainScreen_labelAlarmNut, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_labelAlarmNut, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_labelAlarmNut, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_labelAlarmNut, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_labelAlarmNut, &lv_font_Alatsi_Regular_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_labelAlarmNut, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_labelAlarmNut, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_labelAlarmNut, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_labelAlarmNut, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_labelAlarmNut, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_labelAlarmNut, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_labelAlarmNut, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_labelAlarmNut, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_labelAlarmNut, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_labelAlarmNut, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_labelAlarmPlunger
	ui->MainScreen_labelAlarmPlunger = lv_label_create(ui->MainScreen_contHeader);
	lv_label_set_text(ui->MainScreen_labelAlarmPlunger, "Plunger Released");
	lv_label_set_long_mode(ui->MainScreen_labelAlarmPlunger, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_labelAlarmPlunger, 324, 19);
	lv_obj_set_size(ui->MainScreen_labelAlarmPlunger, 112, 40);

	//Write style for MainScreen_labelAlarmPlunger, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_labelAlarmPlunger, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_labelAlarmPlunger, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_labelAlarmPlunger, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_labelAlarmPlunger, &lv_font_Alatsi_Regular_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_labelAlarmPlunger, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_labelAlarmPlunger, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_labelAlarmPlunger, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_labelAlarmPlunger, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_labelAlarmPlunger, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_labelAlarmPlunger, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_labelAlarmPlunger, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_labelAlarmPlunger, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_labelAlarmPlunger, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_labelAlarmPlunger, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_imgNetwork
	ui->MainScreen_imgNetwork = lv_img_create(ui->MainScreen_contHeader);
	lv_obj_add_flag(ui->MainScreen_imgNetwork, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->MainScreen_imgNetwork, &_network_64_alpha_64x64);
	lv_img_set_pivot(ui->MainScreen_imgNetwork, 50,50);
	lv_img_set_angle(ui->MainScreen_imgNetwork, 0);
	lv_obj_set_pos(ui->MainScreen_imgNetwork, 665, 6);
	lv_obj_set_size(ui->MainScreen_imgNetwork, 64, 64);

	//Write style for MainScreen_imgNetwork, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->MainScreen_imgNetwork, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_imgSerialPort
	ui->MainScreen_imgSerialPort = lv_img_create(ui->MainScreen_contHeader);
	lv_obj_add_flag(ui->MainScreen_imgSerialPort, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->MainScreen_imgSerialPort, &_Serial_64_alpha_64x64);
	lv_img_set_pivot(ui->MainScreen_imgSerialPort, 50,50);
	lv_img_set_angle(ui->MainScreen_imgSerialPort, 0);
	lv_obj_set_pos(ui->MainScreen_imgSerialPort, 579, 6);
	lv_obj_set_size(ui->MainScreen_imgSerialPort, 64, 64);

	//Write style for MainScreen_imgSerialPort, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->MainScreen_imgSerialPort, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_imgUsbPort
	ui->MainScreen_imgUsbPort = lv_img_create(ui->MainScreen_contHeader);
	lv_obj_add_flag(ui->MainScreen_imgUsbPort, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->MainScreen_imgUsbPort, &_usb_64_alpha_64x64);
	lv_img_set_pivot(ui->MainScreen_imgUsbPort, 50,50);
	lv_img_set_angle(ui->MainScreen_imgUsbPort, 0);
	lv_obj_set_pos(ui->MainScreen_imgUsbPort, 490, 6);
	lv_obj_set_size(ui->MainScreen_imgUsbPort, 64, 64);

	//Write style for MainScreen_imgUsbPort, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->MainScreen_imgUsbPort, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_barBatteryLevel
	ui->MainScreen_barBatteryLevel = lv_bar_create(ui->MainScreen_contHeader);
	lv_obj_set_style_anim_time(ui->MainScreen_barBatteryLevel, 1000, 0);
	lv_bar_set_mode(ui->MainScreen_barBatteryLevel, LV_BAR_MODE_NORMAL);
	lv_bar_set_range(ui->MainScreen_barBatteryLevel, 0, 4);
	lv_bar_set_value(ui->MainScreen_barBatteryLevel, 2, LV_ANIM_OFF);
	lv_obj_set_pos(ui->MainScreen_barBatteryLevel, 751, 5);
	lv_obj_set_size(ui->MainScreen_barBatteryLevel, 38, 64);

	//Write style for MainScreen_barBatteryLevel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_barBatteryLevel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_barBatteryLevel, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_barBatteryLevel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->MainScreen_barBatteryLevel, &_batterybg_64_38x64, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->MainScreen_barBatteryLevel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_barBatteryLevel, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_barBatteryLevel, 0, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_barBatteryLevel, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->MainScreen_barBatteryLevel, &_battery_64_38x64, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->MainScreen_barBatteryLevel, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write codes MainScreen_contFooter
	ui->MainScreen_contFooter = lv_obj_create(ui->MainScreen);
	lv_obj_set_pos(ui->MainScreen_contFooter, 0, 380);
	lv_obj_set_size(ui->MainScreen_contFooter, 800, 100);
	lv_obj_set_scrollbar_mode(ui->MainScreen_contFooter, LV_SCROLLBAR_MODE_OFF);

	//Write style for MainScreen_contFooter, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_contFooter, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->MainScreen_contFooter, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->MainScreen_contFooter, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->MainScreen_contFooter, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_contFooter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_contFooter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_contFooter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_contFooter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_contFooter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_contFooter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_contFooter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_imgSyringe
	ui->MainScreen_imgSyringe = lv_img_create(ui->MainScreen_contFooter);
	lv_obj_add_flag(ui->MainScreen_imgSyringe, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->MainScreen_imgSyringe, &_syringe2_512_alpha_400x100);
	lv_img_set_pivot(ui->MainScreen_imgSyringe, 50,50);
	lv_img_set_angle(ui->MainScreen_imgSyringe, 0);
	lv_obj_set_pos(ui->MainScreen_imgSyringe, 400, 0);
	lv_obj_set_size(ui->MainScreen_imgSyringe, 400, 100);

	//Write style for MainScreen_imgSyringe, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->MainScreen_imgSyringe, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_labelDrug
	ui->MainScreen_labelDrug = lv_label_create(ui->MainScreen_contFooter);
	lv_label_set_text(ui->MainScreen_labelDrug, "DrugName-manufacture");
	lv_label_set_long_mode(ui->MainScreen_labelDrug, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_labelDrug, 0, 0);
	lv_obj_set_size(ui->MainScreen_labelDrug, 400, 30);

	//Write style for MainScreen_labelDrug, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_labelDrug, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_labelDrug, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_labelDrug, lv_color_hex(0xffff00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_labelDrug, &lv_font_Amiko_Regular_21, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_labelDrug, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_labelDrug, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_labelDrug, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_labelDrug, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_labelDrug, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_labelDrug, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_labelDrug, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_labelDrug, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_labelDrug, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_labelDrug, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_labelSyringe
	ui->MainScreen_labelSyringe = lv_label_create(ui->MainScreen_contFooter);
	lv_label_set_text(ui->MainScreen_labelSyringe, "SyringeName-manufacture");
	lv_label_set_long_mode(ui->MainScreen_labelSyringe, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_labelSyringe, 0, 30);
	lv_obj_set_size(ui->MainScreen_labelSyringe, 400, 30);

	//Write style for MainScreen_labelSyringe, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_labelSyringe, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_labelSyringe, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_labelSyringe, lv_color_hex(0x00fff5), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_labelSyringe, &lv_font_Amiko_Regular_21, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_labelSyringe, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_labelSyringe, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_labelSyringe, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_labelSyringe, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_labelSyringe, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_labelSyringe, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_labelSyringe, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_labelSyringe, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_labelSyringe, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_labelSyringe, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_labelDiameter
	ui->MainScreen_labelDiameter = lv_label_create(ui->MainScreen_contFooter);
	lv_label_set_text(ui->MainScreen_labelDiameter, "Dia:99.9 mm");
	lv_label_set_long_mode(ui->MainScreen_labelDiameter, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_labelDiameter, 0, 60);
	lv_obj_set_size(ui->MainScreen_labelDiameter, 400, 30);

	//Write style for MainScreen_labelDiameter, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_labelDiameter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_labelDiameter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_labelDiameter, lv_color_hex(0xff0000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_labelDiameter, &lv_font_Amiko_Regular_21, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_labelDiameter, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_labelDiameter, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_labelDiameter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_labelDiameter, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_labelDiameter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_labelDiameter, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_labelDiameter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_labelDiameter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_labelDiameter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_labelDiameter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_barSyringeLevel
	ui->MainScreen_barSyringeLevel = lv_bar_create(ui->MainScreen_contFooter);
	lv_obj_set_style_anim_time(ui->MainScreen_barSyringeLevel, 1000, 0);
	lv_bar_set_mode(ui->MainScreen_barSyringeLevel, LV_BAR_MODE_NORMAL);
	lv_bar_set_range(ui->MainScreen_barSyringeLevel, 0, 100);
	lv_bar_set_value(ui->MainScreen_barSyringeLevel, 50, LV_ANIM_OFF);
	lv_obj_set_pos(ui->MainScreen_barSyringeLevel, 552, 24);
	lv_obj_set_size(ui->MainScreen_barSyringeLevel, 177, 50);

	//Write style for MainScreen_barSyringeLevel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_barSyringeLevel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_barSyringeLevel, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_barSyringeLevel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_barSyringeLevel, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_barSyringeLevel, 151, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_barSyringeLevel, lv_color_hex(0xb400ff), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_barSyringeLevel, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_barSyringeLevel, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write codes MainScreen_labelSyringeInfo
	ui->MainScreen_labelSyringeInfo = lv_label_create(ui->MainScreen_contFooter);
	lv_label_set_text(ui->MainScreen_labelSyringeInfo, "Injecting");
	lv_label_set_long_mode(ui->MainScreen_labelSyringeInfo, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_labelSyringeInfo, 450, 75);
	lv_obj_set_size(ui->MainScreen_labelSyringeInfo, 100, 20);

	//Write style for MainScreen_labelSyringeInfo, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_labelSyringeInfo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_labelSyringeInfo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_labelSyringeInfo, lv_color_hex(0xf00000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_labelSyringeInfo, &lv_font_arial_17, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_labelSyringeInfo, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_labelSyringeInfo, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_labelSyringeInfo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_labelSyringeInfo, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_labelSyringeInfo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_labelSyringeInfo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_labelSyringeInfo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_labelSyringeInfo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_labelSyringeInfo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_labelSyringeInfo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_imgForbidden
	ui->MainScreen_imgForbidden = lv_img_create(ui->MainScreen_contFooter);
	lv_obj_add_flag(ui->MainScreen_imgForbidden, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->MainScreen_imgForbidden, &_forbidden_64_alpha_64x64);
	lv_img_set_pivot(ui->MainScreen_imgForbidden, 50,50);
	lv_img_set_angle(ui->MainScreen_imgForbidden, 0);
	lv_obj_set_pos(ui->MainScreen_imgForbidden, 732, 16);
	lv_obj_set_size(ui->MainScreen_imgForbidden, 64, 64);

	//Write style for MainScreen_imgForbidden, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->MainScreen_imgForbidden, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_imgDroplet
	ui->MainScreen_imgDroplet = lv_img_create(ui->MainScreen_contFooter);
	lv_obj_add_flag(ui->MainScreen_imgDroplet, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->MainScreen_imgDroplet, &_droplet_32_alpha_32x32);
	lv_img_set_pivot(ui->MainScreen_imgDroplet, 50,50);
	lv_img_set_angle(ui->MainScreen_imgDroplet, 0);
	lv_obj_set_pos(ui->MainScreen_imgDroplet, 397, 53);
	lv_obj_set_size(ui->MainScreen_imgDroplet, 32, 32);

	//Write style for MainScreen_imgDroplet, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->MainScreen_imgDroplet, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_contMain
	ui->MainScreen_contMain = lv_obj_create(ui->MainScreen);
	lv_obj_set_pos(ui->MainScreen_contMain, 0, 82);
	lv_obj_set_size(ui->MainScreen_contMain, 800, 300);
	lv_obj_set_scrollbar_mode(ui->MainScreen_contMain, LV_SCROLLBAR_MODE_OFF);

	//Write style for MainScreen_contMain, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_contMain, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->MainScreen_contMain, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->MainScreen_contMain, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->MainScreen_contMain, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_contMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_contMain, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_contMain, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_contMain, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_contMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_contMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_contMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_contMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_contMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_barOcclusionLevel
	ui->MainScreen_barOcclusionLevel = lv_bar_create(ui->MainScreen_contMain);
	lv_obj_set_style_anim_time(ui->MainScreen_barOcclusionLevel, 1000, 0);
	lv_bar_set_mode(ui->MainScreen_barOcclusionLevel, LV_BAR_MODE_NORMAL);
	lv_bar_set_range(ui->MainScreen_barOcclusionLevel, 0, 11);
	lv_bar_set_value(ui->MainScreen_barOcclusionLevel, 4, LV_ANIM_OFF);
	lv_obj_set_pos(ui->MainScreen_barOcclusionLevel, 754, 6);
	lv_obj_set_size(ui->MainScreen_barOcclusionLevel, 26, 132);

	//Write style for MainScreen_barOcclusionLevel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_barOcclusionLevel, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_barOcclusionLevel, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_barOcclusionLevel, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_barOcclusionLevel, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_barOcclusionLevel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->MainScreen_barOcclusionLevel, &_ledbar_empty_26x132, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->MainScreen_barOcclusionLevel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_barOcclusionLevel, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_barOcclusionLevel, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_barOcclusionLevel, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_barOcclusionLevel, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_barOcclusionLevel, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->MainScreen_barOcclusionLevel, &_ledbar_full_26x132, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->MainScreen_barOcclusionLevel, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write codes MainScreen_labelInjectionMode
	ui->MainScreen_labelInjectionMode = lv_label_create(ui->MainScreen_contMain);
	lv_label_set_text(ui->MainScreen_labelInjectionMode, "Mode: Volume / Mass / Dosage\n");
	lv_label_set_long_mode(ui->MainScreen_labelInjectionMode, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_labelInjectionMode, 5, 3);
	lv_obj_set_size(ui->MainScreen_labelInjectionMode, 550, 35);

	//Write style for MainScreen_labelInjectionMode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_labelInjectionMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_labelInjectionMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_labelInjectionMode, lv_color_hex(0xebff00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_labelInjectionMode, &lv_font_arial_33, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_labelInjectionMode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_labelInjectionMode, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_labelInjectionMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_labelInjectionMode, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_labelInjectionMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_labelInjectionMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_labelInjectionMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_labelInjectionMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_labelInjectionMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_labelInjectionMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_labelInjectionRate
	ui->MainScreen_labelInjectionRate = lv_label_create(ui->MainScreen_contMain);
	lv_label_set_text(ui->MainScreen_labelInjectionRate, "Rate: 100.0 ml/min\n\n");
	lv_label_set_long_mode(ui->MainScreen_labelInjectionRate, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_labelInjectionRate, 5, 43);
	lv_obj_set_size(ui->MainScreen_labelInjectionRate, 550, 35);

	//Write style for MainScreen_labelInjectionRate, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_labelInjectionRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_labelInjectionRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_labelInjectionRate, lv_color_hex(0xff0027), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_labelInjectionRate, &lv_font_arial_35, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_labelInjectionRate, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_labelInjectionRate, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_labelInjectionRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_labelInjectionRate, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_labelInjectionRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_labelInjectionRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_labelInjectionRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_labelInjectionRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_labelInjectionRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_labelInjectionRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_Error
	ui->MainScreen_label_Error = lv_label_create(ui->MainScreen_contMain);
	lv_label_set_text(ui->MainScreen_label_Error, "Plunger Sensor Error");
	lv_label_set_long_mode(ui->MainScreen_label_Error, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_Error, 250, 270);
	lv_obj_set_size(ui->MainScreen_label_Error, 300, 30);

	//Write style for MainScreen_label_Error, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_Error, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_Error, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_Error, lv_color_hex(0xff0027), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_Error, &lv_font_arial_25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_Error, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_Error, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_Error, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_Error, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_Error, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_Error, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_Error, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_Error, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_Error, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_Error, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_labelInjectedVolume
	ui->MainScreen_labelInjectedVolume = lv_label_create(ui->MainScreen_contMain);
	lv_label_set_text(ui->MainScreen_labelInjectedVolume, "100.1 ml");
	lv_label_set_long_mode(ui->MainScreen_labelInjectedVolume, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_labelInjectedVolume, 0, 94);
	lv_obj_set_size(ui->MainScreen_labelInjectedVolume, 411, 92);

	//Write style for MainScreen_labelInjectedVolume, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_labelInjectedVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_labelInjectedVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_labelInjectedVolume, lv_color_hex(0xff6500), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_labelInjectedVolume, &lv_font_arial_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_labelInjectedVolume, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_labelInjectedVolume, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_labelInjectedVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_labelInjectedVolume, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_labelInjectedVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_labelInjectedVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_labelInjectedVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_labelInjectedVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_labelInjectedVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_labelInjectedVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_3
	ui->MainScreen_label_3 = lv_label_create(ui->MainScreen_contMain);
	lv_label_set_text(ui->MainScreen_label_3, "Patient Weight:");
	lv_label_set_long_mode(ui->MainScreen_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_3, 18, 195);
	lv_obj_set_size(ui->MainScreen_label_3, 166, 22);

	//Write style for MainScreen_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_3, lv_color_hex(0x2195F6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_3, &lv_font_Acme_Regular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_3, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_4
	ui->MainScreen_label_4 = lv_label_create(ui->MainScreen_contMain);
	lv_label_set_text(ui->MainScreen_label_4, "Total:");
	lv_label_set_long_mode(ui->MainScreen_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_4, 18, 225);
	lv_obj_set_size(ui->MainScreen_label_4, 65, 19);

	//Write style for MainScreen_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_4, lv_color_hex(0x2195F6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_4, &lv_font_Acme_Regular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_4, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_5
	ui->MainScreen_label_5 = lv_label_create(ui->MainScreen_contMain);
	lv_label_set_text(ui->MainScreen_label_5, "Rem:");
	lv_label_set_long_mode(ui->MainScreen_label_5, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_5, 391, 195);
	lv_obj_set_size(ui->MainScreen_label_5, 52, 19);

	//Write style for MainScreen_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_5, lv_color_hex(0x2195F6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_5, &lv_font_Acme_Regular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_5, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_5, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_6
	ui->MainScreen_label_6 = lv_label_create(ui->MainScreen_contMain);
	lv_label_set_text(ui->MainScreen_label_6, "Time Left:");
	lv_label_set_long_mode(ui->MainScreen_label_6, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_6, 391, 225);
	lv_obj_set_size(ui->MainScreen_label_6, 110, 19);

	//Write style for MainScreen_label_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_6, lv_color_hex(0x2195F6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_6, &lv_font_Acme_Regular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_6, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_6, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_labelTimeLeft
	ui->MainScreen_labelTimeLeft = lv_label_create(ui->MainScreen_contMain);
	lv_label_set_text(ui->MainScreen_labelTimeLeft, "00:09:53");
	lv_label_set_long_mode(ui->MainScreen_labelTimeLeft, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_labelTimeLeft, 510, 225);
	lv_obj_set_size(ui->MainScreen_labelTimeLeft, 110, 19);

	//Write style for MainScreen_labelTimeLeft, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_labelTimeLeft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_labelTimeLeft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_labelTimeLeft, lv_color_hex(0x2195F6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_labelTimeLeft, &lv_font_Acme_Regular_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_labelTimeLeft, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_labelTimeLeft, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_labelTimeLeft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_labelTimeLeft, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_labelTimeLeft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_labelTimeLeft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_labelTimeLeft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_labelTimeLeft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_labelTimeLeft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_labelTimeLeft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_labelRemVolume
	ui->MainScreen_labelRemVolume = lv_label_create(ui->MainScreen_contMain);
	lv_label_set_text(ui->MainScreen_labelRemVolume, "180.0 ml");
	lv_label_set_long_mode(ui->MainScreen_labelRemVolume, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_labelRemVolume, 449, 195);
	lv_obj_set_size(ui->MainScreen_labelRemVolume, 100, 19);

	//Write style for MainScreen_labelRemVolume, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_labelRemVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_labelRemVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_labelRemVolume, lv_color_hex(0x2195F6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_labelRemVolume, &lv_font_Acme_Regular_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_labelRemVolume, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_labelRemVolume, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_labelRemVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_labelRemVolume, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_labelRemVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_labelRemVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_labelRemVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_labelRemVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_labelRemVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_labelRemVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_labelPatientKg
	ui->MainScreen_labelPatientKg = lv_label_create(ui->MainScreen_contMain);
	lv_label_set_text(ui->MainScreen_labelPatientKg, "120 kg");
	lv_label_set_long_mode(ui->MainScreen_labelPatientKg, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_labelPatientKg, 190, 195);
	lv_obj_set_size(ui->MainScreen_labelPatientKg, 76, 22);

	//Write style for MainScreen_labelPatientKg, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_labelPatientKg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_labelPatientKg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_labelPatientKg, lv_color_hex(0x2195F6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_labelPatientKg, &lv_font_Acme_Regular_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_labelPatientKg, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_labelPatientKg, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_labelPatientKg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_labelPatientKg, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_labelPatientKg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_labelPatientKg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_labelPatientKg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_labelPatientKg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_labelPatientKg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_labelPatientKg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_labelTotalVolume
	ui->MainScreen_labelTotalVolume = lv_label_create(ui->MainScreen_contMain);
	lv_label_set_text(ui->MainScreen_labelTotalVolume, "180.0 ml");
	lv_label_set_long_mode(ui->MainScreen_labelTotalVolume, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_labelTotalVolume, 88, 225);
	lv_obj_set_size(ui->MainScreen_labelTotalVolume, 100, 19);

	//Write style for MainScreen_labelTotalVolume, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_labelTotalVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_labelTotalVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_labelTotalVolume, lv_color_hex(0x2195F6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_labelTotalVolume, &lv_font_Acme_Regular_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_labelTotalVolume, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_labelTotalVolume, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_labelTotalVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_labelTotalVolume, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_labelTotalVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_labelTotalVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_labelTotalVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_labelTotalVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_labelTotalVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_labelTotalVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_btnGoMenuMain
	ui->MainScreen_btnGoMenuMain = lv_btn_create(ui->MainScreen_contMain);
	ui->MainScreen_btnGoMenuMain_label = lv_label_create(ui->MainScreen_btnGoMenuMain);
	lv_label_set_text(ui->MainScreen_btnGoMenuMain_label, "");
	lv_label_set_long_mode(ui->MainScreen_btnGoMenuMain_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->MainScreen_btnGoMenuMain_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->MainScreen_btnGoMenuMain, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->MainScreen_btnGoMenuMain_label, LV_PCT(100));
	lv_obj_set_pos(ui->MainScreen_btnGoMenuMain, 722, 247);
	lv_obj_set_size(ui->MainScreen_btnGoMenuMain, 58, 44);

	//Write style for MainScreen_btnGoMenuMain, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_btnGoMenuMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_btnGoMenuMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_btnGoMenuMain, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_btnGoMenuMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_btnGoMenuMain, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_btnGoMenuMain, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_btnGoMenuMain, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_btnGoMenuMain, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_contMenu
	ui->MainScreen_contMenu = lv_obj_create(ui->MainScreen);
	lv_obj_set_pos(ui->MainScreen_contMenu, 800, 80);
	lv_obj_set_size(ui->MainScreen_contMenu, 800, 300);
	lv_obj_set_scrollbar_mode(ui->MainScreen_contMenu, LV_SCROLLBAR_MODE_OFF);

	//Write style for MainScreen_contMenu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_contMenu, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->MainScreen_contMenu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->MainScreen_contMenu, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->MainScreen_contMenu, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_contMenu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_contMenu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_contMenu, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_contMenu, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_contMenu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_contMenu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_contMenu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_contMenu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_contMenu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_contMenuButtons
	ui->MainScreen_contMenuButtons = lv_obj_create(ui->MainScreen_contMenu);
	lv_obj_set_pos(ui->MainScreen_contMenuButtons, 0, 0);
	lv_obj_set_size(ui->MainScreen_contMenuButtons, 800, 300);
	lv_obj_set_scrollbar_mode(ui->MainScreen_contMenuButtons, LV_SCROLLBAR_MODE_OFF);

	//Write style for MainScreen_contMenuButtons, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_contMenuButtons, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_contMenuButtons, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_contMenuButtons, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_contMenuButtons, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_contMenuButtons, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_contMenuButtons, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_contMenuButtons, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_contMenuButtons, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_contMenuButtons, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_contMenuButtons, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_7
	ui->MainScreen_label_7 = lv_label_create(ui->MainScreen_contMenuButtons);
	lv_label_set_text(ui->MainScreen_label_7, "Syringe");
	lv_label_set_long_mode(ui->MainScreen_label_7, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_7, 25, 105);
	lv_obj_set_size(ui->MainScreen_label_7, 100, 50);

	//Write style for MainScreen_label_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_7, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_7, &lv_font_Acme_Regular_26, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_7, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_7, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_9
	ui->MainScreen_label_9 = lv_label_create(ui->MainScreen_contMenuButtons);
	lv_label_set_text(ui->MainScreen_label_9, "Drug");
	lv_label_set_long_mode(ui->MainScreen_label_9, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_9, 155, 105);
	lv_obj_set_size(ui->MainScreen_label_9, 100, 50);

	//Write style for MainScreen_label_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_9, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_9, &lv_font_Acme_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_9, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_9, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_9, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_10
	ui->MainScreen_label_10 = lv_label_create(ui->MainScreen_contMenuButtons);
	lv_label_set_text(ui->MainScreen_label_10, "Mode");
	lv_label_set_long_mode(ui->MainScreen_label_10, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_10, 285, 105);
	lv_obj_set_size(ui->MainScreen_label_10, 100, 50);

	//Write style for MainScreen_label_10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_10, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_10, &lv_font_Acme_Regular_28, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_10, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_10, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_10, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_11
	ui->MainScreen_label_11 = lv_label_create(ui->MainScreen_contMenuButtons);
	lv_label_set_text(ui->MainScreen_label_11, "OCC. Pressure");
	lv_label_set_long_mode(ui->MainScreen_label_11, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_11, 415, 105);
	lv_obj_set_size(ui->MainScreen_label_11, 100, 50);

	//Write style for MainScreen_label_11, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_11, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_11, &lv_font_Acme_Regular_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_11, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_11, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_11, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_12
	ui->MainScreen_label_12 = lv_label_create(ui->MainScreen_contMenuButtons);
	lv_label_set_text(ui->MainScreen_label_12, "KVO");
	lv_label_set_long_mode(ui->MainScreen_label_12, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_12, 545, 105);
	lv_obj_set_size(ui->MainScreen_label_12, 100, 50);

	//Write style for MainScreen_label_12, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_12, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_12, &lv_font_Acme_Regular_28, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_12, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_12, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_12, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_12, 11, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_13
	ui->MainScreen_label_13 = lv_label_create(ui->MainScreen_contMenuButtons);
	lv_label_set_text(ui->MainScreen_label_13, "Intermittent Infusion");
	lv_label_set_long_mode(ui->MainScreen_label_13, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_13, 668, 110);
	lv_obj_set_size(ui->MainScreen_label_13, 115, 50);

	//Write style for MainScreen_label_13, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_13, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_13, &lv_font_Acme_Regular_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_13, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_13, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_8
	ui->MainScreen_label_8 = lv_label_create(ui->MainScreen_contMenuButtons);
	lv_label_set_text(ui->MainScreen_label_8, "Rhythmic Infusion");
	lv_label_set_long_mode(ui->MainScreen_label_8, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_8, 25, 250);
	lv_obj_set_size(ui->MainScreen_label_8, 100, 50);

	//Write style for MainScreen_label_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_8, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_8, &lv_font_Acme_Regular_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_8, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_14
	ui->MainScreen_label_14 = lv_label_create(ui->MainScreen_contMenuButtons);
	lv_label_set_text(ui->MainScreen_label_14, "Nurse Call");
	lv_label_set_long_mode(ui->MainScreen_label_14, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_14, 155, 250);
	lv_obj_set_size(ui->MainScreen_label_14, 100, 50);

	//Write style for MainScreen_label_14, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_14, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_14, &lv_font_Acme_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_14, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_14, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_15
	ui->MainScreen_label_15 = lv_label_create(ui->MainScreen_contMenuButtons);
	lv_label_set_text(ui->MainScreen_label_15, "Bolus");
	lv_label_set_long_mode(ui->MainScreen_label_15, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_15, 285, 250);
	lv_obj_set_size(ui->MainScreen_label_15, 100, 50);

	//Write style for MainScreen_label_15, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_15, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_15, &lv_font_Acme_Regular_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_15, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_15, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_15, 11, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_16
	ui->MainScreen_label_16 = lv_label_create(ui->MainScreen_contMenuButtons);
	lv_label_set_text(ui->MainScreen_label_16, "Purge");
	lv_label_set_long_mode(ui->MainScreen_label_16, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_16, 415, 250);
	lv_obj_set_size(ui->MainScreen_label_16, 100, 50);

	//Write style for MainScreen_label_16, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_16, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_16, &lv_font_Acme_Regular_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_16, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_16, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_16, 11, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_17
	ui->MainScreen_label_17 = lv_label_create(ui->MainScreen_contMenuButtons);
	lv_label_set_text(ui->MainScreen_label_17, "Setting");
	lv_label_set_long_mode(ui->MainScreen_label_17, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_17, 544, 249);
	lv_obj_set_size(ui->MainScreen_label_17, 100, 50);

	//Write style for MainScreen_label_17, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_17, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_17, &lv_font_Acme_Regular_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_17, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_17, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_17, 11, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_btnMenuSyringe
	ui->MainScreen_btnMenuSyringe = lv_btn_create(ui->MainScreen_contMenuButtons);
	ui->MainScreen_btnMenuSyringe_label = lv_label_create(ui->MainScreen_btnMenuSyringe);
	lv_label_set_text(ui->MainScreen_btnMenuSyringe_label, "");
	lv_label_set_long_mode(ui->MainScreen_btnMenuSyringe_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->MainScreen_btnMenuSyringe_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->MainScreen_btnMenuSyringe, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->MainScreen_btnMenuSyringe_label, LV_PCT(100));
	lv_obj_set_pos(ui->MainScreen_btnMenuSyringe, 22, 5);
	lv_obj_set_size(ui->MainScreen_btnMenuSyringe, 100, 100);

	//Write style for MainScreen_btnMenuSyringe, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_btnMenuSyringe, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_btnMenuSyringe, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_btnMenuSyringe, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_btnMenuSyringe, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->MainScreen_btnMenuSyringe, &_Syringe_100_100x100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->MainScreen_btnMenuSyringe, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_btnMenuSyringe, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_btnMenuSyringe, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_btnMenuSyringe, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_btnMenuSyringe, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_btnMenuSyringe, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
	lv_obj_set_style_bg_opa(ui->MainScreen_btnMenuSyringe, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_color(ui->MainScreen_btnMenuSyringe, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_btnMenuSyringe, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_width(ui->MainScreen_btnMenuSyringe, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_radius(ui->MainScreen_btnMenuSyringe, 5, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_shadow_width(ui->MainScreen_btnMenuSyringe, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_img_src(ui->MainScreen_btnMenuSyringe, &_Syringe_100_100x100, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_img_opa(ui->MainScreen_btnMenuSyringe, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_color(ui->MainScreen_btnMenuSyringe, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->MainScreen_btnMenuSyringe, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_opa(ui->MainScreen_btnMenuSyringe, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write codes MainScreen_btnMenuDrug
	ui->MainScreen_btnMenuDrug = lv_btn_create(ui->MainScreen_contMenuButtons);
	ui->MainScreen_btnMenuDrug_label = lv_label_create(ui->MainScreen_btnMenuDrug);
	lv_label_set_text(ui->MainScreen_btnMenuDrug_label, "");
	lv_label_set_long_mode(ui->MainScreen_btnMenuDrug_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->MainScreen_btnMenuDrug_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->MainScreen_btnMenuDrug, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->MainScreen_btnMenuDrug_label, LV_PCT(100));
	lv_obj_set_pos(ui->MainScreen_btnMenuDrug, 155, 5);
	lv_obj_set_size(ui->MainScreen_btnMenuDrug, 100, 100);

	//Write style for MainScreen_btnMenuDrug, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_btnMenuDrug, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_btnMenuDrug, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_btnMenuDrug, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_btnMenuDrug, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->MainScreen_btnMenuDrug, &_Drug_100_100x100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->MainScreen_btnMenuDrug, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_btnMenuDrug, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_btnMenuDrug, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_btnMenuDrug, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_btnMenuDrug, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_btnMenuDrug, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
	lv_obj_set_style_bg_opa(ui->MainScreen_btnMenuDrug, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_color(ui->MainScreen_btnMenuDrug, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_btnMenuDrug, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_width(ui->MainScreen_btnMenuDrug, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_radius(ui->MainScreen_btnMenuDrug, 5, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_shadow_width(ui->MainScreen_btnMenuDrug, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_img_src(ui->MainScreen_btnMenuDrug, &_Drug_100_100x100, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_img_opa(ui->MainScreen_btnMenuDrug, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_color(ui->MainScreen_btnMenuDrug, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->MainScreen_btnMenuDrug, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_opa(ui->MainScreen_btnMenuDrug, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write codes MainScreen_btnMenuMode
	ui->MainScreen_btnMenuMode = lv_btn_create(ui->MainScreen_contMenuButtons);
	ui->MainScreen_btnMenuMode_label = lv_label_create(ui->MainScreen_btnMenuMode);
	lv_label_set_text(ui->MainScreen_btnMenuMode_label, "");
	lv_label_set_long_mode(ui->MainScreen_btnMenuMode_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->MainScreen_btnMenuMode_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->MainScreen_btnMenuMode, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->MainScreen_btnMenuMode_label, LV_PCT(100));
	lv_obj_set_pos(ui->MainScreen_btnMenuMode, 285, 5);
	lv_obj_set_size(ui->MainScreen_btnMenuMode, 100, 100);

	//Write style for MainScreen_btnMenuMode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_btnMenuMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_btnMenuMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_btnMenuMode, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_btnMenuMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->MainScreen_btnMenuMode, &_Mode_100_100x100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->MainScreen_btnMenuMode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_btnMenuMode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_btnMenuMode, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_btnMenuMode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_btnMenuMode, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_btnMenuMode, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
	lv_obj_set_style_bg_opa(ui->MainScreen_btnMenuMode, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_color(ui->MainScreen_btnMenuMode, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_btnMenuMode, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_width(ui->MainScreen_btnMenuMode, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_radius(ui->MainScreen_btnMenuMode, 5, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_shadow_width(ui->MainScreen_btnMenuMode, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_img_src(ui->MainScreen_btnMenuMode, &_Mode_100_100x100, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_img_opa(ui->MainScreen_btnMenuMode, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_color(ui->MainScreen_btnMenuMode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->MainScreen_btnMenuMode, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_opa(ui->MainScreen_btnMenuMode, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write codes MainScreen_btnMenuOCC
	ui->MainScreen_btnMenuOCC = lv_btn_create(ui->MainScreen_contMenuButtons);
	ui->MainScreen_btnMenuOCC_label = lv_label_create(ui->MainScreen_btnMenuOCC);
	lv_label_set_text(ui->MainScreen_btnMenuOCC_label, "");
	lv_label_set_long_mode(ui->MainScreen_btnMenuOCC_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->MainScreen_btnMenuOCC_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->MainScreen_btnMenuOCC, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->MainScreen_btnMenuOCC_label, LV_PCT(100));
	lv_obj_set_pos(ui->MainScreen_btnMenuOCC, 415, 5);
	lv_obj_set_size(ui->MainScreen_btnMenuOCC, 100, 100);

	//Write style for MainScreen_btnMenuOCC, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_btnMenuOCC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_btnMenuOCC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_btnMenuOCC, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_btnMenuOCC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->MainScreen_btnMenuOCC, &_OCC_100_100x100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->MainScreen_btnMenuOCC, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_btnMenuOCC, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_btnMenuOCC, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_btnMenuOCC, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_btnMenuOCC, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_btnMenuOCC, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
	lv_obj_set_style_bg_opa(ui->MainScreen_btnMenuOCC, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_color(ui->MainScreen_btnMenuOCC, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_btnMenuOCC, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_width(ui->MainScreen_btnMenuOCC, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_radius(ui->MainScreen_btnMenuOCC, 5, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_shadow_width(ui->MainScreen_btnMenuOCC, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_img_src(ui->MainScreen_btnMenuOCC, &_OCC_100_100x100, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_img_opa(ui->MainScreen_btnMenuOCC, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_color(ui->MainScreen_btnMenuOCC, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->MainScreen_btnMenuOCC, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_opa(ui->MainScreen_btnMenuOCC, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write codes MainScreen_btnMenuKVO
	ui->MainScreen_btnMenuKVO = lv_btn_create(ui->MainScreen_contMenuButtons);
	ui->MainScreen_btnMenuKVO_label = lv_label_create(ui->MainScreen_btnMenuKVO);
	lv_label_set_text(ui->MainScreen_btnMenuKVO_label, "");
	lv_label_set_long_mode(ui->MainScreen_btnMenuKVO_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->MainScreen_btnMenuKVO_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->MainScreen_btnMenuKVO, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->MainScreen_btnMenuKVO_label, LV_PCT(100));
	lv_obj_set_pos(ui->MainScreen_btnMenuKVO, 540, 5);
	lv_obj_set_size(ui->MainScreen_btnMenuKVO, 100, 100);

	//Write style for MainScreen_btnMenuKVO, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_btnMenuKVO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_btnMenuKVO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_btnMenuKVO, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_btnMenuKVO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->MainScreen_btnMenuKVO, &_KVO_100_100x100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->MainScreen_btnMenuKVO, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_btnMenuKVO, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_btnMenuKVO, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_btnMenuKVO, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_btnMenuKVO, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_btnMenuKVO, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
	lv_obj_set_style_bg_opa(ui->MainScreen_btnMenuKVO, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_color(ui->MainScreen_btnMenuKVO, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_btnMenuKVO, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_width(ui->MainScreen_btnMenuKVO, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_radius(ui->MainScreen_btnMenuKVO, 5, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_shadow_width(ui->MainScreen_btnMenuKVO, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_img_src(ui->MainScreen_btnMenuKVO, &_KVO_100_100x100, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_img_opa(ui->MainScreen_btnMenuKVO, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_color(ui->MainScreen_btnMenuKVO, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->MainScreen_btnMenuKVO, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_opa(ui->MainScreen_btnMenuKVO, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write codes MainScreen_btnMenuIntInf
	ui->MainScreen_btnMenuIntInf = lv_btn_create(ui->MainScreen_contMenuButtons);
	ui->MainScreen_btnMenuIntInf_label = lv_label_create(ui->MainScreen_btnMenuIntInf);
	lv_label_set_text(ui->MainScreen_btnMenuIntInf_label, "");
	lv_label_set_long_mode(ui->MainScreen_btnMenuIntInf_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->MainScreen_btnMenuIntInf_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->MainScreen_btnMenuIntInf, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->MainScreen_btnMenuIntInf_label, LV_PCT(100));
	lv_obj_set_pos(ui->MainScreen_btnMenuIntInf, 673, 5);
	lv_obj_set_size(ui->MainScreen_btnMenuIntInf, 100, 100);

	//Write style for MainScreen_btnMenuIntInf, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_btnMenuIntInf, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_btnMenuIntInf, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_btnMenuIntInf, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_btnMenuIntInf, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->MainScreen_btnMenuIntInf, &_Intermittent_100_100x100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->MainScreen_btnMenuIntInf, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_btnMenuIntInf, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_btnMenuIntInf, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_btnMenuIntInf, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_btnMenuIntInf, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_btnMenuIntInf, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
	lv_obj_set_style_bg_opa(ui->MainScreen_btnMenuIntInf, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_color(ui->MainScreen_btnMenuIntInf, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_btnMenuIntInf, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_width(ui->MainScreen_btnMenuIntInf, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_radius(ui->MainScreen_btnMenuIntInf, 5, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_shadow_width(ui->MainScreen_btnMenuIntInf, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_img_src(ui->MainScreen_btnMenuIntInf, &_Intermittent_100_100x100, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_img_opa(ui->MainScreen_btnMenuIntInf, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_color(ui->MainScreen_btnMenuIntInf, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->MainScreen_btnMenuIntInf, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_opa(ui->MainScreen_btnMenuIntInf, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write codes MainScreen_btnMenuRhyInf
	ui->MainScreen_btnMenuRhyInf = lv_btn_create(ui->MainScreen_contMenuButtons);
	ui->MainScreen_btnMenuRhyInf_label = lv_label_create(ui->MainScreen_btnMenuRhyInf);
	lv_label_set_text(ui->MainScreen_btnMenuRhyInf_label, "");
	lv_label_set_long_mode(ui->MainScreen_btnMenuRhyInf_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->MainScreen_btnMenuRhyInf_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->MainScreen_btnMenuRhyInf, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->MainScreen_btnMenuRhyInf_label, LV_PCT(100));
	lv_obj_set_pos(ui->MainScreen_btnMenuRhyInf, 25, 150);
	lv_obj_set_size(ui->MainScreen_btnMenuRhyInf, 100, 100);

	//Write style for MainScreen_btnMenuRhyInf, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_btnMenuRhyInf, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_btnMenuRhyInf, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_btnMenuRhyInf, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_btnMenuRhyInf, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->MainScreen_btnMenuRhyInf, &_Rhythmic_100_100x100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->MainScreen_btnMenuRhyInf, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_btnMenuRhyInf, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_btnMenuRhyInf, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_btnMenuRhyInf, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_btnMenuRhyInf, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_btnMenuRhyInf, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
	lv_obj_set_style_bg_opa(ui->MainScreen_btnMenuRhyInf, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_color(ui->MainScreen_btnMenuRhyInf, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_btnMenuRhyInf, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_width(ui->MainScreen_btnMenuRhyInf, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_radius(ui->MainScreen_btnMenuRhyInf, 5, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_shadow_width(ui->MainScreen_btnMenuRhyInf, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_img_src(ui->MainScreen_btnMenuRhyInf, &_Rhythmic_100_100x100, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_img_opa(ui->MainScreen_btnMenuRhyInf, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_color(ui->MainScreen_btnMenuRhyInf, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->MainScreen_btnMenuRhyInf, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_opa(ui->MainScreen_btnMenuRhyInf, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write codes MainScreen_btnMenuNurseCall
	ui->MainScreen_btnMenuNurseCall = lv_btn_create(ui->MainScreen_contMenuButtons);
	ui->MainScreen_btnMenuNurseCall_label = lv_label_create(ui->MainScreen_btnMenuNurseCall);
	lv_label_set_text(ui->MainScreen_btnMenuNurseCall_label, "");
	lv_label_set_long_mode(ui->MainScreen_btnMenuNurseCall_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->MainScreen_btnMenuNurseCall_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->MainScreen_btnMenuNurseCall, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->MainScreen_btnMenuNurseCall_label, LV_PCT(100));
	lv_obj_set_pos(ui->MainScreen_btnMenuNurseCall, 155, 150);
	lv_obj_set_size(ui->MainScreen_btnMenuNurseCall, 100, 100);

	//Write style for MainScreen_btnMenuNurseCall, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_btnMenuNurseCall, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_btnMenuNurseCall, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_btnMenuNurseCall, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_btnMenuNurseCall, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->MainScreen_btnMenuNurseCall, &_Nurse_100_100x100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->MainScreen_btnMenuNurseCall, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_btnMenuNurseCall, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_btnMenuNurseCall, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_btnMenuNurseCall, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_btnMenuNurseCall, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_btnMenuNurseCall, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
	lv_obj_set_style_bg_opa(ui->MainScreen_btnMenuNurseCall, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_color(ui->MainScreen_btnMenuNurseCall, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_btnMenuNurseCall, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_width(ui->MainScreen_btnMenuNurseCall, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_radius(ui->MainScreen_btnMenuNurseCall, 5, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_shadow_width(ui->MainScreen_btnMenuNurseCall, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_img_src(ui->MainScreen_btnMenuNurseCall, &_Nurse_100_100x100, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_img_opa(ui->MainScreen_btnMenuNurseCall, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_color(ui->MainScreen_btnMenuNurseCall, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->MainScreen_btnMenuNurseCall, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_opa(ui->MainScreen_btnMenuNurseCall, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write codes MainScreen_btnMenuBolus
	ui->MainScreen_btnMenuBolus = lv_btn_create(ui->MainScreen_contMenuButtons);
	ui->MainScreen_btnMenuBolus_label = lv_label_create(ui->MainScreen_btnMenuBolus);
	lv_label_set_text(ui->MainScreen_btnMenuBolus_label, "");
	lv_label_set_long_mode(ui->MainScreen_btnMenuBolus_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->MainScreen_btnMenuBolus_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->MainScreen_btnMenuBolus, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->MainScreen_btnMenuBolus_label, LV_PCT(100));
	lv_obj_set_pos(ui->MainScreen_btnMenuBolus, 285, 150);
	lv_obj_set_size(ui->MainScreen_btnMenuBolus, 100, 100);

	//Write style for MainScreen_btnMenuBolus, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_btnMenuBolus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_btnMenuBolus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_btnMenuBolus, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_btnMenuBolus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->MainScreen_btnMenuBolus, &_Bolus_100_100x100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->MainScreen_btnMenuBolus, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_btnMenuBolus, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_btnMenuBolus, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_btnMenuBolus, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_btnMenuBolus, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_btnMenuBolus, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
	lv_obj_set_style_bg_opa(ui->MainScreen_btnMenuBolus, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_color(ui->MainScreen_btnMenuBolus, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_btnMenuBolus, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_width(ui->MainScreen_btnMenuBolus, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_radius(ui->MainScreen_btnMenuBolus, 5, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_shadow_width(ui->MainScreen_btnMenuBolus, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_img_src(ui->MainScreen_btnMenuBolus, &_Bolus_100_100x100, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_img_opa(ui->MainScreen_btnMenuBolus, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_color(ui->MainScreen_btnMenuBolus, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->MainScreen_btnMenuBolus, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_opa(ui->MainScreen_btnMenuBolus, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write codes MainScreen_btnMenuPurge
	ui->MainScreen_btnMenuPurge = lv_btn_create(ui->MainScreen_contMenuButtons);
	ui->MainScreen_btnMenuPurge_label = lv_label_create(ui->MainScreen_btnMenuPurge);
	lv_label_set_text(ui->MainScreen_btnMenuPurge_label, "");
	lv_label_set_long_mode(ui->MainScreen_btnMenuPurge_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->MainScreen_btnMenuPurge_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->MainScreen_btnMenuPurge, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->MainScreen_btnMenuPurge_label, LV_PCT(100));
	lv_obj_set_pos(ui->MainScreen_btnMenuPurge, 415, 150);
	lv_obj_set_size(ui->MainScreen_btnMenuPurge, 100, 100);

	//Write style for MainScreen_btnMenuPurge, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_btnMenuPurge, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_btnMenuPurge, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_btnMenuPurge, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_btnMenuPurge, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->MainScreen_btnMenuPurge, &_Purge_100_100x100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->MainScreen_btnMenuPurge, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_btnMenuPurge, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_btnMenuPurge, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_btnMenuPurge, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_btnMenuPurge, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_btnMenuPurge, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
	lv_obj_set_style_bg_opa(ui->MainScreen_btnMenuPurge, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_color(ui->MainScreen_btnMenuPurge, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_btnMenuPurge, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_width(ui->MainScreen_btnMenuPurge, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_radius(ui->MainScreen_btnMenuPurge, 5, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_shadow_width(ui->MainScreen_btnMenuPurge, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_img_src(ui->MainScreen_btnMenuPurge, &_Purge_100_100x100, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_img_opa(ui->MainScreen_btnMenuPurge, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_color(ui->MainScreen_btnMenuPurge, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->MainScreen_btnMenuPurge, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_opa(ui->MainScreen_btnMenuPurge, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write codes MainScreen_btnMenuSetting
	ui->MainScreen_btnMenuSetting = lv_btn_create(ui->MainScreen_contMenuButtons);
	ui->MainScreen_btnMenuSetting_label = lv_label_create(ui->MainScreen_btnMenuSetting);
	lv_label_set_text(ui->MainScreen_btnMenuSetting_label, "");
	lv_label_set_long_mode(ui->MainScreen_btnMenuSetting_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->MainScreen_btnMenuSetting_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->MainScreen_btnMenuSetting, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->MainScreen_btnMenuSetting_label, LV_PCT(100));
	lv_obj_set_pos(ui->MainScreen_btnMenuSetting, 545, 150);
	lv_obj_set_size(ui->MainScreen_btnMenuSetting, 100, 100);

	//Write style for MainScreen_btnMenuSetting, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_btnMenuSetting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_btnMenuSetting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_btnMenuSetting, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_btnMenuSetting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->MainScreen_btnMenuSetting, &_Setting_100_100x100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->MainScreen_btnMenuSetting, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_btnMenuSetting, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_btnMenuSetting, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_btnMenuSetting, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_btnMenuSetting, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_btnMenuSetting, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
	lv_obj_set_style_bg_opa(ui->MainScreen_btnMenuSetting, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_color(ui->MainScreen_btnMenuSetting, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_btnMenuSetting, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_width(ui->MainScreen_btnMenuSetting, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_radius(ui->MainScreen_btnMenuSetting, 5, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_shadow_width(ui->MainScreen_btnMenuSetting, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_img_src(ui->MainScreen_btnMenuSetting, &_Setting_100_100x100, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_img_opa(ui->MainScreen_btnMenuSetting, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_color(ui->MainScreen_btnMenuSetting, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->MainScreen_btnMenuSetting, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_opa(ui->MainScreen_btnMenuSetting, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write codes MainScreen_btnGoMainMenu
	ui->MainScreen_btnGoMainMenu = lv_btn_create(ui->MainScreen_contMenu);
	ui->MainScreen_btnGoMainMenu_label = lv_label_create(ui->MainScreen_btnGoMainMenu);
	lv_label_set_text(ui->MainScreen_btnGoMainMenu_label, "");
	lv_label_set_long_mode(ui->MainScreen_btnGoMainMenu_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->MainScreen_btnGoMainMenu_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->MainScreen_btnGoMainMenu, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->MainScreen_btnGoMainMenu_label, LV_PCT(100));
	lv_obj_set_pos(ui->MainScreen_btnGoMainMenu, 732, 247);
	lv_obj_set_size(ui->MainScreen_btnGoMainMenu, 58, 44);

	//Write style for MainScreen_btnGoMainMenu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_btnGoMainMenu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_btnGoMainMenu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_btnGoMainMenu, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_btnGoMainMenu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_btnGoMainMenu, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_btnGoMainMenu, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_btnGoMainMenu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_btnGoMainMenu, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_contSyringe
	ui->MainScreen_contSyringe = lv_obj_create(ui->MainScreen);
	lv_obj_set_pos(ui->MainScreen_contSyringe, 800, 80);
	lv_obj_set_size(ui->MainScreen_contSyringe, 800, 300);
	lv_obj_set_scrollbar_mode(ui->MainScreen_contSyringe, LV_SCROLLBAR_MODE_OFF);

	//Write style for MainScreen_contSyringe, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_contSyringe, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->MainScreen_contSyringe, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->MainScreen_contSyringe, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->MainScreen_contSyringe, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_contSyringe, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_contSyringe, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_contSyringe, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_contSyringe, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_contSyringe, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_contSyringe, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_contSyringe, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_contSyringe, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_contSyringe, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_btnGoMenuSyringe
	ui->MainScreen_btnGoMenuSyringe = lv_btn_create(ui->MainScreen_contSyringe);
	ui->MainScreen_btnGoMenuSyringe_label = lv_label_create(ui->MainScreen_btnGoMenuSyringe);
	lv_label_set_text(ui->MainScreen_btnGoMenuSyringe_label, "");
	lv_label_set_long_mode(ui->MainScreen_btnGoMenuSyringe_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->MainScreen_btnGoMenuSyringe_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->MainScreen_btnGoMenuSyringe, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->MainScreen_btnGoMenuSyringe_label, LV_PCT(100));
	lv_obj_set_pos(ui->MainScreen_btnGoMenuSyringe, 733, 247);
	lv_obj_set_size(ui->MainScreen_btnGoMenuSyringe, 58, 44);

	//Write style for MainScreen_btnGoMenuSyringe, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_btnGoMenuSyringe, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_btnGoMenuSyringe, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_btnGoMenuSyringe, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_btnGoMenuSyringe, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_btnGoMenuSyringe, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_btnGoMenuSyringe, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_btnGoMenuSyringe, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_btnGoMenuSyringe, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_listSyringeCompany
	ui->MainScreen_listSyringeCompany = lv_list_create(ui->MainScreen_contSyringe);
	ui->MainScreen_listSyringeCompany_item0 = lv_list_add_btn(ui->MainScreen_listSyringeCompany, LV_SYMBOL_SAVE, "save_1");
	ui->MainScreen_listSyringeCompany_item1 = lv_list_add_btn(ui->MainScreen_listSyringeCompany, LV_SYMBOL_SAVE, "save_2");
	ui->MainScreen_listSyringeCompany_item2 = lv_list_add_btn(ui->MainScreen_listSyringeCompany, LV_SYMBOL_SAVE, "save_3");
	ui->MainScreen_listSyringeCompany_item3 = lv_list_add_btn(ui->MainScreen_listSyringeCompany, LV_SYMBOL_SAVE, "save_4");
	ui->MainScreen_listSyringeCompany_item4 = lv_list_add_btn(ui->MainScreen_listSyringeCompany, LV_SYMBOL_SAVE, "save_5");
	ui->MainScreen_listSyringeCompany_item5 = lv_list_add_btn(ui->MainScreen_listSyringeCompany, LV_SYMBOL_SAVE, "save_6");
	ui->MainScreen_listSyringeCompany_item6 = lv_list_add_btn(ui->MainScreen_listSyringeCompany, LV_SYMBOL_SAVE, "save_7");
	ui->MainScreen_listSyringeCompany_item7 = lv_list_add_btn(ui->MainScreen_listSyringeCompany, LV_SYMBOL_SAVE, "save_8");
	ui->MainScreen_listSyringeCompany_item8 = lv_list_add_btn(ui->MainScreen_listSyringeCompany, LV_SYMBOL_SAVE, "save_9");
	ui->MainScreen_listSyringeCompany_item9 = lv_list_add_btn(ui->MainScreen_listSyringeCompany, LV_SYMBOL_SAVE, "save_10");
	ui->MainScreen_listSyringeCompany_item10 = lv_list_add_btn(ui->MainScreen_listSyringeCompany, LV_SYMBOL_SAVE, "save_11");
	ui->MainScreen_listSyringeCompany_item11 = lv_list_add_btn(ui->MainScreen_listSyringeCompany, LV_SYMBOL_SAVE, "save_12");
	ui->MainScreen_listSyringeCompany_item12 = lv_list_add_btn(ui->MainScreen_listSyringeCompany, LV_SYMBOL_SAVE, "save_13");
	ui->MainScreen_listSyringeCompany_item13 = lv_list_add_btn(ui->MainScreen_listSyringeCompany, LV_SYMBOL_SAVE, "save_14");
	ui->MainScreen_listSyringeCompany_item14 = lv_list_add_btn(ui->MainScreen_listSyringeCompany, LV_SYMBOL_SAVE, "save_15");
	ui->MainScreen_listSyringeCompany_item15 = lv_list_add_btn(ui->MainScreen_listSyringeCompany, LV_SYMBOL_SAVE, "save_16");
	ui->MainScreen_listSyringeCompany_item16 = lv_list_add_btn(ui->MainScreen_listSyringeCompany, LV_SYMBOL_SAVE, "save_17");
	ui->MainScreen_listSyringeCompany_item17 = lv_list_add_btn(ui->MainScreen_listSyringeCompany, LV_SYMBOL_SAVE, "save_18");
	ui->MainScreen_listSyringeCompany_item18 = lv_list_add_btn(ui->MainScreen_listSyringeCompany, LV_SYMBOL_SAVE, "save_19");
	ui->MainScreen_listSyringeCompany_item19 = lv_list_add_btn(ui->MainScreen_listSyringeCompany, LV_SYMBOL_SAVE, "save_20");
	ui->MainScreen_listSyringeCompany_item20 = lv_list_add_btn(ui->MainScreen_listSyringeCompany, LV_SYMBOL_SAVE, "save_21");
	ui->MainScreen_listSyringeCompany_item21 = lv_list_add_btn(ui->MainScreen_listSyringeCompany, LV_SYMBOL_SAVE, "save_22");
	ui->MainScreen_listSyringeCompany_item22 = lv_list_add_btn(ui->MainScreen_listSyringeCompany, LV_SYMBOL_SAVE, "save_23");
	ui->MainScreen_listSyringeCompany_item23 = lv_list_add_btn(ui->MainScreen_listSyringeCompany, LV_SYMBOL_SAVE, "save_24");
	ui->MainScreen_listSyringeCompany_item24 = lv_list_add_btn(ui->MainScreen_listSyringeCompany, LV_SYMBOL_SAVE, "save_25");
	ui->MainScreen_listSyringeCompany_item25 = lv_list_add_btn(ui->MainScreen_listSyringeCompany, LV_SYMBOL_SAVE, "save_26");
	ui->MainScreen_listSyringeCompany_item26 = lv_list_add_btn(ui->MainScreen_listSyringeCompany, LV_SYMBOL_SAVE, "save_27");
	ui->MainScreen_listSyringeCompany_item27 = lv_list_add_btn(ui->MainScreen_listSyringeCompany, LV_SYMBOL_SAVE, "save_28");
	ui->MainScreen_listSyringeCompany_item28 = lv_list_add_btn(ui->MainScreen_listSyringeCompany, LV_SYMBOL_SAVE, "save_29");
	ui->MainScreen_listSyringeCompany_item29 = lv_list_add_btn(ui->MainScreen_listSyringeCompany, LV_SYMBOL_SAVE, "save_30");
	ui->MainScreen_listSyringeCompany_item30 = lv_list_add_btn(ui->MainScreen_listSyringeCompany, LV_SYMBOL_SAVE, "save_31");
	ui->MainScreen_listSyringeCompany_item31 = lv_list_add_btn(ui->MainScreen_listSyringeCompany, LV_SYMBOL_SAVE, "save_32");
	ui->MainScreen_listSyringeCompany_item32 = lv_list_add_btn(ui->MainScreen_listSyringeCompany, LV_SYMBOL_SAVE, "save_33");
	ui->MainScreen_listSyringeCompany_item33 = lv_list_add_btn(ui->MainScreen_listSyringeCompany, LV_SYMBOL_SAVE, "save_34");
	ui->MainScreen_listSyringeCompany_item34 = lv_list_add_btn(ui->MainScreen_listSyringeCompany, LV_SYMBOL_SAVE, "save_35");
	ui->MainScreen_listSyringeCompany_item35 = lv_list_add_btn(ui->MainScreen_listSyringeCompany, LV_SYMBOL_SAVE, "save_36");
	ui->MainScreen_listSyringeCompany_item36 = lv_list_add_btn(ui->MainScreen_listSyringeCompany, LV_SYMBOL_SAVE, "save_37");
	ui->MainScreen_listSyringeCompany_item37 = lv_list_add_btn(ui->MainScreen_listSyringeCompany, LV_SYMBOL_SAVE, "save_38");
	ui->MainScreen_listSyringeCompany_item38 = lv_list_add_btn(ui->MainScreen_listSyringeCompany, LV_SYMBOL_SAVE, "save_39");
	ui->MainScreen_listSyringeCompany_item39 = lv_list_add_btn(ui->MainScreen_listSyringeCompany, LV_SYMBOL_SAVE, "save_40");
	ui->MainScreen_listSyringeCompany_item40 = lv_list_add_btn(ui->MainScreen_listSyringeCompany, LV_SYMBOL_SAVE, "save_41");
	ui->MainScreen_listSyringeCompany_item41 = lv_list_add_btn(ui->MainScreen_listSyringeCompany, LV_SYMBOL_SAVE, "save_42");
	ui->MainScreen_listSyringeCompany_item42 = lv_list_add_btn(ui->MainScreen_listSyringeCompany, LV_SYMBOL_SAVE, "save_43");
	ui->MainScreen_listSyringeCompany_item43 = lv_list_add_btn(ui->MainScreen_listSyringeCompany, LV_SYMBOL_SAVE, "save_44");
	ui->MainScreen_listSyringeCompany_item44 = lv_list_add_btn(ui->MainScreen_listSyringeCompany, LV_SYMBOL_SAVE, "save_45");
	ui->MainScreen_listSyringeCompany_item45 = lv_list_add_btn(ui->MainScreen_listSyringeCompany, LV_SYMBOL_SAVE, "save_46");
	ui->MainScreen_listSyringeCompany_item46 = lv_list_add_btn(ui->MainScreen_listSyringeCompany, LV_SYMBOL_SAVE, "save_47");
	ui->MainScreen_listSyringeCompany_item47 = lv_list_add_btn(ui->MainScreen_listSyringeCompany, LV_SYMBOL_SAVE, "save_48");
	ui->MainScreen_listSyringeCompany_item48 = lv_list_add_btn(ui->MainScreen_listSyringeCompany, LV_SYMBOL_SAVE, "save_49");
	ui->MainScreen_listSyringeCompany_item49 = lv_list_add_btn(ui->MainScreen_listSyringeCompany, LV_SYMBOL_SAVE, "save_50");
	lv_obj_set_pos(ui->MainScreen_listSyringeCompany, 0, 29);
	lv_obj_set_size(ui->MainScreen_listSyringeCompany, 399, 140);
	lv_obj_set_scrollbar_mode(ui->MainScreen_listSyringeCompany, LV_SCROLLBAR_MODE_AUTO);

	//Write style state: LV_STATE_DEFAULT for &style_MainScreen_listSyringeCompany_main_main_default
	static lv_style_t style_MainScreen_listSyringeCompany_main_main_default;
	ui_init_style(&style_MainScreen_listSyringeCompany_main_main_default);
	
	lv_style_set_pad_top(&style_MainScreen_listSyringeCompany_main_main_default, 0);
	lv_style_set_pad_left(&style_MainScreen_listSyringeCompany_main_main_default, 0);
	lv_style_set_pad_right(&style_MainScreen_listSyringeCompany_main_main_default, 0);
	lv_style_set_pad_bottom(&style_MainScreen_listSyringeCompany_main_main_default, 0);
	lv_style_set_bg_opa(&style_MainScreen_listSyringeCompany_main_main_default, 255);
	lv_style_set_bg_color(&style_MainScreen_listSyringeCompany_main_main_default, lv_color_hex(0x000000));
	lv_style_set_bg_grad_dir(&style_MainScreen_listSyringeCompany_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_border_width(&style_MainScreen_listSyringeCompany_main_main_default, 2);
	lv_style_set_border_opa(&style_MainScreen_listSyringeCompany_main_main_default, 255);
	lv_style_set_border_color(&style_MainScreen_listSyringeCompany_main_main_default, lv_color_hex(0x008dff));
	lv_style_set_border_side(&style_MainScreen_listSyringeCompany_main_main_default, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_MainScreen_listSyringeCompany_main_main_default, 0);
	lv_style_set_shadow_width(&style_MainScreen_listSyringeCompany_main_main_default, 0);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany, &style_MainScreen_listSyringeCompany_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_MainScreen_listSyringeCompany_main_scrollbar_default
	static lv_style_t style_MainScreen_listSyringeCompany_main_scrollbar_default;
	ui_init_style(&style_MainScreen_listSyringeCompany_main_scrollbar_default);
	
	lv_style_set_radius(&style_MainScreen_listSyringeCompany_main_scrollbar_default, 3);
	lv_style_set_bg_opa(&style_MainScreen_listSyringeCompany_main_scrollbar_default, 255);
	lv_style_set_bg_color(&style_MainScreen_listSyringeCompany_main_scrollbar_default, lv_color_hex(0x9e9e9e));
	lv_style_set_bg_grad_dir(&style_MainScreen_listSyringeCompany_main_scrollbar_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany, &style_MainScreen_listSyringeCompany_main_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_MainScreen_listSyringeCompany_extra_btns_main_default
	static lv_style_t style_MainScreen_listSyringeCompany_extra_btns_main_default;
	ui_init_style(&style_MainScreen_listSyringeCompany_extra_btns_main_default);
	
	lv_style_set_pad_top(&style_MainScreen_listSyringeCompany_extra_btns_main_default, 2);
	lv_style_set_pad_left(&style_MainScreen_listSyringeCompany_extra_btns_main_default, 2);
	lv_style_set_pad_right(&style_MainScreen_listSyringeCompany_extra_btns_main_default, 2);
	lv_style_set_pad_bottom(&style_MainScreen_listSyringeCompany_extra_btns_main_default, 2);
	lv_style_set_border_width(&style_MainScreen_listSyringeCompany_extra_btns_main_default, 0);
	lv_style_set_text_color(&style_MainScreen_listSyringeCompany_extra_btns_main_default, lv_color_hex(0xffffff));
	lv_style_set_text_font(&style_MainScreen_listSyringeCompany_extra_btns_main_default, &lv_font_Alatsi_Regular_19);
	lv_style_set_text_opa(&style_MainScreen_listSyringeCompany_extra_btns_main_default, 255);
	lv_style_set_radius(&style_MainScreen_listSyringeCompany_extra_btns_main_default, 3);
	lv_style_set_bg_opa(&style_MainScreen_listSyringeCompany_extra_btns_main_default, 255);
	lv_style_set_bg_color(&style_MainScreen_listSyringeCompany_extra_btns_main_default, lv_color_hex(0x000000));
	lv_style_set_bg_grad_dir(&style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item49, &style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item48, &style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item47, &style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item46, &style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item45, &style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item44, &style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item43, &style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item42, &style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item41, &style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item40, &style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item39, &style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item38, &style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item37, &style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item36, &style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item35, &style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item34, &style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item33, &style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item32, &style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item31, &style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item30, &style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item29, &style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item28, &style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item27, &style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item26, &style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item25, &style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item24, &style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item23, &style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item22, &style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item21, &style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item20, &style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item19, &style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item18, &style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item17, &style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item16, &style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item15, &style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item14, &style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item13, &style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item12, &style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item11, &style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item10, &style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item9, &style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item8, &style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item7, &style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item6, &style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item5, &style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item4, &style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item3, &style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item2, &style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item1, &style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item0, &style_MainScreen_listSyringeCompany_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_FOCUSED for &style_MainScreen_listSyringeCompany_extra_btns_main_focused
	static lv_style_t style_MainScreen_listSyringeCompany_extra_btns_main_focused;
	ui_init_style(&style_MainScreen_listSyringeCompany_extra_btns_main_focused);
	
	lv_style_set_pad_top(&style_MainScreen_listSyringeCompany_extra_btns_main_focused, 2);
	lv_style_set_pad_left(&style_MainScreen_listSyringeCompany_extra_btns_main_focused, 2);
	lv_style_set_pad_right(&style_MainScreen_listSyringeCompany_extra_btns_main_focused, 2);
	lv_style_set_pad_bottom(&style_MainScreen_listSyringeCompany_extra_btns_main_focused, 2);
	lv_style_set_border_width(&style_MainScreen_listSyringeCompany_extra_btns_main_focused, 0);
	lv_style_set_radius(&style_MainScreen_listSyringeCompany_extra_btns_main_focused, 3);
	lv_style_set_text_color(&style_MainScreen_listSyringeCompany_extra_btns_main_focused, lv_color_hex(0xffffff));
	lv_style_set_text_font(&style_MainScreen_listSyringeCompany_extra_btns_main_focused, &lv_font_Alatsi_Regular_19);
	lv_style_set_text_opa(&style_MainScreen_listSyringeCompany_extra_btns_main_focused, 255);
	lv_style_set_bg_opa(&style_MainScreen_listSyringeCompany_extra_btns_main_focused, 255);
	lv_style_set_bg_color(&style_MainScreen_listSyringeCompany_extra_btns_main_focused, lv_color_hex(0x0016ff));
	lv_style_set_bg_grad_dir(&style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_GRAD_DIR_NONE);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item49, &style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item48, &style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item47, &style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item46, &style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item45, &style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item44, &style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item43, &style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item42, &style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item41, &style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item40, &style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item39, &style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item38, &style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item37, &style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item36, &style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item35, &style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item34, &style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item33, &style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item32, &style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item31, &style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item30, &style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item29, &style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item28, &style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item27, &style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item26, &style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item25, &style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item24, &style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item23, &style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item22, &style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item21, &style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item20, &style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item19, &style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item18, &style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item17, &style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item16, &style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item15, &style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item14, &style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item13, &style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item12, &style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item11, &style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item10, &style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item9, &style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item8, &style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item7, &style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item6, &style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item5, &style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item4, &style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item3, &style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item2, &style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item1, &style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeCompany_item0, &style_MainScreen_listSyringeCompany_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write codes MainScreen_listSyringeType
	ui->MainScreen_listSyringeType = lv_list_create(ui->MainScreen_contSyringe);
	ui->MainScreen_listSyringeType_item0 = lv_list_add_btn(ui->MainScreen_listSyringeType, LV_SYMBOL_SAVE, "save_1");
	ui->MainScreen_listSyringeType_item1 = lv_list_add_btn(ui->MainScreen_listSyringeType, LV_SYMBOL_SAVE, "save_2");
	ui->MainScreen_listSyringeType_item2 = lv_list_add_btn(ui->MainScreen_listSyringeType, LV_SYMBOL_SAVE, "save_3");
	ui->MainScreen_listSyringeType_item3 = lv_list_add_btn(ui->MainScreen_listSyringeType, LV_SYMBOL_SAVE, "save_4");
	ui->MainScreen_listSyringeType_item4 = lv_list_add_btn(ui->MainScreen_listSyringeType, LV_SYMBOL_SAVE, "save_5");
	ui->MainScreen_listSyringeType_item5 = lv_list_add_btn(ui->MainScreen_listSyringeType, LV_SYMBOL_SAVE, "save_6");
	ui->MainScreen_listSyringeType_item6 = lv_list_add_btn(ui->MainScreen_listSyringeType, LV_SYMBOL_SAVE, "save_7");
	ui->MainScreen_listSyringeType_item7 = lv_list_add_btn(ui->MainScreen_listSyringeType, LV_SYMBOL_SAVE, "save_8");
	ui->MainScreen_listSyringeType_item8 = lv_list_add_btn(ui->MainScreen_listSyringeType, LV_SYMBOL_SAVE, "save_9");
	ui->MainScreen_listSyringeType_item9 = lv_list_add_btn(ui->MainScreen_listSyringeType, LV_SYMBOL_SAVE, "save_10");
	ui->MainScreen_listSyringeType_item10 = lv_list_add_btn(ui->MainScreen_listSyringeType, LV_SYMBOL_SAVE, "save_11");
	ui->MainScreen_listSyringeType_item11 = lv_list_add_btn(ui->MainScreen_listSyringeType, LV_SYMBOL_SAVE, "save_12");
	ui->MainScreen_listSyringeType_item12 = lv_list_add_btn(ui->MainScreen_listSyringeType, LV_SYMBOL_SAVE, "save_13");
	ui->MainScreen_listSyringeType_item13 = lv_list_add_btn(ui->MainScreen_listSyringeType, LV_SYMBOL_SAVE, "save_14");
	ui->MainScreen_listSyringeType_item14 = lv_list_add_btn(ui->MainScreen_listSyringeType, LV_SYMBOL_SAVE, "save_15");
	ui->MainScreen_listSyringeType_item15 = lv_list_add_btn(ui->MainScreen_listSyringeType, LV_SYMBOL_SAVE, "save_16");
	ui->MainScreen_listSyringeType_item16 = lv_list_add_btn(ui->MainScreen_listSyringeType, LV_SYMBOL_SAVE, "save_17");
	ui->MainScreen_listSyringeType_item17 = lv_list_add_btn(ui->MainScreen_listSyringeType, LV_SYMBOL_SAVE, "save_18");
	ui->MainScreen_listSyringeType_item18 = lv_list_add_btn(ui->MainScreen_listSyringeType, LV_SYMBOL_SAVE, "save_19");
	ui->MainScreen_listSyringeType_item19 = lv_list_add_btn(ui->MainScreen_listSyringeType, LV_SYMBOL_SAVE, "save_20");
	lv_obj_set_pos(ui->MainScreen_listSyringeType, 395, 29);
	lv_obj_set_size(ui->MainScreen_listSyringeType, 400, 140);
	lv_obj_set_scrollbar_mode(ui->MainScreen_listSyringeType, LV_SCROLLBAR_MODE_AUTO);

	//Write style state: LV_STATE_DEFAULT for &style_MainScreen_listSyringeType_main_main_default
	static lv_style_t style_MainScreen_listSyringeType_main_main_default;
	ui_init_style(&style_MainScreen_listSyringeType_main_main_default);
	
	lv_style_set_pad_top(&style_MainScreen_listSyringeType_main_main_default, 0);
	lv_style_set_pad_left(&style_MainScreen_listSyringeType_main_main_default, 0);
	lv_style_set_pad_right(&style_MainScreen_listSyringeType_main_main_default, 0);
	lv_style_set_pad_bottom(&style_MainScreen_listSyringeType_main_main_default, 0);
	lv_style_set_bg_opa(&style_MainScreen_listSyringeType_main_main_default, 255);
	lv_style_set_bg_color(&style_MainScreen_listSyringeType_main_main_default, lv_color_hex(0x000000));
	lv_style_set_bg_grad_dir(&style_MainScreen_listSyringeType_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_border_width(&style_MainScreen_listSyringeType_main_main_default, 2);
	lv_style_set_border_opa(&style_MainScreen_listSyringeType_main_main_default, 255);
	lv_style_set_border_color(&style_MainScreen_listSyringeType_main_main_default, lv_color_hex(0x008dff));
	lv_style_set_border_side(&style_MainScreen_listSyringeType_main_main_default, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_MainScreen_listSyringeType_main_main_default, 0);
	lv_style_set_shadow_width(&style_MainScreen_listSyringeType_main_main_default, 0);
	lv_obj_add_style(ui->MainScreen_listSyringeType, &style_MainScreen_listSyringeType_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_MainScreen_listSyringeType_main_scrollbar_default
	static lv_style_t style_MainScreen_listSyringeType_main_scrollbar_default;
	ui_init_style(&style_MainScreen_listSyringeType_main_scrollbar_default);
	
	lv_style_set_radius(&style_MainScreen_listSyringeType_main_scrollbar_default, 3);
	lv_style_set_bg_opa(&style_MainScreen_listSyringeType_main_scrollbar_default, 255);
	lv_style_set_bg_color(&style_MainScreen_listSyringeType_main_scrollbar_default, lv_color_hex(0x9e9e9e));
	lv_style_set_bg_grad_dir(&style_MainScreen_listSyringeType_main_scrollbar_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(ui->MainScreen_listSyringeType, &style_MainScreen_listSyringeType_main_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_MainScreen_listSyringeType_extra_btns_main_default
	static lv_style_t style_MainScreen_listSyringeType_extra_btns_main_default;
	ui_init_style(&style_MainScreen_listSyringeType_extra_btns_main_default);
	
	lv_style_set_pad_top(&style_MainScreen_listSyringeType_extra_btns_main_default, 2);
	lv_style_set_pad_left(&style_MainScreen_listSyringeType_extra_btns_main_default, 2);
	lv_style_set_pad_right(&style_MainScreen_listSyringeType_extra_btns_main_default, 2);
	lv_style_set_pad_bottom(&style_MainScreen_listSyringeType_extra_btns_main_default, 2);
	lv_style_set_border_width(&style_MainScreen_listSyringeType_extra_btns_main_default, 0);
	lv_style_set_text_color(&style_MainScreen_listSyringeType_extra_btns_main_default, lv_color_hex(0xffffff));
	lv_style_set_text_font(&style_MainScreen_listSyringeType_extra_btns_main_default, &lv_font_Alatsi_Regular_19);
	lv_style_set_text_opa(&style_MainScreen_listSyringeType_extra_btns_main_default, 255);
	lv_style_set_radius(&style_MainScreen_listSyringeType_extra_btns_main_default, 3);
	lv_style_set_bg_opa(&style_MainScreen_listSyringeType_extra_btns_main_default, 255);
	lv_style_set_bg_color(&style_MainScreen_listSyringeType_extra_btns_main_default, lv_color_hex(0x000000));
	lv_style_set_bg_grad_dir(&style_MainScreen_listSyringeType_extra_btns_main_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(ui->MainScreen_listSyringeType_item19, &style_MainScreen_listSyringeType_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeType_item18, &style_MainScreen_listSyringeType_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeType_item17, &style_MainScreen_listSyringeType_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeType_item16, &style_MainScreen_listSyringeType_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeType_item15, &style_MainScreen_listSyringeType_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeType_item14, &style_MainScreen_listSyringeType_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeType_item13, &style_MainScreen_listSyringeType_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeType_item12, &style_MainScreen_listSyringeType_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeType_item11, &style_MainScreen_listSyringeType_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeType_item10, &style_MainScreen_listSyringeType_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeType_item9, &style_MainScreen_listSyringeType_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeType_item8, &style_MainScreen_listSyringeType_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeType_item7, &style_MainScreen_listSyringeType_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeType_item6, &style_MainScreen_listSyringeType_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeType_item5, &style_MainScreen_listSyringeType_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeType_item4, &style_MainScreen_listSyringeType_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeType_item3, &style_MainScreen_listSyringeType_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeType_item2, &style_MainScreen_listSyringeType_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeType_item1, &style_MainScreen_listSyringeType_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listSyringeType_item0, &style_MainScreen_listSyringeType_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_FOCUSED for &style_MainScreen_listSyringeType_extra_btns_main_focused
	static lv_style_t style_MainScreen_listSyringeType_extra_btns_main_focused;
	ui_init_style(&style_MainScreen_listSyringeType_extra_btns_main_focused);
	
	lv_style_set_pad_top(&style_MainScreen_listSyringeType_extra_btns_main_focused, 2);
	lv_style_set_pad_left(&style_MainScreen_listSyringeType_extra_btns_main_focused, 2);
	lv_style_set_pad_right(&style_MainScreen_listSyringeType_extra_btns_main_focused, 2);
	lv_style_set_pad_bottom(&style_MainScreen_listSyringeType_extra_btns_main_focused, 2);
	lv_style_set_border_width(&style_MainScreen_listSyringeType_extra_btns_main_focused, 0);
	lv_style_set_radius(&style_MainScreen_listSyringeType_extra_btns_main_focused, 3);
	lv_style_set_text_color(&style_MainScreen_listSyringeType_extra_btns_main_focused, lv_color_hex(0xffffff));
	lv_style_set_text_font(&style_MainScreen_listSyringeType_extra_btns_main_focused, &lv_font_Alatsi_Regular_19);
	lv_style_set_text_opa(&style_MainScreen_listSyringeType_extra_btns_main_focused, 255);
	lv_style_set_bg_opa(&style_MainScreen_listSyringeType_extra_btns_main_focused, 255);
	lv_style_set_bg_color(&style_MainScreen_listSyringeType_extra_btns_main_focused, lv_color_hex(0x0016ff));
	lv_style_set_bg_grad_dir(&style_MainScreen_listSyringeType_extra_btns_main_focused, LV_GRAD_DIR_NONE);
	lv_obj_add_style(ui->MainScreen_listSyringeType_item19, &style_MainScreen_listSyringeType_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeType_item18, &style_MainScreen_listSyringeType_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeType_item17, &style_MainScreen_listSyringeType_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeType_item16, &style_MainScreen_listSyringeType_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeType_item15, &style_MainScreen_listSyringeType_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeType_item14, &style_MainScreen_listSyringeType_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeType_item13, &style_MainScreen_listSyringeType_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeType_item12, &style_MainScreen_listSyringeType_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeType_item11, &style_MainScreen_listSyringeType_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeType_item10, &style_MainScreen_listSyringeType_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeType_item9, &style_MainScreen_listSyringeType_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeType_item8, &style_MainScreen_listSyringeType_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeType_item7, &style_MainScreen_listSyringeType_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeType_item6, &style_MainScreen_listSyringeType_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeType_item5, &style_MainScreen_listSyringeType_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeType_item4, &style_MainScreen_listSyringeType_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeType_item3, &style_MainScreen_listSyringeType_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeType_item2, &style_MainScreen_listSyringeType_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeType_item1, &style_MainScreen_listSyringeType_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listSyringeType_item0, &style_MainScreen_listSyringeType_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write style state: LV_STATE_DEFAULT for &style_MainScreen_listSyringeType_extra_texts_main_default
	static lv_style_t style_MainScreen_listSyringeType_extra_texts_main_default;
	ui_init_style(&style_MainScreen_listSyringeType_extra_texts_main_default);
	
	lv_style_set_pad_top(&style_MainScreen_listSyringeType_extra_texts_main_default, 5);
	lv_style_set_pad_left(&style_MainScreen_listSyringeType_extra_texts_main_default, 5);
	lv_style_set_pad_right(&style_MainScreen_listSyringeType_extra_texts_main_default, 5);
	lv_style_set_pad_bottom(&style_MainScreen_listSyringeType_extra_texts_main_default, 5);
	lv_style_set_border_width(&style_MainScreen_listSyringeType_extra_texts_main_default, 0);
	lv_style_set_text_color(&style_MainScreen_listSyringeType_extra_texts_main_default, lv_color_hex(0xffffff));
	lv_style_set_text_font(&style_MainScreen_listSyringeType_extra_texts_main_default, &lv_font_arial_14);
	lv_style_set_text_opa(&style_MainScreen_listSyringeType_extra_texts_main_default, 255);
	lv_style_set_radius(&style_MainScreen_listSyringeType_extra_texts_main_default, 3);
	lv_style_set_bg_opa(&style_MainScreen_listSyringeType_extra_texts_main_default, 255);
	lv_style_set_bg_color(&style_MainScreen_listSyringeType_extra_texts_main_default, lv_color_hex(0x000000));
	lv_style_set_bg_grad_dir(&style_MainScreen_listSyringeType_extra_texts_main_default, LV_GRAD_DIR_NONE);

	//Write codes MainScreen_contSyringeValues
	ui->MainScreen_contSyringeValues = lv_obj_create(ui->MainScreen_contSyringe);
	lv_obj_set_pos(ui->MainScreen_contSyringeValues, 0, 170);
	lv_obj_set_size(ui->MainScreen_contSyringeValues, 740, 128);
	lv_obj_set_scrollbar_mode(ui->MainScreen_contSyringeValues, LV_SCROLLBAR_MODE_OFF);

	//Write style for MainScreen_contSyringeValues, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_contSyringeValues, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_contSyringeValues, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_contSyringeValues, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_contSyringeValues, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_contSyringeValues, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_contSyringeValues, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_contSyringeValues, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_contSyringeValues, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_contSyringeValues, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_contSyringeValues, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_labelSyringeNameValue
	ui->MainScreen_labelSyringeNameValue = lv_label_create(ui->MainScreen_contSyringeValues);
	lv_label_set_text(ui->MainScreen_labelSyringeNameValue, "Name:");
	lv_label_set_long_mode(ui->MainScreen_labelSyringeNameValue, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_labelSyringeNameValue, 0, 0);
	lv_obj_set_size(ui->MainScreen_labelSyringeNameValue, 70, 25);

	//Write style for MainScreen_labelSyringeNameValue, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_labelSyringeNameValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_labelSyringeNameValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_labelSyringeNameValue, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_labelSyringeNameValue, &lv_font_Alatsi_Regular_19, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_labelSyringeNameValue, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_labelSyringeNameValue, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_labelSyringeNameValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_labelSyringeNameValue, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_labelSyringeNameValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_labelSyringeNameValue, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_labelSyringeNameValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_labelSyringeNameValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_labelSyringeNameValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_labelSyringeNameValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_labelSyringeVolumeValue
	ui->MainScreen_labelSyringeVolumeValue = lv_label_create(ui->MainScreen_contSyringeValues);
	lv_label_set_text(ui->MainScreen_labelSyringeVolumeValue, "Volume:");
	lv_label_set_long_mode(ui->MainScreen_labelSyringeVolumeValue, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_labelSyringeVolumeValue, 0, 35);
	lv_obj_set_size(ui->MainScreen_labelSyringeVolumeValue, 80, 25);

	//Write style for MainScreen_labelSyringeVolumeValue, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_labelSyringeVolumeValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_labelSyringeVolumeValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_labelSyringeVolumeValue, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_labelSyringeVolumeValue, &lv_font_Alatsi_Regular_19, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_labelSyringeVolumeValue, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_labelSyringeVolumeValue, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_labelSyringeVolumeValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_labelSyringeVolumeValue, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_labelSyringeVolumeValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_labelSyringeVolumeValue, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_labelSyringeVolumeValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_labelSyringeVolumeValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_labelSyringeVolumeValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_labelSyringeVolumeValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_labelSyringeInnerDiaValue
	ui->MainScreen_labelSyringeInnerDiaValue = lv_label_create(ui->MainScreen_contSyringeValues);
	lv_label_set_text(ui->MainScreen_labelSyringeInnerDiaValue, "Inner Dia:");
	lv_label_set_long_mode(ui->MainScreen_labelSyringeInnerDiaValue, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_labelSyringeInnerDiaValue, 0, 70);
	lv_obj_set_size(ui->MainScreen_labelSyringeInnerDiaValue, 100, 25);

	//Write style for MainScreen_labelSyringeInnerDiaValue, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_labelSyringeInnerDiaValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_labelSyringeInnerDiaValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_labelSyringeInnerDiaValue, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_labelSyringeInnerDiaValue, &lv_font_Alatsi_Regular_19, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_labelSyringeInnerDiaValue, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_labelSyringeInnerDiaValue, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_labelSyringeInnerDiaValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_labelSyringeInnerDiaValue, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_labelSyringeInnerDiaValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_labelSyringeInnerDiaValue, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_labelSyringeInnerDiaValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_labelSyringeInnerDiaValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_labelSyringeInnerDiaValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_labelSyringeInnerDiaValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_labelSyringeOuterDiaValue
	ui->MainScreen_labelSyringeOuterDiaValue = lv_label_create(ui->MainScreen_contSyringeValues);
	lv_label_set_text(ui->MainScreen_labelSyringeOuterDiaValue, "Outer Dia:");
	lv_label_set_long_mode(ui->MainScreen_labelSyringeOuterDiaValue, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_labelSyringeOuterDiaValue, 0, 105);
	lv_obj_set_size(ui->MainScreen_labelSyringeOuterDiaValue, 110, 25);

	//Write style for MainScreen_labelSyringeOuterDiaValue, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_labelSyringeOuterDiaValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_labelSyringeOuterDiaValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_labelSyringeOuterDiaValue, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_labelSyringeOuterDiaValue, &lv_font_Alatsi_Regular_19, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_labelSyringeOuterDiaValue, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_labelSyringeOuterDiaValue, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_labelSyringeOuterDiaValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_labelSyringeOuterDiaValue, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_labelSyringeOuterDiaValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_labelSyringeOuterDiaValue, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_labelSyringeOuterDiaValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_labelSyringeOuterDiaValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_labelSyringeOuterDiaValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_labelSyringeOuterDiaValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_labelSyringeBarrelLenValue
	ui->MainScreen_labelSyringeBarrelLenValue = lv_label_create(ui->MainScreen_contSyringeValues);
	lv_label_set_text(ui->MainScreen_labelSyringeBarrelLenValue, "Barrel Len:");
	lv_label_set_long_mode(ui->MainScreen_labelSyringeBarrelLenValue, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_labelSyringeBarrelLenValue, 400, 0);
	lv_obj_set_size(ui->MainScreen_labelSyringeBarrelLenValue, 120, 25);

	//Write style for MainScreen_labelSyringeBarrelLenValue, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_labelSyringeBarrelLenValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_labelSyringeBarrelLenValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_labelSyringeBarrelLenValue, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_labelSyringeBarrelLenValue, &lv_font_Alatsi_Regular_19, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_labelSyringeBarrelLenValue, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_labelSyringeBarrelLenValue, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_labelSyringeBarrelLenValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_labelSyringeBarrelLenValue, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_labelSyringeBarrelLenValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_labelSyringeBarrelLenValue, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_labelSyringeBarrelLenValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_labelSyringeBarrelLenValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_labelSyringeBarrelLenValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_labelSyringeBarrelLenValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_labelSyringePlungerLenValue
	ui->MainScreen_labelSyringePlungerLenValue = lv_label_create(ui->MainScreen_contSyringeValues);
	lv_label_set_text(ui->MainScreen_labelSyringePlungerLenValue, "Plunger Len:");
	lv_label_set_long_mode(ui->MainScreen_labelSyringePlungerLenValue, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_labelSyringePlungerLenValue, 400, 35);
	lv_obj_set_size(ui->MainScreen_labelSyringePlungerLenValue, 130, 25);

	//Write style for MainScreen_labelSyringePlungerLenValue, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_labelSyringePlungerLenValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_labelSyringePlungerLenValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_labelSyringePlungerLenValue, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_labelSyringePlungerLenValue, &lv_font_Alatsi_Regular_19, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_labelSyringePlungerLenValue, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_labelSyringePlungerLenValue, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_labelSyringePlungerLenValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_labelSyringePlungerLenValue, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_labelSyringePlungerLenValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_labelSyringePlungerLenValue, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_labelSyringePlungerLenValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_labelSyringePlungerLenValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_labelSyringePlungerLenValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_labelSyringePlungerLenValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_labelSyringeDiaTolValue
	ui->MainScreen_labelSyringeDiaTolValue = lv_label_create(ui->MainScreen_contSyringeValues);
	lv_label_set_text(ui->MainScreen_labelSyringeDiaTolValue, "Dia Tolerance:");
	lv_label_set_long_mode(ui->MainScreen_labelSyringeDiaTolValue, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_labelSyringeDiaTolValue, 400, 70);
	lv_obj_set_size(ui->MainScreen_labelSyringeDiaTolValue, 150, 25);

	//Write style for MainScreen_labelSyringeDiaTolValue, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_labelSyringeDiaTolValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_labelSyringeDiaTolValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_labelSyringeDiaTolValue, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_labelSyringeDiaTolValue, &lv_font_Alatsi_Regular_19, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_labelSyringeDiaTolValue, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_labelSyringeDiaTolValue, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_labelSyringeDiaTolValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_labelSyringeDiaTolValue, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_labelSyringeDiaTolValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_labelSyringeDiaTolValue, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_labelSyringeDiaTolValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_labelSyringeDiaTolValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_labelSyringeDiaTolValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_labelSyringeDiaTolValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_taSyringeNameValue
	ui->MainScreen_taSyringeNameValue = lv_textarea_create(ui->MainScreen_contSyringeValues);
	lv_textarea_set_text(ui->MainScreen_taSyringeNameValue, "MySyringe");
	lv_textarea_set_placeholder_text(ui->MainScreen_taSyringeNameValue, "");
	lv_textarea_set_password_bullet(ui->MainScreen_taSyringeNameValue, "*");
	lv_textarea_set_password_mode(ui->MainScreen_taSyringeNameValue, false);
	lv_textarea_set_one_line(ui->MainScreen_taSyringeNameValue, true);
	lv_textarea_set_accepted_chars(ui->MainScreen_taSyringeNameValue, "");
	lv_textarea_set_max_length(ui->MainScreen_taSyringeNameValue, 20);
	#if LV_USE_KEYBOARD != 0 || LV_USE_ZH_KEYBOARD != 0
		lv_obj_add_event_cb(ui->MainScreen_taSyringeNameValue, ta_event_cb, LV_EVENT_ALL, ui->g_kb_MainScreen);
	#endif
	lv_obj_set_pos(ui->MainScreen_taSyringeNameValue, 73, 0);
	lv_obj_set_size(ui->MainScreen_taSyringeNameValue, 300, 30);

	//Write style for MainScreen_taSyringeNameValue, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->MainScreen_taSyringeNameValue, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_taSyringeNameValue, &lv_font_Alatsi_Regular_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_taSyringeNameValue, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_taSyringeNameValue, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_taSyringeNameValue, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_taSyringeNameValue, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_taSyringeNameValue, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_taSyringeNameValue, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_taSyringeNameValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_taSyringeNameValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_taSyringeNameValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_taSyringeNameValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_taSyringeNameValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_taSyringeNameValue, 4, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_taSyringeNameValue, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
	lv_obj_set_style_text_color(ui->MainScreen_taSyringeNameValue, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->MainScreen_taSyringeNameValue, &lv_font_Alatsi_Regular_18, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_opa(ui->MainScreen_taSyringeNameValue, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_opa(ui->MainScreen_taSyringeNameValue, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_color(ui->MainScreen_taSyringeNameValue, lv_color_hex(0xa4e6fd), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_taSyringeNameValue, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_width(ui->MainScreen_taSyringeNameValue, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_shadow_width(ui->MainScreen_taSyringeNameValue, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_pad_top(ui->MainScreen_taSyringeNameValue, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_pad_right(ui->MainScreen_taSyringeNameValue, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_pad_left(ui->MainScreen_taSyringeNameValue, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_radius(ui->MainScreen_taSyringeNameValue, 4, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write codes MainScreen_spinboxSyringeVolume
	ui->MainScreen_spinboxSyringeVolume = lv_spinbox_create(ui->MainScreen_contSyringeValues);
	lv_obj_set_pos(ui->MainScreen_spinboxSyringeVolume, 119, 34);
	lv_obj_set_width(ui->MainScreen_spinboxSyringeVolume, 90);
	lv_obj_set_height(ui->MainScreen_spinboxSyringeVolume, 25);
	lv_spinbox_set_digit_format(ui->MainScreen_spinboxSyringeVolume, 2, 2);
	lv_spinbox_set_range(ui->MainScreen_spinboxSyringeVolume, -99, 99);
	lv_coord_t MainScreen_spinboxSyringeVolume_h = lv_obj_get_height(ui->MainScreen_spinboxSyringeVolume);
	ui->MainScreen_spinboxSyringeVolume_btn = lv_btn_create(ui->MainScreen_contSyringeValues);
	lv_obj_set_size(ui->MainScreen_spinboxSyringeVolume_btn, MainScreen_spinboxSyringeVolume_h, MainScreen_spinboxSyringeVolume_h);
	lv_obj_align_to(ui->MainScreen_spinboxSyringeVolume_btn, ui->MainScreen_spinboxSyringeVolume, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxSyringeVolume_btn, LV_SYMBOL_PLUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxSyringeVolume_btn, lv_MainScreen_spinboxSyringeVolume_increment_event_cb, LV_EVENT_ALL, NULL);
	ui->MainScreen_spinboxSyringeVolume_btn_minus = lv_btn_create(ui->MainScreen_contSyringeValues);
	lv_obj_set_size(ui->MainScreen_spinboxSyringeVolume_btn_minus, MainScreen_spinboxSyringeVolume_h, MainScreen_spinboxSyringeVolume_h);
	lv_obj_align_to(ui->MainScreen_spinboxSyringeVolume_btn_minus, ui->MainScreen_spinboxSyringeVolume, LV_ALIGN_OUT_LEFT_MID, -5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxSyringeVolume_btn_minus, LV_SYMBOL_MINUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxSyringeVolume_btn_minus, lv_MainScreen_spinboxSyringeVolume_decrement_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_set_pos(ui->MainScreen_spinboxSyringeVolume, 119, 34);

	//Write style for MainScreen_spinboxSyringeVolume, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxSyringeVolume, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxSyringeVolume, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxSyringeVolume, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_spinboxSyringeVolume, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->MainScreen_spinboxSyringeVolume, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->MainScreen_spinboxSyringeVolume, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->MainScreen_spinboxSyringeVolume, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_spinboxSyringeVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_spinboxSyringeVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_spinboxSyringeVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_spinboxSyringeVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_spinboxSyringeVolume, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxSyringeVolume, &lv_font_Alatsi_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxSyringeVolume, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_spinboxSyringeVolume, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_spinboxSyringeVolume, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_spinboxSyringeVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_spinboxSyringeVolume, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->MainScreen_spinboxSyringeVolume, lv_color_hex(0x000000), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxSyringeVolume, &lv_font_Alatsi_Regular_16, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxSyringeVolume, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxSyringeVolume, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxSyringeVolume, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxSyringeVolume, LV_GRAD_DIR_NONE, LV_PART_CURSOR|LV_STATE_DEFAULT);

	//Write codes MainScreen_spinboxSyringeInnerDia
	ui->MainScreen_spinboxSyringeInnerDia = lv_spinbox_create(ui->MainScreen_contSyringeValues);
	lv_obj_set_pos(ui->MainScreen_spinboxSyringeInnerDia, 123, 69);
	lv_obj_set_width(ui->MainScreen_spinboxSyringeInnerDia, 90);
	lv_obj_set_height(ui->MainScreen_spinboxSyringeInnerDia, 25);
	lv_spinbox_set_digit_format(ui->MainScreen_spinboxSyringeInnerDia, 3, 2);
	lv_spinbox_set_range(ui->MainScreen_spinboxSyringeInnerDia, -999, 999);
	lv_coord_t MainScreen_spinboxSyringeInnerDia_h = lv_obj_get_height(ui->MainScreen_spinboxSyringeInnerDia);
	ui->MainScreen_spinboxSyringeInnerDia_btn = lv_btn_create(ui->MainScreen_contSyringeValues);
	lv_obj_set_size(ui->MainScreen_spinboxSyringeInnerDia_btn, MainScreen_spinboxSyringeInnerDia_h, MainScreen_spinboxSyringeInnerDia_h);
	lv_obj_align_to(ui->MainScreen_spinboxSyringeInnerDia_btn, ui->MainScreen_spinboxSyringeInnerDia, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxSyringeInnerDia_btn, LV_SYMBOL_PLUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxSyringeInnerDia_btn, lv_MainScreen_spinboxSyringeInnerDia_increment_event_cb, LV_EVENT_ALL, NULL);
	ui->MainScreen_spinboxSyringeInnerDia_btn_minus = lv_btn_create(ui->MainScreen_contSyringeValues);
	lv_obj_set_size(ui->MainScreen_spinboxSyringeInnerDia_btn_minus, MainScreen_spinboxSyringeInnerDia_h, MainScreen_spinboxSyringeInnerDia_h);
	lv_obj_align_to(ui->MainScreen_spinboxSyringeInnerDia_btn_minus, ui->MainScreen_spinboxSyringeInnerDia, LV_ALIGN_OUT_LEFT_MID, -5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxSyringeInnerDia_btn_minus, LV_SYMBOL_MINUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxSyringeInnerDia_btn_minus, lv_MainScreen_spinboxSyringeInnerDia_decrement_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_set_pos(ui->MainScreen_spinboxSyringeInnerDia, 123, 69);

	//Write style for MainScreen_spinboxSyringeInnerDia, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxSyringeInnerDia, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxSyringeInnerDia, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxSyringeInnerDia, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_spinboxSyringeInnerDia, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->MainScreen_spinboxSyringeInnerDia, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->MainScreen_spinboxSyringeInnerDia, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->MainScreen_spinboxSyringeInnerDia, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_spinboxSyringeInnerDia, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_spinboxSyringeInnerDia, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_spinboxSyringeInnerDia, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_spinboxSyringeInnerDia, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_spinboxSyringeInnerDia, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxSyringeInnerDia, &lv_font_Alatsi_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxSyringeInnerDia, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_spinboxSyringeInnerDia, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_spinboxSyringeInnerDia, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_spinboxSyringeInnerDia, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_spinboxSyringeInnerDia, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->MainScreen_spinboxSyringeInnerDia, lv_color_hex(0x000000), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxSyringeInnerDia, &lv_font_Alatsi_Regular_16, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxSyringeInnerDia, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxSyringeInnerDia, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxSyringeInnerDia, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxSyringeInnerDia, LV_GRAD_DIR_NONE, LV_PART_CURSOR|LV_STATE_DEFAULT);

	//Write codes MainScreen_spinboxSyringeOuterDia
	ui->MainScreen_spinboxSyringeOuterDia = lv_spinbox_create(ui->MainScreen_contSyringeValues);
	lv_obj_set_pos(ui->MainScreen_spinboxSyringeOuterDia, 123, 102);
	lv_obj_set_width(ui->MainScreen_spinboxSyringeOuterDia, 90);
	lv_obj_set_height(ui->MainScreen_spinboxSyringeOuterDia, 25);
	lv_spinbox_set_digit_format(ui->MainScreen_spinboxSyringeOuterDia, 3, 2);
	lv_spinbox_set_range(ui->MainScreen_spinboxSyringeOuterDia, -999, 999);
	lv_coord_t MainScreen_spinboxSyringeOuterDia_h = lv_obj_get_height(ui->MainScreen_spinboxSyringeOuterDia);
	ui->MainScreen_spinboxSyringeOuterDia_btn = lv_btn_create(ui->MainScreen_contSyringeValues);
	lv_obj_set_size(ui->MainScreen_spinboxSyringeOuterDia_btn, MainScreen_spinboxSyringeOuterDia_h, MainScreen_spinboxSyringeOuterDia_h);
	lv_obj_align_to(ui->MainScreen_spinboxSyringeOuterDia_btn, ui->MainScreen_spinboxSyringeOuterDia, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxSyringeOuterDia_btn, LV_SYMBOL_PLUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxSyringeOuterDia_btn, lv_MainScreen_spinboxSyringeOuterDia_increment_event_cb, LV_EVENT_ALL, NULL);
	ui->MainScreen_spinboxSyringeOuterDia_btn_minus = lv_btn_create(ui->MainScreen_contSyringeValues);
	lv_obj_set_size(ui->MainScreen_spinboxSyringeOuterDia_btn_minus, MainScreen_spinboxSyringeOuterDia_h, MainScreen_spinboxSyringeOuterDia_h);
	lv_obj_align_to(ui->MainScreen_spinboxSyringeOuterDia_btn_minus, ui->MainScreen_spinboxSyringeOuterDia, LV_ALIGN_OUT_LEFT_MID, -5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxSyringeOuterDia_btn_minus, LV_SYMBOL_MINUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxSyringeOuterDia_btn_minus, lv_MainScreen_spinboxSyringeOuterDia_decrement_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_set_pos(ui->MainScreen_spinboxSyringeOuterDia, 123, 102);

	//Write style for MainScreen_spinboxSyringeOuterDia, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxSyringeOuterDia, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxSyringeOuterDia, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxSyringeOuterDia, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_spinboxSyringeOuterDia, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->MainScreen_spinboxSyringeOuterDia, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->MainScreen_spinboxSyringeOuterDia, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->MainScreen_spinboxSyringeOuterDia, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_spinboxSyringeOuterDia, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_spinboxSyringeOuterDia, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_spinboxSyringeOuterDia, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_spinboxSyringeOuterDia, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_spinboxSyringeOuterDia, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxSyringeOuterDia, &lv_font_Alatsi_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxSyringeOuterDia, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_spinboxSyringeOuterDia, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_spinboxSyringeOuterDia, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_spinboxSyringeOuterDia, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_spinboxSyringeOuterDia, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->MainScreen_spinboxSyringeOuterDia, lv_color_hex(0x000000), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxSyringeOuterDia, &lv_font_Alatsi_Regular_16, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxSyringeOuterDia, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxSyringeOuterDia, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxSyringeOuterDia, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxSyringeOuterDia, LV_GRAD_DIR_NONE, LV_PART_CURSOR|LV_STATE_DEFAULT);

	//Write codes MainScreen_spinboxSyringeBarrelLen
	ui->MainScreen_spinboxSyringeBarrelLen = lv_spinbox_create(ui->MainScreen_contSyringeValues);
	lv_obj_set_pos(ui->MainScreen_spinboxSyringeBarrelLen, 568, 0);
	lv_obj_set_width(ui->MainScreen_spinboxSyringeBarrelLen, 90);
	lv_obj_set_height(ui->MainScreen_spinboxSyringeBarrelLen, 25);
	lv_spinbox_set_digit_format(ui->MainScreen_spinboxSyringeBarrelLen, 3, 3);
	lv_spinbox_set_range(ui->MainScreen_spinboxSyringeBarrelLen, -999, 999);
	lv_coord_t MainScreen_spinboxSyringeBarrelLen_h = lv_obj_get_height(ui->MainScreen_spinboxSyringeBarrelLen);
	ui->MainScreen_spinboxSyringeBarrelLen_btn = lv_btn_create(ui->MainScreen_contSyringeValues);
	lv_obj_set_size(ui->MainScreen_spinboxSyringeBarrelLen_btn, MainScreen_spinboxSyringeBarrelLen_h, MainScreen_spinboxSyringeBarrelLen_h);
	lv_obj_align_to(ui->MainScreen_spinboxSyringeBarrelLen_btn, ui->MainScreen_spinboxSyringeBarrelLen, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxSyringeBarrelLen_btn, LV_SYMBOL_PLUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxSyringeBarrelLen_btn, lv_MainScreen_spinboxSyringeBarrelLen_increment_event_cb, LV_EVENT_ALL, NULL);
	ui->MainScreen_spinboxSyringeBarrelLen_btn_minus = lv_btn_create(ui->MainScreen_contSyringeValues);
	lv_obj_set_size(ui->MainScreen_spinboxSyringeBarrelLen_btn_minus, MainScreen_spinboxSyringeBarrelLen_h, MainScreen_spinboxSyringeBarrelLen_h);
	lv_obj_align_to(ui->MainScreen_spinboxSyringeBarrelLen_btn_minus, ui->MainScreen_spinboxSyringeBarrelLen, LV_ALIGN_OUT_LEFT_MID, -5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxSyringeBarrelLen_btn_minus, LV_SYMBOL_MINUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxSyringeBarrelLen_btn_minus, lv_MainScreen_spinboxSyringeBarrelLen_decrement_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_set_pos(ui->MainScreen_spinboxSyringeBarrelLen, 568, 0);

	//Write style for MainScreen_spinboxSyringeBarrelLen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxSyringeBarrelLen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxSyringeBarrelLen, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxSyringeBarrelLen, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_spinboxSyringeBarrelLen, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->MainScreen_spinboxSyringeBarrelLen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->MainScreen_spinboxSyringeBarrelLen, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->MainScreen_spinboxSyringeBarrelLen, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_spinboxSyringeBarrelLen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_spinboxSyringeBarrelLen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_spinboxSyringeBarrelLen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_spinboxSyringeBarrelLen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_spinboxSyringeBarrelLen, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxSyringeBarrelLen, &lv_font_Alatsi_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxSyringeBarrelLen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_spinboxSyringeBarrelLen, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_spinboxSyringeBarrelLen, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_spinboxSyringeBarrelLen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_spinboxSyringeBarrelLen, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->MainScreen_spinboxSyringeBarrelLen, lv_color_hex(0x000000), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxSyringeBarrelLen, &lv_font_Alatsi_Regular_16, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxSyringeBarrelLen, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxSyringeBarrelLen, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxSyringeBarrelLen, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxSyringeBarrelLen, LV_GRAD_DIR_NONE, LV_PART_CURSOR|LV_STATE_DEFAULT);

	//Write codes MainScreen_spinboxSyringePlungerLen
	ui->MainScreen_spinboxSyringePlungerLen = lv_spinbox_create(ui->MainScreen_contSyringeValues);
	lv_obj_set_pos(ui->MainScreen_spinboxSyringePlungerLen, 570, 35);
	lv_obj_set_width(ui->MainScreen_spinboxSyringePlungerLen, 90);
	lv_obj_set_height(ui->MainScreen_spinboxSyringePlungerLen, 25);
	lv_spinbox_set_digit_format(ui->MainScreen_spinboxSyringePlungerLen, 2, 2);
	lv_spinbox_set_range(ui->MainScreen_spinboxSyringePlungerLen, -99, 99);
	lv_coord_t MainScreen_spinboxSyringePlungerLen_h = lv_obj_get_height(ui->MainScreen_spinboxSyringePlungerLen);
	ui->MainScreen_spinboxSyringePlungerLen_btn = lv_btn_create(ui->MainScreen_contSyringeValues);
	lv_obj_set_size(ui->MainScreen_spinboxSyringePlungerLen_btn, MainScreen_spinboxSyringePlungerLen_h, MainScreen_spinboxSyringePlungerLen_h);
	lv_obj_align_to(ui->MainScreen_spinboxSyringePlungerLen_btn, ui->MainScreen_spinboxSyringePlungerLen, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxSyringePlungerLen_btn, LV_SYMBOL_PLUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxSyringePlungerLen_btn, lv_MainScreen_spinboxSyringePlungerLen_increment_event_cb, LV_EVENT_ALL, NULL);
	ui->MainScreen_spinboxSyringePlungerLen_btn_minus = lv_btn_create(ui->MainScreen_contSyringeValues);
	lv_obj_set_size(ui->MainScreen_spinboxSyringePlungerLen_btn_minus, MainScreen_spinboxSyringePlungerLen_h, MainScreen_spinboxSyringePlungerLen_h);
	lv_obj_align_to(ui->MainScreen_spinboxSyringePlungerLen_btn_minus, ui->MainScreen_spinboxSyringePlungerLen, LV_ALIGN_OUT_LEFT_MID, -5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxSyringePlungerLen_btn_minus, LV_SYMBOL_MINUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxSyringePlungerLen_btn_minus, lv_MainScreen_spinboxSyringePlungerLen_decrement_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_set_pos(ui->MainScreen_spinboxSyringePlungerLen, 570, 35);

	//Write style for MainScreen_spinboxSyringePlungerLen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxSyringePlungerLen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxSyringePlungerLen, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxSyringePlungerLen, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_spinboxSyringePlungerLen, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->MainScreen_spinboxSyringePlungerLen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->MainScreen_spinboxSyringePlungerLen, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->MainScreen_spinboxSyringePlungerLen, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_spinboxSyringePlungerLen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_spinboxSyringePlungerLen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_spinboxSyringePlungerLen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_spinboxSyringePlungerLen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_spinboxSyringePlungerLen, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxSyringePlungerLen, &lv_font_Alatsi_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxSyringePlungerLen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_spinboxSyringePlungerLen, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_spinboxSyringePlungerLen, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_spinboxSyringePlungerLen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_spinboxSyringePlungerLen, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->MainScreen_spinboxSyringePlungerLen, lv_color_hex(0x000000), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxSyringePlungerLen, &lv_font_Alatsi_Regular_16, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxSyringePlungerLen, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxSyringePlungerLen, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxSyringePlungerLen, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxSyringePlungerLen, LV_GRAD_DIR_NONE, LV_PART_CURSOR|LV_STATE_DEFAULT);

	//Write codes MainScreen_spinboxSyringeDiaTolerance
	ui->MainScreen_spinboxSyringeDiaTolerance = lv_spinbox_create(ui->MainScreen_contSyringeValues);
	lv_obj_set_pos(ui->MainScreen_spinboxSyringeDiaTolerance, 567, 70);
	lv_obj_set_width(ui->MainScreen_spinboxSyringeDiaTolerance, 90);
	lv_obj_set_height(ui->MainScreen_spinboxSyringeDiaTolerance, 25);
	lv_spinbox_set_digit_format(ui->MainScreen_spinboxSyringeDiaTolerance, 2, 2);
	lv_spinbox_set_range(ui->MainScreen_spinboxSyringeDiaTolerance, -99, 99);
	lv_coord_t MainScreen_spinboxSyringeDiaTolerance_h = lv_obj_get_height(ui->MainScreen_spinboxSyringeDiaTolerance);
	ui->MainScreen_spinboxSyringeDiaTolerance_btn = lv_btn_create(ui->MainScreen_contSyringeValues);
	lv_obj_set_size(ui->MainScreen_spinboxSyringeDiaTolerance_btn, MainScreen_spinboxSyringeDiaTolerance_h, MainScreen_spinboxSyringeDiaTolerance_h);
	lv_obj_align_to(ui->MainScreen_spinboxSyringeDiaTolerance_btn, ui->MainScreen_spinboxSyringeDiaTolerance, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxSyringeDiaTolerance_btn, LV_SYMBOL_PLUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxSyringeDiaTolerance_btn, lv_MainScreen_spinboxSyringeDiaTolerance_increment_event_cb, LV_EVENT_ALL, NULL);
	ui->MainScreen_spinboxSyringeDiaTolerance_btn_minus = lv_btn_create(ui->MainScreen_contSyringeValues);
	lv_obj_set_size(ui->MainScreen_spinboxSyringeDiaTolerance_btn_minus, MainScreen_spinboxSyringeDiaTolerance_h, MainScreen_spinboxSyringeDiaTolerance_h);
	lv_obj_align_to(ui->MainScreen_spinboxSyringeDiaTolerance_btn_minus, ui->MainScreen_spinboxSyringeDiaTolerance, LV_ALIGN_OUT_LEFT_MID, -5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxSyringeDiaTolerance_btn_minus, LV_SYMBOL_MINUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxSyringeDiaTolerance_btn_minus, lv_MainScreen_spinboxSyringeDiaTolerance_decrement_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_set_pos(ui->MainScreen_spinboxSyringeDiaTolerance, 567, 70);

	//Write style for MainScreen_spinboxSyringeDiaTolerance, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxSyringeDiaTolerance, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxSyringeDiaTolerance, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxSyringeDiaTolerance, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_spinboxSyringeDiaTolerance, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->MainScreen_spinboxSyringeDiaTolerance, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->MainScreen_spinboxSyringeDiaTolerance, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->MainScreen_spinboxSyringeDiaTolerance, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_spinboxSyringeDiaTolerance, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_spinboxSyringeDiaTolerance, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_spinboxSyringeDiaTolerance, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_spinboxSyringeDiaTolerance, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_spinboxSyringeDiaTolerance, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxSyringeDiaTolerance, &lv_font_Alatsi_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxSyringeDiaTolerance, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_spinboxSyringeDiaTolerance, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_spinboxSyringeDiaTolerance, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_spinboxSyringeDiaTolerance, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_spinboxSyringeDiaTolerance, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->MainScreen_spinboxSyringeDiaTolerance, lv_color_hex(0x000000), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxSyringeDiaTolerance, &lv_font_Alatsi_Regular_16, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxSyringeDiaTolerance, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxSyringeDiaTolerance, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxSyringeDiaTolerance, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxSyringeDiaTolerance, LV_GRAD_DIR_NONE, LV_PART_CURSOR|LV_STATE_DEFAULT);

	//Write codes MainScreen_labelSyringeHeader
	ui->MainScreen_labelSyringeHeader = lv_label_create(ui->MainScreen_contSyringe);
	lv_label_set_text(ui->MainScreen_labelSyringeHeader, "Select Company");
	lv_label_set_long_mode(ui->MainScreen_labelSyringeHeader, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_labelSyringeHeader, 0, 0);
	lv_obj_set_size(ui->MainScreen_labelSyringeHeader, 800, 30);

	//Write style for MainScreen_labelSyringeHeader, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_labelSyringeHeader, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_labelSyringeHeader, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_labelSyringeHeader, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_labelSyringeHeader, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_labelSyringeHeader, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_labelSyringeHeader, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_labelSyringeHeader, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_labelSyringeHeader, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_labelSyringeHeader, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_labelSyringeHeader, lv_color_hex(0x324e75), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_labelSyringeHeader, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_labelSyringeHeader, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_labelSyringeHeader, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_labelSyringeHeader, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_labelSyringeHeader, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_labelSyringeHeader, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_btnDummySyringe
	ui->MainScreen_btnDummySyringe = lv_btn_create(ui->MainScreen_contSyringe);
	ui->MainScreen_btnDummySyringe_label = lv_label_create(ui->MainScreen_btnDummySyringe);
	lv_label_set_text(ui->MainScreen_btnDummySyringe_label, "");
	lv_label_set_long_mode(ui->MainScreen_btnDummySyringe_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->MainScreen_btnDummySyringe_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->MainScreen_btnDummySyringe, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->MainScreen_btnDummySyringe_label, LV_PCT(100));
	lv_obj_set_pos(ui->MainScreen_btnDummySyringe, 773, 199);
	lv_obj_set_size(ui->MainScreen_btnDummySyringe, 8, 10);

	//Write style for MainScreen_btnDummySyringe, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_btnDummySyringe, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_btnDummySyringe, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_btnDummySyringe, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_btnDummySyringe, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_btnDummySyringe, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_btnDummySyringe, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_btnDummySyringe, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_btnDummySyringe, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_contDrug
	ui->MainScreen_contDrug = lv_obj_create(ui->MainScreen);
	lv_obj_set_pos(ui->MainScreen_contDrug, 800, 80);
	lv_obj_set_size(ui->MainScreen_contDrug, 800, 300);
	lv_obj_set_scrollbar_mode(ui->MainScreen_contDrug, LV_SCROLLBAR_MODE_OFF);

	//Write style for MainScreen_contDrug, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_contDrug, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->MainScreen_contDrug, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->MainScreen_contDrug, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->MainScreen_contDrug, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_contDrug, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_contDrug, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_contDrug, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_contDrug, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_contDrug, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_contDrug, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_contDrug, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_contDrug, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_contDrug, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_btnGoMenuDrug
	ui->MainScreen_btnGoMenuDrug = lv_btn_create(ui->MainScreen_contDrug);
	ui->MainScreen_btnGoMenuDrug_label = lv_label_create(ui->MainScreen_btnGoMenuDrug);
	lv_label_set_text(ui->MainScreen_btnGoMenuDrug_label, "");
	lv_label_set_long_mode(ui->MainScreen_btnGoMenuDrug_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->MainScreen_btnGoMenuDrug_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->MainScreen_btnGoMenuDrug, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->MainScreen_btnGoMenuDrug_label, LV_PCT(100));
	lv_obj_set_pos(ui->MainScreen_btnGoMenuDrug, 727, 247);
	lv_obj_set_size(ui->MainScreen_btnGoMenuDrug, 58, 44);

	//Write style for MainScreen_btnGoMenuDrug, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_btnGoMenuDrug, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_btnGoMenuDrug, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_btnGoMenuDrug, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_btnGoMenuDrug, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_btnGoMenuDrug, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_btnGoMenuDrug, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_btnGoMenuDrug, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_btnGoMenuDrug, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_listDrugBrand
	ui->MainScreen_listDrugBrand = lv_list_create(ui->MainScreen_contDrug);
	ui->MainScreen_listDrugBrand_item0 = lv_list_add_btn(ui->MainScreen_listDrugBrand, LV_SYMBOL_SAVE, "save_1");
	ui->MainScreen_listDrugBrand_item1 = lv_list_add_btn(ui->MainScreen_listDrugBrand, LV_SYMBOL_SAVE, "save_2");
	ui->MainScreen_listDrugBrand_item2 = lv_list_add_btn(ui->MainScreen_listDrugBrand, LV_SYMBOL_SAVE, "save_3");
	ui->MainScreen_listDrugBrand_item3 = lv_list_add_btn(ui->MainScreen_listDrugBrand, LV_SYMBOL_SAVE, "save_4");
	ui->MainScreen_listDrugBrand_item4 = lv_list_add_btn(ui->MainScreen_listDrugBrand, LV_SYMBOL_SAVE, "save_5");
	ui->MainScreen_listDrugBrand_item5 = lv_list_add_btn(ui->MainScreen_listDrugBrand, LV_SYMBOL_SAVE, "save_6");
	ui->MainScreen_listDrugBrand_item6 = lv_list_add_btn(ui->MainScreen_listDrugBrand, LV_SYMBOL_SAVE, "save_7");
	ui->MainScreen_listDrugBrand_item7 = lv_list_add_btn(ui->MainScreen_listDrugBrand, LV_SYMBOL_SAVE, "save_8");
	ui->MainScreen_listDrugBrand_item8 = lv_list_add_btn(ui->MainScreen_listDrugBrand, LV_SYMBOL_SAVE, "save_9");
	ui->MainScreen_listDrugBrand_item9 = lv_list_add_btn(ui->MainScreen_listDrugBrand, LV_SYMBOL_SAVE, "save_10");
	ui->MainScreen_listDrugBrand_item10 = lv_list_add_btn(ui->MainScreen_listDrugBrand, LV_SYMBOL_SAVE, "save_11");
	ui->MainScreen_listDrugBrand_item11 = lv_list_add_btn(ui->MainScreen_listDrugBrand, LV_SYMBOL_SAVE, "save_12");
	ui->MainScreen_listDrugBrand_item12 = lv_list_add_btn(ui->MainScreen_listDrugBrand, LV_SYMBOL_SAVE, "save_13");
	ui->MainScreen_listDrugBrand_item13 = lv_list_add_btn(ui->MainScreen_listDrugBrand, LV_SYMBOL_SAVE, "save_14");
	ui->MainScreen_listDrugBrand_item14 = lv_list_add_btn(ui->MainScreen_listDrugBrand, LV_SYMBOL_SAVE, "save_15");
	ui->MainScreen_listDrugBrand_item15 = lv_list_add_btn(ui->MainScreen_listDrugBrand, LV_SYMBOL_SAVE, "save_16");
	ui->MainScreen_listDrugBrand_item16 = lv_list_add_btn(ui->MainScreen_listDrugBrand, LV_SYMBOL_SAVE, "save_17");
	ui->MainScreen_listDrugBrand_item17 = lv_list_add_btn(ui->MainScreen_listDrugBrand, LV_SYMBOL_SAVE, "save_18");
	ui->MainScreen_listDrugBrand_item18 = lv_list_add_btn(ui->MainScreen_listDrugBrand, LV_SYMBOL_SAVE, "save_19");
	ui->MainScreen_listDrugBrand_item19 = lv_list_add_btn(ui->MainScreen_listDrugBrand, LV_SYMBOL_SAVE, "save_20");
	ui->MainScreen_listDrugBrand_item20 = lv_list_add_btn(ui->MainScreen_listDrugBrand, LV_SYMBOL_SAVE, "save_21");
	ui->MainScreen_listDrugBrand_item21 = lv_list_add_btn(ui->MainScreen_listDrugBrand, LV_SYMBOL_SAVE, "save_22");
	ui->MainScreen_listDrugBrand_item22 = lv_list_add_btn(ui->MainScreen_listDrugBrand, LV_SYMBOL_SAVE, "save_23");
	ui->MainScreen_listDrugBrand_item23 = lv_list_add_btn(ui->MainScreen_listDrugBrand, LV_SYMBOL_SAVE, "save_24");
	ui->MainScreen_listDrugBrand_item24 = lv_list_add_btn(ui->MainScreen_listDrugBrand, LV_SYMBOL_SAVE, "save_25");
	ui->MainScreen_listDrugBrand_item25 = lv_list_add_btn(ui->MainScreen_listDrugBrand, LV_SYMBOL_SAVE, "save_26");
	ui->MainScreen_listDrugBrand_item26 = lv_list_add_btn(ui->MainScreen_listDrugBrand, LV_SYMBOL_SAVE, "save_27");
	ui->MainScreen_listDrugBrand_item27 = lv_list_add_btn(ui->MainScreen_listDrugBrand, LV_SYMBOL_SAVE, "save_28");
	ui->MainScreen_listDrugBrand_item28 = lv_list_add_btn(ui->MainScreen_listDrugBrand, LV_SYMBOL_SAVE, "save_29");
	ui->MainScreen_listDrugBrand_item29 = lv_list_add_btn(ui->MainScreen_listDrugBrand, LV_SYMBOL_SAVE, "save_30");
	ui->MainScreen_listDrugBrand_item30 = lv_list_add_btn(ui->MainScreen_listDrugBrand, LV_SYMBOL_SAVE, "save_31");
	ui->MainScreen_listDrugBrand_item31 = lv_list_add_btn(ui->MainScreen_listDrugBrand, LV_SYMBOL_SAVE, "save_32");
	ui->MainScreen_listDrugBrand_item32 = lv_list_add_btn(ui->MainScreen_listDrugBrand, LV_SYMBOL_SAVE, "save_33");
	ui->MainScreen_listDrugBrand_item33 = lv_list_add_btn(ui->MainScreen_listDrugBrand, LV_SYMBOL_SAVE, "save_34");
	ui->MainScreen_listDrugBrand_item34 = lv_list_add_btn(ui->MainScreen_listDrugBrand, LV_SYMBOL_SAVE, "save_35");
	ui->MainScreen_listDrugBrand_item35 = lv_list_add_btn(ui->MainScreen_listDrugBrand, LV_SYMBOL_SAVE, "save_36");
	ui->MainScreen_listDrugBrand_item36 = lv_list_add_btn(ui->MainScreen_listDrugBrand, LV_SYMBOL_SAVE, "save_37");
	ui->MainScreen_listDrugBrand_item37 = lv_list_add_btn(ui->MainScreen_listDrugBrand, LV_SYMBOL_SAVE, "save_38");
	ui->MainScreen_listDrugBrand_item38 = lv_list_add_btn(ui->MainScreen_listDrugBrand, LV_SYMBOL_SAVE, "save_39");
	ui->MainScreen_listDrugBrand_item39 = lv_list_add_btn(ui->MainScreen_listDrugBrand, LV_SYMBOL_SAVE, "save_40");
	ui->MainScreen_listDrugBrand_item40 = lv_list_add_btn(ui->MainScreen_listDrugBrand, LV_SYMBOL_SAVE, "save_41");
	ui->MainScreen_listDrugBrand_item41 = lv_list_add_btn(ui->MainScreen_listDrugBrand, LV_SYMBOL_SAVE, "save_42");
	ui->MainScreen_listDrugBrand_item42 = lv_list_add_btn(ui->MainScreen_listDrugBrand, LV_SYMBOL_SAVE, "save_43");
	ui->MainScreen_listDrugBrand_item43 = lv_list_add_btn(ui->MainScreen_listDrugBrand, LV_SYMBOL_SAVE, "save_44");
	ui->MainScreen_listDrugBrand_item44 = lv_list_add_btn(ui->MainScreen_listDrugBrand, LV_SYMBOL_SAVE, "save_45");
	ui->MainScreen_listDrugBrand_item45 = lv_list_add_btn(ui->MainScreen_listDrugBrand, LV_SYMBOL_SAVE, "save_46");
	ui->MainScreen_listDrugBrand_item46 = lv_list_add_btn(ui->MainScreen_listDrugBrand, LV_SYMBOL_SAVE, "save_47");
	ui->MainScreen_listDrugBrand_item47 = lv_list_add_btn(ui->MainScreen_listDrugBrand, LV_SYMBOL_SAVE, "save_48");
	ui->MainScreen_listDrugBrand_item48 = lv_list_add_btn(ui->MainScreen_listDrugBrand, LV_SYMBOL_SAVE, "save_49");
	ui->MainScreen_listDrugBrand_item49 = lv_list_add_btn(ui->MainScreen_listDrugBrand, LV_SYMBOL_SAVE, "save_50");
	lv_obj_set_pos(ui->MainScreen_listDrugBrand, 0, 29);
	lv_obj_set_size(ui->MainScreen_listDrugBrand, 350, 270);
	lv_obj_set_scrollbar_mode(ui->MainScreen_listDrugBrand, LV_SCROLLBAR_MODE_AUTO);

	//Write style state: LV_STATE_DEFAULT for &style_MainScreen_listDrugBrand_main_main_default
	static lv_style_t style_MainScreen_listDrugBrand_main_main_default;
	ui_init_style(&style_MainScreen_listDrugBrand_main_main_default);
	
	lv_style_set_pad_top(&style_MainScreen_listDrugBrand_main_main_default, 0);
	lv_style_set_pad_left(&style_MainScreen_listDrugBrand_main_main_default, 0);
	lv_style_set_pad_right(&style_MainScreen_listDrugBrand_main_main_default, 0);
	lv_style_set_pad_bottom(&style_MainScreen_listDrugBrand_main_main_default, 0);
	lv_style_set_bg_opa(&style_MainScreen_listDrugBrand_main_main_default, 255);
	lv_style_set_bg_color(&style_MainScreen_listDrugBrand_main_main_default, lv_color_hex(0x000000));
	lv_style_set_bg_grad_dir(&style_MainScreen_listDrugBrand_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_border_width(&style_MainScreen_listDrugBrand_main_main_default, 2);
	lv_style_set_border_opa(&style_MainScreen_listDrugBrand_main_main_default, 255);
	lv_style_set_border_color(&style_MainScreen_listDrugBrand_main_main_default, lv_color_hex(0x008dff));
	lv_style_set_border_side(&style_MainScreen_listDrugBrand_main_main_default, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_MainScreen_listDrugBrand_main_main_default, 0);
	lv_style_set_shadow_width(&style_MainScreen_listDrugBrand_main_main_default, 0);
	lv_obj_add_style(ui->MainScreen_listDrugBrand, &style_MainScreen_listDrugBrand_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_MainScreen_listDrugBrand_main_scrollbar_default
	static lv_style_t style_MainScreen_listDrugBrand_main_scrollbar_default;
	ui_init_style(&style_MainScreen_listDrugBrand_main_scrollbar_default);
	
	lv_style_set_radius(&style_MainScreen_listDrugBrand_main_scrollbar_default, 3);
	lv_style_set_bg_opa(&style_MainScreen_listDrugBrand_main_scrollbar_default, 255);
	lv_style_set_bg_color(&style_MainScreen_listDrugBrand_main_scrollbar_default, lv_color_hex(0x9e9e9e));
	lv_style_set_bg_grad_dir(&style_MainScreen_listDrugBrand_main_scrollbar_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(ui->MainScreen_listDrugBrand, &style_MainScreen_listDrugBrand_main_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_MainScreen_listDrugBrand_extra_btns_main_default
	static lv_style_t style_MainScreen_listDrugBrand_extra_btns_main_default;
	ui_init_style(&style_MainScreen_listDrugBrand_extra_btns_main_default);
	
	lv_style_set_pad_top(&style_MainScreen_listDrugBrand_extra_btns_main_default, 2);
	lv_style_set_pad_left(&style_MainScreen_listDrugBrand_extra_btns_main_default, 2);
	lv_style_set_pad_right(&style_MainScreen_listDrugBrand_extra_btns_main_default, 2);
	lv_style_set_pad_bottom(&style_MainScreen_listDrugBrand_extra_btns_main_default, 2);
	lv_style_set_border_width(&style_MainScreen_listDrugBrand_extra_btns_main_default, 0);
	lv_style_set_text_color(&style_MainScreen_listDrugBrand_extra_btns_main_default, lv_color_hex(0xffffff));
	lv_style_set_text_font(&style_MainScreen_listDrugBrand_extra_btns_main_default, &lv_font_Alatsi_Regular_19);
	lv_style_set_text_opa(&style_MainScreen_listDrugBrand_extra_btns_main_default, 255);
	lv_style_set_radius(&style_MainScreen_listDrugBrand_extra_btns_main_default, 3);
	lv_style_set_bg_opa(&style_MainScreen_listDrugBrand_extra_btns_main_default, 255);
	lv_style_set_bg_color(&style_MainScreen_listDrugBrand_extra_btns_main_default, lv_color_hex(0x000000));
	lv_style_set_bg_grad_dir(&style_MainScreen_listDrugBrand_extra_btns_main_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item49, &style_MainScreen_listDrugBrand_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item48, &style_MainScreen_listDrugBrand_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item47, &style_MainScreen_listDrugBrand_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item46, &style_MainScreen_listDrugBrand_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item45, &style_MainScreen_listDrugBrand_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item44, &style_MainScreen_listDrugBrand_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item43, &style_MainScreen_listDrugBrand_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item42, &style_MainScreen_listDrugBrand_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item41, &style_MainScreen_listDrugBrand_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item40, &style_MainScreen_listDrugBrand_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item39, &style_MainScreen_listDrugBrand_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item38, &style_MainScreen_listDrugBrand_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item37, &style_MainScreen_listDrugBrand_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item36, &style_MainScreen_listDrugBrand_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item35, &style_MainScreen_listDrugBrand_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item34, &style_MainScreen_listDrugBrand_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item33, &style_MainScreen_listDrugBrand_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item32, &style_MainScreen_listDrugBrand_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item31, &style_MainScreen_listDrugBrand_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item30, &style_MainScreen_listDrugBrand_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item29, &style_MainScreen_listDrugBrand_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item28, &style_MainScreen_listDrugBrand_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item27, &style_MainScreen_listDrugBrand_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item26, &style_MainScreen_listDrugBrand_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item25, &style_MainScreen_listDrugBrand_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item24, &style_MainScreen_listDrugBrand_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item23, &style_MainScreen_listDrugBrand_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item22, &style_MainScreen_listDrugBrand_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item21, &style_MainScreen_listDrugBrand_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item20, &style_MainScreen_listDrugBrand_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item19, &style_MainScreen_listDrugBrand_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item18, &style_MainScreen_listDrugBrand_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item17, &style_MainScreen_listDrugBrand_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item16, &style_MainScreen_listDrugBrand_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item15, &style_MainScreen_listDrugBrand_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item14, &style_MainScreen_listDrugBrand_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item13, &style_MainScreen_listDrugBrand_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item12, &style_MainScreen_listDrugBrand_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item11, &style_MainScreen_listDrugBrand_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item10, &style_MainScreen_listDrugBrand_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item9, &style_MainScreen_listDrugBrand_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item8, &style_MainScreen_listDrugBrand_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item7, &style_MainScreen_listDrugBrand_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item6, &style_MainScreen_listDrugBrand_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item5, &style_MainScreen_listDrugBrand_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item4, &style_MainScreen_listDrugBrand_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item3, &style_MainScreen_listDrugBrand_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item2, &style_MainScreen_listDrugBrand_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item1, &style_MainScreen_listDrugBrand_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item0, &style_MainScreen_listDrugBrand_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_FOCUSED for &style_MainScreen_listDrugBrand_extra_btns_main_focused
	static lv_style_t style_MainScreen_listDrugBrand_extra_btns_main_focused;
	ui_init_style(&style_MainScreen_listDrugBrand_extra_btns_main_focused);
	
	lv_style_set_pad_top(&style_MainScreen_listDrugBrand_extra_btns_main_focused, 2);
	lv_style_set_pad_left(&style_MainScreen_listDrugBrand_extra_btns_main_focused, 2);
	lv_style_set_pad_right(&style_MainScreen_listDrugBrand_extra_btns_main_focused, 2);
	lv_style_set_pad_bottom(&style_MainScreen_listDrugBrand_extra_btns_main_focused, 2);
	lv_style_set_border_width(&style_MainScreen_listDrugBrand_extra_btns_main_focused, 0);
	lv_style_set_radius(&style_MainScreen_listDrugBrand_extra_btns_main_focused, 3);
	lv_style_set_text_color(&style_MainScreen_listDrugBrand_extra_btns_main_focused, lv_color_hex(0xffffff));
	lv_style_set_text_font(&style_MainScreen_listDrugBrand_extra_btns_main_focused, &lv_font_Alatsi_Regular_19);
	lv_style_set_text_opa(&style_MainScreen_listDrugBrand_extra_btns_main_focused, 255);
	lv_style_set_bg_opa(&style_MainScreen_listDrugBrand_extra_btns_main_focused, 255);
	lv_style_set_bg_color(&style_MainScreen_listDrugBrand_extra_btns_main_focused, lv_color_hex(0x0016ff));
	lv_style_set_bg_grad_dir(&style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_GRAD_DIR_NONE);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item49, &style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item48, &style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item47, &style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item46, &style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item45, &style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item44, &style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item43, &style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item42, &style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item41, &style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item40, &style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item39, &style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item38, &style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item37, &style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item36, &style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item35, &style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item34, &style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item33, &style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item32, &style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item31, &style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item30, &style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item29, &style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item28, &style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item27, &style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item26, &style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item25, &style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item24, &style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item23, &style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item22, &style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item21, &style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item20, &style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item19, &style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item18, &style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item17, &style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item16, &style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item15, &style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item14, &style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item13, &style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item12, &style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item11, &style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item10, &style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item9, &style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item8, &style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item7, &style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item6, &style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item5, &style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item4, &style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item3, &style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item2, &style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item1, &style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listDrugBrand_item0, &style_MainScreen_listDrugBrand_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write codes MainScreen_contDrugValues
	ui->MainScreen_contDrugValues = lv_obj_create(ui->MainScreen_contDrug);
	lv_obj_set_pos(ui->MainScreen_contDrugValues, 350, 29);
	lv_obj_set_size(ui->MainScreen_contDrugValues, 388, 269);
	lv_obj_set_scrollbar_mode(ui->MainScreen_contDrugValues, LV_SCROLLBAR_MODE_OFF);

	//Write style for MainScreen_contDrugValues, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_contDrugValues, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_contDrugValues, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_contDrugValues, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_contDrugValues, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_contDrugValues, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_contDrugValues, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_contDrugValues, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_contDrugValues, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_contDrugValues, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_contDrugValues, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_26
	ui->MainScreen_label_26 = lv_label_create(ui->MainScreen_contDrugValues);
	lv_label_set_text(ui->MainScreen_label_26, "Name:");
	lv_label_set_long_mode(ui->MainScreen_label_26, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_26, 4, 0);
	lv_obj_set_size(ui->MainScreen_label_26, 70, 25);

	//Write style for MainScreen_label_26, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_26, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_26, &lv_font_Alatsi_Regular_19, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_26, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_26, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_26, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_26, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_25
	ui->MainScreen_label_25 = lv_label_create(ui->MainScreen_contDrugValues);
	lv_label_set_text(ui->MainScreen_label_25, "Brand:");
	lv_label_set_long_mode(ui->MainScreen_label_25, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_25, 4, 30);
	lv_obj_set_size(ui->MainScreen_label_25, 80, 25);

	//Write style for MainScreen_label_25, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_25, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_25, &lv_font_Alatsi_Regular_19, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_25, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_25, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_25, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_25, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_24
	ui->MainScreen_label_24 = lv_label_create(ui->MainScreen_contDrugValues);
	lv_label_set_text(ui->MainScreen_label_24, "Id.:");
	lv_label_set_long_mode(ui->MainScreen_label_24, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_24, 4, 60);
	lv_obj_set_size(ui->MainScreen_label_24, 100, 25);

	//Write style for MainScreen_label_24, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_24, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_24, &lv_font_Alatsi_Regular_19, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_24, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_24, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_24, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_24, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_23
	ui->MainScreen_label_23 = lv_label_create(ui->MainScreen_contDrugValues);
	lv_label_set_text(ui->MainScreen_label_23, "mg/ml:");
	lv_label_set_long_mode(ui->MainScreen_label_23, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_23, 4, 90);
	lv_obj_set_size(ui->MainScreen_label_23, 110, 25);

	//Write style for MainScreen_label_23, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_23, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_23, &lv_font_Alatsi_Regular_19, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_23, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_23, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_23, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_23, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_22
	ui->MainScreen_label_22 = lv_label_create(ui->MainScreen_contDrugValues);
	lv_label_set_text(ui->MainScreen_label_22, "U/ml:");
	lv_label_set_long_mode(ui->MainScreen_label_22, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_22, 4, 120);
	lv_obj_set_size(ui->MainScreen_label_22, 120, 25);

	//Write style for MainScreen_label_22, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_22, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_22, &lv_font_Alatsi_Regular_19, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_22, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_22, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_22, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_22, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_21
	ui->MainScreen_label_21 = lv_label_create(ui->MainScreen_contDrugValues);
	lv_label_set_text(ui->MainScreen_label_21, "Per/Kg:");
	lv_label_set_long_mode(ui->MainScreen_label_21, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_21, 4, 150);
	lv_obj_set_size(ui->MainScreen_label_21, 130, 25);

	//Write style for MainScreen_label_21, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_21, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_21, &lv_font_Alatsi_Regular_19, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_21, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_21, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_21, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_21, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_20
	ui->MainScreen_label_20 = lv_label_create(ui->MainScreen_contDrugValues);
	lv_label_set_text(ui->MainScreen_label_20, "Rate Min:");
	lv_label_set_long_mode(ui->MainScreen_label_20, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_20, 4, 180);
	lv_obj_set_size(ui->MainScreen_label_20, 150, 25);

	//Write style for MainScreen_label_20, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_20, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_20, &lv_font_Alatsi_Regular_19, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_20, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_20, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_20, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_20, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_28
	ui->MainScreen_label_28 = lv_label_create(ui->MainScreen_contDrugValues);
	lv_label_set_text(ui->MainScreen_label_28, "Rate Max:");
	lv_label_set_long_mode(ui->MainScreen_label_28, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_28, 4, 210);
	lv_obj_set_size(ui->MainScreen_label_28, 150, 25);

	//Write style for MainScreen_label_28, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_28, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_28, &lv_font_Alatsi_Regular_19, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_28, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_28, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_28, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_28, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_27
	ui->MainScreen_label_27 = lv_label_create(ui->MainScreen_contDrugValues);
	lv_label_set_text(ui->MainScreen_label_27, "Rate Def.:");
	lv_label_set_long_mode(ui->MainScreen_label_27, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_27, 4, 240);
	lv_obj_set_size(ui->MainScreen_label_27, 150, 25);

	//Write style for MainScreen_label_27, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_27, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_27, &lv_font_Alatsi_Regular_19, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_27, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_27, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_27, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_27, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_taDrugNameValue
	ui->MainScreen_taDrugNameValue = lv_textarea_create(ui->MainScreen_contDrugValues);
	lv_textarea_set_text(ui->MainScreen_taDrugNameValue, "MySyringe");
	lv_textarea_set_placeholder_text(ui->MainScreen_taDrugNameValue, "");
	lv_textarea_set_password_bullet(ui->MainScreen_taDrugNameValue, "*");
	lv_textarea_set_password_mode(ui->MainScreen_taDrugNameValue, false);
	lv_textarea_set_one_line(ui->MainScreen_taDrugNameValue, true);
	lv_textarea_set_accepted_chars(ui->MainScreen_taDrugNameValue, "");
	lv_textarea_set_max_length(ui->MainScreen_taDrugNameValue, 20);
	#if LV_USE_KEYBOARD != 0 || LV_USE_ZH_KEYBOARD != 0
		lv_obj_add_event_cb(ui->MainScreen_taDrugNameValue, ta_event_cb, LV_EVENT_ALL, ui->g_kb_MainScreen);
	#endif
	lv_obj_set_pos(ui->MainScreen_taDrugNameValue, 73, 0);
	lv_obj_set_size(ui->MainScreen_taDrugNameValue, 280, 32);

	//Write style for MainScreen_taDrugNameValue, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->MainScreen_taDrugNameValue, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_taDrugNameValue, &lv_font_Alatsi_Regular_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_taDrugNameValue, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_taDrugNameValue, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_taDrugNameValue, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_taDrugNameValue, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_taDrugNameValue, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_taDrugNameValue, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_taDrugNameValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_taDrugNameValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_taDrugNameValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_taDrugNameValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_taDrugNameValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_taDrugNameValue, 4, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_taDrugNameValue, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
	lv_obj_set_style_text_color(ui->MainScreen_taDrugNameValue, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->MainScreen_taDrugNameValue, &lv_font_Alatsi_Regular_18, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_opa(ui->MainScreen_taDrugNameValue, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_opa(ui->MainScreen_taDrugNameValue, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_color(ui->MainScreen_taDrugNameValue, lv_color_hex(0xa4e6fd), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_taDrugNameValue, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_width(ui->MainScreen_taDrugNameValue, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_shadow_width(ui->MainScreen_taDrugNameValue, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_pad_top(ui->MainScreen_taDrugNameValue, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_pad_right(ui->MainScreen_taDrugNameValue, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_pad_left(ui->MainScreen_taDrugNameValue, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_radius(ui->MainScreen_taDrugNameValue, 4, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write codes MainScreen_taDrugBrandValue
	ui->MainScreen_taDrugBrandValue = lv_textarea_create(ui->MainScreen_contDrugValues);
	lv_textarea_set_text(ui->MainScreen_taDrugBrandValue, "MySyringe");
	lv_textarea_set_placeholder_text(ui->MainScreen_taDrugBrandValue, "");
	lv_textarea_set_password_bullet(ui->MainScreen_taDrugBrandValue, "*");
	lv_textarea_set_password_mode(ui->MainScreen_taDrugBrandValue, false);
	lv_textarea_set_one_line(ui->MainScreen_taDrugBrandValue, true);
	lv_textarea_set_accepted_chars(ui->MainScreen_taDrugBrandValue, "");
	lv_textarea_set_max_length(ui->MainScreen_taDrugBrandValue, 20);
	#if LV_USE_KEYBOARD != 0 || LV_USE_ZH_KEYBOARD != 0
		lv_obj_add_event_cb(ui->MainScreen_taDrugBrandValue, ta_event_cb, LV_EVENT_ALL, ui->g_kb_MainScreen);
	#endif
	lv_obj_set_pos(ui->MainScreen_taDrugBrandValue, 73, 28);
	lv_obj_set_size(ui->MainScreen_taDrugBrandValue, 280, 30);

	//Write style for MainScreen_taDrugBrandValue, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->MainScreen_taDrugBrandValue, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_taDrugBrandValue, &lv_font_Alatsi_Regular_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_taDrugBrandValue, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_taDrugBrandValue, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_taDrugBrandValue, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_taDrugBrandValue, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_taDrugBrandValue, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_taDrugBrandValue, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_taDrugBrandValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_taDrugBrandValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_taDrugBrandValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_taDrugBrandValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_taDrugBrandValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_taDrugBrandValue, 4, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_taDrugBrandValue, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
	lv_obj_set_style_text_color(ui->MainScreen_taDrugBrandValue, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->MainScreen_taDrugBrandValue, &lv_font_Alatsi_Regular_18, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_opa(ui->MainScreen_taDrugBrandValue, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_opa(ui->MainScreen_taDrugBrandValue, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_color(ui->MainScreen_taDrugBrandValue, lv_color_hex(0xa4e6fd), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_taDrugBrandValue, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_width(ui->MainScreen_taDrugBrandValue, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_shadow_width(ui->MainScreen_taDrugBrandValue, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_pad_top(ui->MainScreen_taDrugBrandValue, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_pad_right(ui->MainScreen_taDrugBrandValue, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_pad_left(ui->MainScreen_taDrugBrandValue, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_radius(ui->MainScreen_taDrugBrandValue, 4, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write codes MainScreen_ddlistDrugId
	ui->MainScreen_ddlistDrugId = lv_dropdown_create(ui->MainScreen_contDrugValues);
	lv_dropdown_set_options(ui->MainScreen_ddlistDrugId, "ml\nug\nmg\nunit");
	lv_obj_set_pos(ui->MainScreen_ddlistDrugId, 51, 62);
	lv_obj_set_size(ui->MainScreen_ddlistDrugId, 100, 24);

	//Write style for MainScreen_ddlistDrugId, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->MainScreen_ddlistDrugId, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_ddlistDrugId, &lv_font_Alatsi_Regular_19, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_ddlistDrugId, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_ddlistDrugId, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->MainScreen_ddlistDrugId, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->MainScreen_ddlistDrugId, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->MainScreen_ddlistDrugId, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_ddlistDrugId, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_ddlistDrugId, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_ddlistDrugId, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_ddlistDrugId, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_ddlistDrugId, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_ddlistDrugId, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_ddlistDrugId, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_ddlistDrugId, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for &style_MainScreen_ddlistDrugId_extra_list_selected_checked
	static lv_style_t style_MainScreen_ddlistDrugId_extra_list_selected_checked;
	ui_init_style(&style_MainScreen_ddlistDrugId_extra_list_selected_checked);
	
	lv_style_set_border_width(&style_MainScreen_ddlistDrugId_extra_list_selected_checked, 1);
	lv_style_set_border_opa(&style_MainScreen_ddlistDrugId_extra_list_selected_checked, 255);
	lv_style_set_border_color(&style_MainScreen_ddlistDrugId_extra_list_selected_checked, lv_color_hex(0xe1e6ee));
	lv_style_set_border_side(&style_MainScreen_ddlistDrugId_extra_list_selected_checked, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_MainScreen_ddlistDrugId_extra_list_selected_checked, 3);
	lv_style_set_bg_opa(&style_MainScreen_ddlistDrugId_extra_list_selected_checked, 255);
	lv_style_set_bg_color(&style_MainScreen_ddlistDrugId_extra_list_selected_checked, lv_color_hex(0x00a1b5));
	lv_style_set_bg_grad_dir(&style_MainScreen_ddlistDrugId_extra_list_selected_checked, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->MainScreen_ddlistDrugId), &style_MainScreen_ddlistDrugId_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

	//Write style state: LV_STATE_DEFAULT for &style_MainScreen_ddlistDrugId_extra_list_main_default
	static lv_style_t style_MainScreen_ddlistDrugId_extra_list_main_default;
	ui_init_style(&style_MainScreen_ddlistDrugId_extra_list_main_default);
	
	lv_style_set_max_height(&style_MainScreen_ddlistDrugId_extra_list_main_default, 90);
	lv_style_set_text_color(&style_MainScreen_ddlistDrugId_extra_list_main_default, lv_color_hex(0x0D3055));
	lv_style_set_text_font(&style_MainScreen_ddlistDrugId_extra_list_main_default, &lv_font_Alatsi_Regular_19);
	lv_style_set_text_opa(&style_MainScreen_ddlistDrugId_extra_list_main_default, 255);
	lv_style_set_border_width(&style_MainScreen_ddlistDrugId_extra_list_main_default, 1);
	lv_style_set_border_opa(&style_MainScreen_ddlistDrugId_extra_list_main_default, 255);
	lv_style_set_border_color(&style_MainScreen_ddlistDrugId_extra_list_main_default, lv_color_hex(0xe1e6ee));
	lv_style_set_border_side(&style_MainScreen_ddlistDrugId_extra_list_main_default, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_MainScreen_ddlistDrugId_extra_list_main_default, 3);
	lv_style_set_bg_opa(&style_MainScreen_ddlistDrugId_extra_list_main_default, 255);
	lv_style_set_bg_color(&style_MainScreen_ddlistDrugId_extra_list_main_default, lv_color_hex(0xffffff));
	lv_style_set_bg_grad_dir(&style_MainScreen_ddlistDrugId_extra_list_main_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->MainScreen_ddlistDrugId), &style_MainScreen_ddlistDrugId_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_MainScreen_ddlistDrugId_extra_list_scrollbar_default
	static lv_style_t style_MainScreen_ddlistDrugId_extra_list_scrollbar_default;
	ui_init_style(&style_MainScreen_ddlistDrugId_extra_list_scrollbar_default);
	
	lv_style_set_radius(&style_MainScreen_ddlistDrugId_extra_list_scrollbar_default, 3);
	lv_style_set_bg_opa(&style_MainScreen_ddlistDrugId_extra_list_scrollbar_default, 255);
	lv_style_set_bg_color(&style_MainScreen_ddlistDrugId_extra_list_scrollbar_default, lv_color_hex(0x00ff00));
	lv_style_set_bg_grad_dir(&style_MainScreen_ddlistDrugId_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->MainScreen_ddlistDrugId), &style_MainScreen_ddlistDrugId_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write codes MainScreen_spinboxDrugmgml
	ui->MainScreen_spinboxDrugmgml = lv_spinbox_create(ui->MainScreen_contDrugValues);
	lv_obj_set_pos(ui->MainScreen_spinboxDrugmgml, 102, 90);
	lv_obj_set_width(ui->MainScreen_spinboxDrugmgml, 90);
	lv_obj_set_height(ui->MainScreen_spinboxDrugmgml, 25);
	lv_spinbox_set_digit_format(ui->MainScreen_spinboxDrugmgml, 2, 2);
	lv_spinbox_set_range(ui->MainScreen_spinboxDrugmgml, -99, 99);
	lv_coord_t MainScreen_spinboxDrugmgml_h = lv_obj_get_height(ui->MainScreen_spinboxDrugmgml);
	ui->MainScreen_spinboxDrugmgml_btn = lv_btn_create(ui->MainScreen_contDrugValues);
	lv_obj_set_size(ui->MainScreen_spinboxDrugmgml_btn, MainScreen_spinboxDrugmgml_h, MainScreen_spinboxDrugmgml_h);
	lv_obj_align_to(ui->MainScreen_spinboxDrugmgml_btn, ui->MainScreen_spinboxDrugmgml, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxDrugmgml_btn, LV_SYMBOL_PLUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxDrugmgml_btn, lv_MainScreen_spinboxDrugmgml_increment_event_cb, LV_EVENT_ALL, NULL);
	ui->MainScreen_spinboxDrugmgml_btn_minus = lv_btn_create(ui->MainScreen_contDrugValues);
	lv_obj_set_size(ui->MainScreen_spinboxDrugmgml_btn_minus, MainScreen_spinboxDrugmgml_h, MainScreen_spinboxDrugmgml_h);
	lv_obj_align_to(ui->MainScreen_spinboxDrugmgml_btn_minus, ui->MainScreen_spinboxDrugmgml, LV_ALIGN_OUT_LEFT_MID, -5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxDrugmgml_btn_minus, LV_SYMBOL_MINUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxDrugmgml_btn_minus, lv_MainScreen_spinboxDrugmgml_decrement_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_set_pos(ui->MainScreen_spinboxDrugmgml, 102, 90);

	//Write style for MainScreen_spinboxDrugmgml, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxDrugmgml, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxDrugmgml, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxDrugmgml, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_spinboxDrugmgml, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->MainScreen_spinboxDrugmgml, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->MainScreen_spinboxDrugmgml, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->MainScreen_spinboxDrugmgml, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_spinboxDrugmgml, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_spinboxDrugmgml, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_spinboxDrugmgml, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_spinboxDrugmgml, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_spinboxDrugmgml, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxDrugmgml, &lv_font_Alatsi_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxDrugmgml, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_spinboxDrugmgml, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_spinboxDrugmgml, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_spinboxDrugmgml, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_spinboxDrugmgml, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->MainScreen_spinboxDrugmgml, lv_color_hex(0x000000), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxDrugmgml, &lv_font_Alatsi_Regular_16, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxDrugmgml, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxDrugmgml, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxDrugmgml, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxDrugmgml, LV_GRAD_DIR_NONE, LV_PART_CURSOR|LV_STATE_DEFAULT);

	//Write codes MainScreen_spinboxDruguml
	ui->MainScreen_spinboxDruguml = lv_spinbox_create(ui->MainScreen_contDrugValues);
	lv_obj_set_pos(ui->MainScreen_spinboxDruguml, 102, 120);
	lv_obj_set_width(ui->MainScreen_spinboxDruguml, 90);
	lv_obj_set_height(ui->MainScreen_spinboxDruguml, 25);
	lv_spinbox_set_digit_format(ui->MainScreen_spinboxDruguml, 3, 2);
	lv_spinbox_set_range(ui->MainScreen_spinboxDruguml, -999, 999);
	lv_coord_t MainScreen_spinboxDruguml_h = lv_obj_get_height(ui->MainScreen_spinboxDruguml);
	ui->MainScreen_spinboxDruguml_btn = lv_btn_create(ui->MainScreen_contDrugValues);
	lv_obj_set_size(ui->MainScreen_spinboxDruguml_btn, MainScreen_spinboxDruguml_h, MainScreen_spinboxDruguml_h);
	lv_obj_align_to(ui->MainScreen_spinboxDruguml_btn, ui->MainScreen_spinboxDruguml, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxDruguml_btn, LV_SYMBOL_PLUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxDruguml_btn, lv_MainScreen_spinboxDruguml_increment_event_cb, LV_EVENT_ALL, NULL);
	ui->MainScreen_spinboxDruguml_btn_minus = lv_btn_create(ui->MainScreen_contDrugValues);
	lv_obj_set_size(ui->MainScreen_spinboxDruguml_btn_minus, MainScreen_spinboxDruguml_h, MainScreen_spinboxDruguml_h);
	lv_obj_align_to(ui->MainScreen_spinboxDruguml_btn_minus, ui->MainScreen_spinboxDruguml, LV_ALIGN_OUT_LEFT_MID, -5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxDruguml_btn_minus, LV_SYMBOL_MINUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxDruguml_btn_minus, lv_MainScreen_spinboxDruguml_decrement_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_set_pos(ui->MainScreen_spinboxDruguml, 102, 120);

	//Write style for MainScreen_spinboxDruguml, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxDruguml, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxDruguml, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxDruguml, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_spinboxDruguml, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->MainScreen_spinboxDruguml, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->MainScreen_spinboxDruguml, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->MainScreen_spinboxDruguml, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_spinboxDruguml, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_spinboxDruguml, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_spinboxDruguml, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_spinboxDruguml, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_spinboxDruguml, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxDruguml, &lv_font_Alatsi_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxDruguml, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_spinboxDruguml, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_spinboxDruguml, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_spinboxDruguml, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_spinboxDruguml, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->MainScreen_spinboxDruguml, lv_color_hex(0x000000), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxDruguml, &lv_font_Alatsi_Regular_16, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxDruguml, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxDruguml, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxDruguml, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxDruguml, LV_GRAD_DIR_NONE, LV_PART_CURSOR|LV_STATE_DEFAULT);

	//Write codes MainScreen_spinboxDrugperkg
	ui->MainScreen_spinboxDrugperkg = lv_spinbox_create(ui->MainScreen_contDrugValues);
	lv_obj_set_pos(ui->MainScreen_spinboxDrugperkg, 102, 150);
	lv_obj_set_width(ui->MainScreen_spinboxDrugperkg, 90);
	lv_obj_set_height(ui->MainScreen_spinboxDrugperkg, 25);
	lv_spinbox_set_digit_format(ui->MainScreen_spinboxDrugperkg, 3, 2);
	lv_spinbox_set_range(ui->MainScreen_spinboxDrugperkg, -999, 999);
	lv_coord_t MainScreen_spinboxDrugperkg_h = lv_obj_get_height(ui->MainScreen_spinboxDrugperkg);
	ui->MainScreen_spinboxDrugperkg_btn = lv_btn_create(ui->MainScreen_contDrugValues);
	lv_obj_set_size(ui->MainScreen_spinboxDrugperkg_btn, MainScreen_spinboxDrugperkg_h, MainScreen_spinboxDrugperkg_h);
	lv_obj_align_to(ui->MainScreen_spinboxDrugperkg_btn, ui->MainScreen_spinboxDrugperkg, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxDrugperkg_btn, LV_SYMBOL_PLUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxDrugperkg_btn, lv_MainScreen_spinboxDrugperkg_increment_event_cb, LV_EVENT_ALL, NULL);
	ui->MainScreen_spinboxDrugperkg_btn_minus = lv_btn_create(ui->MainScreen_contDrugValues);
	lv_obj_set_size(ui->MainScreen_spinboxDrugperkg_btn_minus, MainScreen_spinboxDrugperkg_h, MainScreen_spinboxDrugperkg_h);
	lv_obj_align_to(ui->MainScreen_spinboxDrugperkg_btn_minus, ui->MainScreen_spinboxDrugperkg, LV_ALIGN_OUT_LEFT_MID, -5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxDrugperkg_btn_minus, LV_SYMBOL_MINUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxDrugperkg_btn_minus, lv_MainScreen_spinboxDrugperkg_decrement_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_set_pos(ui->MainScreen_spinboxDrugperkg, 102, 150);

	//Write style for MainScreen_spinboxDrugperkg, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxDrugperkg, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxDrugperkg, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxDrugperkg, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_spinboxDrugperkg, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->MainScreen_spinboxDrugperkg, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->MainScreen_spinboxDrugperkg, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->MainScreen_spinboxDrugperkg, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_spinboxDrugperkg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_spinboxDrugperkg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_spinboxDrugperkg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_spinboxDrugperkg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_spinboxDrugperkg, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxDrugperkg, &lv_font_Alatsi_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxDrugperkg, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_spinboxDrugperkg, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_spinboxDrugperkg, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_spinboxDrugperkg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_spinboxDrugperkg, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->MainScreen_spinboxDrugperkg, lv_color_hex(0x000000), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxDrugperkg, &lv_font_Alatsi_Regular_16, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxDrugperkg, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxDrugperkg, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxDrugperkg, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxDrugperkg, LV_GRAD_DIR_NONE, LV_PART_CURSOR|LV_STATE_DEFAULT);

	//Write codes MainScreen_spinboxDrugRateMin
	ui->MainScreen_spinboxDrugRateMin = lv_spinbox_create(ui->MainScreen_contDrugValues);
	lv_obj_set_pos(ui->MainScreen_spinboxDrugRateMin, 115, 180);
	lv_obj_set_width(ui->MainScreen_spinboxDrugRateMin, 90);
	lv_obj_set_height(ui->MainScreen_spinboxDrugRateMin, 25);
	lv_spinbox_set_digit_format(ui->MainScreen_spinboxDrugRateMin, 3, 3);
	lv_spinbox_set_range(ui->MainScreen_spinboxDrugRateMin, -999, 999);
	lv_coord_t MainScreen_spinboxDrugRateMin_h = lv_obj_get_height(ui->MainScreen_spinboxDrugRateMin);
	ui->MainScreen_spinboxDrugRateMin_btn = lv_btn_create(ui->MainScreen_contDrugValues);
	lv_obj_set_size(ui->MainScreen_spinboxDrugRateMin_btn, MainScreen_spinboxDrugRateMin_h, MainScreen_spinboxDrugRateMin_h);
	lv_obj_align_to(ui->MainScreen_spinboxDrugRateMin_btn, ui->MainScreen_spinboxDrugRateMin, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxDrugRateMin_btn, LV_SYMBOL_PLUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxDrugRateMin_btn, lv_MainScreen_spinboxDrugRateMin_increment_event_cb, LV_EVENT_ALL, NULL);
	ui->MainScreen_spinboxDrugRateMin_btn_minus = lv_btn_create(ui->MainScreen_contDrugValues);
	lv_obj_set_size(ui->MainScreen_spinboxDrugRateMin_btn_minus, MainScreen_spinboxDrugRateMin_h, MainScreen_spinboxDrugRateMin_h);
	lv_obj_align_to(ui->MainScreen_spinboxDrugRateMin_btn_minus, ui->MainScreen_spinboxDrugRateMin, LV_ALIGN_OUT_LEFT_MID, -5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxDrugRateMin_btn_minus, LV_SYMBOL_MINUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxDrugRateMin_btn_minus, lv_MainScreen_spinboxDrugRateMin_decrement_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_set_pos(ui->MainScreen_spinboxDrugRateMin, 115, 180);

	//Write style for MainScreen_spinboxDrugRateMin, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxDrugRateMin, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxDrugRateMin, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxDrugRateMin, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_spinboxDrugRateMin, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->MainScreen_spinboxDrugRateMin, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->MainScreen_spinboxDrugRateMin, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->MainScreen_spinboxDrugRateMin, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_spinboxDrugRateMin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_spinboxDrugRateMin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_spinboxDrugRateMin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_spinboxDrugRateMin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_spinboxDrugRateMin, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxDrugRateMin, &lv_font_Alatsi_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxDrugRateMin, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_spinboxDrugRateMin, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_spinboxDrugRateMin, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_spinboxDrugRateMin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_spinboxDrugRateMin, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->MainScreen_spinboxDrugRateMin, lv_color_hex(0x000000), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxDrugRateMin, &lv_font_Alatsi_Regular_16, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxDrugRateMin, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxDrugRateMin, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxDrugRateMin, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxDrugRateMin, LV_GRAD_DIR_NONE, LV_PART_CURSOR|LV_STATE_DEFAULT);

	//Write codes MainScreen_spinboxDrugRateMax
	ui->MainScreen_spinboxDrugRateMax = lv_spinbox_create(ui->MainScreen_contDrugValues);
	lv_obj_set_pos(ui->MainScreen_spinboxDrugRateMax, 115, 210);
	lv_obj_set_width(ui->MainScreen_spinboxDrugRateMax, 90);
	lv_obj_set_height(ui->MainScreen_spinboxDrugRateMax, 25);
	lv_spinbox_set_digit_format(ui->MainScreen_spinboxDrugRateMax, 2, 2);
	lv_spinbox_set_range(ui->MainScreen_spinboxDrugRateMax, -99, 99);
	lv_coord_t MainScreen_spinboxDrugRateMax_h = lv_obj_get_height(ui->MainScreen_spinboxDrugRateMax);
	ui->MainScreen_spinboxDrugRateMax_btn = lv_btn_create(ui->MainScreen_contDrugValues);
	lv_obj_set_size(ui->MainScreen_spinboxDrugRateMax_btn, MainScreen_spinboxDrugRateMax_h, MainScreen_spinboxDrugRateMax_h);
	lv_obj_align_to(ui->MainScreen_spinboxDrugRateMax_btn, ui->MainScreen_spinboxDrugRateMax, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxDrugRateMax_btn, LV_SYMBOL_PLUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxDrugRateMax_btn, lv_MainScreen_spinboxDrugRateMax_increment_event_cb, LV_EVENT_ALL, NULL);
	ui->MainScreen_spinboxDrugRateMax_btn_minus = lv_btn_create(ui->MainScreen_contDrugValues);
	lv_obj_set_size(ui->MainScreen_spinboxDrugRateMax_btn_minus, MainScreen_spinboxDrugRateMax_h, MainScreen_spinboxDrugRateMax_h);
	lv_obj_align_to(ui->MainScreen_spinboxDrugRateMax_btn_minus, ui->MainScreen_spinboxDrugRateMax, LV_ALIGN_OUT_LEFT_MID, -5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxDrugRateMax_btn_minus, LV_SYMBOL_MINUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxDrugRateMax_btn_minus, lv_MainScreen_spinboxDrugRateMax_decrement_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_set_pos(ui->MainScreen_spinboxDrugRateMax, 115, 210);

	//Write style for MainScreen_spinboxDrugRateMax, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxDrugRateMax, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxDrugRateMax, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxDrugRateMax, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_spinboxDrugRateMax, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->MainScreen_spinboxDrugRateMax, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->MainScreen_spinboxDrugRateMax, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->MainScreen_spinboxDrugRateMax, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_spinboxDrugRateMax, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_spinboxDrugRateMax, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_spinboxDrugRateMax, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_spinboxDrugRateMax, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_spinboxDrugRateMax, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxDrugRateMax, &lv_font_Alatsi_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxDrugRateMax, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_spinboxDrugRateMax, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_spinboxDrugRateMax, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_spinboxDrugRateMax, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_spinboxDrugRateMax, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->MainScreen_spinboxDrugRateMax, lv_color_hex(0x000000), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxDrugRateMax, &lv_font_Alatsi_Regular_16, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxDrugRateMax, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxDrugRateMax, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxDrugRateMax, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxDrugRateMax, LV_GRAD_DIR_NONE, LV_PART_CURSOR|LV_STATE_DEFAULT);

	//Write codes MainScreen_spinboxDrugRateDef
	ui->MainScreen_spinboxDrugRateDef = lv_spinbox_create(ui->MainScreen_contDrugValues);
	lv_obj_set_pos(ui->MainScreen_spinboxDrugRateDef, 115, 240);
	lv_obj_set_width(ui->MainScreen_spinboxDrugRateDef, 90);
	lv_obj_set_height(ui->MainScreen_spinboxDrugRateDef, 25);
	lv_spinbox_set_digit_format(ui->MainScreen_spinboxDrugRateDef, 2, 2);
	lv_spinbox_set_range(ui->MainScreen_spinboxDrugRateDef, -99, 99);
	lv_coord_t MainScreen_spinboxDrugRateDef_h = lv_obj_get_height(ui->MainScreen_spinboxDrugRateDef);
	ui->MainScreen_spinboxDrugRateDef_btn = lv_btn_create(ui->MainScreen_contDrugValues);
	lv_obj_set_size(ui->MainScreen_spinboxDrugRateDef_btn, MainScreen_spinboxDrugRateDef_h, MainScreen_spinboxDrugRateDef_h);
	lv_obj_align_to(ui->MainScreen_spinboxDrugRateDef_btn, ui->MainScreen_spinboxDrugRateDef, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxDrugRateDef_btn, LV_SYMBOL_PLUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxDrugRateDef_btn, lv_MainScreen_spinboxDrugRateDef_increment_event_cb, LV_EVENT_ALL, NULL);
	ui->MainScreen_spinboxDrugRateDef_btn_minus = lv_btn_create(ui->MainScreen_contDrugValues);
	lv_obj_set_size(ui->MainScreen_spinboxDrugRateDef_btn_minus, MainScreen_spinboxDrugRateDef_h, MainScreen_spinboxDrugRateDef_h);
	lv_obj_align_to(ui->MainScreen_spinboxDrugRateDef_btn_minus, ui->MainScreen_spinboxDrugRateDef, LV_ALIGN_OUT_LEFT_MID, -5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxDrugRateDef_btn_minus, LV_SYMBOL_MINUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxDrugRateDef_btn_minus, lv_MainScreen_spinboxDrugRateDef_decrement_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_set_pos(ui->MainScreen_spinboxDrugRateDef, 115, 240);

	//Write style for MainScreen_spinboxDrugRateDef, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxDrugRateDef, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxDrugRateDef, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxDrugRateDef, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_spinboxDrugRateDef, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->MainScreen_spinboxDrugRateDef, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->MainScreen_spinboxDrugRateDef, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->MainScreen_spinboxDrugRateDef, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_spinboxDrugRateDef, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_spinboxDrugRateDef, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_spinboxDrugRateDef, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_spinboxDrugRateDef, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_spinboxDrugRateDef, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxDrugRateDef, &lv_font_Alatsi_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxDrugRateDef, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_spinboxDrugRateDef, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_spinboxDrugRateDef, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_spinboxDrugRateDef, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_spinboxDrugRateDef, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->MainScreen_spinboxDrugRateDef, lv_color_hex(0x000000), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxDrugRateDef, &lv_font_Alatsi_Regular_16, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxDrugRateDef, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxDrugRateDef, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxDrugRateDef, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxDrugRateDef, LV_GRAD_DIR_NONE, LV_PART_CURSOR|LV_STATE_DEFAULT);

	//Write codes MainScreen_labelDrugHeader
	ui->MainScreen_labelDrugHeader = lv_label_create(ui->MainScreen_contDrug);
	lv_label_set_text(ui->MainScreen_labelDrugHeader, "Select Drug");
	lv_label_set_long_mode(ui->MainScreen_labelDrugHeader, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_labelDrugHeader, 0, 0);
	lv_obj_set_size(ui->MainScreen_labelDrugHeader, 800, 30);

	//Write style for MainScreen_labelDrugHeader, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_labelDrugHeader, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_labelDrugHeader, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_labelDrugHeader, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_labelDrugHeader, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_labelDrugHeader, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_labelDrugHeader, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_labelDrugHeader, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_labelDrugHeader, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_labelDrugHeader, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_labelDrugHeader, lv_color_hex(0x324e75), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_labelDrugHeader, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_labelDrugHeader, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_labelDrugHeader, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_labelDrugHeader, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_labelDrugHeader, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_labelDrugHeader, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_btnDummyDrug
	ui->MainScreen_btnDummyDrug = lv_btn_create(ui->MainScreen_contDrug);
	ui->MainScreen_btnDummyDrug_label = lv_label_create(ui->MainScreen_btnDummyDrug);
	lv_label_set_text(ui->MainScreen_btnDummyDrug_label, "");
	lv_label_set_long_mode(ui->MainScreen_btnDummyDrug_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->MainScreen_btnDummyDrug_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->MainScreen_btnDummyDrug, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->MainScreen_btnDummyDrug_label, LV_PCT(100));
	lv_obj_set_pos(ui->MainScreen_btnDummyDrug, 773, 199);
	lv_obj_set_size(ui->MainScreen_btnDummyDrug, 8, 10);

	//Write style for MainScreen_btnDummyDrug, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_btnDummyDrug, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_btnDummyDrug, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_btnDummyDrug, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_btnDummyDrug, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_btnDummyDrug, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_btnDummyDrug, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_btnDummyDrug, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_btnDummyDrug, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_contMode
	ui->MainScreen_contMode = lv_obj_create(ui->MainScreen);
	lv_obj_set_pos(ui->MainScreen_contMode, 800, 80);
	lv_obj_set_size(ui->MainScreen_contMode, 800, 300);
	lv_obj_set_scrollbar_mode(ui->MainScreen_contMode, LV_SCROLLBAR_MODE_OFF);

	//Write style for MainScreen_contMode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_contMode, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->MainScreen_contMode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->MainScreen_contMode, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->MainScreen_contMode, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_contMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_contMode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_contMode, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_contMode, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_contMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_contMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_contMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_contMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_contMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_btnGoMenuMode
	ui->MainScreen_btnGoMenuMode = lv_btn_create(ui->MainScreen_contMode);
	ui->MainScreen_btnGoMenuMode_label = lv_label_create(ui->MainScreen_btnGoMenuMode);
	lv_label_set_text(ui->MainScreen_btnGoMenuMode_label, "");
	lv_label_set_long_mode(ui->MainScreen_btnGoMenuMode_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->MainScreen_btnGoMenuMode_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->MainScreen_btnGoMenuMode, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->MainScreen_btnGoMenuMode_label, LV_PCT(100));
	lv_obj_set_pos(ui->MainScreen_btnGoMenuMode, 731, 247);
	lv_obj_set_size(ui->MainScreen_btnGoMenuMode, 58, 44);

	//Write style for MainScreen_btnGoMenuMode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_btnGoMenuMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_btnGoMenuMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_btnGoMenuMode, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_btnGoMenuMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_btnGoMenuMode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_btnGoMenuMode, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_btnGoMenuMode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_btnGoMenuMode, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_listModeMode
	ui->MainScreen_listModeMode = lv_list_create(ui->MainScreen_contMode);
	ui->MainScreen_listModeMode_item0 = lv_list_add_btn(ui->MainScreen_listModeMode, LV_SYMBOL_SAVE, "Volume / Mass / Dosage");
	ui->MainScreen_listModeMode_item1 = lv_list_add_btn(ui->MainScreen_listModeMode, LV_SYMBOL_SAVE, "Time");
	ui->MainScreen_listModeMode_item2 = lv_list_add_btn(ui->MainScreen_listModeMode, LV_SYMBOL_SAVE, "Body Weight");
	ui->MainScreen_listModeMode_item3 = lv_list_add_btn(ui->MainScreen_listModeMode, LV_SYMBOL_SAVE, "Intermittent");
	ui->MainScreen_listModeMode_item4 = lv_list_add_btn(ui->MainScreen_listModeMode, LV_SYMBOL_SAVE, "Rhythmic");
	ui->MainScreen_listModeMode_item5 = lv_list_add_btn(ui->MainScreen_listModeMode, LV_SYMBOL_SAVE, "Linear Scale");
	lv_obj_set_pos(ui->MainScreen_listModeMode, -2, 27);
	lv_obj_set_size(ui->MainScreen_listModeMode, 399, 160);
	lv_obj_set_scrollbar_mode(ui->MainScreen_listModeMode, LV_SCROLLBAR_MODE_AUTO);

	//Write style state: LV_STATE_DEFAULT for &style_MainScreen_listModeMode_main_main_default
	static lv_style_t style_MainScreen_listModeMode_main_main_default;
	ui_init_style(&style_MainScreen_listModeMode_main_main_default);
	
	lv_style_set_pad_top(&style_MainScreen_listModeMode_main_main_default, 0);
	lv_style_set_pad_left(&style_MainScreen_listModeMode_main_main_default, 0);
	lv_style_set_pad_right(&style_MainScreen_listModeMode_main_main_default, 0);
	lv_style_set_pad_bottom(&style_MainScreen_listModeMode_main_main_default, 0);
	lv_style_set_bg_opa(&style_MainScreen_listModeMode_main_main_default, 255);
	lv_style_set_bg_color(&style_MainScreen_listModeMode_main_main_default, lv_color_hex(0x000000));
	lv_style_set_bg_grad_dir(&style_MainScreen_listModeMode_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_border_width(&style_MainScreen_listModeMode_main_main_default, 2);
	lv_style_set_border_opa(&style_MainScreen_listModeMode_main_main_default, 255);
	lv_style_set_border_color(&style_MainScreen_listModeMode_main_main_default, lv_color_hex(0x008dff));
	lv_style_set_border_side(&style_MainScreen_listModeMode_main_main_default, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_MainScreen_listModeMode_main_main_default, 0);
	lv_style_set_shadow_width(&style_MainScreen_listModeMode_main_main_default, 0);
	lv_obj_add_style(ui->MainScreen_listModeMode, &style_MainScreen_listModeMode_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_MainScreen_listModeMode_main_scrollbar_default
	static lv_style_t style_MainScreen_listModeMode_main_scrollbar_default;
	ui_init_style(&style_MainScreen_listModeMode_main_scrollbar_default);
	
	lv_style_set_radius(&style_MainScreen_listModeMode_main_scrollbar_default, 3);
	lv_style_set_bg_opa(&style_MainScreen_listModeMode_main_scrollbar_default, 255);
	lv_style_set_bg_color(&style_MainScreen_listModeMode_main_scrollbar_default, lv_color_hex(0x9e9e9e));
	lv_style_set_bg_grad_dir(&style_MainScreen_listModeMode_main_scrollbar_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(ui->MainScreen_listModeMode, &style_MainScreen_listModeMode_main_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_MainScreen_listModeMode_extra_btns_main_default
	static lv_style_t style_MainScreen_listModeMode_extra_btns_main_default;
	ui_init_style(&style_MainScreen_listModeMode_extra_btns_main_default);
	
	lv_style_set_pad_top(&style_MainScreen_listModeMode_extra_btns_main_default, 2);
	lv_style_set_pad_left(&style_MainScreen_listModeMode_extra_btns_main_default, 2);
	lv_style_set_pad_right(&style_MainScreen_listModeMode_extra_btns_main_default, 2);
	lv_style_set_pad_bottom(&style_MainScreen_listModeMode_extra_btns_main_default, 2);
	lv_style_set_border_width(&style_MainScreen_listModeMode_extra_btns_main_default, 0);
	lv_style_set_text_color(&style_MainScreen_listModeMode_extra_btns_main_default, lv_color_hex(0xffffff));
	lv_style_set_text_font(&style_MainScreen_listModeMode_extra_btns_main_default, &lv_font_calibrib_18);
	lv_style_set_text_opa(&style_MainScreen_listModeMode_extra_btns_main_default, 255);
	lv_style_set_radius(&style_MainScreen_listModeMode_extra_btns_main_default, 3);
	lv_style_set_bg_opa(&style_MainScreen_listModeMode_extra_btns_main_default, 255);
	lv_style_set_bg_color(&style_MainScreen_listModeMode_extra_btns_main_default, lv_color_hex(0x000000));
	lv_style_set_bg_grad_dir(&style_MainScreen_listModeMode_extra_btns_main_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(ui->MainScreen_listModeMode_item5, &style_MainScreen_listModeMode_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listModeMode_item4, &style_MainScreen_listModeMode_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listModeMode_item3, &style_MainScreen_listModeMode_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listModeMode_item2, &style_MainScreen_listModeMode_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listModeMode_item1, &style_MainScreen_listModeMode_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listModeMode_item0, &style_MainScreen_listModeMode_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_FOCUSED for &style_MainScreen_listModeMode_extra_btns_main_focused
	static lv_style_t style_MainScreen_listModeMode_extra_btns_main_focused;
	ui_init_style(&style_MainScreen_listModeMode_extra_btns_main_focused);
	
	lv_style_set_pad_top(&style_MainScreen_listModeMode_extra_btns_main_focused, 2);
	lv_style_set_pad_left(&style_MainScreen_listModeMode_extra_btns_main_focused, 2);
	lv_style_set_pad_right(&style_MainScreen_listModeMode_extra_btns_main_focused, 2);
	lv_style_set_pad_bottom(&style_MainScreen_listModeMode_extra_btns_main_focused, 2);
	lv_style_set_border_width(&style_MainScreen_listModeMode_extra_btns_main_focused, 0);
	lv_style_set_radius(&style_MainScreen_listModeMode_extra_btns_main_focused, 3);
	lv_style_set_text_color(&style_MainScreen_listModeMode_extra_btns_main_focused, lv_color_hex(0xffffff));
	lv_style_set_text_font(&style_MainScreen_listModeMode_extra_btns_main_focused, &lv_font_calibrib_18);
	lv_style_set_text_opa(&style_MainScreen_listModeMode_extra_btns_main_focused, 255);
	lv_style_set_bg_opa(&style_MainScreen_listModeMode_extra_btns_main_focused, 255);
	lv_style_set_bg_color(&style_MainScreen_listModeMode_extra_btns_main_focused, lv_color_hex(0x0016ff));
	lv_style_set_bg_grad_dir(&style_MainScreen_listModeMode_extra_btns_main_focused, LV_GRAD_DIR_NONE);
	lv_obj_add_style(ui->MainScreen_listModeMode_item5, &style_MainScreen_listModeMode_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listModeMode_item4, &style_MainScreen_listModeMode_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listModeMode_item3, &style_MainScreen_listModeMode_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listModeMode_item2, &style_MainScreen_listModeMode_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listModeMode_item1, &style_MainScreen_listModeMode_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listModeMode_item0, &style_MainScreen_listModeMode_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write codes MainScreen_listModeUnit
	ui->MainScreen_listModeUnit = lv_list_create(ui->MainScreen_contMode);
	ui->MainScreen_listModeUnit_item0 = lv_list_add_btn(ui->MainScreen_listModeUnit, LV_SYMBOL_SAVE, "save_1");
	ui->MainScreen_listModeUnit_item1 = lv_list_add_btn(ui->MainScreen_listModeUnit, LV_SYMBOL_SAVE, "save_2");
	ui->MainScreen_listModeUnit_item2 = lv_list_add_btn(ui->MainScreen_listModeUnit, LV_SYMBOL_SAVE, "save_3");
	ui->MainScreen_listModeUnit_item3 = lv_list_add_btn(ui->MainScreen_listModeUnit, LV_SYMBOL_SAVE, "save_4");
	ui->MainScreen_listModeUnit_item4 = lv_list_add_btn(ui->MainScreen_listModeUnit, LV_SYMBOL_SAVE, "save_5");
	ui->MainScreen_listModeUnit_item5 = lv_list_add_btn(ui->MainScreen_listModeUnit, LV_SYMBOL_SAVE, "save_6");
	ui->MainScreen_listModeUnit_item6 = lv_list_add_btn(ui->MainScreen_listModeUnit, LV_SYMBOL_SAVE, "save_7");
	ui->MainScreen_listModeUnit_item7 = lv_list_add_btn(ui->MainScreen_listModeUnit, LV_SYMBOL_SAVE, "save_8");
	lv_obj_set_pos(ui->MainScreen_listModeUnit, 399, 28);
	lv_obj_set_size(ui->MainScreen_listModeUnit, 400, 160);
	lv_obj_set_scrollbar_mode(ui->MainScreen_listModeUnit, LV_SCROLLBAR_MODE_AUTO);

	//Write style state: LV_STATE_DEFAULT for &style_MainScreen_listModeUnit_main_main_default
	static lv_style_t style_MainScreen_listModeUnit_main_main_default;
	ui_init_style(&style_MainScreen_listModeUnit_main_main_default);
	
	lv_style_set_pad_top(&style_MainScreen_listModeUnit_main_main_default, 0);
	lv_style_set_pad_left(&style_MainScreen_listModeUnit_main_main_default, 0);
	lv_style_set_pad_right(&style_MainScreen_listModeUnit_main_main_default, 0);
	lv_style_set_pad_bottom(&style_MainScreen_listModeUnit_main_main_default, 0);
	lv_style_set_bg_opa(&style_MainScreen_listModeUnit_main_main_default, 255);
	lv_style_set_bg_color(&style_MainScreen_listModeUnit_main_main_default, lv_color_hex(0x000000));
	lv_style_set_bg_grad_dir(&style_MainScreen_listModeUnit_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_border_width(&style_MainScreen_listModeUnit_main_main_default, 2);
	lv_style_set_border_opa(&style_MainScreen_listModeUnit_main_main_default, 255);
	lv_style_set_border_color(&style_MainScreen_listModeUnit_main_main_default, lv_color_hex(0x008dff));
	lv_style_set_border_side(&style_MainScreen_listModeUnit_main_main_default, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_MainScreen_listModeUnit_main_main_default, 0);
	lv_style_set_shadow_width(&style_MainScreen_listModeUnit_main_main_default, 0);
	lv_obj_add_style(ui->MainScreen_listModeUnit, &style_MainScreen_listModeUnit_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_MainScreen_listModeUnit_main_scrollbar_default
	static lv_style_t style_MainScreen_listModeUnit_main_scrollbar_default;
	ui_init_style(&style_MainScreen_listModeUnit_main_scrollbar_default);
	
	lv_style_set_radius(&style_MainScreen_listModeUnit_main_scrollbar_default, 3);
	lv_style_set_bg_opa(&style_MainScreen_listModeUnit_main_scrollbar_default, 255);
	lv_style_set_bg_color(&style_MainScreen_listModeUnit_main_scrollbar_default, lv_color_hex(0x9e9e9e));
	lv_style_set_bg_grad_dir(&style_MainScreen_listModeUnit_main_scrollbar_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(ui->MainScreen_listModeUnit, &style_MainScreen_listModeUnit_main_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_MainScreen_listModeUnit_extra_btns_main_default
	static lv_style_t style_MainScreen_listModeUnit_extra_btns_main_default;
	ui_init_style(&style_MainScreen_listModeUnit_extra_btns_main_default);
	
	lv_style_set_pad_top(&style_MainScreen_listModeUnit_extra_btns_main_default, 2);
	lv_style_set_pad_left(&style_MainScreen_listModeUnit_extra_btns_main_default, 2);
	lv_style_set_pad_right(&style_MainScreen_listModeUnit_extra_btns_main_default, 2);
	lv_style_set_pad_bottom(&style_MainScreen_listModeUnit_extra_btns_main_default, 2);
	lv_style_set_border_width(&style_MainScreen_listModeUnit_extra_btns_main_default, 0);
	lv_style_set_text_color(&style_MainScreen_listModeUnit_extra_btns_main_default, lv_color_hex(0xffffff));
	lv_style_set_text_font(&style_MainScreen_listModeUnit_extra_btns_main_default, &lv_font_calibrib_18);
	lv_style_set_text_opa(&style_MainScreen_listModeUnit_extra_btns_main_default, 255);
	lv_style_set_radius(&style_MainScreen_listModeUnit_extra_btns_main_default, 3);
	lv_style_set_bg_opa(&style_MainScreen_listModeUnit_extra_btns_main_default, 255);
	lv_style_set_bg_color(&style_MainScreen_listModeUnit_extra_btns_main_default, lv_color_hex(0x000000));
	lv_style_set_bg_grad_dir(&style_MainScreen_listModeUnit_extra_btns_main_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(ui->MainScreen_listModeUnit_item7, &style_MainScreen_listModeUnit_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listModeUnit_item6, &style_MainScreen_listModeUnit_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listModeUnit_item5, &style_MainScreen_listModeUnit_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listModeUnit_item4, &style_MainScreen_listModeUnit_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listModeUnit_item3, &style_MainScreen_listModeUnit_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listModeUnit_item2, &style_MainScreen_listModeUnit_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listModeUnit_item1, &style_MainScreen_listModeUnit_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->MainScreen_listModeUnit_item0, &style_MainScreen_listModeUnit_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_FOCUSED for &style_MainScreen_listModeUnit_extra_btns_main_focused
	static lv_style_t style_MainScreen_listModeUnit_extra_btns_main_focused;
	ui_init_style(&style_MainScreen_listModeUnit_extra_btns_main_focused);
	
	lv_style_set_pad_top(&style_MainScreen_listModeUnit_extra_btns_main_focused, 2);
	lv_style_set_pad_left(&style_MainScreen_listModeUnit_extra_btns_main_focused, 2);
	lv_style_set_pad_right(&style_MainScreen_listModeUnit_extra_btns_main_focused, 2);
	lv_style_set_pad_bottom(&style_MainScreen_listModeUnit_extra_btns_main_focused, 2);
	lv_style_set_border_width(&style_MainScreen_listModeUnit_extra_btns_main_focused, 0);
	lv_style_set_radius(&style_MainScreen_listModeUnit_extra_btns_main_focused, 3);
	lv_style_set_text_color(&style_MainScreen_listModeUnit_extra_btns_main_focused, lv_color_hex(0xffffff));
	lv_style_set_text_font(&style_MainScreen_listModeUnit_extra_btns_main_focused, &lv_font_calibrib_18);
	lv_style_set_text_opa(&style_MainScreen_listModeUnit_extra_btns_main_focused, 255);
	lv_style_set_bg_opa(&style_MainScreen_listModeUnit_extra_btns_main_focused, 255);
	lv_style_set_bg_color(&style_MainScreen_listModeUnit_extra_btns_main_focused, lv_color_hex(0x0016ff));
	lv_style_set_bg_grad_dir(&style_MainScreen_listModeUnit_extra_btns_main_focused, LV_GRAD_DIR_NONE);
	lv_obj_add_style(ui->MainScreen_listModeUnit_item7, &style_MainScreen_listModeUnit_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listModeUnit_item6, &style_MainScreen_listModeUnit_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listModeUnit_item5, &style_MainScreen_listModeUnit_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listModeUnit_item4, &style_MainScreen_listModeUnit_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listModeUnit_item3, &style_MainScreen_listModeUnit_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listModeUnit_item2, &style_MainScreen_listModeUnit_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listModeUnit_item1, &style_MainScreen_listModeUnit_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->MainScreen_listModeUnit_item0, &style_MainScreen_listModeUnit_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write style state: LV_STATE_DEFAULT for &style_MainScreen_listModeUnit_extra_texts_main_default
	static lv_style_t style_MainScreen_listModeUnit_extra_texts_main_default;
	ui_init_style(&style_MainScreen_listModeUnit_extra_texts_main_default);
	
	lv_style_set_pad_top(&style_MainScreen_listModeUnit_extra_texts_main_default, 5);
	lv_style_set_pad_left(&style_MainScreen_listModeUnit_extra_texts_main_default, 5);
	lv_style_set_pad_right(&style_MainScreen_listModeUnit_extra_texts_main_default, 5);
	lv_style_set_pad_bottom(&style_MainScreen_listModeUnit_extra_texts_main_default, 5);
	lv_style_set_border_width(&style_MainScreen_listModeUnit_extra_texts_main_default, 0);
	lv_style_set_text_color(&style_MainScreen_listModeUnit_extra_texts_main_default, lv_color_hex(0xffffff));
	lv_style_set_text_font(&style_MainScreen_listModeUnit_extra_texts_main_default, &lv_font_arial_14);
	lv_style_set_text_opa(&style_MainScreen_listModeUnit_extra_texts_main_default, 255);
	lv_style_set_radius(&style_MainScreen_listModeUnit_extra_texts_main_default, 3);
	lv_style_set_bg_opa(&style_MainScreen_listModeUnit_extra_texts_main_default, 255);
	lv_style_set_bg_color(&style_MainScreen_listModeUnit_extra_texts_main_default, lv_color_hex(0x000000));
	lv_style_set_bg_grad_dir(&style_MainScreen_listModeUnit_extra_texts_main_default, LV_GRAD_DIR_NONE);

	//Write codes MainScreen_contModeValues
	ui->MainScreen_contModeValues = lv_obj_create(ui->MainScreen_contMode);
	lv_obj_set_pos(ui->MainScreen_contModeValues, 0, 190);
	lv_obj_set_size(ui->MainScreen_contModeValues, 688, 108);
	lv_obj_set_scrollbar_mode(ui->MainScreen_contModeValues, LV_SCROLLBAR_MODE_OFF);

	//Write style for MainScreen_contModeValues, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_contModeValues, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_contModeValues, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_contModeValues, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_contModeValues, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_contModeValues, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_contModeValues, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_contModeValues, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_contModeValues, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_contModeValues, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_contModeValues, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_contModeValueWeight
	ui->MainScreen_contModeValueWeight = lv_obj_create(ui->MainScreen_contModeValues);
	lv_obj_set_pos(ui->MainScreen_contModeValueWeight, 212, 72);
	lv_obj_set_size(ui->MainScreen_contModeValueWeight, 400, 36);
	lv_obj_set_scrollbar_mode(ui->MainScreen_contModeValueWeight, LV_SCROLLBAR_MODE_OFF);

	//Write style for MainScreen_contModeValueWeight, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_contModeValueWeight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_contModeValueWeight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_contModeValueWeight, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_contModeValueWeight, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_contModeValueWeight, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_contModeValueWeight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_contModeValueWeight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_contModeValueWeight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_contModeValueWeight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_contModeValueWeight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_33
	ui->MainScreen_label_33 = lv_label_create(ui->MainScreen_contModeValueWeight);
	lv_label_set_text(ui->MainScreen_label_33, "Body Weight:");
	lv_label_set_long_mode(ui->MainScreen_label_33, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_33, 24, 5);
	lv_obj_set_size(ui->MainScreen_label_33, 137, 25);

	//Write style for MainScreen_label_33, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_33, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_33, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_33, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_33, &lv_font_Alatsi_Regular_19, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_33, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_33, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_33, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_33, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_33, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_33, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_33, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_33, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_33, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_33, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_38
	ui->MainScreen_label_38 = lv_label_create(ui->MainScreen_contModeValueWeight);
	lv_label_set_text(ui->MainScreen_label_38, "kg");
	lv_label_set_long_mode(ui->MainScreen_label_38, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_38, 258, 4);
	lv_obj_set_size(ui->MainScreen_label_38, 110, 25);

	//Write style for MainScreen_label_38, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_38, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_38, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_38, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_38, &lv_font_Alatsi_Regular_19, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_38, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_38, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_38, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_38, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_38, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_38, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_38, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_38, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_38, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_38, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_spinboxModeBodyWeight
	ui->MainScreen_spinboxModeBodyWeight = lv_spinbox_create(ui->MainScreen_contModeValueWeight);
	lv_obj_set_pos(ui->MainScreen_spinboxModeBodyWeight, 173, 4);
	lv_obj_set_width(ui->MainScreen_spinboxModeBodyWeight, 40);
	lv_obj_set_height(ui->MainScreen_spinboxModeBodyWeight, 25);
	lv_spinbox_set_digit_format(ui->MainScreen_spinboxModeBodyWeight, 3, 3);
	lv_spinbox_set_range(ui->MainScreen_spinboxModeBodyWeight, -999, 999);
	lv_coord_t MainScreen_spinboxModeBodyWeight_h = lv_obj_get_height(ui->MainScreen_spinboxModeBodyWeight);
	ui->MainScreen_spinboxModeBodyWeight_btn = lv_btn_create(ui->MainScreen_contModeValueWeight);
	lv_obj_set_size(ui->MainScreen_spinboxModeBodyWeight_btn, MainScreen_spinboxModeBodyWeight_h, MainScreen_spinboxModeBodyWeight_h);
	lv_obj_align_to(ui->MainScreen_spinboxModeBodyWeight_btn, ui->MainScreen_spinboxModeBodyWeight, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxModeBodyWeight_btn, LV_SYMBOL_PLUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxModeBodyWeight_btn, lv_MainScreen_spinboxModeBodyWeight_increment_event_cb, LV_EVENT_ALL, NULL);
	ui->MainScreen_spinboxModeBodyWeight_btn_minus = lv_btn_create(ui->MainScreen_contModeValueWeight);
	lv_obj_set_size(ui->MainScreen_spinboxModeBodyWeight_btn_minus, MainScreen_spinboxModeBodyWeight_h, MainScreen_spinboxModeBodyWeight_h);
	lv_obj_align_to(ui->MainScreen_spinboxModeBodyWeight_btn_minus, ui->MainScreen_spinboxModeBodyWeight, LV_ALIGN_OUT_LEFT_MID, -5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxModeBodyWeight_btn_minus, LV_SYMBOL_MINUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxModeBodyWeight_btn_minus, lv_MainScreen_spinboxModeBodyWeight_decrement_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_set_pos(ui->MainScreen_spinboxModeBodyWeight, 173, 4);

	//Write style for MainScreen_spinboxModeBodyWeight, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxModeBodyWeight, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxModeBodyWeight, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxModeBodyWeight, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_spinboxModeBodyWeight, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->MainScreen_spinboxModeBodyWeight, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->MainScreen_spinboxModeBodyWeight, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->MainScreen_spinboxModeBodyWeight, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_spinboxModeBodyWeight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_spinboxModeBodyWeight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_spinboxModeBodyWeight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_spinboxModeBodyWeight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_spinboxModeBodyWeight, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxModeBodyWeight, &lv_font_Alatsi_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxModeBodyWeight, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_spinboxModeBodyWeight, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_spinboxModeBodyWeight, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_spinboxModeBodyWeight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_spinboxModeBodyWeight, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->MainScreen_spinboxModeBodyWeight, lv_color_hex(0x000000), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxModeBodyWeight, &lv_font_Alatsi_Regular_16, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxModeBodyWeight, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxModeBodyWeight, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxModeBodyWeight, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxModeBodyWeight, LV_GRAD_DIR_NONE, LV_PART_CURSOR|LV_STATE_DEFAULT);

	//Write codes MainScreen_contModeValueInfusionRate
	ui->MainScreen_contModeValueInfusionRate = lv_obj_create(ui->MainScreen_contModeValues);
	lv_obj_set_pos(ui->MainScreen_contModeValueInfusionRate, 212, 36);
	lv_obj_set_size(ui->MainScreen_contModeValueInfusionRate, 400, 35);
	lv_obj_set_scrollbar_mode(ui->MainScreen_contModeValueInfusionRate, LV_SCROLLBAR_MODE_OFF);

	//Write style for MainScreen_contModeValueInfusionRate, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_contModeValueInfusionRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_contModeValueInfusionRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_contModeValueInfusionRate, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_contModeValueInfusionRate, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_contModeValueInfusionRate, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_contModeValueInfusionRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_contModeValueInfusionRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_contModeValueInfusionRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_contModeValueInfusionRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_contModeValueInfusionRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_39
	ui->MainScreen_label_39 = lv_label_create(ui->MainScreen_contModeValueInfusionRate);
	lv_label_set_text(ui->MainScreen_label_39, "Infusion Rate:");
	lv_label_set_long_mode(ui->MainScreen_label_39, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_39, 24, 5);
	lv_obj_set_size(ui->MainScreen_label_39, 147, 25);

	//Write style for MainScreen_label_39, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_39, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_39, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_39, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_39, &lv_font_Alatsi_Regular_19, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_39, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_39, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_39, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_39, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_39, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_39, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_39, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_39, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_39, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_39, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_labelModeInfusionRateUnit
	ui->MainScreen_labelModeInfusionRateUnit = lv_label_create(ui->MainScreen_contModeValueInfusionRate);
	lv_label_set_text(ui->MainScreen_labelModeInfusionRateUnit, "Unit/Kg/h\n");
	lv_label_set_long_mode(ui->MainScreen_labelModeInfusionRateUnit, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_labelModeInfusionRateUnit, 255, 5);
	lv_obj_set_size(ui->MainScreen_labelModeInfusionRateUnit, 130, 23);

	//Write style for MainScreen_labelModeInfusionRateUnit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_labelModeInfusionRateUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_labelModeInfusionRateUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_labelModeInfusionRateUnit, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_labelModeInfusionRateUnit, &lv_font_Alatsi_Regular_19, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_labelModeInfusionRateUnit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_labelModeInfusionRateUnit, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_labelModeInfusionRateUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_labelModeInfusionRateUnit, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_labelModeInfusionRateUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_labelModeInfusionRateUnit, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_labelModeInfusionRateUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_labelModeInfusionRateUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_labelModeInfusionRateUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_labelModeInfusionRateUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_spinboxModeInfusionRate
	ui->MainScreen_spinboxModeInfusionRate = lv_spinbox_create(ui->MainScreen_contModeValueInfusionRate);
	lv_obj_set_pos(ui->MainScreen_spinboxModeInfusionRate, 166, 5);
	lv_obj_set_width(ui->MainScreen_spinboxModeInfusionRate, 60);
	lv_obj_set_height(ui->MainScreen_spinboxModeInfusionRate, 25);
	lv_spinbox_set_digit_format(ui->MainScreen_spinboxModeInfusionRate, 3, 2);
	lv_spinbox_set_range(ui->MainScreen_spinboxModeInfusionRate, -999, 999);
	lv_coord_t MainScreen_spinboxModeInfusionRate_h = lv_obj_get_height(ui->MainScreen_spinboxModeInfusionRate);
	ui->MainScreen_spinboxModeInfusionRate_btn = lv_btn_create(ui->MainScreen_contModeValueInfusionRate);
	lv_obj_set_size(ui->MainScreen_spinboxModeInfusionRate_btn, MainScreen_spinboxModeInfusionRate_h, MainScreen_spinboxModeInfusionRate_h);
	lv_obj_align_to(ui->MainScreen_spinboxModeInfusionRate_btn, ui->MainScreen_spinboxModeInfusionRate, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxModeInfusionRate_btn, LV_SYMBOL_PLUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxModeInfusionRate_btn, lv_MainScreen_spinboxModeInfusionRate_increment_event_cb, LV_EVENT_ALL, NULL);
	ui->MainScreen_spinboxModeInfusionRate_btn_minus = lv_btn_create(ui->MainScreen_contModeValueInfusionRate);
	lv_obj_set_size(ui->MainScreen_spinboxModeInfusionRate_btn_minus, MainScreen_spinboxModeInfusionRate_h, MainScreen_spinboxModeInfusionRate_h);
	lv_obj_align_to(ui->MainScreen_spinboxModeInfusionRate_btn_minus, ui->MainScreen_spinboxModeInfusionRate, LV_ALIGN_OUT_LEFT_MID, -5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxModeInfusionRate_btn_minus, LV_SYMBOL_MINUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxModeInfusionRate_btn_minus, lv_MainScreen_spinboxModeInfusionRate_decrement_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_set_pos(ui->MainScreen_spinboxModeInfusionRate, 166, 5);

	//Write style for MainScreen_spinboxModeInfusionRate, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxModeInfusionRate, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxModeInfusionRate, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxModeInfusionRate, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_spinboxModeInfusionRate, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->MainScreen_spinboxModeInfusionRate, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->MainScreen_spinboxModeInfusionRate, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->MainScreen_spinboxModeInfusionRate, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_spinboxModeInfusionRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_spinboxModeInfusionRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_spinboxModeInfusionRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_spinboxModeInfusionRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_spinboxModeInfusionRate, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxModeInfusionRate, &lv_font_Alatsi_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxModeInfusionRate, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_spinboxModeInfusionRate, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_spinboxModeInfusionRate, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_spinboxModeInfusionRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_spinboxModeInfusionRate, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->MainScreen_spinboxModeInfusionRate, lv_color_hex(0x000000), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxModeInfusionRate, &lv_font_Alatsi_Regular_16, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxModeInfusionRate, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxModeInfusionRate, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxModeInfusionRate, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxModeInfusionRate, LV_GRAD_DIR_NONE, LV_PART_CURSOR|LV_STATE_DEFAULT);

	//Write codes MainScreen_contModeValueTotalTime
	ui->MainScreen_contModeValueTotalTime = lv_obj_create(ui->MainScreen_contModeValues);
	lv_obj_set_pos(ui->MainScreen_contModeValueTotalTime, 212, 35);
	lv_obj_set_size(ui->MainScreen_contModeValueTotalTime, 400, 35);
	lv_obj_set_scrollbar_mode(ui->MainScreen_contModeValueTotalTime, LV_SCROLLBAR_MODE_OFF);

	//Write style for MainScreen_contModeValueTotalTime, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_contModeValueTotalTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_contModeValueTotalTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_contModeValueTotalTime, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_contModeValueTotalTime, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_contModeValueTotalTime, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_contModeValueTotalTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_contModeValueTotalTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_contModeValueTotalTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_contModeValueTotalTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_contModeValueTotalTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_41
	ui->MainScreen_label_41 = lv_label_create(ui->MainScreen_contModeValueTotalTime);
	lv_label_set_text(ui->MainScreen_label_41, "Total Time:");
	lv_label_set_long_mode(ui->MainScreen_label_41, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_41, 24, 5);
	lv_obj_set_size(ui->MainScreen_label_41, 147, 25);

	//Write style for MainScreen_label_41, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_41, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_41, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_41, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_41, &lv_font_Alatsi_Regular_19, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_41, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_41, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_41, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_41, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_41, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_41, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_41, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_41, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_41, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_41, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_spinboxModeTotalTimeHour
	ui->MainScreen_spinboxModeTotalTimeHour = lv_spinbox_create(ui->MainScreen_contModeValueTotalTime);
	lv_obj_set_pos(ui->MainScreen_spinboxModeTotalTimeHour, 165, 5);
	lv_obj_set_width(ui->MainScreen_spinboxModeTotalTimeHour, 30);
	lv_obj_set_height(ui->MainScreen_spinboxModeTotalTimeHour, 25);
	lv_spinbox_set_digit_format(ui->MainScreen_spinboxModeTotalTimeHour, 2, 2);
	lv_spinbox_set_range(ui->MainScreen_spinboxModeTotalTimeHour, -99, 99);
	lv_coord_t MainScreen_spinboxModeTotalTimeHour_h = lv_obj_get_height(ui->MainScreen_spinboxModeTotalTimeHour);
	ui->MainScreen_spinboxModeTotalTimeHour_btn = lv_btn_create(ui->MainScreen_contModeValueTotalTime);
	lv_obj_set_size(ui->MainScreen_spinboxModeTotalTimeHour_btn, MainScreen_spinboxModeTotalTimeHour_h, MainScreen_spinboxModeTotalTimeHour_h);
	lv_obj_align_to(ui->MainScreen_spinboxModeTotalTimeHour_btn, ui->MainScreen_spinboxModeTotalTimeHour, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxModeTotalTimeHour_btn, LV_SYMBOL_PLUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxModeTotalTimeHour_btn, lv_MainScreen_spinboxModeTotalTimeHour_increment_event_cb, LV_EVENT_ALL, NULL);
	ui->MainScreen_spinboxModeTotalTimeHour_btn_minus = lv_btn_create(ui->MainScreen_contModeValueTotalTime);
	lv_obj_set_size(ui->MainScreen_spinboxModeTotalTimeHour_btn_minus, MainScreen_spinboxModeTotalTimeHour_h, MainScreen_spinboxModeTotalTimeHour_h);
	lv_obj_align_to(ui->MainScreen_spinboxModeTotalTimeHour_btn_minus, ui->MainScreen_spinboxModeTotalTimeHour, LV_ALIGN_OUT_LEFT_MID, -5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxModeTotalTimeHour_btn_minus, LV_SYMBOL_MINUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxModeTotalTimeHour_btn_minus, lv_MainScreen_spinboxModeTotalTimeHour_decrement_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_set_pos(ui->MainScreen_spinboxModeTotalTimeHour, 165, 5);

	//Write style for MainScreen_spinboxModeTotalTimeHour, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxModeTotalTimeHour, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxModeTotalTimeHour, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxModeTotalTimeHour, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_spinboxModeTotalTimeHour, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->MainScreen_spinboxModeTotalTimeHour, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->MainScreen_spinboxModeTotalTimeHour, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->MainScreen_spinboxModeTotalTimeHour, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_spinboxModeTotalTimeHour, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_spinboxModeTotalTimeHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_spinboxModeTotalTimeHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_spinboxModeTotalTimeHour, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_spinboxModeTotalTimeHour, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxModeTotalTimeHour, &lv_font_Alatsi_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxModeTotalTimeHour, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_spinboxModeTotalTimeHour, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_spinboxModeTotalTimeHour, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_spinboxModeTotalTimeHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_spinboxModeTotalTimeHour, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->MainScreen_spinboxModeTotalTimeHour, lv_color_hex(0x000000), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxModeTotalTimeHour, &lv_font_Alatsi_Regular_16, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxModeTotalTimeHour, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxModeTotalTimeHour, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxModeTotalTimeHour, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxModeTotalTimeHour, LV_GRAD_DIR_NONE, LV_PART_CURSOR|LV_STATE_DEFAULT);

	//Write codes MainScreen_spinboxModeTotalTimeMinute
	ui->MainScreen_spinboxModeTotalTimeMinute = lv_spinbox_create(ui->MainScreen_contModeValueTotalTime);
	lv_obj_set_pos(ui->MainScreen_spinboxModeTotalTimeMinute, 206, 5.5);
	lv_obj_set_width(ui->MainScreen_spinboxModeTotalTimeMinute, 32);
	lv_obj_set_height(ui->MainScreen_spinboxModeTotalTimeMinute, 24);
	lv_spinbox_set_digit_format(ui->MainScreen_spinboxModeTotalTimeMinute, 2, 2);
	lv_spinbox_set_range(ui->MainScreen_spinboxModeTotalTimeMinute, -99, 99);
	lv_coord_t MainScreen_spinboxModeTotalTimeMinute_h = lv_obj_get_height(ui->MainScreen_spinboxModeTotalTimeMinute);
	ui->MainScreen_spinboxModeTotalTimeMinute_btn = lv_btn_create(ui->MainScreen_contModeValueTotalTime);
	lv_obj_set_size(ui->MainScreen_spinboxModeTotalTimeMinute_btn, MainScreen_spinboxModeTotalTimeMinute_h, MainScreen_spinboxModeTotalTimeMinute_h);
	lv_obj_align_to(ui->MainScreen_spinboxModeTotalTimeMinute_btn, ui->MainScreen_spinboxModeTotalTimeMinute, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxModeTotalTimeMinute_btn, LV_SYMBOL_PLUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxModeTotalTimeMinute_btn, lv_MainScreen_spinboxModeTotalTimeMinute_increment_event_cb, LV_EVENT_ALL, NULL);
	ui->MainScreen_spinboxModeTotalTimeMinute_btn_minus = lv_btn_create(ui->MainScreen_contModeValueTotalTime);
	lv_obj_set_size(ui->MainScreen_spinboxModeTotalTimeMinute_btn_minus, MainScreen_spinboxModeTotalTimeMinute_h, MainScreen_spinboxModeTotalTimeMinute_h);
	lv_obj_align_to(ui->MainScreen_spinboxModeTotalTimeMinute_btn_minus, ui->MainScreen_spinboxModeTotalTimeMinute, LV_ALIGN_OUT_LEFT_MID, -5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxModeTotalTimeMinute_btn_minus, LV_SYMBOL_MINUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxModeTotalTimeMinute_btn_minus, lv_MainScreen_spinboxModeTotalTimeMinute_decrement_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_set_pos(ui->MainScreen_spinboxModeTotalTimeMinute, 206, 5.5);

	//Write style for MainScreen_spinboxModeTotalTimeMinute, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxModeTotalTimeMinute, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxModeTotalTimeMinute, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxModeTotalTimeMinute, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_spinboxModeTotalTimeMinute, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->MainScreen_spinboxModeTotalTimeMinute, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->MainScreen_spinboxModeTotalTimeMinute, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->MainScreen_spinboxModeTotalTimeMinute, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_spinboxModeTotalTimeMinute, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_spinboxModeTotalTimeMinute, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_spinboxModeTotalTimeMinute, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_spinboxModeTotalTimeMinute, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_spinboxModeTotalTimeMinute, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxModeTotalTimeMinute, &lv_font_Alatsi_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxModeTotalTimeMinute, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_spinboxModeTotalTimeMinute, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_spinboxModeTotalTimeMinute, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_spinboxModeTotalTimeMinute, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_spinboxModeTotalTimeMinute, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->MainScreen_spinboxModeTotalTimeMinute, lv_color_hex(0x000000), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxModeTotalTimeMinute, &lv_font_Alatsi_Regular_16, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxModeTotalTimeMinute, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxModeTotalTimeMinute, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxModeTotalTimeMinute, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxModeTotalTimeMinute, LV_GRAD_DIR_NONE, LV_PART_CURSOR|LV_STATE_DEFAULT);

	//Write codes MainScreen_spinboxModeTotalTimeSecond
	ui->MainScreen_spinboxModeTotalTimeSecond = lv_spinbox_create(ui->MainScreen_contModeValueTotalTime);
	lv_obj_set_pos(ui->MainScreen_spinboxModeTotalTimeSecond, 248, 5);
	lv_obj_set_width(ui->MainScreen_spinboxModeTotalTimeSecond, 30);
	lv_obj_set_height(ui->MainScreen_spinboxModeTotalTimeSecond, 25);
	lv_spinbox_set_digit_format(ui->MainScreen_spinboxModeTotalTimeSecond, 2, 2);
	lv_spinbox_set_range(ui->MainScreen_spinboxModeTotalTimeSecond, -99, 99);
	lv_coord_t MainScreen_spinboxModeTotalTimeSecond_h = lv_obj_get_height(ui->MainScreen_spinboxModeTotalTimeSecond);
	ui->MainScreen_spinboxModeTotalTimeSecond_btn = lv_btn_create(ui->MainScreen_contModeValueTotalTime);
	lv_obj_set_size(ui->MainScreen_spinboxModeTotalTimeSecond_btn, MainScreen_spinboxModeTotalTimeSecond_h, MainScreen_spinboxModeTotalTimeSecond_h);
	lv_obj_align_to(ui->MainScreen_spinboxModeTotalTimeSecond_btn, ui->MainScreen_spinboxModeTotalTimeSecond, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxModeTotalTimeSecond_btn, LV_SYMBOL_PLUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxModeTotalTimeSecond_btn, lv_MainScreen_spinboxModeTotalTimeSecond_increment_event_cb, LV_EVENT_ALL, NULL);
	ui->MainScreen_spinboxModeTotalTimeSecond_btn_minus = lv_btn_create(ui->MainScreen_contModeValueTotalTime);
	lv_obj_set_size(ui->MainScreen_spinboxModeTotalTimeSecond_btn_minus, MainScreen_spinboxModeTotalTimeSecond_h, MainScreen_spinboxModeTotalTimeSecond_h);
	lv_obj_align_to(ui->MainScreen_spinboxModeTotalTimeSecond_btn_minus, ui->MainScreen_spinboxModeTotalTimeSecond, LV_ALIGN_OUT_LEFT_MID, -5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxModeTotalTimeSecond_btn_minus, LV_SYMBOL_MINUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxModeTotalTimeSecond_btn_minus, lv_MainScreen_spinboxModeTotalTimeSecond_decrement_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_set_pos(ui->MainScreen_spinboxModeTotalTimeSecond, 248, 5);

	//Write style for MainScreen_spinboxModeTotalTimeSecond, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxModeTotalTimeSecond, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxModeTotalTimeSecond, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxModeTotalTimeSecond, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_spinboxModeTotalTimeSecond, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->MainScreen_spinboxModeTotalTimeSecond, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->MainScreen_spinboxModeTotalTimeSecond, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->MainScreen_spinboxModeTotalTimeSecond, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_spinboxModeTotalTimeSecond, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_spinboxModeTotalTimeSecond, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_spinboxModeTotalTimeSecond, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_spinboxModeTotalTimeSecond, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_spinboxModeTotalTimeSecond, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxModeTotalTimeSecond, &lv_font_Alatsi_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxModeTotalTimeSecond, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_spinboxModeTotalTimeSecond, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_spinboxModeTotalTimeSecond, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_spinboxModeTotalTimeSecond, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_spinboxModeTotalTimeSecond, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->MainScreen_spinboxModeTotalTimeSecond, lv_color_hex(0x000000), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxModeTotalTimeSecond, &lv_font_Alatsi_Regular_16, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxModeTotalTimeSecond, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxModeTotalTimeSecond, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxModeTotalTimeSecond, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxModeTotalTimeSecond, LV_GRAD_DIR_NONE, LV_PART_CURSOR|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_43
	ui->MainScreen_label_43 = lv_label_create(ui->MainScreen_contModeValueTotalTime);
	lv_label_set_text(ui->MainScreen_label_43, ":");
	lv_label_set_long_mode(ui->MainScreen_label_43, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_43, 198, 5);
	lv_obj_set_size(ui->MainScreen_label_43, 7, 25);

	//Write style for MainScreen_label_43, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_43, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_43, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_43, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_43, &lv_font_Alatsi_Regular_21, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_43, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_43, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_43, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_43, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_43, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_43, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_43, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_43, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_43, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_43, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_44
	ui->MainScreen_label_44 = lv_label_create(ui->MainScreen_contModeValueTotalTime);
	lv_label_set_text(ui->MainScreen_label_44, ":");
	lv_label_set_long_mode(ui->MainScreen_label_44, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_44, 241, 5);
	lv_obj_set_size(ui->MainScreen_label_44, 7, 25);

	//Write style for MainScreen_label_44, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_44, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_44, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_44, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_44, &lv_font_Alatsi_Regular_21, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_44, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_44, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_44, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_44, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_44, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_44, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_44, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_44, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_44, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_44, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_contModeValueTotalVolume
	ui->MainScreen_contModeValueTotalVolume = lv_obj_create(ui->MainScreen_contModeValues);
	lv_obj_set_pos(ui->MainScreen_contModeValueTotalVolume, 212, 0);
	lv_obj_set_size(ui->MainScreen_contModeValueTotalVolume, 400, 35);
	lv_obj_set_scrollbar_mode(ui->MainScreen_contModeValueTotalVolume, LV_SCROLLBAR_MODE_OFF);

	//Write style for MainScreen_contModeValueTotalVolume, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_contModeValueTotalVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_contModeValueTotalVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_contModeValueTotalVolume, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_contModeValueTotalVolume, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_contModeValueTotalVolume, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_contModeValueTotalVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_contModeValueTotalVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_contModeValueTotalVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_contModeValueTotalVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_contModeValueTotalVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_35
	ui->MainScreen_label_35 = lv_label_create(ui->MainScreen_contModeValueTotalVolume);
	lv_label_set_text(ui->MainScreen_label_35, "Total Volume:");
	lv_label_set_long_mode(ui->MainScreen_label_35, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_35, 24, 5);
	lv_obj_set_size(ui->MainScreen_label_35, 140, 25);

	//Write style for MainScreen_label_35, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_35, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_35, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_35, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_35, &lv_font_Alatsi_Regular_19, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_35, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_35, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_35, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_35, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_35, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_35, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_35, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_35, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_35, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_35, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_labelModeVolumeUnit
	ui->MainScreen_labelModeVolumeUnit = lv_label_create(ui->MainScreen_contModeValueTotalVolume);
	lv_label_set_text(ui->MainScreen_labelModeVolumeUnit, "Unit");
	lv_label_set_long_mode(ui->MainScreen_labelModeVolumeUnit, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_labelModeVolumeUnit, 255, 5);
	lv_obj_set_size(ui->MainScreen_labelModeVolumeUnit, 110, 25);

	//Write style for MainScreen_labelModeVolumeUnit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_labelModeVolumeUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_labelModeVolumeUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_labelModeVolumeUnit, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_labelModeVolumeUnit, &lv_font_Alatsi_Regular_19, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_labelModeVolumeUnit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_labelModeVolumeUnit, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_labelModeVolumeUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_labelModeVolumeUnit, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_labelModeVolumeUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_labelModeVolumeUnit, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_labelModeVolumeUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_labelModeVolumeUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_labelModeVolumeUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_labelModeVolumeUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_spinboxModeTotalVolume
	ui->MainScreen_spinboxModeTotalVolume = lv_spinbox_create(ui->MainScreen_contModeValueTotalVolume);
	lv_obj_set_pos(ui->MainScreen_spinboxModeTotalVolume, 169, 5);
	lv_obj_set_width(ui->MainScreen_spinboxModeTotalVolume, 80);
	lv_obj_set_height(ui->MainScreen_spinboxModeTotalVolume, 25);
	lv_spinbox_set_digit_format(ui->MainScreen_spinboxModeTotalVolume, 5, 4);
	lv_spinbox_set_range(ui->MainScreen_spinboxModeTotalVolume, -99999, 99999);
	lv_coord_t MainScreen_spinboxModeTotalVolume_h = lv_obj_get_height(ui->MainScreen_spinboxModeTotalVolume);
	ui->MainScreen_spinboxModeTotalVolume_btn = lv_btn_create(ui->MainScreen_contModeValueTotalVolume);
	lv_obj_set_size(ui->MainScreen_spinboxModeTotalVolume_btn, MainScreen_spinboxModeTotalVolume_h, MainScreen_spinboxModeTotalVolume_h);
	lv_obj_align_to(ui->MainScreen_spinboxModeTotalVolume_btn, ui->MainScreen_spinboxModeTotalVolume, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxModeTotalVolume_btn, LV_SYMBOL_PLUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxModeTotalVolume_btn, lv_MainScreen_spinboxModeTotalVolume_increment_event_cb, LV_EVENT_ALL, NULL);
	ui->MainScreen_spinboxModeTotalVolume_btn_minus = lv_btn_create(ui->MainScreen_contModeValueTotalVolume);
	lv_obj_set_size(ui->MainScreen_spinboxModeTotalVolume_btn_minus, MainScreen_spinboxModeTotalVolume_h, MainScreen_spinboxModeTotalVolume_h);
	lv_obj_align_to(ui->MainScreen_spinboxModeTotalVolume_btn_minus, ui->MainScreen_spinboxModeTotalVolume, LV_ALIGN_OUT_LEFT_MID, -5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxModeTotalVolume_btn_minus, LV_SYMBOL_MINUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxModeTotalVolume_btn_minus, lv_MainScreen_spinboxModeTotalVolume_decrement_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_set_pos(ui->MainScreen_spinboxModeTotalVolume, 169, 5);

	//Write style for MainScreen_spinboxModeTotalVolume, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxModeTotalVolume, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxModeTotalVolume, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxModeTotalVolume, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_spinboxModeTotalVolume, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->MainScreen_spinboxModeTotalVolume, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->MainScreen_spinboxModeTotalVolume, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->MainScreen_spinboxModeTotalVolume, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_spinboxModeTotalVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_spinboxModeTotalVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_spinboxModeTotalVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_spinboxModeTotalVolume, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_spinboxModeTotalVolume, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxModeTotalVolume, &lv_font_Alatsi_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxModeTotalVolume, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_spinboxModeTotalVolume, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_spinboxModeTotalVolume, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_spinboxModeTotalVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_spinboxModeTotalVolume, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->MainScreen_spinboxModeTotalVolume, lv_color_hex(0x000000), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxModeTotalVolume, &lv_font_Alatsi_Regular_16, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxModeTotalVolume, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxModeTotalVolume, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxModeTotalVolume, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxModeTotalVolume, LV_GRAD_DIR_NONE, LV_PART_CURSOR|LV_STATE_DEFAULT);

	//Write codes MainScreen_labelModeHeader
	ui->MainScreen_labelModeHeader = lv_label_create(ui->MainScreen_contMode);
	lv_label_set_text(ui->MainScreen_labelModeHeader, "Select Operating Mode");
	lv_label_set_long_mode(ui->MainScreen_labelModeHeader, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_labelModeHeader, 0, 0);
	lv_obj_set_size(ui->MainScreen_labelModeHeader, 800, 30);

	//Write style for MainScreen_labelModeHeader, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_labelModeHeader, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_labelModeHeader, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_labelModeHeader, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_labelModeHeader, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_labelModeHeader, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_labelModeHeader, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_labelModeHeader, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_labelModeHeader, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_labelModeHeader, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_labelModeHeader, lv_color_hex(0x324e75), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_labelModeHeader, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_labelModeHeader, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_labelModeHeader, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_labelModeHeader, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_labelModeHeader, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_labelModeHeader, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_btnDummyMode
	ui->MainScreen_btnDummyMode = lv_btn_create(ui->MainScreen_contMode);
	ui->MainScreen_btnDummyMode_label = lv_label_create(ui->MainScreen_btnDummyMode);
	lv_label_set_text(ui->MainScreen_btnDummyMode_label, "");
	lv_label_set_long_mode(ui->MainScreen_btnDummyMode_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->MainScreen_btnDummyMode_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->MainScreen_btnDummyMode, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->MainScreen_btnDummyMode_label, LV_PCT(100));
	lv_obj_set_pos(ui->MainScreen_btnDummyMode, 760, 224);
	lv_obj_set_size(ui->MainScreen_btnDummyMode, 8, 10);

	//Write style for MainScreen_btnDummyMode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_btnDummyMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_btnDummyMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_btnDummyMode, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_btnDummyMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_btnDummyMode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_btnDummyMode, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_btnDummyMode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_btnDummyMode, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_contOcclusion
	ui->MainScreen_contOcclusion = lv_obj_create(ui->MainScreen);
	lv_obj_set_pos(ui->MainScreen_contOcclusion, 800, 80);
	lv_obj_set_size(ui->MainScreen_contOcclusion, 800, 300);
	lv_obj_set_scrollbar_mode(ui->MainScreen_contOcclusion, LV_SCROLLBAR_MODE_OFF);

	//Write style for MainScreen_contOcclusion, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_contOcclusion, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->MainScreen_contOcclusion, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->MainScreen_contOcclusion, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->MainScreen_contOcclusion, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_contOcclusion, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_contOcclusion, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_contOcclusion, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_contOcclusion, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_contOcclusion, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_contOcclusion, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_contOcclusion, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_contOcclusion, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_contOcclusion, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_btnGoMenuOcclusion
	ui->MainScreen_btnGoMenuOcclusion = lv_btn_create(ui->MainScreen_contOcclusion);
	ui->MainScreen_btnGoMenuOcclusion_label = lv_label_create(ui->MainScreen_btnGoMenuOcclusion);
	lv_label_set_text(ui->MainScreen_btnGoMenuOcclusion_label, "");
	lv_label_set_long_mode(ui->MainScreen_btnGoMenuOcclusion_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->MainScreen_btnGoMenuOcclusion_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->MainScreen_btnGoMenuOcclusion, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->MainScreen_btnGoMenuOcclusion_label, LV_PCT(100));
	lv_obj_set_pos(ui->MainScreen_btnGoMenuOcclusion, 731, 247);
	lv_obj_set_size(ui->MainScreen_btnGoMenuOcclusion, 58, 44);

	//Write style for MainScreen_btnGoMenuOcclusion, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_btnGoMenuOcclusion, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_btnGoMenuOcclusion, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_btnGoMenuOcclusion, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_btnGoMenuOcclusion, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_btnGoMenuOcclusion, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_btnGoMenuOcclusion, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_btnGoMenuOcclusion, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_btnGoMenuOcclusion, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_45
	ui->MainScreen_label_45 = lv_label_create(ui->MainScreen_contOcclusion);
	lv_label_set_text(ui->MainScreen_label_45, "Occlusion Level");
	lv_label_set_long_mode(ui->MainScreen_label_45, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_45, 0, 0);
	lv_obj_set_size(ui->MainScreen_label_45, 800, 30);

	//Write style for MainScreen_label_45, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_45, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_45, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_45, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_45, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_45, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_45, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_45, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_45, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_45, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_label_45, lv_color_hex(0x324e75), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_label_45, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_45, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_45, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_45, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_45, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_45, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_sliderOcclusionOcc
	ui->MainScreen_sliderOcclusionOcc = lv_slider_create(ui->MainScreen_contOcclusion);
	lv_slider_set_range(ui->MainScreen_sliderOcclusionOcc, 0, 11);
	lv_slider_set_mode(ui->MainScreen_sliderOcclusionOcc, LV_SLIDER_MODE_NORMAL);
	lv_slider_set_value(ui->MainScreen_sliderOcclusionOcc, 4, LV_ANIM_OFF);
	lv_obj_set_pos(ui->MainScreen_sliderOcclusionOcc, 384, 100);
	lv_obj_set_size(ui->MainScreen_sliderOcclusionOcc, 26, 132);

	//Write style for MainScreen_sliderOcclusionOcc, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_sliderOcclusionOcc, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_sliderOcclusionOcc, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_sliderOcclusionOcc, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_sliderOcclusionOcc, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_outline_width(ui->MainScreen_sliderOcclusionOcc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->MainScreen_sliderOcclusionOcc, &_ledbar_empty_26x132, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->MainScreen_sliderOcclusionOcc, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_sliderOcclusionOcc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_sliderOcclusionOcc, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
	lv_obj_set_style_shadow_width(ui->MainScreen_sliderOcclusionOcc, 0, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write style for MainScreen_sliderOcclusionOcc, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_sliderOcclusionOcc, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_sliderOcclusionOcc, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_sliderOcclusionOcc, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->MainScreen_sliderOcclusionOcc, &_ledbar_full_26x132, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->MainScreen_sliderOcclusionOcc, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_sliderOcclusionOcc, 50, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style for MainScreen_sliderOcclusionOcc, Part: LV_PART_INDICATOR, State: LV_STATE_FOCUSED.
	lv_obj_set_style_bg_opa(ui->MainScreen_sliderOcclusionOcc, 255, LV_PART_INDICATOR|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_color(ui->MainScreen_sliderOcclusionOcc, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_sliderOcclusionOcc, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_img_src(ui->MainScreen_sliderOcclusionOcc, &_ledbar_full_26x132, LV_PART_INDICATOR|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_img_opa(ui->MainScreen_sliderOcclusionOcc, 255, LV_PART_INDICATOR|LV_STATE_FOCUSED);
	lv_obj_set_style_radius(ui->MainScreen_sliderOcclusionOcc, 50, LV_PART_INDICATOR|LV_STATE_FOCUSED);

	//Write style for MainScreen_sliderOcclusionOcc, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_sliderOcclusionOcc, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_sliderOcclusionOcc, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write style for MainScreen_sliderOcclusionOcc, Part: LV_PART_KNOB, State: LV_STATE_FOCUSED.
	lv_obj_set_style_bg_opa(ui->MainScreen_sliderOcclusionOcc, 0, LV_PART_KNOB|LV_STATE_FOCUSED);
	lv_obj_set_style_radius(ui->MainScreen_sliderOcclusionOcc, 50, LV_PART_KNOB|LV_STATE_FOCUSED);

	//Write codes MainScreen_contKVO
	ui->MainScreen_contKVO = lv_obj_create(ui->MainScreen);
	lv_obj_set_pos(ui->MainScreen_contKVO, 800, 80);
	lv_obj_set_size(ui->MainScreen_contKVO, 800, 300);
	lv_obj_set_scrollbar_mode(ui->MainScreen_contKVO, LV_SCROLLBAR_MODE_OFF);

	//Write style for MainScreen_contKVO, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_contKVO, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->MainScreen_contKVO, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->MainScreen_contKVO, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->MainScreen_contKVO, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_contKVO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_contKVO, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_contKVO, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_contKVO, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_contKVO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_contKVO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_contKVO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_contKVO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_contKVO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_46
	ui->MainScreen_label_46 = lv_label_create(ui->MainScreen_contKVO);
	lv_label_set_text(ui->MainScreen_label_46, "KVO Mode");
	lv_label_set_long_mode(ui->MainScreen_label_46, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_46, 0, 0);
	lv_obj_set_size(ui->MainScreen_label_46, 800, 30);

	//Write style for MainScreen_label_46, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_46, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_46, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_46, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_46, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_46, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_46, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_46, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_46, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_46, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_label_46, lv_color_hex(0x324e75), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_label_46, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_46, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_46, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_46, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_46, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_46, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_contKVOValues
	ui->MainScreen_contKVOValues = lv_obj_create(ui->MainScreen_contKVO);
	lv_obj_set_pos(ui->MainScreen_contKVOValues, 89, 32);
	lv_obj_set_size(ui->MainScreen_contKVOValues, 579, 266);
	lv_obj_set_scrollbar_mode(ui->MainScreen_contKVOValues, LV_SCROLLBAR_MODE_OFF);

	//Write style for MainScreen_contKVOValues, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_contKVOValues, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_contKVOValues, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_contKVOValues, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_contKVOValues, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_contKVOValues, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_contKVOValues, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_contKVOValues, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_contKVOValues, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_contKVOValues, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_contKVOValues, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_47
	ui->MainScreen_label_47 = lv_label_create(ui->MainScreen_contKVOValues);
	lv_label_set_text(ui->MainScreen_label_47, "KVO Mode:");
	lv_label_set_long_mode(ui->MainScreen_label_47, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_47, 167, 51);
	lv_obj_set_size(ui->MainScreen_label_47, 155, 21);

	//Write style for MainScreen_label_47, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_47, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_47, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_47, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_47, &lv_font_Alatsi_Regular_19, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_47, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_47, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_47, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_47, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_47, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_47, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_47, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_47, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_47, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_47, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_48
	ui->MainScreen_label_48 = lv_label_create(ui->MainScreen_contKVOValues);
	lv_label_set_text(ui->MainScreen_label_48, "KVO Rate:");
	lv_label_set_long_mode(ui->MainScreen_label_48, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_48, 172, 149);
	lv_obj_set_size(ui->MainScreen_label_48, 155, 21);

	//Write style for MainScreen_label_48, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_48, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_48, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_48, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_48, &lv_font_Alatsi_Regular_19, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_48, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_48, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_48, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_48, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_48, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_48, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_48, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_48, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_48, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_48, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_swKVOMode
	ui->MainScreen_swKVOMode = lv_switch_create(ui->MainScreen_contKVOValues);
	lv_obj_set_pos(ui->MainScreen_swKVOMode, 317, 48);
	lv_obj_set_size(ui->MainScreen_swKVOMode, 110, 27);

	//Write style for MainScreen_swKVOMode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_swKVOMode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_swKVOMode, lv_color_hex(0xe6e2e6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_swKVOMode, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_swKVOMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_swKVOMode, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_swKVOMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_swKVOMode, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->MainScreen_swKVOMode, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->MainScreen_swKVOMode, lv_color_hex(0x1bc52e), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_swKVOMode, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->MainScreen_swKVOMode, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for MainScreen_swKVOMode, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_swKVOMode, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_swKVOMode, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_swKVOMode, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_swKVOMode, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_swKVOMode, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes MainScreen_labelswKVOModeEnable
	ui->MainScreen_labelswKVOModeEnable = lv_label_create(ui->MainScreen_contKVOValues);
	lv_label_set_text(ui->MainScreen_labelswKVOModeEnable, "Enable");
	lv_label_set_long_mode(ui->MainScreen_labelswKVOModeEnable, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_labelswKVOModeEnable, 317, 55);
	lv_obj_set_size(ui->MainScreen_labelswKVOModeEnable, 110, 27);

	//Write style for MainScreen_labelswKVOModeEnable, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_labelswKVOModeEnable, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_labelswKVOModeEnable, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_labelswKVOModeEnable, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_labelswKVOModeEnable, &lv_font_Alatsi_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_labelswKVOModeEnable, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_labelswKVOModeEnable, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_labelswKVOModeEnable, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_labelswKVOModeEnable, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_labelswKVOModeEnable, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_labelswKVOModeEnable, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_labelswKVOModeEnable, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_labelswKVOModeEnable, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_labelswKVOModeEnable, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_labelswKVOModeEnable, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_labelswKVOModeDisable
	ui->MainScreen_labelswKVOModeDisable = lv_label_create(ui->MainScreen_contKVOValues);
	lv_label_set_text(ui->MainScreen_labelswKVOModeDisable, "Disable");
	lv_label_set_long_mode(ui->MainScreen_labelswKVOModeDisable, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_labelswKVOModeDisable, 317, 55);
	lv_obj_set_size(ui->MainScreen_labelswKVOModeDisable, 110, 18);

	//Write style for MainScreen_labelswKVOModeDisable, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_labelswKVOModeDisable, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_labelswKVOModeDisable, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_labelswKVOModeDisable, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_labelswKVOModeDisable, &lv_font_Alatsi_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_labelswKVOModeDisable, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_labelswKVOModeDisable, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_labelswKVOModeDisable, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_labelswKVOModeDisable, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_labelswKVOModeDisable, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_labelswKVOModeDisable, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_labelswKVOModeDisable, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_labelswKVOModeDisable, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_labelswKVOModeDisable, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_labelswKVOModeDisable, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_labelKVORate
	ui->MainScreen_labelKVORate = lv_label_create(ui->MainScreen_contKVOValues);
	lv_label_set_text(ui->MainScreen_labelKVORate, "Unit/min");
	lv_label_set_long_mode(ui->MainScreen_labelKVORate, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_labelKVORate, 416, 150.5);
	lv_obj_set_size(ui->MainScreen_labelKVORate, 110, 18);

	//Write style for MainScreen_labelKVORate, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_labelKVORate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_labelKVORate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_labelKVORate, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_labelKVORate, &lv_font_Alatsi_Regular_19, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_labelKVORate, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_labelKVORate, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_labelKVORate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_labelKVORate, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_labelKVORate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_labelKVORate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_labelKVORate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_labelKVORate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_labelKVORate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_labelKVORate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_spinboxKVORate
	ui->MainScreen_spinboxKVORate = lv_spinbox_create(ui->MainScreen_contKVOValues);
	lv_obj_set_pos(ui->MainScreen_spinboxKVORate, 328, 147);
	lv_obj_set_width(ui->MainScreen_spinboxKVORate, 90);
	lv_obj_set_height(ui->MainScreen_spinboxKVORate, 25);
	lv_spinbox_set_digit_format(ui->MainScreen_spinboxKVORate, 2, 1);
	lv_spinbox_set_range(ui->MainScreen_spinboxKVORate, -99, 99);
	lv_coord_t MainScreen_spinboxKVORate_h = lv_obj_get_height(ui->MainScreen_spinboxKVORate);
	ui->MainScreen_spinboxKVORate_btn = lv_btn_create(ui->MainScreen_contKVOValues);
	lv_obj_set_size(ui->MainScreen_spinboxKVORate_btn, MainScreen_spinboxKVORate_h, MainScreen_spinboxKVORate_h);
	lv_obj_align_to(ui->MainScreen_spinboxKVORate_btn, ui->MainScreen_spinboxKVORate, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxKVORate_btn, LV_SYMBOL_PLUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxKVORate_btn, lv_MainScreen_spinboxKVORate_increment_event_cb, LV_EVENT_ALL, NULL);
	ui->MainScreen_spinboxKVORate_btn_minus = lv_btn_create(ui->MainScreen_contKVOValues);
	lv_obj_set_size(ui->MainScreen_spinboxKVORate_btn_minus, MainScreen_spinboxKVORate_h, MainScreen_spinboxKVORate_h);
	lv_obj_align_to(ui->MainScreen_spinboxKVORate_btn_minus, ui->MainScreen_spinboxKVORate, LV_ALIGN_OUT_LEFT_MID, -5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxKVORate_btn_minus, LV_SYMBOL_MINUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxKVORate_btn_minus, lv_MainScreen_spinboxKVORate_decrement_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_set_pos(ui->MainScreen_spinboxKVORate, 328, 147);

	//Write style for MainScreen_spinboxKVORate, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxKVORate, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxKVORate, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxKVORate, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_spinboxKVORate, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->MainScreen_spinboxKVORate, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->MainScreen_spinboxKVORate, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->MainScreen_spinboxKVORate, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_spinboxKVORate, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_spinboxKVORate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_spinboxKVORate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_spinboxKVORate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_spinboxKVORate, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxKVORate, &lv_font_Alatsi_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxKVORate, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_spinboxKVORate, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_spinboxKVORate, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_spinboxKVORate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_spinboxKVORate, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->MainScreen_spinboxKVORate, lv_color_hex(0x000000), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxKVORate, &lv_font_Alatsi_Regular_16, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxKVORate, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxKVORate, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxKVORate, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxKVORate, LV_GRAD_DIR_NONE, LV_PART_CURSOR|LV_STATE_DEFAULT);

	//Write codes MainScreen_btnGoMenuKVO
	ui->MainScreen_btnGoMenuKVO = lv_btn_create(ui->MainScreen_contKVO);
	ui->MainScreen_btnGoMenuKVO_label = lv_label_create(ui->MainScreen_btnGoMenuKVO);
	lv_label_set_text(ui->MainScreen_btnGoMenuKVO_label, "");
	lv_label_set_long_mode(ui->MainScreen_btnGoMenuKVO_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->MainScreen_btnGoMenuKVO_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->MainScreen_btnGoMenuKVO, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->MainScreen_btnGoMenuKVO_label, LV_PCT(100));
	lv_obj_set_pos(ui->MainScreen_btnGoMenuKVO, 731, 247);
	lv_obj_set_size(ui->MainScreen_btnGoMenuKVO, 58, 44);

	//Write style for MainScreen_btnGoMenuKVO, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_btnGoMenuKVO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_btnGoMenuKVO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_btnGoMenuKVO, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_btnGoMenuKVO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_btnGoMenuKVO, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_btnGoMenuKVO, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_btnGoMenuKVO, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_btnGoMenuKVO, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_btnDummyKVO
	ui->MainScreen_btnDummyKVO = lv_btn_create(ui->MainScreen_contKVO);
	ui->MainScreen_btnDummyKVO_label = lv_label_create(ui->MainScreen_btnDummyKVO);
	lv_label_set_text(ui->MainScreen_btnDummyKVO_label, "");
	lv_label_set_long_mode(ui->MainScreen_btnDummyKVO_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->MainScreen_btnDummyKVO_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->MainScreen_btnDummyKVO, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->MainScreen_btnDummyKVO_label, LV_PCT(100));
	lv_obj_set_pos(ui->MainScreen_btnDummyKVO, 776, 129);
	lv_obj_set_size(ui->MainScreen_btnDummyKVO, 8, 10);

	//Write style for MainScreen_btnDummyKVO, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_btnDummyKVO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_btnDummyKVO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_btnDummyKVO, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_btnDummyKVO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_btnDummyKVO, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_btnDummyKVO, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_btnDummyKVO, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_btnDummyKVO, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_contIntermittent
	ui->MainScreen_contIntermittent = lv_obj_create(ui->MainScreen);
	lv_obj_set_pos(ui->MainScreen_contIntermittent, 800, 80);
	lv_obj_set_size(ui->MainScreen_contIntermittent, 800, 300);
	lv_obj_set_scrollbar_mode(ui->MainScreen_contIntermittent, LV_SCROLLBAR_MODE_OFF);

	//Write style for MainScreen_contIntermittent, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_contIntermittent, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->MainScreen_contIntermittent, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->MainScreen_contIntermittent, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->MainScreen_contIntermittent, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_contIntermittent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_contIntermittent, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_contIntermittent, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_contIntermittent, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_contIntermittent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_contIntermittent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_contIntermittent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_contIntermittent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_contIntermittent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_54
	ui->MainScreen_label_54 = lv_label_create(ui->MainScreen_contIntermittent);
	lv_label_set_text(ui->MainScreen_label_54, "Intermittent Infusion\n");
	lv_label_set_long_mode(ui->MainScreen_label_54, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_54, 0, 0);
	lv_obj_set_size(ui->MainScreen_label_54, 800, 30);

	//Write style for MainScreen_label_54, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_54, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_54, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_54, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_54, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_54, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_54, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_54, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_54, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_54, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_label_54, lv_color_hex(0x324e75), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_label_54, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_54, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_54, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_54, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_54, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_54, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_contIntermittentValues
	ui->MainScreen_contIntermittentValues = lv_obj_create(ui->MainScreen_contIntermittent);
	lv_obj_set_pos(ui->MainScreen_contIntermittentValues, 89, 32);
	lv_obj_set_size(ui->MainScreen_contIntermittentValues, 579, 266);
	lv_obj_set_scrollbar_mode(ui->MainScreen_contIntermittentValues, LV_SCROLLBAR_MODE_OFF);

	//Write style for MainScreen_contIntermittentValues, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_contIntermittentValues, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_contIntermittentValues, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_contIntermittentValues, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_contIntermittentValues, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_contIntermittentValues, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_contIntermittentValues, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_contIntermittentValues, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_contIntermittentValues, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_contIntermittentValues, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_contIntermittentValues, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_53
	ui->MainScreen_label_53 = lv_label_create(ui->MainScreen_contIntermittentValues);
	lv_label_set_text(ui->MainScreen_label_53, "Infusion Rate:\n");
	lv_label_set_long_mode(ui->MainScreen_label_53, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_53, 142, 34);
	lv_obj_set_size(ui->MainScreen_label_53, 155, 21);

	//Write style for MainScreen_label_53, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_53, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_53, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_53, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_53, &lv_font_Alatsi_Regular_19, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_53, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_53, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_53, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_53, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_53, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_53, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_53, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_53, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_53, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_53, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_52
	ui->MainScreen_label_52 = lv_label_create(ui->MainScreen_contIntermittentValues);
	lv_label_set_text(ui->MainScreen_label_52, "Duration:\n");
	lv_label_set_long_mode(ui->MainScreen_label_52, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_52, 142, 94);
	lv_obj_set_size(ui->MainScreen_label_52, 155, 21);

	//Write style for MainScreen_label_52, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_52, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_52, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_52, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_52, &lv_font_Alatsi_Regular_19, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_52, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_52, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_52, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_52, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_52, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_52, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_52, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_52, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_52, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_52, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_55
	ui->MainScreen_label_55 = lv_label_create(ui->MainScreen_contIntermittentValues);
	lv_label_set_text(ui->MainScreen_label_55, "Background Rate:");
	lv_label_set_long_mode(ui->MainScreen_label_55, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_55, 116, 154);
	lv_obj_set_size(ui->MainScreen_label_55, 207, 20);

	//Write style for MainScreen_label_55, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_55, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_55, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_55, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_55, &lv_font_Alatsi_Regular_19, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_55, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_55, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_55, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_55, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_55, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_55, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_55, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_55, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_55, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_55, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_56
	ui->MainScreen_label_56 = lv_label_create(ui->MainScreen_contIntermittentValues);
	lv_label_set_text(ui->MainScreen_label_56, "Sleep:");
	lv_label_set_long_mode(ui->MainScreen_label_56, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_56, 142, 213);
	lv_obj_set_size(ui->MainScreen_label_56, 155, 21);

	//Write style for MainScreen_label_56, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_56, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_56, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_56, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_56, &lv_font_Alatsi_Regular_19, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_56, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_56, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_56, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_56, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_56, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_56, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_56, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_56, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_56, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_56, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_labelIntermittentInfusionRate
	ui->MainScreen_labelIntermittentInfusionRate = lv_label_create(ui->MainScreen_contIntermittentValues);
	lv_label_set_text(ui->MainScreen_labelIntermittentInfusionRate, "Unit/min");
	lv_label_set_long_mode(ui->MainScreen_labelIntermittentInfusionRate, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_labelIntermittentInfusionRate, 417, 35);
	lv_obj_set_size(ui->MainScreen_labelIntermittentInfusionRate, 115, 21);

	//Write style for MainScreen_labelIntermittentInfusionRate, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_labelIntermittentInfusionRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_labelIntermittentInfusionRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_labelIntermittentInfusionRate, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_labelIntermittentInfusionRate, &lv_font_Alatsi_Regular_19, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_labelIntermittentInfusionRate, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_labelIntermittentInfusionRate, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_labelIntermittentInfusionRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_labelIntermittentInfusionRate, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_labelIntermittentInfusionRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_labelIntermittentInfusionRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_labelIntermittentInfusionRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_labelIntermittentInfusionRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_labelIntermittentInfusionRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_labelIntermittentInfusionRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_labelIntermittentBackGroundRate
	ui->MainScreen_labelIntermittentBackGroundRate = lv_label_create(ui->MainScreen_contIntermittentValues);
	lv_label_set_text(ui->MainScreen_labelIntermittentBackGroundRate, "Unit/min");
	lv_label_set_long_mode(ui->MainScreen_labelIntermittentBackGroundRate, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_labelIntermittentBackGroundRate, 365, 156);
	lv_obj_set_size(ui->MainScreen_labelIntermittentBackGroundRate, 115, 21);

	//Write style for MainScreen_labelIntermittentBackGroundRate, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_labelIntermittentBackGroundRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_labelIntermittentBackGroundRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_labelIntermittentBackGroundRate, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_labelIntermittentBackGroundRate, &lv_font_Alatsi_Regular_19, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_labelIntermittentBackGroundRate, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_labelIntermittentBackGroundRate, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_labelIntermittentBackGroundRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_labelIntermittentBackGroundRate, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_labelIntermittentBackGroundRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_labelIntermittentBackGroundRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_labelIntermittentBackGroundRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_labelIntermittentBackGroundRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_labelIntermittentBackGroundRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_labelIntermittentBackGroundRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_spinboxIntermittentInfusionRate
	ui->MainScreen_spinboxIntermittentInfusionRate = lv_spinbox_create(ui->MainScreen_contIntermittentValues);
	lv_obj_set_pos(ui->MainScreen_spinboxIntermittentInfusionRate, 315, 31);
	lv_obj_set_width(ui->MainScreen_spinboxIntermittentInfusionRate, 90);
	lv_obj_set_height(ui->MainScreen_spinboxIntermittentInfusionRate, 25);
	lv_spinbox_set_digit_format(ui->MainScreen_spinboxIntermittentInfusionRate, 5, 4);
	lv_spinbox_set_range(ui->MainScreen_spinboxIntermittentInfusionRate, -99999, 99999);
	lv_coord_t MainScreen_spinboxIntermittentInfusionRate_h = lv_obj_get_height(ui->MainScreen_spinboxIntermittentInfusionRate);
	ui->MainScreen_spinboxIntermittentInfusionRate_btn = lv_btn_create(ui->MainScreen_contIntermittentValues);
	lv_obj_set_size(ui->MainScreen_spinboxIntermittentInfusionRate_btn, MainScreen_spinboxIntermittentInfusionRate_h, MainScreen_spinboxIntermittentInfusionRate_h);
	lv_obj_align_to(ui->MainScreen_spinboxIntermittentInfusionRate_btn, ui->MainScreen_spinboxIntermittentInfusionRate, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxIntermittentInfusionRate_btn, LV_SYMBOL_PLUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxIntermittentInfusionRate_btn, lv_MainScreen_spinboxIntermittentInfusionRate_increment_event_cb, LV_EVENT_ALL, NULL);
	ui->MainScreen_spinboxIntermittentInfusionRate_btn_minus = lv_btn_create(ui->MainScreen_contIntermittentValues);
	lv_obj_set_size(ui->MainScreen_spinboxIntermittentInfusionRate_btn_minus, MainScreen_spinboxIntermittentInfusionRate_h, MainScreen_spinboxIntermittentInfusionRate_h);
	lv_obj_align_to(ui->MainScreen_spinboxIntermittentInfusionRate_btn_minus, ui->MainScreen_spinboxIntermittentInfusionRate, LV_ALIGN_OUT_LEFT_MID, -5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxIntermittentInfusionRate_btn_minus, LV_SYMBOL_MINUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxIntermittentInfusionRate_btn_minus, lv_MainScreen_spinboxIntermittentInfusionRate_decrement_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_set_pos(ui->MainScreen_spinboxIntermittentInfusionRate, 315, 31);

	//Write style for MainScreen_spinboxIntermittentInfusionRate, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxIntermittentInfusionRate, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxIntermittentInfusionRate, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxIntermittentInfusionRate, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_spinboxIntermittentInfusionRate, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->MainScreen_spinboxIntermittentInfusionRate, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->MainScreen_spinboxIntermittentInfusionRate, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->MainScreen_spinboxIntermittentInfusionRate, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_spinboxIntermittentInfusionRate, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_spinboxIntermittentInfusionRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_spinboxIntermittentInfusionRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_spinboxIntermittentInfusionRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_spinboxIntermittentInfusionRate, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxIntermittentInfusionRate, &lv_font_Alatsi_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxIntermittentInfusionRate, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_spinboxIntermittentInfusionRate, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_spinboxIntermittentInfusionRate, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_spinboxIntermittentInfusionRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_spinboxIntermittentInfusionRate, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->MainScreen_spinboxIntermittentInfusionRate, lv_color_hex(0x000000), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxIntermittentInfusionRate, &lv_font_Alatsi_Regular_16, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxIntermittentInfusionRate, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxIntermittentInfusionRate, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxIntermittentInfusionRate, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxIntermittentInfusionRate, LV_GRAD_DIR_NONE, LV_PART_CURSOR|LV_STATE_DEFAULT);

	//Write codes MainScreen_contIntermittentDuration
	ui->MainScreen_contIntermittentDuration = lv_obj_create(ui->MainScreen_contIntermittentValues);
	lv_obj_set_pos(ui->MainScreen_contIntermittentDuration, 281, 87);
	lv_obj_set_size(ui->MainScreen_contIntermittentDuration, 150, 36);
	lv_obj_set_scrollbar_mode(ui->MainScreen_contIntermittentDuration, LV_SCROLLBAR_MODE_OFF);

	//Write style for MainScreen_contIntermittentDuration, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_contIntermittentDuration, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_contIntermittentDuration, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_contIntermittentDuration, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_contIntermittentDuration, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_contIntermittentDuration, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_contIntermittentDuration, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_contIntermittentDuration, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_contIntermittentDuration, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_contIntermittentDuration, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_contIntermittentDuration, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_58
	ui->MainScreen_label_58 = lv_label_create(ui->MainScreen_contIntermittentDuration);
	lv_label_set_text(ui->MainScreen_label_58, ":");
	lv_label_set_long_mode(ui->MainScreen_label_58, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_58, 50, 4);
	lv_obj_set_size(ui->MainScreen_label_58, 7, 25);

	//Write style for MainScreen_label_58, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_58, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_58, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_58, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_58, &lv_font_Alatsi_Regular_21, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_58, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_58, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_58, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_58, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_58, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_58, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_58, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_58, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_58, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_58, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_57
	ui->MainScreen_label_57 = lv_label_create(ui->MainScreen_contIntermittentDuration);
	lv_label_set_text(ui->MainScreen_label_57, ":");
	lv_label_set_long_mode(ui->MainScreen_label_57, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_57, 100, 6);
	lv_obj_set_size(ui->MainScreen_label_57, 7, 25);

	//Write style for MainScreen_label_57, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_57, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_57, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_57, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_57, &lv_font_Alatsi_Regular_21, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_57, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_57, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_57, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_57, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_57, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_57, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_57, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_57, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_57, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_57, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_spinboxIntermittentDurationHour
	ui->MainScreen_spinboxIntermittentDurationHour = lv_spinbox_create(ui->MainScreen_contIntermittentDuration);
	lv_obj_set_pos(ui->MainScreen_spinboxIntermittentDurationHour, 10, 5);
	lv_obj_set_width(ui->MainScreen_spinboxIntermittentDurationHour, 30);
	lv_obj_set_height(ui->MainScreen_spinboxIntermittentDurationHour, 25);
	lv_spinbox_set_digit_format(ui->MainScreen_spinboxIntermittentDurationHour, 2, 2);
	lv_spinbox_set_range(ui->MainScreen_spinboxIntermittentDurationHour, -99, 99);
	lv_coord_t MainScreen_spinboxIntermittentDurationHour_h = lv_obj_get_height(ui->MainScreen_spinboxIntermittentDurationHour);
	ui->MainScreen_spinboxIntermittentDurationHour_btn = lv_btn_create(ui->MainScreen_contIntermittentDuration);
	lv_obj_set_size(ui->MainScreen_spinboxIntermittentDurationHour_btn, MainScreen_spinboxIntermittentDurationHour_h, MainScreen_spinboxIntermittentDurationHour_h);
	lv_obj_align_to(ui->MainScreen_spinboxIntermittentDurationHour_btn, ui->MainScreen_spinboxIntermittentDurationHour, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxIntermittentDurationHour_btn, LV_SYMBOL_PLUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxIntermittentDurationHour_btn, lv_MainScreen_spinboxIntermittentDurationHour_increment_event_cb, LV_EVENT_ALL, NULL);
	ui->MainScreen_spinboxIntermittentDurationHour_btn_minus = lv_btn_create(ui->MainScreen_contIntermittentDuration);
	lv_obj_set_size(ui->MainScreen_spinboxIntermittentDurationHour_btn_minus, MainScreen_spinboxIntermittentDurationHour_h, MainScreen_spinboxIntermittentDurationHour_h);
	lv_obj_align_to(ui->MainScreen_spinboxIntermittentDurationHour_btn_minus, ui->MainScreen_spinboxIntermittentDurationHour, LV_ALIGN_OUT_LEFT_MID, -5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxIntermittentDurationHour_btn_minus, LV_SYMBOL_MINUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxIntermittentDurationHour_btn_minus, lv_MainScreen_spinboxIntermittentDurationHour_decrement_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_set_pos(ui->MainScreen_spinboxIntermittentDurationHour, 10, 5);

	//Write style for MainScreen_spinboxIntermittentDurationHour, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxIntermittentDurationHour, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxIntermittentDurationHour, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxIntermittentDurationHour, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_spinboxIntermittentDurationHour, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->MainScreen_spinboxIntermittentDurationHour, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->MainScreen_spinboxIntermittentDurationHour, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->MainScreen_spinboxIntermittentDurationHour, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_spinboxIntermittentDurationHour, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_spinboxIntermittentDurationHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_spinboxIntermittentDurationHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_spinboxIntermittentDurationHour, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_spinboxIntermittentDurationHour, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxIntermittentDurationHour, &lv_font_Alatsi_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxIntermittentDurationHour, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_spinboxIntermittentDurationHour, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_spinboxIntermittentDurationHour, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_spinboxIntermittentDurationHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_spinboxIntermittentDurationHour, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->MainScreen_spinboxIntermittentDurationHour, lv_color_hex(0x000000), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxIntermittentDurationHour, &lv_font_Alatsi_Regular_16, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxIntermittentDurationHour, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxIntermittentDurationHour, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxIntermittentDurationHour, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxIntermittentDurationHour, LV_GRAD_DIR_NONE, LV_PART_CURSOR|LV_STATE_DEFAULT);

	//Write codes MainScreen_spinboxIntermittentDurationMinute
	ui->MainScreen_spinboxIntermittentDurationMinute = lv_spinbox_create(ui->MainScreen_contIntermittentDuration);
	lv_obj_set_pos(ui->MainScreen_spinboxIntermittentDurationMinute, 60, 5);
	lv_obj_set_width(ui->MainScreen_spinboxIntermittentDurationMinute, 30);
	lv_obj_set_height(ui->MainScreen_spinboxIntermittentDurationMinute, 25);
	lv_spinbox_set_digit_format(ui->MainScreen_spinboxIntermittentDurationMinute, 2, 2);
	lv_spinbox_set_range(ui->MainScreen_spinboxIntermittentDurationMinute, -99, 99);
	lv_coord_t MainScreen_spinboxIntermittentDurationMinute_h = lv_obj_get_height(ui->MainScreen_spinboxIntermittentDurationMinute);
	ui->MainScreen_spinboxIntermittentDurationMinute_btn = lv_btn_create(ui->MainScreen_contIntermittentDuration);
	lv_obj_set_size(ui->MainScreen_spinboxIntermittentDurationMinute_btn, MainScreen_spinboxIntermittentDurationMinute_h, MainScreen_spinboxIntermittentDurationMinute_h);
	lv_obj_align_to(ui->MainScreen_spinboxIntermittentDurationMinute_btn, ui->MainScreen_spinboxIntermittentDurationMinute, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxIntermittentDurationMinute_btn, LV_SYMBOL_PLUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxIntermittentDurationMinute_btn, lv_MainScreen_spinboxIntermittentDurationMinute_increment_event_cb, LV_EVENT_ALL, NULL);
	ui->MainScreen_spinboxIntermittentDurationMinute_btn_minus = lv_btn_create(ui->MainScreen_contIntermittentDuration);
	lv_obj_set_size(ui->MainScreen_spinboxIntermittentDurationMinute_btn_minus, MainScreen_spinboxIntermittentDurationMinute_h, MainScreen_spinboxIntermittentDurationMinute_h);
	lv_obj_align_to(ui->MainScreen_spinboxIntermittentDurationMinute_btn_minus, ui->MainScreen_spinboxIntermittentDurationMinute, LV_ALIGN_OUT_LEFT_MID, -5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxIntermittentDurationMinute_btn_minus, LV_SYMBOL_MINUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxIntermittentDurationMinute_btn_minus, lv_MainScreen_spinboxIntermittentDurationMinute_decrement_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_set_pos(ui->MainScreen_spinboxIntermittentDurationMinute, 60, 5);

	//Write style for MainScreen_spinboxIntermittentDurationMinute, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxIntermittentDurationMinute, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxIntermittentDurationMinute, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxIntermittentDurationMinute, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_spinboxIntermittentDurationMinute, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->MainScreen_spinboxIntermittentDurationMinute, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->MainScreen_spinboxIntermittentDurationMinute, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->MainScreen_spinboxIntermittentDurationMinute, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_spinboxIntermittentDurationMinute, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_spinboxIntermittentDurationMinute, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_spinboxIntermittentDurationMinute, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_spinboxIntermittentDurationMinute, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_spinboxIntermittentDurationMinute, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxIntermittentDurationMinute, &lv_font_Alatsi_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxIntermittentDurationMinute, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_spinboxIntermittentDurationMinute, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_spinboxIntermittentDurationMinute, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_spinboxIntermittentDurationMinute, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_spinboxIntermittentDurationMinute, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->MainScreen_spinboxIntermittentDurationMinute, lv_color_hex(0x000000), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxIntermittentDurationMinute, &lv_font_Alatsi_Regular_16, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxIntermittentDurationMinute, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxIntermittentDurationMinute, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxIntermittentDurationMinute, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxIntermittentDurationMinute, LV_GRAD_DIR_NONE, LV_PART_CURSOR|LV_STATE_DEFAULT);

	//Write codes MainScreen_spinboxIntermittentDurationSecond
	ui->MainScreen_spinboxIntermittentDurationSecond = lv_spinbox_create(ui->MainScreen_contIntermittentDuration);
	lv_obj_set_pos(ui->MainScreen_spinboxIntermittentDurationSecond, 110, 5);
	lv_obj_set_width(ui->MainScreen_spinboxIntermittentDurationSecond, 30);
	lv_obj_set_height(ui->MainScreen_spinboxIntermittentDurationSecond, 25);
	lv_spinbox_set_digit_format(ui->MainScreen_spinboxIntermittentDurationSecond, 2, 2);
	lv_spinbox_set_range(ui->MainScreen_spinboxIntermittentDurationSecond, -99, 99);
	lv_coord_t MainScreen_spinboxIntermittentDurationSecond_h = lv_obj_get_height(ui->MainScreen_spinboxIntermittentDurationSecond);
	ui->MainScreen_spinboxIntermittentDurationSecond_btn = lv_btn_create(ui->MainScreen_contIntermittentDuration);
	lv_obj_set_size(ui->MainScreen_spinboxIntermittentDurationSecond_btn, MainScreen_spinboxIntermittentDurationSecond_h, MainScreen_spinboxIntermittentDurationSecond_h);
	lv_obj_align_to(ui->MainScreen_spinboxIntermittentDurationSecond_btn, ui->MainScreen_spinboxIntermittentDurationSecond, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxIntermittentDurationSecond_btn, LV_SYMBOL_PLUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxIntermittentDurationSecond_btn, lv_MainScreen_spinboxIntermittentDurationSecond_increment_event_cb, LV_EVENT_ALL, NULL);
	ui->MainScreen_spinboxIntermittentDurationSecond_btn_minus = lv_btn_create(ui->MainScreen_contIntermittentDuration);
	lv_obj_set_size(ui->MainScreen_spinboxIntermittentDurationSecond_btn_minus, MainScreen_spinboxIntermittentDurationSecond_h, MainScreen_spinboxIntermittentDurationSecond_h);
	lv_obj_align_to(ui->MainScreen_spinboxIntermittentDurationSecond_btn_minus, ui->MainScreen_spinboxIntermittentDurationSecond, LV_ALIGN_OUT_LEFT_MID, -5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxIntermittentDurationSecond_btn_minus, LV_SYMBOL_MINUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxIntermittentDurationSecond_btn_minus, lv_MainScreen_spinboxIntermittentDurationSecond_decrement_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_set_pos(ui->MainScreen_spinboxIntermittentDurationSecond, 110, 5);

	//Write style for MainScreen_spinboxIntermittentDurationSecond, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxIntermittentDurationSecond, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxIntermittentDurationSecond, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxIntermittentDurationSecond, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_spinboxIntermittentDurationSecond, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->MainScreen_spinboxIntermittentDurationSecond, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->MainScreen_spinboxIntermittentDurationSecond, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->MainScreen_spinboxIntermittentDurationSecond, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_spinboxIntermittentDurationSecond, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_spinboxIntermittentDurationSecond, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_spinboxIntermittentDurationSecond, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_spinboxIntermittentDurationSecond, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_spinboxIntermittentDurationSecond, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxIntermittentDurationSecond, &lv_font_Alatsi_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxIntermittentDurationSecond, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_spinboxIntermittentDurationSecond, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_spinboxIntermittentDurationSecond, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_spinboxIntermittentDurationSecond, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_spinboxIntermittentDurationSecond, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->MainScreen_spinboxIntermittentDurationSecond, lv_color_hex(0x000000), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxIntermittentDurationSecond, &lv_font_Alatsi_Regular_16, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxIntermittentDurationSecond, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxIntermittentDurationSecond, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxIntermittentDurationSecond, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxIntermittentDurationSecond, LV_GRAD_DIR_NONE, LV_PART_CURSOR|LV_STATE_DEFAULT);

	//Write codes MainScreen_spinboxIntermittentBackgroundRate
	ui->MainScreen_spinboxIntermittentBackgroundRate = lv_spinbox_create(ui->MainScreen_contIntermittentValues);
	lv_obj_set_pos(ui->MainScreen_spinboxIntermittentBackgroundRate, 320, 152);
	lv_obj_set_width(ui->MainScreen_spinboxIntermittentBackgroundRate, 40);
	lv_obj_set_height(ui->MainScreen_spinboxIntermittentBackgroundRate, 25);
	lv_spinbox_set_digit_format(ui->MainScreen_spinboxIntermittentBackgroundRate, 2, 1);
	lv_spinbox_set_range(ui->MainScreen_spinboxIntermittentBackgroundRate, -99, 99);
	lv_coord_t MainScreen_spinboxIntermittentBackgroundRate_h = lv_obj_get_height(ui->MainScreen_spinboxIntermittentBackgroundRate);
	ui->MainScreen_spinboxIntermittentBackgroundRate_btn = lv_btn_create(ui->MainScreen_contIntermittentValues);
	lv_obj_set_size(ui->MainScreen_spinboxIntermittentBackgroundRate_btn, MainScreen_spinboxIntermittentBackgroundRate_h, MainScreen_spinboxIntermittentBackgroundRate_h);
	lv_obj_align_to(ui->MainScreen_spinboxIntermittentBackgroundRate_btn, ui->MainScreen_spinboxIntermittentBackgroundRate, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxIntermittentBackgroundRate_btn, LV_SYMBOL_PLUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxIntermittentBackgroundRate_btn, lv_MainScreen_spinboxIntermittentBackgroundRate_increment_event_cb, LV_EVENT_ALL, NULL);
	ui->MainScreen_spinboxIntermittentBackgroundRate_btn_minus = lv_btn_create(ui->MainScreen_contIntermittentValues);
	lv_obj_set_size(ui->MainScreen_spinboxIntermittentBackgroundRate_btn_minus, MainScreen_spinboxIntermittentBackgroundRate_h, MainScreen_spinboxIntermittentBackgroundRate_h);
	lv_obj_align_to(ui->MainScreen_spinboxIntermittentBackgroundRate_btn_minus, ui->MainScreen_spinboxIntermittentBackgroundRate, LV_ALIGN_OUT_LEFT_MID, -5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxIntermittentBackgroundRate_btn_minus, LV_SYMBOL_MINUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxIntermittentBackgroundRate_btn_minus, lv_MainScreen_spinboxIntermittentBackgroundRate_decrement_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_set_pos(ui->MainScreen_spinboxIntermittentBackgroundRate, 320, 152);

	//Write style for MainScreen_spinboxIntermittentBackgroundRate, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxIntermittentBackgroundRate, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxIntermittentBackgroundRate, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxIntermittentBackgroundRate, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_spinboxIntermittentBackgroundRate, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->MainScreen_spinboxIntermittentBackgroundRate, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->MainScreen_spinboxIntermittentBackgroundRate, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->MainScreen_spinboxIntermittentBackgroundRate, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_spinboxIntermittentBackgroundRate, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_spinboxIntermittentBackgroundRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_spinboxIntermittentBackgroundRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_spinboxIntermittentBackgroundRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_spinboxIntermittentBackgroundRate, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxIntermittentBackgroundRate, &lv_font_Alatsi_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxIntermittentBackgroundRate, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_spinboxIntermittentBackgroundRate, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_spinboxIntermittentBackgroundRate, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_spinboxIntermittentBackgroundRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_spinboxIntermittentBackgroundRate, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->MainScreen_spinboxIntermittentBackgroundRate, lv_color_hex(0x000000), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxIntermittentBackgroundRate, &lv_font_Alatsi_Regular_16, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxIntermittentBackgroundRate, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxIntermittentBackgroundRate, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxIntermittentBackgroundRate, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxIntermittentBackgroundRate, LV_GRAD_DIR_NONE, LV_PART_CURSOR|LV_STATE_DEFAULT);

	//Write codes MainScreen_contIntermittentSleep
	ui->MainScreen_contIntermittentSleep = lv_obj_create(ui->MainScreen_contIntermittentValues);
	lv_obj_set_pos(ui->MainScreen_contIntermittentSleep, 281, 205.5);
	lv_obj_set_size(ui->MainScreen_contIntermittentSleep, 150, 36);
	lv_obj_set_scrollbar_mode(ui->MainScreen_contIntermittentSleep, LV_SCROLLBAR_MODE_OFF);

	//Write style for MainScreen_contIntermittentSleep, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_contIntermittentSleep, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_contIntermittentSleep, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_contIntermittentSleep, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_contIntermittentSleep, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_contIntermittentSleep, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_contIntermittentSleep, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_contIntermittentSleep, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_contIntermittentSleep, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_contIntermittentSleep, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_contIntermittentSleep, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_60
	ui->MainScreen_label_60 = lv_label_create(ui->MainScreen_contIntermittentSleep);
	lv_label_set_text(ui->MainScreen_label_60, ":");
	lv_label_set_long_mode(ui->MainScreen_label_60, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_60, 50, 4);
	lv_obj_set_size(ui->MainScreen_label_60, 7, 25);

	//Write style for MainScreen_label_60, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_60, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_60, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_60, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_60, &lv_font_Alatsi_Regular_21, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_60, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_60, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_60, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_60, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_60, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_60, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_60, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_60, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_60, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_60, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_59
	ui->MainScreen_label_59 = lv_label_create(ui->MainScreen_contIntermittentSleep);
	lv_label_set_text(ui->MainScreen_label_59, ":");
	lv_label_set_long_mode(ui->MainScreen_label_59, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_59, 100, 6);
	lv_obj_set_size(ui->MainScreen_label_59, 7, 25);

	//Write style for MainScreen_label_59, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_59, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_59, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_59, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_59, &lv_font_Alatsi_Regular_21, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_59, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_59, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_59, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_59, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_59, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_59, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_59, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_59, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_59, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_59, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_spinboxIntermittentSleepHour
	ui->MainScreen_spinboxIntermittentSleepHour = lv_spinbox_create(ui->MainScreen_contIntermittentSleep);
	lv_obj_set_pos(ui->MainScreen_spinboxIntermittentSleepHour, 10, 5);
	lv_obj_set_width(ui->MainScreen_spinboxIntermittentSleepHour, 30);
	lv_obj_set_height(ui->MainScreen_spinboxIntermittentSleepHour, 25);
	lv_spinbox_set_digit_format(ui->MainScreen_spinboxIntermittentSleepHour, 2, 2);
	lv_spinbox_set_range(ui->MainScreen_spinboxIntermittentSleepHour, -99, 99);
	lv_coord_t MainScreen_spinboxIntermittentSleepHour_h = lv_obj_get_height(ui->MainScreen_spinboxIntermittentSleepHour);
	ui->MainScreen_spinboxIntermittentSleepHour_btn = lv_btn_create(ui->MainScreen_contIntermittentSleep);
	lv_obj_set_size(ui->MainScreen_spinboxIntermittentSleepHour_btn, MainScreen_spinboxIntermittentSleepHour_h, MainScreen_spinboxIntermittentSleepHour_h);
	lv_obj_align_to(ui->MainScreen_spinboxIntermittentSleepHour_btn, ui->MainScreen_spinboxIntermittentSleepHour, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxIntermittentSleepHour_btn, LV_SYMBOL_PLUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxIntermittentSleepHour_btn, lv_MainScreen_spinboxIntermittentSleepHour_increment_event_cb, LV_EVENT_ALL, NULL);
	ui->MainScreen_spinboxIntermittentSleepHour_btn_minus = lv_btn_create(ui->MainScreen_contIntermittentSleep);
	lv_obj_set_size(ui->MainScreen_spinboxIntermittentSleepHour_btn_minus, MainScreen_spinboxIntermittentSleepHour_h, MainScreen_spinboxIntermittentSleepHour_h);
	lv_obj_align_to(ui->MainScreen_spinboxIntermittentSleepHour_btn_minus, ui->MainScreen_spinboxIntermittentSleepHour, LV_ALIGN_OUT_LEFT_MID, -5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxIntermittentSleepHour_btn_minus, LV_SYMBOL_MINUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxIntermittentSleepHour_btn_minus, lv_MainScreen_spinboxIntermittentSleepHour_decrement_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_set_pos(ui->MainScreen_spinboxIntermittentSleepHour, 10, 5);

	//Write style for MainScreen_spinboxIntermittentSleepHour, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxIntermittentSleepHour, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxIntermittentSleepHour, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxIntermittentSleepHour, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_spinboxIntermittentSleepHour, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->MainScreen_spinboxIntermittentSleepHour, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->MainScreen_spinboxIntermittentSleepHour, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->MainScreen_spinboxIntermittentSleepHour, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_spinboxIntermittentSleepHour, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_spinboxIntermittentSleepHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_spinboxIntermittentSleepHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_spinboxIntermittentSleepHour, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_spinboxIntermittentSleepHour, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxIntermittentSleepHour, &lv_font_Alatsi_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxIntermittentSleepHour, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_spinboxIntermittentSleepHour, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_spinboxIntermittentSleepHour, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_spinboxIntermittentSleepHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_spinboxIntermittentSleepHour, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->MainScreen_spinboxIntermittentSleepHour, lv_color_hex(0x000000), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxIntermittentSleepHour, &lv_font_Alatsi_Regular_16, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxIntermittentSleepHour, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxIntermittentSleepHour, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxIntermittentSleepHour, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxIntermittentSleepHour, LV_GRAD_DIR_NONE, LV_PART_CURSOR|LV_STATE_DEFAULT);

	//Write codes MainScreen_spinboxIntermittentSleepMinute
	ui->MainScreen_spinboxIntermittentSleepMinute = lv_spinbox_create(ui->MainScreen_contIntermittentSleep);
	lv_obj_set_pos(ui->MainScreen_spinboxIntermittentSleepMinute, 60, 5);
	lv_obj_set_width(ui->MainScreen_spinboxIntermittentSleepMinute, 30);
	lv_obj_set_height(ui->MainScreen_spinboxIntermittentSleepMinute, 25);
	lv_spinbox_set_digit_format(ui->MainScreen_spinboxIntermittentSleepMinute, 2, 2);
	lv_spinbox_set_range(ui->MainScreen_spinboxIntermittentSleepMinute, -99, 99);
	lv_coord_t MainScreen_spinboxIntermittentSleepMinute_h = lv_obj_get_height(ui->MainScreen_spinboxIntermittentSleepMinute);
	ui->MainScreen_spinboxIntermittentSleepMinute_btn = lv_btn_create(ui->MainScreen_contIntermittentSleep);
	lv_obj_set_size(ui->MainScreen_spinboxIntermittentSleepMinute_btn, MainScreen_spinboxIntermittentSleepMinute_h, MainScreen_spinboxIntermittentSleepMinute_h);
	lv_obj_align_to(ui->MainScreen_spinboxIntermittentSleepMinute_btn, ui->MainScreen_spinboxIntermittentSleepMinute, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxIntermittentSleepMinute_btn, LV_SYMBOL_PLUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxIntermittentSleepMinute_btn, lv_MainScreen_spinboxIntermittentSleepMinute_increment_event_cb, LV_EVENT_ALL, NULL);
	ui->MainScreen_spinboxIntermittentSleepMinute_btn_minus = lv_btn_create(ui->MainScreen_contIntermittentSleep);
	lv_obj_set_size(ui->MainScreen_spinboxIntermittentSleepMinute_btn_minus, MainScreen_spinboxIntermittentSleepMinute_h, MainScreen_spinboxIntermittentSleepMinute_h);
	lv_obj_align_to(ui->MainScreen_spinboxIntermittentSleepMinute_btn_minus, ui->MainScreen_spinboxIntermittentSleepMinute, LV_ALIGN_OUT_LEFT_MID, -5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxIntermittentSleepMinute_btn_minus, LV_SYMBOL_MINUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxIntermittentSleepMinute_btn_minus, lv_MainScreen_spinboxIntermittentSleepMinute_decrement_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_set_pos(ui->MainScreen_spinboxIntermittentSleepMinute, 60, 5);

	//Write style for MainScreen_spinboxIntermittentSleepMinute, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxIntermittentSleepMinute, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxIntermittentSleepMinute, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxIntermittentSleepMinute, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_spinboxIntermittentSleepMinute, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->MainScreen_spinboxIntermittentSleepMinute, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->MainScreen_spinboxIntermittentSleepMinute, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->MainScreen_spinboxIntermittentSleepMinute, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_spinboxIntermittentSleepMinute, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_spinboxIntermittentSleepMinute, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_spinboxIntermittentSleepMinute, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_spinboxIntermittentSleepMinute, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_spinboxIntermittentSleepMinute, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxIntermittentSleepMinute, &lv_font_Alatsi_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxIntermittentSleepMinute, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_spinboxIntermittentSleepMinute, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_spinboxIntermittentSleepMinute, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_spinboxIntermittentSleepMinute, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_spinboxIntermittentSleepMinute, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->MainScreen_spinboxIntermittentSleepMinute, lv_color_hex(0x000000), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxIntermittentSleepMinute, &lv_font_Alatsi_Regular_16, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxIntermittentSleepMinute, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxIntermittentSleepMinute, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxIntermittentSleepMinute, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxIntermittentSleepMinute, LV_GRAD_DIR_NONE, LV_PART_CURSOR|LV_STATE_DEFAULT);

	//Write codes MainScreen_spinboxIntermittentSleepSecond
	ui->MainScreen_spinboxIntermittentSleepSecond = lv_spinbox_create(ui->MainScreen_contIntermittentSleep);
	lv_obj_set_pos(ui->MainScreen_spinboxIntermittentSleepSecond, 110, 5);
	lv_obj_set_width(ui->MainScreen_spinboxIntermittentSleepSecond, 30);
	lv_obj_set_height(ui->MainScreen_spinboxIntermittentSleepSecond, 25);
	lv_spinbox_set_digit_format(ui->MainScreen_spinboxIntermittentSleepSecond, 2, 2);
	lv_spinbox_set_range(ui->MainScreen_spinboxIntermittentSleepSecond, -99, 99);
	lv_coord_t MainScreen_spinboxIntermittentSleepSecond_h = lv_obj_get_height(ui->MainScreen_spinboxIntermittentSleepSecond);
	ui->MainScreen_spinboxIntermittentSleepSecond_btn = lv_btn_create(ui->MainScreen_contIntermittentSleep);
	lv_obj_set_size(ui->MainScreen_spinboxIntermittentSleepSecond_btn, MainScreen_spinboxIntermittentSleepSecond_h, MainScreen_spinboxIntermittentSleepSecond_h);
	lv_obj_align_to(ui->MainScreen_spinboxIntermittentSleepSecond_btn, ui->MainScreen_spinboxIntermittentSleepSecond, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxIntermittentSleepSecond_btn, LV_SYMBOL_PLUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxIntermittentSleepSecond_btn, lv_MainScreen_spinboxIntermittentSleepSecond_increment_event_cb, LV_EVENT_ALL, NULL);
	ui->MainScreen_spinboxIntermittentSleepSecond_btn_minus = lv_btn_create(ui->MainScreen_contIntermittentSleep);
	lv_obj_set_size(ui->MainScreen_spinboxIntermittentSleepSecond_btn_minus, MainScreen_spinboxIntermittentSleepSecond_h, MainScreen_spinboxIntermittentSleepSecond_h);
	lv_obj_align_to(ui->MainScreen_spinboxIntermittentSleepSecond_btn_minus, ui->MainScreen_spinboxIntermittentSleepSecond, LV_ALIGN_OUT_LEFT_MID, -5, 0);
	lv_obj_set_style_bg_img_src(ui->MainScreen_spinboxIntermittentSleepSecond_btn_minus, LV_SYMBOL_MINUS, 0);
	lv_obj_add_event_cb(ui->MainScreen_spinboxIntermittentSleepSecond_btn_minus, lv_MainScreen_spinboxIntermittentSleepSecond_decrement_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_set_pos(ui->MainScreen_spinboxIntermittentSleepSecond, 110, 5);

	//Write style for MainScreen_spinboxIntermittentSleepSecond, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxIntermittentSleepSecond, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxIntermittentSleepSecond, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxIntermittentSleepSecond, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_spinboxIntermittentSleepSecond, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->MainScreen_spinboxIntermittentSleepSecond, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->MainScreen_spinboxIntermittentSleepSecond, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->MainScreen_spinboxIntermittentSleepSecond, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_spinboxIntermittentSleepSecond, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_spinboxIntermittentSleepSecond, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_spinboxIntermittentSleepSecond, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_spinboxIntermittentSleepSecond, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_spinboxIntermittentSleepSecond, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxIntermittentSleepSecond, &lv_font_Alatsi_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxIntermittentSleepSecond, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_spinboxIntermittentSleepSecond, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_spinboxIntermittentSleepSecond, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_spinboxIntermittentSleepSecond, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_spinboxIntermittentSleepSecond, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->MainScreen_spinboxIntermittentSleepSecond, lv_color_hex(0x000000), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_spinboxIntermittentSleepSecond, &lv_font_Alatsi_Regular_16, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_spinboxIntermittentSleepSecond, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_spinboxIntermittentSleepSecond, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_spinboxIntermittentSleepSecond, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_spinboxIntermittentSleepSecond, LV_GRAD_DIR_NONE, LV_PART_CURSOR|LV_STATE_DEFAULT);

	//Write codes MainScreen_btnGOMenuIntermittent
	ui->MainScreen_btnGOMenuIntermittent = lv_btn_create(ui->MainScreen_contIntermittent);
	ui->MainScreen_btnGOMenuIntermittent_label = lv_label_create(ui->MainScreen_btnGOMenuIntermittent);
	lv_label_set_text(ui->MainScreen_btnGOMenuIntermittent_label, "");
	lv_label_set_long_mode(ui->MainScreen_btnGOMenuIntermittent_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->MainScreen_btnGOMenuIntermittent_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->MainScreen_btnGOMenuIntermittent, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->MainScreen_btnGOMenuIntermittent_label, LV_PCT(100));
	lv_obj_set_pos(ui->MainScreen_btnGOMenuIntermittent, 731, 247);
	lv_obj_set_size(ui->MainScreen_btnGOMenuIntermittent, 58, 44);

	//Write style for MainScreen_btnGOMenuIntermittent, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_btnGOMenuIntermittent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_btnGOMenuIntermittent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_btnGOMenuIntermittent, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_btnGOMenuIntermittent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_btnGOMenuIntermittent, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_btnGOMenuIntermittent, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_btnGOMenuIntermittent, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_btnGOMenuIntermittent, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_btnDummyIntermittent
	ui->MainScreen_btnDummyIntermittent = lv_btn_create(ui->MainScreen_contIntermittent);
	ui->MainScreen_btnDummyIntermittent_label = lv_label_create(ui->MainScreen_btnDummyIntermittent);
	lv_label_set_text(ui->MainScreen_btnDummyIntermittent_label, "");
	lv_label_set_long_mode(ui->MainScreen_btnDummyIntermittent_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->MainScreen_btnDummyIntermittent_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->MainScreen_btnDummyIntermittent, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->MainScreen_btnDummyIntermittent_label, LV_PCT(100));
	lv_obj_set_pos(ui->MainScreen_btnDummyIntermittent, 776, 129);
	lv_obj_set_size(ui->MainScreen_btnDummyIntermittent, 8, 10);

	//Write style for MainScreen_btnDummyIntermittent, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_btnDummyIntermittent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_btnDummyIntermittent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_btnDummyIntermittent, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_btnDummyIntermittent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_btnDummyIntermittent, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_btnDummyIntermittent, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_btnDummyIntermittent, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_btnDummyIntermittent, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_ta_keybard
	ui->MainScreen_ta_keybard = lv_textarea_create(ui->MainScreen);
	lv_textarea_set_text(ui->MainScreen_ta_keybard, "hckdsjclsd");
	lv_textarea_set_placeholder_text(ui->MainScreen_ta_keybard, "");
	lv_textarea_set_password_bullet(ui->MainScreen_ta_keybard, "*");
	lv_textarea_set_password_mode(ui->MainScreen_ta_keybard, false);
	lv_textarea_set_one_line(ui->MainScreen_ta_keybard, true);
	lv_textarea_set_accepted_chars(ui->MainScreen_ta_keybard, "");
	lv_textarea_set_max_length(ui->MainScreen_ta_keybard, 32);
	#if LV_USE_KEYBOARD != 0 || LV_USE_ZH_KEYBOARD != 0
		lv_obj_add_event_cb(ui->MainScreen_ta_keybard, ta_event_cb, LV_EVENT_ALL, ui->g_kb_MainScreen);
	#endif
	lv_obj_set_pos(ui->MainScreen_ta_keybard, 294, -43);
	lv_obj_set_size(ui->MainScreen_ta_keybard, 400, 40);
	lv_obj_add_flag(ui->MainScreen_ta_keybard, LV_OBJ_FLAG_HIDDEN);

	//Write style for MainScreen_ta_keybard, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->MainScreen_ta_keybard, lv_color_hex(0x0652ff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_ta_keybard, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_ta_keybard, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_ta_keybard, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_ta_keybard, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_ta_keybard, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_ta_keybard, lv_color_hex(0xbababa), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_ta_keybard, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_ta_keybard, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->MainScreen_ta_keybard, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->MainScreen_ta_keybard, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->MainScreen_ta_keybard, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_ta_keybard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_ta_keybard, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_ta_keybard, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_ta_keybard, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_ta_keybard, 4, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_ta_keybard, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_ta_keybard, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_ta_keybard, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_ta_keybard, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_ta_keybard, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//The custom code of MainScreen.
		//level style
	lv_obj_set_size(ui->g_kb_MainScreen,800,200);
	lv_obj_set_parent(ui->MainScreen_ta_keybard,ui->g_kb_MainScreen);
	lv_obj_set_style_pad_top(ui->g_kb_MainScreen,50,LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_align_to(ui->MainScreen_ta_keybard,ui->g_kb_MainScreen, LV_ALIGN_TOP_MID,0,-50);


lv_obj_clear_flag(ui->MainScreen_btnGoMenuMain, LV_OBJ_FLAG_CLICK_FOCUSABLE);
lv_obj_clear_flag(ui->MainScreen_btnGoMainMenu, LV_OBJ_FLAG_CLICK_FOCUSABLE);
lv_obj_clear_flag(ui->MainScreen_btnGoMenuSyringe, LV_OBJ_FLAG_CLICK_FOCUSABLE);
lv_obj_clear_flag(ui->MainScreen_btnGoMenuDrug, LV_OBJ_FLAG_CLICK_FOCUSABLE);
lv_obj_clear_flag(ui->MainScreen_btnGoMenuMode, LV_OBJ_FLAG_CLICK_FOCUSABLE);

lv_obj_clear_flag(ui->MainScreen_datetext, LV_OBJ_FLAG_CLICK_FOCUSABLE);
lv_obj_set_style_radius(ui->MainScreen_barBatteryLevel, 0, LV_PART_MAIN);
lv_obj_set_style_radius(ui->MainScreen_barBatteryLevel,0,LV_PART_INDICATOR|LV_STATE_DEFAULT);
lv_obj_set_style_radius(ui->MainScreen_barOcclusionLevel, 0, LV_PART_MAIN);
lv_obj_set_style_radius(ui->MainScreen_barOcclusionLevel,0,LV_PART_INDICATOR|LV_STATE_DEFAULT);

//spinbox styles

lv_obj_add_flag(ui->MainScreen_spinboxSyringeVolume_btn,LV_OBJ_FLAG_HIDDEN);
lv_obj_add_flag(ui->MainScreen_spinboxSyringeVolume_btn_minus,LV_OBJ_FLAG_HIDDEN);

lv_obj_add_flag(ui->MainScreen_spinboxSyringeInnerDia_btn,LV_OBJ_FLAG_HIDDEN);
lv_obj_add_flag(ui->MainScreen_spinboxSyringeInnerDia_btn_minus,LV_OBJ_FLAG_HIDDEN);

lv_obj_add_flag(ui->MainScreen_spinboxSyringeOuterDia_btn,LV_OBJ_FLAG_HIDDEN);
lv_obj_add_flag(ui->MainScreen_spinboxSyringeOuterDia_btn_minus,LV_OBJ_FLAG_HIDDEN);

lv_obj_add_flag(ui->MainScreen_spinboxSyringeBarrelLen_btn,LV_OBJ_FLAG_HIDDEN);
lv_obj_add_flag(ui->MainScreen_spinboxSyringeBarrelLen_btn_minus,LV_OBJ_FLAG_HIDDEN);

lv_obj_add_flag(ui->MainScreen_spinboxSyringePlungerLen_btn,LV_OBJ_FLAG_HIDDEN);
lv_obj_add_flag(ui->MainScreen_spinboxSyringePlungerLen_btn_minus,LV_OBJ_FLAG_HIDDEN);

lv_obj_add_flag(ui->MainScreen_spinboxSyringeDiaTolerance_btn,LV_OBJ_FLAG_HIDDEN);
lv_obj_add_flag(ui->MainScreen_spinboxSyringeDiaTolerance_btn_minus,LV_OBJ_FLAG_HIDDEN);

lv_spinbox_set_range(ui->MainScreen_spinboxSyringeVolume,0,60);
lv_spinbox_set_range(ui->MainScreen_spinboxSyringeInnerDia,0,500);
lv_spinbox_set_range(ui->MainScreen_spinboxSyringeOuterDia,0,500);
lv_spinbox_set_range(ui->MainScreen_spinboxSyringeBarrelLen,0,2000);
lv_spinbox_set_range(ui->MainScreen_spinboxSyringePlungerLen,0,600);
lv_spinbox_set_range(ui->MainScreen_spinboxSyringeDiaTolerance,-100,100);


lv_obj_add_flag(ui->MainScreen_spinboxDrugmgml_btn,LV_OBJ_FLAG_HIDDEN);
lv_obj_add_flag(ui->MainScreen_spinboxDrugmgml_btn_minus,LV_OBJ_FLAG_HIDDEN);

lv_obj_add_flag(ui->MainScreen_spinboxDruguml_btn,LV_OBJ_FLAG_HIDDEN);
lv_obj_add_flag(ui->MainScreen_spinboxDruguml_btn_minus,LV_OBJ_FLAG_HIDDEN);

lv_obj_add_flag(ui->MainScreen_spinboxDrugperkg_btn,LV_OBJ_FLAG_HIDDEN);
lv_obj_add_flag(ui->MainScreen_spinboxDrugperkg_btn_minus,LV_OBJ_FLAG_HIDDEN);

lv_obj_add_flag(ui->MainScreen_spinboxDrugRateMin_btn,LV_OBJ_FLAG_HIDDEN);
lv_obj_add_flag(ui->MainScreen_spinboxDrugRateMin_btn_minus,LV_OBJ_FLAG_HIDDEN);

lv_obj_add_flag(ui->MainScreen_spinboxDrugRateMax_btn,LV_OBJ_FLAG_HIDDEN);
lv_obj_add_flag(ui->MainScreen_spinboxDrugRateMax_btn_minus,LV_OBJ_FLAG_HIDDEN);

lv_obj_add_flag(ui->MainScreen_spinboxDrugRateDef_btn,LV_OBJ_FLAG_HIDDEN);
lv_obj_add_flag(ui->MainScreen_spinboxDrugRateDef_btn_minus,LV_OBJ_FLAG_HIDDEN);

lv_spinbox_set_range(ui->MainScreen_spinboxDrugmgml,0,10000);
lv_spinbox_set_range(ui->MainScreen_spinboxDruguml,0,10000);
lv_spinbox_set_range(ui->MainScreen_spinboxDrugperkg,0,20000);
lv_spinbox_set_range(ui->MainScreen_spinboxDrugRateMin,0,18000);
lv_spinbox_set_range(ui->MainScreen_spinboxDrugRateMax,0,18000);
lv_spinbox_set_range(ui->MainScreen_spinboxDrugRateDef,0,18000);



lv_obj_add_flag(ui->MainScreen_spinboxModeBodyWeight_btn,LV_OBJ_FLAG_HIDDEN);
lv_obj_add_flag(ui->MainScreen_spinboxModeBodyWeight_btn_minus,LV_OBJ_FLAG_HIDDEN);


lv_obj_add_flag(ui->MainScreen_spinboxModeInfusionRate_btn,LV_OBJ_FLAG_HIDDEN);
lv_obj_add_flag(ui->MainScreen_spinboxModeInfusionRate_btn_minus,LV_OBJ_FLAG_HIDDEN);

lv_obj_add_flag(ui->MainScreen_spinboxModeTotalTimeHour_btn,LV_OBJ_FLAG_HIDDEN);
lv_obj_add_flag(ui->MainScreen_spinboxModeTotalTimeHour_btn_minus,LV_OBJ_FLAG_HIDDEN);

lv_obj_add_flag(ui->MainScreen_spinboxModeTotalTimeMinute_btn,LV_OBJ_FLAG_HIDDEN);
lv_obj_add_flag(ui->MainScreen_spinboxModeTotalTimeMinute_btn_minus,LV_OBJ_FLAG_HIDDEN);

lv_obj_add_flag(ui->MainScreen_spinboxModeTotalTimeSecond_btn,LV_OBJ_FLAG_HIDDEN);
lv_obj_add_flag(ui->MainScreen_spinboxModeTotalTimeSecond_btn_minus,LV_OBJ_FLAG_HIDDEN);

lv_obj_add_flag(ui->MainScreen_spinboxModeTotalVolume_btn,LV_OBJ_FLAG_HIDDEN);
lv_obj_add_flag(ui->MainScreen_spinboxModeTotalVolume_btn_minus,LV_OBJ_FLAG_HIDDEN);

lv_spinbox_set_range(ui->MainScreen_spinboxModeBodyWeight,0,300);
lv_spinbox_set_range(ui->MainScreen_spinboxModeInfusionRate,0,990);
lv_spinbox_set_range(ui->MainScreen_spinboxModeTotalTimeHour,0,99);
lv_spinbox_set_range(ui->MainScreen_spinboxModeTotalTimeMinute,0,59);
lv_spinbox_set_range(ui->MainScreen_spinboxModeTotalTimeSecond,0,59);
lv_spinbox_set_range(ui->MainScreen_spinboxModeTotalVolume,0,18000);


lv_obj_set_style_radius(ui->MainScreen_sliderOcclusionOcc, 0, LV_PART_MAIN);
lv_obj_set_style_radius(ui->MainScreen_sliderOcclusionOcc,0,LV_PART_INDICATOR|
                                                            LV_STATE_DEFAULT|
                                                            LV_STATE_FOCUS_KEY|
                                                            LV_STATE_FOCUSED);


lv_obj_add_flag(ui->MainScreen_spinboxKVORate_btn,LV_OBJ_FLAG_HIDDEN);
lv_obj_add_flag(ui->MainScreen_spinboxKVORate_btn_minus,LV_OBJ_FLAG_HIDDEN);
lv_spinbox_set_range(ui->MainScreen_spinboxKVORate,0,20);

lv_obj_add_flag(ui->MainScreen_spinboxIntermittentInfusionRate_btn,LV_OBJ_FLAG_HIDDEN);
lv_obj_add_flag(ui->MainScreen_spinboxIntermittentInfusionRate_btn_minus,LV_OBJ_FLAG_HIDDEN);

lv_obj_add_flag(ui->MainScreen_spinboxIntermittentDurationHour_btn,LV_OBJ_FLAG_HIDDEN);
lv_obj_add_flag(ui->MainScreen_spinboxIntermittentDurationHour_btn_minus,LV_OBJ_FLAG_HIDDEN);

lv_obj_add_flag(ui->MainScreen_spinboxIntermittentDurationMinute_btn,LV_OBJ_FLAG_HIDDEN);
lv_obj_add_flag(ui->MainScreen_spinboxIntermittentDurationMinute_btn_minus,LV_OBJ_FLAG_HIDDEN);

lv_obj_add_flag(ui->MainScreen_spinboxIntermittentDurationSecond_btn,LV_OBJ_FLAG_HIDDEN);
lv_obj_add_flag(ui->MainScreen_spinboxIntermittentDurationSecond_btn_minus,LV_OBJ_FLAG_HIDDEN);

lv_obj_add_flag(ui->MainScreen_spinboxIntermittentBackgroundRate_btn,LV_OBJ_FLAG_HIDDEN);
lv_obj_add_flag(ui->MainScreen_spinboxIntermittentBackgroundRate_btn_minus,LV_OBJ_FLAG_HIDDEN);

lv_obj_add_flag(ui->MainScreen_spinboxIntermittentSleepHour_btn,LV_OBJ_FLAG_HIDDEN);
lv_obj_add_flag(ui->MainScreen_spinboxIntermittentSleepHour_btn_minus,LV_OBJ_FLAG_HIDDEN);

lv_obj_add_flag(ui->MainScreen_spinboxIntermittentSleepMinute_btn,LV_OBJ_FLAG_HIDDEN);
lv_obj_add_flag(ui->MainScreen_spinboxIntermittentSleepMinute_btn_minus,LV_OBJ_FLAG_HIDDEN);

lv_obj_add_flag(ui->MainScreen_spinboxIntermittentSleepSecond_btn,LV_OBJ_FLAG_HIDDEN);
lv_obj_add_flag(ui->MainScreen_spinboxIntermittentSleepSecond_btn_minus,LV_OBJ_FLAG_HIDDEN);

lv_spinbox_set_range(ui->MainScreen_spinboxIntermittentInfusionRate,0,18000);
lv_spinbox_set_range(ui->MainScreen_spinboxIntermittentDurationHour,0,99);
lv_spinbox_set_range(ui->MainScreen_spinboxIntermittentDurationMinute,0,59);
lv_spinbox_set_range(ui->MainScreen_spinboxIntermittentDurationSecond,0,59);
lv_spinbox_set_range(ui->MainScreen_spinboxIntermittentBackgroundRate,0,50);
lv_spinbox_set_range(ui->MainScreen_spinboxIntermittentSleepHour,0,99);
lv_spinbox_set_range(ui->MainScreen_spinboxIntermittentSleepMinute,0,59);
lv_spinbox_set_range(ui->MainScreen_spinboxIntermittentSleepSecond,0,59);

MainScreen_digital_clock_timer(NULL);
MainScreenSetStyle(ui);
LoadDefaults();


	//Update current screen layout.
	lv_obj_update_layout(ui->MainScreen);

	//Init events for screen.
	events_init_MainScreen(ui);
}
