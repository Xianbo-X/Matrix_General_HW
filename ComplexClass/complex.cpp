#include "complex.h"
#include <cmath>
#include <iostream>
using namespace std;

class Complex

{
  double real, imag;

 public:
  Complex(double x = 0, double y = 0);  // constructor, set real = x, imag = y

  void print();  // output the complex number with proper form. e.g. 1+2i

  friend Complex add(const Complex&,
                     const Complex&);  // return sum of two complex numbers

  friend Complex multiply(
      const Complex&, const Complex&);  // return product of two complex numbers
};

Complex::Complex(double x, double y) : real{x}, imag{y} {}
void Complex::print() {
  if ((real) && (imag)) {
    if (imag >= 0)
      cout << real << "+" << imag << "i" << endl;
    else
      cout << real << imag << "i" << endl;
    return;
  };
  if (real) {
    cout << real << endl;
    return;
  }
  if (imag) {
    cout << imag << "i" << endl;
    return;
  }
  cout << 0 << endl;
}

Complex add(const Complex& c1, const Complex& c2) {
  Complex temp;
  temp.real = c1.real + c2.real;
  temp.imag = c1.imag + c2.imag;
  return temp;
}

Complex multiply(const Complex& c1, const Complex& c2) {
  Complex temp;
  temp.real = c1.real * c2.real - c1.imag * c2.imag;
  temp.imag = c1.real * c2.imag + c2.real * c1.imag;
  return temp;
}

int main() {
  double real, imag;
  while (cin >> real >> imag) {
    Complex a = Complex(real, imag);
    cin >> real >> imag;
    Complex b = Complex(real, imag);
    Complex c = add(a, b);
    c.print();
    Complex d = multiply(a, b);
    d.print();
  }
}