#include <bits/stdc++.h>

using namespace std;

#include "Customer.h"
#include "Register.h"
#include "Barista.h"
#include "Queue.h"

#include "EventQueue.h"
#include "PrepQueue.h"

void model1(FILE *file, int numCashiers, vector<Customer *> &customers) {
  EventQueue eventQueue;
  for (auto & customer : customers) {
    eventQueue.pushEvent(customer, customer->getStart());
  }
  Register cashiers[numCashiers];
  Barista baristas[numCashiers / 3];

  Queue<int> registersQueue, baristasQueue; // todo

  Queue<Customer *> orderQueue;
  PrepQueue prepQueue;

  for (int i = 0; i < numCashiers; ++i) {
    registersQueue.enqueue(i);
    cashiers[i].setEmployeeId(i);
    if (i < numCashiers / 3) {
      baristasQueue.enqueue(i);
      baristas[i].setEmployeeId(i);
    }
  }
  while (!eventQueue.empty()) {
    do {
      Employee *employee;
      Customer *currCustomer;
      Event *event = eventQueue.popEvent();
      Person *person = event->getPerson();

      if (person->getTypeOf() == customer) {
        currCustomer = (Customer *) person;

        if (registersQueue.empty()) {
          orderQueue.enqueue(currCustomer);
        } else {
          int cashierId = (int) registersQueue.sortAndDequeueMin();
            cashiers[cashierId].createCustomer(currCustomer);
          eventQueue.pushEvent(&cashiers[cashierId], currCustomer->getPlaceOrder());
        }
      } else {
        employee = (Employee *) person;
        currCustomer = employee->getCurrentCustomer();

        if (person->getTypeOf() == cashier) {
          if (orderQueue.empty()) {
            registersQueue.enqueue((employee->getEmployeeId()));
          } else {
            Customer *nextCustomer = orderQueue.dequeue();
              employee->createCustomer(nextCustomer);
            eventQueue.pushEvent(employee, nextCustomer->getPlaceOrder());
          }

          if (baristasQueue.empty()) {
            prepQueue.pushCustomer(currCustomer);
          } else {
            int baristaId = (int) baristasQueue.sortAndDequeueMin();
              baristas[baristaId].createCustomer(currCustomer);
            eventQueue.pushEvent(&baristas[baristaId], currCustomer->getPrep());
          }
        } else {
          if (prepQueue.empty()) {
            baristasQueue.enqueue((employee->getEmployeeId()));
          } else {
            Customer *nextCustomer = prepQueue.popCustomer();
              employee->createCustomer(nextCustomer);
            eventQueue.pushEvent(employee, nextCustomer->getPrep());
          }

          currCustomer->setFinish(eventQueue.getCurrentTime());
        }
      }
      delete event;
    } while (eventQueue.doNext());

    orderQueue.updateMaxLen();
    prepQueue.updateMaxLen();
  }

  double timeElapsed = eventQueue.getCurrentTime();
  fprintf(file, "%.2lf\n", timeElapsed);
  fprintf(file, "%u\n", orderQueue.getMaxLen());
  fprintf(file, "%u\n", prepQueue.getMaxLen());
  for (int i = 0; i < numCashiers; ++i) {
    fprintf(file, "%.2lf\n", cashiers[i].getBusyTime() / timeElapsed);
  }
  for (int i = 0; i < numCashiers / 3; ++i) {
    fprintf(file, "%.2lf\n", baristas[i].getBusyTime() / timeElapsed);
  }
  for (auto & customer : customers) {
    fprintf(file, "%.2lf\n", customer->getTurnaround());
  }
}

void model2(FILE *file, int numRegisters, vector<Customer *> &customers) {
  EventQueue eventQueue;
  for (auto & customer : customers) {
    eventQueue.pushEvent(customer, customer->getStart());
  }
  Register cashiers[numRegisters];
  Barista baristas[numRegisters / 3];

  Queue<int> readyCashiers, readyBaristas[numRegisters / 3];

  Queue<Customer *> orderQueue;
  PrepQueue brewQueue[numRegisters / 3];
  for (int i = 0; i < numRegisters; ++i) {
    readyCashiers.enqueue(i);
    cashiers[i].setEmployeeId(i);
    if (i < numRegisters / 3) {
      readyBaristas[i].enqueue(i);
      baristas[i].setEmployeeId(i);
    }
  }
  while (!eventQueue.empty()) {
    do {
      Employee *employee;
      Customer *currCustomer;
      Event *event = eventQueue.popEvent();
      Person *person = event->getPerson();

      if (person->getTypeOf() == customer) {
        currCustomer = (Customer *) person;

        if (readyCashiers.empty()) {
          orderQueue.enqueue(currCustomer);
        } else {
          int cashierId = (int) readyCashiers.sortAndDequeueMin();
            cashiers[cashierId].createCustomer(currCustomer);
          eventQueue.pushEvent(&cashiers[cashierId], currCustomer->getPlaceOrder());
        }
      } else {
        employee = (Employee *) person;
        currCustomer = employee->getCurrentCustomer();

        if (person->getTypeOf() == cashier) {
          if (orderQueue.empty()) {
            readyCashiers.enqueue((employee->getEmployeeId()));
          } else {
            Customer *nextCustomer = orderQueue.dequeue();
              employee->createCustomer(nextCustomer);
            eventQueue.pushEvent(employee, nextCustomer->getPlaceOrder());
          }
          unsigned int baristaQueueId = (employee->getEmployeeId()) / 3;
          if (readyBaristas[baristaQueueId].empty()) {
            brewQueue[baristaQueueId].pushCustomer(currCustomer);
          } else {
            int baristaId = (int) readyBaristas[baristaQueueId].sortAndDequeueMin();
              baristas[baristaId].createCustomer(currCustomer);
            eventQueue.pushEvent(&baristas[baristaId], currCustomer->getPrep());
          }
        } else {

          unsigned int baristaQueueId = employee->getEmployeeId();

          if (brewQueue[baristaQueueId].empty()) {
            readyBaristas[baristaQueueId].enqueue((employee->getEmployeeId()));
          } else {
            Customer *nextCustomer = brewQueue[baristaQueueId].popCustomer();
              employee->createCustomer(nextCustomer);
            eventQueue.pushEvent(employee, nextCustomer->getPrep());
          }

          currCustomer->setFinish(eventQueue.getCurrentTime());
        }
      }
      delete event;
    } while (eventQueue.doNext());

    orderQueue.updateMaxLen();
    for (int i = 0; i < numRegisters / 3; ++i) {
      brewQueue[i].updateMaxLen();
    }
  }

  double timeElapsed = eventQueue.getCurrentTime();
  fprintf(file, "%.2lf\n", timeElapsed);
  fprintf(file, "%u\n", orderQueue.getMaxLen());
  for (int i = 0; i < numRegisters / 3; ++i) {
    fprintf(file, "%u\n", brewQueue[i].getMaxLen());
  }
  for (int i = 0; i < numRegisters; ++i) {
    fprintf(file, "%.2lf\n", cashiers[i].getBusyTime() / timeElapsed);
  }
  for (int i = 0; i < numRegisters / 3; ++i) {
    fprintf(file, "%.2lf\n", baristas[i].getBusyTime() / timeElapsed);
  }
  for (auto & customer : customers) {
    fprintf(file, "%.2lf\n", customer->getTurnaround());
  }
}


int main(int _, char *argv[]) {
    ifstream infile(argv[1]);
    FILE *file = fopen(argv[2], "w");

    int numCashiers, i;
    double arrival, order, brew, price;
    vector<Customer *> customers;

    infile >> numCashiers >> i;
    while (i--) {
        infile >> arrival >> order >> brew >> price;
        customers.push_back(new Customer(arrival, order, brew, price));
    }

    model1(file, numCashiers, customers);
    fprintf(file, "\n");
    model2(file, numCashiers, customers);

    infile.close();

    fclose(file);
}
