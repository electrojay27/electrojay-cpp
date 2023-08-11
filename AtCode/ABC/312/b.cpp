#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,m;
	cin >> n >> m;

	string mp[n];
	for (int i = 0; i < n; i ++) {
		cin >> mp[i];
	}

	for (int i = 0; i < n - 8; i++) {
		for (int j = 0; j < m - 8; j++) {
			// cout << i << " " << j << " " << "YES" << "\n";
			if (mp[i][j] == '#') {
				// cout << i << " " << j << " " << "YES" << "\n";
				int flag = 1;
				for (int l = i; l < i + 3; l++) {
					for (int r = j; r < j + 3; r++) {
						if (mp[l][r] == '.') {
							flag = 0;
						}
						if (l == i + 2) {
							if (mp[l + 1][r] == '#') {
								flag = 0;
							}
						}
						if (r == j + 2) {
							if (mp[l][r + 1] == '#') {
								flag = 0;
							}
						}
					}
				}
				// cout << "Y" << i << " " << j << "\n";
				for (int l = i + 6; l < i + 9; l++) {
					for (int r = j + 6; r < j + 9; r++) {
						if (mp[l][r] == '.') {
							flag = 0;
						}
						if (l == i + 6) {
							if (mp[l - 1][r] == '#') {
								flag = 0;
							}
						}
						if (r == j + 6) {
							if (mp[l][r - 1] == '#') {
								flag = 0;
							}
						}
					}
				}
				// cout << "N" << i << " " << j << "\n";
				if (mp[i + 3][j + 3] == '#' || mp[i + 5][j + 5] == '#') flag = 0;
				// cout << "S" << i << " " << j << "\n";
				if (!flag) {
					continue;
				} else {
					cout << i + 1 << " " << j + 1 << "\n";
				}
				// cout << "V" << i << " " << j << "\n";
			}
			// cout << "U" << i << " " << j << "\n";
			// cout << i << " " << j << " " << "NO" << "\n";
		}
	}
	// cout << "\n";
}