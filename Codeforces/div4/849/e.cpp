#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;

	i64 ans = 0;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		ans += a[i];
	}

	for (int i = 0; i < n - 1; i ++) {
		if (a[i] < 0 && -a[i] > a[i + 1]) {
			ans += 2 * (-a[i] - a[i + 1]);
			a[i + 1] = -a[i + 1];
		}
	}

	cout << ans << "\n";

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