#include <iostream>
#include <string>
using namespace std;

int main() {
  int t;
  cin >> t;
  string s1, s2, s3;
  while (t--) {
    cin >> s1 >> s2 >> s3;
    bool findFlag = true;
    while (findFlag) {
      findFlag = false;
      int len1 = s1.size();
      int len2 = s2.size();
      for (int i = 0; i <= len1 - len2; i++) {  //当测例为
                                                // 3
                                                // abc abc a    出错，i=0,
                                                // -2时仍然执行 abcbcxabc abc a
                                                // abc ab a
        bool flag = true;
        for (int j = i; j < s2.size() + i; j++)
          if (s1[j] != s2[j - i]) {
            flag = false;
            break;
          }

        if (flag) {
          s1.replace(i, s2.size(), s3);
          findFlag = true;
          break;
        }
      }
    }
    cout << s1 << endl;
  }
  return 0;
}