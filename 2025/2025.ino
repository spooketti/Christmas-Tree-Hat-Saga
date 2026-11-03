int leds[] = {3, 5, 6, 9, 10};
int count = 5;
int brightness = 75;
bool dimMode = false;
int delayTime = 170;

void setup()
{
  if(dimMode)
  {
    brightness = 15;
    delayTime = delayTime;
  }
}

void sequentialWave(int cycles) {
  for (int c = 0; c < cycles; c++) {
    for (int i = 0; i < count; i++) {
      analogWrite(leds[i], brightness);
      delay(delayTime);
      analogWrite(leds[i], 0);
    }
  }
}

void dualChase(int cycles) {
  for (int c = 0; c < cycles; c++) {
    for (int i = 0; i < count; i++) {
      int j = count - 1 - i;
      analogWrite(leds[i], brightness);
      analogWrite(leds[j], brightness);
      delay(delayTime);
      analogWrite(leds[i], 0);
      analogWrite(leds[j], 0);
    }
  }
}

void pulseCenter(int cycles) {
  for (int c = 0; c < cycles; c++) {

    analogWrite(leds[2], brightness);
    delay(delayTime);
    analogWrite(leds[2], 0);

    analogWrite(leds[1], brightness);
    analogWrite(leds[3], brightness);
    delay(delayTime);
    analogWrite(leds[1], 0);
    analogWrite(leds[3], 0);

    analogWrite(leds[0], brightness);
    analogWrite(leds[4], brightness);
    delay(delayTime);
    analogWrite(leds[0], 0);
    analogWrite(leds[4], 0);
  }
}

void loop() {
 sequentialWave(2);    
  dualChase(3);         
  pulseCenter(3);    
}


