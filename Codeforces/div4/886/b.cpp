#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;

	int ans = 0,cnt = 0;

	for (int i = 0; i < n; i++) {
		int a,b;
		cin >> a >> b;

		if (a <= 10 && cnt < b) {
			ans = i + 1;
			cnt = b;
		} 
	}

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