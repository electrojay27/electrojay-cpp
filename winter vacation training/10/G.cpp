#include <bits/stdc++.h>
using namespace std;
#define i64 long long

const int maxn = 1e5 + 10;
i64 n,mod;
i64 t[4 * maxn];

void bulid(i64 l,i64 r,i64 d)
{
	if(l == r){
		t[d] = 1;
		return;
	}

	i64 mid = (l + r) / 2;
	bulid(l,mid,2 * d);
	bulid(mid + 1,r,2 * d + 1);

	t[d] = t[2 * d] * t[2 * d + 1] % mod;
	return; 
}

void update(i64 d,i64 l,i64 r,i64 dl,i64 dr,i64 x)
{
	if(dl <= l && r <= dr){
		t[d] = x;
		return;
	}
	if(dr < l || r < dl)return;

	i64 mid = (l + r) / 2;
	update(2 * d,l,mid,dl,dr,x);
	update(2 * d + 1,mid + 1,r,dl,dr,x);

	t[d] = t[2 * d] * t[2 * d + 1] % mod;
	return;
}

void solve()
{
	cin >> n >> mod;
	// memset(t,1,sizeof(t));
	bulid(1,n,1);
	i64 op,x;
	for(int i = 1;i <= n;i ++){
		cin >> op >> x;
		if(op == 1){
			update(1,1,n,i,i,x);
		}else{
			update(1,1,n,x,x,1);
		}

		cout << t[1] % mod << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t --){
		solve();
	}
	return 0;
}