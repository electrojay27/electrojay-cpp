#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define mod 100003

const int maxn = 1e6 + 10;
int n,m;
int d[maxn];
int ans[maxn];
vector<int> mp[maxn];//路
int vis[maxn];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while(cin >> n >> m){
		int x,y;
		for(int i = 1;i <= m;i ++){
			cin >> x >> y;
			mp[x].push_back(y);
			mp[y].push_back(x);
		}

		memset(d,0,sizeof(d));
		memset(vis,0,sizeof(vis));
		memset(ans,0,sizeof(ans));

		d[1] = 0;
		ans[1] = 1;
		vis[1] = 1;

		queue<int> q;
		q.push(1);

		while(!q.empty()){
			int to = q.front();
			q.pop();
			for(int i = 0;i < mp[to].size();i ++){
				if(!vis[mp[to][i]]){
					d[mp[to][i]] = d[to] + 1;
					vis[mp[to][i]] = 1;
					q.push(mp[to][i]);
				}
				if(d[mp[to][i]] == d[to] + 1)ans[mp[to][i]] = (ans[mp[to][i]] + ans[to]) % mod;
			}
		}

		for(int i = 1;i <= n;i ++){
			cout << ans[i] << endl;
		}
	}
	return 0;
}