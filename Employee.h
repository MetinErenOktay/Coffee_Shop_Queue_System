#ifndef ASSIGNMENT3_EMPLOYEE_H
#define ASSIGNMENT3_EMPLOYEE_H

#include "Customer.h"

class Employee : public Person {
protected:
  Customer *currentCustomer;

  int employeeId{};
  double busyTime;
public:
  explicit Employee(PersonType);
  void setEmployeeId(int);
   int getEmployeeId() const;
  Customer *getCurrentCustomer();
  virtual void createCustomer(Customer *) = 0; // pure virtual
   double getBusyTime() const;
};


#endif //ASSIGNMENT3_EMPLOYEE_H
