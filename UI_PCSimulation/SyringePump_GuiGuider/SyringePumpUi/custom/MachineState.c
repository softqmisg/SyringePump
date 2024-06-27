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
    currentMachineState.OcclusionLevel=5;
    currentMachineState.KvoMode=true;
    currentMachineState.KvoRate10=15;
    currentMachineState.IntermittentInfusionRate10=60;
    currentMachineState.IntermittentInfusionRateUnit=1;
    currentMachineState.IntermittentDuration=(0*3600)+(2*60)+27;
    currentMachineState.IntermittentBackgroundRate10=2;
    currentMachineState.IntermittentSleep=(0*3600)+(0*60)+0;

    cur_SyringeManufacture=currentMachineState.Syringe.ManufactureIndex;
    cur_SyringeType=currentMachineState.Syringe.TypeIndex;
    cur_Drug=currentMachineState.Drug.Drugindex;
    cur_ModeMode=currentMachineState.Mode.mode;
    cur_ModeUnit=currentMachineState.Mode.unit;

}