/*
Owner: Narendra Gurubhaiyye
Project Name: Sun Tracking Solar System
Description: A sun tracking system using LDRs and servos
*/


#include <Servo.h>
Servo ServoMotorH; // 0 to 90
int ServoHorizotal = 0;

Servo ServoMotorV; 
int ServoVertical = 0; 

int LDR1 = A0; //top LDR
int LDR2 = A1; //right LDR 
int LDR3 = A2; //left LDR 
int LDR4 = A3; //bottom LDR


 void setup () {
  ServoMotorH.attach(8);
  ServoMotorH.write(45);
  ServoMotorV.attach(9);
  ServoMotorV.write(0);
  Serial.begin(9600);
  delay(500);
 }


void loop()
{

  ServoHorizotal = ServoMotorH.read();
  ServoVertical = ServoMotorV.read();

  int s = analogRead(LDR1);
  int w = analogRead(LDR2);
  int n = analogRead(LDR4);
  int e = analogRead(LDR3);

   if(n-s>2 || s-n>2){
   if(n>s){ ServoMotorH.write(ServoHorizotal-1); }
    else { ServoMotorH.write(ServoHorizotal+1); }
  }

  if(e-w>2 || w-e>2){
    if(e>w){ ServoMotorV.write(ServoVertical-1); }
    else { ServoMotorV.write(ServoVertical+1); }
  }

Serial.print("top:");
Serial.print(n);
Serial.print("  right:");
Serial.print(e);
Serial.print("  down:");
Serial.print(s);
Serial.print("  left:");
Serial.println(w);
  delay(2);
}
