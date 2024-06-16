#include "InfusionMode.h"
#include "custom.h"
#include "time.h"
infusionmode_t DefaultModes[6][8]; //6 mode with maximum 8 unit
void loadDefaultInfusionModeValue(void)
{
    for(modeid_t modes=modeVol;modes<modeLinear;modes++)
    {
      for(modeunit_t per=perHour;per<=perMin;per++)
      { 
        for(modeunit_t units=unitMl;units<=unitUnit;units++)
        {
          DefaultModes[modes][per*(unitUnit+1)+units].mode=modes;
          DefaultModes[modes][per*(unitUnit+1)+units].unit=units;
          if(modes==modeTime)
            DefaultModes[modes][per*(unitUnit+1)+units].per=perNone;
          else
            DefaultModes[modes][per*(unitUnit+1)+units].per=per;
          DefaultModes[modes][per*(unitUnit+1)+units].TotalVolume10=(uint16_t)randi(0,18000);
          DefaultModes[modes][per*(unitUnit+1)+units].InfusionRate10=(uint16_t)randi(0,990);
          DefaultModes[modes][per*(unitUnit+1)+units].TotalTime=(time_t)randi(0,36000);
          DefaultModes[modes][per*(unitUnit+1)+units].BodyWeight=(int16_t)randi(0,900);
        }
      }
    }
    // if(modes==modeLinear)
    // {
      
    // }

}