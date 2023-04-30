#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{
	int n,k;
	cin >> n >> k;

	string op;
	cin >> op;
	string x;
	int ans = 1; 
	for(int i = 1;i < n;i ++){
		cin >> x;
		if(x == op)ans ++;
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