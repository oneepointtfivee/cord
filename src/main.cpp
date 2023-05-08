#include <Arduino.h> // needed for platformio
#include <BufferedOutput.h> // this stops 'prints' from blocking the arduino loop

#include "pinmap.h"
#include "button.h"
#include "led.h"

//Example of using BufferedOutput to release bytes when there is space in the Serial Tx buffer, extra buffer size 80
createBufferedOutput(BufferedOut, 80, DROP_UNTIL_EMPTY); //speeding up print logic

Cord::Button *scalesButton;
Cord::LED *greenVolumeLED;

void setup() {
  Serial.begin(115200); 
  BufferedOut.connect(Serial);  // connect buffered stream to Serial
  BufferedOut.println("Starting up");

  scalesButton = new Cord::Button(SCALES_BUTTON_PIN);
  greenVolumeLED = new Cord::LED(VOLUME_GREEN_LED_PIN);
}

void loop() {
  if (scalesButton->isPressed()) {
    greenVolumeLED->turnOn();
  } else {
    greenVolumeLED->turnOff();
  }
}