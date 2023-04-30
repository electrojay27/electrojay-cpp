#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n,w;
	cin >> n >> w;
	vector<int> a(n);

	for(int i = 0;i < n;i ++){
		cin >> a[i];
	}

	sort(a.begin(),a.end());

	int ans = 0;

	for(int i = n - 1;i >= 0;i --){
		w -= a[i];
		ans ++;
		if(w <= 0)break;
	}

	cout << ans << endl;
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