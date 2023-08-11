#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n,k;
	cin >> n >> k;

	if (n < k - 2) {
		cout << 0 << "\n";
	} else {
		i64 ans = 0;

		function<int(int, int, int)> dfs = [&](int f1, int f2, int cnt) {
			if (f1 > f2) return 0;
			if (cnt <= 2) return 1;

			return dfs(f2 - f1,f1,cnt - 1);
		};

		for (int i = 0; i <= n / 2; i++) {
			ans += dfs(i,n - i,k - 1);
		}

		cout << ans << "\n";
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