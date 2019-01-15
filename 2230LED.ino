#include <FastLED.h>

#define LED_PIN 3

#define R_PIN A0
#define G_PIN A1
#define B_PIN A2

#define LEDS 69
CRGB leds[LEDS];

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, LEDS);
}

long led;
int r,g,b;
void loop() {
  CRGB tempColor = leds[0];
  for (led = 1; led < LEDS; led++) {
    CRGB tempCurrent = leds[led];
    leds[led] = tempColor;
    tempColor = tempCurrent;
  }
  r=analogRead(R_PIN)/4;
  g=analogRead(G_PIN)/4;
  b=analogRead(B_PIN)/4;
  Serial.print(r);
  Serial.print(" ");
  Serial.print(g);
  Serial.print(" ");
  Serial.print(b);
  Serial.println();
  leds[0] = CRGB(r,g,b);
  FastLED.show();
  delay(50);
}
