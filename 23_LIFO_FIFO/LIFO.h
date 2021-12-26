#pragma once
#include "Interface.h"
class LIFO : public Interface
{
	unsigned int sp; // stack pointer (where to push)
	void rebase(int* vect);
	LIFO() = default;
public:
	LIFO(int);
	int pop();
	LIFO& push(int);
	friend std::ostream& operator<<(std::ostream& os, const LIFO&);
};

