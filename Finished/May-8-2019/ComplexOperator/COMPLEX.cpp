#include "COMPLEX.h"
#include <iomanip>
#include <iostream>
COMPLEX::COMPLEX(double r, double i) : real{r}, image{i} {}
COMPLEX::COMPLEX(const COMPLEX &other) {
  this->real = other.real;
  this->image = other.image;
}

void COMPLEX::print() {
  if (!(real && image)) {
    std::cout << "0" << std::endl;
    return;
  }
  if (!real) {
    std::cout << image << 'i' << std::endl;
    return;
  }
  if (!image) {
    std::cout << real << std::endl;
    return;
  }
  std::cout << real;
  if (image < 0)
    std::cout << "-" << (-image) << "i" << std::endl;
  else {
    std::cout << "+" << image << "i" << std::endl;
  }
}

COMPLEX COMPLEX::operator+(const COMPLEX &other) {
  COMPLEX res;
  res.real = this->real + other.real;
  res.image = this->image + other.image;
  return res;
}

COMPLEX COMPLEX::operator-(const COMPLEX &other) {
  COMPLEX temp{other};
  return (*this + -temp);
}

COMPLEX COMPLEX::operator-() {
  COMPLEX temp;
  temp.real = -this->real;
  temp.image = -this->image;
  return temp;
}

COMPLEX COMPLEX::operator=(const COMPLEX &other) {
  if (this == &other) return *this;
  this->real = other.real;
  this->image = other.image;
  return *this;
}

COMPLEX &COMPLEX::operator++() {
  this->real++;
  this->image++;
  return *this;
}

COMPLEX COMPLEX::operator++(int) {
  COMPLEX temp{*this};
  ++*this;
  return temp;
}

COMPLEX &COMPLEX::operator--() {
  this->real--;
  this->image--;
  return *this;
}
COMPLEX COMPLEX::operator--(int) {
  COMPLEX temp{*this};
  --*this;
  return temp;
}