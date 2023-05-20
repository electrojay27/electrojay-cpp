#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{
	int n;
	cin >> n;

	if(n % 2){
		for(int i = 1;i <= n;i ++){
			cout << i << " \n"[i == n];
		}
	}else{
		for(int i = 1;i <= n;i ++){
			if(i == 1){
				cout << i + (n / 2) << " ";
			}else cout << i << " \n"[i == n];
		}
	}
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