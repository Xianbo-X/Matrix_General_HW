#include <iostream>
#include <map>
#include <set>
typedef std::map<int, std::multiset<int>> mapType;
typedef std::pair<int, std::multiset<int>> pairType;
void dealwith(std::string opt, mapType& mapping) {
  mapType::iterator it;
  int num1, num2;
  if (opt == "new") {
    std::cin >> num1;
    mapping.insert(pairType{num1, std::multiset<int>{}});
    return;
  }
  if (opt == "add") {
    std::cin >> num1 >> num2;
    it = mapping.find(num1);
    if (it != mapping.end()) {
      it->second.insert(num2);
    }
    return;
  }
  if (opt == "out") {
    std::cin >> num1;
    it = mapping.find(num1);
    if (it != mapping.end()) {
      std::multiset<int>::iterator set_it = it->second.begin();
      while (set_it != it->second.end()) {
        std::cout << *set_it;
        if (set_it != it->second.end()) std::cout << " ";
        set_it++;
      }
      std::cout << std::endl;
    }
    return;
  }
  if (opt == "merge") {
    std::cin >> num1 >> num2;
    it = mapping.find(num1);
    mapType::iterator it_2 = mapping.find(num2);
    std::multiset<int>::iterator set_it = it_2->second.begin();

    while (set_it != it_2->second.end()) {
      it->second.insert(*set_it);
      set_it = it_2->second.erase(set_it);
    }
    return;
  }

  if (opt == "unique") {
    std::cin >> num1;
    it = mapping.find(num1);
    std::multiset<int>::iterator set_it, it_fast;
    set_it = it->second.begin();
    while (set_it != it->second.end()) {
      std::multiset<int>::iterator set_it_upper =
          it->second.upper_bound(*set_it);
      std::multiset<int>::iterator set_lower = it->second.lower_bound(*set_it);
      set_lower++;
      it->second.erase(set_lower, set_it_upper);
      set_it++;
    }
    return;
  }
  return;
}
int main() {
  mapType mapping;
  int t;
  std::cin >> t;
  while (t--) {
    std::string opt;
    std::cin >> opt;
    dealwith(opt, mapping);
  }
  return 0;
}