#include <bits/stdc++.h>
#define mod 2520
using namespace std;

using i64 = long long;

i64 dp[22][2600][55],A[22];
int id[2600];

i64 dfs(int pos,int limit,int num,int v) {
	if (!pos) {
		return num % v == 0;
	}

	i64 ans = 0;

	if (~dp[pos][num][id[v]] && !limit) return dp[pos][num][id[v]];

	for (int i = 0; i <= (limit ? A[pos] : 9); i++) {
		// cout << (i ? (v / __gcd(i,v) * i) : v) << endl;
		ans += dfs(pos - 1, limit && i == A[pos], (num * 10 + i) % mod, (i ? (v / __gcd(i,v) * i) : v));
	}

	return (limit ? ans : dp[pos][num][id[v]] = ans);
}

i64 f(i64 x) {
	int cnt = 0;
	memset(A,0,sizeof(A));

	while (x) {
		A[++cnt] = x % 10;
		x /= 10;
		// cout << x << endl;
	}

	return dfs(cnt,1,0,1);
}

void solve()  {
	i64 l,r;
	cin >> l >> r;

	i64 a = f(l - 1),b = f(r);
	cout << b - a << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	int k = 0;
	memset(id,0,sizeof(id));
	for (int i = 1; i <= 2520; i++) {
		if (2520 % i == 0) {
			id[i] = k++;
			// cout << i << endl;
		}
	}

	memset(dp,-1,sizeof(dp));

	while (t--) {
		solve();
	}

	return 0;
}