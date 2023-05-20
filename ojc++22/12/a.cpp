#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

class Shape
{
public:
	virtual double area(){};
};

class Circle:public Shape
{
private:
	double r;
public:
	Circle(double rr){r = rr;}
	virtual double area(){
		return 3.14 * r * r;
	}
};

class Square:public Shape
{
private:
	double l;
public:
	Square(double ll){l = ll;}
	virtual double area(){
		return l * l;
	}
};

class Rectangle:public Shape
{
private:
	double l,d;
public:
	Rectangle(double ll, double dd){l = ll;d = dd;}
	virtual double area(){
		return l * d;
	}
};


void solve()
{
	Shape* p[3];
	double x,y;
	cin >> x;
	p[0] = new Circle(x);
	cin >> x;
	p[1] = new Square(x);
	cin >> x >> y;
	p[2] = new Rectangle(x,y);
	for(int i = 0;i < 3;i ++){
		cout << fixed << setprecision(2) << p[i]->area() << "\n";
	}
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