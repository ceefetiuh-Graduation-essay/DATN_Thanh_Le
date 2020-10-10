#include <arduino.h>

#define IN1	9
#define IN2	8
#define IN3	11
#define IN4	10
#define MAX_SPEED 255 //từ 0-255
#define MIN_SPEED 0
void setup()
{
	pinMode(IN1, OUTPUT);
	pinMode(IN2, OUTPUT);
	pinMode(IN3, OUTPUT);
	pinMode(IN4, OUTPUT);
}
 
void motor_1_Dung() {
	digitalWrite(IN1, LOW);
	digitalWrite(IN2, LOW);
}
 
void motor_2_Dung() 
{
	digitalWrite(IN3, LOW);
	digitalWrite(IN4, LOW);
}
 
void motor_1_Tien(int speed) 
{ //speed: từ 0 - MAX_SPEED
	speed = constrain(speed, MIN_SPEED, MAX_SPEED);//đảm báo giá trị nằm trong một khoảng từ 0 - MAX_SPEED 
	digitalWrite(IN1, HIGH);// chân này không có PWM
	analogWrite(IN2, speed);
}
void motor_2_Tien(int speed) 
{      
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);//đảm báo giá trị nằm trong một khoảng từ 0 - MAX_SPEED
  analogWrite(IN3, HIGH);
	digitalWrite(IN4,speed );// chân này không có PWM
}
  
 
 void motor_1_Lui(int speed)
{
	speed = constrain(speed, MIN_SPEED, MAX_SPEED);//đảm báo giá trị nằm trong một khoảng từ 0 - MAX_SPEED 
	digitalWrite(IN1, LOW);// chân này không có PWM
	analogWrite(IN2, speed);
}

void motor_2_Lui(int speed)
{
	speed = constrain(speed, MIN_SPEED, MAX_SPEED);//đảm báo giá trị nằm trong một khoảng từ 0 - MAX_SPEED 
	analogWrite(IN4, 80 - speed);
	digitalWrite(IN3, HIGH);// chân này không có PWM
}
 
void go_round(void)
{
  motor_1_Tien(70);
  motor_2_Tien(40);
 }
 void stop(void)
 {
  motor_1_Dung();
  motor_2_Dung();
  }
 
       
void loop()
{
	//go_round(); // motor 1 tiến
	//delay(1000);//tiến 5 s
  stop();
  delay(500);
 
}
