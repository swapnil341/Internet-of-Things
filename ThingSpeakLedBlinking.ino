#include<ThingSpeak.h>
#include<ESP8266WiFi.h>

const char* ssid = "ssid";
const char* pass ="password";
const int LED = D2 ;
unsigned int led1 = 1;
unsigned long channelid =36535432;   
WiFiClient client;

void setup() {
  Serial.begin(115200);
  pinMode(LED,OUTPUT);
  digitalWrite(LED,0);
  WiFi.begin(ssid,pass);
  while(WiFi.status() != WL_CONNECTED)
    delay(500);
  Serial.println("WiFi Connected");
  ThingSpeak.begin(client);
}

void loop() {
  int led = ThingSpeak.readFloatField(channelid,led1);
  if(led == 1){
    digitalWrite(LED,HIGH);
    Serial.println("LED is ON");
  }else{
    digitalWrite(LED,LOW);
    Serial.println("LED is OFF");
  }
  delay(500);
}
