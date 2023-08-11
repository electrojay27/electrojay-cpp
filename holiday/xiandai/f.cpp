#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

i64 judge(i64 x, int bit) {
	return x & (1ll << bit);
}

void solve() {
	int n,q;
	cin >> n >> q;
	

	int now = 0;
	for (int bit = 63; bit >= 0 && now < n; bit--) {
		int cnt = now;
		while (cnt < n && !judge(a[cnt], bit)) {
			cnt ++;
		}

		if (cnt == n) {
			continue;
		}

		swap(a[cnt],a[now]);

		for (int i = 0; i < n; i++) {
			if (i == now) continue;

			if (judge(a[i], bit)) {
				a[i] ^= a[now];
			}
		}
		now++;
	}

	i64 ans = 0;

	cout << ans << "\n";
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