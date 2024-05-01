#include <Arduino.h>
#include "ir_send.h"
#include "ir_read.h"
#include "wifi.h"
#include "mqtt.h"
#include "tv_status.h"
#include "button.h"

const bool shouldRead = false;

void setup() {
  Serial.begin(115200);
  delay(500);

  if (!shouldRead) {
    setupWifi();
    irSendSetup();
    setupMQTT();
    setupTvStatus();
    setupButton();
  } else {
    irReadSetup();
  }
}

void loop() {
  if (!shouldRead) {
    mqttLoop();
    wifiLoop();
    tvLoop();
    buttonLoop();
  } else {
    irReadLoop();
  }
}
