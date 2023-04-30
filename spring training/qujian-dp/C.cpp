#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int dp[110][110];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	memset(dp,0x3f3f3f,sizeof(dp));

	vector<int> a(n);

	for(int i = 0;i < n;i ++)cin >> a[i],dp[i][i] = 0;

	for(int i = 1;i < n - 1;i ++){
		for(int begin = 1;begin + i <= n - 1;begin ++){
			int end = begin + i;
			for(int k = begin;k <= end;k ++){
				dp[begin][end] = min(dp[begin][k] + dp[k + 1][end],dp[begin][end]);
			}
		}
	}

	cout << dp[1][n - 1] << endl;

	return 0;
}