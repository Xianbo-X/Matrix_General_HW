#ifndef HUMAN_H
#define HUMAN_H
#include <iostream>
#include "animal.h"

class human : public animal {
 private:
  std::string string_name;

 public:
  human();
  human(const std::string name);
  void greeting() const;  //"Hello, I'm _name."
};

human::human() : string_name{""} {
  setSpecies("Human");
  setEyes(2);
}

human::human(const std::string name) : string_name{name} {
  setSpecies("Human");
  setEyes(2);
}
void human::greeting() const {
  std::cout << "Hello, I'm " << string_name << "." << std::endl;
}

#endif  // HUMAN_H