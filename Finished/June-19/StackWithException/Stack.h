#ifndef STACK_H_
#define STACK_H_
#include <iostream>
#include <stdexcept>
const int MAX_LEN = 5;

template <class T>

class Stack {
 public:
  explicit Stack() : stack_size{0} {}
  bool empty() const { return stack_size == 0; }
  bool full() const { return stack_size == MAX_LEN; }
  int size() const { return stack_size; }
  // T& top() throw(int, double) {}
  const T& top() const {
    if (empty()) throw(1);
    return data[stack_size - 1];
  }
  /*
  void push(const T& x) {
    if (!full()) {
      data[stack_size] = x;
      stack_size++;
      return;
    }
    if (x > top()) {
      pop();
      push(x);
    }
  }*/

  void pop() {
    if (empty()) throw(3.5);
    stack_size--;
  }

 private:
  T data[MAX_LEN];

  int stack_size;
};

#endif