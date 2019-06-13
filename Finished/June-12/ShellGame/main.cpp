#include <iostream>
#include <string>
/*
int findInit(const int total, const int finalPos, int step) {
  if (step == total) return finalPos;
  if (step & 1) {
    int temp = findInit(total, finalPos, step + 1);
    if (temp == 1) return 2;
    if (temp == 2) return 1;
    if (temp == 3) return 3;
  } else {
    int temp = findInit(total, finalPos, step + 1);
    if (temp == 1) return 1;
    if (temp == 2) return 3;
    if (temp == 3) return 2;
  }
}
*/

void swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}
int main() {
  int movements, pos;
  std::cin >> movements >> pos;
  movements = movements % 6;
  int a[6][3] = {0};
  a[0][0] = 0;
  a[0][1] = 1;
  a[0][2] = 2;
  for (int i = 1; i <= 5; i++) {
    if (i & 1) {
      a[i][0] = a[i - 1][1];
      a[i][1] = a[i - 1][0];
      a[i][2] = a[i - 1][2];
    } else {
      a[i][0] = a[i - 1][0];
      a[i][1] = a[i - 1][2];
      a[i][2] = a[i - 1][1];
    }
  }
  std::cout << a[movements][pos] << std::endl;
  return 0;
}