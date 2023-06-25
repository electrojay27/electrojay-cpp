#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;

	vector<int> a(n,0);
	vector<vector<int>> v(n);
	for (int i = 0; i < n - 1; i++) {
		int x,y;
		cin >> x >> y;

		x--,y--;

		v[x].push_back(y);
		v[y].push_back(x);
	}

	auto dfs = [&](auto self, int x, int p) -> void {
        for (auto y : v[x]) {
            if (y != p) {
                self(self, y, x);
                a[x] += a[y];
            }
        // }//从上开始，避免重复
        if (a[x] == 0) {
            a[x] = 1;
        }
    };
    dfs(dfs, 0, -1);

	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int x,y;
		cin >> x >> y;

		x--,y--;

		i64 ans = 1ll * a[x] * a[y];

		// cout << a[x] << " " << a[y] << "\n";

		cout << ans << "\n";
	}
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