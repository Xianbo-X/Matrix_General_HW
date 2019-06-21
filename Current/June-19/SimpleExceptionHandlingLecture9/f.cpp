#include "f.hpp"
#include <iostream>
#include "f3.hpp"
using namespace std;
void f1(int x) {
  try {
    f2(x);
  } catch (int) {
    std::cout << "A int exception occurred!--from f1" << std::endl;
  } catch (float) {
    std::cout << "A float exception occurred!--from f1" << std::endl;
  } catch (double) {
    std::cout << "A double exception occurred!--from f1" << std::endl;
  }
  std::cout << "End of f1" << std::endl;
}

void f2(int x) {
  try {
    f3(x);
  } catch (int) {
    std::cout << "A int exception occurred!--from f2" << std::endl;
  } catch (float) {
    std::cout << "A float exception occurred!--from f2" << std::endl;
  }
  std::cout << "End of f2" << std::endl;
}