#include "Object.h"

void TestObjects() {
  Object** ob = new Object*[4];
  for (int i = 0; i < 3; i++) {
    ob[i] = new Object(i + 1);
  }
  for (int i = 3; i > 1; i--) {
    delete ob[i - 1];
  }
  ob[3] = new Object(4);
  delete ob[3];
  delete ob[0];
  delete[] ob;
}