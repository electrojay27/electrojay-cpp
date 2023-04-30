#include <iostream>
#include <cstring>
#include <queue>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;

int sushu[10001];

bool judge(int x)
{
	if(x == 1)return false;
	if(x == 2)return true;
	for(int i = 2;i * i <= x;i ++){
		if(x % i == 0){
			sushu[x] = -1;
			return false;
		}
	}
	sushu[x] = 1;
	return true;
}

void solve()
{
	int n,m;

	cin >> n >> m;

	int ans = -1;
	bool vis[10001];
	int t[10001];
	memset(vis,0,sizeof(vis));
	memset(t,0,sizeof(t));

	queue<int> q;
	q.push(n);
	vis[n] = 1;

	while(!q.empty())
	{
		int to = q.front();
		q.pop();
		if(to == m){
			ans = t[to];
			break;
		}

		int cmp = 10000;
		for(int i = 0;i < 4;i ++){
			cmp /= 10;
			for(int j = 0;j <= 9;j ++){
				if(!i && !j)continue;
				int cnt = to / (cmp * 10) * (cmp * 10) + j * cmp + to % cmp;
				if(!vis[cnt] && (sushu[cnt] == 1 || judge(cnt))){
					t[cnt] = t[to] + 1;
					// cout << cnt << endl;
					q.push(cnt);
					vis[cnt] = 1;
				}
			}
		}
	}

	if(ans != -1)cout << ans << endl;
	else cout << "Impossible" << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	memset(sushu,0,sizeof(sushu));
	while(t --){
		solve();
	}
	return 0;
}