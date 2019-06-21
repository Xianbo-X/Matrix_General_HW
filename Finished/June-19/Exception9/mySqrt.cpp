#include "mySqrt.hpp"
#include <cmath>
#include "MyException.hpp"

double mySqrt(double dnum) {
  if (dnum < 0) throw MyException{"invalid argument"};
  return sqrt(dnum);
}