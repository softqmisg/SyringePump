#include "MachineState.h"

machinstate_t currentMachineState;
extern uint8_t cur_SyringeManufacture, cur_SyringeType;
extern uint8_t cur_Drug;
extern uint8_t cur_ModeMode, cur_ModeUnit;
void LoadCurrentMachinValue(void)
{
    memcpy(&currentMachineState.Syringe,&DefaultSyrings[0][0],sizeof(syringe_t));
    memcpy(&currentMachineState.Drug,&DefaultDrugs[0],sizeof(drug_t));
    memcpy(&currentMachineState.Mode,&DefaultModes[2][3],sizeof(infusionmode_t));
    currentMachineState.OcclusionLevel=(uint16_t)lv_rand(1,13);;
    currentMachineState.KvoMode=true;
    currentMachineState.KvoRate10=(uint16_t)lv_rand(0,20);;
    currentMachineState.IntermittentInfusionRate10=(uint16_t)lv_rand(0,18000);
    currentMachineState.IntermittentInfusionRateUnit=modeTime;
    currentMachineState.IntermittentDuration=(uint16_t)lv_rand(0,359999); //99:59:59
    currentMachineState.IntermittentBackgroundRate10=modeTime;
    currentMachineState.IntermittentSleep=(uint16_t)lv_rand(0,359999); //99:59:59
    currentMachineState.NurseCall=true;
    currentMachineState.NurseActiveDuration=(uint16_t)lv_rand(0,59);;
    currentMachineState.BolusRate10=(uint16_t)lv_rand(0,18000);
    currentMachineState.BolusMaxVolume10=(uint16_t)lv_rand(0,50);
    currentMachineState.BolusIntervalTime=(uint16_t)lv_rand(0,359999); //99:59:59
    currentMachineState.PurgeRate10=(uint16_t)lv_rand(0,18000);
    currentMachineState.PurgeMaxVolume10=(uint16_t)lv_rand(0,50);
    currentMachineState.PurgeIntervalTime=(uint16_t)lv_rand(0,359999); //99:59:59

    cur_SyringeManufacture=currentMachineState.Syringe.ManufactureIndex;
    cur_SyringeType=currentMachineState.Syringe.TypeIndex;
    cur_Drug=currentMachineState.Drug.Drugindex;
    cur_ModeMode=currentMachineState.Mode.mode;
    cur_ModeUnit=currentMachineState.Mode.unit;

}