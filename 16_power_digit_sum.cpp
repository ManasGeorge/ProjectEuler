#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void square(string &s);

int main()
{
	string s = "1";
	int sum = 0,n,i;
	for(i=0;i<1000;i++)
	{
		square(s);
		// reverse(s.begin(),s.end());
		// cout<<i+1<<" "<<s<<endl;
		// reverse(s.begin(),s.end());
	}

	n = s.size();
	for(i=0;i<n;i++)
		sum += (int)(s[i] - '0');

	cout<<sum<<endl;
}

void square(string &s)
{
	int n = s.size(), digit,i;
	bool carry = 0;
	for(i=0;i<n;i++)
	{
		digit = (int)(s[i] - '0');
		if(digit<5)
		{
			s[i] = (char)('0' + 2*digit);
			if(carry) s[i]++;
			carry = 0;
		}
		else
		{
			s[i] = (char)('0' + (2*digit)%10);
			if(carry) s[i]++;
			carry = 1;
		}
	}
	if(carry)
		s.push_back('1');
}