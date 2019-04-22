#include "complex.h"
#include <iomanip>
#include <string>

Complex conjugate(const Complex& theComplex) {
  Complex temp;
  temp.setReal(theComplex.getReal);
  temp.setImaginary(theComplex.getImaginary);
  return temp;
}

Complex::Complex() : real{0}, imag{0} {}

Complex::Complex(double re, double im) : real{re}, imag{im} {}

Complex::~Complex() {
  real = 0;
  imag = 0;
}

const double Complex::getReal(void) const { return real; }
const double Complex::getImaginary(void) const { return imag; }
void Complex::setReal(double re) { real = re; }
void Complex::setImaginary(double im) { imag = im; }
void Complex::fromString(const std::string& complexString) {
  // todo;
  std::string complexStr;
  std::cin >> complexStr;
  int pos=complexStr.find('+');
}

Complex Complex::operator+(const Complex& theComplex) {
  this->real += theComplex.real;
  this->imag += theComplex.imag;
}

Complex Complex::operator-(const Complex& theComplex) {
  this->real -= theComplex.real;
  this->imag -= theComplex.imag;
}

Complex Complex::operator*(const Complex& theComplex) {
  this->real = this->real * theComplex.real - this->imag * theComplex.imag;
  this->imag = this->real * theComplex.imag + theComplex.real * this->imag;
  return *this;
}

Complex Complex::operator/(const Complex& theComplex) {
  Complex temp = conjugate(theComplex);
  Complex real = temp * theComplex;
  this->real /= real.getReal();
  this->imag /= real.getImaginary();
  return *this;
}

std::ostream& operator<<(std::ostream& out, Complex& theComplex) {
  out << theComplex.getReal();
  out.setf(std::ios::showpos);
  out << theComplex.getImaginary();
  out.unsetf(std::ios::showpos);
  return out;
}