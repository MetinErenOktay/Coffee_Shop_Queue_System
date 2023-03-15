#include "EventQueue.h"

EventQueue::EventQueue() : currentTime(0) {}

bool EventQueue::sameTime(double first, double second) {
    return (first + 0.00001 > second && first < second + 0.00001);
}


void EventQueue::pushEvent(Person *person, double time) {
    auto *event = new Event(person, currentTime + time);
    eventQueue.enqueue(event);
}


Event *EventQueue::popEvent() {
    Event *event = sortAndDequeueMaxEvent();
    currentTime = event->getTime();
    return event;
}


double EventQueue::getCurrentTime() const {
    return currentTime;
}


bool EventQueue::empty() {
    return eventQueue.empty();
}

bool EventQueue::doNext() {
    if (!eventQueue.empty()) {
        double nextTime = eventQueue.arr[eventQueue.top]->getTime();
        return sameTime(currentTime, nextTime);
    }
    return false;
}

void EventQueue::sortEventsAscending() const {
    for (int i = 0; i < eventQueue.top; i++) {
        for (int j = 0; j < eventQueue.top - i - 1; j++) {
            if (eventQueue.arr[j]->compare(eventQueue.arr[j + 1])) {
                swap(eventQueue.arr[j], eventQueue.arr[j + 1]);
            }
        }
    }
}

void EventQueue::sortEventsDescending() const {
    for (int i = 0; i < eventQueue.top; i++) {
        for (int j = 0; j < eventQueue.top - i - 1; j++) {
            if (!eventQueue.arr[j]->compare(eventQueue.arr[j + 1])) {
                swap(eventQueue.arr[j], eventQueue.arr[j + 1]);
            }
        }
    }
}

Event *EventQueue::sortAndDequeueMinEvent() {
    sortEventsAscending();
    return eventQueue.dequeue();
}

Event *EventQueue::sortAndDequeueMaxEvent() {
    sortEventsDescending();
    return eventQueue.dequeue();
}

