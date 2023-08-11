#include <iostream>
#include <vector>
using namespace std;

void solve(int t) {
	int n,m;
	cin >> n >> m;

	vector<vector<int> > adj(n + 1,vector<int>(n + 1,0x3f3f3f3f));
	for (int i = 0; i < m; i++) {
		int x,y,z;
		cin >> x >> y >> z;
		adj[x][y] = adj[y][x] = min(adj[x][y],z);
	}
	cout << "Scenario #" << t << ":\n";
	vector<int> vis(n + 1,0);
	vector<int> d(n + 1,0x3f3f3f3f);
	d[1] = 0;
	for (int i = 1; i < n; i++) {
		int x = -1;
		for (int j = 1; j <= n; j++) {
			if (!vis[j] && (x == -1 || d[j] < d[x])) x = j;
		}
		vis[x] = 1;
		for (int j = 1; j <= n; j++) {
			d[j] = min(d[j],d[x] + adj[x][j]);
		}
	}

	// for (auto it : d) cout << it << " ";
	// 	cout << "\n";

	cout << d[n] << "\n\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	while (cin >> t) {
		for (int i = 1; i <= t; i++) {
			solve(i);
		}
	}
	return 0;
}