#include <bits/stdc++.h>

using i64 = long long;

const int maxn = 1e5 + 10;

void solve()
{
	int n,x,mx = 0;
	std::cin >> n;

	std::vector<i64> a(maxn,0);
	for(int i = 0;i < n;i ++){
		std::cin >> x;
		a[x] ++;
		mx = std::max(x,mx);
	}

	for(int i = 1;i <= mx; i++){
		a[i] = a[i] * i * 1ll;
	}

	std::vector<i64> dp(mx + 1,0);
	dp[1] = a[1];
	for(int i = 2;i <= mx;i ++){
		dp[i] = std::max(dp[i - 1],dp[i - 2] + a[i]);
	}

	std::cout << dp[mx] << "\n";
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	// std::cin >> t;
	while(t --){
		solve();
	}

	return 0;
}