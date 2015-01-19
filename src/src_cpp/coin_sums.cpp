// Project Euler Problem 31
/* coin_sums.cpp calculates the total number of combinations of coins
circulated by the Bank of England that sum to a specified amount */
// Copyright (C) 2015 GPL, R. Evans, E. Higham

/* THE QUESTION!!!!

In England the currency is made up of pound, £, and pence, p, and there are
eight coins in general circulation:

    1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).

It is possible to make £2 in the following way:

    1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p

How many different ways can £2 be made using any number of coins?

*/

#include <iostream>
#include <algorithm>
#include <vector>

// #define uint unsigned int <-- WRONG
typedef unsigned int uint; // <-- RIGHT
//using uint = unsigned int; // <-- ALSO OK with C++11 onwards

using namespace std;

#define TARGET 200

//what we know
//Coins available: 1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).

/* psuedocode for funzies

    -----
    Mischievous Mouse way of doing it:
    
    numWaysOfDoingIt (coins, totalToMake){
        numWays = 0
        for each coin in coins:
            if totalToMake - coin == 0 : numways++
            elseif coin > totalToMake : next coin
            else 
                numways = 1 + numWaysOfDoingIt(coins, totalToMake - coin)
    }

    -----
    Sneaky Butterly
    
    how many ways to make 1p?
    how many ways to make 2p?
    how many ways to make 5p?
    .
    .
    .
    how many ways to make £1?
        
    
    */
/* //Top-Down Method - Recursive Algorithm
 int numWaysOfDoingIt(vector<int> coins, int totalToMake, int start)
 {
     int total {0};
    
     if (totalToMake <= 0){
         return 0;
     }
    
    for (int i = start; i < coins.size(); ++i)

        if (totalToMake - coins[i] == 0)
        {
            total++;
        }
        else if (totalToMake - coins[i] > 0)
        {
            total += numWaysOfDoingIt(coins, totalToMake - coins[i], i);
        }
    }
    
    return total;
    
};
*/

// Bottom-Up 
int numWaysOfDoingItDP(vector<int> coins, int totalToMake)
{
    uint OurComputedValues[totalToMake + 1][coins.size()];
    int i, j;
    
    for (i = 0; i <=  totalToMake; ++i){
        for (j = 0; j < coins.size(); ++j){
            OurComputedValues[i][j] = 1;
        }
    }
    
    // lets find the answer
        for (i = 1; i <= totalToMake; ++i){
                for (j = 1; j < coins.size(); ++j){

            // so here we're trying to ith coin in the array to make total j
            //      1   2   3   4   5   6   7   8   9   ...
            // 1p   1   1   1   1   1   1   1   1   1   ...
            // 2p   1   2   2   
            // 5p
            // ...
            
            //This value is greater than the coin value
            if(i - coins[j] >= 0)
                OurComputedValues[i][j] = OurComputedValues[i][j - 1] + OurComputedValues[i - coins[j]][j];
            else
                OurComputedValues[i][j] = OurComputedValues[i][j-1];
        }
    }
    return OurComputedValues[totalToMake][coins.size()-1];
};

int main(int argc, char* argv[])
{
    
      vector<int> coinsAvailable{1, 2, 5, 10, 20, 50, 100, 200};
    //vector<int> coinsAvailable{200, 100, 50, 20, 10, 5, 2, 1};

    
    cout << "Greetings Earthlings! I am Dave and I like nothing more "\
            "than to count coins!\n" << endl;
    
    cout << "The total number of combinations of coins that makes up £2 is: "\
         << numWaysOfDoingItDP(coinsAvailable, TARGET) << endl;
    
    return 0;
}

