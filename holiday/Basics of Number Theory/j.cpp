#include <bits/stdc++.h>
#define mod 9973
using namespace std;

using i64 = long long;

i64 power(i64 a, i64 b) {
	i64 res = 1;
	for (; b; b /= 2, a *= a, a %= mod) {
		if (b % 2) res = res * a % mod;
	}
	return res;
}

void solve() {
	i64 n,b;
	cin >> n >> b;

	b = power(b,mod - 2);
	i64 ans = n * b % mod;

	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	// int t = 1;

	while (t--) {
		solve();
	}

	return 0;
}