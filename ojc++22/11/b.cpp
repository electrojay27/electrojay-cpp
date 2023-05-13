#include <bits/stdc++.h>
#define pi 3.14
using namespace std;

using i64 = long long;

class C2D
{
protected:
	int x,y;
public:
	void getxy(){
		cin >> x >> y;
	}
	void getdistance(){
		cout << sqrt(x * x + y * y) << "\n";
	}
};

class C3D:public C2D
{
protected:
	int z;
public:
	void getxyz(){
		cin >> x >> y >> z;
	}
	void getDistance(){
		cout << sqrt(x * x + y * y + z * z) << "\n";
	}
};

int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	C2D a;
	C3D b,c;

	a.getxy();
	b.getxyz();
	c.getxyz();

	a.getdistance();
	b.getDistance();
	c.getDistance();
	c.getdistance();

	return 0;
}