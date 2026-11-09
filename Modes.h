// variables
const uint8_t REPEAT = 3;

////////// Mode 1: Blink
void led_blink(){
  for(int i = 0; i < REPEAT; i++){
  //------------------------------------------------------------
      // leds ON
      for (int i = 0; i < NUM_LEDS; i++) digitalWrite(LED[i], 1);
      delay(1000);
      
      // leds OFF
      for (int i = 0; i < NUM_LEDS; i++) digitalWrite(LED[i], 0);
      delay(1000);
  //-------------------------------------------------------------
  }
}

////////// Mode 2: Alternate
void led_alt(){
  for(int i = 0; i < REPEAT; i++){
  //---------------------------------------------------------------------------
      // toggle first half of leds
      for(int i = 0; i < NUM_LEDS/2; i++) digitalWrite(LED[i], 1);
      delay(1000);
      for(int i = 0; i < NUM_LEDS/2; i++) digitalWrite(LED[i], 0);
      delay(1000);

      // toggle second half of leds
      for(int i = NUM_LEDS-1; i > (NUM_LEDS/2)-1; i--) digitalWrite(LED[i], 1);
      delay(1000);
      // turn OFF second half of leds
      for(int i = NUM_LEDS-1; i > (NUM_LEDS/2)-1; i--) digitalWrite(LED[i], 0);
      delay(1000);
  //----------------------------------------------------------------------------
  }
}

////////// Mode 3: Running Lights
void led_run(){
  const uint8_t DELAY = 250;

  for(int i = 0; i < REPEAT; i++){
  //-----------------------------------------
    // forward run
    for(int i = 0; i < NUM_LEDS; i++){
      digitalWrite(LED[i], 1);
      delay(DELAY);
      digitalWrite(LED[i], 0);
    }

    // reverse run
    for(int i = NUM_LEDS-1; i >= 0; i--){
      digitalWrite(LED[i], 1);
      delay(DELAY);
      digitalWrite(LED[i], 0);
    }
  //------------------------------------------
  }
}
