
#include <ps2.h>
#include <Wire.h>
#include <LSM303.h>



/***************** DONG CO **********************/
#define IN1  8
#define IN2  9
#define IN3  10
#define IN4  11
#define MAX_SPEED 255 //từ 0-255
#define MIN_SPEED 0

LSM303 compass;
//khai bao
const int stepPin = 44; 
const int dirPin = 46; 
const int ENPin = 44; 
const int MS1 = 52; 
const int MS2 = 50; 
const int MS3 = 48; 
int goc,buoc;
int heading1;
char tempX,tempY;
/*************DONG CO*****************/
void M_Dung()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
 
void M1_Tien(int speed) 
{ //speed: từ 0 - MAX_SPEED
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);//đảm báo giá trị nằm trong một khoảng từ 0 - MAX_SPEED 
  analogWrite(IN1, speed);
  digitalWrite(IN2, LOW);
}
void M2_Tien(int speed) 
{ //speed: từ 0 - MAX_SPEED
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);//đảm báo giá trị nằm trong một khoảng từ 0 - MAX_SPEED 
  digitalWrite(IN3, LOW);
  analogWrite(IN4, speed );
} 
void M1_Lui(int speed)
{
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);//đảm báo giá trị nằm trong một khoảng từ 0 - MAX_SPEED 
  digitalWrite(IN1, LOW);// chân này không có PWM
  analogWrite(IN2, speed);
}
 
void M2_Lui(int speed) 
{
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);//đảm báo giátrị nằm trong một khoảng từ 0 - MAX_SPEED 
  analogWrite(IN4, speed);
  digitalWrite(IN3, HIGH);// chân này không có PWM
}
/**********************ROBOT DI CHUYEN*******************/
void di_thang ()
{
 M1_Tien(87);
 M2_Tien(82); 
}
/******************** BO DOC TOA DO ********************/

PS2 mouse(6,7); // 7-vang-clock, 6 xanh-data

  int16_t mstat;
  int16_t mx,my;
void mouse_init()
{
  mouse.write(0xff);  // reset
  mouse.read();  // ack byte
  mouse.read();  // blank */
  mouse.read();  // blank */
  mouse.write(0xf0);  // remote mode                        
  mouse.read();  // ack
  delayMicroseconds(100);
}
void co_read ()
{
  mouse.write(0xeb);  // give me data!
  mouse.read();      // ignore ack
  mstat = mouse.read();
  mx = mouse.read();
  my = mouse.read();
 if(mx==129)
 tempX--;
 else if(mx==127)
 tempX++;
 if(my==129)
 tempY--;
 else if(my==127)
 tempY++;
}
/**********************Stabilize****************/
void stab()
{
int heading = compass.heading();
  goc=  heading - heading1;
   buoc=map(goc,0,360,0,3200);
  Serial.println(heading);
  delay(100);
  if(heading > heading1)
  {
  digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < buoc; x++) 
  {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(50); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(50); 
  }
  }
  else if(heading < heading1)
  {
    digitalWrite(dirPin,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < buoc; x++) 
  {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(50); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(50); 
  }
  }
  else
  {
  digitalWrite(ENPin,HIGH);  
  }
  delay(10); // One second delay
  heading1=heading;
}
/********* CODE SETUP VA CODE CHINH *************/

void setup()
{
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  mouse_init(); 
  Wire.begin();
  compass.init();
  compass.enableDefault();
  Serial.begin(9600);
  
  compass.m_min = (LSM303::vector<int16_t>){-4096,  -4096,  -4096};
  compass.m_max = (LSM303::vector<int16_t>){ +2025,   +975,  +1747};
  // Sets the two pins as Outputs
  /***********Step Setup***************/ 
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
 
}

void loop()
{
  di_thang();
  co_read();
  compass.read();
  stab();
  Serial.print ("\tX = ");
  Serial.print (tempX,DEC);
  Serial.print ("\tY= ");
  Serial.print (tempY,DEC);
  Serial.println();
  delay(500);
  
 // M_Dung();
 // delay(2000);
}
  
