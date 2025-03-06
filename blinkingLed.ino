#include<Arduino.h>
const int led = D0;
void setup{
  Serial.begin(115200);
  pinMode(led,OUTPUT);
}  
void loop{
 delay(2000);
 digitalWrite(led,HIGH);
 Serial.write("LED is ON");
 delay(3000);
 digitalWrite(led,LOW); 
 Serial.write("LED is OFF");
}
