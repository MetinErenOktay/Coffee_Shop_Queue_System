#include "Employee.h"

Employee::Employee(PersonType personType) : Person(personType), busyTime(0), currentCustomer(nullptr) {}

void Employee::setEmployeeId(int newEmployeeId) {
  employeeId = newEmployeeId;
}

int Employee::getEmployeeId() const {
  return employeeId;
}

Customer *Employee::getCurrentCustomer() {
  return currentCustomer;
}

double Employee::getBusyTime() const {
  return busyTime;
}