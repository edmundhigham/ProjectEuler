/* sum_square_diff.cpp computes the difference between the sum of the squares
and the square of the sum of the first N natural numbers, where N is an
integer multiple of 10 */
// (C) Edmund Higham, Nov 2014

#include <iostream>

#define uint unsigned int

uint square_diff(const int *lower,const int *upper){
uint sum_squares = 0;
uint square_sum = 0;

for (int i = *lower; i <= *upper; ++i){

	square_sum += i;
	sum_squares += i*i;
}

return square_sum*square_sum-sum_squares;
}


int main(void){

int lLim, uLim; // Lower and upper limits to be used

std::cout << "\nPlease enter the upper limit: ";
std::cin >> uLim;
std::cin.clear();

std::cout << "\nPlease enter the lower limit: ";
std::cin >> lLim;
std::cin.clear();


std::cout << "\nThe difference between the square of the sum and the";
std::cout << "\nsum of the squares is:\n";

std::cout << square_diff(&lLim,&uLim) << "\n";

return 0;
}