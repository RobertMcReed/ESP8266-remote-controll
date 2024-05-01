#include "button.h"

/*
Button Setup ----------------------------------------------------------------

To use with internal pullup resistor (Default setting):
    connect one pin of a button high (3.3V or 5V) via a 10k ohm resistor
    connect the other pin to ground 
    connect the high side of the button to your desired pin
*/

#include <Arduino.h>
#include <EasierButton.h>

uint8_t btn_pin = D0;

const uint32_t BUTTON_DEBOUNCE = 1000;

// defaults to 35ms debounce, internal_pullup = true, active_low = true
EasierButton myBtn(btn_pin, BUTTON_DEBOUNCE);

// or void onPress();
// called EVERY time the button is pressed
// except when held during reboot
void onPress() {
  systemPower();
}

void setupButton() {
  // onPress callbacks are fired at the rising edge, every single time
  // only one onPress callback is permitted (overwrite if called again)
  myBtn.setOnPressed(onPress);

  // You can start normally
  myBtn.begin();
}

void buttonLoop() {
  // must call in loop to keep checking the button state
  myBtn.update();
}
