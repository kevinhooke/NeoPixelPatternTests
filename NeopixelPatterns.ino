#include <Adafruit_NeoPixel.h>
#define PIN            6
#define NUMPIXELS      30

/*

 Simple button/switch activated NeoPixel pattern.
 Kevin Hooke / @kevinhooke 
 
 */
 
//init
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

//predefine some colors
// pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
const uint32_t RED = pixels.Color(255, 0, 0);
const uint32_t GREEN = pixels.Color(0, 255, 0);
const uint32_t BLUE = pixels.Color(0, 0, 255);

const int BUTTON1_PIN = 2;
const int BUTTON2_PIN = 3;
const int BUTTON3_PIN = 4;
const int BUTTON4_PIN = 5;

int button1state, button2state, button3state, button4state = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("setup() ...");
  //init button
  pinMode(BUTTON1_PIN, INPUT);
  digitalWrite(BUTTON1_PIN, HIGH);
  pinMode(BUTTON2_PIN, INPUT);
  digitalWrite(BUTTON2_PIN, HIGH);
  pinMode(BUTTON3_PIN, INPUT);
  digitalWrite(BUTTON3_PIN, HIGH);
  pinMode(BUTTON4_PIN, INPUT);
  digitalWrite(BUTTON4_PIN, HIGH);
  
  pinMode(13, OUTPUT); //on board led for testing
  digitalWrite(13, LOW);
  
  //init pixels
  pixels.begin();
  pixels.show();
  Serial.println("... complete");
}

void loop() {
  
  //read button states
  button1state = digitalRead(BUTTON1_PIN);
  button2state = digitalRead(BUTTON2_PIN);
  button3state = digitalRead(BUTTON3_PIN);
  button4state = digitalRead(BUTTON4_PIN);
  
  
  if(button1state == LOW){
    Serial.println("Button1 pressed!");
    digitalWrite(13, HIGH);
    incrementalOn(BLUE, 50, 2000);
    digitalWrite(13, LOW);
  }
  if(button2state == LOW){
    Serial.println("Button2 pressed!");
    digitalWrite(13, HIGH);
    incrementalOn(RED, 50, 2000);
    digitalWrite(13, LOW);
  }
  if(button3state == LOW){
    Serial.println("Button3 pressed!");
    digitalWrite(13, HIGH);
    //incrementalOn(YELLOW, 50, 2000);
    digitalWrite(13, LOW);
  }
  if(button4state == LOW){
    Serial.println("Button4 pressed!");
    digitalWrite(13, HIGH);
    incrementalOn(GREEN, 50, 2000);
    digitalWrite(13, LOW);
  }
  
//  colorCycle();
  
//  colorMixes();
  
//  individualCycle(RED, 50);
//  individualCycle(GREEN, 50);
//  individualCycle(BLUE, 50);
  
//  incrementalOn(RED, 50, 2000);
//  incrementalOn(GREEN, 50, 2000);
//  incrementalOn(BLUE, 50, 2000);

  
//  individualCycleUpAndDown(RED, 50);
//  individualCycleUpAndDown(GREEN, 50);
//  individualCycleUpAndDown(BLUE, 50);
  
}

void allOff(){
  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, 0);
    pixels.show();
  }
}

uint32_t colorCycle(){
  for(int i=0; i<255; i++){
    uint32_t color = pixels.Color(i, 0, 0);
     pixels.setPixelColor(0, color);
     pixels.show();
     delay(10);
  }
  for(int i=0; i<255; i++){
    uint32_t color = pixels.Color(0, i, 0);
     pixels.setPixelColor(0, color);
     pixels.show();
     delay(10);
  }
  for(int i=0; i<255; i++){
    uint32_t color = pixels.Color(0, 0, i);
     pixels.setPixelColor(0, color);
     pixels.show();
     delay(10);
  }

}

void colorMixes(){
    for(int r=0; r<255; r++){
        uint32_t color = pixels.Color(r, 150, 150);
        pixels.setPixelColor(0, color);
        pixels.show();
        delay(5);
  }
  for(int r=255; r>0; r--){
        uint32_t color = pixels.Color(r, 150, 150);
        pixels.setPixelColor(0, color);
        pixels.show();
        delay(5);
  }

  for(int g=0; g<255; g++){
        uint32_t color = pixels.Color(150, g, 150);
        pixels.setPixelColor(0, color);
        pixels.show();
        delay(5);
  }
  for(int g=255; g>0; g--){
        uint32_t color = pixels.Color(150, g, 150);
        pixels.setPixelColor(0, color);
        pixels.show();
        delay(5);
  }

  for(int b=0; b<255; b++){
        uint32_t color = pixels.Color(150, 150, b);
        pixels.setPixelColor(0, color);
        pixels.show();
        delay(5);
  }
  for(int b=255; b>0; b--){
        uint32_t color = pixels.Color(150, 150, b);
        pixels.setPixelColor(0, color);
        pixels.show();
        delay(5);
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
