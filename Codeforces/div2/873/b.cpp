#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{
	int n;
	cin >> n;

	vector<int> p(n);
	for(int i = 0;i < n;i ++)cin >> p[i];

	vector<int> a(n);
	for(int i = 0;i < n;i ++){
		a[i] = fabs(p[i] - i - 1);
	}

	int ans = a[0];
	for(int i = 0;i < n;i ++){
		ans = __gcd(ans,a[i]);
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