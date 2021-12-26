#pragma once

#include <ostream>

class FIFO
{
    int* arr;
    unsigned int head; // from where to pop
    unsigned int tail; // where to push
    unsigned int capacity;
    unsigned int size;
    FIFO() = default;
    void extend(); // increase capacity
    void shrink(); // decrease capacity
    void rebase(int* vect); // move queue elements to vect
    void moveToStart(); // move queue element to the start of arr
public:
    FIFO(int);
    FIFO& push(int);
    int pop();
    ~FIFO() { delete[] arr; };
    friend std::ostream& operator<<(std::ostream& os, const FIFO& fifo);
};
