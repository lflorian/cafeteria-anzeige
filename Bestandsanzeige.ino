#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 200;
const int colorG = 200;
const int colorB = 200;

int adcPin = A0; // select the input pin for the potentiometer
int ledPin = A1; // select the pin for the LED
int adcIn = 0;   // variable to store the value coming from the sensor
int previousQuantitySelector = 0; // comparison value for adcIn
String ProductName1 = "Croissant: ";
String ProductName2 = "Hotdog: ";

void setup() {
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
  lcd.println("Starting .          ");
  delay(500);
  lcd.clear();
  lcd.println("Starting ..          ");
  delay(500);
  lcd.clear();
  lcd.println("Starting ...          ");
  delay(2000);
  lcd.clear();
  
  Serial.begin(9600); // init serial to 9600b/s
  pinMode(ledPin, OUTPUT); // set ledPin to OUTPUT
  lcd.clear();
}

void loop() {
  adcIn = analogRead(adcPin);
  int QuantitySelector = map(adcIn, 0, 1023, 0, 20); 

  //Serial.print(printMessage);
  //Serial.println(Anzahl);
  
  lcd.setCursor(0, 0);
  String leerzeichen = "       ";
  String leer = "keine";
  if (QuantitySelector > 0){
  lcd.println(ProductName1+QuantitySelector+leerzeichen);
  } else {
  lcd.println(ProductName1+leer+leerzeichen);
  }

  if (QuantitySelector != previousQuantitySelector){
  lcd.clear();
  previousQuantitySelector = QuantitySelector;
  //Serial.println("QuantitySelector changed");
  //Serial.println(previousQuantitySelector);
  } else {
  delay(1000);
  //Serial.println("Nothing changed. Refreshing...");
  }
}
