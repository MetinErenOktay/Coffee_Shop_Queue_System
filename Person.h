#ifndef ASSIGNMENT3_PERSON_H
#define ASSIGNMENT3_PERSON_H

enum PersonType {
  customer, cashier, barista
};

class Person {
  static int globalId;

  unsigned int comparisonId;
  PersonType personType;

public:
  explicit Person(PersonType);
  int getTypeOf();
   int getComparisonId() const;
};

#endif //ASSIGNMENT3_PERSON_H
