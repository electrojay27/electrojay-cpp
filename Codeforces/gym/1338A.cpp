#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;

	vector<int> a(n),b(n,0);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) b[i] = max((i == 0 ? -1000000000 : b[i - 1]),a[i]);

	for (int i = 0; i < n; i++) b[i] = (b[i] - a[i]);

	sort(b.begin(),b.end());

	int ans = 0;
	while (b[n - 1]) {
		b[n - 1] >>= 1;
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