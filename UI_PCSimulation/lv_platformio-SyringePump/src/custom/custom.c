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
	static lv_state_t styleOutlineFocused;
	lv_style_init(&styleOutlineFocused);
	lv_style_set_outline_color(&styleOutlineFocused,lv_color_hex(0xff0000));
	lv_style_set_outline_width(&styleOutlineFocused,3);
	lv_style_set_outline_pad(&styleOutlineFocused,4);

	lv_obj_add_style(ui->MainScreen_slider_1,&styleOutlineFocused,LV_STATE_FOCUS_KEY );
	lv_obj_add_style(ui->MainScreen_btn_2,&styleOutlineFocused,LV_STATE_FOCUS_KEY );
	lv_obj_add_style(ui->MainScreen_btn_1,&styleOutlineFocused,LV_STATE_FOCUS_KEY );

   lv_group_t *g;
    g= lv_group_create();
    lv_group_set_default(g);    
    lv_indev_t *cur_dev=NULL;
    for(;;)
    {
        cur_dev=lv_indev_get_next(cur_dev);
        if(!cur_dev) break;
        if(lv_indev_get_type(cur_dev)==LV_INDEV_TYPE_ENCODER)
        {
            lv_indev_set_group(cur_dev,g);
            lv_group_remove_all_objs(g);

            lv_group_add_obj(g,ui->MainScreen_slider_1);
            lv_group_add_obj(g,ui->MainScreen_btn_2);
            lv_group_add_obj(g,ui->MainScreen_btn_1);
        }
    }
    // lv_group_focus_obj(ui->MainScreen_btn_2);
}
void SettingScreengroup(lv_ui *ui)
{

	static lv_state_t styleOutlineFocused;
	lv_style_init(&styleOutlineFocused);
	lv_style_set_outline_color(&styleOutlineFocused,lv_color_hex(0xff0000));
	lv_style_set_outline_width(&styleOutlineFocused,3);
	lv_style_set_outline_pad(&styleOutlineFocused,4);
    
	lv_obj_add_style(ui->SettingScreen_btn_2,&styleOutlineFocused,LV_STATE_FOCUS_KEY );
	lv_obj_add_style(ui->SettingScreen_btn_1,&styleOutlineFocused,LV_STATE_FOCUS_KEY );

    lv_group_t *g;
    g= lv_group_create();
    lv_group_set_default(g);
    lv_indev_t *cur_dev=NULL;

    for(;;)
    {
        cur_dev=lv_indev_get_next(cur_dev);
        if(!cur_dev) break;
        if(lv_indev_get_type(cur_dev)==LV_INDEV_TYPE_ENCODER)
        {
            lv_indev_set_group(cur_dev,g);
            lv_group_remove_all_objs(g);

            lv_group_add_obj(g,ui->SettingScreen_btn_2);
            lv_group_add_obj(g,ui->SettingScreen_btn_1);

        }

    }
    // lv_group_focus_obj(ui->SettingScreen_btn_2);

}
