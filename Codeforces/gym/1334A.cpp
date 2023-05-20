#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{
	int n;
	cin >> n;
	vector<int> p(n),c(n);
	for(int i = 0;i < n;i ++)cin >> p[i] >> c[i];

	for(int i = 0;i < n;i ++){
		if(!i){
			if(p[i] < c[i]){
				cout << "NO\n";
				return;
			}
		}else{
			if(p[i] - p[i - 1] < c[i] - c[i - 1] || p[i] < c[i] || p[i] - p[i - 1] < 0 || c[i] - c[i - 1] < 0){
				cout << "NO\n";
				return;
			}
		}
	}

	cout << "YES\n";
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