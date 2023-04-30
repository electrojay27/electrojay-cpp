#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

struct node
{
	int id;
	int a,b;

	bool operator < (const node& t)const{
		if(b != t.b)return b > t.b;
		if(a != t.a)return a > t.a;
		return id < t.id;
	}
};

void solve()
{
	int n,m;
	cin >> n >> m;

	vector<node> v(n);
	for(int i = 0;i < n;i ++){
		cin >> v[i].a;
		v[i].id = i;
	}

	for(int i = 0;i < n;i ++){
		cin >> v[i].b;
	}

	sort(v.begin(),v.end());

	int ans = -1;
	for(int i = 0;i < n;i ++){
		if(v[i].a + v[i].id <= m){
			ans = v[i].id + 1;
			break;
		}
	}

	cout << ans << "\n";
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