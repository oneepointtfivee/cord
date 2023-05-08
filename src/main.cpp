#include <Arduino.h> // needed for platformio
#include <BufferedOutput.h> // this stops 'prints' from blocking the arduino loop

#include "pinmap.h"
#include "button.h"
#include "led.h"

// Example of using BufferedOutput to release bytes when there is space in the Serial Tx buffer, extra buffer size 80
createBufferedOutput(BufferedOut, 80, DROP_UNTIL_EMPTY); //speeding up print logic

// STATE
// Mode
const byte MODE_HOME = 0;
const byte MODE_SCALES = 1;
const byte MODE_INSTRUMENTS = 2;
uint8_t selectedMode = MODE_HOME;

// Init
Cord::Button *scalesButton;
Cord::Button *instrumentsButton;
Cord::Button *backButton;

Cord::LED *greenVolumeLED;

void setup() {
  // Serial + Buffer
  Serial.begin(115200); 
  BufferedOut.connect(Serial);  // connect buffered stream to Serial
  BufferedOut.println("Starting up");

  // Init
  // Mode buttons
  scalesButton = new Cord::Button(SCALES_BUTTON_PIN);
  instrumentsButton = new Cord::Button(INSTRUMENTS_BUTTON_PIN);
  backButton = new Cord::Button(BACK_BUTTON_PIN);

  greenVolumeLED = new Cord::LED(VOLUME_GREEN_LED_PIN);
}

void loop() {
  if (scalesButton->isPressed()) {
    selectedMode = MODE_SCALES;
  } else if (instrumentsButton->isPressed()) {
    selectedMode = MODE_INSTRUMENTS;
  } else if (backButton->isPressed()) {
    selectedMode = MODE_HOME;
  }
}