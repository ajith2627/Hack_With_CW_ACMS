#include <Wire.h> // Library for I2C communication
#include <LiquidCrystal_I2C.h> // Library for LCD

// Wiring: SDA pin is connected to A4 and SCL pin to A5.
// Connect to LCD via I2C, default address 0x27 (A0-A2 not jumpered)
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2); // Change to (0x27,16,2) for 16x2 LCD.

void setup() {
   // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  // Initiate the LCD:
  lcd.init();
  lcd.backlight();
}

void loop() {


 // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  delay(1000);
  // print out the value you read:
  Serial.print(sensorValue);
  Serial.print('\n');
  delay(1000);






  
  // Print  on the first line of the LCD:
  lcd.setCursor(0, 0); // Set the cursor on the first column and first row.
  lcd.print("Weight: "); // Print the string "
  lcd.setCursor(8,0);
  lcd.print(sensorValue);
  if (sensorValue>700)
  {
    lcd.setCursor(0, 1); //Set the cursor on the third column and the second row (counting starts at 0!).
    lcd.print("Leakage Detected");
    delay(1000);
  }
  else{
    lcd.setCursor(0, 1); //Set the cursor on the third column and the second row (counting starts at 0!).
  lcd.print("No Leakage"); 
  delay(1000);
  }
  
lcd.clear();

}
