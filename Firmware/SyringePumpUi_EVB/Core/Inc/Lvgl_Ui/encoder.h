/*
 * encoder.h
 *
 *  Created on: Apr 25, 2024
 *      Author: MehdiBMofidi
 */

#ifndef INC_LVGL_UI_ENCODER_H_
#define INC_LVGL_UI_ENCODER_H_
#include "main.h"
#include "lvgl/lvgl.h"

#define NOREADY 0
#define READY 1
#define INIT 3

void encoder_init(void);

void encoder_read(lv_indev_drv_t * drv, lv_indev_data_t*data);



#endif /* INC_LVGL_UI_ENCODER_H_ */
