const int stepPin = 2; 
const int dirPin = 3; 
const int ENPin = 4; 
const int MS1 = 5; 
const int MS2 = 6; 
const int MS3 = 7; 
double goc,buoc;

 
void setup() {
  // Sets the two pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(ENPin, OUTPUT);
  pinMode(MS1,OUTPUT); 
  pinMode(MS2,OUTPUT);
  pinMode(MS3, OUTPUT);
  digitalWrite(ENPin, LOW);
  digitalWrite(MS1, HIGH);
  digitalWrite(MS2, HIGH);
  digitalWrite(MS3, LOW);
  goc=0;
  buoc=map(goc,0,360,0,1600);
}
void loop() 
{
  digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < buoc; x++) 
  {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(1500); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(1500); 
  }
  delay(1000); // One second delay
  digitalWrite(dirPin,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < buoc; x++) 
  {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(1500); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(1500); 
  }
  delay(1000); // One second delay
  
  }
