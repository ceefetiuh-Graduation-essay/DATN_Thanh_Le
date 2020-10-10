#define IN1  10
#define IN2  11
#define IN3  12
#define IN4  13
#define MAX_SPEED 255 //từ 0-255
#define MIN_SPEED 0
#define BAUD (9600)
int x; 

float buoc;
float goc;
  //char tempX,tempY;
  
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
 M2_Tien(60); 
}
void stp ()
{
    goc = 45;
  buoc = map(goc, 0,360,0,1600);
  //digitalWrite(22,LOW); // Đặt Enable ở trạng thái LOW
  digitalWrite(24,HIGH); // Đặt Dir  ở trạng thái HIGH
  //Serial.println("Cho chay 200 steps (1 vong)");
  for(x = 0; x < buoc; x++) // Cho chay 1 vong
  {
    digitalWrite(26,HIGH); // Output high
    delay(10); // chờ
    digitalWrite(26,LOW); // Output low
    delay(10); // chờ
  }
  }

void setup() {
  // put your setup code here, to run once:
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
 // Serial.begin(9600);
  Serial.begin(BAUD);
  pinMode(22,OUTPUT); // Enable pin - chân khởi động - nối vào GND sẽ giúp ta bật động cơ bước, nối vô VCC động cơ bước được thả ra. Nôm na: GND = servo.attach, VCC = servo.detach
  pinMode(24,OUTPUT); // Step pin
  pinMode(26,OUTPUT); // Dir - pin
  pinMode(28,OUTPUT); //MS3
  pinMode(30,OUTPUT);//MS2
  pinMode(32,OUTPUT); //MS1
  digitalWrite(22,LOW); // Set Enable low
  digitalWrite(28,LOW);
  digitalWrite(30,HIGH);
  digitalWrite(32,HIGH);
   
}

void loop() {
  // put your main code here, to run repeatedly:
 di_thang();
 stp();
 
}
