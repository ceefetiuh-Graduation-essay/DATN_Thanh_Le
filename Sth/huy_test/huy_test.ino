#include <arduino.h>
#include <ps2.h>
#include <stdint.h>
#include <SoftwareSerial.h>


/***************** DONG CO **********************/
#define IN1  9
#define IN2  8
#define IN3  11
#define IN4  10
#define MAX_SPEED 255 //từ 0-255
#define MIN_SPEED 0

  signed int tempX,tempY;
  //int i;
  SoftwareSerial BT(15, 14); 
  PS2 mouse(7,6); // 7-xanh data (-), 6 vang clock (+)
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
 M1_Tien(43);
 M2_Tien(48); 
}
/******************** BO DOC TOA DO ********************/
void di_lui()
{
M1_Lui(42);
M2_Lui(50);  
}


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
 tempX-=10;
 else if(mx==127)
 tempX+=5;
 else
 tempX=tempX;
 if(my==129)
 tempY-=5;
 else if(my==127)
 tempY+=10;
 else
 tempY=tempY;
}
/********* CODE SETUP VA CODE CHINH *************/

void setup()
{
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  mouse_init();
  BT.begin(9600);
 // BT.println("Bluetooth Connected"); 
}

void loop()
{ 

  di_thang();
  delay(10);
  co_read();
  BT.print (tempX,DEC);
  BT.print(" ");
  BT.print (tempY,DEC);
  BT.println();
 delay(300);
}
  


 

