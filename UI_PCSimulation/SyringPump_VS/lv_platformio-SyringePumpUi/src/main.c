/**
 ******************************************************************************
 * @file    main.c
 * @author  Ac6
 * @version V1.0
 * @date    01-December-2013
 * @brief   Default main function.
 ******************************************************************************
 */

#include "lvgl.h"
#include "app_hal.h"

#include "main.h"
#include "demos/lv_demos.h"
// #include "myInputDevice.h"
#include "custom.h"
#include "gui_guider.h"
// #include "demos/lv_demos.h"
lv_ui guider_ui;


// static void ta_event_cb(lv_event_t * e)
// {
//     lv_indev_t * indev = lv_indev_get_act();
//     if(indev == NULL) return;
//     lv_indev_type_t indev_type = lv_indev_get_type(indev);

//     lv_event_code_t code = lv_event_get_code(e);
//     lv_obj_t * ta = lv_event_get_target(e);
//     lv_obj_t * kb = lv_event_get_user_data(e);

//     if(code == LV_EVENT_CLICKED && indev_type == LV_INDEV_TYPE_ENCODER) {
//         lv_keyboard_set_textarea(kb, ta);
//         lv_obj_move_foreground(kb);        
//         lv_obj_clear_flag(kb, LV_OBJ_FLAG_HIDDEN);
//         lv_group_focus_obj(kb);
//         lv_group_set_editing(lv_obj_get_group(kb), kb);
//     }

//     if(code == LV_EVENT_READY || code == LV_EVENT_CANCEL) {
//         lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
//         // lv_obj_set_height(tv, LV_VER_RES);
//     }
// }
#include "time.h"

extern int MainScreen_digital_clockHeader_min_value ;
extern int MainScreen_digital_clockHeader_hour_value ;
extern int MainScreen_digital_clockHeader_sec_value;
extern char MainScreen_digital_clockHeader_meridiem[] ;


int main(void)
{

  time_t rawtime;
  struct tm * timeinfo;





  lv_init();

  hal_setup();


  // myInputDevice();
  setup_ui(&guider_ui);

  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  MainScreen_digital_clockHeader_hour_value=timeinfo->tm_hour;    
  MainScreen_digital_clockHeader_min_value=timeinfo->tm_min;    
  MainScreen_digital_clockHeader_sec_value=timeinfo->tm_sec;  
  if(timeinfo->tm_hour>=12)
  {
    lv_snprintf(MainScreen_digital_clockHeader_meridiem,3,"PM");
     if(timeinfo->tm_hour>12) MainScreen_digital_clockHeader_hour_value-=12;
  }
  else
    lv_snprintf(MainScreen_digital_clockHeader_meridiem,3,"AM");

		char buf[16];
		lv_snprintf(buf,sizeof(buf),"%d/%02d/%02d",timeinfo->tm_year+1900, timeinfo->tm_mon+1 ,timeinfo->tm_mday);
		lv_label_set_text(guider_ui.MainScreen_datetextHeader, buf);

  hal_loop();
}
