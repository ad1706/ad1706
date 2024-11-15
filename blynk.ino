#define BLYNK_TEMPLATE_NAME "exp7"
#define BLYNK_AUTH_TOKEN "Ta4dCwMzUii2kDhzd5QYgoe2eXdJKM33"
#define BLYNK_TEMPLATE_ID "TMPL3OruP25ci"
#define BLYNK_PRINT Serial // Defines the object that is used for printing 
#include <ESP8266WiFi.h> //Setting up the ESP8266 WiFi library #include 
#include <BlynkSimpleEsp8266.h> //Setting up the associated Blynk library
#define BLYNK_TEMPLATE_ID "TMPL1GZfcFsh" //Template ID 
#define BLYNK_DEVICE_NAME "ESP8266 LED Template" //Device Name 
#define BLYNK_AUTH_TOKEN "PhE7ocs6M0312DUcTvq6NnfIxSrbVogM"
//Authentication Token
#define ssid "A's Pixel" //WiFi credentials 
#define password "7567260322"
const int LEDPin = 5; //NodeMCU pin for LED 
BLYNK_WRITE(V0){ //Function for getting response from Blynk
int lightVal = param.asInt(); //Reading from virtual pin V0
if(lightVal == 1) {
digitalWrite(LEDPin, HIGH); //Turn the LED ON if V0 reads HIGH or 1
}
else{
  digitalWrite(LEDPin, LOW); //Turn the LED OFF if V0 reads LOW or 0
}
}
void setup() {
Serial.begin(115200); //Setting up the Serial Port delay(100);
Blynk.begin(BLYNK_AUTH_TOKEN, ssid, password, "blynk.cloud", 80);
//Starting the Blynk Server
pinMode(LEDPin, OUTPUT); //LED pin as output pin
}
void loop() {
Blynk.run(); //Connect and run the Blynk Server 
delay(500);
}
