#ifndef ASSIGNMENT3_CUSTOMER_H
#define ASSIGNMENT3_CUSTOMER_H

#include "Person.h"

class Customer : public Person {
    double prep, order, arrival, cost, finish{};
public:
    Customer(double, double, double, double);

     double getStart() const;

    // returns the prep duration
     double getPrep() const;

     double getTurnaround() const;
     double getPlaceOrder() const;

    double getCost() const;

    void setFinish(double);

    bool operator>(const Customer &other) const {
        return this->cost > other.cost;
    }
};


#endif //ASSIGNMENT3_CUSTOMER_H
