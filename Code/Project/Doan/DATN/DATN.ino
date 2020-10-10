#include <arduino.h>
#include <ps2.h>
#include <stdint.h>

PS2 mouse(6,7); // 7-vang-clock, 6 xanh-data

  int16_t mstat;
  int16_t mx,my;
  char tempX,tempY;

/***************** DONG CO **********************/
#define IN1  10
#define IN2  11
#define IN3  12
#define IN4  13
#define MAX_SPEED 255 //từ 0-255
#define MIN_SPEED 0

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
/**********************ROBOT DI CHUYEN*******************/
void di_thang ()
{
 M1_Tien(60);
 M2_Tien(55); 
}
/******************** BO DOC TOA DO ********************/

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
/********* CODE SETUP VA CODE CHINH *************/
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mouse_init();  

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  di_thang();
  delay(5000);
  M_dung();
  delay(2000);
}
