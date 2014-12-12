/* grid_prod.cpp computes the largest product of 4 numbers in a 20x20 grid.
The numbers can be adjacent left, right, up, down or diagonal. */
// (C) GPL, Edmund Higham, Nov 2014

#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>


#define uint unsigned int
#define ulong unsigned long

#define NDIMS 2 // Project Euler gives 2D array
#define DIM 20  // The array is 20 x 20

using namespace std;

int block = 4; // default block size

uint* allocate(const int elems){
    return new uint[elems]();
};


uint* initialise(uint *matrix, const int elems){

    int i = 0;

    std::string line;
    const std::string delimiter = " ";
    size_t pos = 0;
    std::string token;

    ifstream myfile ("dat/20by20.dat");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) ){
            while ((pos = line.find(delimiter)) != std::string::npos) {
                token = line.substr(0, pos);
                matrix[i++] = atoi(token.c_str());
                line.erase(0, pos + delimiter.length());
            }
            matrix[i++] = atoi(line.c_str());
        }

        myfile.close();
    }
    else cout << "Unable to open file"; 

    return matrix;
};


ulong right_mult(uint *matrix){
    extern int block;
    ulong max_prod = 1;
    ulong this_prod = 1;

    for (int j = 0; j < block; ++j){
        for (int i = 0; i < block; ++i){
            this_prod *= matrix[j*DIM + i];
        }
            
        if (this_prod > max_prod) max_prod = this_prod;
        this_prod = 1;
    }

    return max_prod;
};

ulong down_mult(uint *matrix){
    extern int block;
    ulong max_prod = 1;
    ulong this_prod = 1;

    for (int j = 0; j < block; ++j){
        for (int i = 0; i < block; ++i){

            this_prod *= matrix[i*DIM + j];
        }

        if (this_prod > max_prod) max_prod = this_prod;
        this_prod = 1;
    }

    return max_prod;
};

ulong downright_mult(uint *matrix){
    extern int block;
    ulong this_prod = 1;

    for (int i = 0; i < block*DIM; i += DIM+1){

        this_prod *= matrix[i];
    }

    return this_prod;
};

ulong downleft_mult(uint *matrix){
    extern int block;
    ulong this_prod = 1;

    for (int i = block; i < block*DIM; i += DIM-1){

        this_prod *= matrix[i];
    }

    return this_prod;
};

int main(void){

    int elems = pow(DIM,NDIMS); // total number of elements
    extern int block; // number of elements to multiply together
    ulong max_prod = 1;
    std::string input;

    uint * mat = initialise(allocate( elems ), elems);

    std::cout << "\nPlease enter the block size [default=4]: ";
    std::getline( std::cin, input );

    if ( !input.empty() ){
        std::istringstream stream( input );
        stream >> block;
    }
    
    for (int i = 0; i <= DIM-block; ++i) {
        for (int j = 0; j <= DIM-block; ++j){
        
            max_prod = max(max_prod,     right_mult(&mat[i*DIM + j]));
            max_prod = max(max_prod,      down_mult(&mat[i*DIM + j]));
            max_prod = max(max_prod,  downleft_mult(&mat[i*DIM + j]));
            max_prod = max(max_prod, downright_mult(&mat[i*DIM + j]));
        }
    }

    std::cout << "The maximum product of " << block \
              << " is " << max_prod << std::endl;

    delete[] mat; // free heap allocation

    return 0;
}