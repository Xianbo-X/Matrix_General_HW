#ifndef SOURCE_H_
#define SOURCE_H_
#include <cmath>
#include <iostream>
#include <string>
using std::string;
class GeometricObject {
 public:
  GeometricObject(string color, bool filled) {
    this->color = color;
    this->filled = filled;
  }

  string getColor() const { return color; }
  void setColor(string color) { this->color = color; }
  bool isFilled() const { return filled; }
  void setFilled(bool filled) { this->filled = filled; }
  string toString() const {
    return "Geometric object color " + color + " filled " +
           ((filled) ? "true" : "false");
  }

 private:
  string color;
  bool filled;
};

class Triangle : public GeometricObject {
 private:
  double side1, side2, side3;

 public:
  Triangle()
      : GeometricObject{"blue", true}, side1{1.0}, side2{1.0}, side3{1.0} {}
  Triangle(double s1, double s2, double s3, string color = "blue",
           bool filled = true)
      : GeometricObject{color, filled}, side1{s1}, side2{s2}, side3{s3} {}
  // accessor
  double getSide1() const { return side1; }
  double getSide2() const { return side2; }
  double getSide3() const { return side3; }
  double getArea() const {
    double p = (side1 + side2 + side3) / 2;
    return sqrt(p * (p - side1) * (p - side2) * (p - side3));
  }
  double getPerimeter() const { return (side1 + side2 + side3); }
};

#endif