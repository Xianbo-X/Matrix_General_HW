#ifndef SOURCE_H
#define SOURCE_H
class Point {
 private:
  double x, y;

 public:
  Point();
  Point(double xv, double yv);
  Point(Point& pt);
  double getx();
  double gety();
  void setx(double x);
  void sety(double y);
};

class Circle : public Point {
 private:
  double radius;
  const double PI = 3.14;

 public:
  Circle();
  Circle(double x, double y, double radius = 0);
  Circle(Circle& other);

  // access functions
  double getRadius() const;

  int position(Point& pt);
  // mutual functions
  void setR(double r);
};

class Rectangle : public Point {
 private:
  double xLength;
  double yLength;

 public:
  Rectangle();
  Rectangle(double x, double y, double xLen = 0, double yLen = 0);
  Rectangle(Rectangle& other);

  int position(Point& pt);
  double getXLength() const;
  double getYLength() const;
  double getArea() const;
  double getRatio() const;

  // mutual functions

  void setXLength(double xLen);
  void setYLength(double yLen);
};

#endif