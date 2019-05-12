#include "exttime.h"
#include <iostream>
ExtTime::ExtTime(int initHrs, int initMins, int initSecs, ZoneType initZone)
    : zone{initZone} {
  Time::Set(initHrs, initMins, initSecs);
}

ExtTime::ExtTime() : zone{EST} {}
void ExtTime::Set(int hours, int minutes, int seconds, ZoneType timeZone) {
  Time::Set(hours, minutes, seconds);
  zone = timeZone;
}

void ExtTime::Write() const {
  Time::Write();
  switch (zone) {
    case EST:
      std::cout << " EST";
      break;

    case CST:
      std::cout << " CST";
      break;
    case MST:
      std::cout << " MST";
      break;
    case PST:
      std::cout << " PST";
      break;
    case EDT:
      std::cout << " EDT";
      break;
    case CDT:
      std::cout << " CDT";
      break;
    case MDT:
      std::cout << " MDT";
      break;
    case PDT:
      std::cout << " PDT";
      break;
  }
}
