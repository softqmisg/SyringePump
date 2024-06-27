#include "Drug.h"
drug_t DefaultDrugs[50]; //50 Types

void loadDefaultDrugValue(void)
{
    for(uint8_t brands=0;brands<50;brands++)
    {
        DefaultDrugs[brands].Drugindex=brands;
        if(brands==0)
        {
            lv_snprintf(DefaultDrugs[brands].Brand,20,"User Defined",brands);
            lv_snprintf(DefaultDrugs[brands].Name,20,"user Drug",brands);
        }
        else
        {
            lv_snprintf(DefaultDrugs[brands].Brand,20,"Brand %d",brands);
            lv_snprintf(DefaultDrugs[brands].Name,20,"Drug %d",brands);

        }
            DefaultDrugs[brands].Id=(Id_t)lv_rand(0,4);
            DefaultDrugs[brands].mg_ml_1000=(uint16_t)lv_rand(0,10000);
            DefaultDrugs[brands].u_ml_1000=(uint16_t)lv_rand(0,10000);
            DefaultDrugs[brands].per_kg_1000=(uint16_t)lv_rand(0,20000);
            DefaultDrugs[brands].RateMin10=(uint16_t)lv_rand(0,18000);
            DefaultDrugs[brands].RateMax10=(uint16_t)lv_rand(0,18000);
            DefaultDrugs[brands].RateDef10=(uint16_t)lv_rand(0,18000);
           
    }
}