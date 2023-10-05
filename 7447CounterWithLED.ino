int potPin = A0;
int binPins[] = {2, 3, 4, 5}; // Digital Output Pins for Count
int LED1[] = {6, 7, 8};
int LED2[] = {9, 10, 11};

byte count; // Sets Count Variable as a Byte Count

void setup(void)
{
    Serial.begin(9600); // Begins Serial Call
    
  for(byte i = 0; i < 4; i++) {
    pinMode(binPins[i], OUTPUT); // Sets Pins for Binary Counter
  }
  for(byte i2 = 0; i2 < 3; i2++){
    pinMode(LED1[i2], OUTPUT); // Sets Pins for LED1
  }
  for(byte i3 = 0; i3 < 3; i3++){
    pinMode(LED2[i3], OUTPUT);
  }
  count = 0; // Resets Counter
}

void loop(void)
{
  
  int A5Val = analogRead(potPin); // Voltage Across Potentiometer
  float Voltage = A5Val * (5.0 / 1023.0); // Converts Read Data To Correct Voltage
  int timeDelay = Voltage * (100.0);
  dispBinary(count++);
  delay(timeDelay);

  int LEDDelay = 100;

  for(byte i = 0; i < 3; i++){
    digitalWrite(LED1[i], HIGH); delay(LEDDelay);
  }
  for(byte i2 = 0; i2 < 3; i2++){
    digitalWrite(LED2[i2], HIGH); delay(LEDDelay);
  }
  for(byte i3 = 0; i3 < 3; i3++){
    digitalWrite(LED1[i3], LOW); delay(LEDDelay);
  }
  for(byte i4 = 0; i4 < 3; i4++){
    digitalWrite(LED2[i4], LOW); delay(LEDDelay);
  }
  
}

void dispBinary(byte n)
{
  for (byte i = 0; i < 4; i++) {
    digitalWrite(binPins[i], n & 1); // Adds 1 to Binary Value
    n /= 2; // Insures Count never ='s 2
  
  }
}
