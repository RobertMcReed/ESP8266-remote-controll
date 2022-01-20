#include <Arduino.h>

#include <IRremoteESP8266.h>
#include <IRsend.h>

#ifndef IR_SEND_h
#define IR_SEND_h

void irSendSetup();
void tvPower();
void tvInput();
void avOff();
void avVolUp();
void avVolDown();
void avVolUpPlus();
void avVolDownPlus();
void avMute();
void avInputTV();
void avInputVideo1();
void avInputDVD();
void avInputPhono();
void avInputCD();

#endif
