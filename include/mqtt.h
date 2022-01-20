#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "ir_send.h"

#ifndef MQTT_HA_h
#define MQTT_HA_h

void setupMQTT();
void mqttLoop();

#endif
