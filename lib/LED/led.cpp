#include "led.h"

namespace Cord {
  LED *LED::_instance = nullptr;

  LED::LED(uint8_t _digitalPin) {
    _instance = this;
    _instance->_digitalPin = _digitalPin;

    pinMode(_digitalPin, OUTPUT);
  }

  void LED::turnOn() {
    digitalWrite(this->_digitalPin, HIGH);
  }

  void LED::turnOff() {
    digitalWrite(this->_digitalPin, LOW);
  }

  bool LED::isOn() {
    return digitalRead(this->_digitalPin) == HIGH;
  }

  bool LED::isOff() {
    return digitalRead(this->_digitalPin) == LOW;
  }
}