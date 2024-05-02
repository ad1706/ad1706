// 4 Toggle all bits of P2 continuously every 500ms with Timer1, Mode 1
#include <reg51.h> void
T1M1Delay(void); void
main(void)
{
unsigned char x; P2=0x55;
while(1) { P2=~P2;
for(x=0;x<20;x++)
T1M1Delay();
} }
void T1M1Delay(void)
{
TMOD=0x10;
TL1=0xFE;
TH1=0xA5; TR1=1;
while(TF1==0);
TR1=0;
TF1=0;
}
​
// 4 Mode 2, count up and display TL1 state  on P1
#include <reg51.h> sbit
mybit = P3^5; void
main() {
T1=1;
TMOD=0x60;
TH1=0; while(1)
{
do {
TR1=1;
P1=TL1;
}
while(TF1==0);
TR1=0;
TF1=0;
}
}
​
// 4 Timer 0 square wave 3khz
#include <reg51.h> void
T1M1Delay(void); void
main(void)
{
unsigned char x;
P2=0x00; while(1) {
P2=~P2;
T1M1Delay();
} }
void T1M1Delay(void)
{
TMOD=0x01;
TL0=0x66;
TH0=0xFF; TR0=1;
while(TF0==0);
TR0=0;
TF0=0;
}
​
// 4 Toggle P1 with delay using Timer 0, 16 bit
#include <reg51.h> void
T1M1Delay(void)
{
TMOD=0x01;
TL0=0x00;
TH0=0x00; TR0=1;
while(TF0==0);
TR0=0;
TF0=0; }
void main(void)
{
unsigned char x;
P2=0x55; while(1) {
P2=~P2;
T1M1Delay();
}
}
​
// 4 Switch at 1.2, sw = 0 500Hz, sw =1 750Hz
#include <reg51.h> 
sbit IN =
P2^2; void
T0M0Delay(void)
{
TMOD=0x01;
TL0=0x66;
TH0=0xFC; TR0=1;
while(TF0==0);
TR0=0;
TF0=0; }
void T1M1Delay(void)
{
TMOD=0x10;
TL1=0x96;
TH1=0xFD; TR1=1;
while(TF1==0);
TR1=0;
TF1=0; }
void main(void)
{
unsigned char x; P0=0x00;
P1=0x00; if
( IN == 0 )
{
while (1)
{
T0M0Delay();
P0=~P0;
}
}
else
{
while (1)
{
T1M1Delay();
P1=~P1;
}}}
​
// 4 Counter 0 mode 1, count + display th0 tlo on 2 and 1
#include <reg51.h> sbit
mybit = P3^4; void
main() {
T1=1;
TMOD=0x05; while(1)
{
do {
TR0=1;
P1=TL0;
P2 = TH0;
}
while(TF0==0);
TR0=0;
TF0=0;
}
}
​
/* 4 Event counter Timer 1 mode 1
display binary count p1 and p2
initial count 20k */
#include <reg51.h> sbit
mybit = P3^5; void
main() {
T1=1;
TMOD=0x60;
TH1 = 0x4E;
TL1 = 0x20; while(1)
{
do {
TR1=1;
P1=TL1;
P2 = TH1;
}
while(TF1==0);
TR1=0;
TF1=0;
}
}
​
// 4 Count pulses, tlo tho on p1 p2
#include <reg51.h> sbit
mybit = P3^4; void
main() {
T1=1;
TMOD=0x06; while(1)
{
do {
TR0 = 1;
P1 = TL0;
P2 = TH0;
}
while(TF0==0);
TR0=0;
TF0=0;
}
}
