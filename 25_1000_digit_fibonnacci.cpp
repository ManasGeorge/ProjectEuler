#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef vector<int>  vi;
vi operator+(const vi& lhs, const vi& rhs);
vi& operator++(vi& v);
ostream& operator<<(ostream& os, const vi& rhs);

int main()
{
	vi a(1,1);
	vi b(1,1);
	vi c=a+b;
	int i=3;
	
	while(c.size()!=1000)
	{	
		c = a+b;
		a = b;
		b = c;
		i++;
	}
	cout<<i<<endl;
}

vi& operator++(vi& v)
{
	int carry = 1,n=v.size();
	for(int i=0;carry && i<n;i++)
	{
		v[i]+=carry;
		if(v[i] == 10)
		{
			v[i] = 0;
			carry = 1;
		}
		else carry = 0;
	}
	if(carry)
		v.push_back(1);
	return v;
}

ostream& operator<<(ostream& os, const vi& rhs)
{
	int i,n=rhs.size();
	for(i=n-1;i>=0;i--)
		os<<rhs[i];
	return os;
}

vi operator+(const vi& lhs, const vi& rhs)
{
	vi c(0,1);
	int carry=0;
	int result;
	vi::const_iterator i=lhs.begin(),j=rhs.begin();
	while(i<lhs.end() && j<rhs.end())
	{
		result = carry;
		result += *(i++) + *(j++);
		if(result>9)
		{
			carry = 1;
			result = result%10;
		}
		else
			carry = 0;
		c.push_back(result);
	}
	while(i<lhs.end())
	{
		result = carry;
		result += *(i++);
		if(result>9)
		{
			carry = 1;
			result = result%10;
		}
		else
			carry = 0;
		c.push_back(result);
	}
	while(j<rhs.end())
	{
		result = carry;
		result += *(j++);
		if(result>9)
		{
			carry = 1;
			result = result%10;
		}
		else
			carry = 0;
		c.push_back(result);
	}
	if(carry)
		c.push_back(carry);
	return c;
}
