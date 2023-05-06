#ifndef LED_H
#define LED_H

#include <Arduino.h>

namespace Cord {
  class LED {
    private:
      static LED *_instance;

      // PINS
      int _digitalPin;

    public:
      LED(uint8_t _digitalPin);

      void turnOn();
      void turnOff();

      bool isOn();
      bool isOff();
  };
}

#endif