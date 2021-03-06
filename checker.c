#include <stdio.h>
#include <assert.h>
#include "checker.h"

int CheckHighTemperatureWarning(float temperature);
int CheckLowTemperatureWarning(float temperature);
int CheckHighSocWarning(float soc);
int CheckLowSocWarning(float soc);
 
  
int IsTemperatureOK(float temperature){
  int TemperatureOK;
  if(temperature < 0 || temperature > 45){
    TemperatureOK = NOTOK;
    }
  else{
     TemperatureOK = OK;
      }   
  return TemperatureOK;
}

int IsTemperatureWarningLevelReached(float temperature){
    int TemperatureWarningLevel;
    if(CheckHighTemperatureWarning){
      TemperatureWarningLevel = HIGH;
      }
  else if (CheckLowTemperatureWarning){
     TemperatureWarningLevel = LOW;
    }  
  else{
  }
  return TemperatureWarningLevel;
  }

int CheckHighTemperatureWarning(float temperature){
  if ((temperature >= 43) && (temperature <= 45)){
    return 1;
    }
}

int CheckLowTemperatureWarning(float temperature){
  if ((temperature >= 0) && (temperature <= 2)){
    return 1;
    }
}

int IsSocOK(float soc){
  int SocOK;
  if(soc < 20 || soc > 80){
    SocOK = NOTOK;
  }
  else{
    SocOK = OK;
 }
}

int IsSocWarningLevelReached(float soc){
    int SocWarningLevel;
    if(CheckHighSocWarning){
      SocWarningLevel = HIGH;
      }
    else if (CheckLowSocWarning){
      SocWarningLevel = LOW;
     }
  else{
  }
    return SocWarningLevel;
  }

int CheckHighSocWarning(float soc){
  if ((soc >= 76) && (soc <= 80)){
    return 1;
    }
}

int CheckLowSocWarning(float soc){
  if ((soc >= 20) && (soc <= 24)){
    return 1;
    }
}

int IsChargRateOK(float chargeRate){
  return(chargeRate < 0.8);
 }
     
void print(char *warningstatementDisplay){
  printf(" %s\n", warningstatementDisplay);
}
   
int batteryIsOk(float tempertaure, float soc, float chargerate, int (*fpIsTemperatureOK)(float),int (*fpIsSocOK)(float),int (*fpIsChargRateOK)(float)){
  int TempStatus = fpIsTemperatureOK(tempertaure);
  int SocStatus  =  fpIsSocOK(soc);
  int ChargeRateStatus =  fpIsChargRateOK(chargerate);
  return (TempStatus && SocStatus && ChargeRateStatus);
}


int main() {
    assert(batteryIsOk(25,70,0.7, &IsTemperatureOK, &IsSocOK, &IsChargRateOK));
    assert(!batteryIsOk(50, 85, 0, &IsTemperatureOK, &IsSocOK, &IsChargRateOK));
    assert(IsTemperatureWarningLevelReached(44) == HIGH);
   // assert(IsTemperatureWarningLevelReached(1) == LOW);
  
    assert(IsSocWarningLevelReached(79) == HIGH);
   // assert(IsSocWarningLevelReached(21) == LOW);
}


