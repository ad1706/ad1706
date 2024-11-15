// 1. Connect P2 port and SV1(LCD 16*2 Display) port using FRC cable as shown above.
// 2. Connect the USB cable to the board.
// 3. Open Arduino IDE .Select DOIT ESP32 DEVKIT V1in boards and select COM port.
// 4. Write the program, verify and Upload it.
// 5. Now you can see the output on LCD.


#include <LiquidCrystal.h> // Include the LCD library
LiquidCrystal lcd(16,17,19,21,22,23); //Port P2 Mapping the pins with library
void setup()
{
Serial.begin(9600); //Baud Rate
lcd.begin(16,2); //initializing 16X2 LCD display
}
void loop()
{
lcd.setCursor(0,0); //first line in display
lcd.print("*WELCOME TO RDL*");
delay(3000);
//lcd.clear();
lcd.setCursor(0,1); //second line in display
lcd.print("LEARNING IS FUN");
delay(3000);
lcd.clear();
}
