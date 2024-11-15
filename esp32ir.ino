const int proximity=5;    
int value=0;
const int sel1=25, sel2=26, sel3=2, sel4=4; //initializing selection pins -Port P3
const int a=16 ,b=17, c=5, d=18, e=19, f=21, g=22, dp=23; //initializing data pins -Port P2   
//pin5 of port P1 connected to IR sensor 
void setup() {   
Serial.begin(9600);                
pinMode(proximity, INPUT); //declared as input 
delay(100); 
pinMode(sel1,OUTPUT); //declaring Selection Pins as output
pinMode(sel2,OUTPUT);
pinMode(sel3,OUTPUT);
pinMode(sel4,OUTPUT);
digitalWrite(sel1,LOW); //selecting all 4 digits of 7-Segment display by making it LOW
digitalWrite(sel2,HIGH);
digitalWrite(sel3,HIGH);
digitalWrite(sel4,HIGH);
pinMode(a,OUTPUT); //declaring data pins as output
pinMode(b,OUTPUT);
pinMode(c,OUTPUT);
pinMode(d,OUTPUT);
pinMode(e,OUTPUT);
pinMode(f,OUTPUT);
pinMode(g,OUTPUT);
pinMode(dp,OUTPUT);
delay(100);
} 
void loop() { 
value=digitalRead(proximity); // storing sensor data in a variable. 
delay(1000); 
if(!value)                    
//check for an obstacle if present. 
{ 
Serial.println("Theory will only take you so far"); //display this message when obstacle detects 
for(int i=0;i<10;i++)
{
  if (i==1)
  {
    digitalWrite(a,HIGH);
 digitalWrite(b,LOW);
 digitalWrite(c,LOW);
 digitalWrite(d,HIGH);
 digitalWrite(e,HIGH);
 digitalWrite(f,HIGH);
 digitalWrite(g,HIGH);
 digitalWrite(dp,HIGH);
 delay(2000);
 

   }
   else if(i==2)
   {
     digitalWrite(a,LOW);
 digitalWrite(b,LOW);
 digitalWrite(c,HIGH);
 digitalWrite(d,LOW);
 digitalWrite(e,LOW);
 digitalWrite(f,HIGH);
 digitalWrite(g,LOW);
 digitalWrite(dp,LOW);
 delay(2000);

   }
   else if (i==3)
   {
     digitalWrite(a,LOW);
 digitalWrite(b,LOW);
 digitalWrite(c,LOW);
 digitalWrite(d,LOW);
 digitalWrite(e,HIGH);
 digitalWrite(f,HIGH);
 digitalWrite(g,LOW);
 digitalWrite(dp,LOW);
 delay(2000);
   }
   else if (i==4)
   {
     digitalWrite(a,HIGH);
 digitalWrite(b,LOW);
 digitalWrite(c,LOW);
 digitalWrite(d,HIGH);
 digitalWrite(e,HIGH);
 digitalWrite(f,LOW);
 digitalWrite(g,LOW);
 digitalWrite(dp,LOW);
 delay(2000);

   }
   else if (i==5)
   {
     digitalWrite(a,LOW);
 digitalWrite(b,HIGH);
 digitalWrite(c,LOW);
 digitalWrite(d,LOW);
 digitalWrite(e,HIGH);
 digitalWrite(f,LOW);
 digitalWrite(g,LOW);
 digitalWrite(dp,LOW);
 delay(2000);

   }
   else if (i==6)
   {
     digitalWrite(a,LOW);
 digitalWrite(b,HIGH);
 digitalWrite(c,LOW);
 digitalWrite(d,LOW);
 digitalWrite(e,LOW);
 digitalWrite(f,LOW);
 digitalWrite(g,LOW);
 digitalWrite(dp,LOW);
 delay(2000);
   }
   else if (i==7)
   {
     digitalWrite(a,LOW);
 digitalWrite(b,LOW);
 digitalWrite(c,LOW);
 digitalWrite(d,HIGH);
 digitalWrite(e,HIGH);
 digitalWrite(f,HIGH);
 digitalWrite(g,HIGH);
 digitalWrite(dp,HIGH);
 delay(2000);
   }
   else if (i==8)
   {
    digitalWrite(a,LOW);
 digitalWrite(b,LOW);
 digitalWrite(c,LOW);
 digitalWrite(d,LOW);
 digitalWrite(e,LOW);
 digitalWrite(f,LOW);
 digitalWrite(g,LOW);
 digitalWrite(dp,LOW);
 delay(2000);

   }
   else
   {
    digitalWrite(a,LOW);
 digitalWrite(b,LOW);
 digitalWrite(c,LOW);
 digitalWrite(d,LOW);
 digitalWrite(e,HIGH);
 digitalWrite(f,LOW);
 digitalWrite(g,LOW);
 digitalWrite(dp,LOW);
 delay(2000);
   }

}
}
else 
{
  digitalWrite(a,HIGH);
 digitalWrite(b,HIGH);
 digitalWrite(c,HIGH);
 digitalWrite(d,HIGH);
 digitalWrite(e,HIGH);
 digitalWrite(f,HIGH);
 digitalWrite(g,HIGH);
 digitalWrite(dp,HIGH);
 delay(2000);
} 
} 

// 1. Connect P2 port pins (5, GND, 3V) to IR Sensor pins (OUT, GND, 5V) using patch chords as shown above.
// 2. Connect the USB cable to the board.
// 3. Open Arduino IDE .Select DOIT ESP32 DEVKIT V1 in boards and select COM port.
// 4. Write the program, verify and Upload it.
// 5. Now you can see the output on the serial monitor

		  const int proximity=5; //pin5 of port P1 connected to IR sensor
		  int value=0;
		  void setup() {
		  Serial.begin(9600);
		  pinMode(proximity, INPUT); //declared as input
		  delay(100);
		  }
		  void loop() {
		  value=digitalRead(proximity); // storing sensor data in a variable.
		  delay(1000);
		  if(!value) //check for an obstacle if present.
		  {
		  Serial.println("obstacle detected.."); //display this message when obstacle detects
		  }
		  }
		  
