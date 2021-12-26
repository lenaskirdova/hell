#pragma once

#include <ostream>

class LIFO
{
    int* arr;
    unsigned int sp; // stack pointer (where to push)
    unsigned int capacity;
    LIFO() = default;
    void extend(); // increase capacity
    void shrink(); // decrease capacity
    void rebase(int*);
public:
    LIFO(int);
    LIFO& push(int);
    int pop();
    ~LIFO() { delete[] arr; };
    friend std::ostream& operator<<(std::ostream& os, const LIFO& fifo);
};


