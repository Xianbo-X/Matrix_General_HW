#ifndef SOURCE_H_
#define SOURCE_H_

class Number {
 private:
  int sum;

 public:
  explicit Number(int x = 0);
  ~Number();

  Number& add(int x);
  Number& sub(int x);
  void print();
};

Number::Number(int x) : sum{x} {}

Number::~Number() { sum = 0; }
Number& Number::add(int x) {
  this->sum += x;
  return *this;
}

Number& Number::sub(int x) {
  this->sum -= x;
  return *this;
}

void Number::print() {
  std::cout << sum << std::endl;
  return;
}

#endif