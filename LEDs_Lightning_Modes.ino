/*========================================================================
                        LEDs Lightning Modes
==========================================================================
Description:
  This program has LEDs lightning modes which depends on the two switches.
  Mode 1: Blink
  Mode 2: Alternate
  Mode 3: Running Lights

Programmer:
  Gyro A. Madrona

Additional Documentation:
  Mark Garcia
  
Date:
  3 Aug 2026
==========================================================================*/
// GPIOs
const uint8_t LED[] = {19,18,5,17,16,4};
const uint8_t NUM_LEDS = sizeof(LED)/sizeof(LED[0]);

/*------------------------------------------------------------
  sizeof() returns the number of bytes occupied by an element.

  - sizeof(LED) = 6 bytes.
  - sizeof(LED[0]) = 1 byte.
  - 6 / 1 = 6.

  Hard-coding the vlaue automatically means that if you add
  or remove LEDs from the array, the program can adjust
  accordingly.
/*------------------------------------------------------------*/

const uint8_t SW0 = 32;
const uint8_t SW1 = 33;

// Variables
uint8_t mode = 0;
bool    display_msg = true;

/*------------------------------------------------------------
  uint8_t mode = 0; stores the LED mode as per input selection
  Value	  Meaning
    0	    No valid mode selected yet
    1	    Blink
    2	    Alternate
    3	    Running Lights

  bool display_msg = true; acts as a control mechanism
  if display_msg is true, the program displays the menu
  selection, then changes to false.
  This prevents the meny from being repeatedly print
  everytime loop() executes.
------------------------------------------------------------*/

void mode_msg(){
  Serial.println(
    "\nSelect Mode:\n"
    "1. Blink\n"
    "2. Alternate\n"
    "3. Running"
  );
}

void setup(){
  // Baud rate
  Serial.begin(9600);

  // Inputs
  pinMode(SW0, INPUT_PULLDOWN);
  pinMode(SW1, INPUT_PULLDOWN);

/*------------------------------------------------------------
  pinMode(SW0, INPUT_PULLDOWN);
  pinMode(SW1, INPUT_PULLDOWN);

  These configure GPIO 32 and GPIO 33 as input pins with internal
  pull-down resistors.

  What's a pull-down resistor?
  Imagine a switch connected between a GPIO pin and 3.3V.
  When the switch is pressed, GPIO reads HIGH (1).
  When the switch is released, GPIO reads LOW (0).

  The internal pull-down resistor helps keep the pin at a stable
  LOW state when the switch isn't pressed.
------------------------------------------------------------*/

  // Outputs
  for(int i = 0; i < NUM_LEDS; i++){
    pinMode(LED[i], OUTPUT);
  }
}

#include "Modes.h"

void loop(){
  if(display_msg){
    mode_msg();
    display_msg = false;
  }

  // Reads serial monitor
  if(Serial.available()){
    /*Serial.available() checks whether there are
    incoming bytes waiting to be read through serial
    communication.
    If there is incoming data, it returns a positive
    number.*/

    mode = Serial.readStringUntil('\n').toInt();
    /*Serial.readStringUntil('\n') reads incoming
    character until it encounters a newline character,
    as stated by '\n'
    
    Suppose you enter an integer of '2', the function
    returns it asa string. .toInt() converts the string
    into an integer.*/
    
    Serial.printf("Mode %d selected\n",mode);

    // LEDs mode
    switch (mode){
      case 1:  led_blink();  break;
      case 2:  led_alt();    break;
      case 3:  led_run();    break;
      default: Serial.println("Invalid Input");  break;
    }

    display_msg = true;
  }
}
