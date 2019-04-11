#ifndef TIME_H_
#define TIME_H_

class Time {
  int Hour, Minute, Second;

 public:
  Time();
  Time(int totalSeconds);
  int getHour();
  int getMinute();
  int getSecond();
};

#endif