#include <Wire.h> // Library for I2C communication
#include <LiquidCrystal_I2C.h> // Library for LCD
#include <SoftwareSerial.h>
SoftwareSerial toESP(0, 1); //Rx, Tx


#include "HX711.h"
#define DOUT  3
#define CLK  2
HX711 scale(DOUT, CLK);

float weight; 
float calibration_factor = 129640; // for me this value works just perfect 419640 129640
int tonePin = 9;
int fan=4;
// Wiring: SDA pin is connected to A4 and SCL pin to A5.
// Connect to LCD via I2C, default address 0x27 (A0-A2 not jumpered)
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2); // Change to (0x27,16,2) for 16x2 LCD.

void setup() {
    //MOTOR DECLARATION
  
  pinMode(fan,OUTPUT);
   // initialize  communication at 9600 bits per second:
   toESP.begin(9600);
  
  // Initiate the LCD:
  lcd.init();
  lcd.backlight();

   
  scale.set_scale();
  scale.tare(); //Reset the scale to 0
  long zero_factor = scale.read_average(); //Get a baseline reading
 
}

void loop() {

  scale.set_scale(calibration_factor); //Adjust to this calibration factor

  weight = scale.get_units(5); 
  //Serial.print(scale.get_units(), 2);
 // Serial.print(" lbs"); //Change this to kg and re-adjust the calibration factor if you follow SI units like a sane person
  
 // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  delay(1000);

 // Print  on the first line of the LCD:
  lcd.setCursor(0, 0); // Set the cursor on the first column and first row.
  lcd.print("Weight: "); // Print the string "
 lcd.setCursor(8,0);
 lcd.print(String(abs(weight))+" Kg");
 delay(500);
 toESP.println(String(abs(weight)));
  
  if(Serial.available())
  {
    char temp = Serial.read();
    if(temp == '+' || temp == 'a')
      calibration_factor += 10;
    else if(temp == '-' || temp == 'z')
      calibration_factor -= 10;
  }



 
  if (sensorValue>700)
  {
    lcd.setCursor(0, 1); //Set the cursor on the third column and the second row (counting starts at 0!).
    lcd.print("Leakage Detected");
    delay(500);
     toESP.println("leak");
     delay(1000);
      Despacito();  
  }
  else{
    lcd.setCursor(0, 1); //Set the cursor on the third column and the second row (counting starts at 0!).
  lcd.print("No Leakage"); 
  delay(500);
  }
  
lcd.clear();

}


void Despacito() {
  
  tone(tonePin, 587, 709.720327982);
  delay(788.578142202);
  digitalWrite(fan, HIGH);
  delay(10.3082110092);
  tone(tonePin, 554, 709.720327982);
  delay(788.578142202);
  digitalWrite(fan, LOW);
  delay(5.15410550459);
  tone(tonePin, 493, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  digitalWrite(fan, HIGH);
  tone(tonePin, 369, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(tonePin, 369, 134.52215367);
  delay(149.469059633);
  digitalWrite(fan, LOW);
  delay(5.15410550459);
  tone(tonePin, 369, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(tonePin, 369, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(tonePin, 369, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(tonePin, 369, 134.52215367);
  delay(149.469059633);
  digitalWrite(fan, HIGH);
  delay(5.15410550459);
  tone(tonePin, 493, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(tonePin, 493, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(fan, LOW);
  tone(tonePin, 493, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(fan, HIGH);
  tone(tonePin, 493, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(tonePin, 440, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(tonePin, 493, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  digitalWrite(fan, LOW);
  tone(tonePin, 391, 412.843850917);
  delay(458.715389908);
  delay(5.15410550459);
  digitalWrite(fan, HIGH);
  tone(tonePin, 391, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(tonePin, 391, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(fan, LOW);
  tone(tonePin, 391, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(tonePin, 391, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(tonePin, 391, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(tonePin, 493, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(fan, HIGH);
  tone(tonePin, 493, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(tonePin, 493, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(tonePin, 493, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  digitalWrite(fan, LOW);
  tone(tonePin, 554, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(tonePin, 587, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  digitalWrite(fan, HIGH);
  tone(tonePin, 440, 412.843850917);
  delay(458.715389908);
  delay(5.15410550459);
  tone(tonePin, 440, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(tonePin, 440, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(tonePin, 440, 134.52215367);
  delay(149.469059633);
  digitalWrite(fan, LOW);
  delay(5.15410550459);
  tone(tonePin, 440, 41.7482545872);
  delay(46.3869495413);
  delay(36.0787385321);
  tone(tonePin, 440, 37.109559633);
  delay(41.2328440367);
  digitalWrite(fan, HIGH);
  delay(30.9246330275);
  tone(tonePin, 440, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(tonePin, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(tonePin, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(fan, LOW);
  tone(tonePin, 587, 46.3869495413);
  delay(51.5410550459);
  delay(30.9246330275);
  tone(tonePin, 587, 46.3869495413);
  delay(51.5410550459);
  delay(20.6164220183);
  tone(tonePin, 587, 273.683002294);
  delay(304.092224771);
  digitalWrite(fan, HIGH);
  delay(5.15410550459);
  tone(tonePin, 659, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);

  tone(tonePin, 554, 691.165548165);
  delay(767.961720183);
  delay(314.40043578);
  tone(tonePin, 587, 552.004699541);
  delay(613.338555046);
  delay(5.15410550459);
  tone(tonePin, 554, 552.004699541);
  delay(613.338555046);
  delay(5.15410550459);
  digitalWrite(fan, HIGH);
  tone(tonePin, 493, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(tonePin, 369, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(tonePin, 369, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(tonePin, 369, 134.52215367);
  delay(149.469059633);
  digitalWrite(fan, LOW);
  digitalWrite(fan, LOW);
  digitalWrite(fan, LOW);
  digitalWrite(fan, LOW);
  digitalWrite(fan, LOW);
  digitalWrite(fan, LOW); 
 
}
