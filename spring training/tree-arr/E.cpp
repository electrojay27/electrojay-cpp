#include <bits/stdc++.h>
using namespace std;
#define int long long
#define lowbit(x) ((x) & -(x))

const int maxn = 1e6 + 10;
int n,cnt,m;
int t[maxn];
int t1[maxn];
int a[maxn];

void e_update(int x,int d){
	int temp = x;
	while(temp <= n){
		t1[temp] += d;
		temp += lowbit(temp);
	}
}

void b_update(int x,int d){
	int temp = x;
	while(temp <= n){
		t[temp] += d;
		temp += lowbit(temp);
	}
}

int b_query(int x){
	int ret = 0;
	int temp = x;
	while(temp > 0){
		ret += t[temp];
		temp -= lowbit(temp);
	}
	return ret;
}

int e_query(int x){
	int ret = 0;
	int temp = x;
	while(temp > 0){
		ret += t1[temp];
		temp -= lowbit(temp);
	}
	return ret;
}

void solve()
{
	// cout << "Case " << ++cnt << ":" << endl;
	
	memset(t,0,sizeof(t));
	memset(t1,0,sizeof(t1));

	int op,l,r;

	while(m --){
		cin >> op >> l >> r;
		if(op == 1){
			b_update(l,1);
			e_update(r + 1,1);
		}else{
			cout << b_query(r) - e_query(l) << endl;
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

	while(cin >> n >> m){
		solve();
	}

	return 0;
}