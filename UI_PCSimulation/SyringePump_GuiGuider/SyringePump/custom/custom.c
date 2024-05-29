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
void SettingScreenSetStyle(lv_ui *ui)
{

}
void MainScreenSetStyle(lv_ui *ui)
{
  
}
void MainScreengroup(lv_ui *ui)
{
	static lv_style_t MainScreenStyleFocus;
	lv_style_init(&MainScreenStyleFocus);
	lv_style_set_outline_color(&MainScreenStyleFocus,lv_palette_lighten(LV_PALETTE_RED, 2));
	lv_style_set_outline_width(&MainScreenStyleFocus,3);
	lv_style_set_outline_pad(&MainScreenStyleFocus,4);
	lv_obj_add_style(ui->MainScreen_btn_2,&MainScreenStyleFocus,LV_STATE_FOCUS_KEY );
	lv_obj_add_style(ui->MainScreen_ta_1,&MainScreenStyleFocus,LV_STATE_FOCUS_KEY );
	lv_obj_add_style(ui->MainScreen_slider_1,&MainScreenStyleFocus,LV_STATE_FOCUS_KEY );
	lv_obj_add_style(ui->MainScreen_spinbox_1,&MainScreenStyleFocus,LV_STATE_FOCUS_KEY );
	lv_obj_add_style(ui->MainScreen_btn_1,&MainScreenStyleFocus,LV_STATE_FOCUS_KEY );


	static lv_style_t MainScreenStyleEdit;
	lv_style_init(&MainScreenStyleEdit);
	lv_style_set_outline_color(&MainScreenStyleEdit,lv_palette_lighten(LV_PALETTE_YELLOW, 5));
	lv_style_set_outline_width(&MainScreenStyleEdit,3);
	lv_style_set_outline_pad(&MainScreenStyleEdit,4);
	lv_obj_add_style(ui->MainScreen_btn_2,&MainScreenStyleEdit,LV_STATE_PRESSED );
	lv_obj_add_style(ui->MainScreen_ta_1,&MainScreenStyleEdit,LV_STATE_EDITED );
	lv_obj_add_style(ui->MainScreen_slider_1,&MainScreenStyleEdit,LV_STATE_EDITED );
	lv_obj_add_style(ui->MainScreen_spinbox_1,&MainScreenStyleEdit,LV_STATE_EDITED );
	lv_obj_add_style(ui->MainScreen_btn_1,&MainScreenStyleEdit,LV_STATE_PRESSED );

	lv_group_t *g;

    g = lv_group_get_default();
	if(g!=NULL)
	{
            lv_group_del(g);
	}
	g= lv_group_create();
    lv_indev_t *cur_dev=NULL;

    for(;;)
    {
        cur_dev=lv_indev_get_next(cur_dev);
        if(!cur_dev) break;
        if(lv_indev_get_type(cur_dev)==LV_INDEV_TYPE_ENCODER)
        {
            lv_indev_set_group(cur_dev,g);


            lv_group_add_obj(g,ui->MainScreen_btn_2);
            lv_group_add_obj(g,ui->MainScreen_slider_1);
            lv_group_add_obj(g,ui->MainScreen_ta_1);
            lv_group_add_obj(g,ui->MainScreen_spinbox_1);
            lv_group_add_obj(g,ui->MainScreen_btn_1);
            lv_group_add_obj(g,ui->g_kb_MainScreen);
			
        }
    }
}
void SettingScreengroup(lv_ui *ui)
{
	static lv_style_t SettingScreenStyleFocus;
	lv_style_init(&SettingScreenStyleFocus);
	lv_style_set_outline_color(&SettingScreenStyleFocus,lv_palette_lighten(LV_PALETTE_RED, 2));
	lv_style_set_outline_width(&SettingScreenStyleFocus,3);
	lv_style_set_outline_pad(&SettingScreenStyleFocus,4);
	lv_obj_add_style(ui->SettingScreen_btn_2,&SettingScreenStyleFocus,LV_STATE_FOCUS_KEY );
	lv_obj_add_style(ui->SettingScreen_btn_1,&SettingScreenStyleFocus,LV_STATE_FOCUS_KEY );
	lv_obj_add_style(ui->SettingScreen_ta_1,&SettingScreenStyleFocus,LV_STATE_FOCUS_KEY );


	static lv_style_t SettingScreenStyleEdit;
	lv_style_init(&SettingScreenStyleEdit);
	lv_style_set_outline_color(&SettingScreenStyleEdit,lv_palette_lighten(LV_PALETTE_YELLOW, 5));
	lv_style_set_outline_width(&SettingScreenStyleEdit,3);
	lv_style_set_outline_pad(&SettingScreenStyleEdit,4);
	lv_obj_add_style(ui->SettingScreen_btn_2,&SettingScreenStyleEdit,LV_STATE_PRESSED );
	lv_obj_add_style(ui->SettingScreen_btn_1,&SettingScreenStyleEdit,LV_STATE_PRESSED );
	lv_obj_add_style(ui->SettingScreen_ta_1,&SettingScreenStyleEdit,LV_STATE_PRESSED );
	lv_group_t *g;

    g = lv_group_get_default();
	if(g!=NULL)
	{
    	lv_group_del(g);
	}
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
			lv_group_add_obj(g,ui->SettingScreen_ta_1);
            lv_group_add_obj(g,ui->SettingScreen_btn_1);
            lv_group_add_obj(g,ui->g_kb_SettingScreen);

        }

    }

}
