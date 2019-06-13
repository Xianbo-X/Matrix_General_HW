#ifndef SOURCE_H_
#define SOURCE_H_
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

void nature_complete(map<string, int> &nature) {
  for (int i = 0; i < 7; i++) {
    string temp;
    int intensity;
    cin >> temp >> intensity;
    nature.insert(pair<string, int>{temp, intensity});
  }
}
void card_complete(vector<pair<string, int>> &card, map<string, int> &nature) {
  int test;
  cin >> test;
  for (int i = 0; i < test; i++) {
    string name;
    int stars;
    int attack;
    int defense;
    int intensity;
    string attrbuite;
    std::cin >> name >> stars >> attack >> defense >> intensity >> attrbuite;
    if (attrbuite == "god" || stars > 12) continue;
    int mark = stars + attack * 10 + defense * 10 + intensity * 100000 +
               nature[attrbuite];
    card.push_back(pair<string, int>{name, mark});
  }
}

bool compare(pair<string, int> a, pair<string, int> b) {
  return (a.second > b.second);
}
void print(vector<pair<string, int>>::iterator begin,
           vector<pair<string, int>>::iterator end) {
  for (int i = 0; i < 4; i++) {
    if (begin == end) break;
    std::cout << begin->first;
    begin++;
    cout << endl;
  }
}
#endif