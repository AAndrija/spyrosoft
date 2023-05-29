#include "ABC.h"

UINT8 to_be_turned_off = ASCII_A + STATE_NUM; //holds the information which state is about turn off
UINT8 to_be_turned_on = ASCII_A; //holds the information which state is about turn on
std::mutex mtx;

// this function waits for input, which states to turn off
// it also checks if the input is valid
void input_scan(void)
{
	UINT8 var;
	while (1) {
		std::cin >> var;

		assert(var >= ASCII_A && var <= ASCII_A + STATE_NUM);

		if (to_be_turned_off >= (ASCII_A + STATE_NUM) && to_be_turned_on >= (ASCII_A + STATE_NUM)) //checks whether the machine is in the process of turning itself off and on
		{
			mtx.lock(); //entering critical section

			to_be_turned_off = var;
			to_be_turned_on = to_be_turned_off;

			mtx.unlock(); //exiting critical section

			std::cout << var << " gasenje"
				  << "\n"; //prints out which state is about to turn off
		} else {
			std::cout << "automat je u procesu paljenja"
				  << "\n";
		}
	}
}

// function which decides when to turn the states on and off
void next_state(void)
{
	while (1) {
		mtx.lock(); //entering critial section
		if ((to_be_turned_off >= 65 && to_be_turned_off < (65 + STATE_NUM))) { //checks if the machine is in the process of turning off
			std::cout << char(to_be_turned_off) << " se gasi"
				  << "\n"
				  << "==========="
				  << "\n";

			states[ASCII_TO_INDEX(to_be_turned_off)] = LOW; //turning the state off
			to_be_turned_off++;
		} else {
			if ((to_be_turned_on >= 65 && to_be_turned_on < (65 + STATE_NUM)) && //checks if the machine is in the process of turning off
			    states[ASCII_TO_INDEX(to_be_turned_on)] != HIGH) {
				std::cout << char(to_be_turned_on) << " se pali"
					  << "\n"
					  << "==========="
					  << "\n";
				states[ASCII_TO_INDEX(to_be_turned_on++)] = HIGH; //turning the state on
			}
		}
		mtx.unlock(); //exiting critical section
		sleep(2);
	}
}

// print out the current states
void print_out(void)
{
	while (1) {
		mtx.lock();
		for (int i = 0; i < STATE_NUM; i++) {
			std::cout << char(INDEX_TO_ASCII(i)) << " " << ((states[i] == HIGH) ? "Upaljeno" : "Ugaseno") << "\n";
		}
		mtx.unlock();
		std::cout << "===========\n";
		sleep(5);
	}
}