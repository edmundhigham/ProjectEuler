/* divisible_triangular.cpp computes the triangular number which has n
factors */
// (C) GPL, Edmund Higham, Nov 2014

#include <iostream>
#include <math.h>
#include <string>
#include <sstream>

#define uint unsigned int
#define ulong unsigned long

ulong gen_triag(const uint n){
	// generates the nth triangular number
	return n*(n+1)/2;
}


bool has_n_factors(const uint n, const ulong num){
	// checks if num has n factors
	uint acc = 0;

	for (int i = 1; i <= sqrt(num); ++i){
		if (num % i == 0) acc+=2;
	}

	if (acc >= n) {
		return 1;
	}
	else return 0;
}

int main(void){

	uint i = 4;
	uint nfactors = 500;
	std::string input;

	std::cout << "\nPlease enter the number of factors [default=500]: ";
    std::getline( std::cin, input );

    if ( !input.empty() ){
        std::istringstream stream( input );
        stream >> nfactors;
    }

	while(!has_n_factors(nfactors, gen_triag(++i))){
		;
	}

	std::cout << gen_triag(i) << std::endl;

	return 0;
}