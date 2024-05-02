// 10 NU using UART
#include<lpc214x.h>
#define Fosc 12000000
#define Fcclk (Fosc * 5)
#define Fcco (Fcclk * 4)
#define Fpclk (Fcclk / 4) * 1
#define baud_1 9600 // Set Baud Rate here
void Init_UART0(void);
void UART0_SendByte(unsigned char data);
int UART0_getByte(void);
int main() {
PINSEL0 = 0x00000005; // P0.0 and P0.1 are configured as UART
PINSEL1 = 0x00000000; // Configure other pins as GPIO
IO1DIR = 0xFFFFFFFF; // Set all pins of port 1 as output
IO1CLR = 0xFFFFFFFF; // Clear all pins of port 1
Init_UART0(); // Initialize UART0
while(1) {
// Continuously send "NIRMA UNIVERSITY" over UART
UART0_SendByte('N');
UART0_SendByte('I');
UART0_SendByte('R');
UART0_SendByte('M');
UART0_SendByte('A');
UART0_SendByte('\n'); // New line
UART0_SendByte('U');
UART0_SendByte('N');
UART0_SendByte('I');
UART0_SendByte('V');
UART0_SendByte('E');
UART0_SendByte('R');
UART0_SendByte('S');
UART0_SendByte('I');
UART0_SendByte('T');
UART0_SendByte('Y');
UART0_SendByte('\n'); // New line
}
}
void Init_UART0(void) {
unsigned int tem;
U0LCR = 0x83; // 8 bits, no Parity, 1 Stop bit, Enable DLAB
tem = (Fpclk / 16) / baud_1; // Calculate baud rate divisor
U0DLM = tem / 256; // Set the divisor latch MSB
U0DLL = tem % 256; // Set the divisor latch LSB
U0FCR = 0x01; // Enable and reset FIFOs
U0LCR = 0x03; // Disable DLAB and set to 8-N-1
}
void UART0_SendByte(unsigned char data) {
U0THR = data; // Load the data to be transmitted
while ((U0LSR & 0x40) == 0); // Wait until THR is empty
}
int UART0_getByte(void) {
while ((U0LSR & 0x01) == 0); // Wait until RBR contains valid data
return(U0RBR); // Return received data
}
​
// 10 UART DISPLAY ON LCD
#include <lpc214x.h>
#define Fosc 12000000
#define Fcclk (Fosc * 5)
#define Fcco (Fcclk * 4)
#define Fpclk (Fcclk / 4) * 1
#define baud_1 9600 //Set Baud Rate here
// LCD
/* Configure the data bus and Control bus as per the hardware connection */
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
/* Masks for configuring the DataBus and Control Bus direction */
#define LCD_ctrlBusMask ((1<<LCD_RS)|(1<<LCD_RW)|(1<<LCD_EN))
#define LCD_dataBusMask ((1<<LCD_D4)|(1<<LCD_D5)|(1<<LCD_D6)|(1<<LCD_D7))
void delay(int cnt);
void sendNibble(char nibble);
void Lcd_CmdWrite(char cmd);
void Lcd_DataWrite(char dat);
void lcd_init();
// end LCD
void Init_UART0(void);
void UART0_SendByte(unsigned char data);
int UART0_getByte(void);
int main()
{
PINSEL0=0x00000005; //P0.0 and P0.1 are UART
PINSEL1=0x00000000;
IO1DIR=0xFFFFFFFF;
IO1CLR=0xFFFFFFFF;
Init_UART0();
lcd_init();
while(1)
{
int x;
x=UART0_getByte();
Lcd_DataWrite(x);
UART0_SendByte(x);
}
}
void Init_UART0(void) //This function setups UART0
{
unsigned int tem;
U0LCR=0x83;
tem=(Fpclk /16) / baud_1;
U0DLM=tem / 256;
U0DLL=tem % 256;
U0FCR = 0x01;
U0LCR=0x03;
}
void UART0_SendByte(unsigned char data) //A function to send a byte on UART0
{
U0THR = data;
while( (U0LSR&0x40)==0 );
}
int UART0_getByte(void) //A function to send a byte on UART0
{
while((U0LSR & 0x01) == 0);
return(U0RBR);
}
/* local function to generate some delay */
void delay(int cnt)
{
int i, j;
for(i=0; i<cnt; i++)
for(j=0; j<10; j++);
}
/* Function send the a nibble on the Data bus (LCD_D4 to LCD_D7) */
void sendNibble(char nibble)
{
LcdDataBusPort&=~(LCD_dataBusMask); // Clear previous data
LcdDataBusPort|= (((nibble >>0x00) & 0x01) << LCD_D4);
LcdDataBusPort|= (((nibble >>0x01) & 0x01) << LCD_D5);
LcdDataBusPort|= (((nibble >>0x02) & 0x01) << LCD_D6);
LcdDataBusPort|= (((nibble >>0x03) & 0x01) << LCD_D7); }
/* Function to send the command to LCD. As it is 4bit mode, a byte of data is sent in two 4-bit
nibbles */
void Lcd_CmdWrite(char cmd)
{
sendNibble((cmd >> 0x04) & 0x0F); //Send higher nibble
LcdControlBusPort &= ~(1<<LCD_RS); // Send LOW pulse on RS pin for selecting Command register
LcdControlBusPort &= ~(1<<LCD_RW); // Send LOW pulse on RW pin for Write operation
LcdControlBusPort |= (1<<LCD_EN); // Generate a High-to-low pulse on EN pin
delay(1000);
LcdControlBusPort &= ~(1<<LCD_EN);
delay(1000);
sendNibble(cmd & 0x0F); //Send Lower nibble
LcdControlBusPort &= ~(1<<LCD_RS); // Send LOW pulse on RS pin for selecting Command register
LcdControlBusPort &= ~(1<<LCD_RW); // Send LOW pulse on RW pin for Write operation
LcdControlBusPort |= (1<<LCD_EN); // Generate a High-to-low pulse on EN pin
delay(1000);
LcdControlBusPort &= ~(1<<LCD_EN);
delay(1000);
}
/* Function to send the Data LCD. As it is 4bit mode, a byte of data is sent in two 4-bit nibbles */
void Lcd_DataWrite(char dat)
{
sendNibble((dat >> 0x04) & 0x0F); //Send higher nibble
LcdControlBusPort |= (1<<LCD_RS); // Send HIGH pulse on RS pin for selecting data register
LcdControlBusPort &= ~(1<<LCD_RW); // Send LOW pulse on RW pin for Write operation
LcdControlBusPort |= (1<<LCD_EN); // Generate a High-to-low pulse on EN pin
delay(1000);
LcdControlBusPort &= ~(1<<LCD_EN);
delay(1000);
sendNibble(dat & 0x0F); //Send higher nibble
LcdControlBusPort |= (1<<LCD_RS); // Send HIGH pulse on RS pin for selecting data register
LcdControlBusPort &= ~(1<<LCD_RW); // Send LOW pulse on RW pin for Write operation
LcdControlBusPort |= (1<<LCD_EN); // Generate a High-to-low pulse on EN pin
delay(1000);
LcdControlBusPort &= ~(1<<LCD_EN);
delay(1000);
}
void lcd_init()
{
LcdDataBusDirnReg |= LCD_dataBusMask; // Configure all the LCD pins as output
LcdCtrlBusDirnReg |= LCD_ctrlBusMask;
Lcd_CmdWrite(0x02); // Initialize Lcd in 4-bit mode
Lcd_CmdWrite(0x28); // enable 5x7 mode for chars
Lcd_CmdWrite(0x0E); // Display OFF, Cursor ON
Lcd_CmdWrite(0x01); // Clear Display
Lcd_CmdWrite(0x80); // Move the cursor to beginning of first line
}
​
// 10 General Library
#include <lpc214x.h>
#define PCLK_FREQ 12000000 // Assuming PCLK frequency of 12 MHz
void uart_init(unsigned int baudrate) {
unsigned int divisor;
// Calculate divisor value
divisor = PCLK_FREQ / (16 * baudrate);
// Enable UART0 pins (TXD0 and RXD0)
PINSEL0 |= 0x00000005;
// Enable UART0 power
PCONP |= (1 << 3);
// Enable FIFOs and reset them
U0FCR = 0x07;
// Configure line control register
U0LCR = 0x83; // 8-bit data, 1 stop bit, enable DLAB
// Set divisor
U0DLL = divisor & 0xFF;
U0DLM = (divisor >> 8) & 0xFF;
// Clear DLAB
U0LCR &= ~(1 << 7);
}
void uart_send_char(char c) {
// Wait for the THR empty
while (!(U0LSR & (1 << 5)));
// Send the character
U0THR = c;
}
char uart_receive_char() {
// Wait for a character to be received
​
while (!(U0LSR & 0x01));
// Return the received character
return U0RBR;
}
void uart_send_string(const char *str) {
while (*str) {
uart_send_char(*str++);
}}
void uart_receive_string(char *buffer, int max_length) {
int i = 0;
char c;
while (i < max_length - 1) {
c = uart_receive_char();
if (c == '\r' || c == '\n') {
buffer[i] = '\0';
break;
}
buffer[i++] = c;
}
buffer[i] = '\0';
}
int main() {
char buffer[50];
uart_init(9600); // Initialize UART with baud rate 9600
uart_send_string("Hello, World!\r\n");
uart_receive_string(buffer, sizeof(buffer));
uart_send_string("Received: ");
uart_send_string(buffer);
uart_send_string("\r\n");
while(1); // Infinite loop
return 0;
} 