#include "SingleDog.hpp"
#include <cstring>

SingleDog::SingleDog(int id_, char *name_) : id{id_} {
  name = new char[strlen(name_) + 1];
  strncpy(name, name_, strlen(name_) + 1);
  count++;
}

SingleDog::SingleDog(const SingleDog &other) : id{other.id} {
  name = new char[strlen(other.name) + 1];
  strncpy(name, other.name, strlen(other.name) + 1);
  count++;
}

SingleDog::~SingleDog() {
  if (name!=NULL) delete[] name;
  count--;
}

int SingleDog::getCount() { return count; }

int SingleDog::count=0;