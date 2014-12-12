/* path_sum.cpp finds the maximum path by starting at the top of a triangle
imported from text and moving to adjacent numbers on the row below. */
// (C) GPL, Edmund Higham, Nov 2014

#include <iosteam>
#include <fstream>
#include <string>
#include <sstream>

#define uint unsigned int

using namespace std;

uint * get_triangle(const std::string triangle_file , uint * n_rows){







	return triangle;
}










int main(void){

	std::string triangle_file = "dat/triangle15.dat";
	std::string input;

	// Check if user specifies a particular triangle to solve
	std::cout << "Please specify path/to/triangle.dat" \
				 "[default=triangle15.dat] :";

	getline( std::cin , input );
	if ( !input.empty() ){
		std::istringstream stream( input );
		stream >> triangle_file;
	}

	return 0;
}