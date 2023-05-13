#include <bits/stdc++.h>
#define pi 3.14
using namespace std;

using i64 = long long;

class CPoint
{
protected:
	int x,y;
public:
	void getxy(){
		cin >> x >> y;
	}
};

class CCircle:public CPoint
{
protected:
	int r;
public:
	void getr(){
		cin >> r;
	}
	void Calculate_the_area(){
		cout << "Circle:(" << x << ',' << y << ")," << r << "\n";
		cout << "Area:" << fixed << setprecision(2) << r * r * pi << "\n";
	}
};

class CCylinder:public CCircle
{
protected:
	int h;
public:
	void geth(){
		cin >> h;
	}
	void Calculate_volume(){
		cout << "Cylinder:(" << x << ',' << y << ")," << r << ',' << h << "\n";
		cout << "Volume:" << fixed << setprecision(2) << r * r * pi * h << "\n";
	}
};

int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	CCircle a;
	a.getxy();
	a.getr();
	a.Calculate_the_area();

	CCylinder b;
	b.getxy();
	b.getr();
	b.geth();
	b.Calculate_volume();

	return 0;
}