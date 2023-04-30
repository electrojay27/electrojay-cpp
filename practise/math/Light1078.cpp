#include <bits/stdc++.h>
using namespace std;

int n,m;

void solve(int x)
{
	cin >> n >> m;

	int ret = 0;
	int ans = 0;

	cout << "Case " << x << ": " ; 

	do
	{
		ret = (ret * 10 + m) % n;
		ans ++;
	}while(ret);

	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	for(int i = 1;i <= t;i ++)
	{
		solve(i);
	}
	return 0;
}