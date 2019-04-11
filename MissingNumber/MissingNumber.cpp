#include <iostream>

using namespace std;

int missingNumber(int *num) {
  int check[5] = {0};
  for (int i = 0; i < 4; i++) check[num[i] - 1]++;
  for (int i = 0; i < 5; i++) {
    if (!check[i]) return i + 1;
  }
  return 0;
}

int main() {
  int *num = new int[4];
  for (int i = 0; i < 4; i++) cin >> num[i];
  cout << missingNumber(num) << endl;
  delete[] num;
  return 0;
}