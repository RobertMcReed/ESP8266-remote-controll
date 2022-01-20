#include "wifi.h"
#include "ir_send.h"

ESP8266AutoIOT app((char*)__SSID__, (char*)__PW__);

void setupWifi() {
  app.disableLED();
  app.root(HTML);
  app.post("/tv/power", tvPower);
  app.post("/tv/input", tvInput);
  app.post("/av/off", avOff);
  app.post("/av/vol/up", avVolUp);
  app.post("/av/vol/down", avVolDown);
  app.post("/av/vol/up/plus", avVolUpPlus);
  app.post("/av/vol/down/plus", avVolDownPlus);
  app.post("/av/mute", avMute);
  app.post("/av/input/tv", avInputTV);
  app.post("/av/input/video1", avInputVideo1);
  app.post("/av/input/dvd", avInputDVD);
  app.post("/av/input/phono", avInputPhono);
  app.post("/av/input/cd", avInputCD);
  // if you need to reset the wifi config, uncomment below
  // app.resetAllSettings();
  app.begin();
}

void wifiLoop() {
  app.loop();
}
