#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <WiFiUdp.h>
     
const char* ssid = "Verizon-SM-G930V-7551";
const char* password = "xxmv3820";
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
    Serial.write(packetBuffer, 2);
  }
}
