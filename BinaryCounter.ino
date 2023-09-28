int pwrLED = 2;
int ledPins[] = {3, 4, 5, 6, 7, 8, 9, 10};

byte count;

void setup(void)
{
    Serial.begin(9600);
    pinMode(pwrLED, OUTPUT);
    digitalWrite(pwrLED, HIGH);
  for (byte i = 0; i < 8; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  count = 0;
}

void loop(void)
{
  Serial.println(count, BIN);
  delay(250);
  dispBinary(count++);
  delay(500);
}

void dispBinary(byte n)
{
  for (byte i = 0; i < 8; i++) {
    digitalWrite(ledPins[i], n & 1);
    n /= 2;
  }
}
