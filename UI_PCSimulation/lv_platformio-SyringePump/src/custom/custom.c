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

/**
 * Create a demo application
 */

void custom_init(lv_ui *ui)
{
    /* Add your codes here */
}
void MainScreengroup(lv_ui *ui)
{
    lv_group_t *g= lv_group_create();
    lv_indev_t *cur_dev=NULL;
    for(;;)
    {
        cur_dev=lv_indev_get_next(cur_dev);
        if(!cur_dev) break;
        if(lv_indev_get_type(cur_dev)==LV_INDEV_TYPE_ENCODER)
        {
            lv_group_remove_all_objs(g);
            lv_indev_set_group(cur_dev,g);
            lv_group_add_obj(g,ui->MainScreen_btn_1);
            lv_group_add_obj(g,ui->MainScreen_btn_2);
        }
    }
}
void SettingScreengroup(lv_ui *ui)
{
    lv_group_t *g= lv_group_create();
    lv_indev_t *cur_dev=NULL;
    for(;;)
    {
        cur_dev=lv_indev_get_next(cur_dev);
        if(!cur_dev) break;
        if(lv_indev_get_type(cur_dev)==LV_INDEV_TYPE_ENCODER)
        {
            lv_group_remove_all_objs(g);
            lv_indev_set_group(cur_dev,g);
            lv_group_add_obj(g,ui->SettingScreen_btn_1);
            lv_group_add_obj(g,ui->SettingScreen_slider_1);
            lv_group_add_obj(g,ui->SettingScreen_spinbox_1_btn);
            lv_group_add_obj(g,ui->SettingScreen_spinbox_1_btn_minus);
        }
    }
}
