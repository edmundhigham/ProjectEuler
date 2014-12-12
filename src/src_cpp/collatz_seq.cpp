/* collatz_seq.cpp finds the number n below a specifed upper limit which
produces results in the longest Collatz sequence. */
// (C) GPL, Edmund Higham, Nov 2014

#include <iostream>
#include <string>
#include <sstream>

#define uint unsigned int
#define ulong unsigned long int

using namespace std;

bool collatz(ulong * n){

	bool done = 0;

	if (*n & 1) { // n is odd
		*n += (*n<<1) + 1; // n = 3n +1
	}
	else {
		*n >>= 1; 

		if (*n == 1) done = 1;
		
	}
	return done;
};

int main(void){

	ulong this_num;
	ulong max_num;

	uint counter = 0;
	uint max_counter = 0;

	uint upper = 1000000;
	std::string input;

	std::cout << "\nPlease enter the upper limit [default=1m]: ";

	getline( std::cin, input );
	if ( !input.empty() ){
		std::istringstream stream( input );
		stream >> upper;
	}

	for (uint i = 1; i < upper; i+=2){
		this_num = i;

		while(!collatz(&this_num)){
			++counter;
		}

		if ( counter > max_counter ){
			max_counter = counter;
			max_num = i;
		}

		counter = 0;
	}

	std::cout << "\n The longest Collatz sequence was achieved with: "\
			  << max_num << std::endl;
	return 0;
}