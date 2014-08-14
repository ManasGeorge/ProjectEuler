#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long long bignum = 5145170006325963168;
	long long i,biggest_factor;

	while(bignum%2==0) //Divide out all factors of two first, halving the search space for the following loop
		bignum/=2;
	for(i=3;bignum>1;i+=2)
		while(bignum%i==0) //Divide out all multiples of i in bignum
			cout<<i; bignum/=i; 
	cout<<i<<endl;
	return 0;
}
