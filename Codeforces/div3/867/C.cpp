#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{
	i64 n;
	cin >> n;

	i64 ans;
	ans = n * n + (n - 4) * 2 + 10;
	cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t --){
		solve();
	}
	return 0;
}