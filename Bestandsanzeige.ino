#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 200;
const int colorG = 200;
const int colorB = 200;

void setup() {
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);

    lcd.setRGB(colorR, colorG, colorB);

    // Print a message to the LCD.
    lcd.print("Kaesebroetchen");

    delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  int quantity1 = 1
  lcd.print("\(quantity1)");
}
