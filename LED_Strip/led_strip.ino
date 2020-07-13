

#include <Adafruit_NeoPixel.h>
#define LED_PIN 6
#define LED_COUNT 8
#include <SoftwareSerial.h>
SoftwareSerial btSerial(2,3); 

Adafruit_NeoPixel strip = 
Adafruit_NeoPixel(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void easy() {
  strip.setPixelColor(3,0,255,0);
  strip.setPixelColor(4,0,255,0);
}

void normal() {
  strip.setPixelColor(3,255,228,0);
  strip.setPixelColor(4,255,228,0);
}

void busy() {
  strip.setPixelColor(3,255,0,0);
  strip.setPixelColor(4,255,0,0);
}

void setup()
{
  Serial.begin(115200);
  btSerial.begin(9600); 

  strip.setBrightness(1);
  strip.begin();
  strip.show();
  strip.setPixelColor(2,0,0,0);
  strip.setPixelColor(5,0,0,0);
  strip.setPixelColor(6,255,228,0);
  strip.setPixelColor(7,255,228,0);
  strip.setPixelColor(3,0,255,0);
  strip.setPixelColor(4,0,255,0);
  strip.setPixelColor(0,255,0,0);
  strip.setPixelColor(1,255,0,0);
}
void loop()
{
 char value=0;
    strip.begin();
    strip.show();

    if(btSerial.available()) {
     value=btSerial.read();
     Serial.println(value);}
      
     if(value >=48 && value <=49){
        easy();
      }
      
     else if(value >= 50 && value <=52){
        normal();
    }
     else if(value >= 53 && value <=54) {
        busy();
     }
     

   

}
