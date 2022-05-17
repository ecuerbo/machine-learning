#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 6, 5, 4, 3,2);

int sensorPin = A0;
int sensorValue = 0;
int percentValue = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {

  sensorValue = analogRead(sensorPin);
  Serial.print("\n\nAnalog Value: ");
  Serial.print(sensorValue);
  
  percentValue = map(sensorValue, 1023, 200, 0, 100);
  Serial.print("\nPercentValue: ");
  Serial.print(percentValue);
  Serial.print("%");
  lcd.setCursor(0, 0);
  lcd.print("Soil Moisture");
  
  lcd.setCursor(0, 1);  
  lcd.print("Percent: ");
  lcd.print(percentValue);
  lcd.print("%");
  delay(1000);
  lcd.clear();
}
