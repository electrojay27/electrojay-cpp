#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n,m;
int vis[110][110];//判断是否x > y，是的话vis == 1
int x,y,flag,ans;//ans记录答案，flag确定是否都可以判断

void Floyd(){
	for(int k = 1;k <= n;k ++)
		for(int i = 1;i <= n;i ++)
			for(int j = 1;j <= n;j ++)
				vis[i][j] = vis[i][j] || (vis[i][k]&&vis[k][j]);
}//floyd

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> n >> m){
		ans = 0;
		memset(vis,0,sizeof(vis));
		for(int i = 1;i <= m;i ++){
			cin >> x >> y;
			vis[x][y] = 1;
		}

		// for(int k = 1;k <= n;k ++){
		// 	for(int i = 1;i <= n;i ++){
		// 		for(int j = 1;j <= n;j ++){
		// 			vis[i][j] = vis[i][j] || (vis[i][k]&&vis[k][j]); 
		// 		}
		// 	}
		// }//floyd
		Floyd();

		for(int i = 1;i <= n;i ++){
			flag = 0;
			for(int j = 1;j <= n;j ++){
				if(vis[i][j]||vis[j][i])
					flag ++;
			}
			if(flag == n - 1)ans ++;
		}

		cout << ans << endl;
	}
}