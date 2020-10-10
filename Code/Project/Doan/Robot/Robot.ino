#include <arduino.h>
#include <ps2.h>

#define IN2	8
#define IN1 9
#define IN4	10
#define IN3	11
#define MAX_SPEED 255 //từ 0-255
#define MIN_SPEED 0

char tempX,tempY;
int16_t mstat;
int16_t mx,my;
PS2 mouse(6,7); // 7-vang-clock, 6 xanh-data
void setup()
{
	pinMode(IN1, OUTPUT);
	pinMode(IN2, OUTPUT);
	pinMode(IN3, OUTPUT);
	pinMode(IN4, OUTPUT);
   Serial.begin(9600);
 // mouse_init(); 
}
 
void motor_Dung() {
	digitalWrite(IN1, LOW);
	digitalWrite(IN2, LOW);
	digitalWrite(IN3, LOW);
	digitalWrite(IN4, LOW);
}
 
void motor_1_Tien(int speed) 
{ //speed: từ 0 - MAX_SPEED
	speed = constrain(speed, MIN_SPEED, MAX_SPEED);//đảm báo giá trị nằm trong một khoảng từ 0 - MAX_SPEED 
	analogWrite(IN1, speed);
	digitalWrite(IN2, LOW);
}
void motor_2_Tien(int speed) { //speed: từ 0 - MAX_SPEED
	speed = constrain(speed, MIN_SPEED, MAX_SPEED);//đảm báo giá trị nằm trong một khoảng từ 0 - MAX_SPEED 
	digitalWrite(IN3, LOW);
	analogWrite(IN4, speed );
} 
void motor_1_Lui(int speed) {
	speed = constrain(speed, MIN_SPEED, MAX_SPEED);//đảm báo giá trị nằm trong một khoảng từ 0 - MAX_SPEED 
	digitalWrite(IN1, LOW);// chân này không có PWM
	analogWrite(IN2, speed);
}
 
void motor_2_Lui(int speed) {
	speed = constrain(speed, MIN_SPEED, MAX_SPEED);//đảm báo giátrị nằm trong một khoảng từ 0 - MAX_SPEED 
	analogWrite(IN4, speed);
	digitalWrite(IN3, HIGH);// chân này không có PWM
}

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
 
 void go_round_right(void)
 {
        motor_1_Tien(45); // motor 1 tiến
	motor_2_Tien(72); //motor 2 tiến
 }
 void go_round_left(void)
 {
        motor_1_Tien(80); // motor 1 tiến
	motor_2_Tien(58); //motor 2 tiến
 }
 
 void go_straight(void)
 {
       motor_1_Tien(87);
       motor_2_Tien(82);
       
 }
 void go_buff()
 {
       motor_1_Tien(100);
       motor_2_Tien(95);
       
  }
 void turn_right()
 {
       motor_1_Lui(100);
       motor_2_Tien(100);
 }
 void turn_left() 
 {
       motor_1_Tien(54);
       motor_2_Tien(0);
 }
 void square()
 {
        go_straight(); // motor 1 tiến
        delay(7000);
	      turn_right();
        delay(2550);
        motor_Dung();
        delay(500);
 }
void loop()
{
        go_round_left();
        delay(2500);
       
        /*go_straight();
        delay(4000);
        turn_right();
        delay(2550);
        motor_Dung();
        delay(500); */
        	 
}
