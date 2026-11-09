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


Date:
  3 Aug 2026
==========================================================================*/
// GPIOs
const uint8_t LED[] = {19,18,5,17,16,4};
const uint8_t NUM_LEDS = sizeof(LED)/sizeof(LED[0]);
const uint8_t SW0 = 32;
const uint8_t SW1 = 33;

// Variables
uint8_t mode = 0;
bool    display_msg = true;

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
    mode = Serial.readStringUntil('\n').toInt();
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
