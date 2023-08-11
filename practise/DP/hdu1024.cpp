#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,m;

	while (cin >> m >> n) {
		vector<int> a(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}

		vector<int> dp(n + 1,0);
		vector<int> f(n + 1,0);

		int ans;
		for (int i = 1; i <= m; i++) {
			ans = -0x3f3f3f3f;
			for (int j = i; j <= n; j++) {
				dp[j] = max(dp[j - 1] + a[j],f[j - 1] + a[j]);
				f[j - 1] = ans;
				ans = max(dp[j],ans);
			}
		}
		cout << ans << "\n";
		// cout << endl;
	}	
}