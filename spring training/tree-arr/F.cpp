#include <bits/stdc++.h>
using namespace std;
#define int long long
#define lowbit(x) ((x) & -(x))

const int maxn = 1e6 + 10;
const int N = 5e4;
int n,cnt,m;
int t[maxn];
int t1[maxn];

struct node
{
	int v;
	int id;

	bool operator < (const node& t)const{
		if(v != t.v)return v < t.v;
		return id < t.id;
	}
}cow[maxn];

void update_max(int x,int d){
	while(x <= N){
		t[x] += d;
		x += lowbit(x);
	}
}

void update_min(int x,int d){
	while(x <= N){
		t1[x] += d;
		x += lowbit(x);
	}
}

int query_max(int x){
	int ret = 0;
	while(x > 0){
		ret += t[x];
		x -= lowbit(x);
	}
	return ret;
}

int query_min(int x){
	int ret = 0;
	while(x > 0){
		ret += t1[x];
		x -= lowbit(x);
	}
	return ret;
}

void solve()
{
	// cout << "Case " << ++cnt << ":" << endl;

	// vector<node> cow(n);
	int v,x;

	for(int i = 1;i <= n;i ++){
		cin >> cow[i].v >> cow[i].id;
	}

	sort(cow + 1,cow + n + 1);
	
	memset(t,0,sizeof(t));
	memset(t1,0,sizeof(t1));

	int ans = 0;
	int mx = 0;

	for(int i = 1;i <= n;i ++){
		mx = max(mx,cow[i].id);
		ans += cow[i].v * (cow[i].id * query_min(cow[i].id - 1) - query_max(cow[i].id - 1) + (query_max(mx) - query_max(cow[i].id)) - (query_min(mx) - query_min(cow[i].id))*cow[i].id);
		update_max(cow[i].id,cow[i].id);
		update_min(cow[i].id,1);
	}

	cout << ans << endl;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// int t;
	// cin >> t;
	// cnt = 0;

	while(cin >> n){
		solve();
	}

	return 0;
}