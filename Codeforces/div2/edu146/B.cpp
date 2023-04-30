#include <bits/stdc++.h>
using namespace std;
#define ll long long

int a,b;

void solve()
{
	cin >> a >> b;

	int ans = 1e9;

	for(int i = 1;i <= 100000;i ++)
	{
		ans = min(ans,i + 1 + ( a - 1 ) / i  + (b - 1) / i);
	}

	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t --)
	{
		solve();
	}
	return 0;
}