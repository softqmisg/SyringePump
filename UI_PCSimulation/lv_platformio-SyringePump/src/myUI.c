#include "myUI.h"
#include <stdio.h>
#include <conio.h>
/// @brief
/**
 * @brief function primitive
 */
static void gotoscreen1_handler(lv_event_t *e);
static void gotoscreen2_handler(lv_event_t *e);

void createpage1();
void createpage2();

/**
 * @brief variable define
 */
extern lv_indev_t *mykeyboard;
extern lv_indev_t *myencoder;
static lv_indev_t *mykeyboard1;
static  lv_obj_t *page1;
static lv_obj_t *page2;

void mykeyboard_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data)
{

    (void)indev_drv; /*Unused*/
    static uint32_t last_key;
    if (kbhit())
    {
        data->state = LV_INDEV_STATE_PR;
        last_key = getch();
        printf("%d(%c)\n\r",last_key,last_key);
        if (last_key == 224)//0
        {
            last_key = getch();
        printf("%d(%c)\n\r",last_key,last_key);

            switch (last_key)
            {
            // case 'H':
            //     // code for arrow up
            //     last_key = LV_KEY_ENTER;
            //     break;
            // case 'P':
            //     // code for arrow down
            //     last_key = LV_KEY_DOWN;
            //     break;
            case 'M':
                // code for arrow right
                last_key = LV_KEY_RIGHT;
                break;
            case 'K':
                // code for arrow left
                last_key = LV_KEY_LEFT;
                break;
            }
        }
        else if (last_key == 13)
        {
            last_key = LV_KEY_ENTER;
        }
    }
    else
    {
        data->state = LV_INDEV_STATE_REL;
    }
    data->key = last_key;
}

void myInputDevice(void)
{
    static lv_indev_drv_t indev_drv1;
    lv_indev_drv_init(&indev_drv1); /*Basic initialization*/
    indev_drv1.type = LV_INDEV_TYPE_ENCODER;
    indev_drv1.read_cb = mykeyboard_read; /*This function will be called periodically (by the library) to get the mouse position and state*/
    mykeyboard1 = lv_indev_drv_register(&indev_drv1);
}
void myUI(void)
{

    createpage1(page1);

}
static void gotoscreen2_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_PRESSED)     
    {
        printf("gotoscreen2_handler");
        createpage2();

        lv_obj_del(page1);

    }
}

void createpage1()
{
    page1 = lv_obj_create(NULL);
    lv_scr_load(page1);
    lv_group_t *g = lv_group_create();
    lv_indev_set_group(mykeyboard1, g);

    lv_obj_set_style_bg_color(page1,lv_color_hex(0x000000),LV_PART_MAIN);
    
    lv_obj_t *btn1 = lv_btn_create(page1);
    lv_obj_set_size(btn1, 100, 50);
    lv_obj_align(btn1, LV_ALIGN_TOP_MID, 0, 20);
    lv_obj_t *label1=lv_label_create(btn1);
    lv_label_set_text(label1,"page1");
    lv_obj_set_align(label1,LV_ALIGN_CENTER);
    
    lv_obj_t *btn2 = lv_btn_create(page1);
    lv_obj_set_size(btn2, 100, 50);
    lv_obj_align_to(btn2, btn1, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);

    lv_obj_t *btn3 = lv_btn_create(page1);
    lv_obj_set_size(btn3, 100, 50);
    lv_obj_align_to(btn3, btn2, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);
    lv_obj_add_event_cb(btn3, gotoscreen2_handler, LV_EVENT_PRESSED, NULL);
    label1=lv_label_create(btn3);
    lv_label_set_text(label1,"Next Page");
    lv_obj_set_align(label1,LV_ALIGN_CENTER);


    lv_obj_t *slider1 = lv_slider_create(page1);
    lv_obj_set_size(slider1, 200, 30);
    lv_obj_align_to(slider1, btn3, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);

    lv_obj_t *spinbox1 = lv_spinbox_create(page1);
    lv_spinbox_set_range(spinbox1, -100, 100);
    lv_spinbox_set_digit_format(spinbox1, 3, 0);
    // lv_spinbox_step_prev(spinbox1);
    lv_spinbox_set_pos(spinbox1, 1);
    lv_obj_set_width(spinbox1, 100);
    lv_obj_align_to(spinbox1, slider1, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);

    lv_group_add_obj(g, btn1);
    lv_group_add_obj(g, btn2);
    lv_group_add_obj(g, btn3);
    lv_group_add_obj(g, slider1);
    lv_group_add_obj(g, spinbox1);
}
static void gotoscreen1_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_PRESSED) 
    {
        printf("gotoscreen1_handler");
        createpage1();
        lv_obj_del(page2);
    }
}

void createpage2()
{
    page2 = lv_obj_create(NULL);
    lv_scr_load(page2);
    lv_group_t *g = lv_group_create();
    lv_indev_set_group(mykeyboard1, g);

    lv_obj_t *btn1 = lv_btn_create(page2);
    lv_obj_set_size(btn1, 100, 50);
    lv_obj_align(btn1, LV_ALIGN_TOP_MID, 0, 20);
    lv_obj_t *label1=lv_label_create(btn1);
    lv_label_set_text(label1,"page2");
    lv_obj_set_align(label1,LV_ALIGN_CENTER);

    lv_obj_t *btn2 = lv_btn_create(page2);
    lv_obj_set_size(btn2, 100, 50);
    lv_obj_align_to(btn2, btn1, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);
    lv_obj_add_event_cb(btn2, gotoscreen1_handler, LV_EVENT_PRESSED, NULL);

    label1=lv_label_create(btn2);
    lv_label_set_text(label1,"next");
    lv_obj_set_align(label1,LV_ALIGN_CENTER);

    lv_group_add_obj(g, btn1);
    lv_group_add_obj(g, btn2);


}