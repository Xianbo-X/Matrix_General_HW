#include <algorithm>
#include <iostream>
using namespace std;

int CheckDigit(std::string str) {
  int weight = 10;
  std::string::iterator it = str.begin();
  int sum = 0;
  while (it != str.end()) {
    if (*it != '-') {
      sum += (*it - '0') * (weight--);
    }
    it++;
  }

  return 11 - sum % 11;
}

int main() {
  int t;
  std::cin >> t;
  std::string str;
  while (t--) {
    std::cin >> str;
    int num = CheckDigit(str);
    std::cout << str << "-";
    (num == 10) ? std::cout << "X" : std::cout << num;
    std::cout << std::endl;
  }
  return 0;
}