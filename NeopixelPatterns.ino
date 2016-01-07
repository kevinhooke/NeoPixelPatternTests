#include <Adafruit_NeoPixel.h>
#define PIN            6
#define NUMPIXELS      30

//init
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

//predefine some colors
// pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
uint32_t RED = pixels.Color(255, 0, 0);
uint32_t GREEN = pixels.Color(0, 255, 0);
uint32_t BLUE = pixels.Color(0, 0, 255);

void setup() {
  pixels.begin();
  pixels.show();
}

void loop() {
  
  individualCycle(RED, 50);
  individualCycle(GREEN, 50);
  individualCycle(BLUE, 50);
  
  incrementalOn(RED, 50, 2000);
  incrementalOn(GREEN, 50, 2000);
  incrementalOn(BLUE, 50, 2000);

  
  individualCycleUpAndDown(RED, 50);
  individualCycleUpAndDown(GREEN, 50);
  individualCycleUpAndDown(BLUE, 50);
  
}

void allOff(){
  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, 0);
    pixels.show();
  }
}

void individualCycle(uint32_t color, int delayMillis){
    for(int i=0;i<NUMPIXELS;i++){
      //turn off prior pixel
      if(i>0){
        pixels.setPixelColor(i-1, 0);
      }

      pixels.setPixelColor(i, color);
      pixels.show();
      delay(delayMillis);
    }
    
    //turn off last pixel
    pixels.setPixelColor(NUMPIXELS-1, 0);
}

void incrementalOn(uint32_t color, int delayMillis, int millisPause){
    for(int i=0;i<NUMPIXELS;i++){

      pixels.setPixelColor(i, color);
      pixels.show();
      delay(delayMillis);
    }
    
    delay(millisPause);
    
    //turn all off
    allOff();
}


void individualCycleUpAndDown(uint32_t color, int delayMillis){
    for(int i=0;i<NUMPIXELS;i++){
      //turn off prior pixel
      if(i>0){
        pixels.setPixelColor(i-1, 0);
      }
      pixels.setPixelColor(i, color);
      pixels.show();
      delay(delayMillis);
    }
    
    //turn off last pixel
    pixels.setPixelColor(NUMPIXELS-1, 0);
    
    for(int i=NUMPIXELS-1; i >= 0; i--){
      //turn off prior pixel
      pixels.setPixelColor(i+1, 0);
      pixels.setPixelColor(i, color);
      pixels.show();
      delay(delayMillis);
    }
    
    //turn off last pixel
    pixels.setPixelColor(0, 0);

}
