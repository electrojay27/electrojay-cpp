#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

class Group
{
public:
	virtual int add(int x, int y) = 0; // 输出加法的运算结果
	virtual int sub(int x, int y) = 0; // 输出减法的运算结果
};

class A:public Group
{
public:
	virtual int add(int x, int y){
		return x + y;
	}
	virtual int sub(int x, int y){
		return x - y;
	}
};

class B:public Group
{
public:
	virtual int add(int x, int y){
		return x + y;
	}
	virtual int sub(int x, int y){
		int base = 1;
		int res = 0;
		while(x || y){
			int cntx = x % 10;
			int cnty = y % 10;
			if(cntx < cnty){
				cntx += 10;
			}
			res += base * (cntx - cnty);
			base *= 10;
			x /= 10;
			y /= 10;
		}
		return res;
	}
};

class C:public Group
{
public:
	virtual int add(int x, int y){
		int res = 0;
		int base = 1;
		while(x || y){
			int cntx = x % 10;
			int cnty = y % 10;
			if(cntx + cnty >= 10){
				res += (cntx + cnty - 10) * base;
			}else res += (cntx + cnty) * base;
			x /= 10;
			y /= 10;
			base *= 10;
		}
		return res;
	}
	virtual int sub(int x, int y){
		int base = 1;
		int res = 0;
		while(x || y){
			int cntx = x % 10;
			int cnty = y % 10;
			if(cntx < cnty){
				cntx += 10;
			}
			res += base * (cntx - cnty);
			base *= 10;
			x /= 10;
			y /= 10;
		}
		return res;
	}
};


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	Group *p;

	while(t --){
		int n,x,y,ans = 0;
		char op;
		cin >> n >> x >> op >> y;
		if(n == 1){
			p = new A;
		}else if(n == 2){
			p = new B;
		}else{
			p = new C;
		}

		if(op == '+'){
			ans = p->add(x,y);
		}else{
			ans = p->sub(x,y);
		}

		cout << ans << "\n";
	}

	return 0;
}