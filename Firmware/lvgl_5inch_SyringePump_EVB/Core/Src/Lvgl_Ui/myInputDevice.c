/*
 * myUI.c
 *
 *  Created on: Apr 21, 2024
 *      Author: MehdiBMofidi
 */

#include <myInputDevice.h>
#include "main.h"
#include "tim.h"
#include <stdio.h>
static lv_indev_t *myEncoder;

uint8_t enc_pressed(void)
{
	return HAL_GPIO_ReadPin(ENCODER_SW_GPIO_Port, ENCODER_SW_Pin);
}
void encoder_init(void)
{
	  HAL_TIM_Encoder_Start(&htim4, TIM_CHANNEL_ALL);
	  __HAL_TIM_SET_COUNTER(&htim4,0);
}
void encoder_read(lv_indev_drv_t * drv, lv_indev_data_t*data)
{
	static int32_t last_encoder_val = 0;
	int32_t encoder_val = __HAL_TIM_GET_COUNTER(&htim4);
	int32_t encoder_diff = encoder_val - last_encoder_val;
	data->enc_diff = encoder_diff;
	last_encoder_val = encoder_val;

	if (!enc_pressed())
	data->state = LV_INDEV_STATE_PR;
	else
	data->state = LV_INDEV_STATE_REL;
}


void myIndrv(void)
{
	encoder_init();
	static lv_indev_drv_t indev_drv1;
	lv_indev_drv_init(&indev_drv1);
	indev_drv1.type=LV_INDEV_TYPE_ENCODER;
	indev_drv1.read_cb = encoder_read;
	myEncoder = lv_indev_drv_register(&indev_drv1);
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
