#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
using namespace std;

typedef vector<int> vi;
typedef vector<int>::iterator vii;
typedef set<int> si;
typedef set<int>::iterator sii;

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

int main()
{
	si abundant;
	si abundant_sums;
	sii it1,it2,beg,end;
	int i;
	double sum = 0;
	for(i=1;i<28123;i++)
		if(factor_sum(i) > i)
			abundant.insert(i);

	beg = abundant.begin();
	end = abundant.end();
	for(it1 = beg; it1!= end; it1++)
	{
		cout<<*it1<<" ";
		for(it2 = it1; it2!= end; it2++)
			abundant_sums.insert(*it1 + *it2);
	}

	end = abundant_sums.end();
	for(i=1;i<28123;i++)
		if(abundant_sums.find(i) == end)
			sum += i, cout<<i<<" ";
	cout<<setprecision(16);
	cout<<endl<<sum<<endl;
}