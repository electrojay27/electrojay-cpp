#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll m,n;

void solve(int x)
{	
	cin >> n;
	ll ans = 1;
	cout << "Case " << x << ": ";

	while(n % 2 == 0){
		ans *= 2;
		n /= 2;
	}

	if(ans % 2)cout << "Impossible" << endl;
	else cout << n << " " << ans << endl;
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