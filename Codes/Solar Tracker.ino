#include <Servo.h> 

Servo horizontal; 
int servoh = 0; 
int servohLimitHigh = 140;
int servohLimitLow = 20;

Servo vertical; 
int servov = 0; 
int servovLimitHigh = 110;
int servovLimitLow = 55;

int ldrrt = A0; 
int ldrld = A3; 
int ldrrd = A2; 
int ldrlt = A1; 


void setup(){
horizontal.attach(6);
vertical.attach(3);
horizontal.write(180);
vertical.write(90);
delay(250);
}


void loop() {
int lt = analogRead(ldrlt); 
int rt = analogRead(ldrrt); 
int ld = analogRead(ldrld); 
int rd = analogRead(ldrrd); 
int dtime = 10; int tol = 90; 
int avt = (lt + rt) / 2; 
int avd = (ld + rd) / 2;
int avl = (lt + ld) / 2; 
int avr = (rt + rd) / 2;
int dvert = avt - avd; 
int dhoriz = avl - avr;
if (-1*tol > dvert || dvert > tol) 
 {
 if (avt > avd)
 {
 servov = ++servov;
 if (servov > servovLimitHigh)
 {servov = servovLimitHigh;}
 }
 else if (avt < avd)
 {servov= --servov;
 if (servov < servovLimitLow)
 { servov = servovLimitLow;}
 }
 vertical.write(servov);
 }
if (-1*tol > dhoriz || dhoriz > tol) 
 {
 if (avl > avr)
 {
 servoh = --servoh;
 if (servoh < servohLimitLow)
 {
 servoh = servohLimitLow;
 }
 }
 else if (avl < avr)
 {
 servoh = ++servoh;
 if (servoh > servohLimitHigh)
 {
 servoh = servohLimitHigh;
 }
 }
 else if (avl = avr)
 {
 delay(5000);
 }
 horizontal.write(servoh);
 }
 
 delay(dtime);
 
}
