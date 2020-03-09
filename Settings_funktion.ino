void Settings() {
  for (int n = 0; n > 2; n++){
    if (Login() == 1){
      lcd.clear();
      lcd.print("1 for code change");
      lcd.setCursor(0,1);
      lcd.print("2 for lcd settings, 3 ->");
      char key = keypad.getKey();
      if (key == "1") {
        // Code change
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("New code:");
        lcd.setCursor(0,1);
        lcd.print(key)
      }
      if (key == "2") {
        // LCD Settings
        lcd.clear();
        lcd.print("1 for brightness")
        if (key == "1") {
          lcd.clear();
          lcd.print("press 8 for higher");
          lcd.setCursor(0,1);
          lcd.print("press 2 for lower");
        }
      }
      if (key == "3") {
        // Next page
      }
      if (key == "4") {
        // Exit
        break;
      }
      
    }
    else{
      continue;
    }
  }
}
