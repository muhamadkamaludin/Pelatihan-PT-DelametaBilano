#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  lcd.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();//Untuk menghapus karakter pada LCD
  lcd.setCursor(6,0);lcd.print(" WOYY ");
  lcd.setCursor(0,1);lcd.print(" MAKANN ");
  delay(3000);

  lcd.clear();//Untuk menghapus karakter pada LCD
  lcd.setCursor(0,0);lcd.print(" AYO ");
  lcd.setCursor(0,1);lcd.print(" GAS ");
  delay(3000);
}
