#include <Adafruit_NeoPixel.h>
#define Control 7 
#define PixelCount 144 

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PixelCount, Control, NEO_GRB + NEO_KHZ800);

enum Pattern {
  TWINKLE,
  RAIN,
  FADE
}

int pattern = FADE;
int step = 0;
const unsigned long iterDelayMS=20;
unsigned long lastUpdate=0;

void setup() {
  strip.begin();
  clearLED();
  randomSeed(analogRead(0));
}

void loop() {
  unsigned long elapsed = millis();
  if(elapsed - lastUpdate > iterDelayMS) {
    update(elapsed);
  }
}

void update(unsigned long elapsed){
  switch(pattern){
    case FADE:
      fade(255,213,97);
    break;
    default:
      pattern = FADE;
    break;
  }
  lastUpdate = elapsed;
}

void twinkle(){

}

void fade(int R, int G, int B){
  static float iterations = 450;
  static float RStep, GStep, BStep, red, green, blue;
  static bool reverse = false; //forward = dark-->light
  if(step == 0){
    red,green,blue = 0;
    RStep = (float)R/(float)iterations;
    GStep = (float)G/(float)iterations;
    BStep = (float)B/(float)iterations;
    step++;
    return;
  }

  red+=RStep;
  green+=GStep;
  blue+=BStep;

  for(int i=0;i<strip.numPixels();i++){
    strip.setPixelColor(i,strip.Color((int)red,(int)green,(int)blue));
  }
  strip.show();
  step++;

  if(step >= iterations) {
    RStep = -RStep;
    GStep = -GStep;
    BStep = -BStep;
    step = 1;
    if(reverse){
      red,green,blue = 0;
      reverse = false;
      return;
    }
    reverse = true;
  }
}

void clearLED(){
  for(int i=0;i<strip.numPixels();i++){
    strip.setPixelColor(i, strip.Color(0,0,0));
  }
}