#include <stdio.h>
#include <assert.h>

char* FindTempertaureHIGHORLOW(float temperature);
char* FindSocHIGHORLOW(float soc);

int IsTemperatureOK(float temperature){
  int TemperatureOK;
  if(temperature < 0 || temperature > 45){
    TemperatureOK = 0;
    print(&FindTempertaureHIGHORLOW);
  }
  else{
     TemperatureOK = 1;
      printf("Temperature is in range");
      }
  return TemperatureOK;
}

int IsSocOK(float soc){
  int SocOK;
  if(soc < 20 || soc > 80){
    SocOK = 0;
  }
  else{
    SocOK = 1;
 }
}

int IsChargRateOK(float chargeRate){
  return(chargeRate < 0.8);
 }

char* FindTempertaureHIGHORLOW(float temperature){
  char* TempertaureHIGHORLOW;
  if(temperature < 0){
    TempertaureHIGHORLOW = "LOWTemperature";
    }
  else if(temperature > 45){
   TempertaureHIGHORLOW = "HIGHTemperature";
    }
  return TempertaureHIGHORLOW;
}

char* FindSocHIGHORLOW(float soc){
  char* SocHIGHORLOW;
  if(soc < 20){
      SocHIGHORLOW = "LOWSoc";
   }
  else if(soc > 80){
      SocHIGHORLOW = "HIGHSoc";
   }
  return SocHIGHORLOW;
}

int batteryIsOk(float tempertaure, float soc, float chargerate, int (*fpIsTemperatureOK)(float),int (*fpIsSocOK)(float),int (*fpIsChargRateOK)(float)){
  int TempStatus = fpIsTemperatureOK(tempertaure);
  int SocStatus  =  fpIsSocOK(soc);
  int ChargeRateStatus =  fpIsChargRateOK(chargerate);
  return (TempStatus && SocStatus && ChargeRateStatus);
}

void print(char *(fpdisplaystring)(float)){
  printf("%s", &fpdisplaystring);
  printf("\n");
}

int main() {
    assert(batteryIsOk(25,70,0.7, &IsTemperatureOK, &IsSocOK, &IsChargRateOK));
    assert(!batteryIsOk(50, 85, 0, &IsTemperatureOK, &IsSocOK, &IsChargRateOK));
}


