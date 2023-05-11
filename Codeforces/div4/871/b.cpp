#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{
	int n;
	cin >> n;

	vector<int> a(n);
	for(int i = 0;i < n;i ++)cin >> a[i];

	int ans = 0;
	int cmp = 0;
	for(int i = 0;i < n;i ++){
		if(a[i] == 1){
			ans = max(ans,cmp);
			cmp = 0;
		}else{
			cmp ++;
		}
	}
	ans = max(ans,cmp);

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