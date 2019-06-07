#ifndef CLASS_H_
#define CLASS_H_
#include <cstddef>

template <typename ElementType>  // genericStack.h
class Stack {
 public:
  Stack();
  ~Stack();
  void push(ElementType obj);
  void pop();
  ElementType getTop() const;
  bool isEmpty() const;

 private:
  struct Node  // 栈结点类型
  {
    ElementType element;  // 结点中存放的元素
    Node *next;           // 指向下一结点的指针
  };
  Node *top;  // 栈顶
};
template <typename T>
Stack<T>::Stack() : top{NULL} {}
template <typename T>
Stack<T>::~Stack() {
  while (!isEmpty()) {
    pop();
  }
  top = NULL;
}
template <typename T>
void Stack<T>::push(T obj) {
  /*  if (isEmpty()) {
      top = new Node{obj, NULL};
      return;
    }*/
  Node *ptr = new Node{obj, top};
  top = ptr;
}
template <typename T>
void Stack<T>::pop() {
  if (isEmpty()) return;
  Node *ptr = top;
  top = top->next;
  delete ptr;
}
template <typename T>
T Stack<T>::getTop() const {
  if (isEmpty()) return 0;
  return top->element;
}
template <typename T>
bool Stack<T>::isEmpty() const {
  return (top == NULL);
}
#endif