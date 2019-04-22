#include <iostream>
using namespace std;
inline void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

void recursive_sort(int *&num, int l, int r) {
  int i = l, j = r;
  int mid = (i + j) >> 1;
  while (i < j) {
    while (num[i] < num[mid]) i++;
    while (num[j] > num[mid]) j--;
    if (i <= j) {
      swap(num[i], num[j]);
      i++;
      j--;
    }
  }
  if (i < r) recursive_sort(num, i, r);
  if (l < j) recursive_sort(num, l, j);
}

int *sort(const int *const array, int size) {
  int *ans = new int[size];
  for (int i = 0; i < size; i++) {
    ans[i] = array[i];
  }
  recursive_sort(ans, 0, size - 1);
  return ans;
}



int main() {
  int *num;
  int size;
  cin >> size;
  num = new int[size];
  for (int i = 0; i < size; i++) {
    cin >> num[i];
  }
  num = sort(num, size);
  for (int i = 0; i < size; i++) {
    cout << num[i] << " ";
  }
  delete num;
  return 0;
}