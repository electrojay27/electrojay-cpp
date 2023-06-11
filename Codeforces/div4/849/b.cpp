#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	int x = 0,y = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'U') {
			y ++;
		} else if (s[i] == 'D') {
			y --;
		} else if (s[i] == 'L') {
			x --;
		} else {
			x ++;
		}

		if (x == 1 && y == 1) {
			cout << "YES\n";
			return;
		}
	}

	cout << "NO\n";
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