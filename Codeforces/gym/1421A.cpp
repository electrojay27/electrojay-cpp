#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int a,b;
	cin >> a >> b;

	int base = 1;
	int res = 0;

	int e = a,f = b;
	
	while (a && b) {
		int c = a % 2;
		int d = b % 2;
		a /= 2;
		b /= 2;
		if (d && c) {
			res += base;
		}
		base *= 2;
	}

	i64 ans = (e ^ res) + (f ^ res);

	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}