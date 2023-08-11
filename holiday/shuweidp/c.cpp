#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

i64 dp[20][20][20][2][2][2][2],A[20];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	i64 a,b;
	cin >> a >> b;

	i64 cnt;

	function<i64(i64,i64,i64,i64,i64,i64,i64)> dfs = [&](i64 pos, i64 last1, i64 last2, i64 flag, i64 limit, i64 _4, i64 _8) {
		i64 ans = 0;
		if (_4 && _8) return 0ll;
		
		if (pos == cnt) return flag;

		if (dp[pos][last1][last2][flag][limit][_4][_8] != -1) return dp[pos][last1][last2][flag][limit][_4][_8];

		for (i64 v = 0; v <= (limit ? A[pos] : 9); v++) {
			ans += dfs(pos + 1, v, last1, (v == last1 && v == last2 ? 1 : flag), (limit && v == A[pos] ? 1ll : 0), (v == 4 ? 1 : _4), (v == 8 ? 1 : _8));
		}

		return dp[pos][last1][last2][flag][limit][_4][_8] = ans;
	};

	function<i64(i64)> f = [&](i64 x) {
		if (x < 1e10) return 0ll;
		memset(A,0,sizeof(A));
		memset(dp,-1,sizeof(dp));
		cnt = 0;
		while (x) {
			A[cnt++] = x % 10;
			x /= 10;
		}
		reverse(A, A + cnt);
		i64 ans = 0;
		for (int i = 1; i <= A[0]; i++) {
			ans += dfs(1, i, 0, 0, (i == A[0] ? 1 : 0), (i == 4 ? 1 : 0), (i == 8 ? 1 : 0));
		}
		return ans;
	};

	i64 l = f(a - 1),r = f(b);

	cout << r - l << "\n";
}