// Point Class codes
#include "source.h"

Point::Point() : x{0}, y{0} {}
Point::Point(double xv, double yv) : x{xv}, y{yv} {}

Point::Point(Point& other) {
  this->x = other.x;
  this->y = other.y;
}

double Point::getx() { return x; }
double Point::gety() { return y; }
void Point::setx(double x) { this->x = x; }
void Point::sety(double y) { this->y = y; }

// Circle

Circle::Circle() : radius{0} {
  setx(0);
  sety(0);
}

Circle::Circle(double x, double y, double radius) {
  setx(x);
  sety(y);
  this->radius = radius;
}

Circle::Circle(Circle& other) {
  setx(other.getx());
  sety(other.gety());
  this->radius = other.radius;
}

double Circle::getRadius() const { return this->radius; }
int Circle::position(Point& pt) {
  double section = ((pt.getx() - this->getx()) * (pt.getx() - this->getx())) +
                   ((pt.gety() - this->gety()) * (pt.gety() - this->gety()));
  if (section < radius * radius) return -1;
  if (section > radius * radius) return 1;
  return 0;
}

void Circle::setR(double r) { this->radius = r; }

// Rectangle
Rectangle::Rectangle() : xLength{0}, yLength{0} {
  setx(0);
  sety(0);
}
Rectangle::Rectangle(double x, double y, double xLen, double yLen)
    : xLength{xLen}, yLength{yLen} {
  setx(x);
  sety(y);
}

Rectangle::Rectangle(Rectangle& other) {
  setx(other.getx());
  sety(other.gety());
  this->xLength = other.xLength;
  this->yLength = other.yLength;
}

int Rectangle::position(Point& pt) {
  double xDiff = pt.getx() - this->getx();
  double yDiff = pt.gety() - this->gety();
  if (xDiff > 0 && xDiff < this->xLength && yDiff > 0 && yDiff < this->yLength)
    return -1;
  if (xDiff < 0 || xDiff > this->xLength || yDiff < 0 || yDiff > yLength)
    return 1;
  return 0;
}

double Rectangle::getXLength() const { return xLength; }
double Rectangle::getYLength() const { return yLength; }
double Rectangle::getArea() const { return xLength * yLength; }
double Rectangle::getRatio() const { return xLength / yLength; }

// mutual functions

void Rectangle::setXLength(double xLen) { xLength = xLen; }
void Rectangle::setYLength(double yLen) { yLength = yLen; }