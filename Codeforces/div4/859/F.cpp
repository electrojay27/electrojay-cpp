#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n,m;
	cin >> n >> m;

	int x,y,dx,dy;
	cin >> x >> y >> dx >> dy;

	string s;
	cin >> s;

	int d1 = 1,d2 = 1;
	if (s[0] == 'U') {
		d1 = -1;
	} 
	if (s[1] == 'L') {
		d2 = -1;
	}

	int cnt = 0;
	int ans = 0;
	while (cnt < 4 * n * m) {
		if (dx == x && dy == y) {
			cout << ans << "\n";
			return;
		}
		cnt ++;
		bool flag = false;
		if (x + d1 < 1 || d1 + x > n) {
			flag = true;
			d1 *= -1;
		}
		if (y + d2 < 1 || d2 + y > m) {
			flag = true;
			d2 *= -1;
		}

		ans += flag;
		x += d1;
		y += d2;
	}

	cout << -1 << "\n";
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