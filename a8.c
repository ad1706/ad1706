// 8 Display scrolling message
#include <lpc214x.h>
#define LcdDataBusPort IO0PIN
#define LcdControlBusPort IO0PIN
#define LcdDataBusDirnReg IO0DIR
#define LcdCtrlBusDirnReg IO0DIR
#define LCD_RS 13
#define LCD_RW 4
#define LCD_EN 12
#define LCD_D4 8
#define LCD_D5 9
#define LCD_D6 10
#define LCD_D7 11
#define LCD_ctrlBusMask((1 << LCD_RS) | (1 << LCD_RW) | (1 << LCD_EN))
#define LCD_dataBusMask
((1 << LCD_D4) | (1 << LCD_D5) | (1 << LCD_D6) | (1 << LCD_D7))
void delay(int cnt) {
int i, j;
for (i = 0; i < cnt; i++)
for (j = 0; j < 10; j++);
}
void sendNibble(char nibble) {
LcdDataBusPort &= ~(LCD_dataBusMask);
LcdDataBusPort |= (((nibble >> 0x00) & 0x01) << LCD_D4);
LcdDataBusPort |= (((nibble >> 0x01) & 0x01) << LCD_D5);
LcdDataBusPort |= (((nibble >> 0x02) & 0x01) << LCD_D6);
LcdDataBusPort |= (((nibble >> 0x03) & 0x01) << LCD_D7);
}
void Lcd_CmdWrite(char cmd) {
sendNibble((cmd >> 0x04) & 0x0F);
LcdControlBusPort &= ~(1 << LCD_RS);
selecting Command register
LcdControlBusPort &= ~(1 << LCD_RW);
Write operation
LcdControlBusPort |= (1 << LCD_EN);
on EN pin
delay(1000);
LcdControlBusPort &= ~(1 << LCD_EN);
delay(1000);
sendNibble(cmd & 0x0F);
LcdControlBusPort &= ~(1 << LCD_RS);
selecting Command register
LcdControlBusPort &= ~(1 << LCD_RW);
Write operation
LcdControlBusPort |= (1 << LCD_EN);
on EN pin
delay(1000);
LcdControlBusPort &= ~(1 << LCD_EN);
delay(1000);
}
void Lcd_DataWrite(char dat) {
sendNibble((dat >> 0x04) & 0x0F);
LcdControlBusPort |= (1 << LCD_RS);
selecting data register
LcdControlBusPort &= ~(1 << LCD_RW);
Write operation
LcdControlBusPort |= (1 << LCD_EN);
on EN pin
delay(1000);
LcdControlBusPort &= ~(1 << LCD_EN);
delay(1000);
sendNibble(dat & 0x0F);
LcdControlBusPort |= (1 << LCD_RS);
selecting data register
LcdControlBusPort &= ~(1 << LCD_RW);
Write operation
LcdControlBusPort |= (1 << LCD_EN);
on EN pin
delay(1000);
LcdControlBusPort &= ~(1 << LCD_EN);
delay(1000);
}
void displayMessage(char * message) {
char i;
for (i = 0; message[i] != '\0'; i++) {
Lcd_DataWrite(message[i]);
}}
int main() {
char i;
char message[] = "WELCOME TO THE HORIZON";
LcdDataBusDirnReg |= LCD_dataBusMask;
LcdCtrlBusDirnReg |= LCD_ctrlBusMask;
Lcd_CmdWrite(0x02);
Lcd_CmdWrite(0x28);
Lcd_CmdWrite(0x0E);
Lcd_CmdWrite(0x01);
Lcd_CmdWrite(0x80);
displayMessage(message);
while (1) {
for (i = 0; message[i] != '\0'; i++) {
Lcd_CmdWrite(0x18);
delay(100000);
}}}
​
// 8 Display blinking message
#include <lpc214x.h>
#define LcdDataBusPort IO0PIN
#define LcdControlBusPort IO0PIN
#define LcdDataBusDirnReg IO0DIR
#define LcdCtrlBusDirnReg IO0DIR
#define LCD_RS 13
#define LCD_RW 4
#define LCD_EN 12
#define LCD_D4 8
#define LCD_D5 9
#define LCD_D6 10
#define LCD_D7 11
#define LCD_ctrlBusMask((1 << LCD_RS) | (1 << LCD_RW) | (1 << LCD_EN))
#define LCD_dataBusMask
((1 << LCD_D4) | (1 << LCD_D5) | (1 << LCD_D6) | (1 << LCD_D7))
void delay(int cnt) {
int i, j;
for (i = 0; i < cnt; i++)
for (j = 0; j < 10; j++);
}
void sendNibble(char nibble) {
LcdDataBusPort &= ~(LCD_dataBusMask);
LcdDataBusPort |= (((nibble >> 0x00) & 0x01) << LCD_D4);
LcdDataBusPort |= (((nibble >> 0x01) & 0x01) << LCD_D5);
LcdDataBusPort |= (((nibble >> 0x02) & 0x01) << LCD_D6);
LcdDataBusPort |= (((nibble >> 0x03) & 0x01) << LCD_D7);
}
void Lcd_CmdWrite(char cmd) {
sendNibble((cmd >> 0x04) & 0x0F);
LcdControlBusPort &= ~(1 << LCD_RS);
selecting Command register
LcdControlBusPort &= ~(1 << LCD_RW);
Write operation
LcdControlBusPort |= (1 << LCD_EN);
on EN pin
delay(1000);
LcdControlBusPort &= ~(1 << LCD_EN);
delay(1000);
sendNibble(cmd & 0x0F);
LcdControlBusPort &= ~(1 << LCD_RS);
selecting Command register
LcdControlBusPort &= ~(1 << LCD_RW);
Write operation
LcdControlBusPort |= (1 << LCD_EN);
on EN pin
delay(1000);
LcdControlBusPort &= ~(1 << LCD_EN);
delay(1000);
}
void Lcd_DataWrite(char dat) {
sendNibble((dat >> 0x04) & 0x0F);
LcdControlBusPort |= (1 << LCD_RS);
selecting data register
LcdControlBusPort &= ~(1 << LCD_RW);
Write operation
LcdControlBusPort |= (1 << LCD_EN);
on EN pin
delay(1000);
LcdControlBusPort &= ~(1 << LCD_EN);
delay(1000);
sendNibble(dat & 0x0F);
LcdControlBusPort |= (1 << LCD_RS);
selecting data register
LcdControlBusPort &= ~(1 << LCD_RW);
Write operation
LcdControlBusPort |= (1 << LCD_EN);
on EN pin
delay(1000);
LcdControlBusPort &= ~(1 << LCD_EN);
delay(1000);
}
void displayMessage(char * message) {
char i;
for (i = 0; message[i] != '\0'; i++) {
Lcd_DataWrite(message[i]);
}}
int main() {
char i;
char message[] = "SO FAR SO GOOD";
LcdDataBusDirnReg |= LCD_dataBusMask;
as output
LcdCtrlBusDirnReg |= LCD_ctrlBusMask;
Lcd_CmdWrite(0x02);
Lcd_CmdWrite(0x28);
Lcd_CmdWrite(0x0E);
Lcd_CmdWrite(0x01);
Lcd_CmdWrite(0x80);
displayMessage(message);
while (1) {
for (i = 0; message[i] != '\0'; i++) {
displayMessage(message);
Lcd_CmdWrite(0x01);
delay(100000);
}}}
​
// 8 NU on LCD two lines
#include <lpc214x.h>
#define LcdDataBusPort IO0PIN
#define LcdControlBusPort IO0PIN
#define LcdDataBusDirnReg IO0DIR
#define LcdCtrlBusDirnReg IO0DIR
#define LCD_RS 13
#define LCD_RW 4
#define LCD_EN 12
#define LCD_D4 8
#define LCD_D5 9
#define LCD_D6 10
#define LCD_D7 11
#define LCD_ctrlBusMask((1 << LCD_RS) | (1 << LCD_RW) | (1 << LCD_EN))
#define LCD_dataBusMask
((1 << LCD_D4) | (1 << LCD_D5) | (1 << LCD_D6) | (1 << LCD_D7))
void delay(int cnt) {
int i, j;
for (i = 0; i < cnt; i++)
for (j = 0; j < 10; j++);
}
void sendNibble(char nibble) {
LcdDataBusPort &= ~(LCD_dataBusMask);
LcdDataBusPort |= (((nibble >> 0x00) & 0x01) << LCD_D4);
LcdDataBusPort |= (((nibble >> 0x01) & 0x01) << LCD_D5);
LcdDataBusPort |= (((nibble >> 0x02) & 0x01) << LCD_D6);
LcdDataBusPort |= (((nibble >> 0x03) & 0x01) << LCD_D7);
}
void Lcd_CmdWrite(char cmd) {
sendNibble((cmd >> 0x04) & 0x0F);
LcdControlBusPort &= ~(1 << LCD_RS);
selecting Command register
LcdControlBusPort &= ~(1 << LCD_RW);
operation
LcdControlBusPort |= (1 << LCD_EN);
pin
delay(1000);
LcdControlBusPort &= ~(1 << LCD_EN);
delay(1000);
sendNibble(cmd & 0x0F);
LcdControlBusPort &= ~(1 << LCD_RS);
selecting Command register
LcdControlBusPort &= ~(1 << LCD_RW);
operation
LcdControlBusPort |= (1 << LCD_EN);
pin
delay(1000);
LcdControlBusPort &= ~(1 << LCD_EN);
delay(1000);
}
void Lcd_DataWrite(char dat) {
sendNibble((dat >> 0x04) & 0x0F);
LcdControlBusPort |= (1 << LCD_RS);
selecting data register
LcdControlBusPort &= ~(1 << LCD_RW);
operation
LcdControlBusPort |= (1 << LCD_EN);
pin
delay(1000);
LcdControlBusPort &= ~(1 << LCD_EN);
delay(1000);
sendNibble(dat & 0x0F);
LcdControlBusPort |= (1 << LCD_RS);
selecting data register
LcdControlBusPort &= ~(1 << LCD_RW);
operation
LcdControlBusPort |= (1 << LCD_EN);
pin
delay(1000);
LcdControlBusPort &= ~(1 << LCD_EN);
delay(1000);
}
int main() {
char i, a[] = {
"Dhaval Shah!"
};
LcdDataBusDirnReg |= LCD_dataBusMask;
output
LcdCtrlBusDirnReg |= LCD_ctrlBusMask;
Lcd_CmdWrite(0x02);
Lcd_CmdWrite(0x28);
Lcd_CmdWrite(0x0E);
Lcd_CmdWrite(0x01);
Lcd_CmdWrite(0x80);
Lcd_DataWrite('N');
Lcd_DataWrite('I');
Lcd_DataWrite('R');
Lcd_DataWrite('M');
Lcd_DataWrite('A');
Lcd_CmdWrite(0xc0);
Lcd_DataWrite('U');
Lcd_DataWrite('N');
Lcd_DataWrite('I');
Lcd_DataWrite('V');
Lcd_DataWrite('E');
Lcd_DataWrite('R');
Lcd_DataWrite('S');
Lcd_DataWrite('I');
Lcd_DataWrite('T');
Lcd_DataWrite('Y');
while (1) {
for (i = 0; message[i] != '\0'; i++) {
Lcd_CmdWrite(0x18);
delay(100000);
}}}

// 8 NU + scroll and blink
#include <lpc214x.h>
#define LcdDataBusPort IO0PIN
#define LcdControlBusPort IO0PIN
#define LcdDataBusDirnReg IO0DIR
#define LcdCtrlBusDirnReg IO0DIR
#define LCD_RS 13
#define LCD_RW 4
#define LCD_EN 12
#define LCD_D4 8
#define LCD_D5 9
#define LCD_D6 10
#define LCD_D7 11
#define LCD_ctrlBusMask((1 << LCD_RS) | (1 << LCD_RW) | (1 << LCD_EN))
#define LCD_dataBusMask
((1 << LCD_D4) | (1 << LCD_D5) | (1 << LCD_D6) | (1 << LCD_D7))
void delay(int cnt) {
int i, j;
for (i = 0; i < cnt; i++)
for (j = 0; j < 10; j++);
}
void sendNibble(char nibble) {
LcdDataBusPort &= ~(LCD_dataBusMask);
LcdDataBusPort |= (((nibble >> 0x00) & 0x01) << LCD_D4);
LcdDataBusPort |= (((nibble >> 0x01) & 0x01) << LCD_D5);
LcdDataBusPort |= (((nibble >> 0x02) & 0x01) << LCD_D6);
LcdDataBusPort |= (((nibble >> 0x03) & 0x01) << LCD_D7);
}
void Lcd_CmdWrite(char cmd) {
sendNibble((cmd >> 0x04) & 0x0F);
LcdControlBusPort &= ~(1 << LCD_RS);
selecting Command register
LcdControlBusPort &= ~(1 << LCD_RW);
operation
LcdControlBusPort |= (1 << LCD_EN);
pin
delay(1000);
LcdControlBusPort &= ~(1 << LCD_EN);
delay(1000);
sendNibble(cmd & 0x0F);
LcdControlBusPort &= ~(1 << LCD_RS);
selecting Command register
LcdControlBusPort &= ~(1 << LCD_RW);
operation
LcdControlBusPort |= (1 << LCD_EN);
pin
delay(1000);
LcdControlBusPort &= ~(1 << LCD_EN);
delay(1000);
}
void Lcd_DataWrite(char dat) {
sendNibble((dat >> 0x04) & 0x0F);
LcdControlBusPort |= (1 << LCD_RS);
selecting data register
LcdControlBusPort &= ~(1 << LCD_RW);
operation
LcdControlBusPort |= (1 << LCD_EN);
pin
delay(1000);
LcdControlBusPort &= ~(1 << LCD_EN);
delay(1000);
sendNibble(dat & 0x0F);
LcdControlBusPort |= (1 << LCD_RS);
selecting data register
LcdControlBusPort &= ~(1 << LCD_RW);
operation
LcdControlBusPort |= (1 << LCD_EN);
pin
delay(1000);
LcdControlBusPort &= ~(1 << LCD_EN);
delay(1000);
}
int main() {
char i, a[] = {
"Dhaval Shah"
};
LcdDataBusDirnReg |= LCD_dataBusMask;
output
LcdCtrlBusDirnReg |= LCD_ctrlBusMask;
Lcd_CmdWrite(0x02);
Lcd_CmdWrite(0x28);
Lcd_CmdWrite(0x0E);
Lcd_CmdWrite(0x01);
Lcd_CmdWrite(0x80);
Lcd_DataWrite('N');
Lcd_DataWrite('I');
Lcd_DataWrite('R');
Lcd_DataWrite('M');
Lcd_DataWrite('A');
Lcd_CmdWrite(0xc0);
Lcd_DataWrite('U');
Lcd_DataWrite('N');
Lcd_DataWrite('I');
Lcd_DataWrite('V');
Lcd_DataWrite('E');
Lcd_DataWrite('R');
Lcd_DataWrite('S');
Lcd_DataWrite('I');
Lcd_DataWrite('T');
Lcd_DataWrite('Y'); 