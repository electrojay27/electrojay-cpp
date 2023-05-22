#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n,k1,k2;
	cin >> n >> k1 >> k2;
	string s;
	cin >> s;

	vector<int> a(n,0);
	for (int i = 0; i < n; i++) {
		if (!i) {
			if (s[i] == '1') {
				a[i] = k1;
			}
		} else {
			if (s[i] == '1') {
				if (s[i - 1] == '0') {
					a[i] = k1;
				} else {
					a[i] = (k2 - a[i - 1] > k1 ? k1 : k2 - a[i - 1]);
				}
			}
		}
	}


	int ans = 0;
	for (auto it : a) {
		ans += it;
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