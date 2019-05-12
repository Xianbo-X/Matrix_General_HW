#ifndef REDCAR_CLASS_HPP_
#define REDCAR_CLASS_HPP
#include <iostream>

class Car {
 private:
 public:
  Car() { std::cout << "Construct a car" << std::endl; }
};

class Wheel {
 private:
 public:
  Wheel() { std::cout << "Construct a wheel" << std::endl; }
};

class RedCar : public Car {
 private:
  Wheel wheel1, Wheel2, Whee3;

 public:
  RedCar() { std::cout << "Construct a red car" << std::endl; }
};

#endif