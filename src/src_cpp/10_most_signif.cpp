/* 10_most_signif.cpp computes the 10 largest digits of the sum of 100
50 digit numbers */
// (C) GPL, Edmund Higham, 2014

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>

#define uint unsigned int
#define ulong unsigned long int

using namespace std;

ulong * import_most_signif(){

	uint i = 0;
	ulong * myArray = new ulong[100]();
	std::string line;
	std::string token;
	
	ifstream myfile ("dat/100digits.dat");
	
	if (myfile.is_open()){

		while ( getline(myfile,line) ){

			token = line.substr(0,10);
			myArray[i++] = std::atol(token.c_str());

		}

		myfile.close();
	}
	else std::cout << "unable to open file" << std::endl;
	
	return myArray;
}

int main(void){

	ulong * rows = import_most_signif();
	ulong acc = 0;

	for (int i = 0; i < 100; ++i){
		acc += rows[i];
	}

	std::cout << acc << std::endl;

	delete[] rows;

	return 0;
}