#ifndef PRINT_VALUE_H_
#define PRINT_VALUE_H_
#include <iostream>
template <typename T, std::size_t N>
void printValues(T (&arr)[N]) {
  for (int i = 0; i < N; i++) {
    std::cout << arr[i] << std::endl;
  }
}
#endif