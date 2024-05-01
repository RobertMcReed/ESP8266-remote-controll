#include "ir_send.h"
#include "tv_status.h"
#include "sony_av.h"
#include "sanyo_tv.h"
// https://github.com/crankyoldgit/IRremoteESP8266/wiki#ir-sending
// w/ 2N3904 NPN transister flat side facing you...
// GND, irPin, IR Short Leg (cathode, flat)
// IR Long Leg (anode) to 3.3V 

const uint16_t tvIrPin = 4; // D2
const uint16_t avIrPin = 5; // D1
IRsend tvIR(tvIrPin);
IRsend avIR(avIrPin);

bool lastTvStatus = false;
unsigned long lastTvStatusChange = millis();
const uint32_t TV_STATUS_CHANGE_DELAY = 10000;

void irSendSetup() {
  tvIR.begin();
  avIR.begin();
};

void tvSend(uint64_t necData) {
  tvIR.sendNEC(necData);
  delay(10);
  tvIR.sendNEC(sanyo_repeat_data);
  delay(10);
  tvIR.sendNEC(sanyo_repeat_data);
  delay(10);
  tvIR.sendNEC(sanyo_repeat_data);
}

void avSend(uint64_t sonyData) {
  avIR.sendSony(sonyData, 12, 2);  // 12 bits & 2 repeats (3 total)
}

void systemPower() {
  tvPower();
  if (getTvStatus()) {
    avOff();
  } else {
    avInputTV();
  }
}

void tvPower() {
  lastTvStatusChange = millis();
  Serial.println(F("IR_SEND: tvPower"));
  tvSend(sanyo_power_data);
};

void tvInput() {
  Serial.println(F("IR_SEND: tvInput"));
  tvSend(sanyo_input_data);
};

void avOff() {
  Serial.println(F("IR_SEND: avOff"));
  avSend(sony_system_off_data_1);
  delay(10);
  avSend(sony_system_off_data_2);
  delay(10);
  avSend(sony_system_off_data_3);
  delay(10);
  avSend(sony_system_off_data_4);
  delay(10);
  avSend(sony_system_off_data_5);
  delay(10);
  avSend(sony_system_off_data_6);
  delay(10);
  avSend(sony_system_off_data_7);
  delay(10);
  avSend(sony_system_off_data_8);
};

void avVolUp() {
  Serial.println(F("IR_SEND: avVolUp"));
  avSend(sony_volume_up_data);
};

void avVolDown() {
  Serial.println(F("IR_SEND: avVolDown"));
  avSend(sony_volume_down_data);
};

void avVolUpPlus() {
  Serial.println(F("IR_SEND: avVolUpPlus"));
  for (int i = 0; i < 10; i++) {
    avSend(sony_volume_up_data);
    delay(10);
  }
};

void avVolDownPlus() {
  Serial.println(F("IR_SEND: avVolDownPlus"));
  for (int i = 0; i < 10; i++) {
    avSend(sony_volume_down_data);
    delay(10);
  }
};

void avMute() {
  Serial.println(F("IR_SEND: avMute"));
  avSend(sony_mute_data);
};

void avInputTV() {
  Serial.println(F("IR_SEND: avInputTV"));
  avSend(sony_tv_data_1);
  delay(10);
  avSend(sony_tv_data_2);
  delay(10);
  avSend(sony_tv_data_3);
  delay(10);
  avSend(sony_tv_data_4);
  delay(10);
  avSend(sony_tv_data_5);
};

void avInputVideo1() {
  Serial.println(F("IR_SEND: avInputVideo1"));
  avSend(sony_video_one_data_1);
  delay(10);
  avSend(sony_video_one_data_2);
  delay(10);
  avSend(sony_video_one_data_3);
  delay(10);
  avSend(sony_video_one_data_4);
  delay(10);
  avSend(sony_video_one_data_5);
};

void avInputDVD() {
  Serial.println(F("IR_SEND: avInputDVD"));
  avSend(sony_dvd_data_1);
  delay(10);
  avSend(sony_dvd_data_2);
  delay(10);
  avSend(sony_dvd_data_3);
  delay(10);
  // this one only gets sent once
  avIR.sendSony(sony_dvd_data_4, 12, 0);
  delay(10);
  avSend(sony_dvd_data_5);
};

void avInputPhono() {
  Serial.println(F("IR_SEND: avInputPhono"));
  avSend(sony_phono_data);
};

void avInputCD() {
  Serial.println(F("IR_SEND: avInputCD"));
  avSend(sony_cd_data);
};

void tvLoop() {
  bool currentStatus = getTvStatus();

  if (lastTvStatus != currentStatus && millis() - lastTvStatusChange > TV_STATUS_CHANGE_DELAY) {
    lastTvStatusChange = millis();
    lastTvStatus = currentStatus;

    if (currentStatus) {
      Serial.println("TV changed from OFF to ON");
      avInputTV();
    } else {
      Serial.println("TV changed from ON to OFF");
      avOff();
    }
  }
}
