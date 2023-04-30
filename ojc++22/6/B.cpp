#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int mon[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

class Date
{
	int year,month,day;
public:
	Date(){
		year = month = day = 0;
	};
	Date(int y,int m,int d){
		year = y;
		month = m;
		day = d;
	};
	int getyear(){return year;}
	int getmonth(){return month;}
	int getday(){return day;}
	void setDate(int y,int m,int d){
		year = y;
		month = m;
		day = d;
	}
	void print(){
		printf("Today is %d/%02d/%02d\n",year,month,day);
	}
	void addoneday(){
		if(month == 2){
			if(!(year % 4) && (year % 100) || !(year % 400)){
				if(day == 29){
					day = 0;
					month ++;
				}
			}else{
				if(day == 28){
					day = 0;
					month ++;
				}
			}
		}else{
			if(month < 12 && day == mon[month]){
				day = 0;
				month++;
			}else if(month == 12 && day == mon[month]){
				year ++;
				month = 1;
				day = 0;
			}
		}
		day ++;
		printf("Tomorrow is %d/%02d/%02d\n",year,month,day);
	}
};

void solve(int t)
{
	int y,m,d;
	if(t % 2){
		cin >> y >> m >> d;
		Date a(y,m,d);
		a.print();
		a.addoneday();
	}else{
		cin >> y >> m >> d;
		Date a;
		a.setDate(y,m,d);
		a.print();
		a.addoneday();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	for(int i = 1;i <= t;i ++){
		solve(i);
	}

	return 0;
}