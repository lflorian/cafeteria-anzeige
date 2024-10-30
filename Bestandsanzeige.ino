#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

//Pin Initialization
int adc1Pin = A0; // input pin for potentiometer
int adc2Pin = A2;
int LED1Pin = A1; // input pin for LED
int LED2Pin = A3;
int adc1In = 0;   // store the value coming from sensor
int adc2In = 0;
int previousQuantitySelector = 0; // comparison value for adc1In
int previousProductSelector = 0;
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
  //Startup Screen
  lcd.begin(16, 2);
  lcd.setRGB(200, 200, 200);
  lcd.println("Starting .          ");
  delay(250);
  lcd.clear();
  lcd.println("Starting ..          ");
  delay(250);
  lcd.clear();
  lcd.println("Starting ...          ");
  delay(250);
  lcd.clear();
  refreshDisplay();

  //LED Initalization
  pinMode(LED2Pin, OUTPUT); // set ledPin to OUTPUT
  pinMode(LED1Pin, OUTPUT); // set ledPin to OUTPUT

  //Debug
  Serial.begin(9600); // init serial to 9600b/s
  lcd.clear();
}

void refreshDisplay() {
  Serial.println("Refresh Display");
  lcd.clear();

  if ( products[0].quantity == 0 ) {
    lcd.setCursor(0, 0);
    lcd.println("Croissants:keine" + leerzeichen);
  } else {
    lcd.setCursor(0, 0);
    lcd.println(products[0].ProductName + String(products[0].quantity) + leerzeichen);
  }

  if ( products[1].quantity == 0 ) {
    lcd.setCursor(0, 1);
    lcd.println("Hotdogs: keine" + leerzeichen);
  } else {
    lcd.setCursor(0, 1);
    lcd.println(products[1].ProductName + String(products[1].quantity) + leerzeichen);
  }

  if (products[0].quantity == 0 || products[1].quantity == 0) {
    lcd.setRGB(250, 0, 0);
  } else {
    lcd.setRGB(200, 200, 200);
  }
}


void loop() {
  //Slider Mapping
  adc1In = analogRead(adc1Pin);
  adc2In = analogRead(adc2Pin);
  int QuantitySelector = map(adc1In, 30, 1023, 0, 20);
  int ProductSelector = map(adc2In, 0, 950, 0, 1);

  //Refresh Display when value changes
  if (QuantitySelector != previousQuantitySelector) {
    products[ProductSelector].quantity = QuantitySelector;
    refreshDisplay();
    previousQuantitySelector = QuantitySelector;
    Serial.println("QuantitySelector changed");
  } else {
    delay(500);
    Serial.println("Nothing changed. Refreshing...");
  }
}
