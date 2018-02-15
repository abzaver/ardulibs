/*
 created 2018
 by abzaver <abzaver@gmail.com>
 */

#include <timeouter.h>
timeouter waitBeforeBlink;

bool switchLED = false;

void setup() {
  // initialize and start timer
  waitBeforeBlink.setDelay(2000);
  waitBeforeBlink.start();

  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);  
}

void loop(){
  // check timer
  if (waitBeforeBlink.isOver()) {
    waitBeforeBlink.start();
    if (switchLED) {
      digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
    } else {
      digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
    }
    switchLED = !switchLED;
  }
}