// Project Euler Question 35
/* circular_primes.cpp does stuff */
// Copyright (C) GPL, R. Evans, E. Higham

/* THE QUESTION


The number, 197, is called a circular prime because all rotations of the
digits: 197, 971, and 719, are themselves prime.

There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71,
73, 79, and 97.

How many circular primes are there below one million? */


/* Psuedocode for the lolcatz

Generate our list of primes up to 1M
For each prime:
    for each rotation
        if prime:
            continue
        else
            break
    if no break:
        count++ */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <math.h>

using namespace std;


int rotateLeft(const int thingToBeRotated){;
    
    stringstream ss;
    ss << thingToBeRotated;
    string rotateMyShaft {ss.str()};
    rotate(rotateMyShaft.begin(), rotateMyShaft.begin() + 1, rotateMyShaft.end());
    
    istringstream buffer(rotateMyShaft);
    int rotatedValue;
    buffer >> rotatedValue;

    return rotatedValue;
}

void mamaDoTheSieve(const int limit, unordered_set<int>& superSpeedySet){
    vector<bool>is_prime(limit, true);
    const int sqrt_limit = static_cast<int>(sqrt(limit));
    for (int n = 2; n <= sqrt_limit; ++n){
        if (is_prime[n]) {
            superSpeedySet.insert(n);
            for (unsigned k = n*n, ulim = static_cast<unsigned>(limit); k < ulim; k += n) 
              //NOTE: "unsigned" is used to avoid an overflow in `k+=n` for `limit` near INT_MAX
        	  is_prime[k] = false;
        }
    }
    
    for (int n = sqrt_limit + 1; n < limit; ++n){
        if (is_prime[n]){
            superSpeedySet.insert(n);
        }
    }
}

bool itsPrime(const int rValue, const unordered_set<int>& primeSet){
    auto iter = primeSet.find(rValue);
    return (iter != primeSet.end());
}

unsigned GetNumberOfDigits (unsigned i)
{
    return i > 0 ? (int) log10 ((double) i) + 1 : 1;
}

int countCircularPrimes(const unordered_set<int> ourPrimesSet){
    
    int counter{0};
    int currentValue, rotatedValue, timesRotated, numDigits;
    bool lookingGood;
    
    for(auto iter = ourPrimesSet.begin(); iter != ourPrimesSet.end(); ++iter){
        currentValue = *iter;
        rotatedValue = currentValue;
        timesRotated = 0;
        numDigits = GetNumberOfDigits(currentValue);
        lookingGood = true;
        while (rotatedValue != currentValue || timesRotated == 0){
            rotatedValue = rotateLeft(rotatedValue);
            timesRotated++;
            if(!itsPrime(rotatedValue, ourPrimesSet) || numDigits != GetNumberOfDigits(rotatedValue)){
                lookingGood = false;
                break;
            }
        }
        if(lookingGood) counter++;
    }
    return counter;
}

int main(int argc, char *argv[]){
    unordered_set<int> mappedPrimesSet;
    
    mamaDoTheSieve(1000000, mappedPrimesSet);
    cout << "There are " << countCircularPrimes(mappedPrimesSet) << " Potatoes in the universe\n";
}