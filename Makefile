program: main barista customer employee event eventqueue person prepqueue queue register build
main:
	g++ -std=c++11 -c main.cpp -o main.o
barista:
	g++ -std=c++11 -c Barista.cpp -o barista.o
customer:
	g++ -std=c++11 -c Customer.cpp -o customer.o
employee:
	g++ -std=c++11 -c Employee.cpp -o employee.o
event:
	g++ -std=c++11 -c Event.cpp -o event.o
eventqueue:
	g++ -std=c++11 -c EventQueue.cpp -o eventqueue.o
person:
	g++ -std=c++11 -c Person.cpp -o person.o
prepqueue:
	g++ -std=c++11 -c PrepQueue.cpp -o prepqueue.o
queue:
	g++ -std=c++11 -c Queue.cpp -o queue.o
register:
	g++ -std=c++11 -c Register.cpp -o register.o
build:
	g++ main.o barista.o customer.o employee.o event.o eventqueue.o person.o prepqueue.o queue.o register.o -o Assignment3



