
#ifndef _heappriorityqueue_h
#define _heappriorityqueue_h

#include <iostream>
#include <string>
#include "PQEntry.h"
using namespace std;


class HeapPriorityQueue {
public:
    HeapPriorityQueue();
    ~HeapPriorityQueue();
    void changePriority(string value, int newPriority);
    void clear();
    string dequeue();
    void enqueue(string value, int priority);
    bool isEmpty() const;
    string peek() const;
    int peekPriority() const;
    int size() const;

    void checkResize();
    void swap(int x,int y);
    string toString() const;
    void checkChildren(int i);

    friend ostream& operator <<(ostream& out, const HeapPriorityQueue& queue);

private:

    PQEntry* myElements;
    int mySize;
    int myCapacity;



};

#endif
