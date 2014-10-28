#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

    //Todo: command shell mode
    //bool commandMode = false;
    //if(argc == 1) commandMode = true;
bool verifyIsAction(char);

int main(int argc, char *argv[])
{
    //int allocation = 65536;			//Size of memory to play with
    char *ptr;							//Instruction pointer
    char array[65536];					//Memory array
	char input;
    ifstream inFile;
	inFile.open(argv[1]);
	inFile >> input;
	cout << input << endl;
    
    while(inFile.good()){
    	input = inFile.get();
    	
    }
    
    
    system("PAUSE");
    return EXIT_SUCCESS;
}

bool verifyIsAction(char input){
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
	}
}
