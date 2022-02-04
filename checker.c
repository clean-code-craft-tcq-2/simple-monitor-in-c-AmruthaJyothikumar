#include <stdio.h>
#include <assert.h>

bool IsTemperatureOK(float temperature){
  return(temperature < 0 || temperature > 45)
 }

bool IsSocOK(float soc){
  return(soc < 20 || soc > 80) 
 }

bool IsChargRateOK(float chargeRate){
  return(chargeRate > 0.8)
 }

int batteryIsOk(IsTemperatureOK,IsSocOK,IsChargRateOK){
  if(IsTemperatureOK & IsSocOK & IsChargRateOK){
    return 1;
  }
  else{
    return 0;
  }
}
  

int batteryIsOk(float temperature, float soc, float chargeRate) {
  if(temperature < 0 || temperature > 45) {
    printf("Temperature out of range!\n");
    return 0;
  } else if(soc < 20 || soc > 80) {
    printf("State of Charge out of range!\n");
    return 0;
  } else if(chargeRate > 0.8) {
    printf("Charge Rate out of range!\n");
    return 0;
  }
  return 1;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
