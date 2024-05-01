#include "photoresistor.h"

// 1 leg to A0 and 4.7k pull-down to ground
// other leg to 3.3v

#define photoresistorPin A0 // for ESP8266 microcontroller

const unsigned long READ_DEBOUNCE = 10;
unsigned long lastReadAt = millis() - READ_DEBOUNCE - 1;
uint8_t lastNormalizedValue = 0;

uint8_t getPhotoresistor() {
  if (millis() - lastReadAt > READ_DEBOUNCE) {
    lastReadAt = millis();
    int analog_value = analogRead(photoresistorPin);
    lastNormalizedValue = map(analog_value, 0, 1000, 0, 100);
  }

  return lastNormalizedValue;
}
