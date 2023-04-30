#include <iostream>
#include <cstdio>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
#define inf 2e9 + 10;
// #define pii pair<int,int>

const int N = 35;
struct node
{	
	int x,y,z;
};
int bx,by,bz;
int l,r,c;
char mp[N][N][N];
int t[N][N][N];
int d[6][3] = {{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};//上下左右前后

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> l >> r >> c && l && r && c){
		node sta;
		// int ans = inf;
		for(int i = 1;i <= l;i ++)
		{
			for(int j = 1;j <= r;j ++)
			{
				for(int k = 1;k <= c;k ++)
				{
					cin >> mp[i][j][k];
					if(mp[i][j][k] == 'S')sta.x = i,sta.y = j,sta.z = k;
				}
			}
		}

		memset(t,0,sizeof(t));

		queue<node> q;
		q.push(sta);
		int ans = 0,flag = 0,cnt;
		node to;

		while(!q.empty()){
			// cnt = 1;//判断是否有路可走
			node now = q.front();
			q.pop();
			for(int i = 0;i < 6;i ++)
			{
				to.x = now.x + d[i][0];
				to.y = now.y + d[i][1];
				to.z = now.z + d[i][2];
				if(to.x < 1 || to.y < 1 || to.z < 1 || to.x > l || to.y > r || to.z > c)continue;
				if(mp[to.x][to.y][to.z] == '#')continue;
				if(t[to.x][to.y][to.z])continue;
				else{
					t[to.x][to.y][to.z] = t[now.x][now.y][now.z] + 1;
					if(mp[to.x][to.y][to.z] == 'E'){
						ans = t[to.x][to.y][to.z];
						flag = 1;
						break;
					}
					q.push(to);
				}
			}
			if(flag)break;
		}

		if(flag)cout << "Escaped in "<< ans << " minute(s)." << endl;
		else cout << "Trapped!" << endl;

	}

	return 0;
}