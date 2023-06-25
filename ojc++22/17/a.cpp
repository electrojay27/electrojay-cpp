#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

char a[5][10] = {"","黑胶片","CD","VCD","DVD"};

class video
{
private:
	int type;
	string name;
	int value;
	int state;
public:
	video (int t,string na,int v,int s) {
		type = t;
		name = na;
		value = v;
		state = s;
	}
	void print() {
		cout << a[type] << '[' << name << ']';
		if (state) {
			cout << "已出租\n";
		} else {
			cout << "未出租\n";
		}
	}
	void calculate(int x) {
		print();
		if (state) {
			cout << "当前租金为" << value * x << "\n";
		} else {
			cout << "未产生租金\n";
		}
	}
};

void solve() {
	int t,v,s;
	string na;
	cin >> t >> na >> v >> s;

	video now(t,na,v,s);

	int x;
	cin >> x;
	if (x) {
		now.calculate(x);
	} else {
		now.print();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		solve();
	} 
	return 0;
}