#include "Set.hpp"

// find in domain [l,r)
int find(int value, const int *a, int l, int r) {
  for (int i = l; i < r; i++)
    if (a[i] == value) return i;
  return -1;
}

Set::Set() : size{0} {
  for (int i = 0; i < MAX_MEMBERS; i++) members[i] = 0;
}
Set::Set(int *m, int s) : size{s} {
  for (int i = 0; i < s; i++) members[i] = m[i];
}

Set::Set(Set const &s) {
  size = s.size;
  for (int i = 0; i < size; i++) members[i] = s.members[i];
}

bool Set::append(int e) {
  if (find(e, members, 0, size) != -1) return false;
  members[size++] = e;
  return true;
}

bool Set::remove(int e) {
  int pos = find(e, members, 0, size);
  if (pos == -1) return false;
  size--;
  for (int i = pos; i < size; i++) members[i] = members[i + 1];
  return true;
}

bool Set::isEmptySet() { return !size; }
bool Set::isInSet(int e) { return (find(e, members, 0, size) != -1); }

Set Set::operator&(const Set &s) {
  Set res;
  if (s.size > size) {
    for (int i = 0; i < size; i++)
      if (find(members[i], s.members, 0, s.size) != -1) res.append(members[i]);
  } else {
    for (int i = 0; i < s.size; i++)
      if (find(s.members[i], members, 0, size) != -1) res.append(s.members[i]);
  }
  return res;
}

Set Set::operator|(const Set &s) {
  Set temp;
  for (int i = 0; i < size; i++)
    if (find(members[i], temp.members, 0, size) == -1) temp.append(members[i]);
  for (int i = 0; i < s.size; i++)
    if (find(s.members[i], temp.members, 0, size) == -1)
      temp.append(s.members[i]);
  return temp;
}
Set Set::operator-(const Set &s) {
  Set temp(*this);
  for (int i = 0; i < s.size; i++) {
    temp.remove(s.members[i]);
  }
  return temp;
}

Set Set::operator+(const Set &s) {
  Set temp, s_temp{s};
  temp = ((*this - s) | (s_temp - *this));  // TODO:?
  return temp;
}

int *Set::getMembers() { return members; }
int Set::getSize() { return size; }