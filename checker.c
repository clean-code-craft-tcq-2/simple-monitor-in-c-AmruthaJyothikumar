#include <stdio.h>
#include <assert.h>

bool IsTemperatureOK(float temperature){
  bool TemperatureOK;
  char* TempertaureHIGHORLOW;
  if(temperature < 0 || temperature > 45){
    TemperatureOK = 0;
    TempertaureHIGHORLOW = FindTempertaureHIGHORLOW();
    print(TempertaureHIGHORLOW);
  }
  else{
     TemperatureOK = 1;
      printf("Temperature is inrange");
  }
  return TemperatureOK;
}

bool IsSocOK(float soc){
  bool SocOK;
  char* SocHIGHORLOW;
  if(soc < 20 || soc > 80){
    SocOK = 0;
    SocHIGHORLOW = FindSocHIGHORLOW();
    print(FindSocHIGHORLOW);
  }
  else{
    SocOK = 1;
    printf("Soc is inrange");
 }

bool IsChargRateOK(float chargeRate){
  return(chargeRate < 0.8)
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

int batteryIsOk(IsTemperatureOK,IsSocOK,IsChargRateOK){
  int IsBatteryOK;
  if(IsTemperatureOK & IsSocOK & IsChargRateOK){
    IsBatteryOK = 1; 
  }
  else{
    IsBatteryOK = 0;
  }
  return IsBatteryOK;
}

void print(char *displaystring ){
  printf(displaystring);
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
