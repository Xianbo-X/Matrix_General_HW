#include "Sequence.h"

const int maxSize = 2000;

int findPos(int value, int* a, int size) {
  for (int i = 0; i < size; i++) {
    if (a[i] == value) return i;
  }
  return -1;
}

Sequence::Sequence() : msize{0}, mempty{true} {
  a = new int[maxSize];
  for (int i = 0; i < maxSize; i++) {
    a[i] = 0;
  }
}

Sequence::~Sequence() {
  if (a != NULL) delete[] a;
  a = NULL;
}

int Sequence::size() { return msize; }
bool Sequence::empty() { return (!a); }

bool Sequence::find(int value) {
  if (findPos(value, a, size()) == -1) return false;
  return true;
}

int& Sequence::at(int pos) {
  return a[pos];
}  // TODO::what's the difference between a+pos and a[pos]

int Sequence::front() { return a[0]; }

int Sequence::back() { a[msize - 1]; }

void Sequence::insert(int value) { a[msize++] = value; }
void Sequence::insert(int pos, int value) {
  for (int i = msize; i > pos; i--) {
    a[i] = a[i - 1];
  }
  a[pos] = value;
  msize++;
}

void Sequence::clear() {
  msize = 0;
  mempty = true;
  delete[] a;
  a = NULL;
}

void Sequence::reverse() {
  int i = 0, j = size() - 1;
  while (i < j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
    i++;
    j--;
  }
}

void Sequence::reverse(int fir, int las) {
  las--;
  while (fir < las) {
    int temp = a[fir];
    a[fir] = a[las];
    a[las] = temp;
    fir++;
    las--;
  }
}

void Sequence::replace(int value1, int value2) {
  int pos = -1;
  while (pos = findPos(value1, a, size()), pos != -1) a[pos] = value2;
}

void Sequence::swap(Sequence& seq2) {
  int size = msize;
  if (seq2.msize > size) {
    size = seq2.msize;
  }
  for (int i = 0; i < msize; i++) {
    int temp = a[i];
    a[i] = seq2.a[i];
    seq2.a[i] = temp;
  }
  int temp = msize;
  msize = seq2.msize;
  seq2.msize = temp;
}