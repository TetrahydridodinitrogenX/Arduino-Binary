int binPins2[] = {2, 3, 4, 5}; // Digital Output Pins for Count
int binPins[] = {6, 7, 8, 9}; // Digital Output Pins for Count 2

byte count; // Sets Count Variable as a Byte Count
byte count2;

void setup(void)
{
    Serial.begin(9600); // Begins Serial Call
  for (byte i = 0; i < 4; i++) {
    pinMode(binPins[i], OUTPUT); // Sets Digital Pins for Output
    pinMode(binPins2[i], OUTPUT);
  }
  count = 0; // Counter
  count2 = 0;
}

void loop(void)
{
  dispBinary(count++);
  delay(50);
}

void dispBinary(byte n)
{
  for (byte i = 0; i < 4; i++) {
    digitalWrite(binPins[i], n & 1); // Adds 1 to Binary Value
    n /= 2; // Insures Count never ='s 2
  if (i > 9){
    i = 0;
  }}
  for (byte i2 = 0; i2 < 4; i2++){
    digitalWrite(binPins2[i2], n & 1);
    n /= 2;
  }
}
