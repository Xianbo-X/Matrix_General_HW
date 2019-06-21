#ifndef SOURCE_H_
#define SOURCE_H_
#include <iostream>
#include <stdexcept>
using namespace std;
void f3(int x);
void f2(int x);
void f1(int x) {
  try {
    f2(x);
  } catch (double) {
    std::cout << "A double exception occurred!--from f1" << std::endl;
  }
  std::cout << "End of f1" << std::endl;
}
void f2(int x) {
  try {
    f3(x);
  } catch (int) {
    std::cout << "A int exception occurred!--from f2" << std::endl;
  } catch (float) {
    std::cout << "A float exception occurred!--from f2" << std::endl;
  }
  std::cout << "End of f2" << std::endl;
}

void f3(int x) {
  switch (x) {
    case 1:
      throw(3.0);
    case 2:
      throw(3.0f);
    case 3:
      throw(1);
  }
  std::cout << "End of f3" << std::endl;
}
#endif