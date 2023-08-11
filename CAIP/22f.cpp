#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	i64 a = 0,b = 0;
	vector<int> adj[n];
	for (int i = 0; i < n - 1; i++) {
		int x,y;
		cin >> x >> y;
		x--,y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	vector<int> vis(n,-1);

	function<void(int,int,int)> dfs = [&](int x, int p, int cnt) {
		if (vis[x] == -1) {
			vis[x] = cnt;
		}
		for (auto y : adj[x]) {
			if (y == p) continue;
			vis[y] = cnt ^ 1;
			dfs(y,x,cnt ^ 1);
		}
	};

	dfs(0,-1,0);
	for (int i = 0; i < n; i++) {
		if (vis[i])a ++;
		else b ++;
	}

	// cout << a << " " << b << "\n";

	cout << a * b - n + 1 << "\n";
}