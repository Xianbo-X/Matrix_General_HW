#include "set.hpp"

int find(const int e, const int *data, const int size) {
  for (int i = 0; i < size; i++) {
    if (data[i] == e) return i;
  }
  return -1;
}
Set::Set() : size{0} {}  // TODO: How to  array member in initialization list?

Set::Set(int *m, int s) : size{0} {
  for (int i = 0; i < s; i++) {
    append(m[i]);
  }
}

bool Set::append(int e) {
  if (isInSet(e)) return false;
  members[size++] = e;
  return true;
}

bool Set::remove(int e) {
  if (!isInSet(e)) return false;
  int pos = find(e, members, size);
  size--;
  for (int i = pos; i < size; i++) {
    members[i] = members[i + 1];
  }
  return true;
}

bool Set::isEmptySet() { return (!size); }
int *Set::getMembers() { return members; }
int Set::getSize() { return size; }
bool Set::isInSet(int e) { return (find(e, getMembers(), size) + 1); }