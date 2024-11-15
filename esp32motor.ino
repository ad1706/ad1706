//exp6.1

const int En1=2,En2=4; //initializing enable pins
const int in1=27, in2=13, in3=14, in4=15; //initializing input pins
int count=0;
const int Switch[8]={15,14,13,27,4,2,26,25};
#include<LiquidCrystal.h> // Include the LCD library
LiquidCrystal lcd(16,17,19,21,22,23);
void setup()
{
  Serial.begin(9600); //Baud Rate
lcd.begin(16,2);
  for(int i=0;i<8;i++)
  {
    pinMode(Switch[i],INPUT);
    delay(20);
  }
// channel A
pinMode(En1,OUTPUT);
pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
// channel B
pinMode(En2,OUTPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);
}
void loop() {
   digitalWrite(En1,HIGH); //enabling motor1
 digitalWrite(En2,LOW);
  if(Switch[0]==1 && Switch[1]==0)
  {
    while(count!=100) //motor1 keep rotating for 1 minute in clockwise direction
{
 digitalWrite(in1,HIGH);
 digitalWrite(in2,LOW);
 delay(600);
 count++;
}
count=0;
 digitalWrite(in1,LOW); //to stop motor1
digitalWrite(in2,LOW);
 delay(100);
  }
  else if(Switch[1]==1 && Switch[0]==0)
  {
    while(count!=100) //motor1 keep rotating for 1 minute in anti-clockwise direction
{
 digitalWrite(in1,LOW);
 digitalWrite(in2,HIGH);
 delay(600);
 count++;
}
count=0;
 digitalWrite(in1,LOW); //to stop motor1
digitalWrite(in2,LOW);
 delay(100);
  }
  else
  {
    lcd.setCursor(0,0); //first line in display
lcd.print("*ERROR*");
delay(3000);
lcd.clear();

  }
}


