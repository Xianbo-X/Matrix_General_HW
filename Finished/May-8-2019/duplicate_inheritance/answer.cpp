#include <iostream>
#include "head.h"

DERIVED set(int i, int j) {
  DERIVED temp;
  temp.BASE1::i = i;
  temp.BASE2::i = j;
  return temp;
}
void get(DERIVED &origin) {
  std::cout << "BASE1 i: " << origin.BASE1::i << std::endl;
  std::cout << "BASE2 i: " << origin.BASE2::i << std::endl;
}