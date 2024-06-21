#ifndef __INFUSIONMODE_H__
#define __INFUSIONMODE_H__
#include "lvgl.h"
#include "time.h"
// typedef enum  {modeVol=0,modeTime=1,modeBody=2,modeIntermittent=3,modeRhytmic=4,modeLinear=5} modeid_t;
// typedef enum  {unitMl=0,unitUg,unitMg,unitUnit} modeunit_t;
// typedef enum  {perNone=0,perHour,perMin} modeper_t;
// typedef struct{
//     modeid_t mode;
//     modeunit_t unit;
//     modeper_t per;
//     uint16_t TotalVolume10;
//     uint16_t InfusionRate10;
//     time_t TotalTime;
//     uint16_t BodyWeight;
// } infusionmode_t;


typedef enum  {modeVol=0,modeTime=1,modeBody=2,modeIntermittent=3,modeRhytmic=4,modeLinear=5} modeid_t;
typedef struct{
    modeid_t mode;
    uint8_t unit;
    uint16_t TotalVolume10;
    uint16_t InfusionRate10;
    time_t TotalTime;
    uint16_t BodyWeight;
} infusionmode_t;

void loadDefaultInfusionModeValue(void);
extern infusionmode_t DefaultModes[6][8];
#endif