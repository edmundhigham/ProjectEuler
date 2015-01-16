// Project Euler Question 24
/* lexiPermute.cpp finds the millionth lexicographical permutation of the
integers 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9. /*
// Copyright (C) GPL 2015, R. Evans, E. Higham

/* THE QUESTION:

A permutation is an ordered arrangement of objects. For example, 3124 is one
possible permutation of the digits 1, 2, 3 and 4. If all of the permutations
are listed numerically or alphabetically, we call it lexicographic order. The
lexicographic permutations of 0, 1 and 2 are:

                012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits
0, 1, 2, 3, 4, 5, 6, 7, 8 and 9? 

*/

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

typedef unsigned int uint;

#define PERMUTE_NUM 1

using namespace std;

bool permute(vector<int>* list){
    
    /* Psuedocode for funzies
    
    method 1 - from wiki :)
    
    -> Find the largest index k such that a[k] < a[k + 1]. If no such index
    exists, the permutation is the last permutation.
    
    k = list.size() - 1
    while ( list[k] > list[k+1] )
        --k
        if (k < 0)
            error - No more permutations exist
    
    -> Find the largest index l greater than k such that a[k] < a[l].
    
    l = list.size()
    while( list[k] > list[l] )
        --l
        if (l < 0)
            error??
    
    -> Swap the value of a[k] with that of a[l].
    
    buff = list[k]
    list[k] = list[l]
    list[l] = buff
    
    -> Reverse the sequence from a[k + 1] up to and including the final
    element a[n].
    
    Reverse sort algorithm... (see book LULZ) probably quick sort as
    the vector is only 10 elems long...
    
    */
    
    int k {0};
    int l {0};
    vector<int> buff{0};
    
    k = list->size()-2;
    while ( list[k] > list[k+1] ){
        --k;
        if ( k < 0 ) return 0;
    };

    l = list->size()-1;
    while( list[k] > list[l] ){
        --l;
    };
    
    buff = list[k];
    list[k] = list[l];
    list[l] = buff;
    
    return 1;
};

int main(int argc, char* argv[]){
    
    vector<int> numsAvailable{0,1,2,3,4,5,6,7,8,9};
    
    uint i {0};
    
    while (permute(&numsAvailable) && (i < PERMUTE_NUM)) {
        ++i;
    }
    
    if (i < PERMUTE_NUM ){
        cout << "The PERMUTE_NUM permutation was not found." << endl;
    }
    else{
        cout << "The PERMUTE_NUM permutation is: ";
        for_each(numsAvailable.begin(), numsAvailable.end(), [](vector<int>::value_type val) { cout << val << " "; });
        cout << endl;
    }
    
    return 0;   
}