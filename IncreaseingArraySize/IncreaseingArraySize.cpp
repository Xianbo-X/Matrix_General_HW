#include <iostream>

int *doubleCapacity(int *list, int size) {
  int *newList = new int[2 * size];
  for (int i = 0; i < size; i++) {
    newList[i] = list[i];
  }
  for (int i = size; i < 2 * size; i++) {
    newList[i] = 0;
  }
  return newList;
}

int main()
{
    int list
}