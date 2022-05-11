int thermistor = A0;
int leds[] = {2,3,4};

void setup()
{
  pinMode(thermistor, INPUT);
  for (int i = 0; i <= 2; i++)
  {
    pinMode(leds[i], OUTPUT);
  }
  Serial.begin(9600);
}
void loop()
{
  int reading = analogRead(thermistor);
  float Va0 = map(reading, 0, 1023, 0 ,5000)/1000.0;
  float Rt = 10000.0*(5.0/Va0-1.0);
  float Tc = 1.0/(log(Rt/10000.0)/3435.0+1.0/298.15)-273.15;
  Serial.println(Tc);
  pinMode(leds[2], HIGH);
  delay(500);
  pinMode(leds[2], LOW);
  delay(500);
}
