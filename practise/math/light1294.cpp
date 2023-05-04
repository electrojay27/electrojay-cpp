#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve(int x){
	i64 n,m;
	cin >> n >> m;

	cout << "Case " << x << ": ";
	
	i64 ans = 0;
	ans = n * m / 2;

	cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	for(int i = 1;i <= t;i ++){
		solve(i);
	}

	return 0;
}