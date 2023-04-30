#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

class Point
{
	double x,y;
public:
	Point(){
		x = y = 0;
	};
	Point(double x_val,double y_val){
		x = x_val;
		y = y_val;
	};
	double getX(){return x;}
	double getY(){return y;}
	void setX(double x_val){
		x = x_val;
	}
	void setY(double y_val){
		y = y_val;
	}
	double distanceToAnotherPoint(Point p){
		return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y)); 
	}
};

void solve()
{
	double x,y;
	cin >> x >> y;
	Point a(x,y);
	cin >> x >> y;
	Point b(x,y);
	cout << "Distance of Point(" << fixed << setprecision(2) << a.getX() << ',' << fixed << setprecision(2) << a.getY() << ") to Point(" << fixed << setprecision(2) << b.getX() << ',' << fixed << setprecision(2) << b.getY() << ") is " << fixed << setprecision(2) << a.distanceToAnotherPoint(b) << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t --){
		solve();
	}

	return 0;
}