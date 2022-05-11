int tonePosition = 0;
int sensorPin = A0;
int n = 10;
long sum = 0;
float mma = 0;

void setup()
{
  Serial.begin(9600);
  for(int i=0; i<n; i++)
  {
    sum = analogRead(A0);
    mma = mma + sum;
    delay(50);
  }
  mma = mma / n;
}

void loop()
{
  for(int i=0; i<32; i++)
  {
    sum += analogRead(sensorPin);
  }
  sum >>= 5;
  Serial.println(mma);
  mma = ((n-1) * mma + sum) / n;
  delay(50);
}

void serialEvent()
{
  Serial.read();
  if (tonePosition == 0)
  {
    tone(8, 220);
    tonePosition = 1;
  }
  else if (tonePosition == 1)
  {
    noTone(8);
    tonePosition = 0;
  }
}
