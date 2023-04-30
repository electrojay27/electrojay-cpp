#include <bits/stdc++.h>
using namespace std;
#define int long long
#define lowbit(x) ((x) & -(x))

const int maxn = 1e6 + 10;
int n,cnt,f;
int t[maxn];
int t1[maxn];
int a[maxn];

void dan_update(int x,int d){
	int temp = x;
	while(temp <= n){
		t[temp] += d;
		temp += lowbit(temp);
	}
}

void update(int x,int d){
	int temp = x;
	while(temp <= n){
		t[temp] += d;
		t1[temp] += x * d;
		temp += lowbit(temp);
	}
}

int query(int x){
	int ret = 0;
	int temp = x;
	while(temp > 0){
		ret += ((x + 1) * t[temp] - t1[temp]);
		temp -= lowbit(temp);
	}
	return ret;
}

void solve()
{
	// cout << "Case " << ++cnt << ":" << endl;
	
	memset(t,0,sizeof(t));
	memset(t1,0,sizeof(t1));

	// cin >> n;
	a[0] = 0;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		update(i,a[i] - a[i - 1]);
	}

	// cout << "Case " << ++cnt << ": " << endl;

	int x,y,k,op;

	int cha = 0;

	while(f --){
		// if(op == "End")break;

		cin >> op;

		if(op == 1){
			cin >> x >> y >> k;
			update(x,k);
			update(y + 1,-k);
		}else if(op == 2){
			cin >> k;
			// dan_update(1,k);
			update(1,k);
			update(2,-k);
		}else if(op == 3){
			cin >> k;
			// dan_update(1,-k);
			update(1,-k);
			update(2,k);
		}else if(op == 4){
			cin >> x >> y;
			// if(x != 1)cout << query(y) - query(x - 1) << endl;
			// else cout << query(y) - query(x - 1) + cha << endl;
			cout << query(y) - query(x - 1) << endl;
			// cout << query(y) << " " << query(x - 1) << endl;
		}else{
			cout << query(1) << endl;
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// int t;
	// cin >> t;
	// cnt = 0;

	while(cin >> n >> f){
		solve();
	}

	return 0;
}