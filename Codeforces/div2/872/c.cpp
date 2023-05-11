#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{
	int n,m;
	cin >> n >> m;

	vector<int> x(n);
	vector<int> vis(m + 1,0);

	for(int i = 0;i < n;i ++){
		cin >> x[i];
	}

	if(m < n){
		cout << m << "\n";
		return;
	}

	sort(x.begin(),x.end());
	int a = 0,b = 0;
	for(int i = 0;i < n;i ++){
		if(x[i] == -1){
			a ++;
		}else if(x[i] == -2){
			b ++;
		}else{
			vis[x[i]] = 1;
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