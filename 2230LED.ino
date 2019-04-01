#include <FastLED.h>

#define LED_PIN 3
#define LEDS 55
#define LOOP_DELAY 20 //50Hz

CRGB leds[LEDS];
CRGB color, current;
long led;
byte buffer[5];

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, LEDS);
}

void loop() {
  Serial.readBytes(buffer, 5);
  if ((int)buffer[1] > 0) {
    if ((int)buffer[0] == 0) {
      for (led = 0; led < (int)buffer[1]; led++) {
        leds[led] = CRGB(buffer[4], buffer[3], buffer[2]);
      }
    } else {
      for (led = LEDS - 1; led > LEDS - (int)buffer[1] - 1; led--) {
        leds[led] = CRGB(buffer[4], buffer[3], buffer[2]);
      }
    }
  } else {
    if ((int)buffer[0] == 0) {
      color = leds[0];
      for (led = 1; led < LEDS; led++) {
        current = leds[led];
        leds[led] = color;
        color = current;
      }
      // BGR Mode
      leds[0] = CRGB(buffer[4], buffer[3], buffer[2]);
    } else {
      color = leds[LEDS - 1];
      for (led = LEDS - 2; led >= 0; led++) {
        current = leds[led];
        leds[led] = color;
        color = current;
      }
      // BGR Mode
      leds[LEDS - 1] = CRGB(buffer[4], buffer[3], buffer[2]);
    }
  }
  FastLED.show();
  delay(LOOP_DELAY);
}
