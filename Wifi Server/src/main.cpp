#include <Arduino.h>

#include "WiFi.h"
#include "ESPAsyncWebServer.h"

const char* ssid = "ESP32-Access-Point";
const char* password = "123456789";
AsyncWebServer server(80);

String info1() {
  return "INFO A";
}

String info2() {
  return "INFO B";
}

String info3() {
  return "INFO C";
}

void setup(){
  Serial.begin(115200);
  Serial.println();
  Serial.print("Setting AP (Access Point)…");
  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  server.on("/info1", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", info1().c_str());
  });
  server.on("/info2", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", info2().c_str());
  });
  server.on("/info3", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", info3().c_str());
  });
  
  bool status;
  
  server.begin();
}
 
void loop(){
  
}
