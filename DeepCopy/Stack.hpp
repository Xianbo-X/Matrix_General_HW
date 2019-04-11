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

  node* data;

 public:
  Stack();              // 构造一个空栈
  Stack(const Stack&);  // 深拷贝
  ~Stack();             // 注意内存回收

  Stack operator=(const Stack&);  // 深拷贝
  void push(int);                 // 入栈
  void pop();                     // 出栈
  int top() const;                // 查看栈顶元素
  bool empty() const;             // 判断栈是否为空
  void clear();                   // 清空栈
};

///
#include <cstddef>
#include "Stack.hpp"
Stack::Stack() { data = NULL; }

Stack::Stack(const Stack& origin) {
  this->data = NULL;
  if (origin.data != NULL) {
    node* ptr = origin.data;
    this->data = new node(ptr->num);
    node* lastPtr = this->data;

    ptr = ptr->next;
    while (ptr != NULL) {
      node* newPtr = new node(ptr->num);
      lastPtr->next = newPtr;
      lastPtr = newPtr;
      ptr = ptr->next;
    }
  }
}

Stack::~Stack() { clear(); }

Stack Stack::operator=(const Stack& origin) {
  if (this == &origin) return *this;
  if (data != NULL) clear();
  if (origin.data == NULL) return *this;
  node* ptr = origin.data;
  this->data = new node(ptr->num);
  node* lastPtr = this->data;

  ptr = ptr->next;
  while (ptr != NULL) {
    node* newPtr = new node(ptr->num);
    lastPtr->next = newPtr;
    lastPtr = newPtr;
    ptr = ptr->next;
  }
  return *this;
}

void Stack::push(int x) {
  if (!data) {
    data = new node(x);
    return;
  }
  node* ptr = new node(x);
  ptr->next = data;
  data = ptr;
}

void Stack::pop() {
  if (data == NULL) return;
  node* ptr = data;
  data = data->next;
  delete ptr;
}

int Stack::top() const { return data->num; }
bool Stack::empty() const { return (!data); }

void Stack::clear() {
  if (data == NULL) return;
  node* p = data;
  while (data != NULL) {
    data = data->next;
    delete p;
    p = data;
  }
}

//
#endif