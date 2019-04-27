#include "Sequence.h"

const int MAXSIZE = 2000;

int find(int *a, int msize, int value) {
  for (int i = 0; i < msize; i++)
    if (a[i] == value) return i;
  return -1;
}

Sequence::Sequence() : a{NULL}, msize{0}, mempty{true} {}
Sequence::~Sequence() { clear(); }
int Sequence::size() { return msize; }
bool Sequence::empty() { return (!msize); }

bool Sequence::find(int value) {
  if (::find(this->a, msize, value) == -1) return false;
  return true;
}

int &Sequence::at(int pos) { return a[pos]; }
int Sequence::front() { return a[0]; }
int Sequence::back() { return a[msize-1]; }
void Sequence::insert(int value) { insert(msize-1, value); }
void Sequence::insert(int pos, int value) {
  if (a == NULL) {
    a = new int[MAXSIZE];
    for (int i = 0; i < MAXSIZE; i++) a[i] = 0;
  }

  for (int i = msize; i > pos; i--) {
    a[i] = a[i - 1];
  }
  a[pos] = value;
  msize++;
}

void Sequence::clear() {
  if (a != NULL) delete[] a;
  a = NULL;
  msize = 0;
  mempty = true;
}

void Sequence::reverse() { reverse(0, msize - 1); }
void Sequence::reverse(int fir, int las) {
  while (fir < las) {
    int temp = a[fir];
    a[fir] = a[las];
    a[las] = temp;
    fir++;
    las--;
  }
  return;
}

void Sequence::replace(int value1, int value2) {
  int pos = -1;
  while (pos = ::find(this->a, msize, value1), pos != -1) {
    a[pos] = value2;
  }
}

void Sequence::swap(Sequence &seq2) {
  for (int i = 0; i < MAXSIZE; i++) {
    int temp = at(i);
    at(i) = seq2.at(i);
    seq2.at(i) = temp;
  }
  return;
}