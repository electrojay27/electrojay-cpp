#include <iostream>
#define ll long long
using namespace std;

ll n,m;

ll f(ll i, ll j) {
	return i * i + 100000 * i + j * j - 100000 * j + i * j;
}

ll judge(ll x) {
	ll res = 0;

	for (ll i = 1;i <= n; i++) {
		ll l = 0,r = n + 1;
		while (l + 1 < r) {
			ll mid = (l + r) / 2;
			if (f(mid,i) < x) {
				l = mid;
			} else {
				r = mid;
			}
		}

		res += l;
	}

	return res;
}

void solve() {
	cin >> n >> m;

	ll l = -1e12,r = 1e12;
	while (r > l + 1) {
		ll mid = (l + r) / 2;
		if (judge(mid) < m) {
			l = mid;
		} else {
			r = mid;
		}
	}

	cout << l << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}