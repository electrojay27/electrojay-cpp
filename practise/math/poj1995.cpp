#include <iostream>
#define i64 long long
using namespace std;

i64 mod;
i64 q_pos(i64 a, i64 b) {
	i64 res = 1;
	for (; b; b >>= 1, a = a * a % mod) {
		if (b & 1) res = res * a % mod;
	}
	return res;
}

void solve() {
	cin >> mod;
	int h;
	cin >> h;
	i64 ans = 0;
	for (int i = 0; i < h; i++) {
		i64 a,b;
		cin >> a >> b;
		ans = ( ans + q_pos(a,b) ) % mod;
	}

	cout << ans << "\n";
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