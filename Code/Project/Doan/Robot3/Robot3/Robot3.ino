#include <arduino.h>


#define DUONG1 10
#define AM1    11
#define DUONG2 13
#define AM2    12
#define tocdo_MAX 255
#define tocdo_MIN 0

void quay1(int tocdo)
{ tocdo = constrain(tocdo, tocdo_MIN, tocdo_MAX);
  if (tocdo >= 255)
  {
    tocdo = 255;
  }
  if (tocdo <= -255)
  {
    tocdo = -255;
  }
  if (tocdo > 0)
  {
    analogWrite(AM1, 0);
    analogWrite(DUONG1, tocdo);
  }
  if (tocdo < 0)
  {
    analogWrite(DUONG1, 0);
    analogWrite(AM1, - tocdo);
  }
}
void quay2(int tocdo)
{ tocdo = constrain(tocdo, tocdo_MIN, tocdo_MAX);
  if (tocdo >= 255)
  {
    tocdo = 255;
  }
  if (tocdo <= -255)
  {
    tocdo = -255;
  }
  if (tocdo > 0)
  {
    analogWrite(AM2, 0);
    analogWrite(DUONG2, tocdo);
  }
  if (tocdo < 0)
  {
    analogWrite(DUONG2, 0);
    analogWrite(AM2, - tocdo);
  }
}
void setup() 
{// put your setup code here, to run once:
  pinMode(AM1,    OUTPUT);
  pinMode(DUONG1, OUTPUT);
  pinMode(AM2,    OUTPUT);
  pinMode(DUONG2, OUTPUT);
  
}

void loop() 
{ // put your main code here, to run repeatedly:
//quay1(84);
//quay2(77);
//delay(5000);
//quay2(0);
//quay1(0);
//delay(2000);
quay2(100);
quay1(-100);
delay(2000);

}
