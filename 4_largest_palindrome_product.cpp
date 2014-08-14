#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

bool isPalindrome(long n);
int main()
{
	int i,j,maxpal=0;
	for(i=999;i>=100;i--)
		for(j=999;j>=100;j--)
			if(isPalindrome(i*j))
				maxpal = (i*j>maxpal)?(i*j):(maxpal);
	cout<<maxpal<<endl;
}

bool isPalindrome(long n)
{
	ostringstream num;
	num<<n;
	string number = num.str();
	return equal(number.begin(),number.end(),number.rbegin());
}