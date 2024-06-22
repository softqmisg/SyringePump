#include "myInputDevice.h"
#include <stdio.h>
#include <conio.h>
/// @brief
/**
 * @brief function primitive
 */
/**
 * @brief variable define
 */

#define HIGHBYTE    0//224
static lv_indev_t *myencoder;
static lv_indev_t *mybuttons;
static bool mybtn_is_pressed(uint8_t id)
{
    uint16_t last_key;
    if (kbhit())
    {
        last_key = getch();
        // printf("%d(%c)\n\r",last_key,last_key);
        if (last_key == HIGHBYTE)//0
        {
            last_key = getch();
           printf("btn:%d(%c)\n\r",last_key,last_key);

            switch (last_key)
            {
            case 'O'://Home
                // code for arrow right
                if(id==0)
                    return true;
                break;
            case 'G':  //end
                // code for arrow left
                if(id==1)
                    return true;
                break;
            }
        }
    }
    return false;
}
static int8_t mybtn_get_pressed_id(void)
{
    uint8_t i;
    for(i=0;i<2;i++)
    {
        if(mybtn_is_pressed(i))
        {
            return i;
        }
    }
    return -1;
}
void mybuttons_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data)
{

    static uint32_t last_btn = 0;   /*Store the last pressed button*/
    int btn_pr = mybtn_get_pressed_id();     /*Get the ID (0,1,2...) of the pressed button*/
    if(btn_pr >= 0) {               /*Is there a button press? (E.g. -1 indicated no button was pressed)*/
       last_btn = btn_pr;           /*Save the ID of the pressed button*/
       data->state = LV_INDEV_STATE_PRESSED;  /*Set the pressed state*/
    } else {
       data->state = LV_INDEV_STATE_RELEASED; /*Set the released state*/
    }

    data->btn_id = last_btn;            /*Save the last button*/
}
static int32_t encoder_diff=0;
void myencoder_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data)
{
    static uint32_t last_key;
    if (kbhit())
    {
        last_key = getch();
        //    printf("%d(%c)\n\r",last_key,last_key);

        if (last_key == HIGHBYTE)//0
        {
            last_key = getch();
        //    printf("enc:%d(%c)\n\r",last_key,last_key);

            switch (last_key)
            {
                case 'M':
                    // code for arrow right
                    encoder_diff = 1;
                    break;
                case 'K':
                    // code for arrow left
                        encoder_diff =- 1;
                    break;
            }
        }
        else if (last_key == 13)
        {
            data->state = LV_INDEV_STATE_PR;
        }    
    }
    else
    {
        data->state = LV_INDEV_STATE_REL;
        encoder_diff=0;
    }
    data->enc_diff = encoder_diff;

}

void myInputDevice(void)
{
    static lv_indev_drv_t indev_drv1;
    lv_indev_drv_init(&indev_drv1); /*Basic initialization*/
    indev_drv1.type = LV_INDEV_TYPE_ENCODER;
    indev_drv1.read_cb = myencoder_read; /*This function will be called periodically (by the library) to get the mouse position and state*/
    myencoder = lv_indev_drv_register(&indev_drv1);

    // static lv_indev_drv_t indev_drv2;
    // lv_indev_drv_init(&indev_drv2); /*Basic initialization*/
    // indev_drv2.type = LV_INDEV_TYPE_BUTTON;
    // indev_drv2.read_cb = mybuttons_read; /*This function will be called periodically (by the library) to get the mouse position and state*/
    // mybuttons = lv_indev_drv_register(&indev_drv2);

}
