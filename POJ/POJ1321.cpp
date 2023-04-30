#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,k,cnt;
char mp[10][10];//棋盘
bool vis[10][10];//查看是否违反条件

void solve()
{

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> n >> k){
		if(n == -1 && k == -1)return 0;
		cnt = 0;//记录空地
		memset(vis,0,sizeof(vis));
		for(int i = 1;i <= n;i ++){
			for(int j = 1;j <= n;j ++){
				cin >> mp[i][j];
				if(mp[i][j] == '#')vis[i][j] = 0;
			}
		}
		solve();
	}
}