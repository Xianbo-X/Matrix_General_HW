#include <algorithm>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
std::string decode(std::string str) {
  if (!isdigit(*(str.end() - 1))) str += "1";
  std::string temp = "";
  std::string::iterator it1, it2, it3;
  while (*(str.end() - 1) == ' ') {
    str.erase(str.end() - 1);
  }

  while (!str.empty()) {
    it1 = str.begin();
    while (it1 != str.end() && !isdigit(*it1)) {
      it1++;
    }
    temp.append(str.begin(), it1 - 1);
    str.assign(it1 - 1, str.end());

    if (str == "") continue;
    it1 = str.begin() + 1;
    while (it1 != str.end() && isdigit(*it1)) {
      it1++;
    }
    int times;
    std::stringstream ss;
    ss << std::string{str.begin() + 1, it1};
    ss >> times;
    if (times) temp.append(times, *(str.begin()));
    if (it1 != str.end())
      str.assign(it1, str.end());
    else
      str = "";
  }

  return temp;
}

int main() {
  std::string str;
  while (std::cin >> str, str != "x") 
  std::cout << decode(str) << std::endl;

  return 0;
}