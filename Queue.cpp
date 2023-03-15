#include "Queue.h"
#include "Customer.h"
#include "Event.h"
#include <iostream>

using namespace std;

// An array based queue implementation
template<typename T>
bool Queue<T>::empty() {
    return top == 0;
}

template<typename T>
void Queue<T>::enqueue(T data) { // Insert at the end
    if (top >= 100) {
        cout << "Queue is full" << endl;
        return;
    }
    for (int i = top + 1; i > 0; i--) { // Push all elements back one
        arr[i] = arr[i - 1];
    }
    arr[0] = data; // Insert new element at front
    top++; // Increment top
}

template<typename T>
T Queue<T>::dequeue() { // Remove element from front
    if (empty()) {
        cout << "Queue is empty" << endl;
        // todo: might need to return something
    }
    top--; // Decrement top
    T tmp = arr[top]; // Store last element
    return tmp;
}

template<typename T>
Queue<T>::Queue() {
    arr = new T[100];
//    fill_n(arr, 100, new T);
}

template<typename T>
unsigned int Queue<T>::getMaxLen() const {
    return maxLen;
}

template<typename T>
void Queue<T>::updateMaxLen() {
    maxLen = max(maxLen, top);
}

template<typename T>
void Queue<T>::sortDescending() {
    for (int i = 0; i < top; i++) {
        for (int j = i + 1; j < top; j++) {
            if (arr[i] < arr[j]) {
                T tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }

}

template<typename T>
void Queue<T>::sortAscending() {
    for (int i = 0; i < top; i++) {
        for (int j = i + 1; j < top; j++) {
            if (arr[i] > arr[j]) {
                T tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

template<typename T>
T Queue<T>::sortAndDequeueMax() {
    sortAscending();
    return dequeue();
}

template<typename T>
T Queue<T>::sortAndDequeueMin() {
    sortDescending();
    return dequeue();
}

template class Queue<Customer *>;
template class Queue<Event *>;
template class Queue<int>;
