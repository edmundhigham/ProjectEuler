
#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include <fstream>
#include <stdio.h>

using namespace std;


int main(void){
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
                std::cout << token << std::endl;
                line.erase(0, pos + delimiter.length());
            }
            std::cout << line << std::endl;

        }

        myfile.close();
    }
    else cout << "Unable to open file"; 

    return 0;
}