// 5 Serially send 'YES' at 9600 baud, 8 bd 1 sb
#include <reg51.h>
void init() {
TMOD = 0x20;
TH1 = 0xFD;
SCON = 0x50;
TR1 = 1;
}
void send(char c) {
SBUF = c;
while (TI == 0);
TI = 0;
}
void main() {
init();
while (1) {
send('Y');
send('E');
send('S');
}}
​
// 5 Recieve and put in P1, 4800, 8db 1sb
#include <reg51.h>
void main() {
TMOD = 0x20;
TH1 = 0xFA;
SCON = 0x50;
TR1 = 1;
RI = 0;
while (1) {
while (RI == 0);
P1 = SBUF;
RI = 0;
}}
​
// 5 Send 44H serially to P1, LSB First
#include <reg51.h>
void main() {
int a[] = {0, 0, 1, 0, 0, 1, 0, 0};
TMOD = 0x20;
TH1 = 0xFD;
SCON = 0x50;
TR1 = 1;
while (1) {
for (int i = 7; i >= 0; i--) {
P1_0 = a[i] & 0x01;
while (TI == 0);
TI = 0;
}}}
​
// Recieve serially through P1.3, MSB First
#include <reg51.h>
sbit in = P1^3;
void main() {
int data[] = {0, 1, 0, 0, 0, 1, 0, 0};
TMOD = 0x20;
TH1 = 0xFD;
SCON = 0x50;
TR1 = 1;
RI = 0;
while (1) {
while (RI == 0) {
for (int i = 7; i >= 0; i--) {
while (RI == 0); // Wait for start bit
data[i] = in;}
RI = 0; // Clear RI for the next byte
}}}
​
// 5 Send strings to port 0 for fname
#include <reg51.h>
sbit sw = P2^0;
void main() {
char fname[] = {'A', 'B', 'C', 'D', '\0'};
char lname[] = {'x', '4', 'Z', '\0'};
int i;
TMOD = 0x20;
TH1 = 0xFD;
SCON = 0x50;
TR1 = 1;
sw = 1; 
while (1) {
if (sw == 0) {
for (i = 0; fname[i] != '\0'; i++) {
SBUF = fname[i];
while (TI == 0);
TI = 0;
}} else {
for (i = 0; lname[i] != '\0'; i++) {
SBUF = lname[i];
while (TI == 0);
TI = 0;
}}}}
​
// 5 Transfer serially at 57600
#include <reg51.h>
void main() {
char msg[] = "The earth is but one country and mankind its citizens";
TMOD = 0x20;
TH1 = 0xFF;
SCON = 0x50;
TR1 = 1;
while (1) {
for (int i = 0; msg[i] != '\0'; i++) {
SBUF = msg[i];
while (TI == 0);
TI = 0;
}}}
​
// 5 Transfer serially using PCON
#include <reg51.h>
void main() {
char msg[] = "The earth is one, don't divide it";
TMOD = 0x20;
TH1 = 0xFF;
SCON = 0x50;
PCON = 0x80; // SMOD = 1 for baud rate doubling
TR1 = 1;
while (1) {
for (int i = 0; msg[i] != '\0'; i++) {
SBUF = msg[i];
while (TI == 0);
TI = 0;
}}}
​
// 5 Transfer 10 bits RAM at 45H
#include <reg51.h>
void init() {
TMOD = 0x20;
TH1 = 0xFD;
SCON = 0x50;
TR1 = 1;}
void send(unsigned char byte) {
SBUF = byte;
while (TI == 0);
TI = 0;}
void main() {
init();
unsigned char *ptr = 0x45;
for (int i = 0; i < 10; i++) {
send(*ptr++);
}
while (1) {
send(R0);
}}
​