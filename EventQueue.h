#ifndef ASSIGNMENT3_EVENTQUEUE_H
#define ASSIGNMENT3_EVENTQUEUE_H

#include <iostream>

#include "Event.h"
#include "Queue.h"

using namespace std;

class EventQueue {
    Queue<Event *> eventQueue;

    double currentTime;
    static bool sameTime(double, double);
public:
    EventQueue();
    void pushEvent(Person *, double);
    Event *popEvent();
    bool doNext();
    double getCurrentTime() const;

    bool empty();

    void sortEventsAscending() const;
    void sortEventsDescending() const;

    Event* sortAndDequeueMinEvent();
    Event* sortAndDequeueMaxEvent();
};


#endif //ASSIGNMENT3_EVENTQUEUE_H
