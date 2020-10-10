#include <SoftwareSerial.h>// import the serial library
#include <String.h>
SoftwareSerial BT(15, 14); // RX, TX

int i;

void setup() {
 // put your setup code here, to run once:
 BT.begin(9600);
 BT.println("Bluetooth Connected");
}
void loop() {

 // put your main code here, to run repeatedly:
 
 
 for(i = 0; i < 100; i++)
 BT.println(i);
 
delay(10000);// prepare for next data ...
}


