int tempC;
const int sensorTemp= A0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
tempC = analogRead(sensorTemp);
tempC = tempC*.48828125;
Serial.println(tempC);
}
