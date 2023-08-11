#include <bits/stdc++.h>
using namespace std;

using i64 = unsigned long long;

vector<string> v(64);

void solve() {
	string s;
	cin >> s;

	int ans = s.size() + 1;

	for (int i = 0; i < 64; i++) {
		int cnt = 0;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == v[i][cnt]) {
				cnt ++;
			}
		}

		ans = min(ans,int(s.size() - cnt + v[i].size() - cnt));
	}

	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	v[0] = "1";
	i64 cnt = 1;
	for (int i = 1; i < 64; i++) {
		cnt *= 2;
		v[i] = to_string(cnt);
		// cout << v[i] << "\n";
	} 

	while (t--) {
		solve();
	}

	return 0;
}