#include "Stack.hpp"

void Stack::copyOnWrite() {
  node* oldPtr = p.data;  // Track the old one;
  p.count--;

  p.data = new node(oldPtr->num);  // Create the top pointer;
  oldPtr = oldPtr->next;
  node* last = p.data;
  p.count = new int(1);
  
  while (oldPtr != NULL) {
    node* newPtr = new node(oldPtr->num);
    last->next = newPtr;
  }
  
}

Stack::Stack() {
  p.count = new int(1);
  p.data = NULL;
}

Stack::Stack(const Stack& origin) {
  p.data = origin.p.data;
  p.count = origin.p.count;
}

Stack::~Stack() {
  if (*(p.count) > 1) {
    *(p.count)--;
  } else {
    clear();
    delete p.count;
    p.count = NULL;
    p.data = NULL;
  }
}

Stack Stack::operator=(const Stack& origin) {
  p.count = origin.p.count;
  p.data = origin.p.data;
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

bool Stack::empty() const { return (p.data); }

void Stack::clear() {
  copyOnWrite();
  node* ptr = p.data;
  while (ptr) {
    p.data = ptr->next;
    delete ptr;
    ptr = p.data;
  }
}