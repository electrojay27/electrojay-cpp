#include <bits/stdc++.h>
using namespace std;

class Complex
{
private:
	double real; // 实部
	double imag; // 虚部
public:
	Complex(){};
	Complex(double r, double i){
		real = r;
		imag = i;
	};
	// 友元函数，复数c1 + c2(二参数对象相加)
	friend Complex addCom(const Complex& c1, const Complex& c2){
		Complex ans(0,0);
		ans.real = c1.real + c2.real;
		ans.imag = c1.imag + c2.imag;
		return ans;
	};
	friend Complex minusCom(const Complex& c1, const Complex& c2){
		Complex ans(0,0);
		ans.real = c1.real - c2.real;
		ans.imag = c1.imag - c2.imag;
		return ans;
	};
	// 友元函数，输出类对象c的有关数据(c为参数对象)
	friend void outCom(const Complex& c){
		cout << '(' << c.real << ',' << c.imag << ')' << "\n";
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	double r,i;
	cin >> r >> i;
	Complex ans(r,i);
	int n;
	cin >> n;
	while(n --){
		char op;
		double x,y;
		cin >> op >> x >> y;
		Complex cnt(x,y);
		if(op == '+')ans = addCom(ans,cnt);
		else ans = minusCom(ans,cnt);

		outCom(ans);
	}

	return 0;
}