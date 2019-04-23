#include "Biginteger.h"

BigInteger::BigInteger() : data_{NULL}, size_{0} {}
BigInteger::BigInteger(const string& number) {
  size_ = number.length();
  if (data_ != NULL) delete[] data_;
  data_ = new int[size_];
  init(this->data_, this->size_);
  for (int i = 0; i < size_; i++) {
    data_[i] = number[i] + 48;
  }
}
BigInteger::BigInteger(const BigInteger& other) {
  this->size_ = other.size_;
  delete[] this->data_;
  this->data_ = new int[this->size_];

  for (int i = 0; i < this->size_; i++) {
    this->data_[i] = other.size_;
  }
}

BigInteger::~BigInteger() {
  if (data_ != NULL) {
    delete[] data_;
    data_ = NULL;
  }
  size_ = 0;
}

inline int max(int a, int b) { return (a > b ? a : b); }
inline int min(int a, int b) { return (a < b ? a : b); }
inline void init(int*& data, int size) { memset(data, 0, size * sizeof(int)); }

BigInteger operator+(const BigInteger& left, const BigInteger& right) {
  BigInteger temp;
  temp.size_ = max(left.size_, right.size_);
  if (temp.data_ != NULL) delete[] temp.data_;
  temp.data_ = new int[temp.size_];
  init(temp.data_, temp.size_);
  for (int i = 0; i < temp.size_; i++) {
    temp.data_[i] = temp.data_[i] + left.data_[i] + right.data_[i];
    temp.data_[i + 1] += temp.data_[i] / 10;
    temp.data_[i] %= 10;
  }
  while (temp.data_[temp.size_] == 0) temp.size_--;
  return temp;
}
BigInteger operator-(const BigInteger& left, const BigInteger& right) {
  BigInteger temp;
  temp.size_ = min(left.size_, right.size_);
  if (temp.data_ != NULL) delete[] temp.data_;
  temp.data_ = new int[temp.size_];
  init(temp.data_, temp.size_);
  for (int i = 0; i < temp.size_; i++) {
    temp.data_[i] =
        left.data_[i] - right.data_[i] + 10;     // Borrow one in advance.
    temp.data_[i + 1] = temp.data_[i] / 10 - 1;  // Substract 1 since
    temp.data_[i] %= 10;
  }
  while (temp.data_[temp.size_] == 0) temp.size_--;
  return temp;
}
ostream& operator<<(ostream& out, const BigInteger& Bint);