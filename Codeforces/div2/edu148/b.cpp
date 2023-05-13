#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve(){
	int n,k;
	cin >> n >> k;

	vector<int> a(n);
	vector<i64> s(n + 1,0);
	i64 ans = 1e-18;
	for(int i = 0;i < n;i ++){
		cin >> a[i];
	}

	sort(a.begin(),a.end());
	
	for(int i = 1;i <= n;i ++){
		s[i] = s[i - 1] + a[i - 1];
	}

	for(int i = 1;i <= k;i ++){
		ans = max(ans,max(s[n - k + i] - s[i * 2],s[n - k]));
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