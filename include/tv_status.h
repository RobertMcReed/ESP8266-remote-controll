#include <Arduino.h>
#include <EEPROM.h>
#include "photoresistor.h"

#ifndef TV_STATUS_h
#define TV_STATUS_h

bool getTvStatus();
void setThreshold(uint8_t newThreshold);
uint8_t getThreshold();
void setupTvStatus();
uint8_t getPhotoresistorValue();

#endif
