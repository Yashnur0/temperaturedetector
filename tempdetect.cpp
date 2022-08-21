// include the library code:
#include <liquidCrystal.h>
#include "DHT.h"

// set the DHT Pin
#define DHTPIN 8

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 3);
  dht.begin();
  
  // Print a message to the LCD.
  lcd.print("Temp:  Humidity:  Suggestion:");
}

void loop() {
  delay(500);
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 2);
  // read humidity
  float h = dht.readHumidity();
  //read temperature in Fahrenheit
  float f = dht.readTemperature(true);

  float c  dht.readTemperature(true);

  if (f > 70 || c >30){
     cout << "Close window and turn on AC";

  }
  else {
     cout << "Keep windows open";
  }
  return lcd.Suggestion;



  if (isnan(h) || isnan(f) || isnan(c)) {
    lcd.print("ERROR");
    return;
  }

  lcd.print(f);
  lcd.setCursor(10,2);
  lcd.print(c);
  lcd.setCursor(7,1);
  lcd.print(h);  
}