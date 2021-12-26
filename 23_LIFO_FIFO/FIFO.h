#pragma once
#include "interface.h"
class FIFO : public Interface
{
	unsigned int head; // from where to pop
	unsigned int tail; // where to push
	unsigned int size;
	FIFO() = default;
	void rebase(int* vect); // move queue elements to vect
	void moveToStart(); // move queue element to the start of arr
public:
	FIFO(int);
	FIFO& push(int);
	int pop();
	friend std::ostream& operator<<(std::ostream& os, const FIFO& fifo);
};

