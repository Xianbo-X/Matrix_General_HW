#ifndef STACK_HPP
#define STACK_HPP

#include <stddef.h>

class Stack {
  struct node {
    int num;
    node* next;
    node() {
      num = 0;
      next = NULL;
    }
    node(int n, node* p = NULL) {
      num = n;
      next = p;
    }
  };

  struct {
    node* data;
    int* count;
  } p;

  void copyOnWrite();

 public:
  Stack();              // 构造一个空栈
  Stack(const Stack&);  // 写时复制规则
  ~Stack();             // 注意内存回收

  Stack operator=(const Stack&);  // 写时复制规则
  void push(int);                 // 入栈
  void pop();                     // 出栈
  int top() const;                // 查看栈顶元素
  bool empty() const;             // 判断栈是否为空
  void clear();                   // 清空栈
};

#include "Stack.hpp"

void Stack::copyOnWrite() {
  node* oldPtr = p.data;  // Track the old one;
  if (oldPtr == NULL) {
    return;
  }
  if ((p.count != NULL) && ((*(p.count)) == 1)) return;
  (*p.count)--;

  p.data = new node(oldPtr->num);  // Create the top pointer;
  oldPtr = oldPtr->next;
  node* last = p.data;
  p.count = new int(1);

  while (oldPtr != NULL) {
    node* newPtr = new node(oldPtr->num);
    last->next = newPtr;
    last=newPtr;
    oldPtr = oldPtr->next;
  }
}

Stack::Stack() {
  p.count = new int(1);
  p.data = NULL;
}

Stack::Stack(const Stack& origin) {
  p.data = origin.p.data;
  p.count = origin.p.count;
  (*(p.count))++;
}

Stack::~Stack() {
  if ((*(p.count)) > 1) {
    (*(p.count))--;
  } else {
    clear();
    delete p.count;
    p.count = NULL;
    p.data = NULL;
  }
}

Stack Stack::operator=(const Stack& origin) {
  if (this == &origin) return *this;
  p.count = origin.p.count;
  p.data = origin.p.data;
  (*(p.count))++;
  return *this;
}

void Stack::push(int num) {
  copyOnWrite();
  node* ptr = new node(num, p.data);
  p.data = ptr;
}

void Stack::pop() {
  copyOnWrite();
  node* ptr = p.data;
  p.data = (p.data)->next;
  delete ptr;
}

int Stack::top() const { return ((p.data)->num); }

bool Stack::empty() const { return (!p.data); }

void Stack::clear() {
  copyOnWrite();
  node* ptr = p.data;
  while (ptr) {
    p.data = ptr->next;
    delete ptr;
    ptr = p.data;
  }
}
#endif