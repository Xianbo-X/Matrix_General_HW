#include "IntegerSet.h"

IntegerSet::IntegerSet(int s[], int l) {
  for (int i = 0; i < l; i++) {
    if (validEntry(s[i])) set[s[i]] = 1;
  }
}

IntegerSet IntegerSet::unionOfSets(const IntegerSet& other) {
  IntegerSet temp;
  for (int i = 0; i < 101; i++) {
    if ((this->set[i]) || (other.set[i])) temp.set[i] = 1;
  }
  return temp;
}

IntegerSet IntegerSet::intersectionOfSets(const IntegerSet& other) {
  IntegerSet temp;
  for (int i = 0; i < 101; i++) {
    if ((this->set[i]) && (other.set[i])) temp.set[i] = 1;
  }
  return temp;
}

void IntegerSet::emptySet() {
  for (int i = 0; i < 101; i++) set[i] = 0;
}

void IntegerSet::insertElement(int element) {
  if (validEntry(element)) {
    set[element] = 1;
  }
}

void IntegerSet::deleteElement(int element) {
  if (validEntry(element)) {
    set[element] = 0;
  }
}

bool IntegerSet::isEqualTo(const IntegerSet& other) const {
  for (int i = 0; i < 101; i++) {
    if (!(this->set[i] && other.set[i])) return false;
  }
  return true;
}

