	#include <bits/stdc++.h>
	using namespace std;

	using i64 = long long;

	void solve() {
		int n;
		cin >> n;
		string s;
		cin >> s;

		vector<int> a[4];

		for (int i = 0; i < n; i++) {
			if (s[i] == 'm' || s[i] == 'M') {
				a[0].push_back(i);
			} else if (s[i] == 'e' || s[i] == 'E') {
				a[1].push_back(i);
			} else if (s[i] == 'o' || s[i] == 'O') {
				a[2].push_back(i);
			} else if (s[i] == 'w' || s[i] == 'W') {
				a[3].push_back(i);
			} else {
				cout << "NO\n";
				return;
			}

			if (!i && !a[0].size()) {
				cout << "NO\n";
				return;
			}
		}

		for (int i = 0; i < 4; i++) {
			if (!a[i].size()) {
				cout << "NO\n";
				return;
			}
			for (int j = 1; j < a[i].size(); j++) {
				if (a[i][j] - 1 != a[i][j - 1]) {
					cout << "NO\n";
					return;
				}
			}
			if (i && a[i][0] < a[i - 1][0]) {
				cout << "NO\n";
				return;
			}
		}

		cout << "YES\n";
	}

	int main() {
		ios::sync_with_stdio(false);;
		cin.tie(nullptr);

		int t;
		cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}