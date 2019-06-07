#include <iostream>
#include <string>
using namespace std;

string Reverse(const string str) {
  string strReverse;
  string::const_reverse_iterator rit = str.rbegin();
  string::iterator it = strReverse.begin();
  while (rit != str.rend()) {
    strReverse.insert(strReverse.end(), *rit);
    rit++;
  }
  return strReverse;
}

string BreakReverse(const string str) {
  if (str == "") return "";
  string temp = str;
  string res = "";
  while (!temp.empty() && *temp.begin() == '_') {
    res.push_back(*temp.begin());
    temp.erase(temp.begin());
  }  //将字符串处理成abc_sdasd或sdasd_bad_的形式,b并将无需处理的字符加入到结果中

  string::iterator last;
  string::iterator now;
  //两个迭代器用来获得_前的字符串
  now = temp.begin();  //将目前处理指向第一个，必然为需要翻转字符串
  while (now != temp.end()) {  // 当没有处理完全部字符串时执行
    last = now;                //记录需要翻转字串开始位置
    while (now != temp.end() && *now != '_') {  //寻找需要处理字符串结束位置;
      now++;
    }  //此时[last,now)为需要处理的字符串
    res += Reverse(string(last, now));  //[last,now)
    if (now != temp.end()) {
      res.push_back(*now);
      now++;
    }  //将Now指向下一个待处理开头并将'_'加入到结果中
  }
  return res;
}

int main() {
  int t;
  cin >> t;
  string str;
  while (t--) {
    cin >> str;
    cout << BreakReverse(str);
  }
  return 0;
}