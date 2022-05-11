#define ROTARY_ANGLE_SENSOR A0
#define ADC_REF 5
#define GROVE_VCC 5
#define FULL_ANGLE 300

#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

void setup() 
{
  Serial.begin(9600);
    lcd.begin(16, 2);
    pinMode(ROTARY_ANGLE_SENSOR, INPUT);
}

void loop() 
{
  int r = 0;
  int g = 0;
  int b = 0;
  float voltage;
  int sensor_value = analogRead(ROTARY_ANGLE_SENSOR);
  voltage = (float)sensor_value*ADC_REF/1023;
  float degrees = (voltage*FULL_ANGLE)/GROVE_VCC;
  lcd.clear();
  lcd.print(degrees);

  if (degrees <= 100)
  {
    float i = degrees / 100.0;
    float color = (1 - i) * 255;
    float colorShade = i * 255;
    lcd.setRGB(r, colorShade * .5, color);
  }
  else if (degrees <= 200)
  {
    degrees = degrees - 100;
    float i = degrees / 100.0;
    float colorShade = (1 - i) * 255;
    float color = i * 255;
    lcd.setRGB(r, color, colorShade * .25);
  }
  else if (degrees <= 300)
  {
    degrees = degrees - 200;
    float i = degrees / 100.0;
    float color = i * 255;
    float colorShade = (1 - i) * 255;
    lcd.setRGB(color, colorShade * .5, b);
  }
  delay(1000);
}
