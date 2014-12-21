#define DEBUG true
#define SDBG false

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stack>
#include <queue>

using namespace std;

//Todo: command shell mode
//if(argc == 1) commandMode = true;
bool ParseBrainfuckSyntax( unsigned char );
//bool EvalBrainfuckSyntax( unsigned char );

//Globals
unsigned char *ptr;							//Data pointer
unsigned char arrayMemory[65536] = { 0 };	//Memory array
string g_instructions = "";					//Vector for tracking instructions
stack<int> beginLoopAddresses;
queue<int> endLoopAddresses;
bool g_commandMode = false;

int main(int argc, char *argv[])
{
	unsigned char input;
	ifstream fin;
	fin.open("example.bf");
	//fin.open(argv[1]);
    while(fin.good()){
    	//Read input file and determine instructions
    	input = fin.get();
    	SDBG && DEBUG && cout << input << endl;
    	if( ParseBrainfuckSyntax( input ) ) g_instructions += input;
    }
    DEBUG && cout << g_instructions << endl;
    
    
    //system("PAUSE");
    return 0;
}
/*
bool EvalBrainfuckSyntax(char input){
	switch(input){
    	case '>':
    		++ptr;
    		break;
    	case '<':
    		--ptr;
    		break;
    	case '+':
    		++*ptr;
    		break;
    	case '-':
    		--*ptr;
    		break;
    	case '.':
    		putchar(*ptr);
    		break;
    	case ',':
    		*ptr = getchar();
    		break;
    	default:
    		return false;
	}
	return true;
}
*/

bool ParseBrainfuckSyntax( unsigned char input){
	//Return true if input is valid brainfuck instruction.
	switch(input)
	{
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

