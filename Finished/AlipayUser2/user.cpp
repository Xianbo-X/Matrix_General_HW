#include "user.hpp"
#include <ctype.h>
#include <cstring>
#include <string>
using namespace Alipay;

// auxiliary functions
inline bool verifyPasswordFormat(const std::string& password) {
  if (password.length() < 8 || password.length() > 20) return false;
  for (int i = 0; i < password.length(); i++) {
    if (!isalnum(password[i])) return false;
  }
  return true;
}

inline bool verifyUsernameFormat(const std::string& username) {
  if (username.length() < 6 || username.length() > 20) return false;
  for (int i = 0; i < username.length(); i++) {
    if (!isalnum(username[i])) return false;
  }
  return true;
}
inline bool verifyPhoneFormat(const std::string& phone) {
  if (phone.length() != 13) return false;
  for (int i = 0; i < phone.length(); i++) {
    if (!isdigit(phone[i])) return false;
  }
  return true;
}

// member functions
user::user(const char* username, const char* password) {
  int len = strlen(username);
  if (len > 20) len = 20;
  for (int i = 0; i < len; i++) {
    this->username[i] = username[i];
  }

  int len = strlen(password);
  if (len > 20) len = 20;
  for (int i = 0; i < len; i++) {
    this->password[i] = password[i];
  }
}
user::~user() {
  username[0] = '\0';
  password[0] = '\0';
}

const char* user::getUsername() const { return username; }
const char* user::getPassword() const { return password; }

const void user::setUsername(const char* username) {
  if (verifyUsernameFormat(username))
    for (int i = 0; i < strlen(username); i++) {
      this->username[i] = username[i];
    }
}

const void user::setPassword(const char* password) {
  if (verifyPasswordFormat(password)) {
    for (int i = 0; i < strlen(password); i++) {
      this->password[i] = password[i];
    }
  }
}
double user::getBalance() { return balance; }

bool user::withdraw(double amount) {
  if (amount < 0) return false;
  if (amount > balance) return false;
  balance -= amount;
  return true;
}

bool user::deposite(double amount) {
  if (amount < 0) return false;
  balance += amount;
  return true;
}