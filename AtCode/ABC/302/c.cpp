#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,m;
	cin >> n >> m;

	string s[n];
	for (int i = 0;i < n;i ++) cin >> s[i];

	if (n == 2) {
		int cnt = 0;
		for (int i = 0;i < m;i ++) {
			if (s[0][i] != s[1][i]) cnt ++;
		}

		if (cnt == 1) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}

		return 0;
	}

	vector<int> p(n,0);
	for (int i = 0;i < n;i ++) {
		for (int j = i + 1;j < n;j ++) {
			int cnt = 0;
			for (int k = 0;k < m;k ++) {
				if (s[i][k] != s[j][k]) {
					cnt ++;
				}
			}
			if (cnt == 1) {
				p[i] ++;
				p[j] ++;
			}
		}
	}

	int cnt = 0;
	for (int i = 0;i < n;i ++) {
		if (p[i] < 2) {
			cnt ++;
		}
	}

	cout << (cnt <= 2 ? "Yes" : "No") << "\n";
}