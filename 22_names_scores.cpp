#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
typedef vector<string> vs;
typedef vector<int> vi;

double score(string s);
void sort(vs::iterator begin, vs::iterator end);
int main()
{
	fstream f;
	vs names;
	string s;
	double sc = 0;

	f.open("names.txt",ios::in);
	while(getline(f,s,','))
		names.push_back(s);
	sort(names.begin(), names.end());
	for(vs::iterator i = names.begin(); i!= names.end(); i++)
		// if((i - names.begin() + 1 == 938))
			// cout<<(i-names.begin() + 1)<<" "<<*i<<" "<<score(*i)<<endl;
		sc += score(*i) * (double)(1 + i - names.begin());
	cout<<setprecision(10)<<sc;
}

double score(string s)
{
	double sum = 0;
	for(string::iterator i = s.begin(); i!= s.end(); i++)
			sum += (int)(*i - 'A' + 1);
	return sum;
}

void sort(vs::iterator begin, vs::iterator end)
{
	if(end-begin == 1)
		return;
	vs::iterator middle = begin + (end-begin)/2, i,j;
	string temp;
	
	temp = *middle;
	*middle = *(end-1);
	*(end-1) = temp;
	j = begin;

	for(i=begin;i!=end-1;i++)
	{
		if(*i < *(end-1))
		{
			temp = *i;
			*i = *j;
			*j = temp;
			j++;
		}
	}

	temp = *(end-1);
	*(end-1) = *j;
	*j = temp;

	sort(begin,j);
	sort(j,end);
	return;
}