/* Author : Xianbo XU
 * Date:May-25
 *
 * Process:
 * Assume U[i] is rabbits who are born in the ith month,
 * m as the months after witch a pair of rabbits can be adult rabbits;
 * F[i] is total number of rabbits include both mature and immature;
 * Then  U[i]=Σ(0,i-m)U[k], where U[0]=initialNumbers,U[-1]=0;
 * Then U[i+1]=Σ(0,i+1-m)U[k]=U[i+1-m]+U[i]
 * Thus F[i]=Σ(0,i)U[k]=U[i+m];
 * Results: U[i+m] is the number of total rabbits in the month i with immature
 * beginning; When it comes to a mature one, it must be shift to the rabbit
 * matured, that is m-1; So the final answer is U[i+m+m-1];
 */

#include <cstring>
#include <iostream>
#define HIGH_ACCURACY_MODE_
const int MAXSIZE = 40;
class Number {
 public:
  Number(int l = 1) : len{l} { init(); }
  Number(const std::string str) : len{1} {
    init();
    this->set(str);
  }
  Number(const Number& another) {
    this->len = another.len;
    init();
    for (int i = 0; i < another.len; i++) this->num[i] = another.num[i];
  }
  ~Number() {}
  void set(std::string str) {
    this->len = str.size();
    for (int i = len; i > 0; i--) {
      (*this)[i - 1] = str[len - i] - '0';
    }
  }

  Number operator+(Number& another) {
    int maxLen = max(this->len, another.len);
    Number ans{maxLen};
    for (int i = 0; i < maxLen; i++) {
      ans[i] += (*this)[i] + another[i];
      ans[i + 1] = ans[i + 1] + ans[i] / 10;
      ans[i] = ans[i] % 10;
    }
    while (ans[ans.len - 1] > 10) {
      ans[ans.len] += ans[ans.len - 1] / 10;
      ans[ans.len - 1] = ans[ans.len - 1] % 10;
      ans.len++;
    }
    while (ans[ans.len] > 0) {
      ans.len++;
    }
    return ans;
  }

  Number& operator=(Number another) {
    this->len = another.len;
    for (int i = 0; i < this->len; i++) (*this)[i] = another[i];
    return *this;
  }

  friend std::ostream& operator<<(std::ostream& out, Number current) {
    for (int i = current.len; i > 0; i--) {
      out << current[i - 1];
    }
    return out;
  }

 private:
  int num[MAXSIZE];
  int len;
  int max(int a, int b) { return (a > b ? a : b); }
  int min(int a, int b) { return (a < b ? a : b); }
  int& operator[](int pos) { return this->num[pos]; }
  void init() {
    for (int i = 0; i < MAXSIZE; i++) num[i] = 0;
  }
};

Number production(int month, int period) {
  // if (month < period) return Number{"1"};
  // if (month == period) return Number{"2"};
#ifdef ARRAY_MODE_
  long long int u[1000];
  for (int i = 0; i < 1000; i++) u[i] = 0;
  u[0] = 1;
  u[1] = 0;
#else
  Number u[1000];
  u[0].set("1");
  u[period].set("1");
#endif
  for (int i = period + 1; i < month + period + 1 + period - 1; i++) {
    u[i] = u[i - period] + u[i - 1];
  }
  return u[month + period + period - 1];
}

int main() {
  int n, m;
  while (std::cin >> n >> m, n != 0 && m != 0) {
    std::cout << production(m, n) << std::endl;
  }
  return 0;
}