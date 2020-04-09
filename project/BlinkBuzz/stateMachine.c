#include <msp430.h>
#include "stateMachine.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "led.h"
#include "state_1.h"

char stateAt = 0; //allows us to use it outside the method

void state_advance() {
  //here we begin our state machine
  switch (stateAt) {

    //these are the states and are deined below
  case 1:
    state1();
    led_update();
    break;

  case 2:    
    state2();
    led_update();
    break;
    
  case 3:
    state3();
    led_update();
    break;
    
  case 4:
    state4();
    led_update();
    break;
  }
  
}

void state1() {

  buzzer_set_period(700);
  stateBegin();
  //static char next = 0;
  /*
  switch(next) { //this will then allows us to repeat within the same state performing different actions    
  case 0:
    green_on = 1;
    red_on = 1;
    next = 1;
    break;
    
  case 1:
    green_on = 0;
    next = 2;
    break;

  case 2:
    red_on = 0;
    next = 3;
    break;

  case 3:
    red_on = 1;
    next = 0; // repeat
    break;
  }
  */
}

void state2() {

  static char next2 = 0;
  buzzer_set_period(800);
  
  switch (next2){
  case 0:
    red_on = 0;
    green_on = 0;
    next2 = 1;
    break;

  case 1:
    red_on = 1;
    green_on = 1;
    next2 = 2;
    break;

  case 2:
    red_on = 0;
    green_on = 0;
    next2 = 0;
    break;
  }
}

void state3() {

  buzzer_set_period(500);
  static char next3 = 0;

  switch(next3) {

  case 0:
    green_on = 1;
    red_on = 0;
    next3 = 1;
    break;

  case 1:
    red_on = 1;
    next3 = 2;
    break;

  case 2:
    green_on = 0;
    next3 = 3;
    break;

  case 3:
    red_on = 0;
    green_on = 0;
    next3 = 0;
    break;
  }
}

void state4() {

  buzzer_set_period(400);
  static char next4 = 0;

  switch (next4) {
  case 0:
    red_on = 0;
    green_on = 0;
    next4 = 1;
    break;

  case 1:
    next4 = 2;
    break;

  case 2:
    next4 = 3;
    break;

  case 3:
    next4 = 4;
    break;

  case 4:
    green_on = 1;
    next4 = 0;
    break;
  }
}
