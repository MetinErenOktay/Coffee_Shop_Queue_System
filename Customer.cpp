#include "Customer.h"

Customer::Customer(double arrival, double order, double brew, double price) :
        Person(customer), arrival(arrival), order(order), prep(brew), cost(price) {}

double Customer::getStart() const {
  return arrival;
};

double Customer::getPlaceOrder() const {
  return order;
};

double Customer::getPrep() const {
  return prep;
};

void Customer::setFinish(double newFinish) {
  finish = newFinish;
};

double Customer::getTurnaround() const {
  return finish - arrival;
}

double Customer::getCost() const {
    return this->cost;
};