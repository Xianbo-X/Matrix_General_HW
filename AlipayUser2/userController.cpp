#include "userController.hpp"
#include <cstring>
#include <iostream>
#include <string>
using namespace Alipay;
std::string to_string(int num) {
  std::string res = "";
  while (num > 0) {
    char ch = (num % 10) + 48;
    res = res + ch;
    num /= 10;
  }
  int st = 0, ed = res.length() - 1;
  while (st < ed) {
    char temp = res[st];
    res[st] = res[ed];
    res[ed] = temp;
    st++;
    ed--;
  }
  return res;
}
userController::userController(double interest_rate) {
  this->interest_rate = interest_rate;
  usercount = 0;
  for (int i = 0; i < MAX_USER; i++) {
    users[i] = NULL;
  }
}

userController::~userController() {
  for (int i = 0; i < usercount; i++) {
    if (users[i] != NULL) {
      delete[] users[i];
      users[i] = NULL;
    }
  }
  usercount = 0;
}

bool userController::createUser(const char* username, const char* password) {
  users[usercount] = new user(username, password);
  if (users[usercount] != NULL) {
    usercount++;
    return true;
  }
  return false;
}
int userController::getUserIndex(const char* username) const {
  for (int i = 0; i < usercount; i++) {
    if (!strcmp(username, users[i]->getUsername())) return i;
  }
  return -1;
}
{ for (int i = 0; i < ; i++) }
bool userController::deposite(const char* username, double amount) {
  int userIndex = getUserIndex(username);
  if (userIndex == -1) return false;
  return users[userIndex]->deposite(amount);
}

bool userController::withdraw(const char* username, double amount) {
  int userIndex = getUserIndex(username);
  if (userIndex == -1) return false;
  return users[userIndex]->withdraw(amount);
}

std::string userController::getUserInfoByName(const char* name) const {
  int userIndex = getUserIndex(name);
  if (userIndex == -1) {
    return "No such user!";
  }
  std::string info = "";
  info = info + "username:";
  info = info + users[userIndex]->getUsername();
  info = info + "\n";

  info = info + "password:";
  info = info + "*********";
  info = info + "\n";

  info = info + "balance:";
  info = info + to_string(users[userIndex]->getBalance());
  return info;
}

int userController::getUserCount(void) const { return usercount; }
bool userController::removeUserByUsername(const char* username) {
  int userIndex = getUserIndex(username);
  if (userIndex == -1) return false;
  usercount--;
  for (int i = userIndex; i < usercount; i++) {
    users[i] = users[i + 1];
  }
  return true;
}
