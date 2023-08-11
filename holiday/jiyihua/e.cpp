#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n,k;
	cin >> n >> k;

	vector<vector<int>> f(300,vector<int>(10,0));

	function<int(int,int)> dfs = [&](int x, int p) {
		if (f[x][p]) return f[x][p];

		if (x < p || p < 0) return 0;

		if (p == 1) return 1;

		if (p == 2) return x / 2;

		f[x][p] = dfs(x - p, p) + dfs(x - 1,p - 1);

		return f[x][p];
	};

	cout << dfs(n,k) << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	// cin >> t;
	t = 1;

	while (t--) {
		solve();
	}

	return 0;
}