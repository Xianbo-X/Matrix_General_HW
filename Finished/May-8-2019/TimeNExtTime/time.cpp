#include "Time.h"
void Time::Write() const {
  if (hrs < 10) cout << '0';
  cout << hrs << ':';
  if (mins < 10) cout << '0';
  cout << mins << ':';
  if (secs < 10) cout << '0';
  cout << secs;
}
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
  hrs %= 24;
}

Time::Time(int initHrs, int initMins, int initSecs)
    : hrs{initHrs}, mins{initMins}, secs{initSecs} {}
Time::Time() : hrs{0}, mins{0}, secs{0} {}