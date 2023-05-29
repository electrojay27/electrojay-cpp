#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,l,s;
	cin >> n >> l >> s;

	set<pair<int,int>> mp;
	vector<vector<int>> f(s+1,vector<int>(s+1,0));

	for (int i = 0; i < n; i++) {
		int x,y;
		cin >> x >> y;
		mp.insert({x,y});
	}

	for (int i = s; i >= 0; i--) {
		for (int j = 0; j <= s; j++) {
			cin >> f[i][j];
		}
	}

	int ans = 0;
	for (auto it : mp) {
		int x = it.first;
		int y = it.second;
		int flag = 1;
		for (int i = 0; i <= s; i++) {
			for (int j = 0; j <= s; j++) {
				if (x + i > l || y + j > l)flag = 0;
				if (f[i][j] && !mp.count({x+i,y+j}))flag = 0;
				if (!f[i][j] && mp.count({x+i,y+j}))flag = 0;
			}
		}
		ans += flag;
	}
	
	cout << ans << "\n";
}