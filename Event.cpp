#include "Event.h"

Event::Event(Person *person, double triggerTime) : triggerTime(triggerTime), person(person) {}

Person *Event::getPerson() {
  return person;
}

double Event::getTime() const {
  return triggerTime;
}