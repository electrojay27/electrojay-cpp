#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) ((x) & -(x))

using i64 = long long;

const int maxn = 2e6;
int t[maxn * 2];
int n,m,s;
int a[maxn+1];
int vis1[maxn + 1];
int vis2[maxn + 1];
int ans[maxn + 1];
struct node
{
	int x,y;
	int id;
	bool operator <(const node&t)const{
		return y < t.y;
	}
}p[maxn * 2];

void update(int x,int d)
{
	while(x <= n){
		t[x] += d;
		x += lowbit(x);
	}
}

int query(int x)
{
	int ret = 0;
	while(x > 0){
		ret += t[x];
		x -= lowbit(x);
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> s >> m;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}

	// cin >> m;
	for(int i = 1;i <= m;i ++){
		cin >> p[i].x >> p[i].y;
		p[i].id = i;
	}

	sort(p + 1,p + 1 + m);

	// vector<int> ans(m);

	int j = 1;
	for(int i = 1;i <= m;i ++){
		for(;j <= p[i].y;j ++){
			if(!vis1[a[j]])vis1[a[j]] = j;
			else{
				if(!vis2[a[j]]){
					vis2[a[j]] = j;
					update(vis1[a[j]],1);
				}else{
					update(vis2[a[j]],1);
					update(vis1[a[j]],-1);
					vis1[a[j]] = vis2[a[j]];
					vis2[a[j]] = j;
				}
			}
		}
		ans[p[i].id] = query(p[i].y) - query(p[i].x - 1);
	}

	for(int i = 1;i <= m;i ++)cout << ans[i] << "\n";

	return 0;
}