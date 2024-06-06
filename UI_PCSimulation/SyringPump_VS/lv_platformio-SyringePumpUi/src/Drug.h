#ifndef __DRUG_H__
#define __DRUG_H__
#include "lvgl.h"
typedef enum  {ml,ug,mg,unit} Id_t;
typedef struct{
    char Brand[20];
    char Name[20];
    Id_t Id;
    uint16_t mg_ml_1000; //0.000->10.000
    uint16_t u_ml_1000; //0.000->10.000
    uint16_t per_kg_1000;//0.000->20.000
    uint16_t RateMin10; //0.0->1800.0
    uint16_t RateMax10; //0.0->1800.0
    uint16_t RateDef10; //0.0->1800.0    
} drug_t;

void loadDefaultDrugValue(void);
extern drug_t DefaultDrugs[50];
#endif