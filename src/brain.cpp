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
	memory = unsigned char[actualMemSize];
	
	
		
	
		
	
}

