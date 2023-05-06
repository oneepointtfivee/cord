#include "led.h"

namespace Cord {
  LED *LED::_instance = nullptr;

  LED::LED(uint8_t _digitalPin) {
    _instance = this;

    pinMode(_digitalPin, OUTPUT);
  }

  void LED::turnOn() {
    digitalWrite(_digitalPin, HIGH);
  }

  void LED::turnOff() {
    digitalWrite(_digitalPin, LOW);
  }

  bool LED::isOn() {
    return digitalRead(_digitalPin) == HIGH;
  }

  bool LED::isOff() {
    return digitalRead(_digitalPin) == LOW;
  }
}