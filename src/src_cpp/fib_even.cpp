/* fib_even.cpp sums the even terms in a fibonacci sequence whose values
do not exceed 4 million/ */
// (C) Edmund Higham, Nov 2014

#include <iostream>
using namespace std;

int main(void){
    
    unsigned int fib[2];
    unsigned int buf;       // buf to copy old fib[0] term
    unsigned int N = 4000000;
    unsigned int acc = 0;
    
    fib[0] = 0;
    fib[1] = 1;

    while (fib[1] <= N){
    
        /* if the current term in the fibonacci sequence is even,
        accumulate the sum */
        if(!(fib[1] & 1)) acc += fib[1];
    
        // Caculate the next term in the sequence
        buf = fib[1];
        fib[1] += fib[0];
        fib[0] = buf;
    
    }
    
    std::cout << "\nThe sum of the even terms in a fibonacci sequence";
    std::cout << "\nwhose values do not exceed " << N << " is: \n";
    std::cout << acc << std::endl;
    
return 0;
}