#include <SoftwareSerial.h>

int counter = 0;

int rxPin = 19;
int txPin = 18;
SoftwareSerial bluetooth(rxPin, txPin);

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600); //set baud rate
}

void loop() {
  counter++;
  bluetooth.print("Arduino counter: ");
  bluetooth.println(counter);
  delay(500); // wait half a sec
}
