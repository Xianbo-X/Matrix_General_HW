#ifndef CALCULATOR_HPP_
#define CALCULATOR_HPP_
#include <cctype>
#include <string>
#include "Exception.hpp"
using namespace std;

class calculator {
 public:
  calculator(){};
  string calculate(string expression) {
    int sum = 0;
    int sign = 1;
    if (expression.empty()) throw EmptyExpressionException();

    for (int i = 0; i < expression.size(); i++) {
      if (!isdigit(expression[i]) && expression[i] != '+' &&
          expression[i] != '-')
        throw IllegalSymbolException(i);
      if (i & 1) {
        if (expression[i] == '-') {
          sign = -1;
        } else if (expression[i] == '+') {
          sign = 1;
        } else
          throw MissingOperatorException(i);
      } else {
        if (!isdigit(expression[i])) throw MissingOperandException(i);
        sum = sum + sign * (expression[i] - '0');
      }
    }
    if (!isdigit(expression[expression.size() - 1]))
      throw MissingOperandException(expression.size());
    return gear.int2String(sum);
  }

 private:
  Utils gear;
};
#endif