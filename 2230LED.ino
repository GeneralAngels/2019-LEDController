#include <FastLED.h>

#define LED_PIN 3
#define LEDS 69
#define LOOP_DELAY 10 //100Hz

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
  // BGR Mode
  leds[0] = CRGB(buffer[2], buffer[1], buffer[0]);
  FastLED.show();
  delay(LOOP_DELAY);
}
