#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

i64 dp[22][20][2][2],A[20];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	i64 a,b;
	cin >> a >> b;

	i64 cnt;

	function<i64(i64,i64,i64,i64)> dfs = [&](i64 pos, i64 last, i64 limit, i64 lead) {
		i64 ans = 0;
		if (pos == cnt) return 1ll;

		if (dp[pos][last][limit][lead] != -1) return dp[pos][last][limit][lead];

		for (i64 v = 0; v <= (limit ? A[pos] : 9); v++) {
			if (fabs(v - last) < 2) continue;
			if (lead && v == 0) ans += dfs(pos + 1, 19, limit && v == A[pos], 1);
			else ans += dfs(pos + 1, v, limit && v == A[pos], 0);
		}

		return dp[pos][last][limit][lead] = ans;
	};

	function<i64(i64)> f = [&](i64 x) {
		memset(A,0,sizeof(A));
		memset(dp,-1,sizeof(dp));
		cnt = 0;
		while (x) {
			A[cnt++] = x % 10;
			x /= 10;
		}
		reverse(A, A + cnt);
		return dfs(0, 19, 1, 1);
	};

	i64 l = f(a - 1),r = f(b);

	cout << r - l << "\n";
}