#include<LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16 , 2);
int sensorPin = A0;

void setup() {
  Serial.begin(9600);
  lcd.clear();
  lcd.init();
  lcd.backlight();

}

void loop() {
  int value = analogRead(sensorPin);
  double voltage = map(value,0,1024,0,2500);
  voltage /= 100;
  lcd.setCursor(0,0);
  lcd.print("Solar Panel is");
  lcd.setCursor(0,1);
  lcd.print("Generating:");
  lcd.setCursor(11,1);
  lcd.print(voltage);
  lcd.setCursor(15,1);
  lcd.print("V");
  delay(1000);
  
  Serial.print("Voltage:");
  Serial.println(voltage);
}
