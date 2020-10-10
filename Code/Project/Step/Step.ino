// Run a A4998 Stepstick from an Arduino UNO.
// Paul Hurley Aug 2015 - http://www.instructables.com/id/Drive-a-Stepper-Motor-with-an-Arduino-and-a-A4988-/
int x; 
#define BAUD (9600)
const int stepPin = 2; 
const int dirPin = 3; 
const int ENPin = 4; 
const int MS1 = 5; 
const int MS2 = 6; 
const int MS3 = 7; 
int goc,buoc;

void setup() 
{
  Serial.begin(BAUD);
  pinMode(stepPin,OUTPUT); // Enable pin - chân khởi động - nối vào GND sẽ giúp ta bật động cơ bước, nối vô VCC động cơ bước được thả ra. Nôm na: GND = servo.attach, VCC = servo.detach
  pinMode(dirPin,OUTPUT); // Step pin
  pinMode(ENPin,OUTPUT); // Dir - pin
  pinMode(MS1,OUTPUT); //MS3
   pinMode(MS2,OUTPUT);//MS2
    pinMode(MS3,OUTPUT); //MS1
  digitalWrite(ENPin,LOW); // Set Enable low
  digitalWrite(MS1,HIGH);
  digitalWrite(MS2,HIGH);
  digitalWrite(MS3,HIGH);
   
  
}

void loop() 
{ 
  goc = 90;
  buoc = map(goc, 0,360,0,3200);
  //digitalWrite(22,LOW); // Đặt Enable ở trạng thái LOW
  digitalWrite(dirPin,HIGH); // Đặt Dir  ở trạng thái HIGH
  Serial.println("Cho chay 200 steps (1 vong)");
  for(x = 0; x < buoc; x++) // Cho chay 1 vong
  {
    digitalWrite(stepPin,HIGH); // Output high
    delay(10); // chờ
    digitalWrite(stepPin,LOW); // Output low
    delay(10); // chờ
  }
 // Serial.println("Pause");
 // delay(2000); // dừng 1 s rồi quay tiếp
}
