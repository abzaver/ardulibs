#include "Arduino.h"
#include "timeouter.h"

timeouter::timeouter(void)
{
    delay = 0;//3600000UL; // default 1 hour
}

void timeouter::setDelay(unsigned long v)
{
    delay = v;
    start();
}

unsigned long timeouter::getDelay()
{
  return delay;
}

void timeouter::start()
{
    last_set = millis();
}

int timeouter::getSecondsUntilOver() {
    int secondUntilOver = (last_set + delay - millis()) / 1000;
    if (secondUntilOver <= 0)
      return 0;
    else
      return secondUntilOver;
}

bool timeouter::isOver()
{
    unsigned long now = millis();
    if (now - last_set > delay) {
        last_set = now;
        return true;
    }
    return false;
}
