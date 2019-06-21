#ifndef JUDGE_H_
#define JUDGE_H
#include <cstring>
#include <sstream>
#include <stdexcept>
#include <string>

using namespace std;

class NumberParseException {
 private:
  string error_content;

 public:
  NumberParseException(string str) : error_content{str} {}
  string what_is() { return error_content; }
};

bool isNumber(const char* str) {
  if (str == NULL) return false;
  string temp{str};
  if (temp == "") return false;
  string::iterator it = temp.begin();

  while (it != temp.end()) {
    if (!isdigit(*it)) return false;
    it++;
  }
  return true;
}

int parseNumber(const char* str) {
  int sign = 1;

  if (str == NULL) throw(NumberParseException("NULL"));
  string temp{str};
  if ((*temp.begin()) == '+' || (*temp.begin() == '-')) {
    if (*temp.begin() == '-') sign = -1;
    temp.erase(temp.begin());
  }
  if (!isNumber(temp.c_str())) throw(NumberParseException("Not a number."));
  stringstream ss;
  ss << temp;
  int res;
  ss >> res;
  return sign * res;
}

#endif