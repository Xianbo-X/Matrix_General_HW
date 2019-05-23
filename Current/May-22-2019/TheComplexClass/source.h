#ifndef SOURCE_H_
#define SOURCE_H_
class Complex {
  double re;  // real part of a complex number
  double im;  // imaginary part of a complex number
 public:
  double real() const { return re; }
  double imag() const { return im; }

  // add any other function needed here
  Complex operator+(const Complex &other);
  Complex operator-(const Complex &other);
  Complex operator*(const Col)
};

#endif