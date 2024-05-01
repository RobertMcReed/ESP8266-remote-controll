#include "tv_status.h"

uint8_t threshold = 50;
uint8_t addr = 0;

boolean thresholdIsValid(uint8_t threshold_to_test) {
  return threshold_to_test > 0 && threshold_to_test < 100 && threshold_to_test != threshold;
};

bool getTvStatus() {
  uint8_t normalizedReading = getPhotoresistor();
  bool isTvOn = normalizedReading > threshold;

  return isTvOn;
};

void setThreshold(uint8_t newThreshold) {
  if (thresholdIsValid(newThreshold)) {
    Serial.println("Setting new threshold: "+ String(newThreshold));
    threshold = newThreshold;
    // set in EEPROM
    EEPROM.put(addr, threshold);
    EEPROM.commit();
  }
};

uint8_t getThreshold() {
  return threshold;
}

void setupTvStatus() {
  // read threshold from EEPROM if it exists and update variable
  uint addr = 0;
  EEPROM.begin(4);
  uint8_t stored_threshold = 0;
  EEPROM.get(addr, stored_threshold);

  if (thresholdIsValid(stored_threshold)) {
    Serial.println("Found stored threshold in EEPROM: "+String(stored_threshold));
    threshold = stored_threshold;
  } else {
    Serial.println("No threshold stored in EEPROM. Using default: "+String(threshold));
  }
};

uint8_t getPhotoresistorValue() {
  return getPhotoresistor();
}
