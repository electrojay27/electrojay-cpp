#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) ((x) & -(x))

const int maxn = 1e6 + 10;
int n,cnt,m;
int t[maxn * 4];
int a[maxn];

void update(int x,int d){
	for(;x <= n;x += lowbit(x)){
		t[x] += d;
	}
}

int query(int x){
	int ret = 0;
	for(;x > 0;x -= lowbit(x)){
		ret += t[x];
	}
	return ret;
}

void solve()
{
	// cout << "Case " << ++cnt << ":" << endl;
	
	memset(t,0,sizeof(t));

	// cin >> n;
	a[0] = 0;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		update(i,a[i] - a[i - 1]);
	}

	// cout << "Case " << ++cnt << ": " << endl;

	int x,y,k,op;

	while(m --){
		// if(op == "End")break;

		cin >> op;

		if(op == 1){
			cin >> x >> y >> k;
			update(x,k);
			update(y + 1,-k);
		}else if(op == 2){
			cin >> x;
			cout << query(x) << endl;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// int t;
	// cin >> t;
	// cnt = 0;

	while(cin >> n >> m){
		solve();
	}

	return 0;
}