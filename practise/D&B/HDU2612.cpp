#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

char mp[205][205];
int sum[205][205];
int yes[205][205];
int vis[205][205];
int dx[4] = {0,0,1,-1};
int dy[4] = {-1,1,0,0};
int n,m;

struct node
{
	int x,y,step;
};

void Memset(){
	for(int i = 1;i <= n;i ++)
		for(int j = 1;j <= m;j ++)
			vis[i][j] = 0;
}

void bfs(int x,int y)
{
	queue<node> q;
	q.push({x,y,0});
	while(!q.empty()){
		node to = q.front();
		q.pop();
		if(mp[to.x][to.y] == '@'){
			sum[to.x][to.y] += to.step * 11;
			yes[to.x][to.y] ++;
		}
		for(int i = 0;i < 4;i ++){
			node cnt;
			cnt.x = to.x + dx[i];
			cnt.y = to.y + dy[i];
			cnt.step = to.step + 1;
			if(cnt.x > n || cnt.x <= 0 || cnt.y > m || cnt.y <= 0)continue;
			if(vis[cnt.x][cnt.y])continue;
			if(mp[cnt.x][cnt.y] == '#')continue;
			vis[cnt.x][cnt.y] = 1;
			q.push(cnt);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while(cin >> n >> m){
		int yx,yy,mx,my;

		for(int i = 1;i <= n;i ++){
			for(int j = 1;j <= m;j ++){
				cin >> mp[i][j];
				vis[i][j] = 0;
				sum[i][j] = 0;
				yes[i][j] = 0;
				if(mp[i][j] == 'Y')yx = i,yy = j;
				if(mp[i][j] == 'M')mx = i,my = j;
			}
		}

		vis[yx][yy] = 1;
		bfs(yx,yy);

		Memset();

		vis[mx][my] = 1;
		bfs(mx,my);

		int ans = 0x3f3f3f3f;
		for(int i = 1;i <= n;i ++){
			for(int j = 1;j <= m;j ++){
				// cout << sum[i][j] << " \n"[j == m];
				if(mp[i][j] == '@' && yes[i][j] == 2)ans =  min(ans,sum[i][j]);
			}
		}

		cout << ans << "\n";
	}
}