#include <arduino.h>
#include <Wire.h>
#include <LSM303.h>
LSM303 compass;

const int stepPin = 2; 
const int dirPin = 3; 
const int ENPin = 4; 
const int MS1 = 5; 
const int MS2 = 6; 
const int MS3 = 7; 
int goc,buoc;
int heading1=0;
int chieu;


 
void setup() {
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(ENPin, OUTPUT);
  pinMode(MS1,OUTPUT); 
  pinMode(MS2,OUTPUT);
  pinMode(MS3, OUTPUT);
//  digitalWrite(ENPin, LOW);
  digitalWrite(MS1, HIGH);
  digitalWrite(MS2, HIGH);
  digitalWrite(MS3, LOW);

  Serial.begin(9600);
  Wire.begin();
  compass.init();
  compass.enableDefault();
  compass.m_min = (LSM303::vector<int16_t>){ -627,   -605,   -287};
  compass.m_max = (LSM303::vector<int16_t>){ +301,   +203,   +396};
  // Sets the two pins as Outputs
  
}
void loop() 
{ 
   compass.read();
  int heading = compass.heading();
  if(heading > heading1)
    (chieu=1);
    else if ( heading < heading1)
    (chieu=2);
    else 
    chieu=0;

    switch (chieu)
    {
      case(1): 
      { 
        digitalWrite (ENPin,LOW);
        delay(50);
        goc = heading-heading1;
        buoc = map( goc, 0,359, 0, 1600);
        //Serial.print ("\tgoc = ");
      //  Serial.print(goc);
    //    Serial.println();
        delay(50);
        digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
        for(int x = 0; x < buoc; x++) 
       {
        digitalWrite(stepPin,HIGH); 
        delayMicroseconds(50); 
        digitalWrite(stepPin,LOW); 
        delayMicroseconds(50);
        }
        break;
      }
      case(2):
      {
        digitalWrite (ENPin,LOW);
        delay(50);
        goc = heading1-heading;
        buoc = map( goc, 0,359, 0, 1600);
   //     Serial.print ("\tgoc = ");
     //   Serial.print(goc);
    //    Serial.println();
        delay(50);
        digitalWrite(dirPin,LOW); // Enables the motor to move in a particular direction
        for(int x = 0; x < buoc; x++) 
       {
        digitalWrite(stepPin,HIGH); 
        delayMicroseconds(100); 
        digitalWrite(stepPin,LOW); 
        delayMicroseconds(100);
        }
        break;
      }
      case (0):
      { 
        delay(50);
       // Serial.print ("\tgoc = 0");
        //Serial.print();
     //   Serial.println();
     //   delay(50);
        digitalWrite (ENPin,HIGH);
        break;
      }
    }
    heading1=heading;
}  
  
  /*digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
  for(int x = 0; x < buoc; x++) 
  {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(500); 
  }*/
