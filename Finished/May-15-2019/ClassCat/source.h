#ifndef SOURCE_H_
#define SOURCE_H_
#include <iostream>

class Cat {
  int data;

 public:
  Cat() : data{0} {
    std::cout << "Default Constructor of Cat is Running" << std::endl;
  }
  Cat(int x) : data{x} {
    std::cout << "Constructor of Cat is Running " << data << std::endl;
  }
  ~Cat() { std::cout << "Destructor of Cat is Running " << data << std::endl; }
};

class Tiger : public Cat {
  int data;

 public:
  Tiger(int x) : Cat{x}, data{x} {
    std::cout << "Constructor of Tiger is Running " << data << std::endl;
  }
  ~Tiger() {
    std::cout << "Destructor of Tiger is Running " << data << std::endl;
  }
};

#endif