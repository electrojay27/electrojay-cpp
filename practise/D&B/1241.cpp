#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

char mp[110][110];
bool vis[110][110];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,m;
	while(cin >> n >> m){
		if(!n && !m)break;

		memset(mp,0,sizeof(mp));
		memset(vis,0,sizeof(vis));

		for(int i = 0;i < n;i ++){
			for(int j = 0;j < m;j ++){
				cin >> mp[i][j];
			}
		}

		
	}
}