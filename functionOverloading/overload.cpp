#include <iostream>
#include <string>

int myplus(const int a, const int b) { return a + b; }
double myplus(const double a, const double b) { return a + b; }
std::string myplus(const std::string& a, const std::string& b) {
  return (a + b);
}

int main() {
  int n;
  int a, b;
  double c, d;
  std::string str1, str2;
  std::cin >> n;
  while (n--) {
    std::cin >> a >> b;
    std::cin >> c >> d;
    std::cin >> str1 >> str2;
    std::cout << myplus(a, b) << std::endl;
    std::cout << myplus(d, c) << std::endl;
    std::cout << myplus(str1, str2) << std::endl;
  }
  return 0;
}
