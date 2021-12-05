#include <iostream>
#include "FIFO.h"

int main()
{
    FIFO f = FIFO(5);
    bool run = true;
    while (run) {
        std::cout << "1. show" << std::endl;
        std::cout << "2. push" << std::endl;
        std::cout << "3. pop" << std::endl;
        std::cout << "4. exit" << std::endl;
        std::cout << "> ";
        char c;
        std::cin >> c;
        switch (c) {
        case '1':
            std::cout << f << std::endl;
            break;
        case '2':
            int arg;
            std::cout << "enter value: ";
            std::cin >> arg;
            f.push(arg);
            break;
        case '3':
            std::cout << f.pop() << std::endl;
            break;
        case '4':
            run = false;
            break;
        default:
            std::cout << "incorrect option" << std::endl;
            break;
        }
    }
}
