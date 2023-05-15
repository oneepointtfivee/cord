#ifndef Encoder_H
#define Encoder_H

#include <Arduino.h>
#include <RotaryEncoder.h>

namespace Cord {
  class Encoder {
    private:
      static Encoder *_instance;

      // PINS
      int _encAPin;
      int _encBPin;
      int _encButtonPin;

      RotaryEncoder *_Encoder;
      void _initEncoder();
      static void _updateEncoderWrapper();
      void _updateEncoder();

    public:
      Encoder(uint8_t _encAPin, uint8_t _encBPin, uint8_t _encButtonPin);

      double getPosition();
      bool isPressed();
  };
}

#endif