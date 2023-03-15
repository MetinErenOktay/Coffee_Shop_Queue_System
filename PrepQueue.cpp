#include "PrepQueue.h"

PrepQueue::PrepQueue() : maxLen(0) {}


void PrepQueue::pushCustomer(Customer * customer) {
    prepQueue.enqueue(customer);
}

Customer* PrepQueue::popCustomer() {
    return sortAndDequeueMinCustomer();
}

bool PrepQueue::empty() {
    return prepQueue.empty();
}

void PrepQueue::updateMaxLen() {
    unsigned int tmp = prepQueue.top;
    maxLen = max(maxLen, tmp);
}

unsigned int PrepQueue::getMaxLen() const {
    return maxLen;
}

void PrepQueue::sortCustomersDescending() const {
    for (int i = 0; i < prepQueue.top; ++i) {
        for (int j = 0; j < prepQueue.top - i - 1; ++j) {
            if (prepQueue.arr[j]->getCost() < prepQueue.arr[j + 1]->getCost()) {
                Customer *temp = prepQueue.arr[j];
                prepQueue.arr[j] = prepQueue.arr[j + 1];
                prepQueue.arr[j + 1] = temp;
            }
        }
    }
}

void PrepQueue::sortCustomersAscending() const {
    for (int i = 0; i < prepQueue.top; ++i) {
        for (int j = 0; j < prepQueue.top - i - 1; ++j) {
            if (prepQueue.arr[j]->getCost() > prepQueue.arr[j + 1]->getCost()) {
                Customer *temp = prepQueue.arr[j];
                prepQueue.arr[j] = prepQueue.arr[j + 1];
                prepQueue.arr[j + 1] = temp;
            }
        }
    }
}

Customer* PrepQueue::sortAndDequeueMinCustomer() {
    sortCustomersAscending();
    return prepQueue.dequeue();
}

Customer* PrepQueue::sortAndDequeueMaxCustomer() {
    sortCustomersDescending();
    return prepQueue.dequeue();
}
