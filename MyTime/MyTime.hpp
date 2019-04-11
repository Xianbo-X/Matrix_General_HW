#ifndef TIME_H_INCLUDE
#define TIME_H_INCLUDE

class MyTime {
  int Hour, Minute, Second;

 public:
  MyTime();
  MyTime(int totalSeconds);
  int getHour();
  int getMinute();
  int getSecond();
};
#endif