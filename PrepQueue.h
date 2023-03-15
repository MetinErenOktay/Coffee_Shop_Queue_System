#ifndef ASSIGNMENT3_PREPQUEUE_H
#define ASSIGNMENT3_PREPQUEUE_H

#include "Customer.h"

#include "Queue.h"
# include <iostream>

using namespace std;

class PrepQueue { // TODO: the problem is that it uses Queue's sort functions
    Queue<Customer *> prepQueue;
    unsigned int maxLen;
public:
    PrepQueue();

    Customer *popCustomer();
    void pushCustomer(Customer *);
    void updateMaxLen();
    bool empty();

    void sortCustomersAscending() const;
    void sortCustomersDescending() const;

    Customer* sortAndDequeueMinCustomer();
    Customer* sortAndDequeueMaxCustomer();

    unsigned int getMaxLen() const;
};

#endif //ASSIGNMENT3_PREPQUEUE_H