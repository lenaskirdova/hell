#include <iostream>
#include <cstdlib>
#include <Windows.h>
using namespace std;

int main()
{ 
SetConsoleCP(1251);
SetConsoleOutputCP(1251);
int a=0, s,m,t,n,i,N=1000;
int b=100;
setlocale(LC_ALL, "Russian");

cin>>m;

for(i=0; i<10;i++)
{ s=(a+b)/2;

if (m>s)
{a=s;
cout<<"N больше "<<s<<" (1 да, 2 нет, 3 равно)?"<<'\n';
cin>>t;}

if (m<s){
cout<<"N больше "<<s<<" (1 да, 2 нет, 3 равно)?"<<'\n';
b=s;
cin>>t;
}

if (m==s)
{cout<<"N больше "<<s<<" (1 да, 2 нет, 3 равно)?"<<'\n';
cin>>t;
cout<<m<<'\n';
break;
}}

system("pause");
return 0;
}
