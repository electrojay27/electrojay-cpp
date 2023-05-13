#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

char mp[105][105];
int vis[105][105];
int n,m;

void Memset(){
	for(int i = 0;i < n;i ++)
		for(int j = 0;j < m;j ++)
			vis[i][j] = 0;
}

void dfs(int x,int y,int cmp){
	if(x < 0 || y < 0 || x >= n || y >= m)return;
	if(vis[x][y] || mp[x][y] != '@')return;
	vis[x][y] = cmp;
	for(int i = -1;i <= 1;i ++){
		for(int j = -1;j <= 1;j ++){
			if(!j && !i)continue;
			dfs(x + i,y + j,cmp);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while(cin >> n >> m && m){
		for(int i = 0;i < n;i ++){
			for(int j = 0;j < m;j ++){
				cin >> mp[i][j];
			}
		}

		Memset();

		int ans = 0;
		for(int i = 0;i < n;i ++){
			for(int j = 0;j < m;j ++){
				if(vis[i][j] || mp[i][j] != '@')continue;
				dfs(i,j,++ans);
			}
		}

		cout << ans << "\n";
	}
	return 0;
}