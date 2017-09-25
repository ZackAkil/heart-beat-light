#include "FastLED.h"

#define NUM_LEDS 10
#define DATA_PIN 3
#define CLOCK_PIN 13

// Define the array of leds
CRGB leds[NUM_LEDS];
const int analogInPin = A0;
int sensorValue = 0;

int led_list[10];

void setup() { 
       FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);
        LEDS.setBrightness(20);
        
        pinMode(4, OUTPUT);
        pinMode(2, OUTPUT);
        digitalWrite(4, LOW);
        digitalWrite(2, HIGH);
          Serial.begin(9600);
}
    
long createRGB(byte r, byte g, byte b)
{   
  long RGB = ((long)r << 16L) | ((long)g << 8L) | (long)b;
  return RGB;
}

void loop() { 

 delay(20);
 sensorValue =constrain(analogRead(analogInPin), 450, 550)-500;
 led_list[0] = constrain( sensorValue*7,0,255);
 Serial.println(sensorValue);
   for(int i = 9; i > 0; i--){
    led_list[i] = led_list[i-1];
  }
  for(int i = 0; i < 10; i++){
    leds[i] = createRGB(0,led_list[i],0);
  }
  FastLED.show();
  
  
}
