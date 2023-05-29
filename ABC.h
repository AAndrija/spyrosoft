#ifndef _ABC_H
#define _ABC_H

#include <iostream>
#include <ctime>
#include <unistd.h>
#include <mutex>
#include <thread>
#include <cassert>
#define STATE_NUM 3 //number of states of the machine
#define ASCII_A 65 //ASCII value of uppercase 'A'
#define UINT8 unsigned char
#define ASCII_TO_INDEX(X) ((X) - (ASCII_A)) //macro for converting ascii value to array index
#define INDEX_TO_ASCII(X) ((X) + (ASCII_A)) //macro for converting array index to ascii value

void input_scan(void);
void next_state(void);
void print_out(void);

extern UINT8 to_be_turned_off;
extern UINT8 to_be_turned_on;
extern std::mutex mtx;

enum high_low { LOW, HIGH };

extern high_low states[STATE_NUM]; //array of machine states
	//each array element represents on state (index 0 is letter 'A', index 1 is letter 'B', etc.)
	//length of array and number of states is determined by the STATE_NUM constant

#endif // _ABC_H
