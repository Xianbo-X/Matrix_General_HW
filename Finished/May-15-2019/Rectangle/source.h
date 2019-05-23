#ifndef SOURCE_H_
#define SOURCE_H_
#include <iostream>

class Point {
  int x, y;

 public:
  Point(int x, int y) {
    this->x = x;
    this->y = y;
  }
  void Move(int x, int y) {
    this->x += x;
    this->y += y;
  }

  int Getx() const { return x; }
  int Gety() const { return y; }
};

class Rectangle : public Point {
 private:
  int length, width;

 public:
  Rectangle(int x, int y, int length, int width) : Point{x, y} {
    this->length = length;
    this->width = width;
  }
  int Getwidth() const { return width; }
  int Getlength() const { return length; }
  int Getarea() const { return width * length; }
};

#endif