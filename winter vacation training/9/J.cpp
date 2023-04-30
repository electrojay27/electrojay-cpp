#include <bits/stdc++.h>
using namespace std;
#define pll pair<long long,long long>
#define i64 long long

const int maxn = 1e5 + 10;
i64 n,m,b;
i64 x,y,z;
i64 f[maxn];//收费
i64 d[maxn];
i64 vis[maxn];
vector<pll> edge[maxn];

bool SPFA(i64 x){
	memset(vis,0,sizeof(vis));
	memset(d,0x3f3f3f3f,sizeof(d));

	queue<i64> q;
	d[1] = 0;
	vis[1] = 1;
	q.push(1);

	while(!q.empty()){
		i64 to = q.front();
		q.pop();
		vis[to] = 0;//标记
		
		for(int i = 0;i < edge[to].size();i ++){
			pll cmp = edge[to][i];
			i64 a = cmp.first;
			i64 c = cmp.second;
			if(d[a] > d[to] + c){
				d[a] = d[to] + c;
			}else continue;
			if(!vis[a] && f[a] <= x){
				q.push(a);
				vis[a] = 1;
			}
		}
	}

	if(d[n] > b)return false;
	else return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while(cin >> n >> m >> b){
		i64 r = 0,l = 0;

		for(int i = 1;i <= n;i ++){
			cin >> f[i];
			r = max(f[i],r);
		}

		for(int i = 1;i <= m;i ++){
			cin >> x >> y >> z;
			if(x == y)continue;
			edge[x].push_back({y,z});
			edge[y].push_back({x,z});
		}//无向图建立

		if(!SPFA(1000000001)){
			cout << "AFK" << endl;
		}else{
			l = max(f[1],f[n]);
			while(l <= r){
				i64 mid = (l + r) / 2;
				if(SPFA(mid))r = mid - 1;
				else l = mid + 1;
			}
			cout << l << endl;

			// cout << 0x3f3f3f3f << endl;
		}
	}	
}