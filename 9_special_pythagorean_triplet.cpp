#include <iostream>
#include <iomanip>
using namespace std;

const int sum=1000;
const int limit=500;
const int digits=4;
int main()
{
	original();
	optimized();	
}

void original()
{
	int i,j,k,count=0;
	for (i=1; i<=limit; i++)
		for (j=i; j<=limit; j++)
			{
				if (i*i+j*j==(sum-i-j)*(sum-i-j));
				{
					count++;
					cout<<left;
					cout<<setw(digits)<<count
						<<setw(digits)<<i
						<<setw(digits)<<j
						<<setw(digits)<<k
						<<setw(digits)<<i*j*k<<endl;
				}
			}
	return 0;
}

void optimized()
{
	int i,j,count=0;
	for (i=3; i<=(sum-3)/3; i++) //i<j<(sum-i-j). The least value of sum is when the numbers are consecutive: a,a+1,a+2; Hence sum>=3a+3
		for (j=i+1; j<(sum-i)/2; j++) //i<j<(sum-i-j) => j<sum-i-j => 2j<sum-i => j<(sum-i)/2
			{
				if (i*i+j*j==(sum-i-j)*(sum-i-j))
				{
					count++;
					cout<<right;
					cout<<count
						<<setw(digits)<<i
						<<setw(digits)<<j<<endl;
				}
			}
	return 0;
}

void even_better()
{
	
}