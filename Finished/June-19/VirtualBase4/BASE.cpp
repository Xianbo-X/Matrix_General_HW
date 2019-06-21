#include <iostream>
class baseA {
 public:
  baseA() { std::cout << "This is baseA class." << std::endl; }
  ~baseA(){};
};

class baseB {
 public:
  baseB() { std::cout << "This is baseB class." << std::endl; }
  ~baseB(){};
};

class derivedA : virtual public baseA, public baseB {
 public:
  derivedA() { std::cout << "This is derivedA class." << std::endl; }
};

class derivedB : virtual public baseA, public baseB {
 public:
  derivedB() { std::cout << "This is derivedB class." << std::endl; }
};

class Derived : public derivedB, public derivedA {
 public:
  Derived() { std::cout << "This is Derived class." << std::endl; }
};