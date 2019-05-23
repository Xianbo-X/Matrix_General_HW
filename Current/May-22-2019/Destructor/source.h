#ifndef SOURCE_H_
#define SOURCE_H_

#include <iostream>
using std::cout;
using std::endl;

class A {
 public:
  virtual ~A() { std::cout << "A::~A()called" << std::endl; }
  virtual void Prin() { cout << "Prin come form class A" << endl; }
};

class B : public A {
  char *buf;

 public:
  B(int x) : buf{NULL} { buf = new char[10]; }
  ~B() {
    std::cout << "B::~B()called" << std::endl;
    if (buf != NULL) delete[] buf;
    return;
  }
  void Prin() { cout << "Prin come from class B" << endl; }
};
#endif