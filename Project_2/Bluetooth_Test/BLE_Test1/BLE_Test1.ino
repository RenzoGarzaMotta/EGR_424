#include <SoftwareSerial.h>
SoftwareSerial mySerial(8, 9);
void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);
  delay(100);
}
void loop() {
  if (Serial.available() > 0)
    mySerial.write(Serial.read());
  if (mySerial.available() > 0)
    Serial.write(mySerial.read());
// }