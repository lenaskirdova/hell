#include "LIFO.h"
#include <iomanip>
#include <cassert>
#include "Interface.h"

void LIFO::rebase(int* vect) {
    for (size_t i = 0; i < sp; i++) {
        vect[i] = arr[i];
    }
    delete[] arr;
    arr = vect;
}

LIFO::LIFO(int N) {
    assert(N > 0);
    capacity = N;
    arr = new int[N];
    sp = 0;
}

LIFO& LIFO::push(int elem) {
    if (sp == capacity) {
        extend();
    }
    arr[sp] = elem;
    sp++;
    return *this;
}

int LIFO::pop() {
    if (sp == 0) {
        return 0;
    }
    if (sp < 2 * capacity / 3) {
        shrink();
    }
    sp--;
    return arr[sp];
}

std::ostream& operator<<(std::ostream& os, const LIFO& lifo) {
    os << std::endl;
    os << "        +--------+" << std::endl;
    for (size_t i = 0; i <= lifo.sp; i++) {
        os << "        ";
        if (i != lifo.sp) {
            os << '|' << std::setfill(' ') << std::setw(8) << lifo.arr[i] << '|' << std::endl;
        }
        else {
            os << "|        | < sp" << std::endl;
        }
        os << "        +--------+" << std::endl;
    }
    os << std::endl;
    return os;
}