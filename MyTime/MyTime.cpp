// TODO:: can it has a different name with its header file?

#include "MyTime.hpp"
//#include <ctime>
#include <iostream>
#include <string>;

using namespace std;

MyTime::MyTime() {
  /*time_t* nowTime = new time_t(time(NULL));
  tm* nowLocalTime = localtime(nowTime);
  Hour = nowLocalTime->tm_hour;
  Minute = nowLocalTime->tm_min;
  Second = nowLocalTime->tm_sec;
  delete nowTime;
  delete nowLocalTime;
  */
}

MyTime::MyTime(int totalSeconds) {
  /*tm* nowLocalTime =
      localtime((time_t*)&totalSeconds);  // TODO::force or static cast
                                          // totalSeconds into time_t
  Hour = nowLocalTime->tm_hour;
  Minute = nowLocalTime->tm_min;
  Second = nowLocalTime->tm_sec;
  delete nowLocalTime;*/
}

int MyTime::getHour() { return Hour; }
int MyTime::getMinute() { return Minute; }
int MyTime::getSecond() { return Second; }