#include "FIFO.h"
#include "LIFO.h"
#include "Interface.h"
#include <iostream>

using namespace std;

int main() {
	cout << "fifo or lifo? 0 for fifo, 1 for lifo ";
	bool choice;
	cin >> choice;
    Interface* fl;
    if (choice) {
        fl = new LIFO(5);
    }
    else {
        fl = new FIFO(5);
    }
    bool isRun = true;
    while (isRun) {
        cout << "1. show" << endl;
        cout << "2. push" << endl;
        cout << "3. pop" << endl;
        cout << "4. exit" << endl;
        cout << "> ";
        char c;
        cin >> c;
        switch (c) {
        case '1':
            if (choice) {
                cout << *(LIFO*)fl << endl;
            }
            else {
                cout << *(FIFO*)fl << endl;
            }
            break;
        case '2':
            int arg;
            cout << "enter value: ";
            cin >> arg;
            fl->push(arg);
            break;
        case '3':
            cout << fl->pop() << endl;
            break;
        case '4':
            isRun = false;
            break;
        default:
            cout << "incorrect option" << endl;
            break;
        }
    }
}