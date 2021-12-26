#include "FIFO.h"
#include <iomanip>
#include <cassert>

void FIFO::rebase(int* vect) {
    for (size_t i = 0; i < size; i++) {
        vect[i] = arr[i + head];
    }
    delete[] arr;
    arr = vect;
    head = 0;
    tail = size;
}

void FIFO::moveToStart() {
    for (size_t i = 0; i < size; i++) {
        arr[i] = arr[i + head];
    }
    head = 0;
    tail = size;
}

FIFO::FIFO(int N) {
    assert(N > 0);
    capacity = N;
    arr = new int[N];
    size = 0;
    tail = 0;
    head = 0;
}

FIFO& FIFO::push(int elem) {
    if (tail == capacity) {
        if (size < capacity) {
            moveToStart();
        }
        else {
            extend();
        }
    }
    arr[tail] = elem;
    tail++;
    size++;
    return *this;
}

int FIFO::pop() {
    if (size == 0) {
        return 0;
    }
    if (size < 2 * capacity / 3) {
        shrink();
    }
    head++;
    size--;
    return arr[head - 1];
}

std::ostream& operator<<(std::ostream& os, const FIFO& fifo) {
    os << std::endl;
    os << "        +--------+" << std::endl;
    for (size_t i = fifo.head; i <= fifo.tail; i++)
    {
        if (i == fifo.head)
            os << " head > ";
        else
            os << "        ";
        if (i != fifo.tail) {
            os << '|' << std::setfill(' ') << std::setw(8) << fifo.arr[i] << '|' << std::endl;
        }
        else {
            os << "|        | < tail " << std::endl;
        }
        os << "        +--------+" << std::endl;
    }
    os << std::endl;
    return os;
}