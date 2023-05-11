#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{
	string s;
	cin >> s;

	string op = "codeforces";
	int ans = 0;
	for(int i = 0;i < s.size();i ++){
		if(s[i] != op[i])ans ++;
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