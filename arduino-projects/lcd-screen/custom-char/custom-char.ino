#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

byte hieroglyph[8] = 
{
    0b11111,
    0b00000,
    0b11111,
    0b10001,
    0b10001,
    0b10101,
    0b10111,
    0b00000
};

int value = 0;

void setup() 
{
    Serial.begin(9600);
    lcd.begin(16, 2);
    #if 1
    lcd.createChar(0, hieroglyph);
    #endif
}

void loop() 
{
  if (Serial.available() > 0) 
  {
    value = Serial.parseInt();
    lcd.clear();
    if (value <= 15)
    {
      Serial.println(value);
      lcd.setCursor(value, 0);
      lcd.write((unsigned char)0);
    }
    else if (value >= 15)
    {
      if (value > 31)
      {
        Serial.println(value);
        lcd.setCursor(0, 0);
        lcd.write("Warning:");
        lcd.setCursor(0, 1);
        lcd.write("OutOfBounds");
      }
      else
      {
        Serial.println(value);
        lcd.setCursor(value - 16, 1);
        lcd.write((unsigned char)0);
      }
    }
  }
}
