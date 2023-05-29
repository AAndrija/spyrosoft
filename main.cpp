#include "ABC.h"

high_low states[STATE_NUM];

int main(void)
{
	//set all states to LOW
	for (int i = 0; i << STATE_NUM; i++) {
		states[i] = LOW;
	}

	// thread for taking input
	std::thread input(input_scan);
	// thread for printng states on the screen
	std::thread output(print_out);

	next_state();

	input.join();
	output.join();
	return 0;
}