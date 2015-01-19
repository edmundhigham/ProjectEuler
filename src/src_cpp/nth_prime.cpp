/* nth_prime.cpp computes the nth prime of the natural numbers. */
// (C) GPL Edmund Higham, Nov 2014

#include <iostream>
#include <math.h>

#define uint unsigned int

using namespace std;

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

    bool found = 0;
    uint n;             // the nth prime to be determined
    uint prime_counter=0;
    uint this_num = 2;  // number to increment
    
    std::cout << "\nPlease enter the nth prime to be determined: ";
    std::cin >> n;
    std::cin.clear();
    
    do {
                     
        if (is_prime( &this_num )) {
            prime_counter++;

            if (prime_counter == n){
                found = 1;
            }
            else {
                this_num++;
            }
        }
        else{
            this_num++;
        }
        
    } while(!found);
    
    std::cout << "\nThe n = " << n << " prime is: \n";
    std::cout << this_num << "\n";
    
    return 0;
}