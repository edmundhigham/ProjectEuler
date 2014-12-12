/* palindrome.cpp computes the largest palindromic number made by the
product of two 3-digit base-10 numbers */
// (C) GPL, Edmund Higham, Nov 2014

#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>

#define uint unsigned int

using namespace std;

bool is_palindrome(const uint num){

	bool result = 1;
	std::string x = to_string(num);
	int i = 0;

	for (i = 0; i < (x.length())/2; ++i){

		if ( x[i] != x[x.length()-1-i] ) {
			result = 0;
			break;
		}

	}

	return result;
};


int main(void){

	uint max_palindrome = 0;

	for (uint i = 100; i < 999; ++i){
		for (uint j = 100; j < 999; ++j){

			if ( is_palindrome(i*j) ){

				if ( i*j > max_palindrome) max_palindrome = i*j;

			}
		}
	}

	std::cout << "the largest palindrome is " << max_palindrome <<std::endl;


	return 0;
}