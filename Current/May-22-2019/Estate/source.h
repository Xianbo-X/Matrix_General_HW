#ifndef SOURCE_H_
#define SOURCE_H_
#include <cmath>

const double PI = acos(-1);
class Land {
 public:
  Land(double _price = 0, double _size = 0) : price{_price}, size{_size} {}
  virtual double GetArea() = 0;
  virtual double GetPrice() { return price; }
  virtual ~Land(){};

 protected:
  double price,size;
};

class Circle : public Land {
 public:
  Circle(double x, double y) : Land{x, y} {}
  double GetArea() { return PI * size * size; }
  ~Circle() {}
};

class Square : public Land {
 public:
  Square(double x, double y) : Land{x, y} {}
  double GetArea() { return size * size; }
  ~Square() {}
};

class Accountant {
 public:
  Accountant(double x = 0) : money{x} {}
  ~Accountant() {}

  void DevelopEstate(Land *estate) {
    money =money+ estate->GetArea() * estate->GetPrice();
  }
  double CheckMoney() { return money; }

 private:
  double money;
};
#endif