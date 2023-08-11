#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n,m;
	cin >> n >> m;

	vector<vector<int>> adj(n);
	vector<int> in(n,0),out(n,0);
	for (int i = 0; i < m; i++) {
		int x,y;
		cin >> x >> y;
		x--,y--;
		adj[x].push_back(y);
		in[y] ++;
		out[x] ++;
	}

	vector<int> f(n,0);

	function<int(int)> dfs = [&](int x) {
		if (f[x]) {
			return  f[x];
		}

		if (!out[x]) return 1;
		for (int i = 0; i < adj[x].size(); i++) {
			f[x] += dfs(adj[x][i]);
		}

		return f[x];
	};

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (!in[i] && out[i]) {
			ans += dfs(i);
		}
	}

	cout << ans << "\n";
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