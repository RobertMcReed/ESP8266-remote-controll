#include "ir_read.h"

// https://github.com/crankyoldgit/IRremoteESP8266/blob/master/examples/IRrecvDumpV2/IRrecvDumpV2.ino
// https://www.adafruit.com/product/157
// w/ the circular part of the IR Receiver facing you...
// D5, GND, 3.3v

const uint16_t receivePin = 14; // this is pin D5
const uint16_t captureBufferSize = 1024;
const uint8_t timeout = 15;
const uint16_t minUnknownSize = 12;
const uint8_t tolerancePercentage = kTolerance; // likely 25%
const bool useSaveBuffer = true;

IRrecv irrecv(receivePin, captureBufferSize, timeout, useSaveBuffer);
decode_results results; // store results

void irReadSetup() {
  irrecv.setTolerance(tolerancePercentage);
  irrecv.enableIRIn();
  Serial.println();
  Serial.printf("\n" D_STR_IRRECVDUMP_STARTUP "\n", receivePin);
}

void irReadLoop() {
  if (irrecv.decode(&results)) {
    if (results.overflow) {
      Serial.println("BUFFER OVERFLOW!");
    }
    Serial.println(resultToSourceCode(&results));
    Serial.println();
    yield();
  }
}
