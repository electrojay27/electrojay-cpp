#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	i64 ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		ans += fabs(a[i]);
	}

	int cnt = 0;
	int flag = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < 0) {
			if (!flag) {
				flag = 1;
			}
		}

		if (a[i] > 0) {
			if (flag) {
				cnt ++;
				flag = 0;
			}
		}
	}

	cnt += flag;

	cout << ans << " " << cnt << "\n";
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