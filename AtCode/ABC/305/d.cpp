#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	i64 n;
	cin >> n;

	vector<i64> a(n),f(n,0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i < n; i++) {
		if (i % 2 == 0) {
			f[i] = f[i - 1] + a[i] - a[i - 1];
		} else {
			f[i] = f[i - 1];
		}

		// cout << f[i] << " \n"[i == n - 1];
	}

	int q;
	cin >> q;

	while (q--) {
		int l,r;
		cin >> l >> r;

		int ll = upper_bound(begin(a) + 1, end(a), l) - begin(a) - 1;
		int rr = upper_bound(begin(a) + 1, end(a), r) - begin(a) - 1;

		// cout << rr << " " << ll << "\n";

	// 	cout << f[rr] + (f[rr + 1] - f[rr]) / (a[rr + 1] - a[rr]) * (r - a[rr]) - (f[ll] + (f[ll + 1] - f[ll]) / (a[ll + 1] - a[ll]) * (l - a[ll])) << "\n";
		int ans = f[rr] - f[ll];

		if (l > a[ll] && ll & 1) ans -= (l - a[ll]);
		if (r > a[rr] && rr & 1) ans += (r - a[rr]);

		cout << ans << "\n";
	} 
}