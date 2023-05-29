#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,m;
	cin >> n >> m;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> mp[n];
	for (int i = 0; i < n - 1; i++) {
		int x,y;
		cin >> x >> y;
		if (x == y)continue;
		mp[x - 1].push_back(y - 1);
		mp[y - 1].push_back(x - 1);
		// cout << x << " " << y << "\n";
	}

	vector<int> v(n,0),vis(n,0);
	queue<int> q;
	q.push(0);
	v[0] = a[0];
	vis[0] = 1;
	int ans = 0;
	while (!q.empty()) {
		int to = q.front();
		q.pop();
		// cout << to << " " << mp[to].size() << "\n";
		if (to && mp[to].size() == 1) {
			ans ++;
			continue;
		}
		for (int i = 0; i < mp[to].size(); i++) {
			if (vis[mp[to][i]]) continue;
			if (a[mp[to][i]]) {
				if (a[mp[to][i]] + v[to] <= m) {
					q.push(mp[to][i]);
					v[mp[to][i]] = a[mp[to][i]] + v[to];
					// cout << v[mp[to][i]] << "\n";
				}
			} else {
				v[mp[to][i]] = 0;
				q.push(mp[to][i]);
			}

			// cout << mp[to][i] << "\n";
			
			vis[mp[to][i]] = 1;
		}
	}

	cout << ans << "\n";
}