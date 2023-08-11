#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

i64 d[100] = {0};

struct node {
	i64 a,b;

	bool operator < (const node& t) const {
		return b < t.b;
	}
};

i64 judge(i64 x, int bit) {
	return x & (1ll << bit);
}

bool insert(i64 x) {
	for (int i = 63; i >= 0; i--) {
		if ((x >> i) & 1) {
			if (!d[i]) {
				d[i] = x;
				return true;
			}
			else x ^= d[i];
		}
	}
	return false;
}

void solve() {
	int n;
	cin >> n;

	vector<node> c(n);
	for (int i = 0; i < n; i++) {
		cin >> c[i].a >> c[i].b;
	}

	sort(c.begin(),c.end());

	i64 ans = 0;

	for (int i = n - 1; i >= 0; i--) {
		if (insert(c[i].a)) ans += c[i].b;
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