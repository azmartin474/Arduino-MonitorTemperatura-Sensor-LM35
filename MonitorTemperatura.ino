#include <LiquidCrystal.h>
int tempC;
const int sensorTemp= A0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  // put your main code here, to run repeatedly:
tempC = analogRead(sensorTemp);
tempC = tempC*.48828125;
Serial.println(tempC);
lcd.setCursor(0,0);
lcd.print("Temperatura:");
lcd.setCursor(0,1);
lcd.print(tempC);
delay(500);
}
