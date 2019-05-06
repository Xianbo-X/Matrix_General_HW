#include "List.hpp"
#include <iostream>
#include <sstream>
#include <string>
std::string num2str(int x) {
  std::stringstream ss;
  ss.clear();
  ss << x;
  std::string res = "";
  ss >> res;
  return res;
}

list::list() : _size{2} {
  head = new listNode{-1};
  tail = new listNode{-1};
  head->next = tail;
  tail->prev = head;
}

list::list(const data_type data[], int length) : _size{2} {
  head = new listNode{-1};
  tail = new listNode{-1};
  head->next = tail;
  tail->prev = head;
  for (int i = 0; i < length; i++) push_back(data[i]);
}

list::list(const list& origin) : _size{2} {
  head = new listNode{-1};
  tail = new listNode{-1};
  head->next = tail;
  tail->prev = head;
  *this = origin;
}
list& list::operator=(const list& origin) {
  if (this == &origin) return *this;
  this->clear();
  listPointer p = origin.head->next;
  while (p != origin.tail) {
    this->push_back(p->data);
    p = p->next;
  }
  return *this;
}
list::~list() {
  clear();
  delete head;
  delete tail;
  head = NULL;
  tail = NULL;
}

// Capacity
bool list::empty(void) const { return (head->next == tail); }
list::size_type list::size(void) const { return _size - 2; }

// Element access

list::data_type& list::front(void) const {
  if (head->next == tail) {
    return head->prev->data;
  }
  return head->next->data;
}
list::data_type& list::back(void) const {
  if (tail->prev == head) {
    return tail->next->data;
  }
  return tail->prev->data;
}

// output
std::string list::toString(void) const {
  listPointer p = head;
  if (p->next == tail) return "NULL";
  std::string res = "";
  while (p != NULL) {
    if (p == head) {
      res = res + "NULL<-";
    } else if (p->next == tail) {
      res = res + num2str(p->data);
    } else if (p == tail) {
      res = res + "->NULL";
    } else {
      res = res + num2str(p->data) + "<->";
    }

    p = p->next;
  }
  return res;
}

// Modifiers
void list::assign(const list& other) {
  this->clear();
  *this = other;
}

void list::assign(const data_type datas[], int length) {
  *this = list{datas, length};
}

void list::push_front(const data_type& num) { insert(0, num); }
void list::push_back(const data_type& num) { insert(size(), num); }
void list::pop_front(void) { erase(0); }
void list::pop_back(void) { erase(size() - 1); }
void insert(const list::data_type& data, list::listPointer prev,
            list::listPointer next) {
  list::listPointer p = new list::listNode{data, next, prev};
  next->prev = p;
  prev->next = p;
}
void list::insert(int position, const data_type& data) {
  listPointer pos = this->at(position + 1);
  if (pos == NULL) return;
  ::insert(data, pos->prev, pos);
  _size++;
}
void erase(list::listPointer prev, list::listPointer cur,
           list::listPointer next) {
  prev->next = next;
  next->prev = prev;
  delete cur;
}

void list::erase(int position) {
  //  position = position - 1;
  listPointer pos = this->at(
      position);  // next is the exact position since we have a head pointer;
  if (pos == NULL || pos->next == NULL || pos->next == tail) return;
  ::erase(pos, pos->next, pos->next->next);
  _size--;
}

void list::clear(void) {
  while (!empty()) {
    pop_back();
  }
  head->next = tail;
  tail->prev = head;
  _size = 2;
}

// operators
list::data_type& list::operator[](int index) {
  listPointer p = this->at(index + 1);
  if (p != NULL && p != tail) return p->data;
}

list& list::operator+=(const list& another) {
  listPointer p = another.head->next;
  while (p != another.tail) {
    this->push_back(p->data);
    p = p->next;
  }
  return *this;
}

void list::split(int position, list* des1, list* des2) {
  if (des1 == NULL || des2 == NULL) return;
  des1->clear();
  des2->clear();
  for (int i = 0; i < position; i++) {
    des1->push_back((*this)[i]);
  }
  for (int i = position; i < this->size(); i++) {
    des2->push_back((*this)[i]);
  }
  return;
}
list& list::merge(const list& src1, const list& src2) {
  list temp1{src1};
  list temp2{src2};
  this->clear();
  (*this) += temp1;
  (*this) += temp2;
  return *this;
}
list& list::remove_if(bool (*condition)(listPointer listPtr)) {
  listPointer current = head->next;
  while (current != tail) {
    listPointer temp = current;
    current = current->next;
    if (condition(temp)) {
      ::erase(temp->prev, temp, temp->next);
      _size--;
    }
  }
  return *this;
}

list& list::unique(void) {
  listPointer slow, fast;
  slow = head->next;
  while (slow != tail) {
    fast = slow->next;
    while (fast != tail) {
      listPointer temp = fast;
      fast = fast->next;
      if (temp->data == slow->data) {
        ::erase(temp->prev, temp, temp->next);
        _size--;
      }
    }
    slow = slow->next;
  }
  return *this;
}

void swap(list::listPointer& a, list::listPointer& b) {
  list::listPointer temp = a;
  a = b;
  b = temp;
}

list& list::reverse(void) {
  listPointer p = head;
  while (p != NULL) {
    listPointer temp = p;
    p = p->next;
    swap(temp->prev, temp->next);
  }
  swap(head, tail);
}

std::ostream& operator<<(std::ostream& out, const list& li) {
  out << li.toString();
  return out;
}
