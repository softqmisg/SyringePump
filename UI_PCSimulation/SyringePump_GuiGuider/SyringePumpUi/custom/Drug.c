#include "Drug.h"
#include "main.h"
drug_t DefaultDrugs[50]; //50 Types

void loadDefaultSyringesValue(void)
{
    for(uint8_t brands=0;brands<50;brands++)
    {
            lv_snprintf(DefaultDrugs[brands].Brand,20,"Brand %d",brands);
            lv_snprintf(DefaultDrugs[brands].Name,20,"Drug %d",brands);
            DefaultDrugs[brands].Id=(Id_t)randi(0,4);
            DefaultDrugs[brands].mg_ml_1000=(uint16_t)randi(0,10000);
            DefaultDrugs[brands].u_ml_1000=(uint16_t)randi(0,10000);
            DefaultDrugs[brands].per_kg_1000=(uint16_t)randi(0,20000);
            DefaultDrugs[brands].RateMin10=(uint16_t)randi(0,18000);
            DefaultDrugs[brands].RateMax10=(uint16_t)randi(0,18000);
            DefaultDrugs[brands].RateDef10=(uint16_t)randi(0,18000);
           
    }
}