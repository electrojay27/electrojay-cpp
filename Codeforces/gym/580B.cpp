#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

struct node
{
	int m,s;

	bool operator < (const node& t)const
	{
		return m < t.m;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,d;
	cin >> n >> d;

	vector<node> a(n);
	for(int i = 0;i < n;i ++){
		cin >> a[i].m >> a[i].s;
	}

	sort(a.begin(),a.end());

	i64 ans = 0;
	int last = 0;
	i64 cmp = 0;
	for(int i = 0;i < n;i ++){
		if(!i){
			cmp += a[i].s;
		}else{
			if(a[i].m >= a[last].m + d){
				ans = max(ans,cmp);
				while(last < i && a[last].m + d <= a[i].m){
					cmp -= a[last].s;
					last ++;
				}
			}
			cmp += a[i].s;
		}
	}

	ans = max(ans,cmp);

	cout << ans << "\n";
}