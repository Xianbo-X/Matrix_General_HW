#ifndef STACK_TEMPLATE_H_
#define STACK_TEMPLATE_H_
#include <cstddef>
template <typename ElementType, std::size_t N>
class Stack {
 public:
  Stack();
  void push(ElementType obj);
  void pop();
  ElementType getTop() const;
  bool isEmpty() const;

 private:
  ElementType elements[N];  // 堆栈中存放的元素
  std::size_t count;        // 堆栈中现有元素的数目
};

template <typename T, std::size_t N>
Stack<T, N>::Stack() : count{0} {}
template <typename T, std::size_t N>
void Stack<T, N>::push(T obj) {
  if (count < N) elements[count++] = obj;
}
template <typename T, std::size_t N>
void Stack<T, N>::pop() {
  if (isEmpty()) return;
  count--;
}
template <typename T, std::size_t N>
T Stack<T, N>::getTop() const {
  if (isEmpty()) return 0;
  return elements[count - 1];
}
template <typename T, std::size_t N>
bool Stack<T, N>::isEmpty() const {
  return !count;
}

#endif