#include <Arduino.h>
#include "ir_read.h"


void setup() {
  Serial.begin(115200);
  while (!Serial) {
    delay(50);
  }

  irReadSetup();
}

void loop() {
  irReadLoop();
}
