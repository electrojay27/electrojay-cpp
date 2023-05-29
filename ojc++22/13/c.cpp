#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

class CVehicle
{
protected:
	int max_speed,speed,weight;
public:
	CVehicle (int m,int s,int w) : max_speed(m),speed(s),weight(w){}
	virtual void display() {
		cout << "Vehicle:\n";
		cout << "max_speed:" << max_speed << "\n";
		cout << "speed:" << speed << "\n";
		cout << "weight:" << weight << "\n";
		cout << "\n";
	}
};

class CBicycle:public CVehicle
{
protected:
	int height;
public:
	CBicycle (int m,int s,int w,int h) : CVehicle(m,s,w),height(h){}
	virtual void display() {
		cout << "Bicycle:\n";
		cout << "max_speed:" << max_speed << "\n";
		cout << "speed:" << speed << "\n";
		cout << "weight:" << weight << "\n";
		cout << "height:" << height << "\n";
		cout << "\n";
	}
};

class CMotocar:public CVehicle
{
protected:
	int seat_num;
public:
	CMotocar (int m,int s,int w,int se) : CVehicle(m,s,w),seat_num(se){}
	virtual void display() {
		cout << "Motocar:\n";
		cout << "max_speed:" << max_speed << "\n";
		cout << "speed:" << speed << "\n";
		cout << "weight:" << weight << "\n";
		cout << "seat_num:" << seat_num << "\n"; 
		cout << "\n";
	}
};

class CMotocycle:public CBicycle,public CMotocar
{
public:
	CMotocycle (int m,int s,int w,int h,int se) : CBicycle(m,s,w,h),CMotocar(m,s,w,se){}
	virtual void display() {
		cout << "Motocycle:\n";
		cout << "max_speed:" << CBicycle::max_speed << "\n";
		cout << "speed:" << CBicycle::speed << "\n";	
		cout << "weight:" << CBicycle::weight << "\n";
		cout << "height:" << height << "\n";
		cout << "seat_num:" << seat_num << "\n"; 
		cout << "\n";
	}
};

int main() {
	int m,s,w,h,se;
	cin >> m >> s >> w;
	cin >> h >> se;
	CVehicle a(m,s,w);
	a.display();
	CBicycle b(m,s,w,h);
	b.display();
	CMotocar c(m,s,w,se);
	c.display();
	CMotocycle d(m,s,w,h,se);
	d.display();	
}