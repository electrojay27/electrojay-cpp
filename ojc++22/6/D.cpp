#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

class Point
{
	double x,y;
public:
	Point(){
		cout << "Constructor." << endl;
		x = y = 0;
	};
	~Point()
	{
		cout << "Distructor." << endl;
	}
	Point(double x_val,double y_val){
		x = x_val;
		y = y_val;
	};
	double getX(){return x;}
	double getY(){return y;}
	void setXY(double x_val,double y_val){
		x = x_val;
		y = y_val;
	}
	double getDisTo(Point &p){
		return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y)); 
	}
};

void solve()
{
	int n;
	cin >> n;
	Point* arr = new Point[n];
	double x,y;
	for(int i = 0;i < n;i ++)
	{
		cin >> x >> y;
		arr[i].setXY(x,y);
	}

	double maxl = arr[0].getDisTo(arr[1]);
	int maxa = 0,maxb = 1;

	for(int i = 0;i < n;i ++){
		for(int j = i + 1;j < n;j ++){
			if(maxl < arr[i].getDisTo(arr[j])){
				maxl = arr[i].getDisTo(arr[j]);
				maxa = i;
				maxb = j;
			}
		}
	}

	cout << "The longeset distance is " << fixed << setprecision(2) << maxl << ",between p[" << maxa << "] and p[" << maxb << "]." << endl;

	delete[] arr;
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