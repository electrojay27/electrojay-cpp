#include <iostream>
#include <cstring>
using namespace std;

class Date;
class Time;

class Date
{
private:
	int year,month,day;
public:
	Date(int y,int m,int d){
		year = y;
		month = m;
		day = d;
	};
	friend void display(const Date& a,const Time& b);
};

class Time
{
private:
	int hour,mintue,second;
public:
	Time(int h,int m,int s){
		hour = h;
		mintue = m;
		second = s;
	};
	friend void display(const Date& a,const Time& b);
};

void display(const Date& a,const Time& b){
	printf("%d-%02d-%02d ",a.year,a.month,a.day);
	printf("%02d:%02d:%02d\n",b.hour,b.mintue,b.second);
}

int main()
{
	int n;
	cin >> n;
	while(n --){
		int a,b,c;
		cin >> a >> b >> c;
		Date x(a,b,c);
		cin >> a >> b >> c;
		Time y(a,b,c);
		display(x,y);
	}

	return 0;
}