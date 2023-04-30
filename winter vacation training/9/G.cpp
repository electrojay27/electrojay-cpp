#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
using namespace std;
#define inf 0x3f3f3f3f
#define pii pair<int,int>

const int maxn = 110;
int n,m;
int a,b,x;
struct thing
{
	int val;//价格
	int L;//等级
	// vector<pii> X;//用来存储可优惠物品
}p[maxn];
int d[maxn];
bool vis[maxn];
int mp[maxn][maxn];
int limit[maxn];

int Dij(){
	for(int i = 0;i <= n;i ++)d[i] = inf;
	memset(vis,0,sizeof(vis));
		
	d[1] = 0;
	for(int i = 1;i <= n;i ++){
		int mn = inf;
		int to;
		for(int j = 1;j <= n;j ++){
			if(!vis[j] && d[j] <= mn && limit[j]){
				mn = d[j];
				to = j;
			}
		}

		vis[to] = 1;
		for(int j = 1;j <= n;j ++){
			if(!vis[j] && d[j] > mp[to][j] + d[to] && limit[j]){
				d[j] = mp[to][j] + d[to];
			}
		}
	}

	int minx = inf;
	for(int i = 1;i <= n;i ++){
		d[i] += p[i].val;
		minx = min(d[i],minx);
	}

	return minx;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> m >> n){
		for(int i = 0;i <= n;i ++){
			for(int j = 0;j <= n;j ++){
				mp[i][j] = inf;
			}
		}

		for(int i = 1;i <= n;i ++){
			cin >> p[i].val >> p[i].L >> x;
			mp[i][i] = p[i].val;
			for(int j = 1;j <= x;j ++){
				cin >> a >> b;
				mp[i][a] = b;
				// p[i].X.push_back({a,b});
			}
		}

		int mx = 10000;
		for(int i = 0;i <= m;i ++){
			memset(limit,0,sizeof(limit));
			for(int j = 1;j <= n;j ++){
				if(p[j].L >= p[1].L + i - m && p[j].L <= p[1].L + i){
					limit[j] = 1;
				}
			}
			if(!limit[1])continue;
			mx = min(mx,Dij());
		}

		cout << mx << endl;
	}
}