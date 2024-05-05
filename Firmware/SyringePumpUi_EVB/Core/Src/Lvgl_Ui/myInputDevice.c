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
static lv_indev_t *myEncoder,*myButtons;
const lv_point_t points_array[] = { {759,349}};
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

/*Get ID  (0, 1, 2 ..) of the pressed button*/
static int8_t button_get_pressed_id(void)
{
    uint8_t i;

    /*Check to buttons see which is being pressed (assume there are 2 buttons)*/
    	if(HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin)==GPIO_PIN_RESET)
    		return 0;
    	if(HAL_GPIO_ReadPin(KEY2_GPIO_Port, KEY2_Pin)==GPIO_PIN_RESET)
    		return 1;
    /*No button pressed*/
    return -1;
}
static void button_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{

    static uint8_t last_btn = 0;

    /*Get the pressed button's ID*/
    int8_t btn_act = button_get_pressed_id();

    if(btn_act >= 0) {
        data->state = LV_INDEV_STATE_PR;
        last_btn = btn_act;
    }
    else {
        data->state = LV_INDEV_STATE_REL;
    }

    /*Save the last pressed button's ID*/
    data->btn_id = last_btn;
}

void myIndrv(void)
{
	encoder_init();
	static lv_indev_drv_t indev_drv1;
	lv_indev_drv_init(&indev_drv1);
	indev_drv1.type=LV_INDEV_TYPE_ENCODER;
	indev_drv1.read_cb = encoder_read;
	myEncoder = lv_indev_drv_register(&indev_drv1);

	static lv_indev_drv_t indev_drv2;
	lv_indev_drv_init(&indev_drv2);
	indev_drv2.type=LV_INDEV_TYPE_BUTTON;
	indev_drv2.read_cb = button_read;
	myButtons = lv_indev_drv_register(&indev_drv2);
	lv_indev_set_button_points(myButtons, points_array);

}
//static uint32_t keypad_get_key(void)
//{
//    /*Your code comes here*/
//	if(HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin)==GPIO_PIN_RESET)
//		return (uint32_t) LV_KEY_NEXT;
//	if(HAL_GPIO_ReadPin(KEY2_GPIO_Port, KEY2_Pin)==GPIO_PIN_RESET)
//		return (uint32_t)  LV_KEY_UP;
//    return 0;
//}
//static void keypad_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
//{
//    (void) indev_drv;      /*Unused*/
//    static uint32_t last_key = 0;
//
//    /*Get whether the a key is pressed and save the pressed key*/
//    uint32_t act_key = keypad_get_key();
//    if(act_key != 0) {
//        data->state = LV_INDEV_STATE_PR;
//        last_key = act_key;
//    }
//    else {
//        data->state = LV_INDEV_STATE_REL;
//    }
//
//    data->key = last_key;
//}
