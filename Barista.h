#ifndef ASSIGNMENT3_BARISTA_H
#define ASSIGNMENT3_BARISTA_H

#include "Employee.h"

class Barista : public Employee {
public:
  Barista();

  void createCustomer(Customer* customer) override;
};


#endif //ASSIGNMENT3_BARISTA_H
