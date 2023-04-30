#include <bits/stdc++.h>
using namespace std;

int n,m,flag;
string mp[25];
int vis[25][25];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while(cin >> n >> m){
		memset(vis,0,sizeof(vis));

		for(int i = 0;i < n;i ++)cin >> mp[i];

		for(int x = 0;x < n;x ++){
			for(int y = 0;y < m;y ++){
				if(mp[x][y] == '.' || mp[x][y] == '#')continue;
				else{
					int op = mp[x][y] - '0';
					for(int i = x - op;i <= x + op;i ++){
						int cnt;
						if(i <= x)cnt = i - (x - op);
						else cnt = (x + op) - i;
						for(int j = y - cnt;j <= y + cnt;j ++){
							if(i < 0 || j < 0 || i >= n || j >= m)continue;
							if(mp[i][j] == '#')mp[i][j] = '.';
						}
					}
					mp[x][y] = '.';
				}
			}
		}

		for(int i = 0;i < n;i ++)
			cout << mp[i] << endl;
	}
	return 0;
}