#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int lectura;
float voltaje;
float temperatura;

const int sensorTemp = A0;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
}

void loop() {

  // Leer el TMP36
  lectura = analogRead(sensorTemp);

  // Convertir la lectura a voltaje
  voltaje = lectura * (5.0 / 1023.0);

  // Convertir voltaje a temperatura
  temperatura = (voltaje - 0.5) * 100.0;

  // Monitor Serial
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" C");

  // LCD
  lcd.setCursor(0, 0);
  lcd.print("Temperatura:");

  lcd.setCursor(0, 1);
  lcd.print("                "); // Limpia la línea

  lcd.setCursor(0, 1);
  lcd.print((int)temperatura);
  lcd.print((char)223);
  lcd.print("C");

  delay(500);
}
