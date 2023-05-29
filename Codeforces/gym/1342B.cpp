#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	string s;
	cin >> s;

	for (int i = 1; i < s.size(); i++) {
		if (s[i] != s[i - 1]) {
			for (int j = 0;j < s.size(); j++) {
				cout << "01";
			}
			cout << "\n";
			return;
		}
	}

	cout << s << "\n";
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