/*
 * myUI.c
 *
 *  Created on: Apr 21, 2024
 *      Author: MehdiBMofidi
 */

#include "myUI.h"
#include "main.h"
#include "encoder.h"
#include <stdio.h>
static lv_indev_t *physical_keypad;
static lv_group_t *g;
void ui_event_spinbox1(lv_event_t * e)
{
	uint32_t u32_key;
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_KEY) {
//        printf("enter key event spinbox1\n\r");
//
//    	u32_key = lv_event_get_key(e);
//    	if (u32_key == LV_KEY_LEFT)
//    	{
//    		//lv_spinbox_decrement(target);
//    		printf("left\n\r");
//    	}
//    	else if (u32_key == LV_KEY_RIGHT)
//    	{
//    	  //lv_spinbox_increment(target);
//    	  printf("right\n\r");
//
//    	  /* Project specific code */
//    	}
//    	else if(u32_key==LV_KEY_ENTER)
//    	{
//    		g= lv_obj_get_group(target);
//    		if(lv_obj_is_focused(target))
//    			printf("focus spin\n\r");
//    		lv_group_focus_next(g);
//    		if(!lv_obj_is_focused(target))
//    			printf("not focus spin\n\r");
//
//    		lv_spinbox_set_pos(target,0);
//
//    		 printf("Enter\n\r");
//
//    	}
    }
}

static uint32_t keypad_get_key(void)
{
    /*Your code comes here*/
	if(HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin)==GPIO_PIN_RESET)
		return (uint32_t) LV_KEY_NEXT;
	if(HAL_GPIO_ReadPin(KEY2_GPIO_Port, KEY2_Pin)==GPIO_PIN_RESET)
		return (uint32_t)  LV_KEY_UP;
    return 0;
}
static void keypad_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
    (void) indev_drv;      /*Unused*/
    static uint32_t last_key = 0;

    /*Get whether the a key is pressed and save the pressed key*/
    uint32_t act_key = keypad_get_key();
    if(act_key != 0) {
        data->state = LV_INDEV_STATE_PR;
//        switch(act_key)
//        {
//        case 1:
//        	act_key=LV_KEY_ENTER;
//        	break;
//        case 2:
//        	act_key=LV_KEY_UP;
//        	break;
//        }
        last_key = act_key;
    }
    else {
        data->state = LV_INDEV_STATE_REL;
    }

    data->key = last_key;
}


void myIndrv(void)
{
	encoder_init();
	static lv_indev_drv_t physical_btn_drv;
	lv_indev_drv_init(&physical_btn_drv);
	physical_btn_drv.type=LV_INDEV_TYPE_ENCODER;
	physical_btn_drv.read_cb = encoder_read;
	physical_keypad = lv_indev_drv_register(&physical_btn_drv);
}
void myUI(void)
{

	 lv_obj_t *disp=lv_scr_act();
	 g=lv_group_create();
	 lv_indev_set_group(physical_keypad,g);

	  lv_obj_t *btn1=lv_btn_create(disp);
	  lv_obj_set_size(btn1,100,50);
	  lv_obj_align(btn1,LV_ALIGN_TOP_MID,0,20);
	  lv_obj_t *btn2=lv_btn_create(disp);
	  lv_obj_set_size(btn2,100,50);
	  lv_obj_align_to(btn2,btn1,LV_ALIGN_OUT_BOTTOM_MID,0,20);
	  lv_obj_t *btn3=lv_btn_create(disp);
	  lv_obj_set_size(btn3,100,50);
	  lv_obj_align_to(btn3,btn2,LV_ALIGN_OUT_BOTTOM_MID,0,20);

	  lv_obj_t *slider1=lv_slider_create(disp);
	  lv_obj_set_size(slider1,200,30);
	  lv_obj_align_to(slider1,btn3,LV_ALIGN_OUT_BOTTOM_MID,0,20);

	  lv_obj_t *spinbox1=lv_spinbox_create(disp);
	  lv_spinbox_set_range(spinbox1, -100, 100);
	  lv_spinbox_set_digit_format(spinbox1, 3, 0);
	  // lv_spinbox_step_prev(spinbox1);
	  lv_spinbox_set_pos(spinbox1,0);
	  lv_obj_set_width(spinbox1, 100);
	  lv_obj_align_to(spinbox1,slider1,LV_ALIGN_OUT_BOTTOM_MID,0,20);
	   lv_obj_add_event_cb(spinbox1, ui_event_spinbox1, LV_EVENT_ALL, NULL);

	  lv_group_add_obj(g,btn1);
	  lv_group_add_obj(g,btn2);
	  lv_group_add_obj(g,btn3);
	  lv_group_add_obj(g,slider1);
	  lv_group_add_obj(g,spinbox1);
}


