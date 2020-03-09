void Information() {
  lcd.clear();
  delay(100);
  lcd.print("(1) temp, (2) hum");
  lcd.setCursor(0,1);
  lcd.print("(3) amb light, (4)->");

  if (key == "1") {
    lcd.clear();
    delay(100);
    lcd.print("The temperature is: ");
    lcd.setCursor(5, 1);
    lcd.print(t, " C")
  }
  if (key == "2") {
    lcd.clear();
    delay(100);
    lcd.print("The humidity is: ");
    lcd.setCursor(5, 1);
    lcd.print(h, "%");
  }
  if (key == "3") {
    lcd.clear();
    delay(100);
    lcd.print("The ambient light is: ");
    lcd.setCursor(5, 1);
    lcd.print(amb_light);
  }
  if (key == "4") {
    lcd.clear();
    delay(100);
    lcd.print("(1) gas, (2) UNKOWN");
    lcd.setCursor(0,1);
    lcd.print("(3) UNKNOWN, (4)->");

    if (key == "1") {
      lcd.clear();
      delay(100);
      lcd.print("The gas Value is: ");
      lcd.setCursor(5,1);
      lcd.print(gas_value);
    }
    
  if (key == "0") {
    break;
  }
}
