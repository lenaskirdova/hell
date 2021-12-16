#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>



void swapTemp(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void swapSum(int& a, int& b) {
    a = a + b;
    b = a - b; // b == a
    a = a - b; // a == b
}

void swapXor(int& a, int& b) {
    a ^= b;
    b ^= a;
    a ^= b;
}

void sort(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[i]) {
                std::swap(arr[j], arr[i]);
            }
        }
    }
}

bool isNum(char c ) {
if (c >=48 && c <=57) return true;
return false;
} 

void getInt(int& a)
{
    for (;;) {
        std::string syroy;
		std::cin>>syroy;
		
		for(int i=0;i<syroy.size();i++)
		{
			if(!isNum(syroy[i])) 
				break;
			if(i==syroy.size()-1)
			{ 
				a=atoi(syroy.c_str());
				
				if(a<=100 && a>=1)
				return;
			}

			
		}


       
    }
}

int main()
{
    srand(time(nullptr));
    int a = 5, b = 6;
    std::cout << "start: " << a << " " << b << std::endl;
    std::cout << "swapTemp: ";
    swapTemp(a, b);
    std::cout << a << " " << b << std::endl;
    std::cout << "swapSum: ";
    swapSum(a, b);
    std::cout << a << " " << b << std::endl;
    std::cout << "swapXor: ";
    swapXor(a, b);
    std::cout << a << " " << b << std::endl;

    int size;
    getInt(size);
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100 - 50;
    }

    std::cout << "generated array: [";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "]" << std::endl;

    sort(arr, size);

    std::cout << "sorted array: [";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "]" << std::endl;  
    delete[] arr;

	system ("pause");
    return 0;

	
}
