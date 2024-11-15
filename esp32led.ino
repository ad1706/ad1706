// Blinking an LED

// 1. Connect P1 port and SV4 (Data) port and connect P2 port and SV3 (Select) port using FRC cable as shown above.
// 2. Connect the USB cable to the board.
// 3. Open Arduino IDE .Select Arduino Uno in boards and select COM port.
// 4. Now write the program, verify and Upload it.
// 5. Now you can see that number starts displaying on the seven segments on the ATmega328 development board.

const int L1=23, L2=22, L3=21, L4=19, L5=18, L6=5, L7=17, L8=16; //initializing LED pins
void setup()
{
pinMode(L1, OUTPUT); // Set all Port P2 pins as output
pinMode(L2, OUTPUT);
pinMode(L3, OUTPUT);
pinMode(L4, OUTPUT);
pinMode(L5, OUTPUT);
pinMode(L6, OUTPUT);
pinMode(L7, OUTPUT);
pinMode(L8, OUTPUT);
}
void loop()
{
digitalWrite(L1, HIGH);
digitalWrite(L2, HIGH);
digitalWrite(L3, HIGH);
digitalWrite(L4, HIGH);
digitalWrite(L5, HIGH);
digitalWrite(L6, HIGH);
digitalWrite(L7, HIGH);
digitalWrite(L8, HIGH);
delay(2000);
digitalWrite(L1, LOW);
digitalWrite(L2, LOW);
digitalWrite(L3, LOW);
digitalWrite(L4, LOW);
digitalWrite(L5, LOW);
digitalWrite(L6, LOW);
digitalWrite(L7, LOW);
digitalWrite(L8, LOW);
delay(2000);
}

// Controlling LED with a switch

// 1. Connect P3 port and SV13(Digital Input Switch) port and connect P2 port and SV2(LED) port using FRC cable as shown above.
// 2. Connect the USB cable to the board.
// 3. Open Arduino IDE .Select DOIT ESP32 DEVKIT V1in boards and select COM port.
// 4. Now write the program, verify and Upload it.
// 5. Now, when the switch is turned on, LED gets On. 

const int Led[8]={23, 22, 21, 19, 18, 5, 17, 16}; //declaring LEDs (Port P2)
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
for(int i=0; i<8;i++)
{
digitalWrite(Led[i],digitalRead(Switch[i]));//Reads the state of each switches and replicate
}
delay(1000);
}
void loop()
{
for(int i=0; i<8;i++)
 {
 digitalWrite(Led[i],digitalRead(Switch[i]));//Reads the state of each switches and replicate
it on LEDs
 }
delay(1000);
}
