#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int limit=10001;

int main()
{
	vector<int> a;
	int i,j;
	bool flag;

	a.push_back(2);
	cout<<2<<endl;
	for(i=3;a.size()<limit;i+=2)
	{
		flag=1;
		for(j=1;a[j]<=sqrt(i);j++)
			if(i%a[j]==0)
				flag=0;
		if(flag)
			{
				cout<<i<<endl;
				a.push_back(i);
			}
	}
	return 0;
}