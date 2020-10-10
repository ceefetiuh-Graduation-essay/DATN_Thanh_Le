
#include <arduino.h>

#define IN1  10
#define IN2  11
#define IN3  12
#define IN4  13
#define MAX_SPEED 255 //từ 0-255
#define MIN_SPEED 0
int count = 0,count1=0;

void pulse()
{
 
    if(digitalRead(4) == LOW)
      count++;
    else
      count--;
}
void pulse1()
{
 
    if(digitalRead(1) == LOW)
      count1++;
    else
      count1--;
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
  analogWrite(IN3, speed);
  digitalWrite(IN4, LOW);
}
void setup()
{
    Serial.begin(9600);
    pinMode(2, INPUT_PULLUP); 
    pinMode(4, INPUT_PULLUP); 
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    //attachInterrupt(0, pulse, LOW); 
    attachInterrupt(0, pulse, FALLING); //Ngắt cạnh xuống
    ///attachInterrupt(1, pulse, FALLING);
}

void loop()
{
    // đoạn chương trình này nhấp nháy led sau 500ms
//    digitalWrite(ledPin, HIGH);
//    delay(50);
//    digitalWrite(ledPin, LOW);
//    delay(50);
    M1_Tien(200);
    M2_Tien(200);
    Serial.print(count);
    Serial.print("\t");
    Serial.print(count1);
    Serial.print("\t");
    Serial.println();
    
        
}   
