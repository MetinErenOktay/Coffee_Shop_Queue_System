#include "Register.h"

Register::Register() : Employee(cashier) {}

void Register::createCustomer(Customer *person) {
  busyTime += person->getPlaceOrder();
  currentCustomer = person;
};