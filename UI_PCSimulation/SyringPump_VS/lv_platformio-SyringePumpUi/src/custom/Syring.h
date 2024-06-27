#ifndef __SYRING_H__
#define __SYRING_H__
#include "lvgl.h"
typedef struct{
    uint8_t ManufactureIndex;
    uint8_t TypeIndex;
    char Manufacture[20];
    char Name[20];
    uint8_t Volume;
    uint16_t InnerDia10;
    uint16_t OuterDia10;
    uint16_t BarrelLen10;
    uint16_t PlungerLen10;
    uint16_t DiaTolerance10;
} syringe_t;

void loadDefaultSyringesValue(void);
extern syringe_t DefaultSyrings[50][20];
#endif