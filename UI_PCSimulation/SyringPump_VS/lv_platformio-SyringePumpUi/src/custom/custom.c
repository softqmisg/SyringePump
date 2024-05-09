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
void MainScreenSetStyle(lv_ui *ui)
{
 //  	static lv_style_t style_indic;
 // 	lv_style_init(&style_indic);
	// lv_style_set_bg_img_src(&style_indic,&indicator_ver);
	// lv_obj_add_style(ui->MainScreen_slider_2,&style_indic,LV_PART_INDICATOR);

	// static lv_style_t MainScreenStyleFocus;
	// lv_style_init(&MainScreenStyleFocus);
	// lv_style_set_outline_color(&MainScreenStyleFocus,lv_palette_darken(LV_PALETTE_RED, 4));
	// lv_style_set_outline_width(&MainScreenStyleFocus,3);
	// lv_style_set_outline_pad(&MainScreenStyleFocus,1);
	// // lv_style_set_border_width(&MainScreenStyleFocus,50);
 //  	lv_style_set_border_color(&MainScreenStyleFocus,lv_palette_darken(LV_PALETTE_BLUE, 4));
 //    lv_style_set_bg_color(&MainScreenStyleFocus,lv_palette_darken(LV_PALETTE_BLUE, 4));

	// lv_obj_add_style(ui->MainScreen_imgMenuSyringe,&MainScreenStyleFocus,LV_STATE_FOCUS_KEY );
 //  	lv_obj_add_style(ui->MainScreen_imgMenuDrug,&MainScreenStyleFocus,LV_STATE_FOCUS_KEY );
	// lv_obj_add_style(ui->MainScreen_imgMenuMode,&MainScreenStyleFocus,LV_STATE_FOCUS_KEY );
	// lv_obj_add_style(ui->MainScreen_imgMenuOCC,&MainScreenStyleFocus,LV_STATE_FOCUS_KEY );
	// lv_obj_add_style(ui->MainScreen_imgMenuKVO,&MainScreenStyleFocus,LV_STATE_FOCUS_KEY );
	// lv_obj_add_style(ui->MainScreen_imgMenuIntInf,&MainScreenStyleFocus,LV_STATE_FOCUS_KEY );
 //    lv_obj_add_style(ui->MainScreen_imgMenuRhyInf,&MainScreenStyleFocus,LV_STATE_FOCUS_KEY );
 //    lv_obj_add_style(ui->MainScreen_imgMenuNurseCall,&MainScreenStyleFocus,LV_STATE_FOCUS_KEY );
 //    lv_obj_add_style(ui->MainScreen_imgMenuBolus,&MainScreenStyleFocus,LV_STATE_FOCUS_KEY );
 //    lv_obj_add_style(ui->MainScreen_imgMenuPurge,&MainScreenStyleFocus,LV_STATE_FOCUS_KEY );
 //    lv_obj_add_style(ui->MainScreen_imgMenuSetting,&MainScreenStyleFocus,LV_STATE_FOCUS_KEY );
  


	// static lv_style_t MainScreenStyleEdit;
	// lv_style_init(&MainScreenStyleEdit);
	// lv_style_set_outline_color(&MainScreenStyleEdit,lv_palette_lighten(LV_PALETTE_YELLOW, 5));
	// lv_style_set_outline_width(&MainScreenStyleEdit,3);
	// lv_style_set_outline_pad(&MainScreenStyleEdit,4);
	// lv_obj_add_style(ui->MainScreen_btn_2,&MainScreenStyleEdit,LV_STATE_PRESSED );
	// lv_obj_add_style(ui->MainScreen_ta_1,&MainScreenStyleEdit,LV_STATE_EDITED );
	// lv_obj_add_style(ui->MainScreen_slider_1,&MainScreenStyleEdit,LV_STATE_EDITED );
	// lv_obj_add_style(ui->MainScreen_slider_2,&MainScreenStyleEdit,LV_STATE_EDITED );
	// lv_obj_add_style(ui->MainScreen_spinbox_1,&MainScreenStyleEdit,LV_STATE_EDITED );
	// lv_obj_add_style(ui->MainScreen_btn_1,&MainScreenStyleEdit,LV_STATE_PRESSED );	

}

void SettingConSetGroup(lv_ui *ui)
{
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
            //lv_group_add_obj(g,ui->MainScreen_imgDroplet);
            lv_group_add_obj(g,ui->MainScreen_btnMenuSyringe);
            lv_group_add_obj(g,ui->MainScreen_btnMenuDrug);
            lv_group_add_obj(g,ui->MainScreen_btnMenuMode);
            lv_group_add_obj(g,ui->MainScreen_btnMenuOCC);			
            lv_group_add_obj(g,ui->MainScreen_btnMenuKVO);
            lv_group_add_obj(g,ui->MainScreen_btnMenuIntInf);
            lv_group_add_obj(g,ui->MainScreen_btnMenuRhyInf);
            lv_group_add_obj(g,ui->MainScreen_btnMenuNurseCall);
            lv_group_add_obj(g,ui->MainScreen_btnMenuBolus);
            lv_group_add_obj(g,ui->MainScreen_btnMenuPurge);
            lv_group_add_obj(g,ui->MainScreen_btnMenuSetting);
          
            // lv_group_add_obj(g,ui->g_kb_MainScreen);
			lv_obj_add_state(ui->MainScreen_btnMenuSyringe,LV_STATE_FOCUS_KEY);
        }
    }
}
void MainConSetGroup(lv_ui *ui)
{
  lv_group_t *g;
  g = lv_group_get_default();
	if(g!=NULL)
	{
            lv_group_del(g);
	}
}
void SyringeConSetGroup(lv_ui *ui)
{
  lv_group_t *g;
  g = lv_group_get_default();
	if(g!=NULL)
	{
            lv_group_del(g);
	}
}
void animconMain_ready_callback(lv_anim_t * a)
{
  MainConSetGroup(&guider_ui);
}
void animconSetting_ready_callback(lv_anim_t * a)
{
		SettingConSetGroup(&guider_ui);
 
}
void animconSyringe_ready_callback(lv_anim_t * a)
{
  SyringeConSetGroup(&guider_ui);
}