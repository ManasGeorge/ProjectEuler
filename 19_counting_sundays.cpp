#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{	
	map<int,string> days;
	days[0] = "Sunday";
	days[1] = "Monday";
	days[2] = "Tuesday";
	days[3] = "Wednesday";
	days[4] = "Thursday";
	days[5] = "Friday";
	days[6] = "Saturday";

	int months[12] = {3,0,3,2,3,2,3,3,2,3,2,3}; //Remainders modulo 7
	int day = 2; //1st January, 1901 was a Tuesday. Sundays are 0 mod 7
	int leap = 0;
	int year = 1901;
	int count = 0;
	int i;
	for(year = 1901; year <= 2000; year++)
	{
		if(year % 4 == 0 && year%100 != 0 || year%400 == 0) leap = 1; else leap = 0;
		months[1] += leap;
		for(i = 0;i<12;i++)
		{
			day = (day + months[i])%7; //Next month
			if(day == 0) // Sunday
				count++;
			cout<<i+2<<" "<<days[day]<<endl;
		}
		months[1] -= leap;
	}
	cout<<endl<<count<<endl;
}