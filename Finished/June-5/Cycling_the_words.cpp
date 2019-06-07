#include <iostream>
#include <queue>
using namespace std;

void print(queue<string> q) {
  while (!q.empty()) {
    cout << q.front();
    q.pop();
    if (!q.empty()) cout << " ";
  }
  cout << endl;
  return;
}

queue<string> Break(const string str) {
  queue<string> q;
  while (!q.empty()) q.pop();
  if (str == "") return q;
  string temp = str;
  while (*temp.begin() == ' ') {
    temp.erase(temp.begin());
  }  //清除头部部多余空格

  while (*temp.end() == ' ') {
    temp.erase(temp.end());
  }  //清除尾部多余空格
  int pos;

  while (pos = temp.find(' '), pos != string::npos) {
    q.push(temp.substr(0, pos));
    temp.erase(0, pos - 0 + 1);

    while (*temp.begin() == ' ') {
      temp.erase(temp.begin());
    }  //清除头部部多余空格

    while (*temp.end() == ' ') {
      temp.erase(temp.end());
    }  //清除尾部多余空格
  }
  if (!temp.empty()) q.push(temp);
  return q;
}

int main() {
  string line;
  queue<string> list;
  getline(cin, line);
  list = Break(line);
  for (int i = 0; i < list.size(); i++) {
    print(list);
    string temp = list.front();
    list.pop();
    list.push(temp);
  }
  return 0;
}