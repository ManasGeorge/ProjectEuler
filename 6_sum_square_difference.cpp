#include <iostream>
using namespace std;

const int limit=100;
int main()
{
	int i,j;
	long long sum = 0;
	for(i=1;i<=limit;i++)
	{
		for(j=1;j<i;j++)
			sum+=i*j;
		for(j=i+1;j<=limit;j++)
			sum+=i*j;
	}
	cout<<sum<<endl;
	return 0;
}
