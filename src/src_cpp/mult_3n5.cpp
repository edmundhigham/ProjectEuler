// mult_3n5.cpp find the sum of all multiples of 3 and 5 below 1000
// (C) Edmund Higham, Nov 2014

#include <iostream>
using namespace std;

int main(void){

    unsigned int acc = 0;    /* Accumulator to sum the multiples*/
    int n = 1000;   /* Number to sum multiples until */

    // Loop 1 - sum multiples of 3
    for (int i = 3; i < n; i += 3){

        acc += i;
    }

    // Loop 2 - sum multiples of 5 which are not common with 3
    for (int i = 5; i < n; i += 5){
        
        if (i % 3 != 0) acc += i;
    }

    std::cout << "\nAll the multiples of 3 or 5 below " << n;
    std::cout << "\nsum to: \n \n";
    std::cout << acc << " \n \n";

return 0;
}