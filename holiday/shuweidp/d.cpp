#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#define i64 long long
using namespace std;

// using i64 = long long;

int dp[65][65][65],A[65];

int dfs(int pos, int limit, int _0, int _1, int lead) {
	int ans = 0;

	if (!pos) return _0 >= _1;

	if (!limit && dp[pos][_0][_1] != -1) return dp[pos][_0][_1];

	for (int i = 0; i <= (limit ? A[pos] : 1); i++) {
		ans += dfs(pos - 1, limit && i == A[pos], lead ? 0 : _0 + (!i ? 1 : 0), _1 + (i ? 1 : 0), lead && !i);
	}

	return limit ? ans : dp[pos][_0][_1] = ans;
}

int f(int x) {
	memset(A,0,sizeof(A));
	int cnt = 0;
	while (x) {
		A[++cnt] = x & 1;
		x >>= 1;
	}
	// reverse(A, A + cnt);
	// for (int i = 0; i < cnt; i++) cout << A[i] << " \n"[i == cnt - 1];
	return dfs(cnt,1,0,0,1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a,b;
	cin >> a >> b;

	memset(dp,-1,sizeof(dp));

	int l = f(a - 1),r = f(b);

	// cout << l << " " << r << "\n";

	cout << r - l << "\n";
}