#include <cmath>
#include <iostream>
#include <string>
using namespace std;

class MyInteger {
 public:
  MyInteger() : value{0} {}
  MyInteger(int);
  // Accessor Function
  int getValue() const;
  bool isEven() const;
  bool isOdd() const;
  bool isPrime() const;
  bool equals(int);
  bool equals(const MyInteger &);

  static bool isEven(int);
  static bool isOdd(int);
  static bool isPrime(int);
  static bool isEven(const MyInteger &);
  static bool isOdd(const MyInteger &);
  static bool isPrime(const MyInteger &);
  static int parseInt(const std::string &);

 private:
  int value;
};

MyInteger::MyInteger(int x) { value = x; }
int MyInteger::getValue() const { return value; }

bool MyInteger::isEven() const { return isEven(value); }
bool MyInteger::isOdd() const { return isOdd(value); }
bool MyInteger::isPrime() const { return isPrime(value); }
bool MyInteger::equals(int x) { return (value == x); }
bool MyInteger::equals(const MyInteger &x) { return (value == x.value); }

bool MyInteger::isEven(int x) { return (!(x % 2)); }
bool MyInteger::isOdd(int x) { return (x % 2); }
bool MyInteger::isPrime(int x) {
  if (x == 1) return false;
  if (x == 2) return true;
  bool flag = true;
  for (int i = 2; i <= sqrt(x); i++) {
    if (x % i == 0) {
      flag = false;
      break;
    }
  }
  return flag;
}

bool MyInteger::isEven(const MyInteger &x) { return isEven(x.value); }
bool MyInteger::isOdd(const MyInteger &x) { return isOdd(x.value); }
bool MyInteger::isPrime(const MyInteger &x) { return isPrime(x.value); }

int MyInteger::parseInt(const std::string &str) {
  int res = 0;
  int sign = 1;
  int st = 0;
  if (str[0] == '-') {
    sign = -1;
    st = 1;
  }
  for (int i = st; i < str.size(); i++) {
    res *= 10;
    res += str[i] - 48;
  }
  return sign*res;
}

int main() {
  const string words[3][2] = {"not even", "even",      "not odd",
                              "odd",      "not prime", "prime"};
  int a, b, c, d, e;
  string num;
  cin >> a >> b >> c;
  cin >> d >> e;
  cin >> num;

  MyInteger myInt(a);
  cout << "Integer " << myInt.getValue() << " is: ";
  cout << words[0][myInt.isEven()] << ", ";
  cout << words[1][myInt.isOdd()] << ", ";
  cout << words[2][myInt.isPrime()] << ".\n";

  cout << "Integer " << b << " is: ";
  cout << words[0][MyInteger::isEven(b)] << ", ";
  cout << words[1][MyInteger::isOdd(b)] << ", ";
  cout << words[2][MyInteger::isPrime(b)] << ".\n";

  MyInteger myInt2(c);
  cout << "Integer " << myInt2.getValue() << " is: ";
  cout << words[0][MyInteger::isEven(myInt2)] << ", ";
  cout << words[1][MyInteger::isOdd(myInt2)] << ", ";
  cout << words[2][MyInteger::isPrime(myInt2)] << ".\n";

  MyInteger myInt3(d);
  MyInteger myInt4(e);
  if (myInt3.equals(e) && myInt3.equals(myInt4))
    cout << d << " and " << e << " are equal.\n";
  else
    cout << d << " and " << e << " are not equal.\n";

  cout << "String '" << num << "' convert to " << MyInteger::parseInt(num)
       << endl;

  return 0;
}