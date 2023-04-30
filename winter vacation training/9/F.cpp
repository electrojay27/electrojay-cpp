#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;
#define i64 long long
#define inf 123456789

const int maxn = 110;
int mp[maxn][maxn];
int n;
char op[10];
int d[maxn];
bool vis[maxn];

void Dijkstra(){
	memset(vis,0,sizeof(vis));

	d[1] = 0;

	for(int i = 1;i <= n;i ++){
		int mn = inf;
		int to;
		for(int j = 1;j <= n;j ++){
			if(!vis[j] && mn > d[j]){
				to = j;
				mn = d[j];
			}
		}
		vis[to] = 1;//最短路确定
		for(int j = 1;j <= n;j ++){
			if(!vis[j] && d[j] > d[to] + mp[to][j] && mp[to][j] != inf){
				d[j] = d[to] + mp[to][j];
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> n){
		for(int i = 0;i <= n;i ++){
			d[i] = inf;
			for(int j = 0;j <= i;j ++){
				if(i != j)mp[i][j] = mp[j][i] = inf;
				else mp[i][j] = 0;
			}
		}//初始化

		for(int i = 1;i <= n;i ++){
			for(int j = 1;j < i;j ++){
				cin >> op;
				if(op[0] == 'x'){
					continue;
				}else{
					mp[i][j] = mp[j][i] = atoi(op);
				}
			}
		}

		Dijkstra();
		
		int ans = -1;
		for(int i = 2;i <= n;i ++){
			ans = max(ans,d[i]);
			//这里为什么取最大值，欸，不是求最小值吗，那是因为题目要求全部服务器都得到达,那么最大值都到了，其他不都也到了吗
		}
		cout << ans << endl;
	}
	return 0;
}