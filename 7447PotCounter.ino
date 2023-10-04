int potPin = A0;
int binPins[] = {2, 3, 4, 5}; // Digital Output Pins for Count

byte count; // Sets Count Variable as a Byte Count

void setup(void)
{
    Serial.begin(9600); // Begins Serial Call
  for (byte i = 0; i < 4; i++) {
    pinMode(binPins[i], OUTPUT); // Sets Digital Pins for Output
  }
  count = 0; // Counter
}

void loop(void)
{
  
  int A5Val = analogRead(potPin); // Voltage Across Potentiometer
  float Voltage = A5Val * (5.0 / 1023.0); // Converts Read Data To Correct Voltage
  int timeDelay = Voltage * (100.0);
  dispBinary(count++);
  delay(timeDelay);
}

void dispBinary(byte n)
{
  for (byte i = 0; i < 4; i++) {
    digitalWrite(binPins[i], n & 1); // Adds 1 to Binary Value
    n /= 2; // Insures Count never ='s 2
  }
}
