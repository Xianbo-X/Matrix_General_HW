#ifndef INHERITANCE_H
/*TODO:Warning: direct base class inaccessible in derived due to ambiguity;
**   When C:public derivedA,baseA,derivedB
**
*/
#define INHERITANCE_H

#include <iostream>
using std::cout;
using std::endl;
class baseA {
 public:
  baseA();
  ~baseA();
};

class baseB {
 public:
  baseB();
  ~baseB();
};

class derivedA : public baseA {
 public:
  derivedA();
  ~derivedA();
};

class derivedB : public baseA, baseB {
 public:
  derivedB();
  ~derivedB();
};

class C : public derivedA, derivedB {
 public:
  C();
  ~C();
};

#endif