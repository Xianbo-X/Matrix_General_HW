#ifndef ARRAY_H_
#define ARRAY_H_
#include <iostream>
using namespace std;
class array {
  typedef int* pointer;
  typedef unsigned int size_t;
  typedef int data_type;

  pointer _data;
  size_t _size;

 public:
  // constructor
  array(size_t size);
  // destructor
  ~array();
  // Capacity
  // Return maximum size
  size_t max_size(void);

  // Element access
  // Access element
  // int& operator[](const int &i) {return data[i];}
  // Access element
  data_type& at(const data_type& i);
  // Access first element
  data_type& front();
  // Access last element
  data_type& back();
  // Get pointer to data
  pointer data();

  // Modifiers
  // Fill array with the same value
  void fill(const data_type& value);
  // Resize the array (newSize > oldSize)
  void resize(int newSize);
  // Sort the array in the section [from, to)
  void sort(int from, int to);
};
array::array(size_t size) {
  _data = new int[size];
  _size = size;
}

array::~array() {
  if (_data != NULL) delete[] _data;
  _data = NULL;
}

array::size_t array::max_size(void) { return _size; }

array::data_type& array::at(const data_type& i) { return _data[i]; }

array::data_type& array::front() { return _data[0]; }

array::data_type& array::back() { return _data[_size - 1]; }
array::pointer array::data() { return _data; }
void array::fill(const data_type& value) {
  for (int i = 0; i < _size; i++) {
    _data[i] = value;
  }
}

void array::resize(int newSize) {
  data_type* old = _data;
  _data = new int[newSize];
  for (int i = 0; i < _size; i++) {
    _data[i] = old[i];
  }
  delete[] old;
  old = NULL;
}

void array::sort(int from, int to) {
  int i = from, j = to - 1;
  int tmp;
  int pivot = _data[(i + j) >> 1];

  while (i <= j) {
    while (_data[i] < pivot) i++;
    while (_data[j] > pivot) j--;
    if (i <= j) {
      tmp = _data[i];
      _data[i] = _data[j];
      _data[j] = tmp;
      i++;
      j--;
    }
  }
  if (i < to - 1) sort(i, to);
  if (from < j) sort(from, j + 1);
}

#endif  // ARRAY_H_
