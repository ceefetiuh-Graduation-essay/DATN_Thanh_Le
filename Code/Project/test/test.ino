#include <arduino.h>
#include <ps2.h>
#include <stdint.h>
#include <SoftwareSerial.h>


 
    
 PS2 mouse(7,6); // 7-vang-clock, 6 xanh-data

  char tempX,tempY;
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

void setup()
{
  mouse_init();
  BT.begin(9600);
  BT.println("Bluetooth Connected");
}
void loop()
{
  co_read();
  BT.print ("\tX = ");
  BT.print (tempX ,DEC);
  BT.println();
  BT.print ("\tY= ");
  BT.print (tempY,DEC);
  BT.println();
  BT.println();
  delay(1000);
  
 }
