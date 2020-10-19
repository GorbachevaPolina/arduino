#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <WiFiUdp.h>
     
const char* ssid = "Keenetic-3162";
const char* password = "sfU6MA5R";
unsigned int localPort = 5005;
WiFiUDP Udp;
char packetBuffer[255];
int message;
     
void setup(void){  
  Serial.begin(115200);
  while (!Serial) {;}
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }
  Udp.begin(localPort);
}   
void loop(void){
  if (Udp.parsePacket()) {
    int n = Udp.read(packetBuffer, 255);
    packetBuffer[n] = 0;
    message = atoi(packetBuffer);
    //Serial.write(message);
    Serial.println(message);
  }
}
