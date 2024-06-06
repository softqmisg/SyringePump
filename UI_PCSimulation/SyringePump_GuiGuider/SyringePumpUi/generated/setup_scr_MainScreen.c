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
	lv_obj_set_size(ui->MainScreen_barOcclusionLevel, 25, 132);

	//Write style for MainScreen_barOcclusionLevel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_barOcclusionLevel, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_barOcclusionLevel, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_barOcclusionLevel, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_barOcclusionLevel, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_barOcclusionLevel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->MainScreen_barOcclusionLevel, &_ledbar_empty_25x132, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->MainScreen_barOcclusionLevel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_barOcclusionLevel, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_barOcclusionLevel, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_barOcclusionLevel, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_barOcclusionLevel, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_barOcclusionLevel, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->MainScreen_barOcclusionLevel, &_ledbar_full_25x132, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->MainScreen_barOcclusionLevel, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_1
	ui->MainScreen_label_1 = lv_label_create(ui->MainScreen_contMain);
	lv_label_set_text(ui->MainScreen_label_1, "Mode:\n");
	lv_label_set_long_mode(ui->MainScreen_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_1, 5, 4);
	lv_obj_set_size(ui->MainScreen_label_1, 100, 35);

	//Write style for MainScreen_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_1, lv_color_hex(0xebff00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_1, &lv_font_Acme_Regular_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_labelInjectionMode
	ui->MainScreen_labelInjectionMode = lv_label_create(ui->MainScreen_contMain);
	lv_label_set_text(ui->MainScreen_labelInjectionMode, "Volume / Mass / Dosage\n");
	lv_label_set_long_mode(ui->MainScreen_labelInjectionMode, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_labelInjectionMode, 121, 3);
	lv_obj_set_size(ui->MainScreen_labelInjectionMode, 400, 35);

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

	//Write codes MainScreen_label_2
	ui->MainScreen_label_2 = lv_label_create(ui->MainScreen_contMain);
	lv_label_set_text(ui->MainScreen_label_2, "Rate:\n");
	lv_label_set_long_mode(ui->MainScreen_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_2, 5, 45);
	lv_obj_set_size(ui->MainScreen_label_2, 100, 35);

	//Write style for MainScreen_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_2, lv_color_hex(0xff0027), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_2, &lv_font_Acme_Regular_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_2, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_labelInjectionRate
	ui->MainScreen_labelInjectionRate = lv_label_create(ui->MainScreen_contMain);
	lv_label_set_text(ui->MainScreen_labelInjectionRate, "100.0 ml/min\n\n");
	lv_label_set_long_mode(ui->MainScreen_labelInjectionRate, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_labelInjectionRate, 121, 44);
	lv_obj_set_size(ui->MainScreen_labelInjectionRate, 400, 35);

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

	//Write codes MainScreen_btnGoSettingMain
	ui->MainScreen_btnGoSettingMain = lv_btn_create(ui->MainScreen_contMain);
	ui->MainScreen_btnGoSettingMain_label = lv_label_create(ui->MainScreen_btnGoSettingMain);
	lv_label_set_text(ui->MainScreen_btnGoSettingMain_label, "");
	lv_label_set_long_mode(ui->MainScreen_btnGoSettingMain_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->MainScreen_btnGoSettingMain_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->MainScreen_btnGoSettingMain, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->MainScreen_btnGoSettingMain_label, LV_PCT(100));
	lv_obj_set_pos(ui->MainScreen_btnGoSettingMain, 727, 247);
	lv_obj_set_size(ui->MainScreen_btnGoSettingMain, 58, 44);

	//Write style for MainScreen_btnGoSettingMain, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_btnGoSettingMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_btnGoSettingMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_btnGoSettingMain, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_btnGoSettingMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_btnGoSettingMain, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_btnGoSettingMain, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_btnGoSettingMain, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_btnGoSettingMain, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_contSetting
	ui->MainScreen_contSetting = lv_obj_create(ui->MainScreen);
	lv_obj_set_pos(ui->MainScreen_contSetting, 800, 80);
	lv_obj_set_size(ui->MainScreen_contSetting, 800, 300);
	lv_obj_set_scrollbar_mode(ui->MainScreen_contSetting, LV_SCROLLBAR_MODE_OFF);

	//Write style for MainScreen_contSetting, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_contSetting, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->MainScreen_contSetting, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->MainScreen_contSetting, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->MainScreen_contSetting, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_contSetting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_contSetting, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_contSetting, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_contSetting, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_contSetting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_contSetting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_contSetting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_contSetting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_contSetting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_btnGoMainSetting
	ui->MainScreen_btnGoMainSetting = lv_btn_create(ui->MainScreen_contSetting);
	ui->MainScreen_btnGoMainSetting_label = lv_label_create(ui->MainScreen_btnGoMainSetting);
	lv_label_set_text(ui->MainScreen_btnGoMainSetting_label, "");
	lv_label_set_long_mode(ui->MainScreen_btnGoMainSetting_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->MainScreen_btnGoMainSetting_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->MainScreen_btnGoMainSetting, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->MainScreen_btnGoMainSetting_label, LV_PCT(100));
	lv_obj_set_pos(ui->MainScreen_btnGoMainSetting, 732, 247);
	lv_obj_set_size(ui->MainScreen_btnGoMainSetting, 58, 44);

	//Write style for MainScreen_btnGoMainSetting, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_btnGoMainSetting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_btnGoMainSetting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_btnGoMainSetting, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_btnGoMainSetting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_btnGoMainSetting, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_btnGoMainSetting, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_btnGoMainSetting, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_btnGoMainSetting, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_7
	ui->MainScreen_label_7 = lv_label_create(ui->MainScreen_contSetting);
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
	ui->MainScreen_label_9 = lv_label_create(ui->MainScreen_contSetting);
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
	ui->MainScreen_label_10 = lv_label_create(ui->MainScreen_contSetting);
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
	ui->MainScreen_label_11 = lv_label_create(ui->MainScreen_contSetting);
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
	ui->MainScreen_label_12 = lv_label_create(ui->MainScreen_contSetting);
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
	ui->MainScreen_label_13 = lv_label_create(ui->MainScreen_contSetting);
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
	ui->MainScreen_label_8 = lv_label_create(ui->MainScreen_contSetting);
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
	ui->MainScreen_label_14 = lv_label_create(ui->MainScreen_contSetting);
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
	ui->MainScreen_label_15 = lv_label_create(ui->MainScreen_contSetting);
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
	ui->MainScreen_label_16 = lv_label_create(ui->MainScreen_contSetting);
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
	ui->MainScreen_label_17 = lv_label_create(ui->MainScreen_contSetting);
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
	ui->MainScreen_btnMenuSyringe = lv_btn_create(ui->MainScreen_contSetting);
	ui->MainScreen_btnMenuSyringe_label = lv_label_create(ui->MainScreen_btnMenuSyringe);
	lv_label_set_text(ui->MainScreen_btnMenuSyringe_label, "");
	lv_label_set_long_mode(ui->MainScreen_btnMenuSyringe_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->MainScreen_btnMenuSyringe_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->MainScreen_btnMenuSyringe, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->MainScreen_btnMenuSyringe_label, LV_PCT(100));
	lv_obj_set_pos(ui->MainScreen_btnMenuSyringe, 25, 5);
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
	ui->MainScreen_btnMenuDrug = lv_btn_create(ui->MainScreen_contSetting);
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
	lv_obj_set_style_bg_img_src(ui->MainScreen_btnMenuDrug, &_Syringe_100_100x100, LV_PART_MAIN|LV_STATE_DEFAULT);
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
	lv_obj_set_style_bg_img_src(ui->MainScreen_btnMenuDrug, &_Syringe_100_100x100, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_img_opa(ui->MainScreen_btnMenuDrug, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_color(ui->MainScreen_btnMenuDrug, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->MainScreen_btnMenuDrug, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_opa(ui->MainScreen_btnMenuDrug, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write codes MainScreen_btnMenuMode
	ui->MainScreen_btnMenuMode = lv_btn_create(ui->MainScreen_contSetting);
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
	lv_obj_set_style_bg_img_src(ui->MainScreen_btnMenuMode, &_Syringe_100_100x100, LV_PART_MAIN|LV_STATE_DEFAULT);
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
	lv_obj_set_style_bg_img_src(ui->MainScreen_btnMenuMode, &_Syringe_100_100x100, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_img_opa(ui->MainScreen_btnMenuMode, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_color(ui->MainScreen_btnMenuMode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->MainScreen_btnMenuMode, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_opa(ui->MainScreen_btnMenuMode, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write codes MainScreen_btnMenuOCC
	ui->MainScreen_btnMenuOCC = lv_btn_create(ui->MainScreen_contSetting);
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
	lv_obj_set_style_bg_img_src(ui->MainScreen_btnMenuOCC, &_Syringe_100_100x100, LV_PART_MAIN|LV_STATE_DEFAULT);
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
	lv_obj_set_style_bg_img_src(ui->MainScreen_btnMenuOCC, &_Syringe_100_100x100, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_img_opa(ui->MainScreen_btnMenuOCC, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_color(ui->MainScreen_btnMenuOCC, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->MainScreen_btnMenuOCC, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_opa(ui->MainScreen_btnMenuOCC, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write codes MainScreen_btnMenuKVO
	ui->MainScreen_btnMenuKVO = lv_btn_create(ui->MainScreen_contSetting);
	ui->MainScreen_btnMenuKVO_label = lv_label_create(ui->MainScreen_btnMenuKVO);
	lv_label_set_text(ui->MainScreen_btnMenuKVO_label, "");
	lv_label_set_long_mode(ui->MainScreen_btnMenuKVO_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->MainScreen_btnMenuKVO_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->MainScreen_btnMenuKVO, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->MainScreen_btnMenuKVO_label, LV_PCT(100));
	lv_obj_set_pos(ui->MainScreen_btnMenuKVO, 545, 5);
	lv_obj_set_size(ui->MainScreen_btnMenuKVO, 100, 100);

	//Write style for MainScreen_btnMenuKVO, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_btnMenuKVO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_btnMenuKVO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_btnMenuKVO, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_btnMenuKVO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->MainScreen_btnMenuKVO, &_Syringe_100_100x100, LV_PART_MAIN|LV_STATE_DEFAULT);
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
	lv_obj_set_style_bg_img_src(ui->MainScreen_btnMenuKVO, &_Syringe_100_100x100, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_img_opa(ui->MainScreen_btnMenuKVO, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_color(ui->MainScreen_btnMenuKVO, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->MainScreen_btnMenuKVO, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_opa(ui->MainScreen_btnMenuKVO, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write codes MainScreen_btnMenuIntInf
	ui->MainScreen_btnMenuIntInf = lv_btn_create(ui->MainScreen_contSetting);
	ui->MainScreen_btnMenuIntInf_label = lv_label_create(ui->MainScreen_btnMenuIntInf);
	lv_label_set_text(ui->MainScreen_btnMenuIntInf_label, "");
	lv_label_set_long_mode(ui->MainScreen_btnMenuIntInf_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->MainScreen_btnMenuIntInf_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->MainScreen_btnMenuIntInf, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->MainScreen_btnMenuIntInf_label, LV_PCT(100));
	lv_obj_set_pos(ui->MainScreen_btnMenuIntInf, 675, 5);
	lv_obj_set_size(ui->MainScreen_btnMenuIntInf, 100, 100);

	//Write style for MainScreen_btnMenuIntInf, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_btnMenuIntInf, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_btnMenuIntInf, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_btnMenuIntInf, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_btnMenuIntInf, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->MainScreen_btnMenuIntInf, &_Syringe_100_100x100, LV_PART_MAIN|LV_STATE_DEFAULT);
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
	lv_obj_set_style_bg_img_src(ui->MainScreen_btnMenuIntInf, &_Syringe_100_100x100, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_img_opa(ui->MainScreen_btnMenuIntInf, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_color(ui->MainScreen_btnMenuIntInf, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->MainScreen_btnMenuIntInf, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_opa(ui->MainScreen_btnMenuIntInf, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write codes MainScreen_btnMenuRhyInf
	ui->MainScreen_btnMenuRhyInf = lv_btn_create(ui->MainScreen_contSetting);
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
	lv_obj_set_style_bg_img_src(ui->MainScreen_btnMenuRhyInf, &_Syringe_100_100x100, LV_PART_MAIN|LV_STATE_DEFAULT);
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
	lv_obj_set_style_bg_img_src(ui->MainScreen_btnMenuRhyInf, &_Syringe_100_100x100, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_img_opa(ui->MainScreen_btnMenuRhyInf, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_color(ui->MainScreen_btnMenuRhyInf, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->MainScreen_btnMenuRhyInf, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_opa(ui->MainScreen_btnMenuRhyInf, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write codes MainScreen_btnMenuNurseCall
	ui->MainScreen_btnMenuNurseCall = lv_btn_create(ui->MainScreen_contSetting);
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
	ui->MainScreen_btnMenuBolus = lv_btn_create(ui->MainScreen_contSetting);
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
	ui->MainScreen_btnMenuPurge = lv_btn_create(ui->MainScreen_contSetting);
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
	ui->MainScreen_btnMenuSetting = lv_btn_create(ui->MainScreen_contSetting);
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

	//Write codes MainScreen_btnGoSettingSyringe
	ui->MainScreen_btnGoSettingSyringe = lv_btn_create(ui->MainScreen_contSyringe);
	ui->MainScreen_btnGoSettingSyringe_label = lv_label_create(ui->MainScreen_btnGoSettingSyringe);
	lv_label_set_text(ui->MainScreen_btnGoSettingSyringe_label, "");
	lv_label_set_long_mode(ui->MainScreen_btnGoSettingSyringe_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->MainScreen_btnGoSettingSyringe_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->MainScreen_btnGoSettingSyringe, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->MainScreen_btnGoSettingSyringe_label, LV_PCT(100));
	lv_obj_set_pos(ui->MainScreen_btnGoSettingSyringe, 733, 247);
	lv_obj_set_size(ui->MainScreen_btnGoSettingSyringe, 58, 44);

	//Write style for MainScreen_btnGoSettingSyringe, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen_btnGoSettingSyringe, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_btnGoSettingSyringe, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_btnGoSettingSyringe, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_btnGoSettingSyringe, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_btnGoSettingSyringe, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_btnGoSettingSyringe, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_btnGoSettingSyringe, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_btnGoSettingSyringe, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

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
	lv_obj_set_pos(ui->MainScreen_listSyringeCompany, -1, 29);
	lv_obj_set_size(ui->MainScreen_listSyringeCompany, 400, 140);
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
	lv_obj_set_pos(ui->MainScreen_listSyringeType, 401, 29);
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
	lv_obj_set_size(ui->MainScreen_contSyringeValues, 740, 130);
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
	lv_obj_set_pos(ui->MainScreen_spinboxSyringeVolume, 123, 34);
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
	lv_obj_set_pos(ui->MainScreen_spinboxSyringeVolume, 123, 34);

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

	//Write codes MainScreen_label_18
	ui->MainScreen_label_18 = lv_label_create(ui->MainScreen_contSyringe);
	lv_label_set_text(ui->MainScreen_label_18, "Select Company");
	lv_label_set_long_mode(ui->MainScreen_label_18, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_18, 0, 0);
	lv_obj_set_size(ui->MainScreen_label_18, 800, 30);

	//Write style for MainScreen_label_18, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_18, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_18, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_18, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_18, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_18, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_18, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_label_18, lv_color_hex(0x9ac9e7), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_label_18, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_18, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

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
	lv_obj_set_pos(ui->MainScreen_ta_keybard, 320, 77);
	lv_obj_set_size(ui->MainScreen_ta_keybard, 400, 40);
	lv_obj_add_flag(ui->MainScreen_ta_keybard, LV_OBJ_FLAG_HIDDEN);
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
lv_obj_clear_flag(guider_ui.MainScreen_btnGoSettingMain, LV_OBJ_FLAG_CLICK_FOCUSABLE);
lv_obj_clear_flag(guider_ui.MainScreen_btnGoMainSetting, LV_OBJ_FLAG_CLICK_FOCUSABLE);
lv_obj_clear_flag(guider_ui.MainScreen_btnGoSettingSyringe, LV_OBJ_FLAG_CLICK_FOCUSABLE);

lv_obj_clear_flag(guider_ui.MainScreen_datetext, LV_OBJ_FLAG_CLICK_FOCUSABLE);
lv_obj_set_style_radius(guider_ui.MainScreen_barOcclusionLevel, 0, LV_PART_MAIN);
lv_obj_set_style_radius(guider_ui.MainScreen_barBatteryLevel, 0, LV_PART_MAIN);
lv_obj_set_style_radius(ui->MainScreen_barBatteryLevel,0,LV_PART_INDICATOR|LV_STATE_DEFAULT);
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
lv_spinbox_set_range(ui->MainScreen_spinboxSyringeInnerDia,0,50);
lv_spinbox_set_range(ui->MainScreen_spinboxSyringeOuterDia,0,50);
lv_spinbox_set_range(ui->MainScreen_spinboxSyringeBarrelLen,0,200);
lv_spinbox_set_range(ui->MainScreen_spinboxSyringePlungerLen,0,60);
lv_spinbox_set_range(ui->MainScreen_spinboxSyringeDiaTolerance,-10,10);

MainScreen_digital_clock_timer(NULL);
MainScreenSetStyle(ui);
LoadDefaults();


	//Update current screen layout.
	lv_obj_update_layout(ui->MainScreen);

	//Init events for screen.
	events_init_MainScreen(ui);
}
