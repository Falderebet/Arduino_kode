#include "Keypad.h"
#include <LiquidCrystal.h>
// #include <DHT.h>
// #include <DHT_U.h>
// #define dht_pin 2
// #define AL_sensor A0
// #define BUZZ A1
// DHT dht(dht_pin, DHT11);
LiquidCrystal lcd(22, 23, 27, 26, 25, 24);

const byte ROWS = 4;
const byte COLS = 3;
byte rowPins[ROWS] = {42, 44, 46, 48};
byte colPins[COLS] = {36, 38, 40};
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  lcd.begin(16,2);
}

void loop() {
  float t = dht.readTemperature();
  char key = keypad.getKey();
  int AL_val = analogRead(AL_sensor);
  lcd.print("Vælg lys eller temp");
  lcd.setCursor(0,1);
  lcd.print("1 for L, 2 for T");
  int x = key;
  if (x == 49){
    lcd.clear();
    lcd.print(t);
    delay(3000);
    lcd.clear();
    if (t > 31){
      analogWrite(BUZZ, 255);
    }
    if (27 < t < 31){
      analogWrite(BUZZ, 100);
    }
    if (t < 27){
      analogWrite(BUZZ, 0);
    }
  }
  if (x == 50){
    lcd.clear();
    lcd.print(AL_val);
    if (AL_val > 500){
      analogWrite(BUZZ, 0);
    }
    delay(3000);
    lcd.clear();
  }
}
