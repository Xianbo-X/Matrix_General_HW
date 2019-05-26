// TODO::friend operator overloading problem, implicit type casting?
// TODO::Why didn't a operator+ have a qualifer const? 
#ifndef SOURCE_H_
#define SOURCE_H_
#include <iomanip>
#include <iostream>

class Complex {
  double re;  // real part of a complex number
  double im;  // imaginary part of a complex number
 public:
  Complex(double real = 0, double imag = 0);
  Complex(const Complex &another);
  ~Complex();
  void set(double real = 0, double imag = 0) {
    this->re = real;
    this->im = imag;
  }
  double real() const { return re; }
  double imag() const { return im; }

  // add any other function needed here
  double norm() const;

  Complex &operator=(const Complex &another);
  Complex operator+(const Complex &another);
  Complex operator-(const Complex &another);
  Complex operator*(const Complex &another);
  Complex operator/(const Complex &another);
  Complex operator+=(const Complex &another);
  Complex operator-=(const Complex &another);
  Complex operator*=(const Complex &another);
  Complex operator/=(const Complex &another);
  Complex operator-();
  bool operator==(const Complex &another);
  bool operator!=(const Complex &another);

  friend Complex operator+(const Complex &left, const Complex &right);
  friend Complex operator-(const Complex &left, const Complex &right);
  friend Complex operator*(const Complex &left, const Complex &right);
  friend Complex operator/(const Complex &left, const Complex &right);
  friend bool operator==(const Complex &left, const Complex &right);
  friend bool operator!=(const Complex &left, const Complex &right);
  friend std::istream &operator>>(std::istream &in, Complex &another);
  friend std::ostream &operator<<(std::ostream &out, const Complex &another);
};
Complex::Complex(double real, double imag) : re{real}, im{imag} {}
Complex::Complex(const Complex &another) {
  this->re = another.re;
  this->im = another.im;
}
Complex::~Complex(){};

double Complex::norm() const {
  return (this->re * this->re + this->im + this->im);
}

Complex &Complex::operator=(const Complex &another) {
  if (this == &another) return *this;
  this->re = another.re;
  this->im = another.im;
  return *this;
}
Complex Complex::operator+(const Complex &another) {
  Complex temp;
  temp.re = this->re + another.re;
  temp.im = this->im + another.im;
  return temp;
}

Complex Complex::operator-(const Complex &another) {
  Complex temp{another};
  return (*this) + -temp;
}

Complex Complex::operator*(const Complex &another) {
  Complex temp;
  temp.re = this->re * another.re - this->im * another.im;
  temp.im = this->im * another.re + this->re * another.im;
  return temp;
}

Complex Complex::operator/(const Complex &another) {
  Complex coax{another.re, -another.im};
  Complex temp{*this * coax};
  temp.re = temp.re / (another.norm());
  temp.im = temp.im / (another.norm());
  return temp;
}

Complex Complex ::operator+=(const Complex &another) {
  *this = *this + another;
  return *this;
}
Complex Complex::operator-=(const Complex &another) {
  *this = *this - another;
  return *this;
}
Complex Complex::operator*=(const Complex &another) {
  *this = *this * another;
  return *this;
}
Complex Complex::operator/=(const Complex &another) {
  *this = *this / another;
  return *this;
}
Complex Complex::operator-() {
  Complex temp;
  temp.re = -this->re;
  temp.im = -this->im;
  return temp;
}
bool Complex::operator==(const Complex &another) {
  if (this->re != another.re) return false;
  if (this->im != another.im) return false;
  return true;
}
bool Complex::operator!=(const Complex &another) {
  return (!(*this == another));
}

Complex operator+(const Complex &left, const Complex &right) {
  //return left+right will cause self-call with no ending.
  Complex temp{left};
  return temp + right;
}
Complex operator-(const Complex &left, const Complex &right) {
  Complex temp{left};
  return temp - right;
}
Complex operator*(const Complex &left, const Complex &right) {
  Complex temp{left};
  return temp * right;
}
Complex operator/(const Complex &left, const Complex &right) {
  Complex temp{left};
  return temp / right;
}
bool operator==(const Complex &left, const Complex &right) {
  Complex temp{left};
  return (temp == right);
}
bool operator!=(const Complex &left, const Complex &right) {
  Complex temp{left};
  return (temp != right);
}
std::istream &operator>>(std::istream &in, Complex &another) {
  char ch;
  double real, imag;
  in >> ch >> real >> ch >> imag >> ch;
  another.set(real, imag);
  return in;
}
std::ostream &operator<<(std::ostream &out, const Complex &another) {
  out << "(" << another.real() << "," << another.imag() << ")";
  return out;
}

#endif