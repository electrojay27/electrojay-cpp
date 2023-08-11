#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	i64 n;
	cin >> n;

	if (n % 2) {
		cout << 1 << "\n";
	} else {
		for (int i = 1; i <= 10001; i++) {
			if (n % i) {
				cout << i - 1 <<  "\n";
				return;
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