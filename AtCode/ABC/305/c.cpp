#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int h,w;
	cin >> h >> w;

	vector<vector<char>> a(h + 2,vector<char>(w + 2,' '));
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			int cnt = 0;

			cnt += (a[i + 1][j] == '#');
			cnt += (a[i - 1][j] == '#');
			cnt += (a[i][j - 1] == '#');
			cnt += (a[i][j + 1] == '#');

			if (cnt >= 2 && a[i][j] != '#') {
				cout << i << " " << j << "\n";
				return 0;
			}
		}
	}
}