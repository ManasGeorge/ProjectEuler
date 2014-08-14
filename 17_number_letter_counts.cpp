#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

class num_names{
private:
	map<int,string> names;	
	map<int,int> lengths;
	int nums[29];
public:
	num_names();
	string name(int num);
	int length(int num);
};

int main()
{
	fstream f;
	f.open("number_names.txt",ios::out|ios::trunc);
	num_names n;
	int sum = 0;
	for(int i=1;i<=1000;i++)
		sum+=n.length(i);
		// f<<n.name(i)<<endl;
	cout<<sum<<endl;

}
num_names::num_names()
{
	names[1] = "one";
	names[2] = "two";
	names[3] = "three";
	names[4] = "four";
	names[5] = "five";
	names[6] = "six";
	names[7] = "seven";
	names[8] = "eight";
	names[9] = "nine";
	names[10] = "ten";
	names[11] = "eleven";
	names[12] = "twelve";
	names[13] = "thirteen";
	names[14] = "fourteen";
	names[15] = "fifteen";
	names[16] = "sixteen";
	names[17] = "seventeen";
	names[18] = "eighteen";
	names[19] = "nineteen";
	names[20] = "twenty";
	names[30] = "thirty";
	names[40] = "forty";
	names[50] = "fifty";
	names[60] = "sixty";
	names[70] = "seventy";
	names[80] = "eighty";
	names[90] = "ninety";
	names[100] = "hundred";
	names[1000] = "thousand";

	int n[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 30, 40, 50, 60, 70, 80, 90, 100,1000}; //29
	for(int i=0;i<29;i++)
		nums[i] = n[i];
	for(int i=0;i<29;i++)
		lengths[nums[i]] = names[nums[i]].size();
}

string num_names::name(int num)
{
	int i;
	stringstream s;
	if(num/1000>=1  && num!=0)
		{
			s<<(names[num/1000]);
			s<<(" thousand ");
			while(num/1000 >= 1 && num!=0)
				num -= 1000;
		}
	if(num/100>=1  && num!=0)
		{
			s<<(names[num/100]);
			s<<(" hundred ");
			while(num/100 >= 1 && num!=0)
				num -= 100;
			if(num)
				s<<"and ";
		}
	for(i=26;i>=0 && num!=0;i--)
		if(num/nums[i] >= 1)
		{
			s<<(names[nums[i]]);
			s<<(" ");
			while((num/nums[i]) >= 1 && num!=0)
				num -= nums[i];
		}
	return s.str();
}

int num_names::length(int num)
{
	int i;
	int s=0;
	if(num/1000>=1  && num!=0)
		{
			s += (lengths[num/1000]);
			// s<<(" thousand ");
			s += 8;
			while(num/1000 >= 1 && num!=0)
				num -= 1000;
		}
	if(num/100>=1  && num!=0)
		{
			s += (lengths[num/100]);
			// s<<(" hundred and ");
			s += 7;
			while(num/100 >= 1 && num!=0)
				num -= 100;
			if(num)
				s+= 3;
		}
	for(i=26;i>=0 && num!=0;i--)
		if(num/nums[i] >= 1)
		{
			s+=lengths[nums[i]];
			while((num/nums[i]) >= 1 && num!=0)
				num -= nums[i];
		}
	return s;
}