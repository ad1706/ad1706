#include<LiquidCrystal.h>                              
LiquidCrystal lcd(16,17,19,21,22,23);             
void setup() 
{ 
Serial.begin(9600);                                      
lcd.begin(16,2);                                           
} 
void loop() 
{ 
lcd.setCursor(0,0);                                   
lcd.print("*WELCOME TO RDL*"); 
delay(3000); 
//lcd.clear(); 
lcd.setCursor(0,1);                                
lcd.print("LEARNING IS FUN"); 
delay(3000); 
lcd.clear(); 
} 
