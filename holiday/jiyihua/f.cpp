#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

i64 f[16][16][16][16][16][6] = {0};

void solve() {
	int mod = 1000000007;
	int n;
	cin >> n;

	vector<int> v(6,0);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v[x] ++;
	}

	// cout << "Yes\n";

	function<i64(int,int,int,int,int,int)> dfs = [&](int a,int b,int c,int d,int e,int last) {
		if (f[a][b][c][d][e][last]) return f[a][b][c][d][e][last];

		if (a + b + c + d + e == 0) return f[a][b][c][d][e][last] = 1;

		if (a) f[a][b][c][d][e][last] += (a - (last == 2)) * dfs(a - 1,b,c,d,e,1);
		if (b) f[a][b][c][d][e][last] += (b - (last == 3)) * dfs(a + 1,b - 1,c,d,e,2);
		if (c) f[a][b][c][d][e][last] += (c - (last == 4)) * dfs(a,b + 1,c - 1,d,e,3);
		if (d) f[a][b][c][d][e][last] += (d - (last == 5)) * dfs(a,b,c + 1,d - 1,e,4);
		if (e) f[a][b][c][d][e][last] += e * dfs(a,b,c,d + 1,e - 1,5);

		f[a][b][c][d][e][last] %= mod;

		return f[a][b][c][d][e][last];
	};

	cout << dfs(v[1],v[2],v[3],v[4],v[5],0) << "\n";

	// cout << 0 << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// int t;
	// cin >> t;
	int t = 1;
	// cout << "Yes\n";

	while (t--) {
		// cout << "Yes\n";
		solve();
	}

	return 0;
}