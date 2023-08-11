#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

struct node
{
	int a,b;
	i64 val;

	bool operator < (const node& t) const {
		return val > t.val;
	}
};

i64 power(i64 a, i64 b, i64 m) {
	i64 res = 1;
	for (; b; b /= 2, a *= a, a %= m) {
		if (b % 2) {
			res *= a;
			res %= m;
		}
	}
	return res;
}

vector<int> id(10000);
int find(int x) {
	return id[x] = (id[x] == x ? x : find(id[x]));
}

void solve() {
	i64 n,m;
	cin >> n >> m;

	for (int i = 0; i <= n; i++) {
		id[i] = i;
	}

	vector<node> adj;
	vector<i64> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			node cnt;
			cnt.a = i + 1;
			cnt.b = j + 1;	
			cnt.val = (power(a[i],a[j],m) + power(a[j],a[i],m)) % m;
			adj.push_back(cnt);
		}
	}

	sort(adj.begin(),adj.end());

	i64 ans = 0;
	int num = 0;

	for (int i = 0; i < adj.size(); i++) {
		if (find(adj[i].a) != find(adj[i].b)) {
			id[find(adj[i].a)] = find(adj[i].b);
			ans += adj[i].val;
			num ++;
		}
	}

	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// int t;
	// cin >> t;
	int t = 1;

	while (t--) {
		solve();
	}

	return 0;
}