#include <stdio.h>
#include <iostream>
#include <string>
#include "stringCstring.h"
int main() {
  std::string s1;
  char *cstr = new char[100];
  std::cin >> cstr;
  std::cout << change1(cstr) << std::endl;
  std::cin >> s1;
  delete[] cstr;
  cstr = new char[s1.size() + 1];
  change2(s1, cstr);
  // std::cout << cstr;
  printf("%s", cstr);
  delete[] cstr;
  return 0;
}