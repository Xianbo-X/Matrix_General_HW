#include "user.hpp"
#include <ctype.h>
#include <cstring>
#include <string>
using namespace alipay;

inline bool User::verifyPasswordFormat(const std::string &password) {
  if (password.length() < 8 || password.length() > 20) return false;
  for (int i = 0; i < password.length(); i++) {
    if (!isalnum(password[i])) return false;
  }
  return true;
}

inline bool User::verifyUsernameFormat(const std::string &username) {
  if (username.length() < 6 || username.length() > 20) return false;
  for (int i = 0; i < username.length(); i++) {
    if (!isalnum(username[i])) return false;
  }
  return true;
}
inline bool User::verifyPhoneFormat(const std::string &phone) {
  if (phone.length() != 13) return false;
  for (int i = 0; i < phone.length(); i++) {
    if (!isdigit(phone[i])) return false;
  }
  return true;
}

bool User::setUsername(const char *username) {
  if (!verifyUsernameFormat(username)) return false;
  this->username = username;
  return true;
}

bool User::setPassword(const char *new_password, const char *old_password) {
  if (verifyPasswordFormat(new_password)) {
    password = new_password;
    return true;
  } else if (verifyPasswordFormat(old_password)) {
    password = old_password;
    return false;
  }
  return false;
}
bool User::setPhone(const char *new_phone) {
  if (!verifyPhoneFormat(new_phone)) return false;
  phone = new_phone;
  return true;
}

bool User::setGender(Gender::Gender gender) {
  if (gender > 3 || gender < 0) return false;
  this->gender = gender;
  return true;
}

std::string User::getUsername(void) { return username; }
std::string User::getPhone(void) { return phone; }
Gender::Gender User::getGender(void) { return gender; }

long long int User::getMoneyAmount(const char *password) {
  if (strcmp(password, this->password.c_str())) return -1;
  return balance;
}

bool User::deposit(long long int amount) {
  if (amount < 0) return false;
  balance += amount;
  return true;
}

bool User::withdraw(long long int amount, const char *password) {
  if (amount < 0) return false;
  if (strcmp(password, this->password.c_str())) return false;
  if (amount > balance) return false;
  balance -= amount;
  return true;
}