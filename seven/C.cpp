#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Circle
{
public:
	int cx,cy;//圆心
	int cr;//半径
	void setCenter()
	{
		cin >> cx >> cy;
	}
	void setPadius()
	{
		cin >> cr;
	}
	void getArea(){
		double ans;
		ans = 3.14 * cr * cr;
		cout<<fixed<<setprecision(2)<<ans << " ";
	}
	void getLength()
	{
		double ans;
		ans = 2 * 3.14 * cr;
		cout<<fixed<<setprecision(2)<<ans << endl;
	}
};

class Point
{
public:
	int x,y;
	void getPoint()
	{
		cin >> x >> y;
	}
	int getx()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	Circle a;
	Point b;
	for(int i = 1;i < 2;i ++)
	{
		a.setCenter();
		a.setPadius();
		b.getPoint();

		a.getArea();
		a.getLength();

		if(sqrt((a.cx - b.x) * (a.cx - b.x) + (a.cy - b.y) * (a.cy - b.y)) <= a.cr)cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}