#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

bool Judge(int year) {
    if (year % 4 == 0 && year % 100 || year % 400 == 0) {
        return true;
    }
    return false;
}

class CDate
{
private:
    int year,month,day;
public:
    CDate() {}
    CDate (int y, int m, int d) {
        year = y;
        month = m;
        day = d;
    };

    bool operator < (const CDate& a) {
        if (year != a.year) {
            return year < a.year;
        } else if (month != a.month) {
            return month < a.month;
        } else if (day != a.day) {
            return day < a.day;
        }
    }

    int operator - (const CDate& a) {
        int M[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
        int m[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

        int d = 0;
        if (Judge(a.year)) {
            for (int i = 1; i < a.month; i++) {
                d += M[i - 1];
            }
        } else {
            for (int i = 1; i < a.month; i++) {
                d += m[i - 1];
            }
        }
        d += a.day;

        int D = 0;
        for (int i = a.year; i < this->year; i++) {
            if (Judge(i)) {
                D += 366;
            } else D += 365;
        }
        if (Judge(this->year)) {
            for (int i = 1; i < this->month; i++) {
                D += M[i - 1];
            }
        } else {
            for (int i = 1; i < this->month; i++) {
                D += m[i - 1];
            }
        }
        D += this->day;

        return D - d;
    }
};

class Pet
{
protected:
    string name;//姓名
    float length;//身长
    float weight;//体重
    CDate current;//开始记录时间
public:
    Pet () {}
    virtual void display(CDate Day)=0;//输出目标日期时宠物的身长和体重
};

class Cat:public Pet{
    float len_change = 0.1;
    float wei_change = 0.2;
public:
    Cat (string na,float h,float w,int y,int m,int d) {
        current = CDate(y,m,d);
        name = na;
        length = h;
        weight = w;
    }
    void display(CDate Day) {
        if (Day < current) {
            int res = current - Day;
            cout << name << " after " << res << " day: ";
            cout << "length=" << fixed << setprecision(2) << res * len_change + length << ',';
            cout << "weight=" << fixed << setprecision(2) << res * wei_change + weight << "\n";
        } else {
            cout << "error\n";
        }
    }
};

class Dog:public Pet{
    float len_change = 0.2;
    float wei_change = 0.1;
public:
    Dog (string na,float h,float w,int y,int m,int d) {
        current = CDate(y,m,d);
        name = na;
        length = h;
        weight = w;
    }
    void display(CDate Day) {
        if (Day < current) {
            int res = current - Day;
            cout << name << " after " << res << " day: ";
            cout << "length=" << fixed << setprecision(2) << res * len_change + length << ',';
            cout << "weight=" << fixed << setprecision(2) << res * wei_change + weight << "\n";
        } else {
            cout << "error\n";
        }
    }
};

// void solve() {
    
// }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
    // t = 1;
    Pet* pt;
    int y,m,d;
    cin >> y >> m >> d;
    CDate now(y,m,d);
	while (t--) {
		int type;
        cin >> type;
        string s;
        cin >> s;
        int l,w;
        cin >> l >> w >> y >> m >> d;
        if (type == 1) {
            pt = new Cat(s,l,w,y,m,d);
        } else {
            pt = new Dog(s,l,w,y,m,d);
        }

        pt->display(now);
	} 
	return 0;
}