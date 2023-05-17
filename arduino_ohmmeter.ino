#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int sensorPin = A0;
int sensorValue = 0;
float Vin = 5;    
float Vout = 0;         
float Rref = 1000;       
float R = 0;

void setup()
{
  lcd.begin(16, 2);
  lcd.print("Ohms:");
}

void loop()
{
  sensorValue = analogRead(sensorPin);
  Vout = (Vin * sensorValue) / 1023; 
  R = Rref * (1 / ((Vin / Vout) - 1));
  lcd.setCursor(0, 1);
  lcd.print(R);
  delay(500);
}
