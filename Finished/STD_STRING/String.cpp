#include "String.h"
#include <cstring>
String::String() : _buff{NULL}, _length{0}, _size{0} {}

String::String(const char *src) {
  this->_length = 0;
  this->_size = 0;
  while (src[this->_length] != '\0') this->_length++;
  this->_size = this->_length + 1;
  this->_buff = new char[this->_size];
  for (int i = 0; i < this->_length; i++) {
    this->_buff[i] = src[i];
  }
  this->_buff[this->_length] = '\0';
}

String::String(const String &src) {
  this->_length = src._length;
  //this->_size=src._size;
  this->_size = this->_length+1;
  this->_buff = new char[this->_size];
  for (int i = 0; i < src._length; i++) {
    this->_buff[i] = src._buff[i];
  }
  this->_buff[this->_length] = '\0';
}

String ::~String() { clear(); }

void String ::assign(const char *src) {
  this->clear();

  while (src[this->_length] != '\0') this->_length++;
  this->_size = this->_length + 1;
  this->_buff = new char[this->_size];

  for (int i = 0; i < this->_length; i++) {
    this->_buff[i] = src[i];
  }
  this->_buff[this->_length] = '\0';
}

void String::append(const char &other) {
  String temp{*this};
  this->clear();
  this->_length = temp._length + 1;
  this->_size = this->_length + 1;
  this->_buff = new char[this->_size];
  for (int i = 0; i < temp._length; i++) {
    this->_buff[i] = temp._buff[i];
  }
  this->_buff[temp._length] = other;
  this->_buff[this->_length] = '\0';
}

void String::clear() {
  if (_buff != NULL) {
    delete[] _buff;
    _buff = NULL;
  }
  _size = 0;
  _length = 0;
}

int String::compare(const String &other) const {
  int sign=strcmp(this->c_str(), other.c_str());
  if (sign<0) return -1;
  if (sign>0) return 1;
  return 0;
}

const char *String::c_str() const {
  //  char *temp=new char[this->_size];
  // strcpy(temp,this->_buff);
  return this->_buff;
}

bool String::empty() const { return (!this->_size); }
int String::find(const String &other, int pos) const {
  for (int i = pos; i < this->_length - other._length + 1;
       i++)  //:TODO  Proble of Length should be figured out.
  {
    bool same = true;
    for (int j = 0; j < other._length; j++) {
      if (this->_buff[i + j] != other._buff[j]) {
        same = false;
        break;
      }
    }
    if (same) return i;
  }
  return this->_length;
}

int String::length() const { return _length; }
String String::substr(const int &pos, const int &count) const {
  int realcount = count;
  if (!(pos + count - 1 < this->_length - 1)) {
    realcount = this->_length - pos;
  }
  char *temp = new char[realcount + 1];
  for (int i = 0; i < realcount; i++) {
    temp[i] = this->_buff[pos + i];
  }
  temp[realcount] = '\0';
  String Str{temp};
  delete[] temp;
  return Str;
}

// overload operators
char &String::operator[](const int &index) { return this->_buff[index]; }
void String::operator=(const String &other) { this->assign(other.c_str()); }

void String::operator=(const char *src) { this->assign(src); }
String String::operator+(const String &other) const {
  String temp;
  temp._length = this->_length + other._length;
  temp._size = temp._length + 1;
  temp._buff = new char[temp._size];
  for (int i = 0; i < this->_length; i++) {
    temp._buff[i] = this->_buff[i];
  }
  for (int i = 0; i < other._length; i++) {
    temp._buff[i + this->_length] = other._buff[i];
  }
  temp._buff[temp._length] = '\0';
  return temp;
}

bool String::operator<(const String &other) const {
  if (this->compare(other) == -1) return true;
  return false;
}
bool String::operator<=(const String &other) const { return !(*this > other); }
bool String::operator>(const String &other) const {
  if (this->compare(other) == 1) return true;
  return false;
}
bool String::operator>=(const String &other) const { return !(*this < other); }
bool String::operator==(const String &other) const {
  if (this->compare(other) == 0) return true;
  return false;
}
bool String::operator!=(const String &other) const { return !(*this == other); }
// friend methods
std::ostream &operator<<(std::ostream &out, const String &str) {
  for (int i = 0; i < str._length; i++) out << str._buff[i];
  return out;
}
// non-meaning static property
char String::_error_sign = 0;  // initial as any char is okay
