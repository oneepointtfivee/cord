#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

namespace Cord {
  class Button {
    private:
      static Button *_instance;

      // PINS
      int _digitalPin;

      // STATES
      bool _buttonState;
      bool _lastButtonState;

    public:
      Button(uint8_t _digitalPin);

      bool isPressed();
  };
}

#endif