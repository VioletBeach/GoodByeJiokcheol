#include <SoftwareSerial.h>
#include "HX711.h"
#define calibration_factor -150000 //This value is obtained using the SparkFun_HX711_Calibration sketch
#define DOUT  A3
#define CLK  A2
#define fake_weight 2.30

HX711 scale(DOUT, CLK);

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
  
  for(int i=11;i<14;i++){
    pinMode(i,OUTPUT);
  }
  scale.set_scale(calibration_factor); //This value is obtained by using the SparkFun_HX711_Calibration sketch
  scale.tare(10); //Assuming there is no weight on the scale at start up, reset the scale to 0
  
  
  pinMode(DOUT, INPUT_PULLUP);
 
}
void loop()
{
  char count =0;
  float current_weight=0;
  float scale_factor=0;
  current_weight = (scale.get_units(20));
  scale_factor = -(current_weight/0.200);
  //Serial.print("Reading: ");
  //Serial.print(scale_factor); //scale.get_units() returns a float
  //Serial.print(" kg"); //You can change this to kg but you'll need to refactor the calibration_factor
  //Serial.println();
  //delay(200);

  if(scale_factor >= fake_weight + 1.4)
    count++;

  if(scale_factor >= fake_weight + 1.88)
    count++;

  if(scale_factor >= fake_weight + 3.76)
    count++;


  float dis1=0,dis2=0,dis3=0;
  
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
 
  //Serial.println("eco1 : "+String(dis1)+"\t eco2 : "+String(dis2)+"\t echo3 : "+String(dis3));
 
  scale.get_units(10);
   
   
  if(dis1< 19.0)
  count++;

  if(dis2< 19.0)
  count++;

  if(dis3< 19.0)
  count++;

  Serial.print("Count: ");
  Serial.print(count);
  Serial.println();
  
  btSerial.write(count+48);
  
   
}
