#include <iostream>

#include <cstdlib>
#include <stdio.h>
#include <string>
using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
long double N=1, i,N1;
int m,c=1, p;
float n=-1,k;
string s, s1;
cin>>s;

k=stof(s);


while( n!=stof(s))
{

try {
        
        n = stof(s);
        
    }
    catch(std::invalid_argument e) {
		cout << "¬ведите число\n";
	cin>>s1;
	s=s1;
	}
	
} 

m=n*10;
do {
if(n>100000)
{
cout<<"¬ведите число меньше 100000";
cout<<'\n';
cin>>N1;
n=N1;
m=n*10;
cout<<'\n';
}



if(n<=0)
{ cout<<"¬ведите число больше 0";
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
while(n<0 || n>100000 || (m%10)!=0 );

cout<<'\n';





for( i=1; i<=n; i++)
{ N=N*i;
}
cout<<N<<'\n';




system("pause");
return 0;
}