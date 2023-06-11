#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	string ans;
	for (int i = 0; i < n; i++) {
		ans += s[i];
		int to = i + 1;
		while (to < n) {
			if (s[to] == s[i]) {
				break;
			}
			to ++;
		}
		i = to;
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