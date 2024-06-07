#include "Syring.h"
#include "custom.h"
syringe_t DefaultSyrings[50][20]; //50 Companies,20 Types

void loadDefaultSyringesValue(void)
{
    for(uint8_t mfg=0;mfg<50;mfg++)
    {
        for(uint8_t sy=0;sy<20;sy++)
        {
            lv_snprintf(DefaultSyrings[mfg][sy].Manufacture,20,"Company %d",mfg);
            lv_snprintf(DefaultSyrings[mfg][sy].Name,20,"Syringe %d_%d",mfg,sy);
            DefaultSyrings[mfg][sy].Volume=(uint8_t)randi(0,60);
            DefaultSyrings[mfg][sy].InnerDia10=(uint16_t)randi(0,500);
            DefaultSyrings[mfg][sy].OuterDia10=(uint16_t)randi(0,500);
            DefaultSyrings[mfg][sy].BarrelLen10=(uint16_t)randi(0,2000);
            DefaultSyrings[mfg][sy].PlungerLen10=(uint16_t)randi(0,600);
            DefaultSyrings[mfg][sy].DiaTolerance10=(int16_t)randi(-100,100);
        }
    }
}