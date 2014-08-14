#include <iostream>
#include <cmath>
#include <iomanip>
const int width = 170;
const int numw  = 10;
const int limit = 4000000;
using namespace std;

long long naive();
long long better(); //Every third fibonacci number is even
long long even_better(); //Feven(N) = 4Feven(n-1)+Feven(n-2)

int main()
{
	cout<<setw(5)<<naive()<<endl;
	cout<<setw(5)<<better()<<endl;
	cout<<setw(5)<<even_better()<<endl;

}

long long naive()
{
	long long a,b,c,sum,i;
	a = b = 1;
	i = sum = 0;
	c = 2;
	while(c<limit)
	{
		i++;
		sum += (c%2==0)?(c):(0);
		a = b;
		b = c;
		c = b+a;
	}
	return sum;
}

long long better() //Every third fibonacci number is even
{
	long long a,b,c,sum=0;
	a = b = 1;
	c = 2;
	while(c<limit)
	{
		sum+=c;
		a = b+c;
		b = a+c;
		c = a+b;
	}
	return sum;
}

long long even_better() //Feven(N) = 4Feven(n-1)+Feven(n-2)
{
	long long a,b,c,sum=0;
	a=0;
	b=2;
	c=4*b+a;
	while(c<limit)
	{
		sum+=c;
		a=b;
		b=c;
		c=4*b+a;
	}
	return sum;
}