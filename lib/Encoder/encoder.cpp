#include "encoder.h"

namespace Cord {
  Encoder *Encoder::_instance = nullptr;

  Encoder::Encoder(uint8_t _encAPin, uint8_t _encBPin, uint8_t _encButtonPin) {
    _instance = this;
    _instance->_encAPin = _encAPin;
    _instance->_encBPin = _encBPin;
    _instance->_encButtonPin = _encButtonPin;

    // PINS
    pinMode(_encButtonPin, INPUT_PULLUP);

    // INIT
    _initEncoder();
  }

  void Encoder::_initEncoder() {
        _Encoder = new RotaryEncoder(_encAPin, _encBPin, RotaryEncoder::LatchMode::TWO03);
        attachInterrupt(digitalPinToInterrupt(_encAPin), _updateEncoderWrapper, CHANGE);
        attachInterrupt(digitalPinToInterrupt(_encBPin), _updateEncoderWrapper, CHANGE);
  }

  //* This interrupt service routine will be called on any change of one of the encoder inputs
  void Encoder::_updateEncoderWrapper() {
    if (_instance) {
        _instance->_updateEncoder();
    }
  }

  void Encoder::_updateEncoder() { 
    _Encoder->tick();
  }

  double Encoder::getPosition() {
      return _Encoder->getPosition();
  }

  bool Encoder::isPressed() {
    return !digitalRead(_encButtonPin);
  }
}