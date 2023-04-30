#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{
	int n;
	cin >> n;

	vector<i64> a(n);
	for(int i = 0;i < n;i ++){
		cin >> a[i];
	}

	i64 ans;
	sort(a.begin(),a.end());

	ans = max(a[0] * a[1],a[n - 1] * a[n - 2]);

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