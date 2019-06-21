#include "f3.hpp"
#include <iostream>

void f3(int x) {
  switch (x) {
    case 1:
      throw(3.0);
    case 2:
      throw(3.0f);
    case 3:
      throw(1);
  }
  std::cout << "End of f3" << std::endl;
}