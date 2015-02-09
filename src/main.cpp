#define DEBUG false
#define SDBG false

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stack>
#include <queue>

//test comment pls ignore

using namespace std;

bool ParseBrainfuckSyntax( unsigned char );
bool EvalBrainfuckSyntax( unsigned char );

//Globals
unsigned char *ptr;                       //Data pointer
unsigned char arrayMemory[65536] = { 0 }; //Memory array
unsigned char *g_instructions;            //Vector for tracking instructions
int g_instructionc = 0;
int loopBeginnings,loopEndings,loopDepth = 0;
int PC = 0;
int **loopStart,**loopEnd;
//Todo: command shell mode
//if(argc == 1) commandMode = true;
bool g_commandMode = false;



int main(int argc, char *argv[])
{
    string filename;
    filename = "example.bf";
    ptr = arrayMemory;
    queue<int> beginLoopAddresses;
    stack<int> endLoopAddresses;
    unsigned char input;
    ifstream fin;
    fin.open(filename.c_str());
    //fin.open(argv[1]);
    while(fin.good()){
        //Read input file and determine instructions
        input = fin.get();
        //SDBG && DEBUG && cout << input << endl;
        if( ParseBrainfuckSyntax( input ) ) g_instructionc++;
    }
    g_instructions = new unsigned char[g_instructionc];
    fin.close();
    fin.open(filename.c_str());
    int ins_index_temp = 0;
    while(fin.good()){
        input = fin.get();
        if( ParseBrainfuckSyntax( input ) ){
            g_instructions[ins_index_temp] = input;
            ins_index_temp++;
        }
    }
    
    DEBUG && cout << g_instructions << endl;
    
    for(int i = 0; i < g_instructionc; i++){
        if( g_instructions[i] == '[' ){
            beginLoopAddresses.push(i);
            loopBeginnings++;
        }
        if( g_instructions[i] == ']' ){
            endLoopAddresses.push(i);
            loopEndings++;
        }
    }
    DEBUG && cout << "Trace: counted brackets\n";
    if (loopBeginnings != loopEndings){
        cout << "Syntax error: incomplete loop. Exiting program." << endl;
        return 1;
    }
    DEBUG && cout << "Trace: all loops work\n";
    loopStart = new int*[loopBeginnings];
    loopEnd = new int*[loopEndings];
    for(int i = 0; i < loopBeginnings; i++)
    {
        *loopStart[i] = beginLoopAddresses.front();
        beginLoopAddresses.pop();
        *loopEnd[i] = endLoopAddresses.top();
        endLoopAddresses.pop();
    }
    DEBUG && cout << *loopStart << endl;
    DEBUG && cout << *loopEnd << endl;
    //end "lexing"
    DEBUG && cout << "Trace: lexing complete\n";

    //program execution loop
    for(PC = 0; PC < g_instructionc; PC++){
        unsigned char cur_ins = (unsigned char) g_instructions[PC];
        bool status;
        status = EvalBrainfuckSyntax( cur_ins );
        if(!status) cout << "Unknown syntax error.\n";
    }
    //system("PAUSE");
    return 0;
}

bool EvalBrainfuckSyntax( unsigned char input ){
    DEBUG && cout << input;
    switch( input ){
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
    case '[':
        if(*ptr == 0){
            PC = *loopEnd[loopDepth];
        } else {
            loopDepth++;
        }
        break;
    case ']':
        if(*ptr == 0){
            loopDepth--;
        } else {
            PC = (*loopStart[loopDepth]);
        }
        break;
    default:
        return false;
    }
    cout << ' ' << "returning from parse\n";
    return true;
}


bool ParseBrainfuckSyntax( unsigned char input ){
    //Return true if input is valid brainfuck instruction.
    switch( input )
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

