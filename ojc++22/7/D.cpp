#include <bits/stdc++.h>
using namespace std;

class CDate
{
    private:
        int year, month, day;
    public:
        CDate(int y, int m, int d);
        bool isLeapYear();
        int getYear();
        int getMonth();
        int getDay();
        int getDayofYear();
};
CDate::CDate(int y, int m, int d)
{ 
    year = y, month = m,day = d;
}
bool CDate::isLeapYear()
{ 
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0; 
}
int CDate::getYear()
{ 
    return year;
}
int CDate::getMonth() 
{ 
    return month;
}
int CDate::getDay() 
{ 
    return day;
}
int CDate::getDayofYear()
{
    int i, sum = day;
    int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // 求日期的天数
    for(int j = 2015;j <= year;j ++){
	    if(j != year){
	    if((j % 4 == 0 && j % 100 != 0 || j % 400 == 0) && a[2] == 28)a[2] ++;
	    else if(a[2] == 29)a[2] --;
	    for (i = 0; i <= 12; i++)
	    {
	        sum += a[i];
	    }
   		}
	    else{
	    if (isLeapYear())
    	{
        	a[2] = 29;
    	}
	    for (i = 0; i < month; i++)
	    {
	        sum += a[i];
	    }
		}
	}
    return sum;
}

class software
{
private:
	string name;
	char type;
	char media;
	CDate date;
public:
	software(string name,char type,char media,int year,int month,int day):date(year,month,day){
		this->name = name;
		this->type = type;
		this->media = media;
	}
	software(const software& s):date(s.date){
		this->name = s.name;
		this->type = 'B';
		this->media = 'H';
	}
	string getName(){
		return name;
	}
	string getType(){
		switch(type){
			case 'O':return "original";
			case 'T':return "trial";
			case 'B':return "backup";
		}
	}
	string getMedia()
	{
		switch(media){
			case 'D':return "optical disk";
			case 'H':return "hard disk";
			case 'U':return "USB disk";
		}
	}
	void print()
	{
		CDate ddate(2015,4,8);
		if(date.getDayofYear() == 0){
			cout << "this software has unlimited use\n";
		}else if(date.getDayofYear() < ddate.getDayofYear()){
			cout << "this software has expired\n";
		}else{
			cout << "this software is going to be expired in " << date.getDayofYear() - ddate.getDayofYear() << " days\n";
		}
	}
};

void Print(software & now){
	cout << "name:" << now.getName() << "\n";
	cout << "type:" << now.getType() << "\n";
	cout << "media:" << now.getMedia() << "\n";
	now.print();
	cout << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t --){
		string name;
		char type,media;
		int year,month,day;
		cin >> name >> type >> media >> year >> month >> day;
		software now(name,type,media,year,month,day);
		Print(now);
		software now2(now);
		Print(now2);
	}
	return 0;
}