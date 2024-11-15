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

//2
const int Switch[8]={15,14,13,27,4,2,26,25};
const int Led[8]={23,22,21,19,18,5,17,16};
void setup()
{
  for(int i=0;i<8;i++)
  {
    pinMode(Switch[i],INPUT);
    pinMode(Led[i],OUTPUT);
    delay(20);
  }
}
void loop()
{
  for(int i=0;i<8;i++)
  {
    digitalWrite(Led[i],digitalRead(Switch[i]));
  }
  delay(1000);
}
