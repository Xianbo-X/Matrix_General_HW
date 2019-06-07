#ifndef DEMO_H_
#define DEMO_H_
#include <iostream>
template <class T>
void demoFunc(const T v1, const T v2) {
  std::cout << "the first generic version of demoFunc()" << std::endl;
  std::cout << "the arguments: " << v1 << " " << v2 << std::endl;
}
template <class T>
void demoFunc(const T v) {
  std::cout << "the second generic version of demoFunc()" << std::endl;
  std::cout << "the argument: " << v << std::endl;
}

void demoFunc(const int v1, const int v2) {
  std::cout << "the ordinary version of demoFunc()" << std::endl;
  std::cout << "the arguments: " << v1 << " " << v2 << std::endl;
}
#endif