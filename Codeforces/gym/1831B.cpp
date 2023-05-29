#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;

	vector<int> a(n),b(n);
	map<int,int> v1,v2;

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (!i) {
			cnt ++;
		} else {
			if (a[i] != a[i - 1]) {
				v1[a[i - 1]] = max(v1[a[i - 1]],cnt);
				cnt = 1;
			} else {
				cnt ++;
			}
		}
	}
	v1[a[n - 1]] = max(v1[a[n - 1]],cnt);

	cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		if (!i) {
			cnt ++;
		} else {
			if (b[i] != b[i - 1]) {
				v2[b[i - 1]] = max(v2[b[i - 1]],cnt);
				cnt = 1;
			} else {
				cnt ++;
			}
		}
	}
	v2[b[n - 1]] = max(v2[b[n - 1]],cnt);

	int ans = 0;
	for (auto it = v1.begin(); it != v1.end(); it++) {
		ans = max(ans,it->second + v2[it->first]);
	}
	for (auto it = v2.begin(); it != v2.end(); it++) {
		ans = max(ans,it->second + v1[it->first]);
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