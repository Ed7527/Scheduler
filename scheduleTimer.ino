#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

unsigned long timeElapsed = 0;
unsigned long previousTime = 0;

unsigned long secondsDisplay = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(8, INPUT);
  
  lcd.begin(16, 2);
  lcd.print("EdwardTorpy.com");
  lcd.setCursor(0, 1);

}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long millisTime = millis();
  timeElapsed = millisTime - previousTime;
  previousTime = millisTime;

  if(timeElapsed < 1000){
    secondsDisplay++;
    lcd.setCursor(0, 1);
    lcd.print(secondsDisplay);
  }

  if(digitalRead(8) == HIGH){
    secondsDisplay = 0;
  }
}
