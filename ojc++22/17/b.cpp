#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

class Date
{
protected:
    int year,month,day;
public:
    Date (int y, int m, int d) {
        year = y;
        month = m;
        day = d;
    }
};

class Time
{
protected:
    int hour,mintue,second;
public:
    Time (int h,int m,int s) {
        hour = h;
        mintue = m;
        second = s;
    }
};

class Work:public Date,public Time
{
private:
    int id;
public:
    Work (int i,int y, int mo, int d,int h, int mi, int s) : Date(y,mo,d) , Time(h,mi,s) {
        id = i;
    }
    bool operator < (const Work& a) const {
        if (year != a.year) {
            return year < a.year;
        } else if (month != a.month) {
            return month < a.month;
        } else if (day != a.day) {
            return day < a.day;
        }else if (hour != a.hour) {
            return hour < a.hour;
        } else if (mintue != a.mintue) {
            return mintue < a.mintue;
        } else {
            return second < a.second;
        }
    }
    friend bool before(const Work& a,const Work& b) {
        if (b < a) {
            return true;
        }
        return false;
    }
    void print() {
        printf("The urgent Work is No.%d: %04d/%02d/%02d %02d:%02d:%02d\n",id,year,month,day,hour,mintue,second);
    }
};

void solve() {
    int id;
    vector<Work> a;
    while (cin >> id) {
        if (!id) break;
        int year,month,day,hour,mintue,second;
        cin >> year >> month >> day >> hour >> mintue >> second;
        a.push_back({id,year,month,day,hour,mintue,second});
    }
    Work goal = a[0];
    // goal.print();
    for (int i = 0; i < a.size(); i++) {
        if (before(goal,a[i])) {
            goal = a[i];
        }
    }

    goal.print();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	// cin >> t;
    t = 1;
	while (t--) {
		solve();
	} 
	return 0;
}