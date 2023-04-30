#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{
	int n;
	string s;
	cin >> n >> s;

	if(n % 2){
		cout << "-1\n";
		return;
	}

	vector<int> str(26,0);
	for(int i = 0;i < n;i ++){
		str[s[i] - 'a'] ++;	
	}

	for(int i = 0;i < 26;i ++){
		if(str[i] > n/2){
			cout << "-1\n";
			return;
		}
	}

	int ans = 0,cnt = 0;
	vector<int> ret(26,0);
	for(int i = 0;i < n / 2;i ++){
		if(s[i] == s[n - 1 - i]){
			ret[s[i] - 'a'] ++;
			cnt ++;
			ans = max(ans,ret[s[i] - 'a']);
		}
	}

	ans = max(ans,(cnt + 1) / 2);

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