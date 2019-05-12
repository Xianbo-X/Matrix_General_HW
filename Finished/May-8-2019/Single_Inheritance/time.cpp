#include "time.h"

void Time::Set(int hours, int minutes, int seconds) {
  hrs = hours;
  mins = minutes;
  secs = seconds;
}

void Time::Increment() {
  secs++;
  mins += secs / 60;
  hrs += mins / 60;
  secs %= 60;
  mins %= 60;
  hrs%=24;
}

Time::Time(int initHrs, int initMins, int initSecs)
    : hrs{initHrs}, mins{initMins}, secs{initSecs} {}
Time::Time() : hrs{0}, mins{0}, secs{0} {}