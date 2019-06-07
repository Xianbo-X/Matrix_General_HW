#ifndef MAXVALUE_H_
#define MAXVALUE_H_
#include <cctype>
#include <cstring>

template <class T>
T maxValue(const T value1, const T value2) {
  if (value1 >= value2) return value1;
  return value2;
}

char maxValue(const char value1, const char value2) {
  if (std::isalpha(value1) && std::isalpha(value2)) {
    return (toupper(value1) >= toupper(value2) ? value1 : value2);
  }
  return (value1 >= value2 ? value1 : value2);
}
#endif