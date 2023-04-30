#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e4 + 10;
int t;
int n,m,x;
int a[maxn];

void solve()
{
	cin >> m;
	// cin >> n;

	int flag;
	memset(a,0,sizeof(a));
	// memset(vis,0,sizeof(vis));
	
	vector<int> ans(m);
	vector<vector<int>> day(m);

	for(int i = 0;i < m;i ++){
		cin >> n;

		day[i].resize(n);
		for(int j = 0;j < n;j ++){
			cin >> day[i][j];
		}
	}

	set<int> nowin;
	for(int i = m - 1;i >= 0;i --){
		flag = -1;
		for(int j = day[i].size() - 1;j >= 0;j --){
			if(!nowin.count(day[i][j])){
				nowin.insert(day[i][j]);
				flag = day[i][j];
			}
		}
		if(flag == -1){
			cout << -1 << endl;
			return;
		}

		ans[i] = flag;
	}

	for(int i = 0;i < m;i ++)cout << ans[i] << " ";
	cout << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while(cin >> t){
		while(t --){
			solve();
		}
	}
	return 0;
}