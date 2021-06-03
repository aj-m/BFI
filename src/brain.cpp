#include "brain.h"
#include <stack>
#include <queue>
#ifdef DEFAULT_MEMSIZE
	#if DEFAULT_MEMSIZE <= 0
		#undef DEFAULT_MEMSIZE
	#endif
#endif
#define DEFAULT_MEMSIZE 30000

Brain::Brain() {
	this(DEFAULT_MEMSIZE);
}

Brain::Brain(int memSize) {
	int actualMemSize = 0;
	if (memSize < 0 || memSize > 65536) {
		actualMemSize = DEFAULT_MEMSIZE;
	} else {
		actualMemSize = memSize;
	}
	this.memory = new unsigned char[actualMemSize];
	this.ptr = this.memory;
	this.cInstruction = 0;
	this.cLoopEntries = 0;
	this.cLoopExits = 0;
	this.cLoopDepth = 0;
	this.PC = 0;

	//this.
}

int Brain::fuck(const char* path) {
}

bool Brain::isValidBF(unsigned char item) {
	switch(item) {
	case '>':
	case '<':
	case '+':
	case '-':
	case '.':
	case ',':
	case '[':
	case ']':
		return true;
	default:
		return false;
	}
}

bool Brain::eval(unsigned char item) {
	switch(item) {
	case '>':
		++(this.ptr);
		break;
	case '<':
		--(this.ptr);
		break;
	case '+':
		++(*this.ptr);
		break;
	case '-':
		--(*this.ptr);
		break;
	case '.':
		putchar(*(this.ptr));
		break;
	case ',':
		*(this.ptr) = getchar();
		break;
	case '[':
		if(*(this.ptr) == 0) {
			this.PC = *loopEnd[cLoopDepth];
		} else {
			this.cLoopDepth++;
		}
		break;
	case ']':
		if(*(this.ptr) == 0) {
			this.cLoopDepth--;
		} else {
			PC = (*loopStart[cLoopDepth]);
		}
		break;
	default:
		return false;
	}
	return true;
}

