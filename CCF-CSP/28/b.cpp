#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,m;
	cin >> n >> m;

	vector<int> p(m + 1,0);
	vector<int> t(m + 1,0);
	for (int i = 1;i <= m;i ++) cin >> p[i];
	for (int i = 1;i <= m;i ++) cin >> t[i];

	vector<int> ans1(m + 1,1);
	vector<int> ans2(m + 1,0);
	bool flag = false;
	for (int i = 1;i <= m;i ++) {
		if (p[i]) {
			ans1[i] = ans1[p[i]] + t[p[i]];
		}
		if (ans1[i] + t[i] - 1 > n) {
			flag = true;
		}
	}

	vector<int> dp(m + 1,0);
	for (int i = m;i > 0;i --) {
		if (!dp[i]) ans2[i] = n - t[i] + 1;
		else ans2[i] = dp[i] - t[i];

		if (!dp[p[i]]) dp[p[i]] = ans2[i];
		else dp[p[i]] = min(dp[p[i]],ans2[i]);
	}

	for (int i = 1;i <= m;i ++) cout << ans1[i] << " \n"[i == m];
	
	if (!flag) for (int i = 1;i <= m;i ++) cout << ans2[i] << " \n"[i == m];

	return 0;
}