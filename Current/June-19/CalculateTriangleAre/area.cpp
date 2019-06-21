#include "area.hpp"
#include <stdexcept>
using namespace std;
double area(double a, double b, double c) throw (invalid_argument){
  if (a <= 0 || b <= 0 || c <= 0)
    throw invalid_argument("the side length should be positive");
  if (!(a + b > c && a + c > b && b + c > a))
    throw invalid_argument(
        "the side length should fit the triangle inequation");
  double p = (a + b + c) / 2;
  return (sqrt(p * (p - a) * (p - b) * (p - c)));
}