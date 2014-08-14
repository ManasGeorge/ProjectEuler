#include <iostream>
#include <vector>

using namespace std;

typedef vector<int>  vi;
vi operator*(const vi& lhs, const vi& rhs);
vi& operator++(vi& v);
ostream& operator<<(ostream& os, const vi& rhs);

int main()
{
	vi a(1,1);
	vi i(1,1);
	int j,n;
	double sum=0;
	for(j=0;j<100;++j,++i)
		a = a*i;
	n = a.size();
	for(j=0;j<n;j++)
		sum += a[j];
	cout<<sum<<endl;
	cout<<a<<endl;
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

vi operator*(const vi& lhs, const vi& rhs)
{
	int i,j,m=lhs.size(),n=rhs.size();
	int carry=0,digit;
	vi res(m+n,0);
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			res[i+j] += lhs[i]*rhs[j];
	carry = 0;
	for(i=0;i<m+n;i++)
	{
		res[i] += carry;
		carry = res[i]/10;
		res[i] = res[i]%10;
	}
	if(res[m+n-1]==0)
		res.pop_back();
	return res;
}