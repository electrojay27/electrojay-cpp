#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 2e+18
	
const int maxn = 2e5 + 10;
ll n,m;

void solve()
{
	ll ans = INF;

	ll x;

	for(ll i = 1;i <= n;i ++)
	{
		x = (m + i - 1) / i;
		if(x <= n)ans = min(ans,i * x);
		if(i > x)break;
	}

	if(ans != INF)cout << ans << endl;
	else cout << -1 << endl;


}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while(cin >> n >> m)
	{
		solve();
	}
	return 0;
}