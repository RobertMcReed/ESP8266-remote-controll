#include "mqtt.h"
#include "ir_send.h"

// how long to wait between connection attempts
uint32_t MQTT_CONNECT_DELAY = 10000;

// how long to wait before advertising to HA
uint32_t MQTT_DISCOVERY_DELAY = 300000;

const unsigned long before = millis() - MQTT_CONNECT_DELAY - MQTT_DISCOVERY_DELAY;
unsigned long last_discovery = before;
unsigned long last_connect_attempt = before;

const char* client_id = "remote_control";
const char *temperature_topic = "remote_control/temperature";
const char *humidity_topic = "remote_control/humidity";
const char *heat_index_topic = "remote_control/heat_index";

WiFiClient wifi_client;
PubSubClient mqtt_client(wifi_client);

void subscribeToTopics() {
  mqtt_client.subscribe("remote_control/tv_power");
  mqtt_client.subscribe("remote_control/tv_input");
  mqtt_client.subscribe("remote_control/av_off");
  mqtt_client.subscribe("remote_control/av_vol_up");
  mqtt_client.subscribe("remote_control/av_vol_down");
  mqtt_client.subscribe("remote_control/av_vol_up_plus");
  mqtt_client.subscribe("remote_control/av_vol_down_plus");
  mqtt_client.subscribe("remote_control/av_mute");
  mqtt_client.subscribe("remote_control/av_input_tv");
  mqtt_client.subscribe("remote_control/av_input_video1");
  mqtt_client.subscribe("remote_control/av_input_dvd");
  mqtt_client.subscribe("remote_control/av_input_phono");
  mqtt_client.subscribe("remote_control/av_input_cd");
}

void publishHomeAssistantDiscovery() {
  last_discovery = millis();
  Serial.println("Sending Home Assistant Configuration Topics...");
  mqtt_client.publish("homeassistant/button/tv_power/config",
    "{\"name\":\"TV Power\",\"cmd_t\":\"remote_control/tv_power\"}"
  );
  mqtt_client.publish("homeassistant/button/tv_input/config",
    "{\"name\":\"TV Input\",\"cmd_t\":\"remote_control/tv_input\"}"
  );
  mqtt_client.publish("homeassistant/button/av_off/config",
    "{\"name\":\"AV Off\",\"cmd_t\":\"remote_control/av_off\"}"
  );
  mqtt_client.publish("homeassistant/button/av_vol_up/config",
    "{\"name\":\"AV Volume Up\",\"cmd_t\":\"remote_control/av_vol_up\"}"
  );
  mqtt_client.publish("homeassistant/button/av_vol_down/config",
    "{\"name\":\"AV Volume Down\",\"cmd_t\":\"remote_control/av_vol_down\"}"
  );
  mqtt_client.publish("homeassistant/button/av_vol_up_plus/config",
    "{\"name\":\"AV Volume Up Plus\",\"cmd_t\":\"remote_control/av_vol_up_plus\"}"
  );
  mqtt_client.publish("homeassistant/button/av_vol_down_plus/config",
    "{\"name\":\"AV Volume Down Plus\",\"cmd_t\":\"remote_control/av_vol_down_plus\"}"
  );
  mqtt_client.publish("homeassistant/button/av_mute/config",
    "{\"name\":\"AV Mute\",\"cmd_t\":\"remote_control/av_mute\"}"
  );
  mqtt_client.publish("homeassistant/button/av_input_tv/config",
    "{\"name\":\"AV Input TV\",\"cmd_t\":\"remote_control/av_input_tv\"}"
  );
  mqtt_client.publish("homeassistant/button/av_input_video1/config",
    "{\"name\":\"AV Input Video1\",\"cmd_t\":\"remote_control/av_input_video1\"}"
  );
  mqtt_client.publish("homeassistant/button/av_input_dvd/config",
    "{\"name\":\"AV Input DVD\",\"cmd_t\":\"remote_control/av_input_dvd\"}"
  );
  mqtt_client.publish("homeassistant/button/av_input_phono/config",
    "{\"name\":\"AV Input Phono\",\"cmd_t\":\"remote_control/av_input_phono\"}"
  );
  mqtt_client.publish("homeassistant/button/av_input_cd/config",
    "{\"name\":\"AV Input CD\",\"cmd_t\":\"remote_control/av_input_cd\"}"
  );
}

void callback(String topic, byte* message, unsigned int length) {
  Serial.print("Received topic: ");
  Serial.println(topic);

  if (topic.indexOf("tv_power") > 0) {
    tvPower();
  } else if (topic.indexOf("tv_input") > 0) {
    tvInput();
  } else if (topic.indexOf("av_off") > 0) {
    avOff();
  } else if (topic.indexOf("av_vol_up") > 0) {
    avVolUp();
  } else if (topic.indexOf("av_vol_down") > 0) {
    avVolDown();
  } else if (topic.indexOf("av_vol_up_plus") > 0) {
    avVolUpPlus();
  } else if (topic.indexOf("av_vol_down_plus") > 0) {
    avVolDownPlus();
  } else if (topic.indexOf("av_mute") > 0) {
    avMute();
  } else if (topic.indexOf("av_input_tv") > 0) {
    avInputTV();
  } else if (topic.indexOf("av_input_video1") > 0) {
    avInputVideo1();
  } else if (topic.indexOf("av_input_dvd") > 0) {
    avInputDVD();
  } else if (topic.indexOf("av_input_phono") > 0) {
    avInputPhono();
  } else if (topic.indexOf("av_input_cd") > 0) {
    avInputCD();
  }
}


bool reconnect() {
  last_connect_attempt = millis();
  if (mqtt_client.connect(client_id, __MQTT_USERNAME__, __MQTT_PASSWORD__)) {
    Serial.println("Connected to MQTT broker!");
    publishHomeAssistantDiscovery();
    subscribeToTopics();
  } else {
    Serial.print("Could not connect to broker: ");
    Serial.println(mqtt_client.state());
  }

  return mqtt_client.connected();
}

void setupMQTT() {
  mqtt_client.setServer(__MQTT_BROKER__, 1883);
  mqtt_client.setCallback(callback);
}

bool connectionOk() {
  if (mqtt_client.connected()) {
    return true;
  }

  if (millis() - last_connect_attempt < MQTT_CONNECT_DELAY) {
    return false;
  }

  return reconnect();
}

void mqttLoop() {
  if (!connectionOk()) { return; }
  if (!mqtt_client.loop()) { return; } // tick for callback
    
  unsigned long now = millis();

  if (now - last_discovery > MQTT_DISCOVERY_DELAY) {
    // publish the discovery config every 5 minutes in case HA was down
    publishHomeAssistantDiscovery();
  }
}
