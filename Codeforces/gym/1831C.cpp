#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;

	vector<vector<pair<int,int>>> a(n);
	vector<int> f(n,1),id(n,0);
	for (int i = 0; i < n - 1; i++) {
		int u,v;
		cin >> u >> v;
		u --,v --;
		a[u].push_back({v,i});
		a[v].push_back({u,i});
	}

	int ans = 0;

	function<void(int,int)> dfs=[&](int x,int p) {
		for (auto it : a[x]) {
			if (it.first == p) continue;
			id[it.first] = it.second;
			f[it.first] = f[x];
			if (id[x] > it.second) f[it.first] ++;
			ans = max(f[it.first],ans);
			dfs(it.first,x);  
		}
	};

	dfs(0,-1);

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