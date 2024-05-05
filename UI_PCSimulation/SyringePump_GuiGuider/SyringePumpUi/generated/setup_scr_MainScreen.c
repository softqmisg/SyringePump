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



int MainScreen_digital_clock_min_value = 57;
int MainScreen_digital_clock_hour_value = 11;
int MainScreen_digital_clock_sec_value = 3;
char MainScreen_digital_clock_meridiem[] = "AM";
void setup_scr_MainScreen(lv_ui *ui)
{
	//Write codes MainScreen
	ui->MainScreen = lv_obj_create(NULL);
	lv_obj_set_size(ui->MainScreen, 800, 480);
	lv_obj_set_scrollbar_mode(ui->MainScreen, LV_SCROLLBAR_MODE_OFF);

	//Write style for MainScreen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->MainScreen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

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
	lv_obj_set_pos(ui->MainScreen_labelSyringeInfo, 593, 80);
	lv_obj_set_size(ui->MainScreen_labelSyringeInfo, 104, 20);

	//Write style for MainScreen_labelSyringeInfo, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_labelSyringeInfo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_labelSyringeInfo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_labelSyringeInfo, lv_color_hex(0xf00000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_labelSyringeInfo, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
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

	//Write codes MainScreen_contMiddle
	ui->MainScreen_contMiddle = lv_obj_create(ui->MainScreen);
	lv_obj_set_pos(ui->MainScreen_contMiddle, 0, 80);
	lv_obj_set_size(ui->MainScreen_contMiddle, 800, 300);
	lv_obj_set_scrollbar_mode(ui->MainScreen_contMiddle, LV_SCROLLBAR_MODE_OFF);

	//Write style for MainScreen_contMiddle, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_contMiddle, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->MainScreen_contMiddle, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->MainScreen_contMiddle, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->MainScreen_contMiddle, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_contMiddle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_contMiddle, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_contMiddle, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_contMiddle, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_contMiddle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_contMiddle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_contMiddle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_contMiddle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_contMiddle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_barOcclusionLevel
	ui->MainScreen_barOcclusionLevel = lv_bar_create(ui->MainScreen_contMiddle);
	lv_obj_set_style_anim_time(ui->MainScreen_barOcclusionLevel, 1000, 0);
	lv_bar_set_mode(ui->MainScreen_barOcclusionLevel, LV_BAR_MODE_NORMAL);
	lv_bar_set_range(ui->MainScreen_barOcclusionLevel, 0, 11);
	lv_bar_set_value(ui->MainScreen_barOcclusionLevel, 4, LV_ANIM_OFF);
	lv_obj_set_pos(ui->MainScreen_barOcclusionLevel, 754, 6);
	lv_obj_set_size(ui->MainScreen_barOcclusionLevel, 25, 132);

	//Write style for MainScreen_barOcclusionLevel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_radius(ui->MainScreen_barOcclusionLevel, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_barOcclusionLevel, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_barOcclusionLevel, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_barOcclusionLevel, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->MainScreen_barOcclusionLevel, &_ledbar_empty_25x132, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->MainScreen_barOcclusionLevel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_barOcclusionLevel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for MainScreen_barOcclusionLevel, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_radius(ui->MainScreen_barOcclusionLevel, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_barOcclusionLevel, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->MainScreen_barOcclusionLevel, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->MainScreen_barOcclusionLevel, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->MainScreen_barOcclusionLevel, &_ledbar_full_25x132, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->MainScreen_barOcclusionLevel, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_1
	ui->MainScreen_label_1 = lv_label_create(ui->MainScreen_contMiddle);
	lv_label_set_text(ui->MainScreen_label_1, "Mode:\n");
	lv_label_set_long_mode(ui->MainScreen_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_1, 5, 4);
	lv_obj_set_size(ui->MainScreen_label_1, 100, 35);

	//Write style for MainScreen_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_1, lv_color_hex(0xebff00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_1, &lv_font_Alatsi_Regular_30, LV_PART_MAIN|LV_STATE_DEFAULT);
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

	//Write codes MainScreen_label_InjectionMode
	ui->MainScreen_label_InjectionMode = lv_label_create(ui->MainScreen_contMiddle);
	lv_label_set_text(ui->MainScreen_label_InjectionMode, "Volume / Mass / Dosage\n");
	lv_label_set_long_mode(ui->MainScreen_label_InjectionMode, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_InjectionMode, 121, 3);
	lv_obj_set_size(ui->MainScreen_label_InjectionMode, 400, 35);

	//Write style for MainScreen_label_InjectionMode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_InjectionMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_InjectionMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_InjectionMode, lv_color_hex(0xebff00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_InjectionMode, &lv_font_Alatsi_Regular_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_InjectionMode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_InjectionMode, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_InjectionMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_InjectionMode, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_InjectionMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_InjectionMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_InjectionMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_InjectionMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_InjectionMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_InjectionMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_2
	ui->MainScreen_label_2 = lv_label_create(ui->MainScreen_contMiddle);
	lv_label_set_text(ui->MainScreen_label_2, "Rate:\n");
	lv_label_set_long_mode(ui->MainScreen_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_2, 5, 45);
	lv_obj_set_size(ui->MainScreen_label_2, 100, 35);

	//Write style for MainScreen_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_2, lv_color_hex(0xff0027), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_2, &lv_font_Alatsi_Regular_30, LV_PART_MAIN|LV_STATE_DEFAULT);
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

	//Write codes MainScreen_label_InjectionRate
	ui->MainScreen_label_InjectionRate = lv_label_create(ui->MainScreen_contMiddle);
	lv_label_set_text(ui->MainScreen_label_InjectionRate, "100.0 ml/min\n\n");
	lv_label_set_long_mode(ui->MainScreen_label_InjectionRate, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_InjectionRate, 121, 44);
	lv_obj_set_size(ui->MainScreen_label_InjectionRate, 400, 35);

	//Write style for MainScreen_label_InjectionRate, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_InjectionRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_InjectionRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_InjectionRate, lv_color_hex(0xff0027), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_InjectionRate, &lv_font_Alatsi_Regular_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_InjectionRate, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_InjectionRate, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_InjectionRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_InjectionRate, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_InjectionRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_InjectionRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_InjectionRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_InjectionRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_InjectionRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_InjectionRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_Error
	ui->MainScreen_label_Error = lv_label_create(ui->MainScreen_contMiddle);
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

	//Write codes MainScreen_label_InjectedVolume
	ui->MainScreen_label_InjectedVolume = lv_label_create(ui->MainScreen_contMiddle);
	lv_label_set_text(ui->MainScreen_label_InjectedVolume, "100.1 ml");
	lv_label_set_long_mode(ui->MainScreen_label_InjectedVolume, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_InjectedVolume, 0, 94);
	lv_obj_set_size(ui->MainScreen_label_InjectedVolume, 411, 92);

	//Write style for MainScreen_label_InjectedVolume, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_InjectedVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_InjectedVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_InjectedVolume, lv_color_hex(0xff6500), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_InjectedVolume, &lv_font_arial_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_InjectedVolume, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_InjectedVolume, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_InjectedVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_InjectedVolume, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_InjectedVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_InjectedVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_InjectedVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_InjectedVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_InjectedVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_InjectedVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_3
	ui->MainScreen_label_3 = lv_label_create(ui->MainScreen_contMiddle);
	lv_label_set_text(ui->MainScreen_label_3, "Patient Weight:");
	lv_label_set_long_mode(ui->MainScreen_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_3, 18, 195);
	lv_obj_set_size(ui->MainScreen_label_3, 166, 22);

	//Write style for MainScreen_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_3, lv_color_hex(0x2195F6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_3, &lv_font_Alatsi_Regular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
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
	ui->MainScreen_label_4 = lv_label_create(ui->MainScreen_contMiddle);
	lv_label_set_text(ui->MainScreen_label_4, "Total:");
	lv_label_set_long_mode(ui->MainScreen_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_4, 18, 225);
	lv_obj_set_size(ui->MainScreen_label_4, 65, 19);

	//Write style for MainScreen_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_4, lv_color_hex(0x2195F6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_4, &lv_font_Alatsi_Regular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
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
	ui->MainScreen_label_5 = lv_label_create(ui->MainScreen_contMiddle);
	lv_label_set_text(ui->MainScreen_label_5, "Rem:");
	lv_label_set_long_mode(ui->MainScreen_label_5, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_5, 391, 195);
	lv_obj_set_size(ui->MainScreen_label_5, 52, 19);

	//Write style for MainScreen_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_5, lv_color_hex(0x2195F6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_5, &lv_font_Alatsi_Regular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
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
	ui->MainScreen_label_6 = lv_label_create(ui->MainScreen_contMiddle);
	lv_label_set_text(ui->MainScreen_label_6, "Time Left:");
	lv_label_set_long_mode(ui->MainScreen_label_6, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_6, 391, 225);
	lv_obj_set_size(ui->MainScreen_label_6, 110, 19);

	//Write style for MainScreen_label_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_6, lv_color_hex(0x2195F6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_6, &lv_font_Alatsi_Regular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
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

	//Write codes MainScreen_label_TimeLeft
	ui->MainScreen_label_TimeLeft = lv_label_create(ui->MainScreen_contMiddle);
	lv_label_set_text(ui->MainScreen_label_TimeLeft, "00:09:53");
	lv_label_set_long_mode(ui->MainScreen_label_TimeLeft, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_TimeLeft, 510, 225);
	lv_obj_set_size(ui->MainScreen_label_TimeLeft, 110, 19);

	//Write style for MainScreen_label_TimeLeft, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_TimeLeft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_TimeLeft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_TimeLeft, lv_color_hex(0x2195F6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_TimeLeft, &lv_font_arial_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_TimeLeft, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_TimeLeft, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_TimeLeft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_TimeLeft, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_TimeLeft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_TimeLeft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_TimeLeft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_TimeLeft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_TimeLeft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_TimeLeft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_RemVolume
	ui->MainScreen_label_RemVolume = lv_label_create(ui->MainScreen_contMiddle);
	lv_label_set_text(ui->MainScreen_label_RemVolume, "180.0 ml");
	lv_label_set_long_mode(ui->MainScreen_label_RemVolume, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_RemVolume, 449, 195);
	lv_obj_set_size(ui->MainScreen_label_RemVolume, 100, 19);

	//Write style for MainScreen_label_RemVolume, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_RemVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_RemVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_RemVolume, lv_color_hex(0x2195F6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_RemVolume, &lv_font_arial_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_RemVolume, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_RemVolume, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_RemVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_RemVolume, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_RemVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_RemVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_RemVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_RemVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_RemVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_RemVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_PatientKg
	ui->MainScreen_label_PatientKg = lv_label_create(ui->MainScreen_contMiddle);
	lv_label_set_text(ui->MainScreen_label_PatientKg, "120 kg");
	lv_label_set_long_mode(ui->MainScreen_label_PatientKg, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_PatientKg, 190, 195);
	lv_obj_set_size(ui->MainScreen_label_PatientKg, 76, 22);

	//Write style for MainScreen_label_PatientKg, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_PatientKg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_PatientKg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_PatientKg, lv_color_hex(0x2195F6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_PatientKg, &lv_font_arial_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_PatientKg, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_PatientKg, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_PatientKg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_PatientKg, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_PatientKg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_PatientKg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_PatientKg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_PatientKg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_PatientKg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_PatientKg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_label_TotalVolume
	ui->MainScreen_label_TotalVolume = lv_label_create(ui->MainScreen_contMiddle);
	lv_label_set_text(ui->MainScreen_label_TotalVolume, "180.0 ml");
	lv_label_set_long_mode(ui->MainScreen_label_TotalVolume, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->MainScreen_label_TotalVolume, 88, 225);
	lv_obj_set_size(ui->MainScreen_label_TotalVolume, 100, 19);

	//Write style for MainScreen_label_TotalVolume, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->MainScreen_label_TotalVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->MainScreen_label_TotalVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->MainScreen_label_TotalVolume, lv_color_hex(0x2195F6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->MainScreen_label_TotalVolume, &lv_font_arial_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->MainScreen_label_TotalVolume, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->MainScreen_label_TotalVolume, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->MainScreen_label_TotalVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->MainScreen_label_TotalVolume, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->MainScreen_label_TotalVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_label_TotalVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_label_TotalVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_label_TotalVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_label_TotalVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_label_TotalVolume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

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
	lv_obj_set_style_radius(ui->MainScreen_datetext, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->MainScreen_datetext, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->MainScreen_datetext, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->MainScreen_datetext, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_datetext, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->MainScreen_datetext, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

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
	lv_obj_set_style_pad_left(ui->MainScreen_labelAlarmNut, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->MainScreen_labelAlarmNut, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->MainScreen_labelAlarmNut, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

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
	lv_obj_set_pos(ui->MainScreen_imgUsbPort, 493, 6);
	lv_obj_set_size(ui->MainScreen_imgUsbPort, 64, 64);

	//Write style for MainScreen_imgUsbPort, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->MainScreen_imgUsbPort, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MainScreen_barBatteryLevel
	ui->MainScreen_barBatteryLevel = lv_bar_create(ui->MainScreen_contHeader);
	lv_obj_set_style_anim_time(ui->MainScreen_barBatteryLevel, 1000, 0);
	lv_bar_set_mode(ui->MainScreen_barBatteryLevel, LV_BAR_MODE_NORMAL);
	lv_bar_set_range(ui->MainScreen_barBatteryLevel, 0, 4);
	lv_bar_set_value(ui->MainScreen_barBatteryLevel, 1, LV_ANIM_OFF);
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

	//The custom code of MainScreen.
	lv_obj_clear_flag(ui->MainScreen_datetext,LV_OBJ_FLAG_CLICK_FOCUSABLE);
lv_obj_set_style_radius(ui->MainScreen_barBatteryLevel,0,LV_PART_MAIN|LV_STATE_DEFAULT);
lv_obj_set_style_radius(ui->MainScreen_barBatteryLevel,0,LV_PART_INDICATOR|LV_STATE_DEFAULT);
lv_obj_set_style_radius(ui->MainScreen_barOcclusionLevel,0,LV_PART_MAIN|LV_STATE_DEFAULT);
lv_obj_set_style_radius(ui->MainScreen_barOcclusionLevel,0,LV_PART_INDICATOR|LV_STATE_DEFAULT);

MainScreen_digital_clock_timer(NULL);


	//Update current screen layout.
	lv_obj_update_layout(ui->MainScreen);

}
