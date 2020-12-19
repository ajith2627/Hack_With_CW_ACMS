#include <Wire.h> // Library for I2C communication
#include <LiquidCrystal_I2C.h> // Library for LCD

#include "HX711.h"
#define DOUT  3
#define CLK  2
HX711 scale(DOUT, CLK);

float weight; 
float calibration_factor = 129640; // for me this value works just perfect 419640 129640

// Wiring: SDA pin is connected to A4 and SCL pin to A5.
// Connect to LCD via I2C, default address 0x27 (A0-A2 not jumpered)
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2); // Change to (0x27,16,2) for 16x2 LCD.

void setup() {
   // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  // Initiate the LCD:
  lcd.init();
  lcd.backlight();

   Serial.println("HX711 calibration sketch");
  Serial.println("Remove all weight from scale");
  Serial.println("After readings begin, place known weight on scale");
  Serial.println("Press + or a to increase calibration factor");
  Serial.println("Press - or z to decrease calibration factor");
  scale.set_scale();
  scale.tare(); //Reset the scale to 0
  long zero_factor = scale.read_average(); //Get a baseline reading
 
}

void loop() {

  scale.set_scale(calibration_factor); //Adjust to this calibration factor
  Serial.print("Reading: ");
  weight = scale.get_units(5); 
  //Serial.print(scale.get_units(), 2);
 // Serial.print(" lbs"); //Change this to kg and re-adjust the calibration factor if you follow SI units like a sane person
  


 // Print  on the first line of the LCD:
  lcd.setCursor(0, 0); // Set the cursor on the first column and first row.
  lcd.print("Weight: "); // Print the string "
 lcd.setCursor(8,0);
  lcd.print(abs(weight));


  
  if(Serial.available())
  {
    char temp = Serial.read();
    if(temp == '+' || temp == 'a')
      calibration_factor += 10;
    else if(temp == '-' || temp == 'z')
      calibration_factor -= 10;
  }








 // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  delay(1000);
  // print out the value you read:
  Serial.print(sensorValue);
  Serial.print('\n');
  delay(700);



 
  if (sensorValue>700)
  {
    lcd.setCursor(0, 1); //Set the cursor on the third column and the second row (counting starts at 0!).
    lcd.print("Leakage Detected");
    delay(500);
  }
  else{
    lcd.setCursor(0, 1); //Set the cursor on the third column and the second row (counting starts at 0!).
  lcd.print("No Leakage"); 
  delay(500);
  }
  
lcd.clear();

}
