#include <iostream>
#include <string>
#include "Biginteger.h"
using namespace std;

int main() {
  string s1, s2, s3, s4;
  cin >> s1 >> s2;
  cin >> s4;
  BigInteger a(s1);
  BigInteger b(s2);
  BigInteger c(a);
  BigInteger d(s4);
  cout << a << endl << b << endl << c << endl << d << endl;
  BigInteger sum(a + b);
  BigInteger diff(c - d);
  cout << sum << endl;
  cout << diff << endl;
  return 0;
}
