#include <bits/stdc++.h>

using i64 = long long;

int a[30001];

void init() {
	a[0] = 0;
	a[1] = 2;
	for (int i = 2;i <= 30000;i ++) {
		a[i] = a[i - 1] + 2 + (i - 1) * 3;
	}
}

void solve() {
	int n;
	std::cin >> n;

	int to,ans = 0;

	for (int i = 0;i <= 30000;i ++) {
		if (a[i] > n) {
			to = i - 1;
			break;
		}
	}

	while (to) {
		if (n - a[to] >= 0) {
			ans += n / a[to];
			n %= a[to];
		}

		to --;
	}

	std::cout << ans << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	init();
	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}