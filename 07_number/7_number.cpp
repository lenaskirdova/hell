#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{ int a=0, s,m,t,n,i,N=1000;
int b=100;
setlocale(LC_ALL, "Russian");

cin>>m;

for(i=0; i<10;i++)
{ s=(a+b)/2;

if (m>s)
{a=s;
cout<<"N ������ "<<s<<" (1 ��, 2 ���, 3 �����)?"<<'\n';
cin>>t;}

if (m<s){
cout<<"N ������ "<<s<<" (1 ��, 2 ���, 3 �����)?"<<'\n';
b=s;
cin>>t;
}

if (m==s)
{cout<<"N ������ "<<s<<" (1 ��, 2 ���, 3 �����)?"<<'\n';
cin>>t;
cout<<m<<'\n';
break;
}}

system("pause");
return 0;
}