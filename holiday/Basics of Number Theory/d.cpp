#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	i64 n;
	cin >> n;

	vector<i64> prime,v(n + 1,0),phi(n + 1,0),sum(n + 1,0);
	prime.push_back(0);
	function<void(i64)> euler = [&](i64 x) {
		phi[1] = 1;
		for (int i = 2; i <= x; i++) {
			if (!v[i]) {
				v[i] = i;
				prime.push_back(i);
				phi[i] = i - 1;
			}

			for (int j = 1; j < prime.size(); j++) {
				if (prime[j] > v[i] || i * prime[j] > x) break;
				v[i * prime[j]] = prime[j];
				phi[i * prime[j]] = phi[i] * (i % prime[j] ? phi[prime[j]] : prime[j]);
			}
		}

		for (int i = 1; i <= x; i++) {
			sum[i] = sum[i - 1] + phi[i];
		}
	};
	euler(n);

	i64 ans = 0;

	for (int i = 1; i < prime.size(); i++) {
		ans += 2 * sum[n / prime[i]] - 1;
	}

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