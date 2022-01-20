#include <Arduino.h>
#include <IRrecv.h>
#include <IRremoteESP8266.h>
#include <IRtext.h>
#include <IRutils.h>

#ifndef IR_READ_h
#define IR_READ_h

void irReadSetup();
void irReadLoop();

#endif
