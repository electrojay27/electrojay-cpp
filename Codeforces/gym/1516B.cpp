#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	int goal = 0;
	for (int i = 0; i < n; i++) cin >> a[i],goal ^= a[i];

	if (goal == 0) {
		cout << "YES\n";
	} else {
		int now = 0;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			now ^= a[i];
			if (now == goal) {
				cnt ++;
				now = 0;
			}
		}

		if (cnt >= 3) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
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