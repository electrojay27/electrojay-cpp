#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

char mp[1050][1050];
bool vis[1050][1050];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};
int t[1050][1050];

void solve()
{
	int r,c;
	cin >> r >> c;

	int bx,by,fx,fy;
	int x,y;

	memset(vis,0,sizeof(vis));
	memset(mp,'.',sizeof(mp));
	memset(t,0,sizeof(vis));

	for(int i = 1;i <= r;i ++){
		for(int j = 1;j <= c;j ++){
			cin >> mp[i][j];
			if(mp[i][j] == 'J')bx = i,by = j;
			if(mp[i][j] == 'F')fx = i,fy = j;
		}
	}

	queue<pii> q;
	q.push({bx,by});
	vis[bx][by] = 1;
	vis[fx][fy] = 2;

	while(!q.empty()){
		pii to = q.front();
		q.pop();

		int x = to->first;
		int y = to->second;

		if(vis[x][y] == 2)continue;

		for(int i = 0;i < 4;i ++){
			int xx = x + dx[i];
			int yy = y + dy[i];
			if(vis[xx][yy] && vis[xx][yy] == '#')continue;
			vis[xx][yy] = 1;
			q.push({xx,yy});
			t[xx][yy] = t[x][y] + 1;
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