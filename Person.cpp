#include "Person.h"

int Person::globalId = 0;

Person::Person(PersonType personType) : personType(personType) {
  comparisonId = globalId++;
}

int Person::getTypeOf() {
  return personType;
}

int Person::getComparisonId() const {
  return comparisonId;
}