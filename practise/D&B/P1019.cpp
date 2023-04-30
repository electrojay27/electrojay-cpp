#include <bits/stdc++.h>
using namespace std;

int n,ans;
int long_th[25];
int vis[25];
char op;//首字母
char Word[25][10000];//单词

void dfs(int x,int cmp,int cnt){
	if(cmp == n){
		ans = max(ans,cnt);
		return;
	}
	for(int i = -n;i <= n;i ++){
		if(x + i > n && x + i < 1)continue;//越界
		if(vis[x + i])continue;//访问
		int l = 0,r = 0;//指针
		//int flag = 0;//判断
		while(l < long_th[x] && r < long_th[x+i]){
			if(Word[x][l] == Word[x+i][r]){
				r++;
			}
			l++;
		}//判断是否重合
		if(l == r)continue;//说明包含了
		vis[x + i] = 1;//标记
		cnt = cnt + (long_th[x + i] - l + r);//求长度
		dfs(x + i,cmp + 1,cnt);
		vis[x + i] = 0;//回溯
	}
}

int main()
{
	ios::sync_with_stdio(false);

	while(cin >> n){
		for(int i = 1;i <= n;i ++){
			cin >> Word[i];
			//既然需要知道最长的单词，那么就也需要一个数组来记录长度
			long_th[i] = strlen(Word[i]);			
		}
		cin >> op;
		int cnt;//标记长度
		int b;
		for(int i = 1;i <= n;i ++){
			if(op == Word[i][0]){
				if(cnt < long_th[i])cnt = long_th[i],b = i;				
			}
		}

		ans = 0;
		memset(vis,0,sizeof(vis));
		vis[b] = 1;
		dfs(b,1,cnt);

		cout << ans << endl;
	}
	return 0;
}
//题目大意：给n个单词，再给一个字母，以这个字母开头的最长的的单词作为开头，单词连接时重复部分重合，但不能重复部分不能时一整个单词
//求最长的‘龙’