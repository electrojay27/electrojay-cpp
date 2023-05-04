#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{
	int n;
	cin >> n;

	vector<int> st(n + 1,0);
	vector<int> s(n + 1,0);
	int x;
	for(int i = 1;i <= n;i ++){
		cin >> x;
		st[x] ++;
		s[i] = s[i - 1] + x;
	}

	int ans = 0;
	for(int len = 2;len < n;len ++){
		for(int i = 0;i + len <= n;i ++){
			if(s[i + len] - s[i] <= n && st[s[i + len] - s[i]]){
				ans += st[s[i + len] - s[i]];
				st[s[i + len] - s[i]] = 0;
			}
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