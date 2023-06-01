#include <Arduino.h> // needed for platformio
#include <BufferedOutput.h> // this stops 'prints' from blocking the arduino loop

#include "pinmap.h"

#include "button.h"
#include "encoder.h"
#include "led.h"

// Example of using BufferedOutput to release bytes when there is space in the Serial Tx buffer, extra buffer size 80
createBufferedOutput(BufferedOut, 80, DROP_UNTIL_EMPTY); //speeding up print logic

// STATE
// Mode
const byte MODE_HOME = 0;
const byte MODE_SCALES = 1;
const byte MODE_INSTRUMENTS = 2;
uint8_t selectedMode = MODE_HOME;

const byte VOLUME_LOW = 0;
const byte VOLUME_MEDIUM = 1;
const byte VOLUME_HIGH = 2;
uint8_t selectedVolume = VOLUME_HIGH;

// Init
// Modes
Cord::Button *scalesButton;
Cord::Button *instrumentsButton;
Cord::Button *backButton;

// Volume
Cord::LED *greenVolumeLED;
Cord::LED *orangeVolumeLED;
Cord::LED *redVolumeLED;

// Keys
Cord::Button *cKey;
Cord::Button *cSharpKey;
Cord::Button *dKey;
Cord::Button *dSharpKey;
Cord::Button *eKey; 
Cord::Button *fKey;
Cord::Button *fSharpKey;
Cord::Button *gKey;
Cord::Button *gSharpKey;
Cord::Button *aKey;
Cord::Button *aSharpKey;
Cord::Button *bKey;

// Encoders
Cord::Encoder *selectionEncoder;
Cord::Encoder *volumeEncoder;

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

  // Volume LEDs
  greenVolumeLED = new Cord::LED(VOLUME_GREEN_LED_PIN);
  orangeVolumeLED = new Cord::LED(VOLUME_ORANGE_LED_PIN);
  redVolumeLED = new Cord::LED(VOLUME_RED_LED_PIN);

  // Keys buttons
  cKey = new Cord::Button(C_KEY_PIN);
  cSharpKey = new Cord::Button(C_SHARP_KEY_PIN);
  dKey = new Cord::Button(D_KEY_PIN);
  dSharpKey = new Cord::Button(D_SHARP_KEY_PIN);
  eKey = new Cord::Button(E_KEY_PIN);
  fKey = new Cord::Button(F_KEY_PIN);
  fSharpKey = new Cord::Button(F_SHARP_KEY_PIN);
  gKey = new Cord::Button(G_KEY_PIN);
  gSharpKey = new Cord::Button(G_SHARP_KEY_PIN);
  aKey = new Cord::Button(A_KEY_PIN);
  aSharpKey = new Cord::Button(A_SHARP_KEY_PIN);
  bKey = new Cord::Button(B_KEY_PIN);

  // Encoders
  selectionEncoder = new Cord::Encoder(SELECTION_ENCODER_PIN_A, SELECTION_ENCODER_PIN_B, SELECTION_ENCODER_BUTTON_PIN);
  volumeEncoder = new Cord::Encoder(VOLUME_ENCODER_PIN_A, VOLUME_ENCODER_PIN_B, 0);
}

void adjustVolume() {
  switch (selectedVolume) {
    case VOLUME_LOW:
      greenVolumeLED->turnOff();
      orangeVolumeLED->turnOff();
      redVolumeLED->turnOn();
      break;

    case VOLUME_MEDIUM: 
      greenVolumeLED->turnOff();
      orangeVolumeLED->turnOn();
      redVolumeLED->turnOn();
      break;

    case VOLUME_HIGH:
      greenVolumeLED->turnOn();
      orangeVolumeLED->turnOn();
      redVolumeLED->turnOn();
      break;
      
    default:
      break;
  }
}

void selectMode() {
  if (scalesButton->isPressed()) {
    selectedMode = MODE_SCALES;
  } else if (instrumentsButton->isPressed()) {
    selectedMode = MODE_INSTRUMENTS;
  } else if (backButton->isPressed()) {
    selectedMode = MODE_HOME;
  }
}

void handleKeyPress() {
  if (selectedMode == MODE_SCALES) {
    if (cKey->isPressed()) {
      BufferedOut.println("C Key Pressed");
    } else if (cSharpKey->isPressed()) {
      BufferedOut.println("C# Key Pressed");
    } else if (dKey->isPressed()) {
      BufferedOut.println("D Key Pressed");
    } else if (dSharpKey->isPressed()) {
      BufferedOut.println("D# Key Pressed");
    } else if (eKey->isPressed()) {
      BufferedOut.println("E Key Pressed");
    } else if (fKey->isPressed()) {
      BufferedOut.println("F Key Pressed");
    } else if (fSharpKey->isPressed()) {
      BufferedOut.println("F# Key Pressed");
    } else if (gKey->isPressed()) {
      BufferedOut.println("G Key Pressed");
    } else if (gSharpKey->isPressed()) {
      BufferedOut.println("G# Key Pressed");
    } else if (aKey->isPressed()) {
      BufferedOut.println("A Key Pressed");
    } else if (aSharpKey->isPressed()) {
      BufferedOut.println("A# Key Pressed");
    } else if (bKey->isPressed()) {
      BufferedOut.println("B Key Pressed");
    }
  } 
}

void handleSelectionEncoder() {
  BufferedOut.println(selectionEncoder->getPosition());
  delay(100);
}

void loop() {
  adjustVolume();
  selectMode();
  handleKeyPress();
  handleSelectionEncoder();
}