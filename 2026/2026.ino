#include <Adafruit_NeoPixel.h>
#define Control   7 // pin connected to the small NeoPixels strip
#define PixelCount      144 // number of LEDs on strip

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PixelCount, Control, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  clearLED();
}

void loop() {

}

void clearLED(){
     for(int i=0;i<strip.numPixels();i++){
       strip.setPixelColor(i, strip.Color(0,0,0));
       }
}