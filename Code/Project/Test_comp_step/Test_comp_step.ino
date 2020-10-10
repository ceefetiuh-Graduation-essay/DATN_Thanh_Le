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
int heading1;


 
void setup() {
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(ENPin, OUTPUT);
  pinMode(MS1,OUTPUT); 
  pinMode(MS2,OUTPUT);
  pinMode(MS3, OUTPUT);
  digitalWrite(ENPin, LOW);
  digitalWrite(MS1, HIGH);
  digitalWrite(MS2, HIGH);
  digitalWrite(MS3, HIGH);

  Serial.begin(9600);
  Wire.begin();
  compass.init();
  compass.enableDefault();
  compass.m_min = (LSM303::vector<int16_t>){ -14,   -506,   -271};
  compass.m_max = (LSM303::vector<int16_t>){ +807,   +322,   +303};
  // Sets the two pins as Outputs
  
}
void loop() 
{ 
   compass.read();
  int heading = compass.heading();
  //round(heading);
  // goc = ( heading - heading1);
   //buoc = map(goc,0,360,0,3200);
  Serial.println(heading);
  delay(400);
  if(heading > heading1)
  {
    goc = 2*(heading - heading1);
    buoc = map(goc,0,360,0,3200);
    Serial.println(heading);
    Serial.print ("\tgoc=");
    Serial.print (goc);
  digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
  for(int x = 0; x < buoc; x++) 
  {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(500); 
  }
  }

  else if(heading < heading1)
  { 
    goc = 2*(heading1-heading);
    buoc = map(goc,0,360,0,3200);
    Serial.println(heading);
    Serial.print ("\tgoc=");
    Serial.print (goc);
    digitalWrite(dirPin,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < buoc; x++) 
  {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(500); 
  }
  }
  else
  {
    Serial.println(heading);
    Serial.print ("\tgoc=");
    Serial.print (goc);
  digitalWrite(ENPin,HIGH);  
  }
  delay(100); // One second delay
  heading1 = heading;
  }
  
