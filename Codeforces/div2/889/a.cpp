#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;

	int x,ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x == i + 1) {
			ans ++;
		}
	}
	cout << (int)(ans + 1) / 2 << "\n";
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