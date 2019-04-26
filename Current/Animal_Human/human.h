#ifndef HUMAN_H
#define HUMAN_H
#include "animal.h"
class human : public animal {
 private:
  std::string string_name;

 public:
  human();
  human(const std::string name);
  void greeting();  //"Hello, I'm _name."
};

human ::human() : string_name{""} {}

#endif  // HUMAN_H