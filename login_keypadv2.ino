#include "Keypad.h"
#include <LiquidCrystal.h>

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

int code[3] = {1, 2 ,3};
int code_try[3];

bool Login(){
  bool change = 0;
  
  for (int n = 0; n > 2;) {
    if (keypad.getState() == IDLE || keypad.getState() == RELEASED) {
      change = 1;
    }
    
    if (keypad.getState() == PRESSED && change == 1) {
      change = 0;
      char key = keypad.getKey();      
      code_try[n] = key;
      //Serial.println(code_try[n]);
      lcd.clear();
      lcd.print(code_try[3]);
      n++;
    }
    
    delay(100);
  }
  if (code_try[3] == code[3]){
    code_try[0] = 0;
    code_try[1] = 0;
    code_try[2] = 0;
    return 1;
  }
  else {
    code_try[0] = 0;
    code_try[1] = 0;
    code_try[2] = 0;
    return 0;
  }
}
