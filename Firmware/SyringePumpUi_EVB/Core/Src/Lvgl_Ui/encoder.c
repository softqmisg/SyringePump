/*
 * encoder.c
 *
 *  Created on: Apr 25, 2024
 *      Author: MehdiBMofidi
 */

#include "encoder.h"
#include "tim.h"
#include <stdio.h>



void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance==TIM4)
	{

	}
}
static  uint16_t last_tim4_cnt=0;

int16_t TIM4_read(void)
{

	uint16_t  tim4_cnt = __HAL_TIM_GET_COUNTER(&htim4);
    uint16_t diff = (tim4_cnt - last_tim4_cnt);
	last_tim4_cnt = tim4_cnt;
	if(last_tim4_cnt==0xffff)
	{
		diff=0;
		__HAL_TIM_SET_COUNTER(&htim4,0);
	}
	return (int16_t) diff;
}

uint8_t enc_pressed(void)
{
	return HAL_GPIO_ReadPin(ENCODER_SW_GPIO_Port, ENCODER_SW_Pin);
}
 void encoder_init(void)
{
	  HAL_TIM_Encoder_Start(&htim4, TIM_CHANNEL_ALL);
	  __HAL_TIM_SET_COUNTER(&htim4,0);
	  last_tim4_cnt=0;
}

  void encoder_read(lv_indev_drv_t * drv, lv_indev_data_t*data)
{
//	  data->enc_diff = (int16_t)TIM4_read();
//
//	 if(!enc_pressed()){
//	    data->state = LV_INDEV_STATE_PR;
//	    __HAL_TIM_SET_COUNTER(&htim4,0);
//	  }
//	  else{
//	    data->state = LV_INDEV_STATE_REL;
//	  }



	  static int32_t last_encoder_diff = 0;
	  int32_t encoder_val = __HAL_TIM_GET_COUNTER(&htim4);
	  int32_t encoder_diff = encoder_val - last_encoder_diff;
	  data->enc_diff = encoder_diff;
	  last_encoder_diff = encoder_val;

	  if (!enc_pressed())
	    data->state = LV_INDEV_STATE_PR;
	  else
	    data->state = LV_INDEV_STATE_REL;

}
