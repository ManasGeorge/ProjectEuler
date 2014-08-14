#include <iostream>
#include <map>
#include <iomanip>
using namespace std;

int factor_sum(int n);
int main()
{
	int i,sum=0;
	for(i=1;i<10000;i++)
		if(i == factor_sum(factor_sum(i)) && i!=factor_sum(i))
			sum+=i;
			// cout<<setw(5)<<i<<" "<<factor_sum(i)<<endl;
	cout<<sum;
}

int factor_sum(int n)
{
	static map<int,int> fs;
	int i,sum=0;
	if(fs.find(n) == fs.end())
	{
		for(i=1;i<n;i++)
			if(n%i==0)
				sum+=i;
		fs[n] = sum;
	}
	return fs[n];
}