#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(int n);

const int limit = 2000000;
int main()
{
	int i;
	long long sum=2;
	for(i=3;i<limit;i+=2)
	{
		if(isPrime(i))
			sum+=i;
	}
	cout<<endl<<sum<<endl<<endl;
}

bool isPrime(int n)
{
	static vector<int> primes (1,2); //Static vector with 1 element: 2
	int i;
	for(i=0;primes[i]<=sqrt(n);i++)
	{
		if(n%primes[i]==0)
			return 0;
	}
	primes.push_back(n);
	return 1;
}