#include "Interface.h"
#include <cassert>

void Interface::extend() {
    int* vect = new int[3 * capacity / 2 + 1];
    assert(vect != nullptr);
    rebase(vect);
    capacity = 3 * capacity / 2 + 1;
}

void Interface::shrink() {
    int* vect = new int[2 * capacity / 3 - 1];
    assert(vect != nullptr);
    rebase(vect);
    capacity = 2 * capacity / 3 - 1;
}