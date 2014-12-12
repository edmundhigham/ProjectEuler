/* even_divisible.cpp finds the smallest number that is evenly divisible by
the integers 1 to n, where n is a positive integer. */
// (C) Edmund Higham, Nov 2014

#include <iostream>
#include <time.h>
#include <ctime>

#define ulong unsigned long

int main(void){
    
    ulong num; // Number to find
    int max_factor; // Largest integer factor of num
   
    bool complete = 0;

    time_t start,finish;

    std::cout << "\nlargest factor plz \n";
    std::cin >> max_factor;
    std::cin.clear();
   
    num = max_factor; // rubbish first guess

    start = clock();
    do {
   
        for (int i = max_factor; i > 1; --i){

            if( num % i == 0) {
            
                complete = (i==2);
            }
            else {
            
                num += max_factor; //can increment by max_factor
                break;
            }
        }
   
    } while(!complete);
    
    finish = clock();
    
    
    std::cout << "\nThe smallest number evenly divisible by all of the";
    std::cout << "\nintegers between 1 and " << max_factor << " is: ";
    std::cout << "\n \n" << num << std::endl;
    std::cout << double(finish - start)/double(CLOCKS_PER_SEC) << "\n";

    return 0;
}