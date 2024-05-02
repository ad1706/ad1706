/* 3 Monitor bit P1.5. If high, send 55H
to P0; otherwise send AAH to P2. */
#include <reg51.h>
sbit mybit = P1^5;
void main(void)
{mybit=1;
while(1)
{if(mybit==1)
P0=0x55;
else
P2=0xAA;
mybit=~mybit;}}
​
/* 3 Door sensor to the P1.1, buzzer to P1.7. 
When itsound the buzzer by sending a sq wave */
#include <reg51.h>
#define SENSOR_PIN P1^1
#define BUZZER_PIN P1^7
void MSDelay (unsigned int itime)
{unsigned int i,j;
for (i=0;i<itime;i++)
{for (j=0;j<1275;j++);}}
void main (void)
{SENSOR_PIN = 1;
BUZZER_PIN = 0;
while (1)
{if (SENSOR_PIN == 0)
{BUZZER_PIN = 1;
MSDelay(5);
BUZZER_PIN = 0;
MSDelay(5);
}}}
​
/* 3 Toggle all the bits of P0 and P2 
continuously with some delay */
# include <reg51.h>
void MSDelay (unsigned int itime)
{unsigned int i,j;
for (i=0;i<itime;i++)
{for (j=0;j<1275;j++);}}
void main (void)
{P0 = 255;
P2 = 0;
while (1)
{P0 = ~P0;
P2 = ~P2;
MSDelay (500);
}}
​
/* 3 Read the bits of P1.0 and P1.1 and issue an
ASCII character to P0 according to the following table.
P1.1 P1.0 Task
0 0 send ‘0’ to P0
0 1 send ‘1’ to P0
1 0 send ‘2’ to P0
1 1 send ‘3’ to P0
*/
#include <reg51.h>
#define OUTPUT_PORT P0
void main(void)
{
P1 = P1 | 0x03;
while (1)
{unsigned char input = P1 & 0x03;
char output;
switch (input) {
case 0x00: // P1.1 = 0, P1.0 = 0
output = '0';
break;
case 0x01: // P1.1 = 0, P1.0 = 1
output = '1';
break;
case 0x02: // P1.1 = 1, P1.0 = 0
output = '2';
break;
case 0x03: // P1.1 = 1, P1.0 = 1
output = '3';
break;
default:
output = '?'; // Unknown state
break;
}
OUTPUT_PORT = output;
}}
​
// 3 Calculate the checksum 25H,62H,3FH,52H
#include <reg51.h>
unsigned int sum = 0;
unsigned char checksum = 0;
void main()
{sum = 0x25 + 0x62 + 0x3F + 0x52;
checksum = ~sum + 1;
P0 = checksum;
P1 = sum;
}