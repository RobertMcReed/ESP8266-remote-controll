#include <Arduino.h>

// SONY - each command is sent three times (except for sony_dvd_raw_4)


// A/V OFF
uint16_t sony_av_off_raw[25] = {2446, 566,  1220, 572,  594, 598,  1200, 592,  606, 588,  1198, 568,  628, 566,  602, 592,  1194, 598,  600, 568,  630, 564,  622, 572,  1194};  // SONY A91
uint32_t sony_av_off_address = 0x11;
uint32_t sony_av_off_command = 0x15;
uint64_t sony_av_off_data = 0xA91;



// SYSTEM_OFF
uint16_t sony_system_off_raw_1[31] = {2418, 592,  1194, 572,  1226, 566,  1200, 590,  596, 598,  1198, 566,  1220, 572,  596, 598,  600, 592,  604, 590,  1198, 568,  628, 566,  600, 592,  604, 588,  598, 596,  602};  // SONY 7620
uint32_t sony_system_off_address_1 = 0x4;
uint32_t sony_system_off_command_1 = 0x37;
uint64_t sony_system_off_data_1 = 0x7620;


uint16_t sony_system_off_raw_2[25] = {2416, 572,  1226, 590,  1196, 570,  1226, 564,  1202, 588,  598, 596,  1202, 564,  622, 570,  606, 588,  600, 594,  604, 590,  598, 572,  1226};  // SONY F41
uint32_t sony_system_off_address_2 = 0x10;
uint32_t sony_system_off_command_2 = 0x2F;
uint64_t sony_system_off_data_2 = 0xF41;


uint16_t sony_system_off_raw_3[25] = {2416, 594,  1202, 564,  1222, 568,  1196, 594,  1202, 564,  624, 568,  1196, 594,  602, 590,  1196, 572,  626, 566,  620, 572,  604, 590,  598};  // SONY F50
uint32_t sony_system_off_address_3 = 0x1;
uint32_t sony_system_off_command_3 = 0x2F;
uint64_t sony_system_off_data_3 = 0xF50;


uint16_t sony_system_off_raw_4[25] = {2414, 598,  1200, 566,  1220, 570,  1196, 596,  1202, 564,  622, 570,  1194, 596,  602, 592,  606, 586,  1200, 568,  630, 562,  604, 590,  596};  // SONY F48
uint32_t sony_system_off_address_4 = 0x2;
uint32_t sony_system_off_command_4 = 0x2F;
uint64_t sony_system_off_data_4 = 0xF48;


uint16_t sony_system_off_raw_5[25] = {2422, 590,  1198, 592,  1194, 572,  1224, 566,  1200, 592,  606, 588,  1198, 568,  630, 564,  1202, 588,  1198, 568,  1228, 564,  602, 590,  598};  // SONY F5C
uint32_t sony_system_off_address_5 = 0x7;
uint32_t sony_system_off_command_5 = 0x2F;
uint64_t sony_system_off_data_5 = 0xF5C;


uint16_t sony_system_off_raw_6[25] = {2418, 592,  1194, 572,  1226, 566,  1200, 590,  1196, 570,  626, 566,  1200, 592,  596, 598,  1200, 566,  1220, 572,  606, 588,  1198, 592,  606};  // SONY F5A
uint32_t sony_system_off_address_6 = 0xB;
uint32_t sony_system_off_command_6 = 0x2F;
uint64_t sony_system_off_data_6 = 0xF5A;


uint16_t sony_system_off_raw_7[25] = {2422, 588,  1198, 568,  1198, 592,  1194, 596,  1200, 566,  620, 572,  1194, 598,  598, 594,  604, 564,  1222, 570,  1196, 594,  602, 590,  596};  // SONY F4C
uint32_t sony_system_off_address_7 = 0x6;
uint32_t sony_system_off_command_7 = 0x2F;
uint64_t sony_system_off_data_7 = 0xF4C;


uint16_t sony_system_off_raw_8[31] = {2422, 588,  1198, 566,  1200, 592,  1194, 598,  1200, 566,  620, 572,  1194, 598,  600, 594,  1192, 572,  1224, 568,  1198, 592,  604, 588,  1198, 568,  1196, 594,  604, 588,  1198};  // SONY 7AED
uint32_t sony_system_off_address_8 = 0xB7;
uint32_t sony_system_off_command_8 = 0x2F;
uint64_t sony_system_off_data_8 = 0x7AED;




// VOLUME_UP
uint16_t sony_volume_up_raw[25] = {2446, 566,  602, 592,  1194, 596,  600, 594,  604, 564,  1222, 570,  596, 596,  602, 592,  604, 588,  598, 570,  628, 566,  622, 572,  1204};  // SONY 481
uint32_t sony_volume_up_address = 0x10;
uint32_t sony_volume_up_command = 0x12;
uint64_t sony_volume_up_data = 0x481;



// VOLUME_DOWN
uint16_t sony_volume_down_raw[25] = {2446, 566,  1200, 592,  1194, 596,  602, 568,  630, 562,  1204, 588,  598, 596,  602, 592,  606, 562,  624, 568,  630, 564,  602, 592,  1194};  // SONY C81
uint32_t sony_volume_down_address = 0x10;
uint32_t sony_volume_down_command = 0x13;
uint64_t sony_volume_down_data = 0xC81;



// MUTE
uint16_t sony_mute_raw[25] = {2442, 570,  628, 566,  622, 572,  1194, 598,  600, 594,  1204, 562,  624, 570,  628, 564,  602, 594,  604, 590,  598, 594,  602, 566,  1220};  // SONY 281
uint32_t sony_mute_address = 0x10;
uint32_t sony_mute_command = 0x14;
uint64_t sony_mute_data = 0x281;



// TV
uint16_t sony_tv_raw_1[25] = {2440, 570,  606, 588,  1198, 592,  604, 564,  1222, 568,  598, 596,  1200, 590,  1196, 570,  628, 566,  632, 562,  604, 590,  596, 596,  1200};  // SONY 561
uint32_t sony_tv_address_1 = 0x10;
uint32_t sony_tv_command_1 = 0x6A;
uint64_t sony_tv_data_1 = 0x561;


uint16_t sony_tv_raw_2[25] = {2416, 594,  602, 590,  596, 572,  626, 568,  1196, 594,  1202, 588,  1198, 568,  628, 564,  1202, 590,  596, 596,  602, 568,  630, 564,  622};  // SONY 1D0
uint32_t sony_tv_address_2 = 0x1;
uint32_t sony_tv_command_2 = 0x38;
uint64_t sony_tv_data_2 = 0x1D0;


uint16_t sony_tv_raw_3[25] = {2420, 592,  606, 588,  1198, 592,  1194, 574,  1202, 588,  598, 594,  1202, 564,  624, 570,  1196, 596,  600, 592,  606, 588,  600, 570,  628};  // SONY 750
uint32_t sony_tv_address_3 = 0x1;
uint32_t sony_tv_command_3 = 0x2E;
uint64_t sony_tv_data_3 = 0x750;


uint16_t sony_tv_raw_4[25] = {2414, 596,  602, 590,  606, 562,  624, 570,  1196, 594,  1202, 590,  1198, 568,  628, 564,  1202, 590,  598, 596,  600, 568,  630, 564,  622};  // SONY 1D0
uint32_t sony_tv_address_4 = 0x1;
uint32_t sony_tv_command_4 = 0x38;
uint64_t sony_tv_data_4 = 0x1D0;


uint16_t sony_tv_raw_5[25] = {2422, 590,  596, 596,  602, 568,  1218, 572,  604, 590,  598, 596,  1202, 566,  622, 572,  1194, 596,  600, 594,  604, 590,  596, 572,  626};  // SONY 250
uint32_t sony_tv_address_5 = 0x1;
uint32_t sony_tv_command_5 = 0x24;
uint64_t sony_tv_data_5 = 0x250;



// VIDEO1
uint16_t sony_video_one_raw_1[25] = {2440, 570,  596, 598,  1198, 592,  606, 562,  624, 570,  628, 566,  1198, 592,  606, 588,  600, 594,  602, 566,  630, 562,  624, 570,  1196};  // SONY 441
uint32_t sony_video_one_address_1 = 0x10;
uint32_t sony_video_one_command_1 = 0x22;
uint64_t sony_video_one_data_1 = 0x441;


uint16_t sony_video_one_raw_2[25] = {2414, 596,  600, 592,  604, 564,  622, 572,  1194, 596,  1200, 592,  1196, 570,  626, 568,  1198, 594,  604, 588,  598, 570,  626, 568,  630};  // SONY 1D0
uint32_t sony_video_one_address_2 = 0x1;
uint32_t sony_video_one_command_2 = 0x38;
uint64_t sony_video_one_data_2 = 0x1D0;


uint16_t sony_video_one_raw_3[25] = {2422, 588,  598, 596,  1202, 564,  1200, 590,  1196, 596,  602, 566,  1220, 572,  604, 588,  1198, 594,  604, 564,  622, 572,  626, 568,  598};  // SONY 750
uint32_t sony_video_one_address_3 = 0x1;
uint32_t sony_video_one_command_3 = 0x2E;
uint64_t sony_video_one_data_3 = 0x750;


uint16_t sony_video_one_raw_4[25] = {2422, 590,  598, 596,  1200, 590,  1196, 570,  1196, 596,  602, 592,  1194, 572,  626, 568,  1196, 594,  1202, 588,  598, 570,  1226, 566,  602};  // SONY 75A
uint32_t sony_video_one_address_4 = 0xB;
uint32_t sony_video_one_command_4 = 0x2E;
uint64_t sony_video_one_data_4 = 0x75A;


uint16_t sony_video_one_raw_5[25] = {2418, 592,  604, 588,  598, 570,  626, 566,  632, 562,  604, 590,  598, 596,  1200, 566,  1220, 572,  604, 588,  598, 596,  602, 590,  606};  // SONY 30
uint32_t sony_video_one_address_5 = 0x1;
uint32_t sony_video_one_command_5 = 0x40;
uint64_t sony_video_one_data_5 = 0x30;



// DVD
uint16_t sony_dvd_raw_1[25] = {2442, 544,  1222, 594,  602, 590,  1196, 570,  1226, 564,  1200, 590,  1196, 570,  1228, 564,  602, 592,  606, 586,  600, 594,  604, 566,  1220};  // SONY BE1
uint32_t sony_dvd_address_1 = 0x10;
uint32_t sony_dvd_command_1 = 0x7D;
uint64_t sony_dvd_data_1 = 0xBE1;


uint16_t sony_dvd_raw_2[25] = {2418, 594,  604, 590,  596, 572,  626, 568,  1198, 594,  1202, 588,  1198, 568,  630, 564,  1200, 590,  596, 596,  602, 568,  630, 564,  624};  // SONY 1D0
uint32_t sony_dvd_address_2 = 0x1;
uint32_t sony_dvd_command_2 = 0x38;
uint64_t sony_dvd_data_2 = 0x1D0;


uint16_t sony_dvd_raw_3[25] = {2422, 590,  598, 596,  1202, 590,  1196, 570,  1196, 596,  602, 592,  1194, 572,  626, 568,  1198, 594,  604, 590,  598, 596,  602, 568,  630};  // SONY 750
uint32_t sony_dvd_address_3 = 0x1;
uint32_t sony_dvd_command_3 = 0x2E;
uint64_t sony_dvd_data_3 = 0x750;


// ONLY SEND THIS ONCE!!!
uint16_t sony_dvd_raw_4[125] = {2414, 596,  600, 592,  1204, 562,  1224, 568,  1198, 594,  604, 588,  1198, 568,  628, 566,  622, 572,  1194, 598,  600, 594,  1204, 564,  1202, 588,  1198, 592,  604, 564,  622, 572,  1194, 598,  600, 592,  604, 590,  1196, 570,  628, 12964,  2416, 594,  602, 592,  1194, 572,  1226, 564,  1200, 592,  596, 596,  1200, 568,  630, 564,  604, 590,  1196, 594,  602, 566,  1220, 572,  1194, 596,  1200, 590,  596, 572,  624, 568,  1198, 594,  604, 590,  596, 598,  1198, 568,  630, 12984,  2418, 594,  602, 592,  1196, 570,  1226, 564,  1200, 590,  596, 598,  1198, 568,  630, 562,  604, 590,  1196, 596,  602, 568,  1220, 572,  1194, 598,  1200, 566,  630, 564,  624, 570,  1196, 594,  602, 592,  606, 588,  1198, 568,  630};  // SONY 74B92
uint32_t sony_dvd_address_4 = 0x1A;
uint32_t sony_dvd_command_4 = 0x24AE;
uint64_t sony_dvd_data_4 = 0x74B92;


uint16_t sony_dvd_raw_5[25] = {2414, 596,  600, 592,  606, 564,  624, 570,  628, 566,  600, 594,  604, 590,  1196, 570,  1226, 566,  600, 592,  606, 588,  598, 594,  604};  // SONY 30
uint32_t sony_dvd_address_5 = 0x1;
uint32_t sony_dvd_command_5 = 0x40;
uint64_t sony_dvd_data_5 = 0x30;



// PHONO
uint16_t sony_phono_raw[25] = {2448, 562,  604, 590,  596, 596,  600, 594,  604, 590,  596, 572,  1226, 566,  600, 594,  604, 590,  598, 596,  600, 568,  630, 564,  1202};  // SONY 41
uint32_t sony_phono_address = 0x10;
uint32_t sony_phono_command = 0x20;
uint64_t sony_phono_data = 0x41;



// CD
uint16_t sony_cd_raw[25] = {2444, 566,  1198, 594,  604, 588,  1198, 568,  628, 564,  622, 572,  1194, 596,  602, 592,  604, 564,  624, 570,  626, 568,  598, 596,  1202};  // SONY A41
uint32_t sony_cd_address = 0x10;
uint32_t sony_cd_command = 0x25;
uint64_t sony_cd_data = 0xA41;
