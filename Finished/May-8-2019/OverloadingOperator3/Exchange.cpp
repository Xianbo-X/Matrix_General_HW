#include "Exchange.h"
#include <iostream>
void Exchange::operator()(int &x, int &y) {
  int temp = x;
  x = y;
  y = temp;
  return;
}