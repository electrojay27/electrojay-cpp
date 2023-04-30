#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{
	int n,k;
	cin >> n >> k;

	vector<int> p(n + 1);
	for(int i = 1;i <= n;i ++){
		cin >> p[i];
	}

	int ans = 0;
	for(int i = 1;i <= n;i ++){
		if(p[i] % k != i % k){
			ans ++;
		}
	}

	// cout << "ans = " << ans << "\n";

	ans = (ans + 1) / 2;
	if(ans != 1 && ans){
		ans = -1;
	}

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