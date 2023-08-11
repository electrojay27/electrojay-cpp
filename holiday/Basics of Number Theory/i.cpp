#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	i64 n,p;
	cin >> n >> p;

	vector<i64> ans(n + 1,0);
	ans[1] = 1;
	cout << ans[1] << "\n";
	for (int i = 2; i <= n; i++) {
		ans[i] = (p - p / i) * ans[p % i] % p;
		cout << ans[i] << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// int t;
	// cin >> t;
	int t = 1;

	while (t--) {
		solve();
	}

	return 0;
}