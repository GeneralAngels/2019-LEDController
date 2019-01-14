#include <FastLED.h>

#define PIN 3
#define LEDS 60
CRGB leds[LEDS];

void setup() {
  Serial.begin(115200);
  FastLED.addLeds<WS2812, PIN, GRB>(leds, LEDS);
  Serial.println("Arduino Init");
}

long led;
String color;
void loop() {
  color = Serial.readString();
  if (color != "") {
    Serial.println(color);
    CRGB tempColor = leds[0];
    for (led = 1; led < LEDS; led++) {
      CRGB tempCurrent = leds[led];
      leds[led] = tempColor;
      tempColor = tempCurrent;
    }
    leds[0] = strtol(&color[0], NULL, 16);
    FastLED.show();
  }
  delay(10);
}
