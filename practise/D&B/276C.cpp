#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

struct node
{
	int c;
	int id;
	bool operator < (const node & t)const{
		return c < t.c;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,q;
	cin >> n >> q;
	vector<i64> a(n);
	for(int i = 0;i < n; i++){
		cin >> a[i];
	} 

	sort(a.begin(),a.end());

	vector<int> s(n + 1,0);
	int x,y;
	for(int i = 0;i < q;i ++){
		cin >> x >> y;
		s[x] ++;
		if(y < n)s[y + 1] --;
	}

	for(int i = 1;i <= n;i ++){
		s[i] += s[i - 1];
	}

	sort(s.begin(),s.end());

	i64 ans = 0;
	for(int i = 0;i < n;i ++){
		ans += 1ll * a[i] * s[i + 1];
	}

	cout << ans << "\n";
}