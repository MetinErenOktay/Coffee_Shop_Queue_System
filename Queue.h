#ifndef ASSIGNMENT3_QUEUE_H
#define ASSIGNMENT3_QUEUE_H

template <typename T>
class Queue {
public:
    T* arr = new T[100];
    int top = 0;
    int maxLen = 0;
public:
    Queue();
    void enqueue(T);
    T dequeue();
    bool empty();

    void updateMaxLen();
     unsigned int getMaxLen() const;

    T sortAndDequeueMin();
    T sortAndDequeueMax();
private:
    void sortAscending();
    void sortDescending();
};


#endif //ASSIGNMENT3_QUEUE_H
