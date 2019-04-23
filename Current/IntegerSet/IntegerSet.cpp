#include "IntegerSet.h"

IntegerSet::IntegerSet(int s[], int l) {
  for (int i = 0; i < l; i++) {
    if (s[i]) set[i] = 1;
  }
}