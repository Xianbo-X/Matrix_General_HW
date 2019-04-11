#include <iostream>
#include "Time.h"

using namespace std;

void print(Time& x) {
  cout << "Hour now is " << x.getHour() << endl;
  cout << "Minute now is " << x.getMinute() << endl;
  cout << "Second now is " << x.getSecond() << endl;
}

int main() {
  Time a, b(10000);
  print(a);
  cout << endl;
  print(b);
  return 0;
}