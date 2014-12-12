// prime_factor.cpp calculates the largest prime factor of 600851475143.
// (C) Edmund Higham, Nov 2014

#include <iostream>

#include <time.h>
#include <ctime>

#define BIGNUM unsigned long

using namespace std;

int main(void){

	BIGNUM A, B, C;

	time_t start, finish;

	A = 600851475143; // Number we want to find the largest prime factor of
	B = 2; 			  // Divisor
	C = 1;            // Largest Factor

	start = clock();

	while (A > 1){

		// If A is divisable by B...
		if(A % B == 0){

			// if true, reassign C to be the largest factor found
			if(B > C) C = B;

			A = A/B;
			B = 2; // Reset B
		}
		else{ // Increment B

			B += 1;

		}
	}

	finish = clock();

	std::cout << "\n" << C << "\n";
	std::cout << double(finish - start)/double(CLOCKS_PER_SEC) << "\n";

return 0;
}