#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
int mp[2010][2010];
int id[2010];
int vis[2010];
int n,m;

bool dfs(int x,int cmp){
	if(vis[x])return true;
	id[x] = cmp;
	vis[x] = 1;
	for(int i = 1;i <= n;i ++){
		if(!mp[x][i])continue;
		if(dfs(i,cmp)){
			return true;
		}
	}

	id[cmp] = 0;
	return false;
}

void solve()
{
	// int n,m;
	cin >> n >> m;

	memset(mp,0,sizeof(mp));
	memset(id,0,sizeof(id));
	memset(vis,0,sizeof(vis));
	int u,v;
	for(int i = 0;i < m;i ++){
		cin >> u >> v;
		mp[u][v] = 1;
		mp[v][u] = 1;
	}

	// if(m < n + 2){
	// 	cout << "NO\n";
	// 	return;
	// }

	int cmp = 1;
	for(int i = 1;i <= n;i ++){
		memset(vis,0,sizeof(vis));

		vector<int> a;
		if(dfs(i,cmp)){
			int cnt = 0;
			for(int j = 0;j <= n;j ++){
				if(mp[i][j] && id[j] != cmp){
					a.push_back(j);
				}else if(mp[i][j] && id[j] == cmp){
					cnt ++;
				}
			}
			cmp ++;
			if(a.size() == 2){
				cout << "YES\n";
				cout << cnt + 2 << "\n";
				for(int j = 1;j <= n;j ++){
					if(j != i && mp[i][j]){
						cout << i << " " << j << "\n";
					}
				}
				// for(int j= 0;j < a.size();j ++){
				// 	cout << i << " " << a[j] << "\n";
				// }
				return;
			}
		}
	}

	cout << "NO\n";
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