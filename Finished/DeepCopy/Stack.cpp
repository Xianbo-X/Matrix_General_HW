#include "Stack.hpp"
#include <cstddef>
Stack::Stack() { data = NULL; }

Stack::Stack(const Stack& origin) {
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