#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

class CFraction
{
private:
    int fz,fm;
public:
    CFraction(int fz_val, int fm_val){
    	fz = fz_val;
    	fm = fm_val;
    }
    CFraction add(const CFraction &r){
    	return CFraction(fz * r.fm + fm * r.fz,fm * r.fm);
    }
    CFraction sub(const CFraction &r){
    	return CFraction(fz * r.fm - fm * r.fz,fm * r.fm);
    }
    CFraction mul(const CFraction &r){
    	return CFraction(fz * r.fz,fm * r.fm);
    }
    CFraction div(const CFraction &r){
    	return CFraction(fz * r.fm,fm * r.fz);
    }
    int getGCD(){
    	int temp = fm;
    	int x = fabs(fz),y = fabs(fm);
    	while(x % y){
    		temp = x % y;
    		x = y;
    		y = temp;
    	}
    	return y;
    }// 求对象的分子和分母的最大公约数
    void print(){
    	int temp = getGCD();
    	fz /= temp;
    	fm /= temp;
    	if(fz / fz == fm / fm){
    		cout << fz << '/' << fm << endl;
    	}else{
    		cout << '-' << fz << '/' << fm << endl;
    	}
    }
};

void solve()
{
	int a,b,c,d;
	char e;
	cin >> a >> e >> b;
	CFraction x(a,b);
	cin >> a >> e >> b;
	CFraction y(a,b);
	CFraction z = x.add(y);
	z.print();
	z = x.sub(y);
	z.print();
	z = x.mul(y);
	z.print();
	z = x.div(y);
	z.print();

	cout << endl;
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