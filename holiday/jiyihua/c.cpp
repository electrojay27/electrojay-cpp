#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int r,c;
	cin >> r >> c;

	vector<vector<int>> a(r,vector<int>(c));
	vector<vector<int>> f(r,vector<int>(c,1));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
		}
	}

	int dx[4] = {0,0,1,-1};
	int dy[4] = {1,-1,0,0};

	function<int(int,int)> dfs = [&](int x,int y) {
		if (f[x][y] > 1) {
			return f[x][y];
		}

		for (int i = 0; i < 4; i++) {
			if (x + dx[i] < r && x + dx[i] > -1 && y + dy[i] < c && y + dy[i] > -1) {
				if (a[x][y] > a[x + dx[i]][y + dy[i]]) {
					f[x][y] = max(f[x][y], dfs(x + dx[i], y + dy[i]) + 1);
				}
			}
		}

		return f[x][y];
	};

	int ans = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			ans = max(ans, dfs(i,j));
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