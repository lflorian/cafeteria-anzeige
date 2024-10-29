#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 200;
const int colorG = 200;
const int colorB = 200;

int adcPin = A0; // select the input pin for the potentiometer
int ledPin = A1; // select the pin for the LED
int adcIn = 0;   // variable to store the value coming from the sensor
int previousSchieberegler = 0; // comparison value for adcIn
String printMessage = "Croissant: ";

void setup() {
  Serial.begin(9600); // init serial to 9600b/s
  pinMode(ledPin, OUTPUT); // set ledPin to OUTPUT

  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
  //lcd.print("Hackdays");
  // Print a message to the LCD.
}

void loop() {
  adcIn = analogRead(adcPin);
  int schieberegler = map(adcIn, 0, 1023, 0, 20); 

  //Serial.print(printMessage);
  //Serial.println(schieberegler);
  
  lcd.setCursor(0, 0);
  String leerzeichen = "       ";
  String leer = "keine";
  if (schieberegler > 0){
  lcd.println(printMessage+schieberegler+leerzeichen);
  } else {
  lcd.println(printMessage+leer+leerzeichen);
  }

  if (schieberegler != previousSchieberegler){
  lcd.clear();
  previousSchieberegler = schieberegler;
  //Serial.println("schieberegler changed");
  //Serial.println(previousSchieberegler);
  } else {
  delay(1000);
  //Serial.println("Nothing changed. Refreshing...");
  }
}
