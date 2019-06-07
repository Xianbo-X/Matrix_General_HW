#ifndef STACK_TEMPLATE_H_
#define STACK_TEMPLATE_H_
#include <cstddef>
template <typename ElementType, std::size_t N>
class Stack_base
{
public:
  Stack_base();
  void push(ElementType obj);
  void pop();
  ElementType getTop() const;
  bool isEmpty() const;
  int getCount() const { return count; }

protected:
  ElementType elements[N]; // 堆栈中存放的元素
  std::size_t count;       // 堆栈中现有元素的数目
};

template <typename T, std::size_t N>
Stack_base<T, N>::Stack_base() : count{0} {}
template <typename T, std::size_t N>
void Stack_base<T, N>::push(T obj)
{
  if (count < N)
    elements[count++] = obj;
}
template <typename T, std::size_t N>
void Stack_base<T, N>::pop()
{
  if (isEmpty())
    return;
  count--;
}
template <typename T, std::size_t N>
T Stack_base<T, N>::getTop() const
{
  if (isEmpty())
    return 0;
  return elements[count - 1];
}
template <typename T, std::size_t N>
bool Stack_base<T, N>::isEmpty() const
{
  return !count;
}
template <class T, int num>
class Stack : public Stack_base<T, num>
{
public:
  Stack() {}
  ~Stack() {}
  bool empty() { return Stack_base<T, num>::isEmpty(); }
  T pop()
  {
    T temp = peek();
    Stack_base<T, num>::pop();
    return temp;
  }
  T peek() { return Stack_base<T, num>::getTop(); }
  int size() { return Stack_base<T, num>::getCount(); }
  void printStack()
  {
    for (int i = Stack_base<T, num>::count - 1; i >= 0; i--)
    {
      std::cout << Stack_base<T, num>::elements[i] << std::endl;
    }
  }
};
#endif