#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

struct node {
	int a,b;

	bool operator < (const node& that) const {
		if (a != that.a) return a < that.a;
		return b < that.b;
	}
};

void solve() {
	int n;
	cin >> n;

	vector<node> c(n);
	for (int i = 0; i < n; i++) {
		cin >> c[i].a >> c[i].b;
	}

	sort(c.begin(), c.end());
	vector<int> f(n,1);
	int ans = 1;

	function<int(int)> dfs = [&](int x) {
		if (f[x] > 1) {
			return f[x];
		}

		for (int i = 0; i < n; i++) {
			if (c[i].a < c[x].a && c[i].b < c[x].b || c[i].b < c[x].a && c[i].a < c[x].b) {
				f[x] = max(f[x],dfs(i) + 1);
			}
		}

		return f[x];
	};

	for (int i = 1; i < n; i++) {
		ans = max(ans,dfs(i));
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