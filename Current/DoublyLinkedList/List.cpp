#include "List.hpp"

list::list() : head{NULL}, tail{NULL}, _size{0} {}

list::list(const data_type data[], int length)
    : head{NULL}, tail{NULL}, _size{0} {
  //:TODO insert all;
  for (int i = 0; i < length; i++) push_back(data[i]);
}

list::list(const list& other) : head{NULL}, tail{NULL}, _size{0} {
  *this = other;
}

list& list::operator=(const list& other) {
  listPointer otherPtr = other.head;
  while (otherPtr != NULL) {
    push_back(otherPtr->data);
  }
  return *this;
}

list::~list() { clear(); }

// Capacity
bool list::empty(void) const { return !(head == NULL); }

list::size_type list::size(void) const { return _size; }

// Element access
list::data_type& list::front(void) const { return head->data; }
list::data_type& list::back(void) const { return tail->data; }

// output
std::string list::toString(void) const {
  listPointer p = head;
  std::string res = "NULL";
  while (p != NULL) {
    if (p == head) {
      res = res + "<-";
      continue;
    } else {
      res = res + "<->";
    }
    res = res + static_cast<char>(p->data + 48);
    if (p == tail) {
      res = res + "->NULL";
      continue;
    }
    p = p->next;
  }
  return res;
}

void list::assign(const list& other) {
  this->clear();
  *this = other;
}

void list::assign(const list::data_type data[], int length) {
  *this = list{data, length};
}

void list::push_front(const list::data_type& data) { insert(0, data); }
void list::push_back(const list::data_type& data) { insert(this->_size, data); }
void list::pop_front(void) { erase(0); }
void list::pop_back(void) { erase(this->_size - 1); }

void aux_insert_forward(list::listPointer& succ, const int& data) {
  list::listPointer q;
  q = new list::listNode(data, succ, succ->prev);
  succ->prev = q;
}
void aux_insert_backward(list::listPointer& prev, const int& data) {
  list::listPointer q;
  q = new list::listNode(data, prev->next, prev);
  prev->next = q;
}

void list::insert(int position, const data_type& data) {
  if (position == 0) {
    if (head == NULL) {
      head = new listNode(data, NULL, NULL);
      tail = head;
      this->_size++;
      return;
    }
    aux_insert_forward(head, data);
    head = head->prev;
    this->_size++;
    return;
  }
  if (position == _size) {
    aux_insert_backward(tail, data);
    tail = tail->next;
    this->_size++;
    return;
  }
  aux_insert_forward(this->at(position - 1)->next, data);
  this->_size++;
}
void removeNode_backward(list::listPointer& current) {
  list::listPointer p = current;
  current = p->next;
  current->prev = p->prev;
  p->prev->next = current;
  delete p;
}

void removeNode_foreward(list::listPointer& current) {
  list::listPointer p = current;
  current = p->prev;
  current->next = p->next;
  p->next->prev = current;
  delete p;
}

void list::erase(int position) {
  if (head == NULL) return;
  if (position == 0) {
    removeNode_backward(head);
    _size--;
    // if (_size == 0) clear();
    if (_size == 0) {
      head = NULL;
      tail = NULL;
    }
    return;
  }
  if (position == _size - 1) {
    removeNode_foreward(tail);
    _size--;
    if (_size == 0) {
      head = NULL;
      tail = NULL;
    }
    // if (_size == 0) clear();
    return;
  }
  removeNode_foreward(this->at(position - 1)->next);
  _size--;
  // if (_size == 0) clear();
  return;
}

void list::clear(void) {
  while (!empty()) pop_front();
  head = NULL;
  tail = NULL;
}

void list::split(int position, list* des1, list* dest2) {
  /* useless, local variable
   *if (des1 == NULL) des1 = new list;
   *if (dest2 == NULL) dest2 == new list;
   */
  for (int i = 0; i < position; i++) {
    des1->push_back(this->at(i)->data);
  }
  for (int i = position; i < this->_size; i++) {
    dest2->push_back(this->at(i)->data);
  }
}

list& list::merge(const list& src1, const list& src2) {
  clear();
  *this = src1;
  listPointer src2Ptr = src2.head;

  while (src2Ptr != NULL) {
    this->push_back(src2Ptr->data);
    src2Ptr = src2Ptr->next;
  }
  return *this;
}
list& list::remove_if(bool (*condition)(listPointer ptr)) {
  int size = this->_size;

  for (int i = size - 1; i >= 0; i--) {
    if (condition(this->at(i))) erase(i);
  }

  return *this;
}

list& list::unique(void) {
  listPointer p = this->head;
  while (p != NULL) {
    listPointer q = p->next;
    while (q != NULL) {
      if (q->data == p->data) {
        removeNode_foreward(q);
        continue;
      }
      q = q->next;
    }
    p = p->next;
  }
  return *this;
}

list& list::reverse(void) {
  listPointer p = head;
  while (p != NULL) {
    listPointer temp = p->prev;
    p->prev = p->next;
    p->next = temp;
    p = p->next;
  }
  listPointer temp = head;
  head = tail;
  tail = temp;
  return *this;
}

list::data_type& list::operator[](int index) { return this->at(index)->data; }
list& list::operator+=(const list& other) {
  list temp{*this};
  this->merge(temp, other);
  return *this;
}

std::ostream& operator<<(std::ostream& out, const list& li) {
  out << li.toString();
  return out;
}