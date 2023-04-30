#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) ((x) & -(x))
#define mod 1000000007

using i64 = long long;

const int maxn = 1e5;
int n,m;
i64 t[maxn*2];
i64 t1[maxn * 2];

i64 q_pow(i64 begin,i64 d = mod - 2){
	i64 ans = 1;
	begin %= mod;
	for(;d;d >>= 1){
		if(d & 1)ans = ans * begin % mod;
		begin = begin * begin % mod;
	}
	return ans % mod;
}

void update(i64 *t,int x,i64 d){
	while(x <= n){
		t[x] += d;
		t[x] %= mod;
		x += lowbit(x);
	}
}

i64 query(i64 *t,int x){
	i64 ret = 0;
	while(x > 0){
		ret = (ret + t[x]) % mod;
		x -= lowbit(x);
	}

	return ret % mod;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	vector<i64> a(n);

	for(int i = 0;i < n;i ++){
		cin >> a[i];
		update(t,i + 1,a[i] % mod);
		update(t1,i + 1,a[i] * a[i] % mod);
	}

	i64 op,x,y;
	for(int i = 1;i <= m;i ++){
		cin >> op >> x >> y;
		if(op == 1){
			i64 c1 = query(t,x) - query(t,x - 1);
			i64 c2 = query(t1,x) - query(t1,x - 1);
			update(t,x,(y - c1) % mod);
			update(t1,x,(y * y  - c2) % mod);
		}else{
			i64 l = (query(t,y) - query(t,x - 1)) % mod;//平均数
			i64 r = (query(t1,y) - query(t1,x - 1)) % mod;//平方和
			i64 base = q_pow(y - x + 1);
			l = l * base % mod;
			r = r * base % mod - l * l % mod;
			r = (r % mod + mod) % mod;
			cout << r << endl;
		}
	}
}