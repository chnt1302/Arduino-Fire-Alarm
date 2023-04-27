#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

LiquidCrystal_I2C lcd(0x27,16,2);
DHT dht_2_DHT11(2,DHT11);
void setup(){
  pinMode(4,OUTPUT);
  pinMode(12,OUTPUT);
  lcd.begin();
  lcd.backlight();
  lcd.noCursor();
  lcd.noBlink();
  
  dht_2_DHT11.begin();   
  }

void loop() {
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print((String("Temp : ") + String((int)(dht_2_DHT11.readTemperature())) + String(" *c")));
  if(dht_2_DHT11.readTemperature()>30){
    lcd.setCursor(2,3);
    lcd.print((String("DANGER FIRE!!")));
    tone(12,200);
    digitalWrite(4,HIGH);
    delay(700);
    digitalWrite(4,LOW);
    delay(700);
  }
  else{
    lcd.setCursor(2,3);
    lcd.print((String("IT'S SAFE NOW")));
    digitalWrite(4,LOW);
    noTone(12);
  }
}
