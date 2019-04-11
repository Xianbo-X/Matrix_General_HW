#include "Person.hpp"

Date::Date(int newYear, int newMonth, int newDay) {
  year = newYear;
  month = newMonth;
  day = newDay;
}

int Date::getYear() { return year; }
void Date::setYear(int x) { year = x; }
int Date::getMonth() { return month; }
void Date::setMonth(int x) { month = x; }
int Date::getDay() { return day; }
void Date::setDay(int x) { day = x; }

Person::Person(int _id, int year, int month, int day) {
  id = _id;
  birthDate = new Date(year, month, day);
}

Person::Person(Person& origin) {
  id = origin.id;
  birthDate =
      new Date(origin.birthDate->getYear(), origin.birthDate->getMonth(),
               origin.birthDate->getDay());
}

Person::~Person() {
  if (birthDate) delete birthDate;
}

int Person::getId() { return id; }

Date* Person::getBirthDate() { return birthDate; }