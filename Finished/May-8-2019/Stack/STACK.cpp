#include "STACK.h"
#include <iostream>

NODE* newPtr(ELEMENT obj, NODE* link = NULL) {
  NODE* current = new NODE;
  current->element = obj;
  current->link = link;
  return current;
}

STACK::STACK() : top{NULL} {}
STACK::~STACK() {
  NODE* cur = top;
  while (!is_empty()) {
    cur = top;
    top = top->link;
    delete cur;
  }
  top = NULL;
}
void STACK::push(ELEMENT obj) {
  if (top == NULL) {
    top = newPtr(obj, NULL);
    return;
  }
  NODE* cur = newPtr(obj, top);
  top = cur;
}

void STACK::pop() {
  if (is_empty()) return;
  NODE* cur = top;
  top = top->link;
  delete cur;
}

ELEMENT STACK::get_top() { return top->element; }

int STACK::is_empty() { return (top == NULL); }
void STACK::display() {
  NODE* cur = top;
  while (cur != NULL) {
    std::cout << cur->element << " ";
    cur = cur->link;
  }
  std::cout << std::endl;
}