#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;

	vector<string> s(n);
	int flag = 1;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		if (s[i][0] == 'H' || s[i][0] == 'D' || s[i][0] == 'C' || s[i][0] == 'S') {
			if (s[i][1] == 'A' || s[i][1] == '2' || s[i][1] == '3' || s[i][1] == '4' || s[i][1] == '5' || s[i][1] == '6' || s[i][1] == '7' || s[i][1] == '8' ||s[i][1] == '9' || s[i][1] == 'T' ||s[i][1] == 'J' || s[i][1] == 'Q' || s[i][1] == 'K') {
				continue;
			}
		}
		flag = 0;
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (s[i] == s[j]) {
				flag = 0;
				break;
			}
		}
	}

	if (flag == 0) {
		cout << "No\n";
	} else {
		cout << "Yes\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// int t;
	// cin >> t;
	int t = 1;

	while (t--) {
		solve();
	}

	return 0;
}