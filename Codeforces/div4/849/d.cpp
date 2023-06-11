#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	vector<int> a(26,0);
	for (int i = 0; i < n; i++) {
		a[s[i] - 'a'] ++;
	}

	vector<int> b(26,0);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		b[s[i] - 'a'] ++;
		int cnt1 = 0,cnt2 = 0;
		for (int j = 0; j < 26; j++) {
			if (b[j]) cnt1 ++;
		}
		for (int j = 0; j < 26; j++) {
			if (a[j] - b[j] > 0) cnt2 ++;
		}

		ans = max(ans,cnt1 + cnt2);
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