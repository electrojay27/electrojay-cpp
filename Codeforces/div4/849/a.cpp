#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	string s = "codeforces";
	char op;
	cin >> op;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == op) {
			cout << "YES\n";
			return;
		}
	}

	cout << "NO\n";
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