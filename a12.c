// 1 Send 00H to FFH on Port P1
#include <reg51.h>
void main(void)
{unsigned char z; while(1)
{for(z=0;z<=255;z++) P1 = z;
}}
​
// 1 Send given strings on Port P1 and P2.
#include <reg51.h>
void main(void)
{unsigned char a[] = “ABCDEF012345”; unsigned char b[] = “Hello World”;
unsigned char i, j; while(1)
{for(i=0;i<sizeof(a);i++) P1 = a[i];
for(i=0;i<10;i++) P1 = 255; // Creates separation between the
strings for(j=0;j<sizeof(b);j++) P1 = b[j];
}}
​
// 2 Send values 00-FF to port P1
#include <reg51.h>
void MSDelay(unsigned int itime) {
unsigned int i, j;
for (i = 0; i < itime; i++) {
for (j = 0; j < 1275; j++);
}}
void main(void) {
unsigned char z;
for (z = 0; z <= 255; z++) {
P1 = z;
MSDelay(500);
}
}
​
​
// 2 Send values of -4 to +4 to port P1
#include <reg51.h>
void main(void) {
char mynum[] = {+1, -1, +2, -2, +3, -3, +4, -4};
unsigned char z;
while (1)
for (z = 0; z <= 8; z++)
P1 = mynum[z];
}
​
// 2 Show the count from 00 to FFH on the LEDs to bits P1 and P2
#include <reg51.h>
#define LED P2
void main(void) {
P1 = 00;
LED = 0;
for (;;) {
P1++;
LED++;
}}
​
// 2  Toggle all the bits of P1 continuously
#include <reg51.h>
void MSDelay(unsigned int itime) {
unsigned int i, j;
for (i = 0; i < itime; i++) {
for (j = 0; j < 1275; j++);
}}
void main(void) {
for (;;) {
P1 = 0;
MSDelay(500);
P1 = 255;
MSDelay(500);
}}
​
// 2 Get a byte of data from P1, wait 0.5 s then send it to P2
#include <reg51.h>
void MSDelay(unsigned int itime) {
unsigned int i, j;
for (i = 0; i < itime; i++) {
for (j = 0; j < 1275; j++);
}}
void main(void) {
unsigned char a;
for (a = 0; a <= 255; a++) {
P2 = 0;
P1 = a;
MSDelay(500);
P2 = P1;
}}
​
// 2 Toggle bit D0 of the port P1 (P1.0) 50,000 times
#include <reg51.h>
void main(void) {
unsigned int a;
for (a = 0; a < 50001; a++) {
P1 = ~P1;
}}
​
// 2 Generate a square wave on P0.0 with ON time 3ms and OFF time 10ms
#include <reg51.h>
void MSDelay(unsigned int itime) {
unsigned int i, j;
for (i = 0; i < itime; i++) {
for (j = 0; j < 1275; j++);
}}
void main(void) {
unsigned char z;
for (z = 0; z <= 255; z++) {
P1 = 255;
MSDelay(3);
P1 = 0;
MSDelay(10);
}}
​
// 2 Take packed BCD at port 0, Convert to ASCII and display on P1 and P2
#include <reg51.h>
void MSDelay(unsigned int itime) {
unsigned int i, j;
for (i = 0; i < itime; i++) {
for (j = 0; j < 1275; j++);
}}
void main() {
unsigned char packedBCD;
unsigned char BCD_high, BCD_low, ASCII_high, ASCII_low;
while (1) {
packedBCD = P0;
BCD_high = packedBCD >> 4;
BCD_low = packedBCD & 0x0F;
ASCII_high = BCD_high + '0';
ASCII_low = BCD_low + '0';
P1 = ASCII_high;
P2 = ASCII_low;
MSDelay(1000);
}}