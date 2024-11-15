// 1. Connect P3 port and SV9 port using FRC cable.
// 2. Connect the USB cable to the board.
// 3. Open Arduino IDE .Select DOIT ESP32 DEVKIT V1in boards and select COM port.
// 4. Write the program, verify and Upload it.

const int En1=2,En2=4; //initializing enable pins
const int in1=27, in2=13, in3=14, in4=15; //initializing input pins
int count=0;
void setup()
{
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

 // Motor 1 clockwise rotation
 while(count!=100) //motor1 keep rotating for 1 minute in clockwise direction
 {
 digitalWrite(in1,HIGH);
 digitalWrite(in2,LOW);
 delay(600);
 count++;
 }
count=0;

 //Motor1 anticlockwise rotation
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
 digitalWrite(En1,LOW); //enabling Motor 2
 digitalWrite(En2,HIGH);
// Motor 2 clockwise rotation
 while(count!=100) //motor2 keep rotating for 1 minute in clockwise direction
 {
 digitalWrite(in3,HIGH);
 digitalWrite(in4,LOW);
 delay(600);
 count++;
 }
 count=0;

 //Motor2 anticlockwise rotation

 while(count!=100) //motor2 keep rotating for 1 minute in anti-clockwise direction
 {
 digitalWrite(in3,LOW);
 digitalWrite(in4,HIGH);
 delay(600);
 count++;
 }
 //to stop motor2
 digitalWrite(in3,LOW); //to stop motor2
 digitalWrite(in4,LOW);
 delay(100);
} 
