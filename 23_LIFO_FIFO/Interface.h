#pragma once

#include <ostream>

class Interface {
protected:
    int* arr;
    unsigned int capacity;
    void extend(); // increase capacity
    void shrink(); // decrease capacity
    virtual void rebase(int* vect) = 0; // move queue elements to vect
public:
    virtual Interface& push(int) = 0;
    virtual int pop() = 0;
    virtual ~Interface() { delete[] arr; };
};
