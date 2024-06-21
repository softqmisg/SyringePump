#include "InfusionMode.h"
#include "custom.h"
#include "time.h"
infusionmode_t DefaultModes[6][8]; //6 mode with maximum 8 unit
void loadDefaultInfusionModeValue(void)
{
    for(modeid_t modes=modeVol;modes<=modeLinear;modes++)
    {
        for(uint8_t units=0;units<8;units++)
        {
          DefaultModes[modes][units].mode=modes;
          if(modes==modeLinear)
            DefaultModes[modes][units].unit=units%2;
          else
            DefaultModes[modes][units].unit=units;
          DefaultModes[modes][units].TotalVolume10=(uint16_t)randi(0,18000);
          DefaultModes[modes][units].InfusionRate10=(uint16_t)randi(0,990);
          DefaultModes[modes][units].TotalTime=(time_t)randi(0,36000);
          DefaultModes[modes][units].BodyWeight=(int16_t)randi(0,300);
        }
    }
    // printf("%d\n\r",DefaultModes[2][3].mode);

}