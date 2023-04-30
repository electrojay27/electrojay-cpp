#include <bits/stdc++.h>
using namespace std;

class Point
{
private:
    double x, y;
public:
    Point(double xx, double yy){
    	x = xx;
    	y = yy;
    }; // 构造函数
    friend double Distance(Point& a,Point& b){
    	return sqrt(pow(a.x - b.x,2) + pow(a.y - b.y,2));
    }
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	while(n --){
		double x1,x2,y1,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		Point a(x1,y1);
		Point b(x2,y2);
		cout << int(Distance(a,b)) << "\n";
	}
	return 0;
}