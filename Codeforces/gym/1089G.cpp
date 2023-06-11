#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int k;
	cin >> k;

	vector<int> a(7);
	int cnt = 0;
	for (int i = 0; i < 7; i++) {
		cin >> a[i];
		if (a[i] == 1) cnt ++;
	}

	int ans = 0x3f3f3f3f;
	for (int i = 0; i < 7; i++) {
		vector<int> now(7);
		for (int j = 0; j < 7; j++) {
			now[j] = a[(i + j) % 7];
		}

		int res = (k % cnt == 0 ? (k - 1) / cnt : k / cnt) * 7;

		int ret = k - res / 7 * cnt;

		for (int j = 0; j < 7; j++) {
			if (ret) {
				res ++;
				if (now[j]) {
					ret --;
				}
			}
		}

		for (int j = 0; j < 7; j++) {
			if (!now[j]) {
				res --;
			} else break;
		}

		ans = min(ans,res);
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