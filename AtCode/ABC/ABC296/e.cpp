#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int n,ans;
int a[maxn];
int vis[maxn];

void dfs(int goal,int x)
{
	if(goal == x)
	{
		ans ++;
		return;
	}

	if(vis[x])return;

	x = a[x];
	vis[x] = 1;
	dfs(goal,x);
	vis[x] = 0;

	return;
}

int main()
{
	memset(vis,0,sizeof(vis));

	cin >> n;

	ans = 0;
	// vector<int> v(n + 1);

	for(int i = 1;i <= n;i ++)cin >> a[i];//v[a[i]] = i;

	for(int i = 1;i <= n;i ++)
	{
		int x = a[i];
		vis[i] = 1;
		dfs(i,x);
		vis[i] = 0;
	}

	cout << ans << endl;
}