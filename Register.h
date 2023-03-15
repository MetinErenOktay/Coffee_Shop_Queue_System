#ifndef ASSIGNMENT3_CASHIER_H
#define ASSIGNMENT3_CASHIER_H

#include "Employee.h"

class Register : public Employee {
public:
  Register();
  void createCustomer(Customer* person) override; // override virtual function
};


#endif //ASSIGNMENT3_CASHIER_H
