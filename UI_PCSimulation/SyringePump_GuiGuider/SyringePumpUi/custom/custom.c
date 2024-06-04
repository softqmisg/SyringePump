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
lv_group_t *g_syringevalues;
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


	static lv_style_t MainScreenStyleFocus;
	lv_style_init(&MainScreenStyleFocus);
  lv_style_set_bg_color(&MainScreenStyleFocus,lv_color_hex(0xc2ff00));
	// lv_style_set_outline_color(&MainScreenStyleFocus,lv_palette_darken(LV_PALETTE_RED, 4));
	// lv_style_set_outline_width(&MainScreenStyleFocus,3);
	// lv_style_set_outline_pad(&MainScreenStyleFocus,1);
    lv_obj_add_style(ui->MainScreen_spinboxSyringeVolume,&MainScreenStyleFocus,LV_STATE_FOCUS_KEY );
  lv_obj_add_style(ui->MainScreen_spinboxSyringeInnerDia,&MainScreenStyleFocus,LV_STATE_FOCUS_KEY );
    lv_obj_add_style(ui->MainScreen_spinboxSyringeOuterDia,&MainScreenStyleFocus,LV_STATE_FOCUS_KEY );
    lv_obj_add_style(ui->MainScreen_spinboxSyringeBarrelLen,&MainScreenStyleFocus,LV_STATE_FOCUS_KEY );
    lv_obj_add_style(ui->MainScreen_spinboxSyringePlungerLen,&MainScreenStyleFocus,LV_STATE_FOCUS_KEY );
    lv_obj_add_style(ui->MainScreen_spinboxSyringeDiaTolerance,&MainScreenStyleFocus,LV_STATE_FOCUS_KEY );

      lv_obj_add_style(ui->MainScreen_taSyringeNameValue,&MainScreenStyleFocus,LV_STATE_EDITED );
    lv_obj_add_style(ui->MainScreen_spinboxSyringeVolume,&MainScreenStyleFocus,LV_STATE_EDITED );
    lv_obj_add_style(ui->MainScreen_spinboxSyringeInnerDia,&MainScreenStyleFocus,LV_STATE_EDITED );
    lv_obj_add_style(ui->MainScreen_spinboxSyringeOuterDia,&MainScreenStyleFocus,LV_STATE_EDITED );
    lv_obj_add_style(ui->MainScreen_spinboxSyringeBarrelLen,&MainScreenStyleFocus,LV_STATE_EDITED );
    lv_obj_add_style(ui->MainScreen_spinboxSyringePlungerLen,&MainScreenStyleFocus,LV_STATE_EDITED );
    lv_obj_add_style(ui->MainScreen_spinboxSyringeDiaTolerance,&MainScreenStyleFocus,LV_STATE_EDITED );
  
	// // lv_style_set_border_width(&MainScreenStyleFocus,50);
  	//lv_style_set_border_color(&MainScreenStyleFocus,lv_palette_darken(LV_PALETTE_BLUE, 4));
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

void setcontSettingGroup(lv_ui *ui)
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
void setcontMainGroup(lv_ui *ui)
{
  lv_group_t *g;
  g = lv_group_get_default();
	if(g!=NULL)
	{
            lv_group_del(g);
	}
}
void setcontSyringeGroup(lv_ui *ui)
{
  lv_group_t *g;
  g = lv_group_get_default();
	if(g!=NULL)
	{
            lv_group_del(g);
	}
}
void setlistSyringeCompanyGroup(lv_ui *ui)
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
            lv_obj_t *obj_child;
            bool has_stat=false;
            for(int i=0;i<lv_obj_get_child_cnt(ui->MainScreen_listSyringeCompany);i++)
            {
              obj_child=lv_obj_get_child(ui->MainScreen_listSyringeCompany,i);
              lv_group_add_obj(g,obj_child);			
              if(lv_obj_has_state(obj_child,LV_STATE_FOCUS_KEY)) 
              {
                has_stat=true;
                lv_group_focus_obj(obj_child);
              }
            }
            if(!has_stat)
              lv_obj_add_state(lv_obj_get_child(ui->MainScreen_listSyringeCompany,0),LV_STATE_FOCUS_KEY);
        }
    }  
 
}
void setlistSyringeTypeGroup(lv_ui *ui)
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
            lv_obj_t *obj_child;
            bool has_stat=false;
            for(int i=0;i<lv_obj_get_child_cnt(ui->MainScreen_listSyringeType);i++)
            {
              obj_child=lv_obj_get_child(ui->MainScreen_listSyringeType,i);
              lv_group_add_obj(g,obj_child);			
              if(lv_obj_has_state(obj_child,LV_STATE_FOCUS_KEY)) 
              {
                has_stat=true;
                lv_group_focus_obj(obj_child);
              }
            }
            if(!has_stat)
			        lv_obj_add_state(lv_obj_get_child(ui->MainScreen_listSyringeType,0),LV_STATE_FOCUS_KEY);
        }
    }    
}
void setcontSyringeValuesGroup(lv_ui *ui)
{
    lv_group_t *g;
    g = lv_group_get_default();
	if(g!=NULL)
	{
            lv_group_del(g);
	}
	g_syringevalues= lv_group_create();
	lv_group_set_default(g_syringevalues);
  lv_group_set_wrap(g_syringevalues,false);
    lv_indev_t *cur_dev=NULL;  
   for(;;)
    {
        cur_dev=lv_indev_get_next(cur_dev);
        if(!cur_dev) break;
        if(lv_indev_get_type(cur_dev)==LV_INDEV_TYPE_ENCODER)
        {
            lv_indev_set_group(cur_dev,g_syringevalues);
            lv_group_add_obj(g_syringevalues,ui->MainScreen_taSyringeNameValue);
            lv_group_add_obj(g_syringevalues,ui->MainScreen_spinboxSyringeVolume);
            lv_group_add_obj(g_syringevalues,ui->MainScreen_spinboxSyringeInnerDia);
            lv_group_add_obj(g_syringevalues,ui->MainScreen_spinboxSyringeOuterDia);			
            lv_group_add_obj(g_syringevalues,ui->MainScreen_spinboxSyringeBarrelLen);			
            lv_group_add_obj(g_syringevalues,ui->MainScreen_spinboxSyringePlungerLen);			
            lv_group_add_obj(g_syringevalues,ui->MainScreen_spinboxSyringeDiaTolerance);			          
        
            lv_group_add_obj(g_syringevalues,ui->g_kb_MainScreen);
            lv_obj_add_state(ui->MainScreen_taSyringeNameValue,LV_STATE_FOCUS_KEY);
        }
    }  
}


void animcontMain_ready_callback(lv_anim_t * a)
{
  setcontMainGroup(&guider_ui);
}
void animcontSetting_ready_callback(lv_anim_t * a)
{
  setcontSettingGroup(&guider_ui);
 
}
void animcontSyringe_ready_callback(lv_anim_t * a)
{
  setlistSyringeCompanyGroup(&guider_ui);
}