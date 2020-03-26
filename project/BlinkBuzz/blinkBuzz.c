#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

void main (void) {
  
  configureClocks(); // configure clocks

  switch_init(); // initiate the switches

  led_init(); // initiate the LEDS

  buzzer_init(); // initiate the buzzer

  buzzer_set_period(1000);
  
  enableWDTInterrupts(); //allow watchdog interruptions
  
  or_sr(0x18); // CPU off, GIE on
}
