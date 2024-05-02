/* 6 Continuously gets single bit of data from P1.7, 
sends it to P1.0 while creating a square wave of 200 μs 
period on P2.5 and sending letter ‘A’ to the serial port using timer 0
*/
#include <reg51.h>
sbit read = P1^7;
sbit out = P1^0;
sbit wave = P2^5;
void timerInt0(void) interrupt 1
{wave=~wave;
}
void serialInt(void) interrupt 4
{if(TI)
{SBUF='A';
TI=0;}
else
{RI=0;
}}
void main(void)
{read=1; 
TMOD=0x21; 
TH1=0xFD; 
SCON=0xC0; 
TR1=1;
SBUF='A';
TL0=0xA9;
TH0=0xFF;
TR0=1;
IE=0x92;
while(1)
{out=read;
}}
​
/* 6 Receive data serially and send it to P0.
    Read port P1, transmit data serially, and give a copy to P2.
    Timer 0 square wave of 5 KHz on P0.1 at 4800. */
#include <reg51.h> 
void serial_interrupt () interrupt 4
{if (RI)
{RI = 0;
P0 = SBUF;
}}
void timer_interrupt () interrupt 1
{while (TF0 == 0);
P3 = ~P3;
}
void main (void)
{unsigned char t[] = "PORSCHE";
int i;
TMOD = 0x21;
TH1 = 0xF4;
TH0 = 0xFF;
TL0 = 0xA4;
SCON = 0x50;
TR1 = 1;
TR0 = 1;
ET1 = 0; // Disable Timer 1 interupt
ET0 = 1; // Enable Timer 0 interupt
EX0 = 0; // Disable external interupt 0
EX1 = 0; // Disable external interupt 1
ES = 1; 
EA = 1;
while(1)
{for (i = 0 ; i<sizeof(t) ; i++)
{SBUF = P1;
while(TI==0);
TI = 0;
P2 = P1;
P1 = P1+1;
}}}
​
/* 6 Receive data serially and send it to P0.
    Read port P1, transmit data serially, give a copy to P2.
    Generate a square wave of frequency 5 kHz at P3.7 */
#include <reg51.h>
void main (void)
{TMOD = 0x61;
TL0 = 0xD2;
TH0 = 0xFF;
TR0 = 1;
TR1 = 1;
while (1)
{while (TF0 == 0);
TF0 = 0;
P2 = ~P2;
P3 = P2;
P1 = TL1;		
}}
​
/* 6 Generate a square wave of 10 kHz at P2.1.
    Use timer 1 as an event counter and display it on P2.
*/
#include <reg51.h>
void main (void)
{TMOD = 0x10;
TH1 = 0xFF;
TL1 = 0x3F;
TR1 = 1;
P2 = 0x02;
while (1)
{if (TF1)
{TF1 = 0;
P2 = ~P2;
}}}
​
/* 6 create two square waves of5 kHz and one of 25 kHz 
at P2.1 and P2.2 respectively:*/
#include <reg51.h>
sbit wave0 = P2^1;
sbit wave1 = P2^2;
void time0 (void) interrupt 1
{TF0 = 0;
wave0 = ~wave0;}
void time1 (void) interrupt 3
{TF1 = 0;
wave1 = ~wave1;}
void main (void)
{TMOD = 0x11;
TH1 = 0xFF;
TL1 = 0xED; // 25 kHz
TH0 = 0xFF;
TL0 = 0xA4; // 5 kHz
TR1 = 1;
TR0 = 1;
EA = 1;
ET1 = 1; 
ET0 = 1; 
while (1);
}
​
/* 6 Blink an LED 3 times with an interval of 20ms 
when something is received on the serial port */
#include <reg51.h>
sbit LED = P1^7;
int k;
void MSDelay (unsigned int itime)
{unsigned int i, j;
for (i = 0; i < itime; i++)
{for (j = 0; j < 1275; j++);
}}
void serial (void) interrupt 4
{
if (RI)
{RI = 0;
P2 = SBUF;
for (k = 0; k < 4; k++)
{MSDelay (20);
LED = 0;
MSDelay (20);
LED = 1;
}}}
void main (void)
{P1 = 0;
ES = 1; 
EA = 1;
SCON = 0x50;
}
​