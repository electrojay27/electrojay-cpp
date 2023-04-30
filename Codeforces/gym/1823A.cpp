#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

i64 f[102];
void init()
{	
	f[0] = f[1] = 0;
	for(int i = 2;i <= 101;i ++)f[i] = f[i - 1] + (i - 1);
}

void solve()
{
	int n,k;
	cin >> n >> k;

	int ans = -1;
	for(int i = 0;i < n;i ++){
		if(f[i] + f[n - i] == k){
			ans = i;
			break;
		}
	}

	// cout << ans << "\n";

	// cout << z << " " << d << '\n';

	if(ans == -1)cout << "NO\n";
	else{
		cout << "YES\n";
		for(int i = 0;i < ans;i ++){
			cout << 1 << " ";
		}
		for(int i = 0;i < n - ans;i ++){
			cout << -1 << " ";
		}
		cout << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	init();
	while(t --){
		solve();
	}
	return 0;
}