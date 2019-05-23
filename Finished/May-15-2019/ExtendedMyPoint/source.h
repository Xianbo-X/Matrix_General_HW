#ifndef SOURCE_H_
#define SOURCE_H_
#include <cmath>

class MyPoint {
 private:
  double x, y;

 public:
  // The no-arg constructor that contruccts a point with coordinates(0,0)
  MyPoint() : x{0}, y{0} {}

  MyPoint(double x, double y) {
    this->x = x;
    this->y = y;
  }
  double getX() const { return x; }
  double getY() const { return y; }

  // display the distance between two points in two-dimensional space.
  double distance(const MyPoint &point) {
    double xdiff = this->x - point.x;
    double ydiff = this->y - point.y;
    return sqrt(xdiff * xdiff + ydiff * ydiff);
  }
};

class ThreeDPoint : public MyPoint {
 private:
  double z;

 public:
  // The no-arg constructor that contruccts a point with coordinates(0,0,0)
  ThreeDPoint() : MyPoint{}, z{0} {}

  ThreeDPoint(double x, double y, double z) : MyPoint{x, y} { this->z = z; }
  double getZ() const { return z; }

  // display the distance between two points in Three-dimensional space.
  double distance(const ThreeDPoint &point) {
    double xdiff = this->getX() - point.getX();
    double ydiff = this->getY() - point.getY();
    double zdiff = this->getZ() - point.getZ();
    return sqrt(xdiff * xdiff + ydiff * ydiff + zdiff * zdiff);
  }
};

#endif