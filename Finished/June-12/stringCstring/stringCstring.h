#ifndef STRING_CSTRING_H_
#include <cstring>
#include <iostream>
#include <string>
std::string change1(const char* cstr) { return (std::string(cstr)); }
void change2(std::string str, char* cstr) {
  std::strcpy(cstr, str.c_str());
}
#endif