#include <MemoryFree.h>
#include <EEPROM.h>

void setup() {
  Serial.begin(115200);
  Serial3.begin(115200);
}
int x, y;
void loop() {
  if (Serial3.available()>=2) {
    x = Serial3.read();
    if (x>100) {
      x -= 256;
    }
    delay(10);
    y = Serial3.read();
    if (y>100) {
      y -= 256;
    }
    Serial.print("x:");
    Serial.println(x);
    Serial.print("y:");
    Serial.println(y);
  }
}
