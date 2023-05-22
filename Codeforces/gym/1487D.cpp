#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

vector<array<int,3>> f;
void init() {
	for (int a = 1,b = 2; 1LL * a * a + b * b <= 1000000000; a ++,b ++) {
		f.push_back({b * b - a * a,2 * a * b,b * b + a * a});
	}
}

void solve() {
	int n;
	cin >> n;

	i64 ans = 0;
	for (int i = 0;	i < f.size() && f[i][2] <= n; i++) {
		if (f[i][2] == 1LL * f[i][0] * f[i][0] - f[i][1]) ans ++;
	}

	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	init();
	while (t--) {
		solve();
	}
	return 0;
}