#include "ir_send.h"
#include "sony_av.h"
#include "sanyo_tv.h"

// https://github.com/crankyoldgit/IRremoteESP8266/wiki#ir-sending
// w/ 2N3904 NPN transister flat side facing you...
// GND, D2, IR Short Leg (cathode, flat)
// IR Long Leg (anode) to 3.3V 

const uint16_t irPin = 4; // D2
IRsend irsend(irPin);

void irSendSetup() {
  irsend.begin();
};

void sendSanyo(uint64_t necData) {
  irsend.sendNEC(necData);
  delay(10);
  irsend.sendNEC(sanyo_repeat_data);
  delay(10);
  irsend.sendNEC(sanyo_repeat_data);
  delay(10);
  irsend.sendNEC(sanyo_repeat_data);
}

void sendSony(uint64_t sonyData) {
  irsend.sendSony(sonyData, 12, 2);  // 12 bits & 2 repeats (3 total)
}

void tvPower() {
  Serial.println(F("IR_SEND: tvPower"));
  sendSanyo(sanyo_power_data);
};

void tvInput() {
  Serial.println(F("IR_SEND: tvInput"));
  sendSanyo(sanyo_input_data);
};

void avOff() {
  Serial.println(F("IR_SEND: avOff"));
  sendSony(sony_system_off_data_1);
  delay(10);
  sendSony(sony_system_off_data_2);
  delay(10);
  sendSony(sony_system_off_data_3);
  delay(10);
  sendSony(sony_system_off_data_4);
  delay(10);
  sendSony(sony_system_off_data_5);
  delay(10);
  sendSony(sony_system_off_data_6);
  delay(10);
  sendSony(sony_system_off_data_7);
  delay(10);
  sendSony(sony_system_off_data_8);
};

void avVolUp() {
  Serial.println(F("IR_SEND: avVolUp"));
  sendSony(sony_volume_up_data);
};

void avVolDown() {
  Serial.println(F("IR_SEND: avVolDown"));
  sendSony(sony_volume_down_data);
};
void avVolUpPlus() {
  Serial.println(F("IR_SEND: avVolUpPlus"));
  for (int i = 0; i < 10; i++) {
    sendSony(sony_volume_up_data);
    delay(10);
  }
};

void avVolDownPlus() {
  Serial.println(F("IR_SEND: avVolDownPlus"));
  for (int i = 0; i < 10; i++) {
    sendSony(sony_volume_down_data);
    delay(10);
  }
};

void avMute() {
  Serial.println(F("IR_SEND: avMute"));
  sendSony(sony_mute_data);
};

void avInputTV() {
  Serial.println(F("IR_SEND: avInputTV"));
  sendSony(sony_tv_data_1);
  delay(10);
  sendSony(sony_tv_data_2);
  delay(10);
  sendSony(sony_tv_data_3);
  delay(10);
  sendSony(sony_tv_data_4);
  delay(10);
  sendSony(sony_tv_data_5);
};

void avInputVideo1() {
  Serial.println(F("IR_SEND: avInputVideo1"));
  sendSony(sony_video_one_data_1);
  delay(10);
  sendSony(sony_video_one_data_2);
  delay(10);
  sendSony(sony_video_one_data_3);
  delay(10);
  sendSony(sony_video_one_data_4);
  delay(10);
  sendSony(sony_video_one_data_5);
};

void avInputDVD() {
  Serial.println(F("IR_SEND: avInputDVD"));
  sendSony(sony_dvd_data_1);
  delay(10);
  sendSony(sony_dvd_data_2);
  delay(10);
  sendSony(sony_dvd_data_3);
  delay(10);
  // this one only gets sent once
  irsend.sendSony(sony_dvd_data_4, 12, 0);
  delay(10);
  sendSony(sony_dvd_data_5);
};

void avInputPhono() {
  Serial.println(F("IR_SEND: avInputPhono"));
  sendSony(sony_phono_data);
};

void avInputCD() {
  Serial.println(F("IR_SEND: avInputCD"));
  sendSony(sony_cd_data);
};
