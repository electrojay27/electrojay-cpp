#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,D;
	cin >> n >> D;

	vector<pair<int,int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}

	vector<int> vis(n,0);
	vis[0] = 1;
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int to = q.front();
		q.pop();

		for (int i = 1; i < n; i++) {
			if (vis[i]) {
				continue;
			}

			if (D * D >= (a[i].first - a[to].first) * (a[i].first - a[to].first) + (a[i].second - a[to].second) * (a[i].second - a[to].second)) {
				vis[i] = 1;
				q.push(i);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (vis[i]) cout << "Yes\n";
		else cout << "No\n";
	}
}