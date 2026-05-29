#include <WiFi.h>
const char* ssid     = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";
const char* serverIP = "197.2.185.27"; 
const uint16_t port  = 5005;

WiFiClient client;

void setup()
{
  pinMode(0, INPUT);
  Serial.begin(9600);
  pinMode(1, INPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT); 
 
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWi-Fi Connected!");
}

void loop()
{
   if (!client.connected()) {
    if (!client.connect(serverIP, port)) {
      delay(2000);
      return;
    }
  }
  if (digitalRead(0) == 1) {
    Serial.println("pin0");
    delay(150); 
  }
  if (digitalRead(1) == 1) {
    Serial.println("pin1");
    delay(150);
  }
  if (digitalRead(2) == 1) {
    Serial.println("pin2");
    delay(150);
  }
  if (digitalRead(3) == 1) {
    Serial.println("pin3");
    delay(150);
  }
  
  delay(10); 
}