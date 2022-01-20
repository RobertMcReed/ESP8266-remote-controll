#include <Arduino.h>
#include "ir_send.h"
#include "wifi.h"
#include "mqtt.h"

void setup() {
  Serial.begin(115200);
  delay(500);
  setupWifi();
  irSendSetup();
  setupMQTT();
}

void loop() {
  mqttLoop();
  wifiLoop();
}
