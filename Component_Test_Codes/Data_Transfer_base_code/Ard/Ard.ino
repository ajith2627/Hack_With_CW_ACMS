#include <SoftwareSerial.h>

SoftwareSerial toESP(0, 1); //Rx, Tx

void setup()
{

  toESP.begin(9600);
}

void loop()
{
  String w="Leakage Detected";
  
  toESP.println(String(w));
  delay(2000);
  }
   
