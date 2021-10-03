#include <iostream>
#include <cstdlib>
#include <Windows.h>
using namespace std;

int main()
{
SetConsoleCP(1251);
SetConsoleOutputCP(1251);
char s[1000];
setlocale(LC_ALL, "Russian");
cin>>s;
cout<<"Привет,";
cout<<" "<<s<<"!"<<'\n';

system("pause");
return 0;
}




