#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{
	int n;
	string s;
	cin >> n >> s;

	set<string> st;
	int ans = 0;
	for (int i = 0;i < n - 1;i ++) {
		if(!st.count(s.substr(i,2))){
			st.insert(s.substr(i,2));
			ans ++;
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