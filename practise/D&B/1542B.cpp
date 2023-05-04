#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{
	i64 n,a,b;
	cin >> n >> a >> b;

	if(a == 1){
		if((n - 1) % b != 0){
			cout << "No\n";
		}else cout << "Yes\n";

		return;
	}

	i64 cnt = 1;
	while(cnt <= n){
		if(cnt % b == n % b){
			cout << "Yes\n";
			return;
		}
		cnt = cnt * a;
	}

	cout << "No\n";
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