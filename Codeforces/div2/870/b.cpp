#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{
	int n;
	cin >> n;

	bool flag = 1;
	vector<int> a(n,0);
	for(int i = 0;i < n;i ++){
		cin >> a[i];
		if(i && a[i] != a[i - 1])flag = 0;
	}

	if(n == 1 || flag){
		cout << 0 << "\n";
		return;
	}

	vector<int> v(n / 2);
	for(int l = 0;l <= n / 2 - 1;l ++){
		// int num = __gcd(a[l],a[n - 1 - l]);
		if(a[l] == a[n - 1 - l]){
			v[l] = 0;
		}else v[l] = fabs(a[l] - a[n - 1 - l]);
	}

	int ans = v[0];
	for(int i = 1;i < n / 2;i ++){
		ans = __gcd(ans,v[i]);
	}

	cout << ans << "\n";
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