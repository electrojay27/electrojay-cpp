#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define i64 long long

int n,k,ans;
char mp[10][10];
bool vis[10][10];
bool dp[10];

void dfs(int line,int cnt)
{//last -> 上一个棋子的位置
	if(cnt == 0){
		ans ++;
		return;
	}
	if(line > n)return;

	for(int i = line;i <= n;i ++){
		for(int j = 1;j <= n;j ++){
			if(vis[i][j] && !dp[j]){
				dp[j] = 1;
				dfs(i + 1,cnt - 1);
				dp[j] = 0;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> n >> k){
		if(n == k && n == -1)break;

		ans = 0;
		memset(vis,0,sizeof(vis));//初始化
		memset(dp,0,sizeof(dp));

		for(int i = 1;i <= n;i ++){
			for(int j = 1;j <= n;j ++){
				cin >> mp[i][j];
				if(mp[i][j] == '#')vis[i][j] = 1;//存放棋盘位置
			}
		}

		// for(int i = 1;i <= n - k + 1;i ++)
		// 	dfs(i,k);	
		dfs(1,k);

		cout << ans << endl;
	}
	return 0;
}