#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

struct node1
{
	int x,y,z;
};

struct node2
{
	int l,d,v;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<node1> f(n);
	for(int i = 0;i < n;i ++)cin >> f[i].x >> f[i].y >> f[i].z;

	int m;
	cin >> m;
	vector<node2> p(m); 
	for(int i = 0;i < m;i ++)cin >> p[i].l >> p[i].d >> p[i].v;

	i64 ans = 0;
	for(int i = 0;i < n;i ++){
		int c = (f[i].x + f[i].y) * 2;
		i64 cmp = 0x3f3f3f3f;
		for(int j = 0;j < m;j ++){
			int x = p[j].l / f[i].z;
			int y = (c - 1) / p[j].d + 1;
			// cout << "x = " << x << " " << "y = " << y << "\n";
			i64 cnt;
			if(x > 0)cnt = ((y - 1) / x + 1) * p[j].v;
			else continue;
			// cout << cnt << "\n";

			cmp = min(cnt,cmp);
		}
		ans += cmp;
	}

	cout << ans << "\n";
}