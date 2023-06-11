#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n,k;
	cin >> n >> k;

	if (k == 1) {
		cout << n << "\n";
		return;
	}

	int ans = n / k;
	if (n % k) {
		ans += 1;
		if ((ans - 1) * k + 1 != n) {
			ans ++;
		}
	} else {
		ans ++;
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