/*
 * Copyright 2023 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
 * accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
 * activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
 * comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
 * terms, then you may not retain, install, activate or otherwise use the software.
 */

/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include "lvgl.h"
#include "custom.h"
#include "Syring.h"
#include "Drug.h"
#include "InfusionMode.h"
/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/
lv_group_t *g_syringevalues, *g_drugvalues, *g_modevalues;
extern uint8_t cur_SyringeManufacture, cur_SyringeType;
extern uint8_t cur_Drug;
extern uint8_t cur_ModeMode, cur_ModeUnit;
char unitMode_volume_intermittent_rhythmic[][9] = {"ml/h",
                                                   "ug/h",
                                                   "mg/h",
                                                   "Unit/h",
                                                   "ml/min",
                                                   "ug/min",
                                                   "mg/min",
                                                   "Unit/min"};

char unitMode_time[][17] = {"ml(Volume)",
                            "ug(Mass /Dosage)",
                            "mg(Mass /Dosage)",
                            "U (Unit)"};
char unitMode_BodyWeight[][12] = {"ml/Kg/h",
                                  "ug/Kg/h",
                                  "mg/Kg/h",
                                  "Unit/Kg/h",
                                  "ml/Kg/min",
                                  "ug/Kg/min",
                                  "mg/Kg/min",
                                  "Unit/Kg/min"};
char unitMode_linear[][17] = {
    "mm/h",
    "mm/min",
};
/**
 * Create a demo application
 */
int randi(int lower_bound, int upper_bound)
{
  return rand() % (upper_bound - lower_bound + 1) + lower_bound;
}
void LoadDefaults(void)
{
  loadDefaultSyringesValue();
  loadDefaultDrugValue();
  loadDefaultInfusionModeValue();
}
void custom_init(lv_ui *ui)
{
  /* Add your codes here */
}
void MainScreenSetStyle(lv_ui *ui)
{
  //  	static lv_style_t style_indic;
  // 	lv_style_init(&style_indic);
  // lv_style_set_bg_img_src(&style_indic,&indicator_ver);
  // lv_obj_add_style(ui->MainScreen_slider_2,&style_indic,LV_PART_INDICATOR);

  static lv_style_t MainScreenStyleFocus;
  lv_style_init(&MainScreenStyleFocus);
  lv_style_set_bg_color(&MainScreenStyleFocus, lv_color_hex(0xc2ff00));
  lv_style_set_outline_color(&MainScreenStyleFocus, lv_color_hex(0xc2ff00)); // lv_palette_lighten(LV_PALETTE_YELLOW, 4));
  lv_style_set_outline_width(&MainScreenStyleFocus, 4);
  lv_style_set_outline_pad(&MainScreenStyleFocus, 2);

  lv_obj_add_style(ui->MainScreen_taSyringeNameValue, &MainScreenStyleFocus, LV_STATE_FOCUS_KEY);
  lv_obj_add_style(ui->MainScreen_spinboxSyringeVolume, &MainScreenStyleFocus, LV_STATE_FOCUS_KEY);
  lv_obj_add_style(ui->MainScreen_spinboxSyringeInnerDia, &MainScreenStyleFocus, LV_STATE_FOCUS_KEY);
  lv_obj_add_style(ui->MainScreen_spinboxSyringeOuterDia, &MainScreenStyleFocus, LV_STATE_FOCUS_KEY);
  lv_obj_add_style(ui->MainScreen_spinboxSyringeBarrelLen, &MainScreenStyleFocus, LV_STATE_FOCUS_KEY);
  lv_obj_add_style(ui->MainScreen_spinboxSyringePlungerLen, &MainScreenStyleFocus, LV_STATE_FOCUS_KEY);
  lv_obj_add_style(ui->MainScreen_spinboxSyringeDiaTolerance, &MainScreenStyleFocus, LV_STATE_FOCUS_KEY);
  lv_obj_add_style(ui->MainScreen_taDrugNameValue, &MainScreenStyleFocus, LV_STATE_FOCUS_KEY);
  lv_obj_add_style(ui->MainScreen_taDrugBrandValue, &MainScreenStyleFocus, LV_STATE_FOCUS_KEY);
  lv_obj_add_style(ui->MainScreen_ddlistDrugId, &MainScreenStyleFocus, LV_STATE_FOCUS_KEY);
  lv_obj_add_style(ui->MainScreen_spinboxDrugmgml, &MainScreenStyleFocus, LV_STATE_FOCUS_KEY);
  lv_obj_add_style(ui->MainScreen_spinboxDruguml, &MainScreenStyleFocus, LV_STATE_FOCUS_KEY);
  lv_obj_add_style(ui->MainScreen_spinboxDrugperkg, &MainScreenStyleFocus, LV_STATE_FOCUS_KEY);
  lv_obj_add_style(ui->MainScreen_spinboxDrugRateMin, &MainScreenStyleFocus, LV_STATE_FOCUS_KEY);
  lv_obj_add_style(ui->MainScreen_spinboxDrugRateMax, &MainScreenStyleFocus, LV_STATE_FOCUS_KEY);
  lv_obj_add_style(ui->MainScreen_spinboxDrugRateDef, &MainScreenStyleFocus, LV_STATE_FOCUS_KEY);
  lv_obj_add_style(ui->MainScreen_spinboxModeTotalVolume, &MainScreenStyleFocus, LV_STATE_FOCUS_KEY);
  lv_obj_add_style(ui->MainScreen_spinboxModeTotalTimeHour, &MainScreenStyleFocus, LV_STATE_FOCUS_KEY);
  lv_obj_add_style(ui->MainScreen_spinboxModeTotalTimeMinute, &MainScreenStyleFocus, LV_STATE_FOCUS_KEY);
  lv_obj_add_style(ui->MainScreen_spinboxModeTotalTimeSecond, &MainScreenStyleFocus, LV_STATE_FOCUS_KEY);
  lv_obj_add_style(ui->MainScreen_spinboxModeInfusionRate, &MainScreenStyleFocus, LV_STATE_FOCUS_KEY);
  lv_obj_add_style(ui->MainScreen_spinboxModeBodyWeight, &MainScreenStyleFocus, LV_STATE_FOCUS_KEY);

  static lv_style_t MainScreenStyleEdit;
  lv_style_init(&MainScreenStyleEdit);
  lv_style_set_bg_color(&MainScreenStyleEdit, lv_color_hex(0xc2ff00));
  lv_style_set_outline_color(&MainScreenStyleEdit, lv_color_hex(0xff0000)); // lv_palette_lighten(LV_PALETTE_YELLOW, 4));
  lv_style_set_outline_width(&MainScreenStyleEdit, 4);
  lv_style_set_outline_pad(&MainScreenStyleEdit, 2);

  lv_obj_add_style(ui->MainScreen_taSyringeNameValue, &MainScreenStyleEdit, LV_STATE_EDITED);
  lv_obj_add_style(ui->MainScreen_spinboxSyringeVolume, &MainScreenStyleEdit, LV_STATE_EDITED);
  lv_obj_add_style(ui->MainScreen_spinboxSyringeInnerDia, &MainScreenStyleEdit, LV_STATE_EDITED);
  lv_obj_add_style(ui->MainScreen_spinboxSyringeOuterDia, &MainScreenStyleEdit, LV_STATE_EDITED);
  lv_obj_add_style(ui->MainScreen_spinboxSyringeBarrelLen, &MainScreenStyleEdit, LV_STATE_EDITED);
  lv_obj_add_style(ui->MainScreen_spinboxSyringePlungerLen, &MainScreenStyleEdit, LV_STATE_EDITED);
  lv_obj_add_style(ui->MainScreen_spinboxSyringeDiaTolerance, &MainScreenStyleEdit, LV_STATE_EDITED);
  lv_obj_add_style(ui->MainScreen_taDrugNameValue, &MainScreenStyleEdit, LV_STATE_EDITED);
  lv_obj_add_style(ui->MainScreen_taDrugBrandValue, &MainScreenStyleEdit, LV_STATE_EDITED);
  lv_obj_add_style(ui->MainScreen_ddlistDrugId, &MainScreenStyleEdit, LV_STATE_EDITED);
  lv_obj_add_style(ui->MainScreen_spinboxDrugmgml, &MainScreenStyleEdit, LV_STATE_EDITED);
  lv_obj_add_style(ui->MainScreen_spinboxDruguml, &MainScreenStyleEdit, LV_STATE_EDITED);
  lv_obj_add_style(ui->MainScreen_spinboxDrugperkg, &MainScreenStyleEdit, LV_STATE_EDITED);
  lv_obj_add_style(ui->MainScreen_spinboxDrugRateMin, &MainScreenStyleEdit, LV_STATE_EDITED);
  lv_obj_add_style(ui->MainScreen_spinboxDrugRateMax, &MainScreenStyleEdit, LV_STATE_EDITED);
  lv_obj_add_style(ui->MainScreen_spinboxDrugRateDef, &MainScreenStyleEdit, LV_STATE_EDITED);
  lv_obj_add_style(ui->MainScreen_spinboxModeTotalVolume, &MainScreenStyleEdit, LV_STATE_EDITED);
  lv_obj_add_style(ui->MainScreen_spinboxModeTotalTimeHour, &MainScreenStyleEdit, LV_STATE_EDITED);
  lv_obj_add_style(ui->MainScreen_spinboxModeTotalTimeMinute, &MainScreenStyleEdit, LV_STATE_EDITED);
  lv_obj_add_style(ui->MainScreen_spinboxModeTotalTimeSecond, &MainScreenStyleEdit, LV_STATE_EDITED);
  lv_obj_add_style(ui->MainScreen_spinboxModeInfusionRate, &MainScreenStyleEdit, LV_STATE_EDITED);
  lv_obj_add_style(ui->MainScreen_spinboxModeBodyWeight, &MainScreenStyleEdit, LV_STATE_EDITED);

  static lv_style_t MainScreenStyleCursor;
  lv_style_init(&MainScreenStyleCursor);
  lv_style_set_text_color(&MainScreenStyleCursor, lv_color_black());
  lv_style_set_bg_color(&MainScreenStyleCursor, lv_color_white());
  lv_style_set_opa(&MainScreenStyleCursor, 255);
  lv_obj_add_style(ui->MainScreen_spinboxSyringeVolume, &MainScreenStyleCursor, LV_PART_CURSOR | LV_STATE_DEFAULT);
  lv_obj_add_style(ui->MainScreen_spinboxSyringeInnerDia, &MainScreenStyleCursor, LV_PART_CURSOR | LV_STATE_DEFAULT);
  lv_obj_add_style(ui->MainScreen_spinboxSyringeOuterDia, &MainScreenStyleCursor, LV_PART_CURSOR | LV_STATE_DEFAULT);
  lv_obj_add_style(ui->MainScreen_spinboxSyringeBarrelLen, &MainScreenStyleCursor, LV_PART_CURSOR | LV_STATE_DEFAULT);
  lv_obj_add_style(ui->MainScreen_spinboxSyringePlungerLen, &MainScreenStyleCursor, LV_PART_CURSOR | LV_STATE_DEFAULT);
  lv_obj_add_style(ui->MainScreen_spinboxSyringeDiaTolerance, &MainScreenStyleCursor, LV_PART_CURSOR | LV_STATE_DEFAULT);
  lv_obj_add_style(ui->MainScreen_spinboxDrugmgml, &MainScreenStyleCursor, LV_PART_CURSOR | LV_STATE_DEFAULT);
  lv_obj_add_style(ui->MainScreen_spinboxDruguml, &MainScreenStyleCursor, LV_PART_CURSOR | LV_STATE_DEFAULT);
  lv_obj_add_style(ui->MainScreen_spinboxDrugperkg, &MainScreenStyleCursor, LV_PART_CURSOR | LV_STATE_DEFAULT);
  lv_obj_add_style(ui->MainScreen_spinboxDrugRateMin, &MainScreenStyleCursor, LV_PART_CURSOR | LV_STATE_DEFAULT);
  lv_obj_add_style(ui->MainScreen_spinboxDrugRateMax, &MainScreenStyleCursor, LV_PART_CURSOR | LV_STATE_DEFAULT);
  lv_obj_add_style(ui->MainScreen_spinboxDrugRateDef, &MainScreenStyleCursor, LV_PART_CURSOR | LV_STATE_DEFAULT);
  lv_obj_add_style(ui->MainScreen_spinboxModeTotalVolume, &MainScreenStyleCursor, LV_PART_CURSOR | LV_STATE_DEFAULT);
  lv_obj_add_style(ui->MainScreen_spinboxModeTotalTimeHour, &MainScreenStyleCursor, LV_PART_CURSOR | LV_STATE_DEFAULT);
  lv_obj_add_style(ui->MainScreen_spinboxModeTotalTimeMinute, &MainScreenStyleCursor, LV_PART_CURSOR | LV_STATE_DEFAULT);
  lv_obj_add_style(ui->MainScreen_spinboxModeTotalTimeSecond, &MainScreenStyleCursor, LV_PART_CURSOR | LV_STATE_DEFAULT);
  lv_obj_add_style(ui->MainScreen_spinboxModeInfusionRate, &MainScreenStyleCursor, LV_PART_CURSOR | LV_STATE_DEFAULT);
  lv_obj_add_style(ui->MainScreen_spinboxModeBodyWeight, &MainScreenStyleCursor, LV_PART_CURSOR | LV_STATE_DEFAULT);

  static lv_style_t MainScreenStyleCursorFocus;
  lv_style_init(&MainScreenStyleCursorFocus);
  lv_style_set_text_color(&MainScreenStyleCursor, lv_color_white());
  lv_style_set_bg_color(&MainScreenStyleCursorFocus, lv_color_hex(0x2195f6));
  //    lv_style_set_opa(&MainScreenStyleCursor,255);
  lv_obj_add_style(ui->MainScreen_spinboxSyringeVolume, &MainScreenStyleCursorFocus, LV_PART_CURSOR | LV_STATE_FOCUS_KEY | LV_STATE_FOCUSED);
  lv_obj_add_style(ui->MainScreen_spinboxSyringeInnerDia, &MainScreenStyleCursorFocus, LV_PART_CURSOR | LV_STATE_FOCUS_KEY);
  lv_obj_add_style(ui->MainScreen_spinboxSyringeOuterDia, &MainScreenStyleCursorFocus, LV_PART_CURSOR | LV_STATE_FOCUS_KEY);
  lv_obj_add_style(ui->MainScreen_spinboxSyringeBarrelLen, &MainScreenStyleCursorFocus, LV_PART_CURSOR | LV_STATE_FOCUS_KEY);
  lv_obj_add_style(ui->MainScreen_spinboxSyringePlungerLen, &MainScreenStyleCursorFocus, LV_PART_CURSOR | LV_STATE_FOCUS_KEY);
  lv_obj_add_style(ui->MainScreen_spinboxSyringeDiaTolerance, &MainScreenStyleCursorFocus, LV_PART_CURSOR | LV_STATE_FOCUS_KEY);
  lv_obj_add_style(ui->MainScreen_spinboxDrugmgml, &MainScreenStyleCursorFocus, LV_PART_CURSOR | LV_STATE_FOCUS_KEY);
  lv_obj_add_style(ui->MainScreen_spinboxDruguml, &MainScreenStyleCursorFocus, LV_PART_CURSOR | LV_STATE_FOCUS_KEY);
  lv_obj_add_style(ui->MainScreen_spinboxDrugperkg, &MainScreenStyleCursorFocus, LV_PART_CURSOR | LV_STATE_FOCUS_KEY);
  lv_obj_add_style(ui->MainScreen_spinboxDrugRateMin, &MainScreenStyleCursorFocus, LV_PART_CURSOR | LV_STATE_FOCUS_KEY);
  lv_obj_add_style(ui->MainScreen_spinboxDrugRateMax, &MainScreenStyleCursorFocus, LV_PART_CURSOR | LV_STATE_FOCUS_KEY);
  lv_obj_add_style(ui->MainScreen_spinboxDrugRateDef, &MainScreenStyleCursorFocus, LV_PART_CURSOR | LV_STATE_FOCUS_KEY);
  lv_obj_add_style(ui->MainScreen_spinboxModeTotalVolume, &MainScreenStyleCursorFocus, LV_PART_CURSOR | LV_STATE_FOCUS_KEY);
  lv_obj_add_style(ui->MainScreen_spinboxModeTotalTimeHour, &MainScreenStyleCursorFocus, LV_PART_CURSOR | LV_STATE_FOCUS_KEY);
  lv_obj_add_style(ui->MainScreen_spinboxModeTotalTimeMinute, &MainScreenStyleCursorFocus, LV_PART_CURSOR | LV_STATE_FOCUS_KEY);
  lv_obj_add_style(ui->MainScreen_spinboxModeTotalTimeSecond, &MainScreenStyleCursorFocus, LV_PART_CURSOR | LV_STATE_FOCUS_KEY);
  lv_obj_add_style(ui->MainScreen_spinboxModeInfusionRate, &MainScreenStyleCursorFocus, LV_PART_CURSOR | LV_STATE_FOCUS_KEY);
  lv_obj_add_style(ui->MainScreen_spinboxModeBodyWeight, &MainScreenStyleCursorFocus, LV_PART_CURSOR | LV_STATE_FOCUS_KEY);
}

void setcontMenuGroup(lv_ui *ui)
{
  lv_group_t *g;
  g = lv_group_get_default();
  if (g != NULL)
  {
    lv_group_del(g);
  }
  g = lv_group_create();
  lv_group_set_default(g);
  lv_indev_t *cur_dev = NULL;
  for (;;)
  {
    cur_dev = lv_indev_get_next(cur_dev);
    if (!cur_dev)
      break;
    if (lv_indev_get_type(cur_dev) == LV_INDEV_TYPE_ENCODER)
    {
      lv_indev_set_group(cur_dev, g);

      lv_obj_t *obj_child;
      bool has_stat = false;
      for (int i = 0; i < lv_obj_get_child_cnt(ui->MainScreen_contMenuButtons); i++)
      {
        obj_child = lv_obj_get_child(ui->MainScreen_contMenuButtons, i);
        if(lv_obj_check_type(obj_child,&lv_btn_class))
        {
             lv_group_add_obj(g, obj_child);
            //  printf("state:%d\n\r",lv_obj_get_state(obj_child));
            if (lv_obj_has_state(obj_child, LV_STATE_FOCUS_KEY))
            {
              has_stat = true;
              lv_group_focus_obj(obj_child);
            }
        }
      }
        if (!has_stat)
          lv_obj_add_state(lv_obj_get_child(ui->MainScreen_contMenuButtons, 0), LV_STATE_FOCUS_KEY);
    }
  }
}
void setcontMainGroup(lv_ui *ui)
{
  lv_group_t *g;
  g = lv_group_get_default();
  if (g != NULL)
  {
    lv_group_del(g);
  }
}
void setlistSyringeCompanyGroup(lv_ui *ui)
{
  lv_group_t *g;
  g = lv_group_get_default();
  if (g != NULL)
  {
    lv_group_del(g);
  }
  g = lv_group_create();
  lv_group_set_default(g);
  lv_indev_t *cur_dev = NULL;
  for (;;)
  {
    cur_dev = lv_indev_get_next(cur_dev);
    if (!cur_dev)
      break;
    if (lv_indev_get_type(cur_dev) == LV_INDEV_TYPE_ENCODER)
    {
      lv_indev_set_group(cur_dev, g);
      lv_obj_t *obj_child;
      bool has_stat = false;
      for (int i = 0; i < lv_obj_get_child_cnt(ui->MainScreen_listSyringeCompany); i++)
      {
        obj_child = lv_obj_get_child(ui->MainScreen_listSyringeCompany, i);
        lv_group_add_obj(g, obj_child);
        if (lv_obj_has_state(obj_child, LV_STATE_FOCUS_KEY))
        {
          has_stat = true;
          lv_group_focus_obj(obj_child);
        }
      }
      if (!has_stat)
        lv_obj_add_state(lv_obj_get_child(ui->MainScreen_listSyringeCompany, 0), LV_STATE_FOCUS_KEY);
    }
  }
}
void setlistSyringeTypeGroup(lv_ui *ui)
{
  lv_group_t *g;
  g = lv_group_get_default();
  if (g != NULL)
  {
    lv_group_del(g);
  }
  g = lv_group_create();
  lv_group_set_default(g);
  lv_indev_t *cur_dev = NULL;
  for (;;)
  {
    cur_dev = lv_indev_get_next(cur_dev);
    if (!cur_dev)
      break;
    if (lv_indev_get_type(cur_dev) == LV_INDEV_TYPE_ENCODER)
    {
      lv_indev_set_group(cur_dev, g);
      lv_obj_t *obj_child;
      // bool has_stat=false;
      for (int i = 0; i < lv_obj_get_child_cnt(ui->MainScreen_listSyringeType); i++)
      {
        obj_child = lv_obj_get_child(ui->MainScreen_listSyringeType, i);
        lv_group_add_obj(g, obj_child);
        if (lv_obj_has_state(obj_child, LV_STATE_FOCUS_KEY))
        {
          // has_stat=true;
          lv_group_focus_obj(obj_child);
        }
      }
      // if(!has_stat)
      //   lv_obj_add_state(lv_obj_get_child(ui->MainScreen_listSyringeType,0),LV_STATE_FOCUS_KEY);
    }
  }
}
void setcontSyringeValuesGroup(lv_ui *ui)
{
  lv_group_t *g;
  g = lv_group_get_default();
  if (g != NULL)
  {
    lv_group_del(g);
  }
  g_syringevalues = lv_group_create();
  lv_group_set_default(g_syringevalues);
  lv_group_set_wrap(g_syringevalues, false);
  lv_indev_t *cur_dev = NULL;
  for (;;)
  {
    cur_dev = lv_indev_get_next(cur_dev);
    if (!cur_dev)
      break;
    if (lv_indev_get_type(cur_dev) == LV_INDEV_TYPE_ENCODER)
    {
      lv_indev_set_group(cur_dev, g_syringevalues);
      lv_group_add_obj(g_syringevalues, ui->MainScreen_taSyringeNameValue);
      lv_group_add_obj(g_syringevalues, ui->MainScreen_spinboxSyringeVolume);
      lv_group_add_obj(g_syringevalues, ui->MainScreen_spinboxSyringeInnerDia);
      lv_group_add_obj(g_syringevalues, ui->MainScreen_spinboxSyringeOuterDia);
      lv_group_add_obj(g_syringevalues, ui->MainScreen_spinboxSyringeBarrelLen);
      lv_group_add_obj(g_syringevalues, ui->MainScreen_spinboxSyringePlungerLen);
      lv_group_add_obj(g_syringevalues, ui->MainScreen_spinboxSyringeDiaTolerance);
      lv_group_add_obj(g_syringevalues, ui->g_kb_MainScreen);
      // lv_obj_add_state(ui->MainScreen_taSyringeNameValue,LV_STATE_FOCUS_KEY);
    }
  }
}
void setlistDrugBrandGroup(lv_ui *ui)
{
  lv_group_t *g;
  g = lv_group_get_default();
  if (g != NULL)
  {
    lv_group_del(g);
  }
  g = lv_group_create();
  lv_group_set_default(g);
  lv_indev_t *cur_dev = NULL;
  for (;;)
  {
    cur_dev = lv_indev_get_next(cur_dev);
    if (!cur_dev)
      break;
    if (lv_indev_get_type(cur_dev) == LV_INDEV_TYPE_ENCODER)
    {
      lv_indev_set_group(cur_dev, g);
      lv_obj_t *obj_child;
      bool has_stat = false;
      for (int i = 0; i < lv_obj_get_child_cnt(ui->MainScreen_listDrugBrand); i++)
      {
        obj_child = lv_obj_get_child(ui->MainScreen_listDrugBrand, i);
        lv_group_add_obj(g, obj_child);
        if (lv_obj_has_state(obj_child, LV_STATE_FOCUS_KEY))
        {
          has_stat = true;
          lv_group_focus_obj(obj_child);
        }
      }
      if (!has_stat)
        lv_obj_add_state(lv_obj_get_child(ui->MainScreen_listDrugBrand, 0), LV_STATE_FOCUS_KEY);
    }
  }
}
void setcontDrugValuesGroup(lv_ui *ui)
{
  lv_group_t *g;
  g = lv_group_get_default();
  if (g != NULL)
  {
    lv_group_del(g);
  }
  g_drugvalues = lv_group_create();
  lv_group_set_default(g_drugvalues);
  lv_group_set_wrap(g_drugvalues, false);
  lv_indev_t *cur_dev = NULL;
  for (;;)
  {
    cur_dev = lv_indev_get_next(cur_dev);
    if (!cur_dev)
      break;
    if (lv_indev_get_type(cur_dev) == LV_INDEV_TYPE_ENCODER)
    {
      lv_indev_set_group(cur_dev, g_drugvalues);
      lv_group_add_obj(g_drugvalues, ui->MainScreen_taDrugNameValue);
      lv_group_add_obj(g_drugvalues, ui->MainScreen_taDrugBrandValue);
      lv_group_add_obj(g_drugvalues, ui->MainScreen_ddlistDrugId);
      lv_group_add_obj(g_drugvalues, ui->MainScreen_spinboxDrugmgml);
      lv_group_add_obj(g_drugvalues, ui->MainScreen_spinboxDruguml);
      lv_group_add_obj(g_drugvalues, ui->MainScreen_spinboxDrugperkg);
      lv_group_add_obj(g_drugvalues, ui->MainScreen_spinboxDrugRateMin);
      lv_group_add_obj(g_drugvalues, ui->MainScreen_spinboxDrugRateMax);
      lv_group_add_obj(g_drugvalues, ui->MainScreen_spinboxDrugRateDef);
      lv_group_add_obj(g_drugvalues, ui->g_kb_MainScreen);
      // lv_obj_add_state(ui->MainScreen_taSyringeNameValue,LV_STATE_FOCUS_KEY);
    }
  }
}
void setlistModeModeGroup(lv_ui *ui)
{
  lv_group_t *g;
  g = lv_group_get_default();
  if (g != NULL)
  {
    lv_group_del(g);
  }
  g = lv_group_create();
  lv_group_set_default(g);
  lv_indev_t *cur_dev = NULL;
  for (;;)
  {
    cur_dev = lv_indev_get_next(cur_dev);
    if (!cur_dev)
      break;
    if (lv_indev_get_type(cur_dev) == LV_INDEV_TYPE_ENCODER)
    {
      lv_indev_set_group(cur_dev, g);
      lv_obj_t *obj_child;
      bool has_stat = false;
      for (int i = 0; i < lv_obj_get_child_cnt(ui->MainScreen_listModeMode); i++)
      {
        obj_child = lv_obj_get_child(ui->MainScreen_listModeMode, i);
        lv_group_add_obj(g, obj_child);
        if (lv_obj_has_state(obj_child, LV_STATE_FOCUS_KEY))
        {
          has_stat = true;
          lv_group_focus_obj(obj_child);
        }
      }
      if (!has_stat)
        lv_obj_add_state(lv_obj_get_child(ui->MainScreen_listModeMode, 0), LV_STATE_FOCUS_KEY);
    }
  }
}
void setlistModeUnitGroup(lv_ui *ui)
{
  lv_group_t *g;
  g = lv_group_get_default();
  if (g != NULL)
  {
    lv_group_del(g);
  }
  g = lv_group_create();
  lv_group_set_default(g);
  lv_indev_t *cur_dev = NULL;
  for (;;)
  {
    cur_dev = lv_indev_get_next(cur_dev);
    if (!cur_dev)
      break;
    if (lv_indev_get_type(cur_dev) == LV_INDEV_TYPE_ENCODER)
    {
      lv_indev_set_group(cur_dev, g);
      lv_obj_t *obj_child;
      // bool has_stat=false;
      for (int i = 0; i < lv_obj_get_child_cnt(ui->MainScreen_listModeUnit); i++)
      {
        obj_child = lv_obj_get_child(ui->MainScreen_listModeUnit, i);
        lv_group_add_obj(g, obj_child);
        if (lv_obj_has_state(obj_child, LV_STATE_FOCUS_KEY))
        {
          // has_stat=true;
          lv_group_focus_obj(obj_child);
        }
      }
      // if(!has_stat)
      //   lv_obj_add_state(lv_obj_get_child(ui->MainScreen_listSyringeType,0),LV_STATE_FOCUS_KEY);
    }
  }
}
void setcontModeValuesGroup(lv_ui *ui)
{
  lv_group_t *g;
  g = lv_group_get_default();
  if (g != NULL)
  {
    lv_group_del(g);
  }
  g_modevalues = lv_group_create();
  lv_group_set_default(g_modevalues);
  lv_group_set_wrap(g_modevalues, false);
  lv_indev_t *cur_dev = NULL;
  for (;;)
  {
    cur_dev = lv_indev_get_next(cur_dev);
    if (!cur_dev)
      break;
    if (lv_indev_get_type(cur_dev) == LV_INDEV_TYPE_ENCODER)
    {
      lv_indev_set_group(cur_dev, g_modevalues);

      switch (cur_ModeMode)
      {
      case 0: // Volume
        lv_group_add_obj(g_modevalues, ui->MainScreen_spinboxModeTotalVolume);
        lv_group_add_obj(g_modevalues, ui->MainScreen_spinboxModeInfusionRate);
        break;
      case 1: // Time
        lv_group_add_obj(g_modevalues, ui->MainScreen_spinboxModeTotalVolume);
        lv_group_add_obj(g_modevalues, ui->MainScreen_spinboxModeTotalTimeHour);
        lv_group_add_obj(g_modevalues, ui->MainScreen_spinboxModeTotalTimeMinute);
        lv_group_add_obj(g_modevalues, ui->MainScreen_spinboxModeTotalTimeSecond);
        break;
      case 2: // Weight
        lv_group_add_obj(g_modevalues, ui->MainScreen_spinboxModeTotalVolume);        
        lv_group_add_obj(g_modevalues, ui->MainScreen_spinboxModeInfusionRate);
        lv_group_add_obj(g_modevalues, ui->MainScreen_spinboxModeBodyWeight);
        break;
      case 3: // Intermittent
        lv_group_add_obj(g_modevalues, ui->MainScreen_spinboxModeTotalVolume);
        break;
      case 4: // Rhythmic
        lv_group_add_obj(g_modevalues, ui->MainScreen_spinboxModeTotalVolume);
        break;
      case 5: // linear
        lv_group_add_obj(g_modevalues, ui->MainScreen_spinboxModeTotalVolume);
        lv_group_add_obj(g_modevalues, ui->MainScreen_spinboxModeInfusionRate);
        break;
      }
    }
  }
}
//=======================================//=======================================//=======================================
//=======================================//=======================================//=======================================
void updateSyringeCompanyList(lv_ui *ui)
{
  // load syringe manufacture
  printf("load company list\n\r");
  for (int i = 0; i < lv_obj_get_child_cnt(ui->MainScreen_listSyringeCompany); i++)
  {
    lv_obj_t *btn = lv_obj_get_child(ui->MainScreen_listSyringeCompany, i);
    lv_label_set_text(lv_obj_get_child(btn, lv_obj_get_child_cnt(btn) - 1), DefaultSyrings[i][0].Manufacture);
    if (lv_obj_get_child_cnt(btn) > 1)
      lv_obj_del(lv_obj_get_child(btn, 0));
  }
}
void updateSyringeTypeList(lv_ui *ui, uint8_t companyindex)
{
  printf("select syring company index:%d\n\r", companyindex);
  for (int i = 0; i < lv_obj_get_child_cnt(ui->MainScreen_listSyringeType); i++)
  {
    lv_obj_t *btn = lv_obj_get_child(ui->MainScreen_listSyringeType, i);
    lv_label_set_text(lv_obj_get_child(btn, lv_obj_get_child_cnt(btn) - 1), DefaultSyrings[companyindex][i].Name);
    if (lv_obj_get_child_cnt(btn) > 1)
      lv_obj_del(lv_obj_get_child(btn, 0));
  }
}
void updateSyringeValues(lv_ui *ui, uint8_t Manufactureindex, uint8_t Typeindex)
{
  printf("select syring Type Index:%d,%d\n\r", Manufactureindex, Typeindex);
  lv_textarea_set_text(ui->MainScreen_taSyringeNameValue, DefaultSyrings[Manufactureindex][Typeindex].Name);
  lv_spinbox_set_value(ui->MainScreen_spinboxSyringeVolume, DefaultSyrings[Manufactureindex][Typeindex].Volume);
  lv_spinbox_set_value(ui->MainScreen_spinboxSyringeInnerDia, DefaultSyrings[Manufactureindex][Typeindex].InnerDia10 / 10.0);
  lv_spinbox_set_value(ui->MainScreen_spinboxSyringeOuterDia, DefaultSyrings[Manufactureindex][Typeindex].OuterDia10 / 10.0);
  lv_spinbox_set_value(ui->MainScreen_spinboxSyringeBarrelLen, DefaultSyrings[Manufactureindex][Typeindex].BarrelLen10 / 10.0);
  lv_spinbox_set_value(ui->MainScreen_spinboxSyringePlungerLen, DefaultSyrings[Manufactureindex][Typeindex].PlungerLen10 / 10.0);
  lv_spinbox_set_value(ui->MainScreen_spinboxSyringeDiaTolerance, DefaultSyrings[Manufactureindex][Typeindex].DiaTolerance10 / 10.0);
}
void updateDrugList(lv_ui *ui)
{
  // load syringe manufacture
  printf("load Drug list\n\r");
  for (int i = 0; i < lv_obj_get_child_cnt(ui->MainScreen_listDrugBrand); i++)
  {
    lv_obj_t *btn = lv_obj_get_child(ui->MainScreen_listDrugBrand, i);
    lv_label_set_text_fmt(lv_obj_get_child(btn, lv_obj_get_child_cnt(btn) - 1), "%s(%s)", DefaultDrugs[i].Name, DefaultDrugs[i].Brand);
    if (lv_obj_get_child_cnt(btn) > 1)
      lv_obj_del(lv_obj_get_child(btn, 0));
  }
}
void updateDrugValues(lv_ui *ui, uint8_t drugindex)
{
  printf("select Drug Type Index:%d\n\r", drugindex);
  lv_textarea_set_text(ui->MainScreen_taDrugNameValue, DefaultDrugs[drugindex].Name);
  lv_textarea_set_text(ui->MainScreen_taDrugBrandValue, DefaultDrugs[drugindex].Brand);
  lv_dropdown_set_selected(ui->MainScreen_ddlistDrugId, DefaultDrugs[drugindex].Id);
  lv_spinbox_set_value(ui->MainScreen_spinboxDrugmgml, DefaultDrugs[drugindex].mg_ml_1000 / 1000.0);
  lv_spinbox_set_value(ui->MainScreen_spinboxDruguml, DefaultDrugs[drugindex].u_ml_1000 / 1000.0);
  lv_spinbox_set_value(ui->MainScreen_spinboxDrugperkg, DefaultDrugs[drugindex].per_kg_1000 / 1000.0);
  lv_spinbox_set_value(ui->MainScreen_spinboxDrugRateMin, DefaultDrugs[drugindex].RateMin10 / 10.0);
  lv_spinbox_set_value(ui->MainScreen_spinboxDrugRateMax, DefaultDrugs[drugindex].RateMax10 / 10.0);
  lv_spinbox_set_value(ui->MainScreen_spinboxDrugRateDef, DefaultDrugs[drugindex].RateDef10 / 10.0);
}
void updateModeModeList(lv_ui *ui)
{
  for (int i = 0; i < lv_obj_get_child_cnt(ui->MainScreen_listModeMode); i++)
  {
    lv_obj_t *btn = lv_obj_get_child(ui->MainScreen_listModeMode, i);
    if (lv_obj_get_child_cnt(btn) > 1)
      lv_obj_del(lv_obj_get_child(btn, 0));
  }
}
void updateModeUnitList(lv_ui *ui, uint8_t modeindex)
{
  for (uint8_t i = 0; i < lv_obj_get_child_cnt(ui->MainScreen_listModeUnit); i++)
  {
    lv_obj_t *btn = lv_obj_get_child(ui->MainScreen_listModeUnit, i);
    if (lv_obj_get_child_cnt(btn) > 1)
      lv_obj_del(lv_obj_get_child(btn, 0));

    switch (modeindex)
    {
    case 0:
    case 3:
    case 4:
      lv_label_set_text_fmt(lv_obj_get_child(btn, 0), "%s", unitMode_volume_intermittent_rhythmic[i]);
      lv_obj_clear_flag(btn, LV_OBJ_FLAG_HIDDEN);
      break;
    case 1:
      if (i < 4)
      {
        lv_label_set_text_fmt(lv_obj_get_child(btn, 0), "%s", unitMode_time[i]);
        lv_obj_clear_flag(btn, LV_OBJ_FLAG_HIDDEN);
      }
      else
      {
        lv_obj_add_flag(btn, LV_OBJ_FLAG_HIDDEN);
      }
      break;
    case 2:
      lv_label_set_text_fmt(lv_obj_get_child(btn, 0), "%s", unitMode_BodyWeight[i]);
      lv_obj_clear_flag(btn, LV_OBJ_FLAG_HIDDEN);
      break;
    case 5:
      if (i < 2)
      {
        lv_label_set_text_fmt(lv_obj_get_child(btn, 0), "%s", unitMode_linear[i]);
        lv_obj_clear_flag(btn, LV_OBJ_FLAG_HIDDEN);
      }
      else
      {
        lv_obj_add_flag(btn, LV_OBJ_FLAG_HIDDEN);
      }
      break;
    }
  }
}
void updateModeValues(lv_ui *ui, uint8_t modeindex, uint8_t unitindex)
{
  char unit_volume[][5] = {"ml", "ug", "mg", "Unit"};
  switch (modeindex)
  {
  case 0: // Volume
    lv_obj_clear_flag(ui->MainScreen_contModeValueTotalVolume, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui->MainScreen_contModeValueInfusionRate, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->MainScreen_contModeValueTotalTime, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->MainScreen_contModeValueWeight, LV_OBJ_FLAG_HIDDEN);

    lv_spinbox_set_value(ui->MainScreen_spinboxModeTotalVolume, DefaultModes[modeindex][unitindex].TotalVolume10 / 10.0);
    lv_label_set_text_fmt(ui->MainScreen_labelModeVolumeUnit, "%s", unit_volume[unitindex % 4]);
    lv_spinbox_set_value(ui->MainScreen_spinboxModeInfusionRate, DefaultModes[modeindex][unitindex].InfusionRate10 / 10.0);
    lv_label_set_text_fmt(ui->MainScreen_labelModeInfusionRateUnit, "%s", unitMode_volume_intermittent_rhythmic[unitindex]);

    break;
  case 1: // Time
    lv_obj_clear_flag(ui->MainScreen_contModeValueTotalVolume, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->MainScreen_contModeValueInfusionRate, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui->MainScreen_contModeValueTotalTime, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->MainScreen_contModeValueWeight, LV_OBJ_FLAG_HIDDEN);
    lv_spinbox_set_value(ui->MainScreen_spinboxModeTotalVolume, DefaultModes[modeindex][unitindex].TotalVolume10 / 10.0);
    lv_label_set_text_fmt(ui->MainScreen_labelModeVolumeUnit, "%s", unit_volume[unitindex % 4]);
    // add code fo time update
    time_t time = DefaultModes[modeindex][unitindex].TotalTime;
    int hour = time / 3600;
    int minute = (time % 3600) / 60;
    int second = (time % 3600) % 60;
    lv_spinbox_set_value(ui->MainScreen_spinboxModeTotalTimeHour, hour);
    lv_spinbox_set_value(ui->MainScreen_spinboxModeTotalTimeMinute, minute);
    lv_spinbox_set_value(ui->MainScreen_spinboxModeTotalTimeSecond, second);

    break;
  case 2: // Weight
    lv_obj_clear_flag(ui->MainScreen_contModeValueTotalVolume, LV_OBJ_FLAG_HIDDEN);
    lv_label_set_text_fmt(ui->MainScreen_labelModeInfusionRateUnit, "%s", unitMode_BodyWeight[unitindex]);
    lv_obj_clear_flag(ui->MainScreen_contModeValueInfusionRate, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->MainScreen_contModeValueTotalTime, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui->MainScreen_contModeValueWeight, LV_OBJ_FLAG_HIDDEN);

    lv_spinbox_set_value(ui->MainScreen_spinboxModeTotalVolume, DefaultModes[modeindex][unitindex].TotalVolume10 / 10.0);
    lv_label_set_text_fmt(ui->MainScreen_labelModeVolumeUnit, "%s", unit_volume[unitindex % 4]);

    lv_spinbox_set_value(ui->MainScreen_spinboxModeInfusionRate, DefaultModes[modeindex][unitindex].InfusionRate10 / 10.0);
    lv_label_set_text_fmt(ui->MainScreen_labelModeInfusionRateUnit, "%s", unitMode_volume_intermittent_rhythmic[unitindex]);

    lv_spinbox_set_value(ui->MainScreen_spinboxModeBodyWeight, DefaultModes[modeindex][unitindex].BodyWeight);

    break;
  case 3: // Intermittent
    lv_obj_clear_flag(ui->MainScreen_contModeValueTotalVolume, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->MainScreen_contModeValueInfusionRate, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->MainScreen_contModeValueTotalTime, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->MainScreen_contModeValueWeight, LV_OBJ_FLAG_HIDDEN);

    lv_spinbox_set_value(ui->MainScreen_spinboxModeTotalVolume, DefaultModes[modeindex][unitindex].TotalVolume10 / 10.0);
    lv_label_set_text_fmt(ui->MainScreen_labelModeVolumeUnit, "%s", unit_volume[unitindex % 4]);

    break;
  case 4: // Rhythmic
    lv_obj_clear_flag(ui->MainScreen_contModeValueTotalVolume, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->MainScreen_contModeValueInfusionRate, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->MainScreen_contModeValueTotalTime, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->MainScreen_contModeValueWeight, LV_OBJ_FLAG_HIDDEN);
    lv_spinbox_set_value(ui->MainScreen_spinboxModeTotalVolume, DefaultModes[modeindex][unitindex].TotalVolume10 / 10.0);
    lv_label_set_text_fmt(ui->MainScreen_labelModeVolumeUnit, "%s", unit_volume[unitindex % 4]);

    break;
  case 5: // Linear
    lv_obj_clear_flag(ui->MainScreen_contModeValueTotalVolume, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui->MainScreen_contModeValueInfusionRate, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->MainScreen_contModeValueTotalTime, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->MainScreen_contModeValueWeight, LV_OBJ_FLAG_HIDDEN);
    
    lv_spinbox_set_value(ui->MainScreen_spinboxModeTotalVolume, DefaultModes[modeindex][unitindex].TotalVolume10 / 10.0);    
    lv_label_set_text_fmt(ui->MainScreen_labelModeVolumeUnit, "mm");
    lv_spinbox_set_value(ui->MainScreen_spinboxModeInfusionRate, DefaultModes[modeindex][unitindex].InfusionRate10 / 10.0);
    lv_label_set_text_fmt(ui->MainScreen_labelModeInfusionRateUnit, "%s", unitMode_linear[unitindex]);

    break;
  }
}
//=======================================//=======================================//=======================================
//=======================================//=======================================//=======================================
void animcontMain_ready_callback(lv_anim_t *a)
{
  setcontMainGroup(&guider_ui);
}
void animcontMenu_ready_callback(lv_anim_t *a)
{
  setcontMenuGroup(&guider_ui);
}
void animcontSyringe_ready_callback(lv_anim_t *a)
{
  setlistSyringeCompanyGroup(&guider_ui);
}
void animcontDrug_ready_callback(lv_anim_t *a)
{
  setlistDrugBrandGroup(&guider_ui);
}
void animcontMode_ready_callback(lv_anim_t *a)
{
  setlistModeModeGroup(&guider_ui);
}
// void animcontMode_del_callback(lv_anim_t *a)
// {
//   lv_obj_add_state(guider_ui.MainScreen_btnMenuMode,LV_STATE_FOCUS_KEY);
// }
