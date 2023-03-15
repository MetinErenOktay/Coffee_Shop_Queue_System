#include "Barista.h"

Barista::Barista() : Employee(barista) {}

void Barista::createCustomer(Customer *person) {
    busyTime = busyTime + person->getPrep();
    currentCustomer = person;

};