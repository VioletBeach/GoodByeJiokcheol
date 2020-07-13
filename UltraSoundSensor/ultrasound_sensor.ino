#include <SoftwareSerial.h>
SoftwareSerial btSerial(2,3); 
int eP1=8, tP1=11;
int eP2=9, tP2=12;
int eP3=10, tP3=13;

void setup()
{
  Serial.begin(9600);
  btSerial.begin(9600); 
    for(int i=8;i<11;i++)
  pinMode(i,INPUT);
  for(int i=11;i<14;i++)
  pinMode(i,OUTPUT);
}
void loop()
{
 float dis1=0,dis2=0,dis3=0;
int count=0;
delay(1000);

digitalWrite(tP1,HIGH);
delayMicroseconds(10);
digitalWrite(tP1,LOW);
dis1=pulseIn(eP1,HIGH)/58.2;
delay(200);
digitalWrite(tP2,HIGH);
delayMicroseconds(10);
digitalWrite(tP2,LOW);
dis2=pulseIn(eP2,HIGH)/58.2; 
delay(300);
digitalWrite(tP3,HIGH);
delayMicroseconds(10);
digitalWrite(tP3,LOW);
dis3=pulseIn(eP3,HIGH)/58.2;
delay(200);
Serial.println("eco1 : "+String(dis1)+"\t eco2 : "+String(dis2)+"\t echo3 : "+String(dis3));

if(dis1< 19.0)
  count++;

if(dis2< 19.0)
  count++;

if(dis3< 19.0)
  count++;

  
  btSerial.write(count);
    
   // btSerial.write(dis1);
      
   
}
