#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stdio.h>
#include <string>
#include <Windows.h>
using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
SetConsoleOutputCP(1251);
int N=10000;
string s1, s,s2;
int i,k=0,g=0, count=0, num;
char z[1000], A[10000], B[10000], w;


cout<<"Введите слово и в конце поставьте точку";
cout<<'\n';
do { 
	cin>>z[k];
	k++;
}
while (z[k-1]!='.');

for(i=0; i<k-1; i++)
{ A[i]='-';
cout<<'-';}
cout<<'\n';

do {
	
	cin>>w;

for(i=0; i<k-1; i++)
{ 
	if (z[i]==w)
	{	A[i]=w;
		cout<<A[i];
	count++;
	
	}
	else
	{	cout<<A[i];}

	
}

for(i=0; i<k-1; i++)
{
	if(A[i]==z[i])
	{count++;}}


cout<<'\n';
num=count;
count =0;

}
while(num!=k);

cout<<"Вы победили!";
cout<<'\n';

system("pause");
return 0;
}