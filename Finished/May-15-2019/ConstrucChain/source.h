#ifndef SOURCE_H_
#define SOURCE_H_
#include <iostream>
class B {
 public:
  B() { std::cout << "In B()" << std::endl; }
  ~B() { std::cout << "In ~B()" << std::endl; }
};
class A : public B {
 public:
  A() { std::cout << "In A()" << std::endl; }
  ~A() { std::cout << "In ~A()" << std::endl; }
};

class C : public B {
 public:
  C() { std::cout << "In C()" << std::endl; }
  ~C() { std::cout << "In ~C()" << std::endl; }
};

class D : public C, public A {
 public:
  D() { std::cout << "In D()" << std::endl; }
  ~D() { std::cout << "In ~D()" << std::endl; }
};

#endif