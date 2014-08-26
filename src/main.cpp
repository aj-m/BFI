#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[])
{
    //Todo: command shell mode
    //bool commandMode = false;
    //if(argc == 1) commandMode = true;
    //cout << commandMode << endl;
    //cout << argc << endl << argv[1] << endl;
    char *prgPtr;
    char input;
    ifstream inFile;
	inFile.open(argv[1]);
    
    while(inFile.good()){
    	input = inFile.get();
    	switch(input){
    		
    		default: continue;
    	}
    }
    
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
