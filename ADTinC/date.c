#include "date.h"
#include <stdlib.h>
#include <string.h>

Date* CreateDate(int year, int month, int day) {
  Date* dateObj = (Date*)malloc(sizeof(Date));
  dateObj->year = year;
  dateObj->month = month;
  dateObj->day = day;
  return dateObj;
}

void DestroyDate(Date** p) { free(*p); }

Date* CopyDate(const Date* date) {
  Date* dateObj = (Date*)malloc(sizeof(Date));
  dateObj->year = date->year;
  dateObj->month = date->month;
  dateObj->day = date->day;
  return dateObj;
}

int GetYear(const Date* date) { return date->year; }
int GetMonth(const Date* date) { return date->month; }
int GetDay(const Date* date) { return date->day; }
void SetYear(Date* date, int year) { date->year = year; }
void SetMonth(Date* date, int month) { date->month = month; }
void SetDay(Date* date, int day) { date->day = day; }
void SetDate(Date* date, int year, int month, int day) {
  date->year = year;
  date->month = month;
  date->day = day;
}

char* num2Str(int num, int max_size) {
  int reverseNum = 0;
  while (num) {
    reverseNum *= 10;
    reverseNum += num % 10;
    num /= 10;
  }
  char* str = (char*)malloc(sizeof(char) * max_size);
  int len = 0;
  while (reverseNum) {
    str[len++] = reverseNum % 10 + 48;
    reverseNum /= 10;
  }
  str[len] = '\0';
  return str;
}

char* GetDateString(const Date* date) {
  char* yearStr = num2Str(date->year, 10);
  char* monthStr = num2Str(date->month, 10);
  char* dayStr = num2Str(date->day, 10);
  int totalLen = strlen(yearStr) + strlen(monthStr) + strlen(dayStr);
  char* dateStr = (char*)malloc(totalLen + 1);
  strncat(dateStr, yearStr, strlen(yearStr));
  strncat(dateStr, monthStr, strlen(monthStr));
  strncat(dateStr, dayStr, strlen(dayStr));
  dateStr[totalLen] = '\0';
  free(yearStr);
  free(monthStr);
  free(dayStr);
  return dateStr;
}

void DestroyDateString(char** p) { free(*p); }

int DayInMonth(int month, int year) {
  if (month == 2) {
    if ((!(year % 400)) || ((year % 4 == 0) && (year % 100 != 0))) return 29;
    return 28;
  }
  if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
  return 31;
}

void IncreaseDate(Date* date) {
  if (date->day == DayInMonth(date->month, date->year)) {
    date->month++;
    date->day = 1;
  } else
    date->day++;
  if (date->month == 13) {
    date->year++;
    date->month = 1;
  }
}

void DecreaseDate(Date* date) {
  if (date->day != 1)
    date->day--;
  else {
    if (date->month != 1) {
      date->month--;
      date->day = DayInMonth(date->month, date->year);
    } else {
      date->year--;
      date->month = 12;
      date->day = DayInMonth(date->month, date->year);
    }
  }
  return;
}