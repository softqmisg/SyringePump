#ifndef __MACHINE_STATE_H__
#define __MACHINE_STATE_H__
#include "lvgl.h"
#include "time.h"
#include "Syring.h"
#include "Drug.h"
#include "InfusionMode.h"
typedef struct
{
    uint16_t x;
    uint16_t y;
} pos_t;
typedef struct 
{
    bool UsbPortEnable;
    bool NetworkEnable;
    bool AuromaticDHCPEnable;
    bool WebserverEnable;
    bool ConfigNetworkEnable;
    bool  RS485Enable;
    bool ConfigRs485Enable;
    bool TitleGradientMode;
    bool MainAreaGardientMode;
    bool SyringeGardientMode;

} system_t;


typedef struct 
{
    syringe_t Syringe;
    drug_t  Drug;
    infusionmode_t  Mode;
    uint8_t OcclusionLevel;
    bool KvoMode;
    uint8_t KvoRate10;       //max 20
    uint16_t IntermittentInfusionRate10; //max 18000
    uint8_t IntermittentInfusionRateUnit; //0-7
    time_t IntermittentDuration;
    uint16_t IntermittentBackgroundRate10; //max 50
    time_t IntermittentSleep;
    pos_t RhythmicTable[50];
    bool NurseCall;
    uint8_t NurseActiveDuration; //59
    uint16_t BolusRate10; //max 18000
    uint8_t BolusMaxVolume10;//max 50
    time_t BolusIntervalTime;
    uint16_t PurgeRate10; //max 18000
    uint8_t PurgeMaxVolume10; //max 50
    time_t PurgeIntervalTime;
    
    //setting
    struct tm  curTime;
    uint8_t VolumeLevel;
    uint8_t BrightnessLevel;
    bool NigheMode;
    time_t NightStartTime;
    time_t NightEndTime;
    uint8_t NightBrightnessLevel;
    char Password[4];
    system_t SystemSetup;

} machinstate_t;

extern machinstate_t currentMachineState;
void LoadCurrentMachinValue(void);

#endif