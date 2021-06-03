class Brain {
	Brain();
	Brain(int);
	~Brain();
	int fuck(const char*);
	bool isValidBF(unsigned char);
	bool eval(unsigned char);
	
	unsigned char *ptr;
	unsigned char *memory;
	unsigned char *instructions;
	int cInstruction;
	int cLoopEntries;
	int cLoopExits;
	int cLoopDepth;
	int PC;
	int **loopStart;
	int **loopEnd;
}
