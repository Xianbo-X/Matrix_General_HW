#include <iostream>
#include "testTemplate.h"

class asset {
 public:
  asset();
  asset& operator=(const asset*& origin);

  bool printData() {
    if (!m_data) {
      cout << "NULL, No data" << endl;
      return false;
    }
    cout << m_data->name << "  " << m_data->code << "  " << m_data->data
         << endl;
    return true;
  }
  ~asset();
  struct node<int>* m_data;

 private:
};
asset::asset() { m_data = new struct node<int>; }

asset& asset::operator=(const asset*& origin) {
  this->m_data->data = origin->m_data->data;
  this->m_data->code = origin->m_data->code;
  this->m_data->name = origin->m_data->name;
  return *this;
}
asset::~asset() { delete m_data; }

int main() {
  asset* me;
  me = new asset;
  me->m_data->name = "me";
  me->m_data->code = 10086;
  me->m_data->data = 3245;
  me->printData();
  cout << "=========================" << endl;
  asset* father = new asset;
  father->m_data->name = "father";
  father->m_data->code = 100;
  father->m_data->data = 32235;
  father->printData();
  cout << "=========================" << endl;
  *father = *me;
  father->printData();
  cout << "=========================" << endl;
  return 0;
}
