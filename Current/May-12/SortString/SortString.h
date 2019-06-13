#ifndef SORTSTRING_H_
#include <algorithm>
#include <iostream>
#include <string>
using std::string;
string sort(string &s) {
  string res = s;
  std::sort(res.begin(), res.end(), std::less<char>());
  return res;
}
#endif