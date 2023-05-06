#include "button.h"

namespace Cord {
  Button *Button::_instance = nullptr;

  Button::Button(uint8_t _digitalPin) {
    _instance = this;

    pinMode(_digitalPin, INPUT_PULLUP);
  }

  bool Button::isPressed() {
    _buttonState = digitalRead(_digitalPin);

    if (_buttonState != _lastButtonState) {

      if (_buttonState == LOW) {
        return true;
      }
    }

    _lastButtonState = _buttonState;
    return false;
  } 
}