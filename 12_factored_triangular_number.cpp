#include <iostream>
#include <cmath>
using namespace std;

int count_factors(long num);

int main()
{
	int n;
	for(n=1;count_factors(n*(n+1)/2)<500;n++);
	cout<<n*(n+1)/2<<endl;
	// while(cin>>n)
		// cout<<count_factors(n)<<endl;
}

int count_factors(long num)
{
	int factors,n,i,p;
	factors=1;
	for(i=2;num>1;i++)
	{
		p=1;
		while(num%i==0)
		{
			num/=i;
			p++;
		}
		factors*=p;
	}
	return factors;
}