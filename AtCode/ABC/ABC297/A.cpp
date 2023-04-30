#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int n,m;


void solve()
{
	int last,x;
	cin >> last;
	int ans = -1;

	for(int i = 2;i <= n;i ++){
		cin >> x;
		if(ans != -1)continue;
		if(x - last > m){
			last = x;
		}else{
			ans = x;
		}
	}
	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while(cin >> n >> m){
		solve();
	}
	return 0;
}