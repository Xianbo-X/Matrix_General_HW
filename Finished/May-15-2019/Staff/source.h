#ifndef SOURCE_H_
#define SOURCE_H_
#include <string>
using std::string;
class MyDate {
  int year;
  int month;
  int day;

 public:
  MyDate() : year{0}, month{0}, day{0} {}
  MyDate(int x, int y, int z) : year{x}, month{y}, day{z} {}
};

class Person {
 private:
  string name;
  string address;
  string phonNumber;
  string email;

 public:
  Person() {}
  virtual string toString() { return "Person"; }
};

class Student : public Person {
 private:
  enum class_status { fressman, sophomore, junior, senior };
  class_status status;

 public:
  Student() {}
  string toString() { return "Student"; }
};

class Employee : public Person {
 private:
  string office;
  int salary;
  MyDate dateHired;

 public:
  string toString() { return "Employee"; }
};

class Faculty : public Employee {
 private:
  string officeHours;
  int rank;

 public:
  string toString() { return "Faculty"; }
};

class Staff : public Employee {
 private:
  string title;

 public:
  string toString() { return "Staff"; }
};

#endif