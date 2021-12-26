#include <iostream>
#include <fstream>
#include "CSlice.h"

void outputVector(const std::vector<int>& vect) {
    std::cout << "[ ";
    for (int a : vect) {
        std::cout << a << " ";
    }
    std::cout << "]" << std::endl;
}

int main()
{
    // creating vector
    std::ifstream fin("input.txt");
    std::vector<int> source;
    int a;
    while (!fin.eof()) {
        fin >> a;
        source.emplace_back(a);
    }
    outputVector(source);
    CSlice s(source);

    // invitation to play
    std::cout << "print command like s[expression]" << std::endl;
    // result container
    std::vector<int> result;
    // slice command
    std::string command;
    
    while (true) {
        std::cin >> command;
        try {
            result = s.slice(command);
            outputVector(result);
        }
        catch (std::exception e) {
            std::cout << e.what() << std::endl;
        }
    }
}

