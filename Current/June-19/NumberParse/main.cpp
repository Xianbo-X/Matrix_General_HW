#include <stdio.h>
#include <iostream>
#include <string>
#include "judge.h"
using namespace std;

void BasicTest() {
  string str1 = "", str2 = "1";
  try {
    int num1 = parseNumber(str1.c_str());
    int num2 = parseNumber(str2.c_str());
    printf("sum is %d\n", num1 + num2);
  } catch (NumberParseException) {
    // printf("Not a number.\n");
    cout << "Not a number. \n";
  }
  str1 = "1";
  try {
    int num1 = parseNumber(str1.c_str());
    int num2 = parseNumber(NULL);
    printf("sum is %d\n", num1 + num2);
    // cout << "Not a number. \n";
  } catch (NumberParseException) {
    printf("Not a number.\n");
    // cout << "Not a number. \n";
  }
  cin >> str1 >> str2;
  try {
    int num1 = parseNumber(str1.c_str());
    int num2 = parseNumber(str2.c_str());
    printf("sum is %d\n", num1 + num2);
    // cout << " sum is % d\n " << num1 + num2;
  } catch (NumberParseException) {
    printf("Not a number.\n");
    // cout << "Not a number. \n";
  }
}

void HardTest() {
  int Ttime;
  cin >> Ttime;
  while (Ttime--) {
    string str1, str2;
    cin >> str1 >> str2;
    try {
      int num1 = parseNumber(str1.c_str());
      int num2 = parseNumber(str2.c_str());
      printf("sum is %d\n", num1 + num2);
    } catch (NumberParseException) {
      printf("Not a number.\n");
    }
  }
}

int main() {
  int hard;
  cin >> hard;
  if (hard)
    HardTest();
  else
    BasicTest();
}