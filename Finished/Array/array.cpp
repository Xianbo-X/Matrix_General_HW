#include "array.h"
#include <iostream>

array::array(size_t size) {
  _data = new int(size);
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
  data_type* old = new int(_size);
  for (int i = 0; i < _size; i++) {
    old[i] = _data[i];
  }
  delete[] _data;
  _data = NULL;
  _data = new int(newSize);
  for (int i = 0; i < _size; i++) {
    _data[i] = old[i];
  }
  delete[] old;
  _size = newSize;
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
