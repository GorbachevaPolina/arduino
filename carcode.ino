#include <MemoryFree.h>
#include <EEPROM.h>

void setup() {
  Serial.begin(115200);
  Serial3.begin(115200);
}
int x, y;
byte mess[2];
void loop() {
  if (Serial3.available()>1) {
    Serial3.readBytes(mess, 2);
    
    Serial.print("x:");
    Serial.println(int(mess[0])-100);
    Serial.print("y:");
    Serial.println(int(mess[1])-100);
  }
}
