#include <iostream>
#include <ctime>

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

void getInt(const std::string& prompt, int& a)
{
    for (;;) {
        std::cout << prompt;
        if ((std::cin >> a).good() && (a <= 100) && (a >= 1)) return;
        if (std::cin.fail()) {
            std::cin.clear();
        }
        std::cin.ignore(100, '\n');
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
    getInt("enter size of the array: ", size);
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
    return 0;
}
