#include "brain.h"
#include <cstdlib>
#include <cstdio>
#include <stack>
#include <queue>
#ifdef DEFAULT_MEMSIZE
	#if DEFAULT_MEMSIZE <= 0
		#undef DEFAULT_MEMSIZE
	#endif
#endif
#define DEFAULT_MEMSIZE 30000

Brain::Brain(int memSize) {
	int actualMemSize = 0;
	if (memSize < 0 || memSize > 65536) {
		actualMemSize = DEFAULT_MEMSIZE;
	} else {
		actualMemSize = memSize;
	}
	memory = new unsigned char[actualMemSize];
	ptr = memory;
	cInstruction = 0;
	cLoopEntries = 0;
	cLoopExits = 0;
	cLoopDepth = 0;
	PC = 0;

	//this.
}

Brain::~Brain() {
	delete[] *loopStart;
	delete[] loopStart;
	loopStart = nullptr;
	delete[] *loopEnd;
	delete[] loopEnd;
	loopEnd = nullptr;
	delete[] instructions;
	instructions = nullptr;
	delete[] memory;
	memory = nullptr;
	ptr = nullptr;
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
		++ptr;
		break;
	case '<':
		--ptr;
		break;
	case '+':
		++(*ptr);
		break;
	case '-':
		--(*ptr);
		break;
	case '.':
		putchar(*ptr);
		break;
	case ',':
		*ptr = getchar();
		break;
	case '[':
		if(*ptr == 0) {
			PC = *loopEnd[cLoopDepth];
		} else {
			cLoopDepth++;
		}
		break;
	case ']':
		if(*ptr == 0) {
			cLoopDepth--;
		} else {
			PC = (*loopStart[cLoopDepth]);
		}
		break;
	default:
		return false;
	}
	return true;
}

