#include "button.h"

namespace Cord {
  Button *Button::_instance = nullptr;

  Button::Button(uint8_t _digitalPin) {
    _instance = this;
    this->_digitalPin = _digitalPin;

    pinMode(_digitalPin, INPUT);
  }

  bool Button::isPressed() {
    _buttonState = digitalRead(this->_digitalPin);

    if (_buttonState != _lastButtonState) {
      return (_buttonState == HIGH);
    }

    _lastButtonState = _buttonState;
    return false;
  } 
}