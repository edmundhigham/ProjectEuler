/* sum_primes.cpp sums all the prime numbers up to the user's specification */
// (C) GPL, Edmund Higham, Nov 2014

#include <iostream>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

#define uint unsigned int
#define ulong unsigned long


bool is_prime(uint *num){

    bool prime = 1;

    if (floor(sqrt(*num)) >= 2){

        if (*num % 2 == 0){

            prime = 0;
        }
        else{

            for(uint i = 3; i <= floor(sqrt(*num)); i+=2){
        
                if (*num % i == 0) {
                    prime = 0;
                    break;
            
                }
            }
        }
    }

return prime;
}

int main(void){

    ulong acc = 0; // accumulator to sum prime numbers
    uint upper = 2000000; // upper limit of summation, default 2 million
    uint lower = 2; // lower limit of summation, default 2

    std::string input;

// user input

    std::cout << "\nPlease enter the upper summation limit [default=2m]: ";
    std::getline( std::cin, input );

    if ( !input.empty() ){
        std::istringstream stream( input );
        stream >> upper;
    }

    std::cout << "\nPlease enter the lower summation limit [default=2]: ";
    std::getline( std::cin, input );

    if ( !input.empty() ){
        std::istringstream stream( input );
        stream >> lower;
    }

    std::cin.clear();

    std::cout << "\nsumming between " << lower << " and "<< upper << "\n";

// sum primes

    for (uint k = lower; k <= upper; ++k){

        if ( is_prime( &k ) ) acc += k;

    }

// output sum

    std::cout << "\nThe sum of all the prime numbers between "
              << lower << " and " << upper << " is:" <<std::endl;

    std::cout << "\t sum = "<< acc << std::endl;

return 0;
}