#ifndef DATE_H_
#define DATE_H_

typedef struct {
  int year, month, day;
} Date;

Date* CreateDate(int year, int month, int day);
void DestroyDate(Date** p);
Date* CopyDate(const Date* date);

int GetYear(const Date* date);
int GetMonth(const Date* date);
int GetDay(const Date* date);
void SetYear(Date* date, int year);
void SetMonth(Date* date, int month);
void SetDay(Date* date, int day);
void SetDate(Date* date, int year, int month, int day);

char* GetDateString(const Date* date);
void DestroyDateString(char** p);

void IncreaseDate(Date* date);
void DecreaseDate(Date* date);

#include <stdlib.h>
#include <string.h>
#include "date.h"

Date* CreateDate(int year, int month, int day) {
  Date* dateObj = (Date*)malloc(sizeof(Date));
  dateObj->year = year;
  dateObj->month = month;
  dateObj->day = day;
  return dateObj;
}

void DestroyDate(Date** p) {
  free(*p);
  *p = NULL;
}

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
  char* reverseStr = (char*)malloc(sizeof(char) * max_size);
  int len = 0;
  while (num) {
    reverseStr[len++] = num % 10 + 48;
    num /= 10;
  }
  reverseStr[len] = '\0';
  char* str = (char*)malloc(sizeof(char) * (len + 1));
  for (int i = 0; i < len; i++) {
    str[i] = reverseStr[len - i - 1];
  }
  str[len] = '\0';
  free(reverseStr);
  return str;
}

void dateStrcat(char* dest, const char* src, int high, int low) {
  for (int i = strlen(src); i > 0; i--) {
    dest[high--] = src[i - 1];
  }
  while (high >= low) {
    dest[high--] = '0';
  }
}

char* GetDateString(const Date* date) {
  char* yearStr = num2Str(date->year, 10);
  char* monthStr = num2Str(date->month, 10);
  char* dayStr = num2Str(date->day, 10);
  // int totalLen = strlen(yearStr) + strlen(monthStr) + strlen(dayStr);
  const int totalLen = 4 + 2 + 2 + 2;
  char* dateStr = (char*)malloc(totalLen + 1);
  // strncpy(dateStr, yearStr, strlen(yearStr) + 1);
  dateStrcat(dateStr, yearStr, 3, 0);
  dateStrcat(dateStr, "-", 4, 4);
  dateStrcat(dateStr, monthStr, 6, 5);
  dateStrcat(dateStr, "-", 7, 7);
  dateStrcat(dateStr, dayStr, 9, 8);
  dateStr[totalLen] = '\0';
  free(yearStr);
  free(monthStr);
  free(dayStr);
  return dateStr;
}

void DestroyDateString(char** p) {
  free(*p);
  *p = NULL;
}
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
#endif