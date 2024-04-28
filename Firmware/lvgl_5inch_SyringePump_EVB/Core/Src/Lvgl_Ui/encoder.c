/*
 * encoder.c
 *
 *  Created on: Apr 25, 2024
 *      Author: MehdiBMofidi
 */

#include "encoder.h"
#include "tim.h"
#include <stdio.h>
volatile uint16_t last_tim4_cnt;

int16_t TIM4_read(void)
{

    uint16_t tim4_cnt;

    tim4_cnt = __HAL_TIM_GET_COUNTER(&htim4);
    uint16_t diff = (uint16_t)(tim4_cnt - last_tim4_cnt);
    last_tim4_cnt = tim4_cnt;

    if (diff == 0u)
    {
    	return 0;
        // No change
    }
    else if (diff & 0x8000u)
    {
        // Counter has decreased, diff is negative
    	return -1;
    }
    else
    {
        // Counter has increased, diff is positive
    	return 1;
    }

}

uint8_t enc_pressed(void)
{
	return HAL_GPIO_ReadPin(ENCODER_SW_GPIO_Port, ENCODER_SW_Pin);
}
void encoder_init(void)
{
	  HAL_TIM_Encoder_Start_IT(&htim4, TIM_CHANNEL_ALL);
	  last_tim4_cnt=__HAL_TIM_GET_COUNTER(&htim4);
}

 void encoder_read(lv_indev_drv_t * drv, lv_indev_data_t*data)
{
	  data->enc_diff = TIM4_read();
	  if(!enc_pressed()){
	    data->state = LV_INDEV_STATE_PR;
	  }
	  else{
	    data->state = LV_INDEV_STATE_REL;
	  }
//	  printf("ENC=%d BTN=%d\r\n",data->enc_diff, data->state);
}
