#ifndef ASSIGNMENT3_EVENT_H
#define ASSIGNMENT3_EVENT_H

#include "Person.h"

class Event {
    double triggerTime;
    Person *person;
public:
    Event(Person *, double);
     double getTime() const;
    Person *getPerson();

    bool compare(Event* other) {
        if (triggerTime + 0.00001 > other->triggerTime && other->triggerTime + 0.00001 > triggerTime) {
            return person->getComparisonId() > other->person->getComparisonId();
        }
        return triggerTime > other->triggerTime;
    }
};


#endif //ASSIGNMENT3_EVENT_H
