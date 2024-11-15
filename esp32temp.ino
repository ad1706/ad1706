const int tempPin = 33;            
int Value; 
double milivlt,Cel,Far; 
#include<LiquidCrystal.h>                              
LiquidCrystal lcd(16,17,19,21,22,23);
void setup() 
{ 
Serial.begin(9600);                                      
lcd.begin(16,2);
} 
// pin 33 of port P1 connected to LM35 output 
void loop() 
{ 
Value = analogRead(tempPin);         
//read sensor output value 
milivlt = (Value / 2048.0) * 3300;    // converting it to millivots. 
Cel = milivlt * 0.1;                 
// calculating temperature in Celsius 
Far = (Cel * 1.8) + 32;             
// convert from C to Fahrenheit 
if(Cel>65)
{
  Serial.print("working");
  lcd.setCursor(0,0);                                   
lcd.print("*Turn ON AC*"); 
delay(3000); 
//lcd.clear(); 
lcd.setCursor(0,1);                                
lcd.print("Right Now"); 
delay(3000); 
lcd.clear();
}
else
{
  lcd.setCursor(0,0);                                   
lcd.print("*No AC*"); 
delay(3000); 
//lcd.clear(); 
lcd.setCursor(0,1);                                
lcd.print("Right Now"); 
delay(3000); 
lcd.clear();
}
Serial.print(" Temperature in Celsius = "); 
Serial.print(Cel); 
Serial.print("*C"); 
Serial.print("\t Temperature in Fahrenheit = "); 
Serial.print(Far); 
Serial.println("*F"); 
delay(2000);                       
//check the temperature every 2 second
}

// 1. Connect P1 port and SV12 port using FRC cable as shown above
// 2. Connect the USB cable to the board
// 3. Open Arduino IDE .Select DOIT ESP32 DEVKIT V1in boards and select COM port.
// 4. Write the program, verify and Upload it.
// 5. Now you can see the output on the serial monitor

const int tempPin = 39; // pin 33 of port P1 connected to LM35 output

int Value;
double milivlt,Cel,Far;

void setup()
{
Serial.begin(9600);
}

void loop()
{
 Value = analogRead(tempPin); //read sensor output value
 milivlt = (Value / 2048.0) * 3300; // converting it to millivots.
 Cel = milivlt * 0.1; // calculating temperature in Celsius
 Far = (Cel * 1.8) + 32; // convert from C to Fahrenheit
 Serial.print(" Temperature in Celsius = ");
 Serial.print(Cel);
 Serial.print("*C");
 Serial.print("\t Temperature in Fahrenheit = ");
 Serial.print(Far);
 Serial.println("*F");
 delay(2000); //check the temperature every 2 second
}

