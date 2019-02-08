#include <FastLED.h>

#define LED_PIN 3
#define LEDS 69
#define LOOP_DELAY 10 //100Hz

CRGB leds[LEDS];
CRGB color, current;
long led;
byte buffer[3];

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, LEDS);
}

void loop() {
  Serial.readBytes(buffer, 3);
  // Check if need to clear
  if (buffer[2] == -1 && buffer[1] == -1 && buffer[0] == -1) {
    color = CRGB(0, 0, 0);
    for (led = 0; led < LEDS; led++) {
      leds[led] = color;
    }
  } else {
    color = leds[0];
    for (led = 1; led < LEDS; led++) {
      current = leds[led];
      leds[led] = color;
      color = current;
    }
    // BGR Mode
    leds[0] = CRGB(buffer[2], buffer[1], buffer[0]);
  }
  FastLED.show();
  delay(LOOP_DELAY);
}
