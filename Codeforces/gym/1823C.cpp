#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{
	int n;
	cin >> n;

	vector<int> a(n);
	i64 cnt = 1;
	for(int i = 0;i < n;i ++){
		cin >> a[i];
		cnt *= a[i];
	}

	int ans = 0;
	

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