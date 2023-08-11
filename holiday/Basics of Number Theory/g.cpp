#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n,m;
	cin >> n >> m;

	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	vector<vector<int>> ans(n,vector<int>(n,0));
	for (int i = 0; i < n; i++) {
		ans[i][i] = a[i];
		for (int j = i + 1; j < n; j++) {
			ans[i][j] = __gcd(ans[i][j - 1],a[j]);
		}
	}

	for (int i = 0; i < m; i++) {
		int a,b;
		cin >> a >> b;
		a--,b--;
		cout << ans[a][b] << "\n";
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