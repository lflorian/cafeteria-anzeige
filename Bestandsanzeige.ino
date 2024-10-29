#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 200;
const int colorG = 200;
const int colorB = 200;

int adc1Pin = A0; // select the input pin for the potentiometer
int adc2Pin = A1;
int ledPin = A1; // select the pin for the LED
int adc1In = 0;   // variable to store the value coming from the sensor
int adc2In = 0;   // variable to store the value coming from the sensor
int previousQuantitySelector = 0; // comparison value for adc1In
int previousProductSelector = 0; // comparison value for adc2In
String leerzeichen = "       ";
String leer = "keine";

struct Product {
  String ProductName;
  int quantity;
};

Product products[] = {
  {"Croissants: ", 20},
  {"Hotdogs: ", 20}
};

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
  delay(500);
  lcd.clear();

  Serial.begin(9600); // init serial to 9600b/s
  pinMode(ledPin, OUTPUT); // set ledPin to OUTPUT
  lcd.clear();
}

void loop() {
  adc1In = analogRead(adc1Pin);
  adc2In = analogRead(adc2Pin);
  int QuantitySelector = map(adc1In, 0, 1023, 0, 20);
  int ProductSelector = map(adc2In, 0, 950, 1, 2);
  //Serial.println(ProductSelector);

  //Serial.print(printMessage);
  //Serial.println(Anzahl);

  lcd.setCursor(0, 0);

  if (ProductSelector == 1) {
    lcd.clear();
    lcd.println(products[0].ProductName+String(products[0].quantity)+leerzeichen);
    }
    
  if (ProductSelector == 2) {
    lcd.clear();
    lcd.println(products[1].ProductName+String(products[1].quantity)+leerzeichen);
    }
    

  if (QuantitySelector != previousQuantitySelector) {
    lcd.clear();
    if (ProductSelector == 1) {
      products[0].quantity = QuantitySelector;
      Serial.println(QuantitySelector);
      }

    if (ProductSelector == 2) {
      products[1].quantity = QuantitySelector;
      Serial.print("if2");
      Serial.println(QuantitySelector);
      }

    previousQuantitySelector = QuantitySelector;
    Serial.println("QuantitySelector changed");
  } else {
    delay(1000);
    Serial.println("Nothing changed. Refreshing...");
  }
}
