/* pythag_trip.cpp finds the special Pythagorean triple a^2 + b^2 = c^2 such
that a + b + c = 1000 */
// (C) GPL, Edmund Higham, Nov 2014

#include <iostream>
#include <stdexcept>
#include <cstdlib>

#define uint unsigned int

using namespace std;

bool special_needs(const uint m,const uint n,const uint num){

return ( m*(m + n) == num );
}


int main(void){

    uint num = 0;
    
    uint m = 0;
    uint n = 0;

    // Pythagorean Triple
    uint a = 0;
    uint b = 0;    
    uint c = 0;

    bool done = 0;
    bool overflow = 0;
    bool continue_flag = 1;
    
    do{
        // user specifies target number for special Pythagorean triple
        std::cout << "\nPlease enter target number: ";
        std::cin >> num;
        std::cin.clear();

        continue_flag = 1;
    
        // check if num is divisible by 2
        if (num % 2 != 0) {
            std::cout <<"\nERROR: input must be evenly divisible by two.\n";
            continue_flag = 0;
        }
    } while (!continue_flag);

    // By euclid formula, half target num is needed.
    num /= 2;
    std::cout << num;

    do{

        n++;
        m = n;

        if (n*n > num) {
            std::cout << "Did not converge on pythagorean triple \n";
            exit(0);
        }

        do {

            done = special_needs(++m,n,num);

        } while (!done && (m*m < num));

    } while (!done);
    

    a = m*m - n*n;
    b = b = 2*m*n;
    c = m*m + n*n;

    std::cout << std::endl
              << "The Pythagorean triple which sums to " << num*2 <<" is :\n"
              << " a = "  << a
              << ", b = " << b
              << ", c = " << c  << "."
              << "\nThe product abc = "
              <<  a*b*b << "\n";


return 0;
}


/*
struct triple {
    public:
        uint a;
        uint b;
        uint c;
};


bool special_end(const struct triple thisTriple){
    // test if the pythagorean triple sum to 1000

return (thisTriple.a + thisTriple.b + thisTriple.c == 1000);
}

bool special_overflow(const struct triple thisTriple){
    // test if the pythagorean triple sum to 1000

return (thisTriple.a + thisTriple.b + thisTriple.c > 999);
}

triple euclid(const uint m, const uint n, const uint k){
    // compute a pythagorean triple via euclid's formula

    triple result;

    // Check that m > n
    if (n > m){
        throw std::invalid_argument( "ERROR: m must be greater than n" );
    }
    else if (k <= 0) {
        throw std::invalid_argument( "received negative value or zero k" );
    }

    result.a = k*(m*m - n*n);
    result.b = 2*k*m*n;
    result.c = k*(m*m + n*n);

return result;
}


int main(void){

    triple myTriple = {0, 0, 0};
    
    uint m = 0;
    uint n = 0;
    uint k = 0;

    bool done = 0;
    bool overflow = 0;
    
    do{
    
        n++;
        m = n;

        if (n*n > 1000) {
            std::cout << "Did not converge on pythagorean triple \n";
            exit(0);
        }
        
        do{
        
            m++;
            k = 0;

            do {

                myTriple = euclid(m, n, ++k);

                overflow = special_overflow(myTriple);
                done = special_end(myTriple);

            } while(!overflow);
        
        } while(!done && (m*m < 1000));
    
    } while (!done);


    std::cout << std::endl
              << "The Pythagorean triple which sums to 1000 is :\n"
              << " a = " << myTriple.a
              << ", b = " << myTriple.b
              << ", c = " << myTriple.c << ".\n"
              << "The product abc = "
              <<  myTriple.a*myTriple.b*myTriple.c << "\n";
    
return 0;
}
*/