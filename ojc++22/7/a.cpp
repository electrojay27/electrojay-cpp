#include <bits/stdc++.h>
using namespace std;

class Equation
{
private:
	double a,b,c;
public:
	Equation(){a = 1.0,b = 1.0,c = 0;}
	void set(double da,double db,double dc){
		a = da;
		b = db;
		c = dc;
	}
	void getRoot(){
		double cmp = b * b - 4 * a * c;
		if(cmp > 0){
			double x1 = (-b + sqrt(cmp))/(2 * a);
			double x2 = (-b - sqrt(cmp))/(2 * a);
			cout << "x1=" << fixed << setprecision(2) << x1 << " " <<  "x2=" << fixed << setprecision(2) << x2 << "\n";
		}else if(!cmp){
			double x = -b / (2 * a);
			cout <<  "x1=x2=" << fixed << setprecision(2) << x << "\n";
		}else{
			cmp = sqrt(4*a*c - b*b);
			double fa = -b/(2 * a);
			double fb = cmp/(2*a);
			cout << "x1=" << fixed << setprecision(2) << fa << "+" << fixed << setprecision(2) << fb << "i" << " " <<  "x2=" << fixed << setprecision(2) << fa << "-" << fixed << setprecision(2) << fb << "i" << "\n";
		}
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t --){
		double a,b,c;
		Equation f;

		cin >> a >> b >> c;

		f.set(a,b,c);

		f.getRoot();
	}
	return 0;
}