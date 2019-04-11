#include "source.h"

Date::Date(int newYear, int newMonth, int newDay) {
  year = newYear;
  month = newMonth;
  day = newDay;
}

int Date::getYear() { return year; }
void Date::setYear(int newYear) { year = newYear; }

int Date::getMonth() { return month; }
void Date::setMonth(int Month) { month = Month; }

int Date::getDay() { return day; }
void Date::setDay(int Day) { day = Day; }

// Person Class Below

Person::Person(int id, int year, int month, int day) {
  this->id = id;
  birthDate = new Date(year, month, day);
  numberOfObjects++;
}

Person::Person(const Person &origin) {
  id = origin.id;
  birthDate =
      new Date(origin.birthDate->getYear(), origin.birthDate->getMonth(),
               origin.birthDate->getDay());
  numberOfObjects++;
}

Person::~Person() {
  delete birthDate;
  numberOfObjects--;
}

int Person::getId() { return id; }
Date *Person::getBirthDate() { return birthDate; }
int Person::getNumberOfObjects() { return numberOfObjects; }

int Person::numberOfObjects{0};
