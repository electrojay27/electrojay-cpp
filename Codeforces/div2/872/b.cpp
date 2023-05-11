#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{
	int n,m;
	cin >> n >> m;

	if(n < m)swap(n,m);

	vector<int> b(n * m,0);
	for(int i = 0;i < n * m;i ++)cin >> b[i];

	sort(b.begin(),b.end());
	
	int flag = 0;
	if(b[0] != b[1])flag = 1;
	
	i64 ans = 0;

	i64 cmp = 0;
	if(!flag){
		cmp = (b[n * m - 1] - b[0]) * (n * m - 1);
	}else{
		cmp = (b[n * m - 1] - b[1]) * (m - 1);
		cmp += (b[n * m - 1] - b[0]) * (n * m - m); 
	}

	i64 cnt = 0;
	flag = 0;
	if(b[n * m - 1] != b[n * m - 2])flag = 1;
	if(!flag){
		cnt = (b[n * m - 1] - b[0]) * (n * m - 1);
	}else{
		cnt = (b[n * m - 2] - b[0]) * (m - 1);
		cnt += (b[n * m - 1] - b[0]) * (n * m - m); 
	}

	ans = max(cmp,cnt);

	cout << ans << "\n";
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