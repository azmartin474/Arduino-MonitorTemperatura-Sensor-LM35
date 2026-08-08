//Bibliotecas
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int tempC;
const int sensorTemp= A0;
LiquidCrystal_I2C lcd(0x27, 16, 2);
//0x27 es la dirección I2C (la más común).
//16, 2 indica que la pantalla es de 16 columnas y 2 filas.

void setup() {
  // inicialización
lcd.init();
lcd.backlight();
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
delay(1000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Temperature:");
lcd.setCursor(0,1);
lcd.print(tempC);
delay(1000);
lcd.clear();
}
