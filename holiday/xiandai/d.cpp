#include <bits/stdc++.h>
#define mod 2008
using namespace std;

using i64 = long long;

i64 judge(i64 x, int bit) {
	return x & (1ll << bit);
}

i64 power(i64 a, i64 b) {
    i64 res = 1;
    for (; b; b /= 2, a *= a, a %= mod) {
        if (b % 2) {
            res *= a;
            res % mod;
        }
    }
    return ( res % mod + mod ) % mod;
}

void solve() {
	int n,m;
	cin >> n >> m;

	vector<i64> a(m);
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			a[i] <<= 1;
			if (s[j] == 'O') {
				a[i] ++;
			}
		}
	}

	int now = 0;
	for (int bit = 63; bit >= 0 && now < m; bit--) {
		int cnt = now;
		while (cnt < m && !judge(a[cnt], bit)) {
			cnt ++;
		}

		if (cnt == m) {
			continue;
		}

		swap(a[cnt],a[now]);

		for (int i = 0; i < m; i++) {
			if (i == now) continue;

			if (judge(a[i], bit)) {
				a[i] ^= a[now];
			}
		}
		now++;
	}

	cout << power(2,now) << "\n";
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