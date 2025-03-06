#include"ThingSpeak.h"
#include<ESP8266WiFi.h>
#include<WiFiClient.h>

const char* ssid = "ssid";
const char* pass = "pass";
const char* apikey = "MDH354654DS68";
unsigned long channel = 54341341654 ;
WiFiClient client ;

void setup() {
   Serial.begin(115200);
   pinMode(D2,INPUT );
   pinMode(D4,OUTPUT);
   WiFi.begin(ssid,pass);
   while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
   }
   Serial.print ("WiFi Connected");
   ThingSpeak.begin(client);
}

void loop() {
  int val = digitalRead(D2);
  if(val == HIGH){
    Serial.println("Motio Detected");
    digitalWrite(D4,LOW);
  }else{
    Serial.println("No Motion");
    digitalWrite(D4, HIGH);
  }
  ThingSpeak.writeField(channel, 1, val, apikey);
  delay(500);
}
