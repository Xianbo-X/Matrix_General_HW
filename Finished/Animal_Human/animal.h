#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
#include <string>

class animal {
 private:
  std::string _species;
  int _eyes;

 public:
  animal();
  animal(const std::string species, const int eyes = 2);
  void print_eyes();  // species has _eyes eyes.

  // mutator fuctions
  void setSpecies(const std::string species);
  void setEyes(const int eyes);
};

animal::animal() : _species{""}, _eyes{2} {}
animal::animal(const std::string species, const int eyes)
    : _species{species}, _eyes{eyes} {}
void animal::print_eyes() {
  std::cout << _species << " has " << _eyes << " eyes." << std::endl;
}
void animal::setSpecies(const std::string species) { _species = species; }
void animal::setEyes(const int eyes) { _eyes = eyes; }
#endif  // ANIMAL_H