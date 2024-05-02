// 9 Single edge controlled PWM with varying duty cycle on PWM3
#include <lpc214x.h>
void PWM_ISR(void) {
if (PWMIR & 0x0001) {
PWMIR = 0x0001;
}
if (PWMIR & 0x0002) {
PWMIR = 0x0002;
}
if (PWMIR & 0x0004) {
PWMIR = 0x0004;
}
if (PWMIR & 0x0008) {
PWMIR = 0x0008;
}
VICVectAddr = 0x00000000;
}
int main(void) {
VPBDIV = 0x00000002;
PINSEL0 |= (1 << 3) | (1 << 6);
VICVectAddr0 = (unsigned) PWM_ISR;
VICVectCntl0 = (0x00000020 | 8);
VICIntEnable |= (1 << 8);
VICIntSelect &= ~(1 << 8);
PWMTCR = 0x02;
PWMPR = 0x1D;
PWMMR0 = 1000;
PWMMR3 = 1;
PWMMCR = 0x00000203;
PWMLER = 0x09;
PWMPCR = 0x0800;
PWMTCR = 0x09;
while (1) {
while (PWMMR3 != 999) {
PWMMR3++;
PWMLER = 0x08;
delay_ms(5);
}
while (PWMMR3 != 1) {
PWMMR3--;
PWMLER = 0x08;
delay_ms(5);
}}}