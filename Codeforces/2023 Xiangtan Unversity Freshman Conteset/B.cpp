#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{
	i64 a,b,n;
	cin >> a >> b >> n;

	i64 ans = 0;
	if(b >= a){
		ans += n * b;
	}else{
		if(n % 2){
			ans += (a + b) * (n - 1) / 2 + b;
		}else ans += (a + b) * (n / 2 - 1) + 2 * b;
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