#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{
	int n;
	cin >> n;

	vector<int> b(n + 1,0);
	for(int i = 0;i < n;i ++){
		cin >> b[i];
		b[i] += b[i - 1];
	}

	vector<vector<int>> dp(n + 1,vector<int>(n + 1,0));
	for(int len = 3;len <= n;len ++){
		for(int i = 1;i + len <= n;i ++){
			dp[len][i] = b[i + len] - 
		}
	}
}	

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;;
	while(t --){
		solve();
	}
	return 0;
}