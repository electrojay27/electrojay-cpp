#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

struct node{
	int d,u,r;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	map<int,pair<int,int>> mp;
	set<pair<int,int>> p;
	map<int,bool> st;
	vector<node> v[1010];
	for (int i = 0; i < n; i++) {
		int r,m;
		cin >> r >> m;
		for (int j = 0; j < r; j++) {
			int x;
			cin >> x;
			if (!st[x]) {
				mp[x] = {i,i + 6};
			} else {
				if (i <= mp[x].second + 1) mp[x].second = i + 6;
				else mp[x] = {i,i + 6};
			}
			st[x] = true;
		}

		for (int j = 0; j < m; j++) {
			int a,b,c;
			cin >> a >> b >> c;
			v[i].push_back({a,b,c});
		}

		vector<int> ans;
		for (int j = (i - 6 >= 0 ? i - 6 : 0); j <= i; j++) {
			for (int k = 0; k < v[j].size(); k++) {
				if (st[v[j][k].r] && v[j][k].d >= i - 6 && v[j][k].d <= i && v[j][k].d >= mp[v[j][k].r].first && i <= mp[v[j][k].r].second)ans.push_back(v[j][k].u);
			}
		}

		sort(ans.begin(),ans.end());
		ans.erase(unique(ans.begin(),ans.end()),ans.end());

		cout << i;
		for (auto it : ans) cout << " " << it;
		cout << "\n";
	}
}