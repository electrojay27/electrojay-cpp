#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	i64 n;
	cin >> n;

	i64 ans = 2520;

	i64 v = (n / ans + 1) * ans;

	for (i64 i = n; i <= v; i++) {
		i64 to = i;
		while (to) {
			i64 cnt = to % 10;
			if (cnt && i % cnt) {
				break;
			}
			to /= 10;
		}

		if (!to) {
			cout << i << "\n";
			return;
		}
	}
	
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