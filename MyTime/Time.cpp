#include "Time.h"

Time::Time() : Hour{0}, Minute{0}, Second{0} {}
Time::Time(int totalSeconds) {
  Hour = totalSeconds / 3600;
  totalSeconds %= 3600;
  Minute = totalSeconds / 60;
  totalSeconds %= 60;
  Second = totalSeconds;
}

int Time::getHour() { return Hour; }
int Time::getMinute() { return Minute; }
int Time::getSecond() { return Second; }
