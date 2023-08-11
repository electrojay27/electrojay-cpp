#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n,x;
	cin >> n >> x;

	vector<int> a(n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == x && !ans) {
			ans = i + 1;
		}
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