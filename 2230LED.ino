#include <FastLED.h>

#define LED_PIN 3

#define R_PIN 4
#define G_PIN 5
#define B_PIN 6

#define LEDS 69
CRGB leds[LEDS];
long led;
byte buffer[3];

void setup() {
  Serial.begin(9600); 
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, LEDS);
}

void loop() {
  Serial.readBytes(buffer,3);
  CRGB tempColor = leds[0];
  for (led = 1; led < LEDS; led++) {
    CRGB tempCurrent = leds[led];
    leds[led] = tempColor;
    tempColor = tempCurrent;
  }
  leds[0] = CRGB(buffer[0], buffer[1], buffer[2]);
  FastLED.show();
  delay(10);
}
