#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>

/*从前向后扫描，当不匹配时，把第一个抛出将后续的继续从前向后扫描。
 *
 */

class language {
  typedef std::set<std::string> setType;

 private:
  setType wordsList;
  std::string sequence;
  std::string sentence;

 public:
  language() : sequence{""}, sentence{""} { wordsList.clear(); }
  bool SetInList(std::string str) {
    wordsList.insert(str);
    return true;
  }
  bool SetStr(std::string str) {
    sequence = str;
    return true;
  }
  bool IsInList(std::string str) {
    return (wordsList.find(str) != wordsList.end());
  }

  std::string FindAndEraseWord(std::string& str) {
    std::string::iterator it = str.end();
    std::string word{str.begin(), str.begin() + 1};

    while (it != str.begin()) {
      std::string temp{str.begin(), it};
      if (IsInList(temp)) {
        word = temp;
        str.assign(it, str.end());
        return word;
      }
      it--;
    }
    str.assign(str.begin() + 1, str.end());
    return word;
  }

  std::string GetSentence() const { return sentence; }

  bool BreakInSentences() {
    std::string temp = sequence;
    while (*(temp.end() - 1) == ' ') {
      temp.erase(temp.end() - 1);
    }
    while (!temp.empty()) {
      sentence += FindAndEraseWord(temp);
      if (!temp.empty()) {
        sentence += ' ';
      }
    }
    return true;
  }
};

int main() {
  language seq1;
  int dictSize;
  std::cin >> dictSize;
  while (dictSize--) {
    std::string word;
    std::cin >> word;
    seq1.SetInList(word);
  }
  std::string sentence;
  std::cin >> sentence;
  seq1.SetStr(sentence);
  seq1.BreakInSentences();
  std::cout << seq1.GetSentence() << std::endl;

  return 0;
}