#include <iostream>

#include <cstdlib>
#include <stdio.h>
#include <string>
using namespace std;


int main()


{    
	setlocale(LC_ALL, "Russian");

long double  N1;
int m,c=1, p,N,i,f1,f0,f;
float n=-1,k;
string s, s1;
cin>>s;

k=stof(s);


while( n!=stof(s))
{

try {

n = stof(s);

}
catch(invalid_argument e) {
cout<<"¬ведите число\n";
cin>>s1;
s=s1;
}

}

m=n*10;
do {

	

if(n>100)
{
cout<<"¬ведите число меньше 100";
cout<<'\n';
cin>>N1;
n=N1;
m=n*10;
cout<<'\n';
}



if(n<1)
{ cout<<"¬ведите число больше 1";
cout<<'\n';
cin>>N1;
n=N1;
m=n*10;
}

if((m%10)!=0)
{
cout<<"¬ведите целое число";
cout<<'\n';
cin>>N1;
n=N1;
m=n*10;
}

}
while(n<0 || n>10 || (m%10)!=0 );

cout<<'\n';

if(n==1)
{	cout<<' 1 ';
	cout<<'\n';
}

f0=0;
	f1=1;
	cout<<"1"<<" ";
for(i=2; i<=n; i++)
{
	
	f=f1+f0;
	cout<<f<<" ";
	f0=f1;
	f1=f;
	}

cout<<'\n';

system("pause");
    return 0;
}


