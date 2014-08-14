#include <iostream>
#include <cmath>
using namespace std;

double c_count(double i);

int main()
{
	double i,max[2],c;
	max[0]=max[1]=0;
	for(i=1;i<100000;i+=2)
	{
		c = c_count(i);
		if(c>max[0])
		{
			max[0] = c;
			max[1] = i;
			cout<<i<<" "<<c<<endl;
		}
	}
	cout<<i<<endl;
}

double c_count(double i)
{
	double p=1;
	while(i!=1)
	{
		// cout<<i<<" ";
		if(fmod(i,2)==0)
			i/=2;
		else
			i=3*i+1;
		p++;
	}
	// cout<<endl;
	return p;
}