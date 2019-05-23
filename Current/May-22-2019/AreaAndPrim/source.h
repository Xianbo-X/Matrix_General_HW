#ifndef SOURCE_H_
#define SOURCE_H_
class Shape {
 public:
  Shape(double _x, double _y = 0) : x{_x}, y{_y} {}
  virtual double GetArea() = 0;
  virtual double GetPerim() = 0;
  virtual ~Shape(){}//TODO:pure virtual destructors cause error

 protected:
  double x, y;
};

class Rectangle : public Shape {
 public:
  Rectangle(double x, double y) : Shape{x, y} {}
  double GetArea() { return (x * y); }
  double GetPerim() { return (2 * x + 2 * y); }
  ~Rectangle() {}  // TODO:When virtual destructor is defined as private, it
                   // throws me an error.
};

extern const double PI;
class Circle : public Shape {
 public:
  Circle(double x) : Shape{x} {}
  double GetArea() { return (PI * x * x); }
  double GetPerim() { return (2 * PI * x); }
  ~Circle() {}
};

#endif