#include <iostream>
#include <numeric>
#include <iomanip>
#include <vector>

using namespace std;

long long lcm(long long n, long long m);
int main()
{
	long long i;
	vector<long long> a;
	for(i=1;i<=20;i++)
		a.push_back(i);
	accumulate(a.begin(),a.end(),1,lcm)<<endl;
	return 0;
}

long long lcm(long long n, long long m)
{
	long long r;
	long long mcopy = m;
	long long ncopy = n;
	while(n!=0)
	{
		r=m%n;
		m=n;
		n=r;
	}
	cout<<mcopy<<setw(10)<<mcopy/m*ncopy<<endl; //Careful with order. mcopy*ncopy/m != mcopy/m*ncopy
	return ncopy*mcopy/m;
}