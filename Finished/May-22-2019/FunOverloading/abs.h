#ifndef ABS_H_
#define ABS_H_
#include <iostream>
int abs(int x) {
  std::cout << "Using integer version of abs()." << std::endl;
  return (x > 0 ? x : -x);
}

long int abs(long int x) {
  std::cout << "Using long integer version of abs()." << std::endl;
  return (x > 0 ? x : -x);
}

double abs(double x) {
  std::cout << "Using floating-point version of abs()." << std::endl;
  return (x > 0 ? x : -x);
}
#endif