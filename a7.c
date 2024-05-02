// 7 Program to demonstrate a binary counter using 8 LEDs
#include <LPC214X.H>
int count = 0;
unsigned char z;
void main (void)
{PINSEL0 = 0x00000000;
IO0DIR = 0xFFFFFFFF;
while (1)
{z = 0;
IO0CLR = 0x000000FF;
while (z < 0x000000FF)
{
for (count = 0; count < 1000000; count++);
IO0CLR = 0x000000FF;
IO0SET = z;
z = z + 1;
}}}
​
/* 7 Turn on all even numbered LEDs connected to GPIO first, 
then turn them off and turn on all the odd numbered LEDs */
#include <LPC214X.H>
int count = 0;
void main (void)
{PINSEL0 = 0x00000000;
IO0DIR = 0xFFFFFFFF;
while (1)
{IO0SET = 0x55555555;
for (count = 0; count < 1000000; count++);
IO0CLR = ~(0x55555555);
IO0SET = 0xAAAAAAAA;
for (count = 0; count < 1000000; count++);
IO0CLR = ~(0xAAAAAAAA);
}}
​
// 7  Blink LEDs GPIO from left to right and then from right to left:
#include <LPC214X.H>
int count = 0;
unsigned char i;
void main (void)
{PINSEL0 = 0x00000000;
IO0DIR = 0xFFFFFFFF;
while (1)
{i = 0;
IO0CLR = 0xFFFFFFFF;
while (i < 32)
{for (count = 0; count < 100000; count++);
IO0CLR = 0xFFFFFFFF;
IO0SET = (1 << i);
i += 1;
}while (i > 0)
{for (count = 0; count < 100000; count++);
IO0CLR = 0xFFFFFFFF;
IO0SET = (1 << i);
i -= 1;
}}}
​
// 7 LED L to R then R to L variable duty cycle
#include <LPC214X.H>
unsigned int speed = 1000000;
unsigned int duty_cycle = 50;
void delay (unsigned int time)
{for (unsigned int i = 0; i < time; i++);
}
void main (void)
{PINSEL0 = 0x00000000;
IO0DIR = 0xFFFFFFFF;
while (1)
{for (unsigned int i = 0; i < 32; i++)
{IO0CLR = 0xFFFFFFFF;
IO0SET = (1 << i);
delay(speed * duty_cycle / 100);
IO0CLR = 0xFFFFFFFF;
delay(speed * (100 - duty_cycle) / 100);
}
for (unsigned int i = 31; i > 0; i--)
{IO0CLR = 0xFFFFFFFF;
IO0SET = (1 << i);
delay(speed * duty_cycle / 100);
IO0CLR = 0xFFFFFFFF;
delay(speed * (100 - duty_cycle) / 100);
}}}