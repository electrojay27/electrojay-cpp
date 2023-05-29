#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n,k;
	cin >> n >> k;
	if (n % k) {
		cout << 1 << "\n";
		cout << n << "\n";
	} else {
		for (int i = 1; i <= n - i; i++) {
			if (i % k && (n - i) % k) {
				cout << 2 << "\n";
				cout << i << " " << n - i << "\n";
				break;
			}
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