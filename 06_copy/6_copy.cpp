#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string>
using namespace std;

int main()

{
	
string s, A[10000];
int i,k=0;
getline(cin, s);


for(i=0; i<s.size(); i++)
{A[i]=s[i]; }

for(i=0; i<s.size(); i++)

{cout<<A[i];}
cout<<'\n';
system("pause");
return 0;
}