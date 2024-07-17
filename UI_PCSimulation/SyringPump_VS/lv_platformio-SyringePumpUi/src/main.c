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
  lv_init();

  hal_setup();


  // myInputDevice();
  setup_ui(&guider_ui);



  // lv_demo_keypad_encoder();  
    //  lv_obj_t *parent=lv_scr_act();
    // lv_obj_set_flex_flow(parent, LV_FLEX_FLOW_COLUMN);

    // lv_obj_t * ta1 = lv_textarea_create(parent);
    // lv_obj_set_width(ta1, LV_PCT(100));
    // lv_textarea_set_one_line(ta1, true);
    // lv_textarea_set_placeholder_text(ta1, "Click with an encoder to show a keyboard");

    // lv_obj_t * ta2 = lv_textarea_create(parent);
    // lv_obj_set_width(ta2, LV_PCT(100));
    // lv_textarea_set_one_line(ta2, true);
    // lv_textarea_set_placeholder_text(ta2, "Type something");

    // lv_obj_t * kb = lv_keyboard_create(lv_scr_act());
    // lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
    // lv_keyboard_set_popovers(kb,true);

    // lv_obj_add_event_cb(ta1, ta_event_cb, LV_EVENT_ALL, kb);
    // lv_obj_add_event_cb(ta2, ta_event_cb, LV_EVENT_ALL, kb);

// lv_obj_add_event_cb(guider_ui.MainScreen_ta_1, ta_event_cb, LV_EVENT_ALL, guider_ui.g_kb_MainScreen);
// MainScreengroup(&guider_ui);
// static lv_group_t * g;

//    g = lv_group_get_default();
// 	if(g!=NULL)
// 	{
//     lv_group_del(g);
// 	}
// 	g= lv_group_create();

//     lv_indev_t * cur_drv = NULL;
//     for(;;) {
//         cur_drv = lv_indev_get_next(cur_drv);
//         if(!cur_drv)       break;
//         if(cur_drv->driver->type == LV_INDEV_TYPE_KEYPAD) {
//             lv_indev_set_group(cur_drv, g);
//         }
//         if(cur_drv->driver->type == LV_INDEV_TYPE_ENCODER) {
//             lv_indev_set_group(cur_drv, g);
//             lv_group_add_obj(g,ta1);
//             lv_group_add_obj(g,ta2);
//             lv_group_add_obj(g,kb);

//         }
//     }
  hal_loop();
}
