#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

class Clock
{
private:
	int hour;
	int mintue;
	int second;
public:
	Clock () {}
	Clock (int h,int m,int s) {
		hour = h;
		mintue = m;
		second = s;
	}

	void print() {
		cout << hour << ':' << mintue << ':' << second << "\n";
	}

	friend Clock &operator++(Clock& a) {
		a.second ++;
		if (a.second == 60) {
			a.second = 0;
			a.mintue ++;
			if (a.mintue == 60) {
				a.hour ++;
				a.mintue = 0;
				if (a.hour == 12) {
					a.hour = 0;
				}
			}
		}
		return a;
	};

	friend Clock &operator--(Clock& a) {
		a.second --;
		if (a.second == -1) {
			a.second = 59;
			a.mintue --;
			if (a.mintue == -1) {
				a.hour --;
				a.mintue = 59;
				if (a.hour == -1) {
					a.hour = 11;
				}
			}
		}
		return a;
	};
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int h,m,s;
	cin >> h >> m >> s;

	Clock a(h,m,s);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n > 0) {
			for (int i = 0; i < n; i++) {
				++a;
			}
		} else {
			for (int i = 0; i < -n; i++) {
				--a;
			}
		}
		a.print();
	}
}