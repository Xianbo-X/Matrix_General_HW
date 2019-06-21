#include "MyException.hpp"
#include <string>

MyException::MyException(const std::string msg) : message{msg} {}
std::string MyException::what() { return message; }